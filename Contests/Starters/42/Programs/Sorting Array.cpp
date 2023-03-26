#include <iostream>
#include <vector>
using namespace std;

int is_bit_set(int n, int bit)
{
    return ( ( n&(1 << bit) ) != 0 );
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> sorted_A(no_of_elements + 1);
    sorted_A[1] = 1e5;
    for(int i = 2; i <= no_of_elements; i++)
    {
        sorted_A[i] = sorted_A[i - 1] + 1;
    }

    const int NO_OF_BITS = 20;
    vector < vector <int> > subsequence(NO_OF_BITS);
    for(int i = 1; i <= no_of_elements; i++)
    {
        int difference = sorted_A[i] - A[i];

        for(int bit = 0; bit < NO_OF_BITS; bit++)
        {
            if(is_bit_set(difference, bit))
            {
                subsequence[bit].push_back(i);
            }
        }
    }

    int no_of_non_empty_subsequences = 0;
    for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        no_of_non_empty_subsequences += (subsequence[bit].size() > 0);
    }

    cout << no_of_non_empty_subsequences << "\n";
    for(int bit = 0; bit < NO_OF_BITS; bit++)
    {
        if(subsequence[bit].size() == 0)
        {
            continue;
        }

        int add_to_this_subsequence = (1 << bit);
        cout << subsequence[bit].size() << " " << add_to_this_subsequence << "\n";
        for(int x : subsequence[bit])
        {
            cout << x << " ";
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

