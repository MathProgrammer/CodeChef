#include <stdio.h>

#define true 1
#define false 0

int reverse(int num)
{
    const int base = 10;
    int rev = 0;

    while(num > 0)
    {
        rev = (rev*base) + (num%base);
        num = num/base;
    }

    return rev;
}

int is_Palindrome(int num)
{
    if(num == reverse(num))
        return true;
    else
        return false;
}

void solve()
{
    int left, right, i, sum = 0;
    scanf("%d %d",&left, &right);

    for(i = left; i <= right ; i++)
    {
        sum += (is_Palindrome(i) ? i : 0);
    }

    printf("%d\n",sum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
