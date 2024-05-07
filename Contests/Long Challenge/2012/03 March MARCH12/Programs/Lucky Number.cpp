#include <iostream>
#include <vector>
using namespace std;

const int MAX_LENGTH = 1001, MOD = 1e9 + 7;
vector <long long> factorial(MAX_LENGTH), inverse_factorial(MAX_LENGTH);
vector <int> lucky;

long long power(long long x, long long p, long long mod)
{
    long long answer = 1;

    while(p > 0)
    {
        if(p%2 == 1)
        {
            answer = (answer*x)%mod;
        }

        x = (x*x)%mod;
        p = p >> 1;
    }

    return answer;
}


void precompute_lucky()
{
    lucky.push_back(4);
    lucky.push_back(7);

    for(int current_level_beginning = 0; lucky.back()*10 < MAX_LENGTH;)
    {
        int current_size = lucky.size();

        for(int i = current_level_beginning; i < current_size; i++)
        {
            lucky.push_back(lucky[i]*10 + 4);
            lucky.push_back(lucky[i]*10 + 7);
        }

        current_level_beginning = current_size;
    }
}

void precompute_factorial()
{
    factorial[0] = 1;
    for(int i = 1; i < MAX_LENGTH; i++)
    {
        factorial[i] = (factorial[i - 1]*i)%MOD;
    }

    //i*(i - 1)! = i!
    inverse_factorial[MAX_LENGTH - 1] = power(factorial[MAX_LENGTH - 1], MOD - 2, MOD);
    for(int i = MAX_LENGTH - 2; i >= 0; i--)
    {
        inverse_factorial[i] = inverse_factorial[i + 1]*(i + 1);
        inverse_factorial[i] %= MOD;
    }
}

long long choose(long long n, long long r)
{
    long long numerator = factorial[n];
    long long inverse_denominator = inverse_factorial[n - r]*inverse_factorial[r];
    inverse_denominator %= MOD;

    return (numerator*inverse_denominator)%MOD;
}

int is_lucky_digit(int d)
{
    return ( (d == 4) || (d == 7) );
}


long long get_lucky(string N)
{
    const int MOD = 1e9 + 7;
    long long lucky_count = 0;

    const int NO_OF_DIGITS = 10;
    vector <int> prefix_frequency(NO_OF_DIGITS);

    for(int i = 0; i < N.size(); i++)
    {
        int remaining_digits = (N.size() - 1) - i;
        for(int current_digit = 0; current_digit < N[i] - '0'; current_digit++)
        {
            if(i == 0 && current_digit == 0)
            {
                continue;
            }
            for(auto lucky_frequency : lucky)
            {
                int lucky_prefix_frequency =
                  prefix_frequency[4] + prefix_frequency[7]
                  + (current_digit == 4 || current_digit == 7);

                if(lucky_frequency < lucky_prefix_frequency ||
                   lucky_frequency > lucky_prefix_frequency + remaining_digits)
                {
                    continue;
                }

                int frequency_4 = prefix_frequency[4] + (current_digit == 4);
                int frequency_7 = prefix_frequency[7] + (current_digit == 7);

                int lucky_suffix = lucky_frequency - frequency_4 - frequency_7;

                long long choosing_lucky_suffix = choose(remaining_digits, lucky_suffix);
                choosing_lucky_suffix *= power(2, lucky_suffix, MOD);
                choosing_lucky_suffix %= MOD;

                int non_lucky_suffix = remaining_digits - lucky_suffix;
                long long choosing_non_lucky_suffix = power(8, non_lucky_suffix, MOD);

                long long count_here = choosing_lucky_suffix*choosing_non_lucky_suffix;
                count_here %= MOD;

                lucky_count += count_here;
                lucky_count %= MOD;

                //cout << "N = " << N << " i = " << i << " d = " << current_digit << " Lucky  " << lucky_frequency << "\nLucky Count = " << choosing_lucky_suffix << " others = " << choosing_non_lucky_suffix << " count = " << count_here << "\n";
            }
        }

        prefix_frequency[N[i] - '0']++;
    }

    for(int i = 1; i < N.size(); i++)
    {
        for(int d = 1; d <= 9; d++)
        {
            int remaining_digits = (N.size() - 1) - i;
            for(auto lucky_frequency : lucky)
            {
                int lucky_here = (d == 4 || d == 7);
                if(lucky_frequency >  lucky_here + remaining_digits)
                {
                    continue;
                }

                int lucky_suffix_leading_0 = lucky_frequency - (d == 4 || d == 7);

                long long choosing_lucky_suffix_leading_0 = choose(remaining_digits, lucky_suffix_leading_0);
                choosing_lucky_suffix_leading_0 *= power(2, lucky_suffix_leading_0, MOD);
                choosing_lucky_suffix_leading_0 %= MOD;

                int non_lucky_suffix_leading_0 = remaining_digits - lucky_suffix_leading_0;
                long long choosing_non_lucky_suffix_leading_0 = power(8, non_lucky_suffix_leading_0, MOD);

                long long count_here_leading_0 = choosing_lucky_suffix_leading_0*choosing_non_lucky_suffix_leading_0;
                count_here_leading_0 %= MOD;

                lucky_count += count_here_leading_0;
                lucky_count %= MOD;

                //cout << "N0 = " << N << " i = " << i << " d = " << d << " Lucky  " << lucky_frequency << "\nLucky Count = " << choosing_lucky_suffix_leading_0 << " others = " << choosing_non_lucky_suffix_leading_0 << " count = " << count_here_leading_0 << "\n";
            }
        }
    }

    return lucky_count;
}

string add_1(string N)
{
    for(int i = N.size() - 1; i >= 0; i--)
    {
        if(N[i] != '9')
        {
            N[i]++;
            break;
        }
        else
        {
            N[i] = '0';
        }
    }

    if(N[0] == '0')
    {
        N = "1" + N;
    }

    return N;
}

void solve()
{
    string left, right;
    cin >> left >> right;

    string right_plus_1 = add_1(right);
    //cout << "R = " << right_plus_1 << "\n";

    const int MOD = 1e9 + 7;
    long long answer = get_lucky(right_plus_1) - get_lucky(left) + MOD;
    answer %= MOD;

    //cout << "Answer = " << answer << "\n";
    cout << answer << "\n";
}

int main()
{
    precompute_lucky();
    precompute_factorial();

	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
	    solve();

	return 0;
}
