#include <cstdio>

void solve()
{
    double isha_speed, suhana_speed, maximum_distance;
    scanf("%lf %lf %lf", &isha_speed, &suhana_speed, &maximum_distance);

    double relative_speed = isha_speed + suhana_speed;

    double maximum_time = maximum_distance/relative_speed;

    printf("%lf\n", maximum_time);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
