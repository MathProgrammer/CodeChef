#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y)
{
    if(min(x, y) == 0)
        return max(x, y);
    else
        return gcd(max(x, y)%min(x, y), min(x, y));
}

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    int array_gcd;
    for(int i = 1; i <= no_of_elements; i++)
    {
        array_gcd = (i == 1 ? A[i] : gcd(array_gcd, A[i]));
    }

    printf(array_gcd == 1 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
