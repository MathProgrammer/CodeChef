#include <stdio.h>
#include <algorithm>

#define MAX_PILES 100000 + 1
using namespace std;

int no_of_stones_in_pile[MAX_PILES];
void solve()
{
    int no_of_piles,i;
    long long chef_stones = 0LL;
    scanf("%d", &no_of_piles);

    for(i = 0; i < no_of_piles; i++)
        scanf("%d", &no_of_stones_in_pile[i]);

    sort(no_of_stones_in_pile, no_of_stones_in_pile + no_of_piles);//Ascending order

    for(i = no_of_piles - 1; i >= 0; i = i - 2)
        chef_stones += no_of_stones_in_pile[i];

    printf("%lld\n", chef_stones);

}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
