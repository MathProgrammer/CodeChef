#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 5+1
#define true 1
#define false 0

void solve()
{
    int front_i, back_i, is_palindrome = true;
    char number[MAX_LENGTH];
    scanf("%s",number);

    for(front_i = 0, back_i = strlen(number)-1; front_i < back_i; front_i++, back_i--)
        if(number[front_i] != number[back_i])
        {
            is_palindrome = false;
            break;
        }

    printf(is_palindrome ? "wins\n" : "losses\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases--)
        solve();

    return 0;
}
