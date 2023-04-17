#include <iostream>
using namespace std;

long long power(long long x, long long p, int mod)
{
    long long answer = 1; 
    
    while(p > 0)
    {
        if(p%2 == 1)
            answer = (answer*x)%mod;
            
        x = (x*x)%mod;
        p = p/2;
    }
    
    return answer;
}

long long geometric_progression(long long multiplier, long long no_of_terms, int mod)
{
    //cout << "GP m = " << multiplier << " N = " << no_of_terms << "\n";
    if(no_of_terms == 1)
    {
        return 1;
    }
    
    if(no_of_terms == 2)
    {
        return (1 + multiplier)%mod;
    }
    
    long long left_over_power = 0;
    
    if(no_of_terms%2 == 1)
    {
        left_over_power = power(multiplier, no_of_terms - 1, mod);
    }
    
    long long square_multiplier = power(multiplier, 2, mod);
    
    long long factored_gp = geometric_progression(square_multiplier, no_of_terms/2, mod);
    long long answer = (1 + multiplier)*factored_gp + left_over_power;
    
    
    return answer%mod;
}

void solve()
{
    long long n, mod;
    cin >> n >> mod; 
    
    long long sum = 0;
    for(int i = 1; i <= min(n, mod - 1); i++)
    {
        long long first_term = power(i, i, mod);
        long long multiplier = power(i, mod, mod);
        long long no_of_terms = (n/mod) + (n%mod >= i);
        
        sum += first_term*geometric_progression(multiplier, no_of_terms, mod);
        sum %= mod;
    }
    
    cout << sum << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
