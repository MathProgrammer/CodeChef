#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    double k1, k2, k3, v;
    cin >> k1 >> k2 >> k3 >> v;

    const int DISTANCE = 100,RECORD = 958;

    double speed = k1*k2*k3*v;
    int time = round(100*DISTANCE/speed);

    cout << (time < RECORD ? "Yes" : "No") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
