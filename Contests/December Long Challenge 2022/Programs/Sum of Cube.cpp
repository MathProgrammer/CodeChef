#include <iostream>
#include <vector>
using namespace std;

long long cube(long long n, long long m)
{
    long long answer = (n*n)%m;
    answer = (answer*n)%m;
    
    return answer;
}

long long square(long long n, long long m)
{
    long long answer = (n*n)%m;
    
    return answer;
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
    
    const int MOD = 998244353;
    vector <long long> sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum[i] = A[i] + sum[i - 1];
        sum[i] %= MOD;
    }
    
    long long answer = 0;
    long long prefix_sum = 0, prefix_square = 0, prefix_cube = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int no_of_prefixes = i;
        
        answer += no_of_prefixes*cube(sum[i], MOD);
        answer %= MOD;
        
        answer = answer - 3LL*square(sum[i], MOD)*prefix_sum;
        answer %= MOD;
        
        answer = answer + 3LL*sum[i]*prefix_square;
        answer %= MOD;
        
        answer = answer - prefix_cube + MOD;
        answer %= MOD;
        
        prefix_sum = (prefix_sum + sum[i])%MOD;
        prefix_cube = (prefix_cube + cube(sum[i], MOD))%MOD;
        prefix_square = (prefix_square + square(sum[i], MOD))%MOD;
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
