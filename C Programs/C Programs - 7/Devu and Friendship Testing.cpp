#include <stdio.h>
#include <set>

using namespace std;

void solve()
{
    int no_of_friends;
    set <int> saved_friendships;
    scanf("%d", &no_of_friends);

    for(int i = 1; i <= no_of_friends; i++)
    {
        int day_i;
        scanf("%d", &day_i);

        saved_friendships.insert(day_i);
    }

    printf("%d\n", saved_friendships.size());
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

