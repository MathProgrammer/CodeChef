#include <stdio.h>

int main()
{
    int no_of_test_cases, n;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        scanf("%d", &n);
        printf(n < 10 ? "What an obedient servant you are!\n" : "-1\n");
    }

    return 0;
}
