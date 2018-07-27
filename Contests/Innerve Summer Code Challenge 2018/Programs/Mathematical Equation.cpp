#include <iostream>
#include <map>

using namespace std;

long long power(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long n, long long mod)
{
    return power(n, mod - 2, mod); //Mod is prime here
}

int main()
{
    int no_of_elements, no_of_queries;
    cin >> no_of_elements >> no_of_queries;

    map <unsigned long long, int> value_frequency;
    while(no_of_elements--)
    {
        unsigned long long A, B;
        cin >> A >> B;

        value_frequency[4*A*B + 2*max(A, B)]++;
    }

    while(no_of_queries--)
    {
        long long k;
        cin >> k;

        long long target = k*(k + 1);
        int no_of_answers = value_frequency[target];

        const int MOD = 1e9 + 9;
        long long answer = (no_of_answers == 0 ? -1: inverse(no_of_answers, MOD));

        cout << answer << "\n";
    }

    return 0;
}


