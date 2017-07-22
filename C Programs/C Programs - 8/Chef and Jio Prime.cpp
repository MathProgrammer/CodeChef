#include <cstdio>

int main()
{
    int tower_x, tower_y, chef_x, chef_y, range;
    scanf("%d %d %d %d %d", &tower_x, &tower_y, &chef_x, &chef_y, &range);

    long long x_difference = tower_x - chef_x, y_difference = tower_y - chef_y;

    printf(range*1LL*range >= x_difference*x_difference + y_difference*y_difference ? "Unlimited Hoyenga" : "Nahi Hoyenga");
    return 0;
}
