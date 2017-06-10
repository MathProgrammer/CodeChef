#include <stdio.h>

int main()
{
    int withdrawal;
    float balance;
    scanf("%d %f", &withdrawal, &balance);

    if(withdrawal + 0.5 <= balance && withdrawal%5 == 0)
        balance -= (withdrawal + 0.5);

    printf("%.2f",balance);
    return 0;
}
