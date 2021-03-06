#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_hills, up_limit, down_limit;
    scanf("%d %d %d", &no_of_hills, &up_limit, &down_limit);

    vector <int> height(no_of_hills + 1, 0);
    for(int i = 1; i <= no_of_hills; i++) scanf("%d", &height[i]);

    int reached_hill = no_of_hills, parachute_used = false;

    for(int i = 1; i < no_of_hills; i++)
    {
        if(height[i + 1] > height[i])
        {
            if(height[i + 1] - height[i] > up_limit)
            {
                reached_hill = i;
                break;
            }
        }
        else if(height[i + 1] < height[i])
        {
            if(height[i] - height[i + 1] > down_limit)
            {
                if(!parachute_used)
                {
                    parachute_used = true;

                }
                else
                {
                    reached_hill = i;
                    break;
                }
            }
        }
    }

    printf("%d\n", reached_hill);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
