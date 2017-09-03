#include <cstdio>

#define MAX_SIZE 100000 + 3

using namespace std;

void solve()
{
    char input[MAX_SIZE];
    scanf("%s", input);

    int palindrome_of_2 = false, palindrome_of_3 = false;
    for(int i = 1; input[i] != '\0'; i++)
        if(input[i] == input[i - 1])
            palindrome_of_2 = true;

    for(int i = 1; input[i + 1] != '\0'; i++)
        if(input[i - 1] == input[i + 1])
            palindrome_of_3 = true;

    printf(palindrome_of_2 || palindrome_of_3 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
