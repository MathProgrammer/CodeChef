#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    long long k, b;
    scanf("%d %lld %lld", &no_of_elements, &k, &b);

    vector <long long> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++) scanf("%lld", &A[i]);

    sort(all(A));

    long long last_element = A[1];
    int subsequence_length = 1, last_element_position = 1;

    while(last_element*k + b <= A[no_of_elements] && last_element_position < no_of_elements)
    {
        long long next_element = last_element*k + b;

        int i = last_element_position + 1;
        while(i <= no_of_elements && A[i] < next_element)
            i++;

        last_element = A[i];
        last_element_position = i;

        subsequence_length++;
    }

    printf("%d\n", subsequence_length);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}



