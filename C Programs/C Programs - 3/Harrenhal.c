#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0

void solve()
{
    char string[MAX_LENGTH];
    int is_palindrome = true, front_i, back_i;
    scanf("%s",string);

    for(front_i = 0, back_i = strlen(string) - 1; front_i < back_i; front_i++, back_i--)
    {
        if(string[front_i] != string[back_i])
        {
            is_palindrome = false; break;
        }
    }
    //If the string is a palindrome, we delete the entire string.
    //Else, in one step we delete all the a's - which is a palindromic subsequence and then the b's - which is also palindromic
    printf(is_palindrome ? "1\n" : "2\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
