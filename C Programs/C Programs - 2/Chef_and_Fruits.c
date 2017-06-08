#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define abs(x) ( (x) > 0 ? (x) : (0 - (x)) )

void solve()
{
    int no_of_apples, no_of_oranges, gold_coins, no_of_purchases;
    scanf("%d %d %d", &no_of_apples, &no_of_oranges, &gold_coins);

    no_of_purchases = min(abs(no_of_apples - no_of_oranges), gold_coins);
    printf("%d\n",abs(no_of_apples - no_of_oranges) - no_of_purchases);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

