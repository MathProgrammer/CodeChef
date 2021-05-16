#include <iostream>
#include <cmath>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

void solve()
{
    long long no_of_die;
    cin >> no_of_die;

    const long long SIDE_5 = (6 + 5 + 4 + 3 + 2), SIDE_4 = (6 + 5 + 4 + 3), SIDE_3 = (6 + 5 + 4), SIDE_2 = (6 + 5), EXTRA_TOP = 4;
    long long layers = ceil(no_of_die, 4), layer_contribution = 4*SIDE_2;

    long long total = (layers - 1)*layer_contribution;

    long long second_last = 0, last = 0;

    switch(no_of_die%4)
    {
        case 0 : last = 4*SIDE_3; break;
        case 1 : last = SIDE_5;
                 second_last = (layers >= 2 ? 3*EXTRA_TOP : 0); break;
        case 2 : last = 2*SIDE_4;
                 second_last = (layers >= 2 ? 2*EXTRA_TOP : 0); break;
        case 3 : last = 2*SIDE_4 + SIDE_3;
                 second_last = (layers >= 2 ? EXTRA_TOP : 0); break;
    }

    total += (second_last + last);

    cout << total << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
