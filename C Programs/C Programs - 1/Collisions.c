#include <stdio.h>

#define true 1
#define MAX_NO_OF_GIRLS 10
void solve()
{
    int no_of_boys, no_of_girls, i, j, no_of_collisions = 0, liking;
    int no_of_boys_liking_girl[MAX_NO_OF_GIRLS] = {0};

    scanf("%d %d", &no_of_boys, &no_of_girls);
    for(i = 0; i < no_of_boys; i++)
    {
        for(j = 0; j < no_of_girls; j++)
        {
            scanf("%1d", &liking);

            if(liking == true)
                no_of_boys_liking_girl[j]++;
        }
    }

    for(i = 0; i < no_of_girls; i++)
    {
        no_of_collisions += (no_of_boys_liking_girl[i] > 1 ? (no_of_boys_liking_girl[i]*(no_of_boys_liking_girl[i] - 1) )/2 : 0);
    }

    printf("%d\n",no_of_collisions);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
