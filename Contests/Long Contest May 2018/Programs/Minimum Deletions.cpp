#include <cstdio>
 
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
 
int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}
 
void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
 
    int array_gcd;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int a_i;
        scanf("%d", &a_i);
 
        array_gcd = (i == 1 ? a_i : gcd(a_i, array_gcd));
    }
 
    int no_of_deletions = (array_gcd == 1 ? 0 : -1);
    printf("%d\n", no_of_deletions);
}
 
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
 
    while(no_of_test_cases--)
        solve();
 
    return 0;
}
