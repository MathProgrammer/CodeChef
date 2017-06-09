#include <stdio.h>

#define MAX_LENGTH 100000 + 1

void solve()
{
    int no_of_1s = 0, length;
    char number[MAX_LENGTH];
    scanf("%s",number);

    for(length = 0; number[length] != '\0'; length++)
        if(number[length] == '1')
            no_of_1s++;

    printf(no_of_1s == 1 || no_of_1s + 1 == length ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
