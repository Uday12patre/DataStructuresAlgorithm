#include <iostream>
#include <cstring>
using namespace std;

struct cricketer // Structure
{
    int jersey_no;
    string name;
    string role;
};

void PopulatingTeam(cricketer Team[], int s) // Inserting Data
{
    for (int i = 0; i < s; i++)
    {
        cout << "Enter Jersey No.: " << endl;
        cin >> Team[i].jersey_no;
        cout << "Enter Name: " << endl;
        cin >> Team[i].name;
        cout << "Enter Role:" << endl;
        cin >> Team[i].role;
        cout << endl;
    }

    return;
}

void DisplayTeam(cricketer Team[], int s) // Displaying Team Players
{
    for (int i = 0; i < s; i++)
    {
        cout << "Jersey No. of the Player: " << Team[i].jersey_no;
        cout << "\nName of the Player: " << Team[i].name;
        cout << "\nRole of the Player: " << Team[i].role << "\n";
    }
    return;
}

void Filter(cricketer Team[], int s, string r) // Displaying Role
{
    for (int i = 0; i < s; i++)
    {
        if (Team[i].role == r)
        {
            cout << "Jersey No. of the Player: " << Team[i].jersey_no;
            cout << "\nName of the Player: " << Team[i].name;
            cout << "\nRole of the Player: " << Team[i].role << "\n";
        }
    }
}
int main()
{
    int n;
    cout << "Enter No. of Players: " << endl;
    cin >> n;

    cricketer Team[n]; // Array Of Team
    // int A[];
    PopulatingTeam(Team, n);
    DisplayTeam(Team, n);
    Filter(Team, n, "Batsman"); // Displying all Batsman in the Team

    return 0;
}