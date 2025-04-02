#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    int power_2 = 0, power_5 = 0;
    while(n%2 == 0)
    {
        n /= 2;
        power_2++;
    }

    while(n%5 == 0)
    {
        n /= 5;
        power_5++;
    }

    if(n > 1 || power_5 > power_2 || (2*power_5 < power_2))
    {
        cout << "No\n";

        return;
    }

    cout << "Yes\n";
    // x 5s and y 2s, 2x >= y >= x
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;


	for(int i = 1; i <= no_of_test_cases; i++)
    {
        solve();
    }

	return 0;
}


