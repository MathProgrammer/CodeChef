#include <stdio.h>

void solve()
{
    int width, height, area, i, no_of_pairs = 0;

    scanf("%d %d %d", &width, &height, &area);

    for(i = 1; i*i <= area; i++)
    {
        if(area%i == 0)
        {
            if(i*i == area)
            {
                if(i <= width  && i <= height)
                    no_of_pairs++;
            }
            else
            {
                if(i <= width && area/i <= height) //(x, y)
                    no_of_pairs++;
                if(i <= height && area/i <= width) //(y, x)
                    no_of_pairs++;
            }
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

