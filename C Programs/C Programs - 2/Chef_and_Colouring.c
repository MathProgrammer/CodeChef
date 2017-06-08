#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define MAX_ROOMS 100000 + 1

void solve()
{
    int no_of_red = 0, no_of_blue = 0, no_of_green = 0, no_of_rooms, repainted_rooms, i;
    char room_colour[MAX_ROOMS];
    scanf("%d %s",&no_of_rooms, room_colour);

    for(i = 0; i < no_of_rooms; i++)
    {
        if(room_colour[i] == 'R')
            no_of_red++;
        else if(room_colour[i] == 'G')
            no_of_green++;
        else if(room_colour[i] == 'B')
            no_of_blue++;
    }

    repainted_rooms = no_of_rooms - max(no_of_blue, max(no_of_green, no_of_red));
    printf("%d\n",repainted_rooms);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
