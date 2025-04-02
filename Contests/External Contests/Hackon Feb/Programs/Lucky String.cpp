#include <iostream>
#include <string>

using namespace std;

string reverse(string S)
{
    string R;

    for(int i = S.size() - 1; i  >= 0; i--)
        R += S[i];

    return R;
}

void solve()
{
    long long index;
    cin >> index;

    index++;

    string lucky_string;

    do
    {
        lucky_string += (index%2 == 0 ? '5' : '8');
        index = index >> 1;

    }
    while(index > 1);

    lucky_string = reverse(lucky_string);
    cout << lucky_string << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
