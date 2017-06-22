#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_students, cut_off, no_of_exams, maximal_score, marks;
    long long sergey_score, target_score;
    scanf("%d %d %d %d", &no_of_students, &cut_off, &no_of_exams, &maximal_score);

    vector <long long> total_scores(no_of_students, 0);
    for(int i = 1; i < no_of_students; i++)
    {
        for(int e = 1; e <= no_of_exams; e++)
        {
            scanf("%d", &marks);
            total_scores[i] += marks;
        }
    }

    sergey_score = 0LL;
    for(int e = 1; e < no_of_exams; e++)
    {
        scanf("%d", &marks);
        sergey_score += marks;
    }

    sort(total_scores.begin() + 1, total_scores.end());
    reverse(total_scores.begin() + 1, total_scores.end());

    target_score = max(0LL, (total_scores[cut_off] - sergey_score) + 1);

    printf(target_score > maximal_score ? "Impossible\n" : "%lld\n", target_score);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
