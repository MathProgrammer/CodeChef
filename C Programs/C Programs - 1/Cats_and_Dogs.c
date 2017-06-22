#include <stdio.h>

#define YES 1
#define NO 0

int is_counting_correct()
{
    int no_of_cats, no_of_dogs, no_of_legs, correct_counting = NO;
    long long cats_on_floor, cats_on_back;
    scanf("%d %d %d", &no_of_cats, &no_of_dogs, &no_of_legs);

    cats_on_floor = (no_of_legs - 4*no_of_dogs)/4;
    cats_on_back = no_of_cats - cats_on_floor;

    correct_counting = NO;
    if(no_of_legs%4 == 0 && no_of_legs >= 4LL*no_of_dogs && no_of_legs <= 4LL*(no_of_cats + no_of_dogs) && cats_on_back <= 2LL*no_of_dogs)
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
