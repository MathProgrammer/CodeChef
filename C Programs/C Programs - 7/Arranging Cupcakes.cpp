#include <cstdio>
#include <math.h>

void solve()
{
    int no_of_cupcakes, i;
    scanf("%d", &no_of_cupcakes);

    for(i = (int)sqrt(no_of_cupcakes); i >= 1; i--)
        if(no_of_cupcakes%i == 0)
            break;

    printf("%d\n", (no_of_cupcakes/i - i));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
