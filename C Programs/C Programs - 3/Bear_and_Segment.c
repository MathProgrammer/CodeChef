#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0

void solve()
{
    char segment[MAX_LENGTH];
    int valid = true, i, last_1_index = -1;
    scanf("%s", segment);

    for(i = 0; segment[i] != '\0' ; i++)
    {
        if(segment[i] == '1')
        {
            if(last_1_index != -1 && last_1_index != i-1)
            {
                valid = false; break;
            }
            last_1_index = i;
        }
    }

    printf(valid && last_1_index != -1 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
