#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0

int p[MAX_LENGTH];

int main()
{
    int length_of_permutation, i, ambiguous;

    while(true)
    {
        ambiguous = true;

        scanf("%d", &length_of_permutation);

        if(length_of_permutation == 0)
            return 0;

        for(i = 1; i <= length_of_permutation; i++)
            scanf("%d", &p[i]);

        for(i = 1; i <= length_of_permutation; i++)
        {
            if(p[p[i]] != i)
            {
                ambiguous = false;
                break;
            }
        }

        printf(ambiguous ? "ambiguous\n" : "not ambiguous\n");
    }
    return 0;
}
