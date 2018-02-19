#include <cstdio>

long long square(long long n)
{
    return n*n;
}

void solve()
{
    int x1, y1, radius1, x2, y2, radius2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &radius1, &x2, &y2, &radius2);

    long long distance_squared = square(x1 - x2) + square(y1 - y2);

    if(distance_squared == square(radius1 + radius2))
        printf("tangential\n");
    else if(distance_squared < square(radius1 + radius2))
        printf("overlapping\n");
    else if(distance_squared > square(radius1 + radius2))
        printf("not overlapping\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

