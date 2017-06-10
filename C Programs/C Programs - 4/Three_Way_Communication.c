#include <stdio.h>

#define true 1
#define false 0

int can_communicate(int point_1[], int point_2[], int range)
{
    int x1 = point_1[0], x2 = point_2[0], y1 = point_1[1], y2 = point_2[1];

    if((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= range*range)
        return true;
    else
        return false;
}

void solve()
{
    int range, can_1_and_2_communicate, can_2_and_3_communicate, can_1_and_3_communicate, three_way_communication_possible = false;
    int point_1[2], point_2[2], point_3[2];

    scanf("%d", &range);
    scanf("%d %d", &point_1[0], &point_1[1]);
    scanf("%d %d", &point_2[0], &point_2[1]);
    scanf("%d %d", &point_3[0], &point_3[1]);

    can_1_and_2_communicate = can_communicate(point_1, point_2, range);
    can_2_and_3_communicate = can_communicate(point_2, point_3, range);
    can_1_and_3_communicate = can_communicate(point_3, point_1, range);

    if( ( can_1_and_2_communicate && can_2_and_3_communicate ) || ( can_2_and_3_communicate && can_1_and_3_communicate ) ||
        ( can_1_and_2_communicate && can_1_and_3_communicate ) )
    {
        three_way_communication_possible = true;
    }
    printf(three_way_communication_possible ? "yes\n" : "no\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
