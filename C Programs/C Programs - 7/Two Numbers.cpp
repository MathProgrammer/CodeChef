#include <stdio.h>
#include <algorithm>

using namespace std;

void solve()
{
    int alice, bob, number_of_turns;
    scanf("%d %d %d", &alice, &bob, &number_of_turns);

    if(number_of_turns%2 == 1)
        alice *= 2;

    printf("%d\n", max(alice, bob)/min(alice, bob));
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
