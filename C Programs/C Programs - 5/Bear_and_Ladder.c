#include <stdio.h>

#define true 1
#define false 0
#define abs(x) ( (x) > 0 ? (x) : (0 - (x)) )
#define max(a, b) (a > b ? a : b)

void solve()
{
    int city_1, city_2, connected = false;
    scanf("%d %d",&city_1, &city_2);

    if( (city_1%2 == 0 && city_2%2 == 0) || (city_1%2 == 1 && city_2%2 == 1) )
    {
        if(abs(city_1 - city_2) == 2)
            connected = true;
    }
    else //Different parity
    {
        if(abs(city_1 - city_2) == 1 && max(city_1, city_2)%2 == 0)
            connected = true;
    }

    printf(connected ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
