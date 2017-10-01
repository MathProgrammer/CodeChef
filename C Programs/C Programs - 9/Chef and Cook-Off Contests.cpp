#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

void solve()
{
    map <string, int> difficulty_count;

    int no_of_problems;
    scanf("%d", &no_of_problems);

    for(int i = 1; i <= no_of_problems; i++)
    {
        string difficulty;
        cin >> difficulty;

        difficulty_count[difficulty]++;
    }

    int possible_to_choose = (difficulty_count["simple"]) && (difficulty_count["cakewalk"]) && (difficulty_count["easy"]);
    possible_to_choose = possible_to_choose && (difficulty_count["easy-medium"] || difficulty_count["medium"]);
    possible_to_choose = possible_to_choose && (difficulty_count["medium-hard"] || difficulty_count["hard"]);

    printf("%s\n", possible_to_choose ? "Yes" : "No");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
