#include <stdio.h>

#define MAX_LENGTH 1000 + 1
#define max(a, b) (a > b ? a : b)

void solve()
{
    char correct_answer[MAX_LENGTH], chef_answer[MAX_LENGTH];
    int number_of_questions, i, winning_i, money_won = 0, number_of_correct_answers = 0;

    scanf("%d %s %s", &number_of_questions, correct_answer, chef_answer);

    for(i = 0; i < number_of_questions; i++)
        if(correct_answer[i] == chef_answer[i])
            number_of_correct_answers++;

    for(i = 0; i <= number_of_questions; i++)
    {
        scanf("%d", &winning_i);
        if(i <= number_of_correct_answers)
            money_won = max(money_won, winning_i);
    }
    if(number_of_correct_answers == number_of_questions) money_won = winning_i;

    printf("%d\n", money_won);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
