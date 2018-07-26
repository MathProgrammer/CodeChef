#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_containers, no_of_days;
    scanf("%d %d", &no_of_containers, &no_of_days);

    vector <int> containers_starting_at(no_of_containers + 2, 0);
    while(no_of_days--)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        containers_starting_at[left]++;
        containers_starting_at[right + 1]--;
    }

    vector <int> containers(no_of_containers + 1, 0);
    for(int i = 1; i <= no_of_containers; i++)
        containers[i] = containers[i - 1] + containers_starting_at[i];

    sort(all(containers));

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int minimum_containers;
        scanf("%d", &minimum_containers);

        int first_ineligible_container = (upper_bound(all(containers), minimum_containers - 1) - containers.begin() - 1);
        int answer = no_of_containers - first_ineligible_container;

        printf("%d\n", answer);
    }

    return 0;
}
