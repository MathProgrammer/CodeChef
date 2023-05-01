#include <iostream>
using namespace std;

long long power(long long x, long long p, long long mod)
{
    long long answer = 1;
    
    while(p > 0)
    {
        if(p%2 == 1)
            answer = (answer*x)%mod;
            
        x = (x*x)%mod;
        p /= 2;
    }
    
    return answer;
}

int no_of_ones(long long n)
{
    int count = 0;
    while(n > 0)
    {
        count += n%2;
        n /= 2;
    }
    
    return count;
}

void solve()
{
    long long n;
    cin >> n;
    
    int bit_count = no_of_ones(n);
    
    const int MOD = 1e9 + 7;
    long long all_three = power(3, bit_count, MOD);
    long long only_two = (3*power(2, bit_count, MOD))%MOD;
    long long only_one = 3;
    
    long long answer = all_three - only_two + only_one + MOD;
    answer %= MOD;
    
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
