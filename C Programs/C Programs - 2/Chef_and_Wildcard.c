#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10 + 1
#define true 1
#define false 0

void solve()
{
    char string_x[MAX_LENGTH], string_y[MAX_LENGTH];
    int can_be_made_equal = true, i;

    scanf("%s %s",string_x, string_y);

    if(strlen(string_x) != strlen(string_y))
    {
        can_be_made_equal = false;
    }
    else
    {
        for(i = 0; string_x[i] != '\0'; i++)
        {
             if(string_x[i] != '?' && string_y[i] != '?' && string_x[i] != string_y[i])
            {
                can_be_made_equal = false;
                break;
            }
        }
    }

    printf(can_be_made_equal ? "Yes\n" : "No\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
