#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0

void solve()
{
    int number_of_minutes, i, previous_activity = -1, rules_followed = true;
    char current_activity[MAX_LENGTH];
    scanf("%d", &number_of_minutes);

    for(i = 1; i <= number_of_minutes; i++)
    {
        scanf("%s", current_activity);

        if(strcmp(current_activity, "cookie") == 0 && previous_activity == 1)
            rules_followed = false;

        previous_activity = (strcmp(current_activity, "cookie") == 0 ? 1 : 2); //1 Denotes Cookie and 2 Denotes Milk
    }

    if(previous_activity == 1)
        rules_followed = false;

    printf(rules_followed == true ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
