#include <cstdio>
#include <cstring>

#define max(a, b) (a > b ? a : b)
#define MAX_LENGTH 100000 + 1

void solve()
{
    char sequence[MAX_LENGTH];
    scanf("%s", sequence);

    int maximum_sign_run = 0, length = strlen(sequence), i, j;

    for(i = 0; i < length; i = j)
    {
        int no_of_greater_than = 0;
        for(j = i; sequence[j] == '<' || sequence[j] == '='; j++)
        {
            no_of_greater_than += (sequence[j] == '<');
        }

        int no_of_less_than = 0;
        for(; sequence[j] == '>' || sequence[j] == '='; j++) //Pick off from where the previous loop ended.
        {
            no_of_less_than += (sequence[j] == '>');
        }

        maximum_sign_run = max(maximum_sign_run, max(no_of_greater_than, no_of_less_than));

    }
    printf("%d\n", maximum_sign_run + 1);

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
