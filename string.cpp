#include <iostream>
#include <stdio.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main()
{
    char C[] = {'U', 'D', 'A', 'Y', '\0', 'B', 'A', 'R', 'A', 'P', 'A', 'T', 'R', 'E', '\0'}; // total 15 char '\0' is invisible here!

    char name[] = "UDAY BARAPATRE"; // declaration of array of char (characters)
    for (char c : C)                // Printing array of char using For Each loop
    {
        cout << c;
    }

    cout << endl;

    for (char c : name)
    {
        cout << c;
    }
    cout << endl;

    /*gets(name);
    for(char c : name)
    {
        cout << c;
    }
    cout << endl; */

    // Counting the length of String
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
    }

    printf("Length of '%s' is %d.\n", name, i);

    // Converting Capital Alphabets to Small by Adding 32 to each char (By ASCII Codes)
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] + 32;
    }

    printf("%s", name);

    // Converting Small Alphabets to Capital by Subtracting 32 to each char (By ASCII Codes)
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] - 32;
    }

    printf("\n%s", name);

    // MiUday 'UdayBarapatre' -> 'uDAY bARAPATRE'
    // Converting Capital Alphabets to Small by Adding 32 to each char (By ASCII Codes) & Converting Small Alphabets to Capital by Subtracting 32 to each char (By ASCII Codes)
    char Name[] = "Uday Barapatre";
    for (int i = 0; Name[i] != '\0'; i++)
    {
        if (Name[i] >= 65 && Name[i] <= 90)
        {
            Name[i] = Name[i] + 32;
        }

        else if (Name[i] >= 97 && Name[i] <= 122)
        {
            Name[i] = Name[i] - 32;
        }
    }

    printf("\n%s", Name);

    // Counting no. of Vowels, Consonants and words
    char words[] = "Hey! i am Uday.";
    int vcount = 0, ccount = 0;
    for (int i = 0; words[i] != '\0'; i++)
    {
        if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u' || words[i] == 'A' || words[i] == 'E' || words[i] == 'I' || words[i] == 'O' || words[i] == 'U')
        {
            vcount++;
        }

        else if ((words[i] >= 65 && words[i] <= 90) || (words[i] >= 97 && words[i] <= 122))
        {
            ccount++;
        }
    }

    int wcount = 1;
    for (int i = 0; words[i] != '\0'; i++)
    {
        if (words[i] == ' ' && words[i - 1] != ' ')
        {
            wcount++;
        }
    }

    printf("\nNo. of Vowels present in '%s' is %d.", words, vcount);
    printf("\nNo. of consonants present in '%s' is %d.", words, ccount);
    printf("\nNo. of words present in '%s' is %d.", words, wcount);

    // Passwords (Alphanumeric) Validation
    char pass[] = "Uday1234";
    bool valid;

    for (int i = 0; pass[i] != '\0'; i++)
    {
        valid = false;
        if ((pass[i] >= 65 && pass[i] <= 90) || (pass[i] >= 97 && pass[i] <= 122) || (pass[i] >= 48 && pass[i] <= 57))
        {
            valid = true;
        }

        if (valid == false)
        {
            printf("\n%s is invalid pass which contains special characters.\n", pass);
            break;
        }
    }

    if (valid == true)
    {
        printf("\n%s is Valid Password Containing AlphaNumeric Values.\n", pass);
    }

    // Process of Reversing a string using a char array (Method 1)
    // char name[] = "UDAY BARAPATRE"; (Already Declared and intialises this above)

    for (int i = 0; name[i] != 0; i++)
    {
    }
    char revname[i + 1];
    int j;
    for (j = 0, i--; i >= 0; j++, i--)
    {
        revname[j] = name[i];
    }
    revname[j] = '\0';

    printf("Reverse of %s is %s.\n", name, revname);

    // Method 2: for reversing array of char by swapping

    // Let's Declare an words to be reversed;
    char Uday[] = "VScode";
    printf("\nBefore Reversing: %s", Uday);

    // Not: i,j are Already Declared Above
    for (i = 0; Uday[i] != '\0'; i++)
    {
    }

    for (j = 0, i--; j < i; j++, i--)
    {
        swap(&Uday[j], &Uday[i]);
    }

    printf("\nAfter Reversing: %s", Uday);

    // Checking if Two Strings are same or not;

    char A[] = "Drive";
    char B[] = "Driving";

    for (i = 0, j = 0; A[i] != '\0' || B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }

    if (A[i] == B[j])
        printf("\n%s and %s are Same.", A, B);
    else if (A[i] > B[j])
        printf("\n%s is greater than %s.", A, B);
    else if (A[i] < B[j])
        printf("\n%s is smaller than %s.", A, B);

    // Checking if a string is Palindrome or Not
    // Note: i, j are Already Declared.
    char Naam[] = "Uday"; // try it for nayan, madam, nitin.

    for (i = 0; Naam[i] != '\0'; i++)
    {
    }

    for (j = 0, i--; j < i; j++, i--)
    {
        if (Naam[j] != Naam[i])
        {
            break;
        }
    }

    if (i == j)
        printf("\n%s is a Palindrome.", Naam);
    else if (i != j)
        printf("\n%s is Not a Palindrome.", Naam);

    // Finding Duplicates in a string

    char st[] = "Doraemon";
    int H[26] = {0};

    for (int i = 0; st[i] != '\0'; i++)
    {
        H[st[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("\n%c occurs %d times in %s", (char)(i + 97), H[i], st); // Remember the Format spefier and the printing style.
        }
    }

    // Finding Duplicate Using Bit-wise operations

    int h = 0, x = 0;
    char sent[] = "driving";

    for (int i = 0; sent[i] != '\0'; i++)
    {
        x = 1;
        x = x << (sent[i] - 97);

        if ((x & h) > 0)
        {
            printf("\n%c is Duplicate in '%s'", sent[i], sent);
        }

        else
        {
            h = x | h;
        }
    }
    return 0;
}