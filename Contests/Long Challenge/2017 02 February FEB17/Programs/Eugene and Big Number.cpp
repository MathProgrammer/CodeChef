#include <iostream>
using namespace std;

int digit_count(long long n)
{
    int digits = 0;
    while(n > 0)
    {
        n /= 10;
        digits++;
    }

    return digits;
}

long long power_mod(long long x, long long power, long long mod)
{
    long long answer = 1;

    while(power > 0)
    {
        if(power%2 == 1)
            answer = (answer*x)%mod;

        x = (x*x)%mod;
        power = power/2;
    }

    return answer;
}

//1 + r + r^2 + ... + r^{n - 1} = (1 + r)(1 + r^2 + r^4 + ... )
long long geometric_progression(long long r, long long no_of_terms, int mod)
{

    if(no_of_terms == 1)
    {
        return 1;
    }

    if(no_of_terms == 2)
    {
        return (1 + r);
    }

    long long left_over_power = 0;
    if(no_of_terms%2 == 1)
    {
        left_over_power = power_mod(r, no_of_terms - 1, mod);
    }

    long long r_squared = power_mod(r, 2, mod);
    long long factored_gp = geometric_progression(r_squared, no_of_terms/2, mod);

    long long answer = (1 + r)*factored_gp + left_over_power;
    answer %= mod;

    return answer;
}

void solve()
{
    long long a, n, mod;
    cin >> a >> n >> mod;

    int no_of_digits = digit_count(a);
    long long difference = power_mod(10, no_of_digits, mod);
    long long gp_sum = geometric_progression(difference, n, mod);

    long long answer = a*gp_sum;
    answer %= mod;

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

