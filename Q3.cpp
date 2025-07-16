#include <iostream>
#include <fstream>

using namespace std;

struct cricketer
{
    int jersey_no;
    string name, role;
};

void populateTeam(cricketer Team[], int s, string file)
{
    ifstream f1;
    f1.open(file, ios::in);
    if (!f1)
        return;
    int i = 0;
    while (f1)
    {
        f1 >> Team[i].jersey_no;
        f1 >> Team[i].name;
        f1 >> Team[i].role;
        i++;
    }
    f1.close();
    return;
}

void displayTeam(cricketer Team[], int s)
{
    cout << "\n******Team Members*******\n";
    for (int i = 0; i < s; i++)
    {
        cout << "jersey_no :" << Team[i].jersey_no << endl;
        cout << "\n name :" << Team[i].name << endl;
        cout << "\nrole :" << Team[i].role << endl;
        cout << endl;
    }
    cout << "\n****************\n";
    return;
}

void filter(cricketer Team[], int s, string r)
{
    cout << "\n******Team Members who are " << r << "*******\n";
    for (int i = 0; i < s; i++)
    {
        if (Team[i].role == r)
        {
            cout << "jersey_no :" << Team[i].jersey_no << endl;
            cout << "\n name :" << Team[i].name << endl;
            cout << "\nrole :" << Team[i].role << endl;
        }
    }
    return;
}

void Bsort(cricketer Team[], int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j < s; j++)
        {
            if (Team[i].jersey_no < Team[i + 1].jersey_no)
            {
                int temp = Team[i + 1].jersey_no;
                Team[i + 1].jersey_no = Team[i].jersey_no;
                Team[i].jersey_no = temp;
            }
        }
    }
    return;
}

void displayBSort(cricketer Team[], int s)
{
    cout << "\n******Team Members Sorted by Jersey Number*******\n";
    for (int i = 0; i < s; i++)
    {
        cout << "jersey_no :" << Team[i].jersey_no << endl;
        cout << "\n name :" << Team[i].name << endl;
        cout << "\nrole :" << Team[i].role << endl;
        cout << endl;
    }
    cout << "\n****************\n";
    return;
}

int main()
{
    cricketer Team1[10], Team2[12];
    // int last1 = -1, last2 = 0;
    populateTeam(Team1, 10, "inFile.txt");
    displayTeam(Team1, 6);
    filter(Team1, 10, "batsman");
    Bsort(Team1, 6);
    displayBSort(Team1, 6);
    return 0;
}