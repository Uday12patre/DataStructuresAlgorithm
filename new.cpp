#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int main()
{
    string s1 = "Uday Barapatre";
    string s2;

    ofstream write("uday.txt");
    write << s1;

    ifstream read("sample.txt");
    getline(read, s2);
    cout << s2;
    return 0;
}