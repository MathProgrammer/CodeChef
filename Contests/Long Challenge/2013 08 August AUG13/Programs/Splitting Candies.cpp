#include <cstdio>

void solve()
{
    long long number_of_candies, number_of_students;
    scanf("%lld %lld", &number_of_candies, &number_of_students);

    long long student_candies, teacher_candies;

    if(number_of_students == 0)
    {
        student_candies = 0;
        teacher_candies = number_of_candies;
    }
    else
    {
        student_candies = number_of_candies/number_of_students;
        teacher_candies = number_of_candies%number_of_students;
    }

    printf("%lld %lld\n",student_candies, teacher_candies);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
