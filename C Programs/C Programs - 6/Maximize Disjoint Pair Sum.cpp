#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX_LENGTH 100000 + 1
using namespace std;

void solve()
{
    int no_of_elements, i, difference, elements[MAX_LENGTH];
    long long max_sum_upto[MAX_LENGTH] = {0};

    scanf("%d %d", &no_of_elements, &difference);
    for(i = 1; i <= no_of_elements; i++)
        scanf("%d", &elements[i]);

    sort(elements + 1, elements + no_of_elements + 1);

    max_sum_upto[0] = max_sum_upto[1] = 0;
    for(i = 2; i <= no_of_elements; i++)
    {
        max_sum_upto[i] = max_sum_upto[i - 1];

        if(elements[i] - elements[i - 1] < difference)
            max_sum_upto[i] = max(max_sum_upto[i - 2] + elements[i] + elements[i - 1], max_sum_upto[i - 1]);
    }

    printf("%lld\n",max_sum_upto[no_of_elements]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
