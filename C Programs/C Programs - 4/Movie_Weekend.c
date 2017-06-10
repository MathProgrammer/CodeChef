#include <stdio.h>

#define MAX_NUMBER_OF_MOVIES 100 + 1

void solve()
{
    int length[MAX_NUMBER_OF_MOVIES], rating[MAX_NUMBER_OF_MOVIES], number_of_movies, deciding_factor = 0, movie_chosen = 0, i;
    scanf("%d",&number_of_movies);

    for(i = 0; i < number_of_movies; i++)
        scanf("%d", &length[i]);

    for(i = 0; i < number_of_movies; i++)
        scanf("%d", &rating[i]);

    for(i = 0; i < number_of_movies ; i++)
    {
        if(length[i]*rating[i] > deciding_factor || (length[i]*rating[i] == deciding_factor && rating[i] > rating[movie_chosen]))
        {
            deciding_factor = length[i]*rating[i];
            movie_chosen = i ;
        }
    }

    printf("%d\n",movie_chosen + 1);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
