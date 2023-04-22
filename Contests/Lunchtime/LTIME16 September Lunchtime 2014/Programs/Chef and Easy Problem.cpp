#include <cstdio>

const int MAX_BITS = 31, MAX_N = 1e5 + 5;
int A[MAX_N], sum[MAX_N][MAX_BITS];

int get_half(int n)
{
    return (n/2 + n%2);
}

int bit_set(int n, int position)
{
    return ( ( n & (1 << position) ) != 0 );
}

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++) scanf("%d", &A[i]);

    for(int bit = 0; bit < MAX_BITS; bit++) sum[0][bit] = 0;

    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int bit = 0; bit < MAX_BITS; bit++)
        {
            sum[i][bit] = sum[i - 1][bit] + bit_set(A[i], bit);
        }
    }

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        int half_elements = get_half(right - left + 1);
        int answer = 0;

        for(int bit = 0; bit < MAX_BITS; bit++)
        {
            int no_of_ones = sum[right][bit] - sum[left - 1][bit];

            if(no_of_ones < half_elements)
                answer |= (1 << bit);
        }

        printf("%d\n", answer);
    }

    return 0;
}
