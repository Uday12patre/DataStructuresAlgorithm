#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct country
{
    string name;
    string capital;
    string currency;
    string continent;
};

void populate(country Asia[], int s, string file)
{
    ifstream fin(file);
    int i = 0;
    while (i < s)
    {
        // getline(fin, Asia[i].name);
        // getline(fin, Asia[i].capital);
        // getline(fin, Asia[i].currency);
        // getline(fin, Asia[i].continent);
        fin >> Asia[i].name;
        fin >> Asia[i].capital;
        fin >> Asia[i].currency;
        fin >> Asia[i].continent;
        i++;
    }
    fin.close();
    return;
}

void DisplayCountry(country Asia[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << Asia[i].name << " ";
        cout << Asia[i].capital << " ";
        cout << Asia[i].currency << " ";
        cout << Asia[i].continent << " ";
        cout << "\n";
    }
    return;
}

void SortByName(country Asia[], int s)
{
    string temp;
    int j, countc = 0;
    for (int gap = s / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < s; i++)
        {
            strcpy(temp, Asia[i].name);
            j = i - gap;

            while (j >= 0)
            {
                if (strcmp(temp, Asia[j].name) < 0)
                {
                    strcpy(Asia[j + gap].name, Asia[j].name);
                    j = j - gap;
                    countc++;
                }

                else
                {
                    break;
                }
            }
            strcpy(Asia[j + gap].name, temp);
        }
    }
    cout << "\nNumber of comparisions in Insertion sort is " << countc << endl;
    cout << "\nSorted by Country Name: " << endl;

    for (int i = 0; i < s; i++)
    {
        cout << Asia[i].name << " ";
        cout << Asia[i].capital << " ";
        cout << Asia[i].currency << " ";
        cout << Asia[i].continent << " ";
        cout << "\n";
    }
    return;
}

int main()
{
    country Asia1[30];
    populate(Asia1, 10, "country.txt");
    DisplayCountry(Asia1, 10);
    SortByName(Asia1, 10);
    return 0;
}