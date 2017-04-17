#include <stdio.h>

int main()
{
    int no_of_iterations, n,i, case_count, no_of_test_cases,answer;
    scanf("%d",&no_of_test_cases);

    for(case_count = 1; case_count <= no_of_test_cases; case_count++)
    {
        scanf("%d %d",&no_of_iterations, &n);
        //f^d(n), where f(x) = x(x+1)/2
        for(i = 1; i <=no_of_iterations; i++)
        {
            answer = n*(n+1)/2;
            n = answer; //for next iteration
        }
        printf("%d\n",answer);
    }
    return 0;
}
