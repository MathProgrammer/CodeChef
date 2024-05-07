#include <cstdio>

void solve()
{
    int no_of_elements, m;
    scanf("%d %d", &no_of_elements, &m);

    int m_multiples = 0;

    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        m_multiples += (element%m == 0);
    }

    int no_of_subsequences = (1 << m_multiples) - 1;
    printf("%d\n", no_of_subsequences);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
