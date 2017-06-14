#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10 + 1
#define NUMBER_OF_INGREDIENTS 4

void solve()
{
    char ingredient_1[NUMBER_OF_INGREDIENTS][MAX_NAME_LENGTH], ingredient_2[NUMBER_OF_INGREDIENTS][MAX_NAME_LENGTH];
    int i, j, similarity_count = 0;

    scanf("%s %s %s %s", ingredient_1[0], ingredient_1[1], ingredient_1[2], ingredient_1[3]);
    scanf("%s %s %s %s", ingredient_2[0], ingredient_2[1], ingredient_2[2], ingredient_2[3]);

    for(i = 0; i < NUMBER_OF_INGREDIENTS; i++)
    {
        for(j = 0; j < NUMBER_OF_INGREDIENTS; j++)
        {
            if(strcmp(ingredient_1[i], ingredient_2[j]) == 0)
                similarity_count++;
        }
    }
    printf(similarity_count >= NUMBER_OF_INGREDIENTS/2 ? "similar\n" : "dissimilar\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
