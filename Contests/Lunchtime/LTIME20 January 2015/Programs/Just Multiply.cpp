#include <iostream>
#include <vector>
using namespace std;

long long multiply_mod(long long a, long long b, long long mod)
{   
    long long product = 0;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            product = (product + a)%mod;
        }
        
        a = (a + a)%mod;
        b = b/2;
    }
    
    return product;
}

long long power_mod(long long x, long long p, long long mod)
{
    long long answer = 1; 
    while(p > 0)
    {
        if(p%2 == 1)
        {
            answer = multiply_mod(answer, x, mod);
        }
            
        x = multiply_mod(x, x, mod);
        p = p/2;
    }
    
    return answer;
}

long long power_mod(long long x, string power, long long mod)
{
    long long answer = 1; 
    for(int i = 0; i < power.size(); i++)
    {
        long long last_digit_contribution = power_mod(x, power[i] - '0', mod);
        
        answer = power_mod(answer, 10, mod);
        
        answer = multiply_mod(answer, last_digit_contribution, mod);
    }
    
    return answer;
}

void solve()
{
    string S; 
    long long mod; 
    cin >> mod >> S;
    
    vector <long long> A; 
    for(int i = 0; i < S.size(); )
    {
        int b = i;
        long long base = 0;
        while(S[b] != '*')
        {
            base = base*10 + (S[b] - '0');
            base %= mod;
            b++;
        }
        
        int p = b + 2;
        string power;
        while(p < S.size() && S[p] != '*')
        {
            power += S[p];
            p++;
        }
        
        A.push_back(power_mod(base, power, mod));
        
        i = p + 1;
    }
    
    long long answer = A[0];
    for(int i = 1; i < A.size(); i++)
    {
        answer = multiply_mod(answer, A[i], mod);
    }
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
