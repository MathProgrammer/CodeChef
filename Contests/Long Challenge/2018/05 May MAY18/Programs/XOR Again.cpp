#include <cstdio>

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int diagonal_xor = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        diagonal_xor ^= (a_i + a_i);
    }

    printf("%d\n", diagonal_xor);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
