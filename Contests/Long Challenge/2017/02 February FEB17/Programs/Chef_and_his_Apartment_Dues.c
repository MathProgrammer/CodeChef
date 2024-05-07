#include <stdio.h>

void solve()
{
    const int fine = 100, maintenance = 1000;
    int number_of_months, i, number_of_unpaid_months = 0, due, paid, number_of_late_months = 0;
    scanf("%d", &number_of_months);

    for(i = 1; i <= number_of_months; i++)
    {
        scanf("%d", &paid);

        if(paid == 0)
        {
            number_of_unpaid_months++;
            if(number_of_late_months == 0)
            {
                number_of_late_months = (number_of_months - i + 1);//After the first month that is missed, every month is late
            }
        }
    }

    due = number_of_unpaid_months*maintenance + number_of_late_months*fine;
    printf("%d\n",due);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
