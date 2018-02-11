#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, no_of_partitions;
    scanf("%d %d", &no_of_elements, &no_of_partitions);

    vector <int> element(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <long long> costs;
    for(int i = 1; i < no_of_elements; i++)
        costs.push_back(element[i] + element[i + 1]);

    sort(all(costs));

    no_of_partitions--;

    long long minimum_cost = element[1] + element[no_of_elements];
    for(int i = 0; i < no_of_partitions; i++)
        minimum_cost += costs[i];

    long long maximum_cost = element[1] + element[no_of_elements];
    for(int i = costs.size() - 1; i >= costs.size() - no_of_partitions; i--)
        maximum_cost += costs[i];

    printf("%lld %lld\n", minimum_cost, maximum_cost);

    return 0;
}

