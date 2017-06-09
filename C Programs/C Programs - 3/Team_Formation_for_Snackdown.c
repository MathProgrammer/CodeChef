#include <stdio.h>

void solve()
{
    int no_of_teams, no_of_people, person_1, person_2, team_i;
    scanf("%d %d",&no_of_people, &no_of_teams);

    for(team_i = 1; team_i <= no_of_teams ; team_i++)
        scanf("%d %d", &person_1, &person_2);

    printf(no_of_people%2 == 1 ? "no\n" : "yes\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
