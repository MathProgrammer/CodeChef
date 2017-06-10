#include <stdio.h>

#define MAX_LENGTH 100 + 1

void solve()
{
    char string_1[MAX_LENGTH], string_2[MAX_LENGTH];
    int i, minimum_differences = 0, maximum_differences = 0;
    scanf("%s %s",string_1, string_2);

    for(i = 0; string_1[i] != '\0'; i++)
    {
        if(string_1[i] == '?' || string_2[i] == '?')
            maximum_differences++;
        else if(string_1[i] != string_2[i])
            minimum_differences++, maximum_differences++;
    }

    printf("%d %d\n",minimum_differences, maximum_differences);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
