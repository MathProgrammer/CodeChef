#include <iostream>
using namespace std;

int digit_sum(int n, int base)
{
    int sum = 0;
    while(n > 0)
    {
        sum += (n%base);
        n /= base;
    }
    return sum;
}

int solve_above_square_root(int n, int left, int right)
{
    int minimum_sum = digit_sum(n, right), answer = right;
    //N = digit x B + remainder
    for(int digit = 1; digit*1LL*digit <= n && n/digit >= left; digit++)
    {
        int base = n/digit;
        int remainder = n%base;
        
        if(left <= base && base <= right)
        {
            if(digit + remainder < minimum_sum)
            {
                minimum_sum = digit + remainder;
                answer = base;
            }
        }
    }
    return answer;
}

int solve_below_square_root(int n, int left, int right)
{
    int minimum_sum = digit_sum(n, left), answer = left;
    for(int base = left; base*1LL*base <= n && base <= right; base++)
    {
        if(digit_sum(n, base) < minimum_sum)
        {
            minimum_sum = digit_sum(n, base);
            answer = base;
        }
      
    }
    return answer;
}

void solve()
{
    int n, left, right;
    cin >> n >> left >> right;
    
    int small_base = solve_below_square_root(n, left, right);
    int big_base = solve_above_square_root(n, left, right);
    
    int answer = small_base;
    if(digit_sum(n, small_base) > digit_sum(n, big_base))
    {
        answer = big_base;
    }
                 
    cout << answer << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
