#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    int number_of_subjects, i, marks_i, total = 0, failed = false, one_full = false;
    double average;
    scanf("%d", &number_of_subjects);

    for(i = 1; i <= number_of_subjects; i++)
    {
        scanf("%d", &marks_i);

        total += marks_i;

        if(marks_i == 2)
            failed = true;

        if(marks_i == 5)
            one_full = true;
    }
    average = total/(1.0*number_of_subjects);

    printf(!(failed) && one_full && average >= 4.0 ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
