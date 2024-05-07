#include <iostream>
using namespace std;

int power_mod(long long x, long long p, long long mod)
{
    long long answer = 1; 
    
    while(p > 0)
    {
        if(p%2 == 1)
        {
            answer = (answer*x)%mod;
        }
        
        x = (x*x)%mod;
        p = p/2;
    }
    
    return answer;
}

long long count_mod_till(int m, int n, long long limit)
{
    long long count = limit/n + (limit%n >= m);
    
    return count;
}

void solve()
{
    int upper, d, target, n;
    cin >> upper >> d >> target >> n; 
    
    const int MOD = 1e9 + 7;
    long long no_of_triplets = 0;
    for(int i = 0; i < min(upper + 1, n); i++)
    {
        for(int j = 0; j < min(upper + 1, n); j++)
        {
            for(int k = 0; k < min(upper + 1, n); k++)
            {
                int sum = power_mod(i, d, n) + 
                          power_mod(j, d, n) + 
                          power_mod(k, d, n);
                sum %= n;
                
                if(sum != target)
                {
                    continue;
                }
                
                long long no_of_i = count_mod_till(i, n, upper)%MOD;
                long long no_of_j = count_mod_till(j, n, upper)%MOD;
                long long no_of_k = count_mod_till(k, n, upper)%MOD;

                
                long long count_this_triplet = no_of_i*no_of_j;
                count_this_triplet %= MOD;
                
                count_this_triplet *= no_of_k; 
                count_this_triplet %= MOD;
                
                no_of_triplets += count_this_triplet;
                no_of_triplets %= MOD;
            }
        }
    }
    
    cout << no_of_triplets << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
