#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

void solve()
{
    int A, B, C, middle;
    scanf("%d %d %d", &A, &B, &C);

    middle = (A + B + C) - ( max(A, max(B, C)) + min(A, min(B, C)) );

    printf("%d\n",middle);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
