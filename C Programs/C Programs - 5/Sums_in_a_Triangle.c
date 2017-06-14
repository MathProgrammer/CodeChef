#include <stdio.h>

#define NUMBER_OF_ROWS 100 + 1
#define NUMBER_OF_COLUMNS 100 + 1
#define max(a, b) (a > b ? a : b)

void solve()
{
    int triangle[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], i, j, max_sum_starting_here[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {{0}}, number_of_rows;
    scanf("%d", &number_of_rows);

    for(i = 1; i <= number_of_rows; i++)
        for(j = 1; j <= i; j++)
            scanf("%d", &triangle[i][j]);

    //Initialising the last row
    for(i = 1; i <= number_of_rows; i++)
        max_sum_starting_here[number_of_rows][i] = triangle[number_of_rows][i];

    for(i = number_of_rows - 1; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            max_sum_starting_here[i][j] =triangle[i][j] + max(max_sum_starting_here[i + 1][j], max_sum_starting_here[i + 1][j + 1]);
        }
    }

    printf("%d\n", max_sum_starting_here[1][1]); //The first element
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}
