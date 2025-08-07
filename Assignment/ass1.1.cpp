#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student
{
    string roll_no;
    string name;
    double SGPA;
};

int populate(Student students[], const string &filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    int count = 0;
    while (count < MAX_STUDENTS && fin >> students[count].roll_no >> students[count].name >> students[count].SGPA)
    {
        count++;
    }
    fin.close();
    return count;
}

void printStudents(const Student students[], int n, const string &title = "Student List")
{
    cout << "\n--- " << title << " ---" << endl;
    if (n == 0)
    {
        cout << "No students to display." << endl;
        return;
    }
    cout << "Roll No.\tName\t\tSGPA" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << students[i].roll_no << "\t\t" << students[i].name << "\t\t" << students[i].SGPA << endl;
    }
    cout << "-------------------------------------" << endl;
}

void SortByRollno(Student students[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].roll_no > key.roll_no)
        {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

void ShellSort(Student students[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            Student temp = students[i];
            int j;
            for (j = i; j >= gap && students[j - gap].name > temp.name; j -= gap)
            {
                students[j] = students[j - gap];
            }
            students[j] = temp;
        }
    }
}

double getMaxSGPA(const Student students[], int n)
{
    double max_sgpa = 0.0;
    for (int i = 0; i < n; ++i)
    {
        if (students[i].SGPA > max_sgpa)
        {
            max_sgpa = students[i].SGPA;
        }
    }
    return max_sgpa;
}

void countSortForSGPA(Student students[], int n, int exp)
{
    Student output[MAX_STUDENTS];
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
    {
        int digit = (static_cast<int>(students[i].SGPA * 100) / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int digit = (static_cast<int>(students[i].SGPA * 100) / exp) % 10;
        output[count[digit] - 1] = students[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i)
    {
        students[i] = output[i];
    }
}

void reverseStudents(Student students[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        Student temp = students[start];
        students[start] = students[end];
        students[end] = temp;
        start++;
        end--;
    }
}

void RadixSort(Student students[], int n)
{
    if (n == 0)
    {
        cout << "No students to sort for toppers." << endl;
        return;
    }

    double max_sgpa_val = getMaxSGPA(students, n);
    int max_sgpa_int = static_cast<int>(max_sgpa_val * 100);

    for (int exp = 1; max_sgpa_int / exp > 0; exp *= 10)
    {
        countSortForSGPA(students, n, exp);
    }

    reverseStudents(students, n);
}

int main()
{
    Student sy_comp_students[MAX_STUDENTS];
    int num_students = 0;
    string filename = "students.txt";

    ofstream initial_data_writer(filename);
    initial_data_writer << "S001 Anjali 8.50\n";
    initial_data_writer << "S015 Bob 7.90\n";
    initial_data_writer << "S005 Charlie 9.10\n";
    initial_data_writer << "S010 Diana 6.80\n";
    initial_data_writer << "S002 Ethan 8.90\n";
    initial_data_writer << "S012 Fiona 7.50\n";
    initial_data_writer << "S007 George 9.50\n";
    initial_data_writer << "S003 Hannah 8.20\n";
    initial_data_writer << "S011 Ivy 7.10\n";
    initial_data_writer << "S008 Jack 9.30\n";
    initial_data_writer << "S014 Kelly 6.90\n";
    initial_data_writer << "S004 Liam 8.80\n";
    initial_data_writer << "S006 Mia 9.00\n";
    initial_data_writer << "S009 Noah 9.20\n";
    initial_data_writer << "S013 Olivia 7.00\n";
    initial_data_writer.close();
    cout << "Sample student data written to " << filename << endl;

    num_students = populate(sy_comp_students, filename);
    printStudents(sy_comp_students, num_students, "Original Student List");

    Student students_for_sort[MAX_STUDENTS];
    memcpy(students_for_sort, sy_comp_students, num_students * sizeof(Student));

    SortByRollno(students_for_sort, num_students);
    printStudents(students_for_sort, num_students, "Student List Sorted by Roll Number (Insertion Sort)");

    memcpy(students_for_sort, sy_comp_students, num_students * sizeof(Student));

    ShellSort(students_for_sort, num_students);
    printStudents(students_for_sort, num_students, "Student List Sorted Alphabetically by Name (Shell Sort)");

    memcpy(students_for_sort, sy_comp_students, num_students * sizeof(Student));

    RadixSort(students_for_sort, num_students);
    cout << "\n--- First Ten Toppers (Radix Sort by SGPA) ---" << endl;
    if (num_students == 0)
    {
        cout << "No toppers to display." << endl;
    }
    else
    {
        cout << "Rank\tRoll No.\tName\t\tSGPA" << endl;
        cout << "------------------------------------------------" << endl;
        int count = 0;
        for (int i = 0; i < num_students; ++i)
        {
            if (count < 10)
            {
                cout << count + 1 << "\t" << students_for_sort[i].roll_no << "\t\t" << students_for_sort[i].name << "\t\t" << students_for_sort[i].SGPA << endl;
                count++;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}