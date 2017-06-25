#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

void solve()
{
    int previous_car_speed = INT_MAX, current_car_speed, number_of_cars, current_car_max_speed;;
    scanf("%d", &number_of_cars);

    int no_of_cars_at_max_speed = 0;
    for(int i = 1; i <= number_of_cars; i++)
    {
        scanf("%d", &current_car_max_speed);

        current_car_speed = min(previous_car_speed, current_car_max_speed);

        no_of_cars_at_max_speed += (current_car_speed == current_car_max_speed);

        previous_car_speed = current_car_speed;
    }

    printf("%d\n", no_of_cars_at_max_speed);
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

