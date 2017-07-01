#include <cstdio>
#include <cstring>
#include <map>

#define MAX_LENGTH 1000 + 1

using namespace std;

void solve()
{
    char sequence[MAX_LENGTH];
    scanf("%s", sequence);

    map <char, int> frequency;
    for(int front_i = 0, back_i = strlen(sequence) - 1; front_i < back_i; front_i++, back_i--)
    {
        frequency[ sequence[front_i] ]++;
        frequency[ sequence[back_i] ]--;
    }

    bool is_lapindrome = true;

    map <char, int> :: iterator it;
    for(it = frequency.begin(); it != frequency.end(); it++)
    {
        int frequency_i = it->second;

        if(frequency_i != 0)
        {
            is_lapindrome = false;
            break;
        }
    }

    printf(is_lapindrome ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
