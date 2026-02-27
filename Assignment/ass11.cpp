/*Consider an employee database of N employees. Make use of a hash table implementation to
quickly look up the employer's id number.

OPTION 1
Steps:
Create a text file with Employee records ( EmpId, Name, Department..)
In the code find number of records in the file (say n)
Declare a structure for Employee Record
Declare an array of size more than n and initialize EmpId to INT_MIN
Read one record at a time from the file
Apply Hash function of your choice on the EmpId field
Store record at the index you get after applying Hash function
In case of collision do linear probing.

Now search for a record, count and display number of comparisons done for successful/unsuccessful search
Search same record using Linear Search - display above count for this case too

Compare results. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>
using namespace std;

// Employee structure
struct Employee
{
    int EmpId;
    string Name;
    string Department;
};

// Hash Table size (choose a prime number > number of records)
const int TABLE_SIZE = 20;

// Hash function
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

int main()
{
    Employee hashTable[TABLE_SIZE];
    int n = 0; // number of records

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].EmpId = INT_MIN;

    // Open employee file
    ifstream file("employees.txt");
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Read and insert records
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        Employee emp;
        ss >> emp.EmpId >> emp.Name >> emp.Department;

        int index = hashFunction(emp.EmpId);
        // Linear probing in case of collision
        while (hashTable[index].EmpId != INT_MIN)
        {
            index = (index + 1) % TABLE_SIZE;
        }
        hashTable[index] = emp;
        n++;
    }
    file.close();

    cout << "\nInserted " << n << " records into hash table.\n";

    // Search using hash table
    int searchId;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchId;

    int comparisons = 0;
    int index = hashFunction(searchId);
    bool found = false;

    while (hashTable[index].EmpId != INT_MIN && comparisons < TABLE_SIZE)
    {
        comparisons++;
        if (hashTable[index].EmpId == searchId)
        {
            cout << "\nRecord Found (Using Hash Search): ";
            cout << hashTable[index].EmpId << " " << hashTable[index].Name
                 << " " << hashTable[index].Department << endl;
            cout << "Comparisons (Hash Search): " << comparisons << endl;
            found = true;
            break;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    if (!found)
        cout << "\nRecord not found using Hash Search.\nComparisons: " << comparisons << endl;

    // Linear search for comparison
    ifstream file2("employees.txt");
    comparisons = 0;
    found = false;

    while (getline(file2, line))
    {
        comparisons++;
        stringstream ss(line);
        Employee emp;
        ss >> emp.EmpId >> emp.Name >> emp.Department;

        if (emp.EmpId == searchId)
        {
            cout << "\nRecord Found (Using Linear Search): ";
            cout << emp.EmpId << " " << emp.Name << " " << emp.Department << endl;
            cout << "Comparisons (Linear Search): " << comparisons << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found using Linear Search.\nComparisons: " << comparisons << endl;

    file2.close();
    return 0;
}