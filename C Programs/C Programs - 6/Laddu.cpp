#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

#define MAX_LENGTH 15 + 1

using namespace std;

void solve()
{
    int no_of_activities, laddus = 0;
    char nationality[MAX_LENGTH];
    map <string, int> no_of_redeemable_points;

    //no_of_redeemable_points.insert(make_pair("INDIAN", 200) );
    //no_of_redeemable_points.insert(make_pair("NON_INDIAN", 400) );

    no_of_redeemable_points["INDIAN"] = 200;
    no_of_redeemable_points["NON_INDIAN"] = 400;

    scanf("%d %s", &no_of_activities, nationality);

    for(int i = 1; i <= no_of_activities; i++)
    {
        char activity[MAX_LENGTH];
        scanf("%s", activity);

        if(strcmp(activity, "CONTEST_WON") == 0)
        {
            int contest_rank;
            scanf("%d", &contest_rank);

            laddus += 300 + (contest_rank <= 20 ? (20 - contest_rank) : 0);
        }
        else if(strcmp(activity, "TOP_CONTRIBUTOR") == 0)
        {
            laddus += 300;
        }
        else if(strcmp(activity, "BUG_FOUND") == 0)
        {
            int severity;
            scanf("%d", &severity);

            laddus += severity;
        }
        else if(strcmp(activity, "CONTEST_HOSTED") == 0)
        {
            laddus += 50;
        }
    }

    printf("%d\n", laddus/no_of_redeemable_points[nationality]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
