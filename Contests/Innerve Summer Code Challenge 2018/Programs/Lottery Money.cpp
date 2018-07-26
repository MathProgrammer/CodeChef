#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_cities, money;
    scanf("%d %d", &no_of_cities, &money);

    vector <int> cost(no_of_cities + 1);
    for(int i = 1; i <= no_of_cities; i++)
        scanf("%d", &cost[i]);

    long long maximum_cities = 0, cost_here = 0, money_saved = money;
    int left = 0, right = 1;

    while(right <= no_of_cities)
    {
        cost_here += cost[right];

        while(cost_here > money)
        {
            cost_here -= cost[left];
            left++;
        }

        int cities = right - (left - 1);
        if(cities > maximum_cities || (cities == maximum_cities && money - cost_here < money_saved))
        {
            maximum_cities = cities;
            money_saved = money - cost_here;
        }

        right++;
    }

    printf("%lld %lld\n", maximum_cities, money_saved);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
