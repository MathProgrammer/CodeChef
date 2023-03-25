#include <iostream>
using namespace std;

void solve()
{
    int n; 
    cin >> n;
    
    long long a, b;
    
    if(n%2 == 1)
    {
        a = n/2, b = n - a;
    }
    else if(n%4 == 2)
    {
        if(n == 2)
        {
            a = 1, b = 1;
        }
        else 
        {
            a = n/2 - 2, b = n/2 + 2;
        }
    }
    else if(n%4 == 0)
    {
        a = n/2 - 1, b = n/2 + 1;
    }
    
    long long lcm = a*b, gcd = 1;
    long long answer = lcm - gcd; 
    cout << answer << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
