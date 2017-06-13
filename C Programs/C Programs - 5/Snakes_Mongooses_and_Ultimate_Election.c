#include <stdio.h>

#define MAX_ANIMALS 100 + 1

void solve()
{
    char alive_animals[MAX_ANIMALS];
    int snakes = 0, mongooses = 0, i;
    scanf("%s", alive_animals);

    //Killing the snakes greedily
    for(i = 0; alive_animals[i] != '\0'; i++)
    {
        if(alive_animals[i] == 'm')
        {
            if(i > 0 && alive_animals[i - 1] == 's')
                alive_animals[i - 1] = '.';
            else if(alive_animals[i + 1] == 's')
                alive_animals[i + 1] = '.';
        }
    }

    for(i = 0; alive_animals[i] != '\0'; i++)
    {
        snakes += (alive_animals[i] == 's') ;
        mongooses += (alive_animals[i] == 'm') ;
    }

    if(snakes == mongooses)
        printf("tie\n");
    else
        printf("%s\n", snakes > mongooses ? "snakes" : "mongooses");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

