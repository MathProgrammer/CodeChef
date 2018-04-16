#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

int main()
{
    int no_of_teams;
    scanf("%d", &no_of_teams);

    vector <int> strength(no_of_teams + 1, 0);
    for(int i = 1; i <= no_of_teams; i++)
        scanf("%d", &strength[i]);

    sort(all(strength));

    long long total_revenue = 0;
    for(int i = 1; i <= no_of_teams; i++)
    {
        long long weaker_teams = i - 1, stronger_teams = no_of_teams - i;

        total_revenue += strength[i]*(weaker_teams - stronger_teams);
    }

    printf("%lld\n", total_revenue);
    return 0;
}
