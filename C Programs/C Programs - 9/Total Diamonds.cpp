#include <cstdio>
#include <vector>

using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

int diamond_count(int n)
{
    int even_digit_sum = 0, odd_digit_sum = 0;

    for(int i = 1; n > 0; i++, n/= 10)
    {
        int digit = n%10;

        if(digit%2 == 0)
            even_digit_sum += digit;
        else
            odd_digit_sum += digit;
    }

    return abs(even_digit_sum - odd_digit_sum);
}

void precompute(vector <long long> &grid_diamonds, int MAX_N)
{
    vector <int> room_diamonds(2*MAX_N + 1, 0);
    for(int i = 1; i <= 2*MAX_N; i++)
        room_diamonds[i] = diamond_count(i);

    vector <long long> sum_room_diamonds(2*MAX_N + 1, 0);
    for(int i = 1; i <= 2*MAX_N; i++)
        sum_room_diamonds[i] = sum_room_diamonds[i - 1] + room_diamonds[i];

    grid_diamonds[1] = 2;

    for(int n = 2; n <= MAX_N; n++)
    {
        grid_diamonds[n] = grid_diamonds[n - 1] + 2*(sum_room_diamonds[2*n] - sum_room_diamonds[n]) - room_diamonds[2*n];
    }
}

int main()
{
    const int MAX_N = 1e6;
    vector <long long> grid_diamonds(MAX_N + 1, 0);
    precompute(grid_diamonds, MAX_N);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", grid_diamonds[n]);
    }

    return 0;
}
