#include <stdio.h>

void solve()
{
    const int discount_threshold = 1000;
    int price, quantity;
    double final_amount;
    scanf("%d %d", &price, &quantity);

    final_amount = (price > discount_threshold ? 0.9*price*quantity : price*quantity);
    printf("%6f\n",final_amount);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
