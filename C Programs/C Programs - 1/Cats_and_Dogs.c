#include <stdio.h>

#define YES 1
#define NO 0

int is_counting_correct()
{
    int no_of_cats, no_of_dogs, no_of_legs, correct_counting = NO;
    scanf("%d %d %d", &no_of_cats, &no_of_dogs, &no_of_legs);

    if(no_of_legs%4 == 0 && no_of_legs >= 4*no_of_dogs && no_of_legs <= 4*(no_of_cats + no_of_dogs))
    {
        correct_counting = YES;
    }

    return correct_counting;
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        printf(is_counting_correct() ? "yes\n" : "no\n");
    }
    return 0;
}
