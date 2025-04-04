#include <cstdio>

void solve()
{
    int no_of_recipies;
    scanf("%d", &no_of_recipies);

    double loss = 0;

    for(int i = 1; i <= no_of_recipies; i++)
    {
        double price, amount, discount;
        scanf("%lf %lf %lf", &price, &amount, &discount);

        double selling = price*(1 + discount/100);
        double discount_selling = selling*(1 - discount/100);

        double loss_here = price - discount_selling;

        loss += amount*loss_here;
    }

    printf("%.10lf\n", loss);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

