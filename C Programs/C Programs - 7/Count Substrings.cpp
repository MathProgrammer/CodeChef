#include <stdio.h>

#define MAX_LENGTH 100000 + 1
using namespace std;

void solve()
{
    char sequence[MAX_LENGTH];
    int no_of_1s = 0, length;
    long long no_of_substrings = 0;

    scanf("%d %s", &length, sequence);

    for(int i = 0; i < length; i++)
        no_of_1s += (sequence[i] == '1');

    //Add all subtstrings starting and ending differently and singleton sequences.
    no_of_substrings = (no_of_1s*1LL*(no_of_1s - 1) )/2 + no_of_1s;

    printf("%lld\n", no_of_substrings);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
