#include <stdio.h>

void solve()
{
    int x_1, y_1, x_2, y_2;

    scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);

    if(x_1 != x_2 && y_1 != y_2)
    {
        printf("sad\n");
    }
    else if(x_1 == x_2)
    {
        printf(y_1 < y_2 ? "up\n" : "down\n");
    }
    else if(y_1 == y_2)
    {
        printf(x_1 < x_2 ? "right\n" : "left\n");
    }
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}

