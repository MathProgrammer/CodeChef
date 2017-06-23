#include <stdio.h>
#include <algorithm>
#define MAX_LENGTH 100000 + 1

using namespace std;

int get_balance(char sequence[])
{
    int max_balance = 0, balance = 0;

    for(int i = 0; sequence[i] != '\0'; i++)
    {
        balance += (sequence[i] == '(');
        balance -= (sequence[i] == ')');

        max_balance = max(max_balance, balance);
    }

    return max_balance;
}

void solve()
{
    int balance;
    char sequence[MAX_LENGTH];
    scanf("%s", sequence);

    balance = get_balance(sequence);

    for(int i = 1; i <= 2*balance; i++)
        printf(i <= balance ? "(" : ")");

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
