#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b) );
}

void solve()
{
    int number_of_elements, element_i, array_gcd;
    scanf("%d", &number_of_elements);

    for(int i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &element_i);
        array_gcd = (i == 1 ? element_i : gcd(array_gcd, element_i) );
    }

    long long min_sum = array_gcd*1LL*number_of_elements;
    printf("%lld\n", min_sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
