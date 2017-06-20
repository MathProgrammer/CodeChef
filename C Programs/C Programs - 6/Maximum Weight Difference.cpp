#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int number_of_weights, i, total_weight = 0, first_k_weights = 0, last_k_weights = 0, k;
    int difference_1, difference_2;
    scanf("%d %d", &number_of_weights, &k);

    vector <int> weight(number_of_weights + 1);
    for(i = 1; i <= number_of_weights; i++)
        scanf("%d", &weight[i]);

    sort(weight.begin(), weight.end());

    for(i = 1; i <= number_of_weights; i++)
    {
        total_weight += weight[i];

        first_k_weights += (i <= k ? weight[i] : 0);
        last_k_weights += (i > number_of_weights - k ? weight[i] : 0);
    }

    difference_1 = abs(first_k_weights - (total_weight - first_k_weights));
    difference_2 = abs(last_k_weights - (total_weight - last_k_weights));

    printf("%d\n", max(difference_1, difference_2) );
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
