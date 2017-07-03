#include <cstdio>

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int left, right, n;
        scanf("%d %d %d", &left, &right, &n);

        printf("%d\n", (right/n - (left - 1)/n) );
    }
    return 0;
}
