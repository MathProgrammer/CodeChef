#include <stdio.h>

long long count_solution(long long);
int sum_of_digits(long long);

int main()
{
    long long n, solution_count;
    scanf("%lld",&n);

    solution_count = count_solution(n);
    printf("%lld\n",solution_count);
    return 0;
}

//x + s(x) + s(s(x)) = n
long long count_solution(long long n)
{
    long long x, lower_limit;
    long long solution_count = 0;

    //x can be at most 10^8  so s(x) can be at most 81. s(s(x)) can be 16 at most - 79 is the maximum
    //s(x) + s(s(x)) <= 97, so any value of x less than n - 97 cannot satisfy the equation and neither can any value of x greater than n.
    lower_limit = (n < 97 ? 1 : n - 97);
    for(x = lower_limit; x <= n; x++)
    {
        if(x + sum_of_digits(x) + sum_of_digits(sum_of_digits(x)) == n)
        {
            solution_count++;
        }
    }

    return solution_count;
}

int sum_of_digits(long long num)
{
    long long temp;
    int sum = 0;
    for(temp = num; temp > 0; temp = temp/10)
    {
        sum = sum + temp%10;
    }
    return sum;
}
