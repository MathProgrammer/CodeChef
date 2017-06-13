#include <stdio.h>
#include <string.h>

#define NO_OF_SEATS 8 + 2
#define MAX_LENGTH 2 + 1

int get_partner(int seat_number)
{
    switch(seat_number%8)
    {
        case 1:
        case 2 :
        case 3 :
                return (seat_number + 3);

        case 4:
        case 5 :
        case 6 :
                return (seat_number - 3);

        case 7: return (seat_number + 1);

        case 0: return (seat_number - 1);
    }
}

void solve()
{
    char seat_position[NO_OF_SEATS][MAX_LENGTH];
    int seat_number, partner_seat_number;

    scanf("%d", &seat_number);

    strcpy(seat_position[1], "LB"); strcpy(seat_position[4], "LB");
    strcpy(seat_position[2], "MB"); strcpy(seat_position[5], "MB");
    strcpy(seat_position[3], "UB"); strcpy(seat_position[6], "UB");
    strcpy(seat_position[7], "SL");
    strcpy(seat_position[0], "SU");

    partner_seat_number = get_partner(seat_number);


    printf("%d%s\n", partner_seat_number, seat_position[partner_seat_number%8]);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}

