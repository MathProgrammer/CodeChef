#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n & (1LL << bit)) != 0);
}

void display_binary(long long n)
{
    for(int bit = 63; bit >= 0; bit--)
    {
        cout << (is_bit_set(n, bit) ? "1" : "0");
    }

    cout << "\n";
}

long long all_ones(long long n)
{
    return ((1LL << n) - 1);
}

void solve()
{
    long long left, right;
    cin >> left >> right;

    const int MAX_BIT = 62;
    long long answer = right;
    long long prefix = 0, suffix = 0;
    for(int bit = MAX_BIT; bit >= 0; bit--)
    {
        if(is_bit_set(right, bit) && !is_bit_set(left, bit))
        {
            suffix = all_ones(bit + 1);

            answer = prefix|suffix;

            break;
        }
        else if(is_bit_set(right, bit))
        {
            prefix |= (1LL << bit);
        }
    }

    cout << answer << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;


	while(no_of_test_cases--)
    {
        solve();
    }

	return 0;
}

