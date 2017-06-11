#include <stdio.h>

#define MAX_LENGTH 100000 + 1

void solve()
{
    int i, number_of_punished_pairs = 0;
    char student[MAX_LENGTH], previous_student_position = 'X';
    scanf("%s", student);

    for(i = 0; student[i] != '\0' ; i++)
    {
        if(previous_student_position == '<' && student[i] == '>')
            number_of_punished_pairs++;

        previous_student_position = student[i];
    }

    printf("%d\n",number_of_punished_pairs);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
