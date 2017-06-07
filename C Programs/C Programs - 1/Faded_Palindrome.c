#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 12345 + 1
#define true 1
#define false 0

void solve()
{
    char string[MAX_LENGTH];
    int front_i, back_i;

    scanf("%s", string);
    for(front_i = 0, back_i = strlen(string) - 1; front_i <= back_i; front_i++, back_i--)
    {
        if(string[front_i] == '.' && string[back_i] == '.')
        {
            string[front_i] = string[back_i] = 'a';
        }
        else if(string[front_i] == '.' && string[back_i] != '.')
        {
            string[front_i] = string[back_i];
        }
        else if(string[front_i] != '.' && string[back_i] == '.')
        {
            string[back_i] = string[front_i];
        }
        else if(string[front_i] != string[back_i])
        {
            strcpy(string, "-1");
            break;
        }
    }
    printf("%s\n",string);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
