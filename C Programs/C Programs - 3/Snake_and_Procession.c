#include <stdio.h>

#define MAX_LENGTH 500 + 1
#define true 1
#define false 0

void solve()
{
    char report[MAX_LENGTH], previous_snake = 'T';
    int valid = true, i, report_length;
    scanf("%d %s",&report_length, report);

    for(i = 0; i < report_length ; i++)
    {
        if(report[i] == 'H')
        {
            if(previous_snake == 'H')
            {
                valid = false; break;
            }
            previous_snake = 'H';
        }
        else if(report[i] == 'T')
        {
            if(previous_snake == 'T')
            {
                valid = false; break;
            }
            previous_snake = 'T';
        }

    }

    if(previous_snake == 'H')
        valid = false;


    printf(valid ? "Valid\n" : "Invalid\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
