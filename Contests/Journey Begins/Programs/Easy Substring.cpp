#include <cstdio>

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    long long no_of_zeroes = 0, no_of_ones = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        scanf("%d", &element);

        no_of_zeroes += (element == 0);
        no_of_ones   += (element == 1);
    }

    long long substrings = choose_2(no_of_zeroes) + choose_2(no_of_ones) + no_of_elements;
    printf("%lld\n", substrings);

    return 0;
}
