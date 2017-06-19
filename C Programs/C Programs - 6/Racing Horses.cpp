#include <iostream>
#include <algorithm>

#define INFINITY 1e9 + 1
#define MAX_HORSES 5000 + 1

using namespace std;

void solve()
{
    int no_of_horses, skill_of_horse[MAX_HORSES], i, min_difference  = INFINITY;

    cin >> no_of_horses;
    for(i = 0; i < no_of_horses; i++)
        cin >> skill_of_horse[i];

    sort(skill_of_horse, skill_of_horse + no_of_horses);

    for(i = 1; i < no_of_horses; i++)
        min_difference = min(min_difference, skill_of_horse[i] - skill_of_horse[i-1]);

    cout << min_difference << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
