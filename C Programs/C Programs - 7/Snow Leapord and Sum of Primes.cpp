#include <cstdio>

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);

        printf(n >= 2 ? "YES\n" : "NO\n");
    }
    return 0;
}
