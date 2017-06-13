#include <stdio.h>

#define MAX_CANDIDATES 100 + 1
#define MINUS_INFINITY -200

void solve()
{
    int number_of_students, i, vote_i, minimum_votes, size_of_student_body = 0;
    int candidate_votes[MAX_CANDIDATES] = {0};

    scanf("%d %d", &number_of_students, &minimum_votes);

    for(i = 1; i <= number_of_students; i++)
    {
        scanf("%d", &vote_i);

        candidate_votes[vote_i] = (vote_i == i ? MINUS_INFINITY : candidate_votes[vote_i] + 1); //Disqualified if he votes for himself
    }

    for(i = 1; i <= number_of_students; i++)
        size_of_student_body += (candidate_votes[i] >= minimum_votes);

    printf("%d\n", size_of_student_body);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}

