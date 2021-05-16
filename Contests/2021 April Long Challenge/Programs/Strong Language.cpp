
#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int length, k;
    string S;
    cin >> length >> k >> S;

    int consecutive = 0, max_consecutive = 0;

    for(int i = 0; i < length; i++)
    {
        consecutive = (S[i] == '*' ? consecutive + 1 : 0);

        max_consecutive = max(max_consecutive, consecutive);
    }

    cout << (k <= max_consecutive ? "Yes" : "No") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
