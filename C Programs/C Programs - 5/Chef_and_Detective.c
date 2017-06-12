#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0
int is_somebody_boss[MAX_LENGTH] = {false};

int main()
{
    int number_of_criminals, i, boss_i;
    scanf("%d", &number_of_criminals);

    for(i = 1; i <= number_of_criminals; i++)
    {
        scanf("%d", &boss_i);
        is_somebody_boss[boss_i] = true;
    }

    for(i = 1; i <= number_of_criminals; i++)
        if(is_somebody_boss[i] == false)
            printf("%d ",i);

    return 0;
}
