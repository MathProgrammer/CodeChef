#include <stdio.h>

void solve()
{
    int basic_salary;
    double gross_salary, da, hra;
    scanf("%d", &basic_salary);

    if(basic_salary < 1500)
    {
        //gross_salary = 2*basic_salaryda = 10, hra = 90 ... da + hra = basic
        printf("%d\n", (2*basic_salary));
    }
    else
    {
        da = 0.98*basic_salary;
        hra = 500;
        gross_salary = basic_salary + da + hra;
        printf("%g\n",gross_salary);
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
