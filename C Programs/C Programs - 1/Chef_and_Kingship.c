#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a < b ? a : b)

int population[100001];
void solve()
{
    int no_of_cities, minimum_population = 1e6 + 1, minimum_population_city = -1, i;
    long long minimum_cost = 0LL;

    scanf("%d", &no_of_cities);
    for(i = 0; i < no_of_cities; i++)
    {
        scanf("%d", (population + i) );

        if(population[i] < minimum_population)
            minimum_population = population[i], minimum_population_city = i;
    }

    for(i = 0; i < no_of_cities; i++)
    {
        minimum_cost += (minimum_population_city != i ? minimum_population*1LL*population[i] : 0);
    }

    printf("%lld\n",minimum_cost);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
