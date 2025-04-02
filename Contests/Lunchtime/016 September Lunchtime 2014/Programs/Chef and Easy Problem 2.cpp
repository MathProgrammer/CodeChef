#include <iostream>
#include <vector>
using namespace std;

int exponent(int n, int p)
{
    int answer = 0;
    while(n%p == 0)
    {
        answer++;
        n /= p;
    }
    
    return answer;
}

void solve()
{
    int no_of_elements; 
    cin >> no_of_elements;
    
    const int MAX_N = 1e6 + 1;
    vector <int> frequency(MAX_N, 0);
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        frequency[A[i]]++;
    }
    
    int answer = 0;
    vector <int> no_of_multiples(MAX_N, 0);
    vector <int> is_prime(MAX_N, true);
    for(int i = 2; i < MAX_N; i++)
    {
        if(!is_prime[i])
        {
            continue;
        }
        
        int max_exponent = 0;
        for(int multiple = i; multiple < MAX_N; multiple += i)
        {
            if(frequency[multiple] > 0)
            {
                max_exponent = max(max_exponent, exponent(multiple, i));
            }
            
            is_prime[multiple] = false;
        }
        
        answer += max_exponent;
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
