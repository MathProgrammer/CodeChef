#include <cstdio>

void solve()
{
    int length_of_permutation;
    scanf("%d", &length_of_permutation);

    if(length_of_permutation%2 == 0)
    {
        for(int i = 1; i <= length_of_permutation; i++)
        {
            printf("%d ", i%2 == 1 ? i + 1 : i - 1);
        }
    }
    else
    {
        for(int i = 1; i <= length_of_permutation - 3; i++)
        {
            printf("%d ", i%2 == 1 ? i + 1 : i - 1);
        }
        printf("%d %d %d", length_of_permutation - 1, length_of_permutation, length_of_permutation - 2);
    }

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
