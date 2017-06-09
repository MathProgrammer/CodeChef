#include <stdio.h>

int main()
{
    int no_of_test_cases;
    int num_1, num_2;

    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d", &num_1, &num_2);

        if(num_1 == num_2)
            printf("=\n");
        else
            printf(num_1 > num_2 ? ">\n" : "<\n");
    }
    return 0;
}
