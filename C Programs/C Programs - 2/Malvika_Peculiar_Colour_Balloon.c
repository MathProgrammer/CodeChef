#include <stdio.h>

#define MAX_LENGTH 100 + 1
#define NO_OF_COLOURS 2
#define min(a, b) (a < b ? a : b)

void solve()
{
    char balloons[MAX_LENGTH];
    int i, colour[NO_OF_COLOURS] = {0};
    scanf("%s", balloons);

    for(i = 0; balloons[i] != '\0'; i++)
        colour[balloons[i] - 'a']++;

    printf("%d\n", min(colour[0], colour[1]));
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

