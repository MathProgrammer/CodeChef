#include <iostream>

using namespace std;

void solve()
{
    int no_of_piles, pile_i;
    char first_player[3 + 1];
    cin >> no_of_piles >> first_player;

    for(int i = 1; i <= no_of_piles; i++)
        cin >> pile_i;

    cout << ( (no_of_piles == 1 && pile_i%2 == 0 && first_player[1] == 'e') ? "Dee\n" : "Dum\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
