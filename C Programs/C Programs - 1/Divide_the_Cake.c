#include <stdio.h>

int main()
{
    int no_of_pieces, no_of_test_cases, i;
    scanf("%d",&no_of_test_cases);

    for(i = 1; i <=no_of_test_cases; i++)
    {
        scanf("%d", &no_of_pieces);

        printf( (360%no_of_pieces == 0) ? "y " : "n "); //If n divides 360, then n equal pieces are possible.
        printf( (no_of_pieces <= 360) ? "y " : "n "); //Any n below 360 is attainable
        printf( (no_of_pieces <= 26) ? "y\n" : "n\n");// First piece - 1, second piece - 2 ... at most 27 pieces are possible
    }
    return 0;
}
