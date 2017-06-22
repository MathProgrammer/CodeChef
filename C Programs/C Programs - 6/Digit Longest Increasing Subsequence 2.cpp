#include <stdio.h>

void solve()
{
    int no_of_terms;
    scanf("%d", &no_of_terms);

    for(int i = 1; i <= no_of_terms; i++)
    {
        int sequence_term;
        scanf("%d", &sequence_term);
        printf("%d",sequence_term);
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
