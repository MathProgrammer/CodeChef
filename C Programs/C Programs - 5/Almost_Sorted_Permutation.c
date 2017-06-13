#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define true 1
#define false 0
#define swap(a, b) {a = a^b; b = b^a; a = a^b;}


void solve()
{
    int length_of_permutation, i, almost_sorted = true;
    int moved_once[MAX_LENGTH] = {false}, permutation[MAX_LENGTH];

    scanf("%d", &length_of_permutation);
    for(i = 0; i < length_of_permutation; i++)
        scanf("%d", &permutation[i]);

    for(i = 1; i < length_of_permutation; i++)
    {
        if(permutation[i] < permutation[i - 1])
        {
            if(moved_once[i - 1] == true)
            {
                almost_sorted = false; break;
            }
            else
            {
                swap(permutation[i], permutation[i-1]);
                moved_once[i] = moved_once[i-1] = true;
            }
        }
    }

    //Checking if array is sorted
    for(i = 1; i < length_of_permutation; i++)
    {
        if(permutation[i] < permutation[i - 1])
        {
            almost_sorted = false; break;
        }
    }

    printf(almost_sorted ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
