#include <stdio.h>
#include <math.h>
int main()
{
    unsigned int no_of_test_cases, i, base, left_side;
    double minimum_right_side, maximum_right_side;
    scanf("%u",&no_of_test_cases);
    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%u %u", &base, &left_side);
        minimum_right_side = sqrt(left_side*left_side - base*base); //R is vertical = R^2 + b^2 = L^2
        maximum_right_side = sqrt(left_side*left_side + base*base); //L is vertical L^2 + b^2 = R^2
        printf("%.6f %.6f\n",minimum_right_side, maximum_right_side);
    }
    return 0;
}
