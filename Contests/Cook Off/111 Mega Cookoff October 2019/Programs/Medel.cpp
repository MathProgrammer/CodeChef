#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector <int> A(n + 1, 0);
    for(int i = 1; i <= n ;i++)
        cin >> A[i];

    int minimum = A[1], maximum = A[1];

    for(int i = 1; i <= n; i++)
    {
        minimum = min(A[i], minimum);
        maximum = max(A[i], maximum);
    }

    for(int i = 1; i <= n; i++)
    {
        if(A[i] == minimum)
        {
            cout << minimum << " " << maximum << "\n";

            return;
        }

        if(A[i] == maximum)
        {
            cout << maximum << " " << minimum << "\n";

            return;
        }
    }
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
