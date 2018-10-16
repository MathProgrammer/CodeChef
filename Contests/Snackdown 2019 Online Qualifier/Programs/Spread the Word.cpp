#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> S(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        S[i] = S[i - 1] + A[i];

    int p = 1, days = 0;

    while(p > 0 && p < no_of_elements)
    {
        days++;

        p += S[p];
    }

    printf("%d\n", days);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
