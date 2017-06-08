#include <stdio.h>

#define NO_OF_DENOMINATIONS 6

void solve()
{
    int denomination[NO_OF_DENOMINATIONS] = {1, 2, 5, 10, 50, 100}, no_of_notes, current_denomination, amount;
    scanf("%d", &amount);

    no_of_notes = 0;
    for(current_denomination = NO_OF_DENOMINATIONS - 1; amount > 0; current_denomination--)
    {
        while(amount >= denomination[current_denomination])
        {
            amount = amount - denomination[current_denomination];
            no_of_notes++;
        }
    }

    printf("%d\n",no_of_notes);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
