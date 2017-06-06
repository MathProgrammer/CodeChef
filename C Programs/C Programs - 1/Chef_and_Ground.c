#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define MAX_NUMBER 100 + 1
void solve()
{
    int heights_of_columns[MAX_NUMBER], no_of_columns, no_of_cubes, tallest_column = 0, i, total_difference = 0;
    scanf("%d %d",&no_of_columns, &no_of_cubes);

    for(i = 0; i < no_of_columns; i++)
    {
        scanf("%d", &heights_of_columns[i]);
        tallest_column = max(tallest_column, heights_of_columns[i]);
    }

    for(i = 0; i < no_of_columns; i++)
        total_difference += tallest_column - heights_of_columns[i];

    printf(total_difference == no_of_cubes || (total_difference - no_of_cubes)%no_of_columns == 0 ? "Yes\n" : "No\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
