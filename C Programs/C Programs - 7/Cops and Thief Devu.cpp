#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    const int no_of_houses = 100;
    int safe_houses = false, no_of_cops, houses_per_minutes, no_of_minutes;
    scanf("%d %d %d", &no_of_cops, &houses_per_minutes, &no_of_minutes);

    vector <int> cop_houses(no_of_cops + 1);
    for(int i = 1; i <= no_of_cops; i++)
        scanf("%d", &cop_houses[i]);

    sort(cop_houses.begin(), cop_houses.end());

    vector <int> reachable(no_of_houses + 1, false);
    for(int cop = 1; cop <= no_of_cops; cop++)
    {
        for(int j = cop_houses[cop]; j <= cop_houses[cop] + houses_per_minutes*no_of_minutes && j <= no_of_houses; j++)
            reachable[j] = true;

        for(int j = cop_houses[cop]; j >= cop_houses[cop] - houses_per_minutes*no_of_minutes && j >= 1; j--)
            reachable[j] = true;
    }

    for(int i = 1; i <= no_of_houses; i++)
        safe_houses += (reachable[i] == false);

    printf("%d\n", safe_houses);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
