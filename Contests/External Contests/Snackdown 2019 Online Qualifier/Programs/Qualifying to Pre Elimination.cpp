#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <int> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &A[i]);

    sort(all(A));
    reverse(all(A));

    int qualified_teams = k;
    for(int i = k; i < no_of_elements; i++)
    {
        if(A[i] != A[k - 1])
            break;

        qualified_teams++;
    }

    printf("%d\n", qualified_teams);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
