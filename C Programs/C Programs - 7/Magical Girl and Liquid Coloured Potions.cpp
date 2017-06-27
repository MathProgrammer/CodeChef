#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(),(v).end()

using namespace std;

void solve()
{
    int no_of_red_potions, no_of_blue_potions, no_of_green_potions, no_of_minutes;
    scanf("%d %d %d %d", &no_of_red_potions, &no_of_green_potions, &no_of_blue_potions, &no_of_minutes);

    vector <int> max_potions(3,0);
    int red_i, green_i, blue_i;

    for(int i = 1; i <= no_of_red_potions; i++)
    {
        scanf("%d", &red_i);
        max_potions[0] = max(max_potions[0], red_i);
    }

    for(int i = 1; i <= no_of_green_potions; i++)
    {
        scanf("%d", &green_i);
        max_potions[1] = max(max_potions[1], green_i);
    }

    for(int i = 1; i <= no_of_blue_potions; i++)
    {
        scanf("%d", &blue_i);
        max_potions[2] = max(max_potions[2], blue_i);
    }

    for(int minutes = 1; minutes <= no_of_minutes; minutes++)
    {
        sort(all(max_potions) );

        max_potions[2] = max_potions[2] >> 1;

    }

    sort(all(max_potions) );

    printf("%d\n", max_potions[2]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
