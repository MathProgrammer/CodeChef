#include <stdio.h>

#define MAX_LENGTH 10000 + 1

int alloted_time[MAX_LENGTH];

void solve()
{
    int number_of_students, time_required, i, number_of_success = 0;
    scanf("%d", &number_of_students);

    alloted_time[0] = 0;
    for(i = 1; i <= number_of_students; i++)
        scanf("%d", &alloted_time[i]);

    for(i = 1; i <= number_of_students; i++)
    {
        scanf("%d", &time_required);

        number_of_success += (time_required <= alloted_time[i] - alloted_time[i-1] ? 1 : 0);
    }
    printf("%d\n", number_of_success);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
