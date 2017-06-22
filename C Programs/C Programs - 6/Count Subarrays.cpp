#include <stdio.h>
#include <vector>

using namespace std;

void solve()
{
    int number_of_elements, element_i, element_i_minus_1 = 0;
    long long no_of_subarrays = 0;
    scanf("%d", &number_of_elements);

    vector <int> no_of_non_decreasing_subarray_till(number_of_elements + 1, 0);

    for(int i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &element_i);

        no_of_non_decreasing_subarray_till[i] = (element_i >= element_i_minus_1 ? no_of_non_decreasing_subarray_till[i-1] + 1 : 1);

        element_i_minus_1 = element_i;
    }

    no_of_subarrays = 0;
    for(int i = 1; i <= number_of_elements; i++)
    {
        no_of_subarrays += no_of_non_decreasing_subarray_till[i];
    }

    printf("%lld\n", no_of_subarrays);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
