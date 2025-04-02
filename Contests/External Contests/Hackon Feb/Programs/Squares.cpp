#include <iostream>

using namespace std;

void solve()
{
    long long n;
    cin >> n;

    long long expectation = (((n + 2)*(n + 1))/2)/(2*n + 1);
    cout << expectation << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
