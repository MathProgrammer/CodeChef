#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    int number_of_elements, others = 0, i, number_i, zeroes = 0, ones = 0, minus_ones = 0, is_beautiful = true;

    scanf("%d",&number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);

        if(number_i == 1)
            ones++;
        else if(number_i == 0)
            zeroes++;
        else if(number_i == -1)
            minus_ones++;
        else
            others++;
    }

    if( (others > 1) || (minus_ones > 1 && ones == 0) || (minus_ones > 0 && others > 0))
        is_beautiful = false;

    printf(is_beautiful ? "yes\n" : "no\n");
}

int main()
{
    int no_of_dishes;
    scanf("%d", &no_of_dishes);
    while(no_of_dishes-- != 0)
        solve();

    return 0;
}

