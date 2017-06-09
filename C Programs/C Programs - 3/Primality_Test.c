#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    int is_prime = true, i, number;
    scanf("%d",&number);

    for(i = 2; i*i <= number ; i++)
    {
        if(number%i == 0)
        {
            is_prime = false; break;
        }
    }

    printf(is_prime ? "yes\n" : "no\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
