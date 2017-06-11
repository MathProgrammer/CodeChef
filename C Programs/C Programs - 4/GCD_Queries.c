#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define MAX_SIZE 100000 + 2

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), (max(a, b)%min(a, b)) );
}

void solve()
{
    int number_of_elements, left, right, number_of_queries, i, array[MAX_SIZE], prefix_gcd[MAX_SIZE], suffix_gcd[MAX_SIZE], answer;
    scanf("%d %d", &number_of_elements, &number_of_queries);

    for(i = 1; i <= number_of_elements; i++)
        scanf("%d", &array[i]);

    //Prefix_gcd[i] = gcd(A[1], A[2], ... , A[i]
    for(i = 1; i <= number_of_elements; i++)
        prefix_gcd[i] = (i == 1 ? array[i] : gcd(prefix_gcd[i-1], array[i]) );

    //Suffix gcd[i] = gcd(A[i], A[i+1], A[i+2], ... ,A[n])
    for(i = number_of_elements; i >= 1; i--)
        suffix_gcd[i] = (i == number_of_elements ? array[i] : gcd(suffix_gcd[i + 1], array[i]) );

    for(i = 1; i <= number_of_queries; i++)
    {
        scanf("%d %d", &left, &right);

        //We are guaranteed we never get an empty range for query so the first two conditions never occur together
        if(left == 1)
            answer = suffix_gcd[right+1];
        else if(right == number_of_elements)
            answer = prefix_gcd[left-1];
        else
            answer = gcd(prefix_gcd[left-1], suffix_gcd[right+1]);

        printf("%d\n", answer);
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
