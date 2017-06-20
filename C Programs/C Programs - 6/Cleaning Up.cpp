#include <stdio.h>
#include <vector>

using namespace std;

void solve()
{
    int number_of_jobs, number_of_complete_jobs, number_of_incomplete_jobs, i, job_i, remaining_job_counter = 1;

    scanf("%d %d", &number_of_jobs, &number_of_complete_jobs);

    number_of_incomplete_jobs = number_of_jobs - number_of_complete_jobs;
    vector <int> completed_jobs(number_of_jobs + 1, false);
    vector <int> remaining_jobs(number_of_incomplete_jobs + 1);

    for(i = 1; i <= number_of_complete_jobs ; i++)
    {
        scanf("%d", &job_i);

        completed_jobs[job_i] = true;
    }

    for(i = 1; i <= number_of_jobs; i++)
        if(completed_jobs[i] == false)
            remaining_jobs[remaining_job_counter++] = i;

    //Chef's Jobs
    for(i = 1; i <= number_of_incomplete_jobs ; i += 2)
        printf("%d ", remaining_jobs[i]);

    printf("\n");

    //Assistant
    for(i = 2; i <= number_of_incomplete_jobs; i += 2)
        printf("%d ", remaining_jobs[i]);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
