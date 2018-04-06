#include <cstdio>
#include <vector>

using namespace std;

int ceil(int n, int x)
{
    return (n/x + (n%x != 0));
}

int possible(vector <int> &piles, int speed, int limit_time)
{
    int time = 0;

    for(int i = 0; i < piles.size(); i++)
    {
        time += ceil(piles[i], speed);
    }

    return (time <= limit_time);
}

void solve()
{
    int no_of_piles, no_of_hours;
    scanf("%d %d", &no_of_piles, &no_of_hours);

    vector <int> pile(no_of_piles + 1);
    for(int i = 1; i <= no_of_piles; i++) scanf("%d", &pile[i]);

    int eating_speed;
    int left = 1, right = 1e9;

    while(left <= right)
    {
        int mid = (left + right) >> 1;

        if(possible(pile, mid, no_of_hours))
        {
            if(!possible(pile, mid - 1, no_of_hours))
            {
                eating_speed = mid;
                break;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d\n", eating_speed);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
