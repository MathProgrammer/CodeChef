#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    int no_of_rows, no_of_columns, first_player_wins;
    scanf("%d %d",&no_of_rows, &no_of_columns);

    //After every turn of Player 1, the number of pieces is even. So, the first player will win if the final number of pieces is even since each turn
    //increases the number of pieces by one.
    first_player_wins = (no_of_rows*1LL*no_of_columns%2 == 0 ? true : false);

    printf(first_player_wins ? "Yes\n" : "No\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
