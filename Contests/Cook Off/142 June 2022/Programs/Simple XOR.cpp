#include <iostream>
using namespace std;

void solve()
{
    int left, right; 
    cin >> left >> right;
    
    int starting_xor = left^(left + 1)^(left + 2)^(left + 3);
    
    if(starting_xor != 0 && right - left >= 4)
    {
        left++;
        starting_xor = left^(left + 1)^(left + 2)^(left + 3);
    }
    
    if(starting_xor != 0)
    {
        cout << "-1";
    }
    else 
    {
        for(int i = left; i < left + 4; i++)
        {
            cout << i << " ";
        }
    }
    
    cout << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
