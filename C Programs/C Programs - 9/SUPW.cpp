#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_days;
    scanf("%d", &no_of_days);

    vector <int> time(no_of_days + 5, 0);
    for(int i = 1; i <= no_of_days; i++)
        scanf("%d", &time[i]);

    const int WORK = 0, NO_WORK = 1;
    int minimum_time_starting[no_of_days + 5][2];


    for(int i = no_of_days; i >= 1; i--)
    {
        if(i == no_of_days || i == no_of_days - 1)
        {
            minimum_time_starting[i][WORK] = time[i];
            minimum_time_starting[i][NO_WORK] = 0;
            continue;
        }

        minimum_time_starting[i][NO_WORK] = min(minimum_time_starting[i + 1][WORK], minimum_time_starting[i + 2][WORK]);

        minimum_time_starting[i][WORK] = time[i] + min(minimum_time_starting[i + 1][WORK], minimum_time_starting[i + 1][NO_WORK]);
    }

    int total_time = min(minimum_time_starting[1][WORK], minimum_time_starting[1][NO_WORK]);
    printf("%d\n", total_time);

    return 0;
}
