#include <stdio.h>

#define MAX_LENGTH 50 + 1
#define NO_OF_ALPHABETS 26 + 1
#define max(a, b) (a > b ? a : b)

void solve()
{
    char string[MAX_LENGTH], frequency[NO_OF_ALPHABETS] = {0};
    int max_frequency = 0, i, length;

    scanf("%s", string);

    for(i = 0; string[i] != '\0'; i++)
        frequency[string[i] - 'a']++;

    length = i;

    for(i = 0; i < NO_OF_ALPHABETS; i++)
        max_frequency = max(max_frequency, frequency[i]);

    printf("%s\n", (2*max_frequency == length ? "YES" : "NO") );
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}

