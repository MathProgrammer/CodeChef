#include <stdio.h>

void solve()
{
    int no_of_rows, no_of_columns, max_score;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    /*Draw a graph where the cells are vertices and an edge exists between every adjacent pair of cells.
    An edge is coloured whenever a cell is coloured and it's neighbour is already coloured.
    All edges are coloured only once and at the end of the game, every edge is coloured ! The order of colouring doesn't matter and the
    number of edges is the answer.*/
    max_score = 2*no_of_rows*no_of_columns - no_of_rows - no_of_columns;

    printf("%d\n",max_score);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
