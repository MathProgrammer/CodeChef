#include <iostream>

using namespace std;

void solve()
{
    int no_of_periods, free_time, bill = 0;
    cin >> no_of_periods >> free_time;

    for(int i = 1; i <= no_of_periods; i++)
    {
        int download_i, period_i;

        cin >> period_i >> download_i;

        if(free_time >= period_i)
        {
            free_time -= period_i;
        }
        else
        {
            bill += (period_i - free_time)*download_i;
            free_time = 0;
        }
    }
    cout << bill << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
