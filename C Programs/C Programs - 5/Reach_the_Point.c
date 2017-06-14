#include <stdio.h>

#define abs(x) ( (x) > 0 ? (x) : (0 - (x)) )
#define min(a, b) (a < b ? a : b)

int straight_line(int x, int y)
{
    int x_steps, y_steps;

    x_steps = (x%2 == 0 ? 2*x : 2*x + 1);
    y_steps = (y%2 == 0 ? 2*y : 2*y - 1);

    return (x_steps + y_steps);
}

void solve()
{
    int x, y, z, number_of_steps;
    scanf("%d %d",&x, &y);
    x = abs(x);
    y = abs(y);
    z = min(x, y);

     //It is possible to go from (0,0) to (1,1) in 2 moves ... So, we go till (min, min) first ... After that, go like a square wave
    number_of_steps = 2*z + straight_line(x-z, y-z);

    printf("%d\n",number_of_steps);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
