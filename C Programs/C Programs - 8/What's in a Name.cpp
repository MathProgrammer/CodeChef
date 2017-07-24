#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
#define MAX_LENGTH 50 + 1

using namespace std;

void solve()
{
    int i, space = 0;
    char name[MAX_LENGTH];

    string formatted_name;
    fgets(name, MAX_LENGTH, stdin);

    if(name[0] == '\n') return;

    for(i = strlen(name) - 2; name[i] != ' ' && i > 0; i--)
    {
         formatted_name += tolower(name[i]);
    }

    while(i >= 0)
    {
        if(name[i] == ' ')
        {
            space++;

            if(space > 1)
                formatted_name += name[i + 1];

            char last_char = formatted_name[formatted_name.length() - 1]; //Make first letter of name capital
            formatted_name[formatted_name.length() - 1] = toupper(last_char);

            formatted_name += " .";

        }
         i--;
    }

    char first_letter = name[0];
    formatted_name += toupper(first_letter);

    reverse(all(formatted_name));

    cout << formatted_name << "\n";
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    no_of_test_cases++; //fgets reads the first new line as a test case.

    while(no_of_test_cases--)
        solve();

    return 0;
}
