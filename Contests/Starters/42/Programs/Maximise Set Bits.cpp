#include <iostream>
#include <vector>
using namespace std;

int is_bit_set(int n, int bit)
{
    return ( ( n&(1 << bit) ) != 0 );
}

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;

    const int NO_OF_BITS = 31;
    long long total_bits_set = 0;
    for(int bit = 0; bit < NO_OF_BITS & k > 0; bit++)
    {
        int bits_set_here = 0;
        if(k <= no_of_elements)
        {
            bits_set_here = k;
        }
        else
        {
            bits_set_here = no_of_elements;

            if(k%2 != no_of_elements%2)
            {
                bits_set_here--;
            }
        }

        total_bits_set += bits_set_here;
        k -= bits_set_here;

        k /= 2;
    }

    cout << total_bits_set << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
	    solve();

	return 0;
}

