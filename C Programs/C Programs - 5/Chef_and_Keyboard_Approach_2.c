#include <stdio.h>

void solve()
{
    int width, height, area, x, no_of_pairs = 0;

    scanf("%d %d %d", &width, &height, &area);

    for(x = 1; x <= width; x++)
    {
        if(area%x == 0 && area/x <= height)
        {
            no_of_pairs++;
        }
    }

    printf("%d\n", no_of_pairs);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
