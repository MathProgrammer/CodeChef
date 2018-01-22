#include <cstdio>
#include <vector>

#define min_3(a, b, c) min(a, min(b, c))
using namespace std;

int main()
{
    int no_of_days;
    scanf("%d", &no_of_days);

    vector <int> time(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
        scanf("%d", &time[i]);

    vector <int> minimum_time_starting(no_of_days + 1, 0);

    for(int i = no_of_days; i >= 1; i--)
    {
        if(i >= no_of_days - 1)
        {
            minimum_time_starting[i] = 0;
            continue;
        }

        minimum_time_starting[i] = min_3(time[i] + minimum_time_starting[i + 1], time[i + 1] + minimum_time_starting[i + 2],
                                         time[i + 2] + minimum_time_starting[i + 3]);
    }

    printf("%d\n", minimum_time_starting[1]);

    return 0;
}
