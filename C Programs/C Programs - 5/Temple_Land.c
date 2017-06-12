#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    int height_i, i, number_of_parts, valid = true;
    scanf("%d", &number_of_parts);

    if(number_of_parts%2 == 0)
         valid = false;

    for(i = 1; i <= number_of_parts; i++)
    {
        scanf("%d", &height_i);

        //If h_i is in first half = i, else it is, n - i + 1
        if(i <= number_of_parts/2 + 1 && height_i != i)
            valid = false;

        if(i > number_of_parts/2 + 1 && height_i != number_of_parts - i + 1 )
            valid = false;
    }

    printf(valid ? "yes\n" : "no\n");
}

int main()
{
    int number_of_strips;
    scanf("%d", &number_of_strips);

    while(number_of_strips--)
        solve();

    return 0;
}
