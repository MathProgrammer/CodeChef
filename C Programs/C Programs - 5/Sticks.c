#include <stdio.h>

#define MAX_LENGTH 1000 + 1

void solve()
{
    int frequency[MAX_LENGTH] = {0};
    int number_of_sticks, i, stick_i, largest_stick = 0, second_largest_stick = 0;

    scanf("%d", &number_of_sticks);

    for(i = 0; i < number_of_sticks; i++)
    {
        scanf("%d", &stick_i);
        frequency[stick_i]++;
    }

    for(i = MAX_LENGTH - 1; i >= 1 && second_largest_stick == 0 ; i--) //We keep going till we find the two longest sticks
    {
        if(frequency[i] >= 4)
        {
            if(largest_stick == 0)
                largest_stick = second_largest_stick = i;
            else
                second_largest_stick = i;
        }
        if(frequency[i] >= 2)
        {
            if(largest_stick == 0)
                largest_stick = i;
            else if(second_largest_stick == 0)
                second_largest_stick = i;
        }
    }

    printf("%d\n", (second_largest_stick == 0 ? -1 : largest_stick*second_largest_stick));
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
