#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct student
{
    int roll_no;
    char name[30];
    float SGPA;
};

void populate(student classA[], int n, string file)
{
    ifstream fin(file);

    for (int i = 0; i < n; i++)
    {
        fin >> classA[i].roll_no;
        fin >> classA[i].name;
        fin >> classA[i].SGPA;
    }

    SortByRollno(classA[].roll_no, n);
}

void SortByRollno(student arr[], int s) // USing insertion sort, sort student by roll no.
{

    for (int i = 1; i < s; i++) // Insertion Sort
    {
        student classroom = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].roll_no > classroom.roll)
        {
            roll[j + 1] = roll[j];
            j--;
        }
        roll[j + 1] = classroom;
    }

    for (int i = 0; i < s; i++)
    {
        cout << classroom[i].roll << ", ";
    }
}

void ShellSort(int A[], int n) // using shell sort, sort student by alphabetical order
{
}

void RadixSort(int A[], int n) // using radix sort, find the first ten toppers
{
}

int main()
{
    student S;
    void populate(int n, string file);
    void SortByRollno(int A[], int n);
    void ShellSort(int A[], int n);
    void RadixSort(int A[], int n);
    return 0;
}