#include <cstdio>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> weights(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &weights[i]);

    vector <long long> weight_sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        weight_sum[i] = weight_sum[i - 1] + weights[i];

    map <int, int> frequency;
    long long maximum_segment_sum = 0;

    int left = 1, right = 1;
    while(right <= no_of_elements)
    {
        frequency[A[right]]++;

        while(frequency[A[right]] == 2)
        {
            frequency[A[left]]--;

            left++;
        }

        long long segment_sum = weight_sum[right] - weight_sum[left - 1];

        maximum_segment_sum = max(maximum_segment_sum, segment_sum);

        right++;
    }

    printf("%lld\n", maximum_segment_sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
