#include <stdio.h>

void solve()
{
    int size_of_set, i;
    scanf("%d", &size_of_set);

    for(i = 1; i <= size_of_set; i++)
    {
        printf("%d ", (2*i - 1));
    }
    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
