#include <cstdio>

int no_of_factors(int N, int b, int c)
{
    int answer = 0;

    for(int i = 1; i*i <= N; i++)
    {
        if(N%i == 0)
        {
            if(i*i == N)
            {
                answer += (i <= b && i <= c);
            }
            else
            {
                answer += (i <= b && N/i <= c);
                answer += (N/i <= b && i <= c);
            }
        }
    }

    return answer;
}

void solve()
{
    int N, a, b, c;
    scanf("%d %d %d %d", &N, &a, &b, &c);

    int no_of_triplets = 0;

    for(int i = 1; i*i <= N; i++)
    {
        if(N%i == 0)
        {
            if(i*i == N)
            {
                if(i <= a)
                    no_of_triplets += no_of_factors(N/i, b, c);
            }
            else
            {
                if(i <= a)
                    no_of_triplets += no_of_factors(N/i, b, c);
                if(N/i <= a)
                    no_of_triplets += no_of_factors(i, b, c);
            }
        }
    }

    printf("%d\n", no_of_triplets);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

