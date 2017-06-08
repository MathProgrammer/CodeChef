#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 7 + 1

int main()
{
    char number[MAX_LENGTH];
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        scanf("%s",number);
        printf("%d\n", (number[0] - '0' + number[strlen(number) - 1] - '0') );
    }
    return 0;
}
