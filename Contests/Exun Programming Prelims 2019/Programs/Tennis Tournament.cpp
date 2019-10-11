#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    if(no_of_elements%2 == 0)
    {
        cout << "NO\n";

        return;
    }

    cout << "YES\n";
    int no_of_matches_won = (no_of_elements - 1)/2;

    for(int i = 1; i <= no_of_elements; i++)
    {
        int prefix = (i + no_of_matches_won > no_of_elements ? i + no_of_matches_won - no_of_elements: 0);

        for(int j = 1; j <= no_of_elements; j++)
        {
            if(j <= prefix)
            {
                cout << "1";
            }
            else if(j > prefix && j <= i)
            {
                cout << "0";
            }
            else if(j > i && j <= i + no_of_matches_won)
            {
                cout << "1";
            }
            else if(j > i + no_of_matches_won)
            {
                cout << "0";
            }
        }

        cout << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

