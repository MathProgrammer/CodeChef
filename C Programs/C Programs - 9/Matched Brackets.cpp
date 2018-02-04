#include <cstdio>

int main()
{
    int no_of_brackets;
    scanf("%d", &no_of_brackets);

    const int OPEN = 1, CLOSED = 2;

    int nesting_depth = 0, max_nesting_depth = 0, max_depth_location = 0;
    int no_of_symbols = 0, max_symbols = 0, max_symbol_start = 0;

    for(int i = 1; i <= no_of_brackets; i++)
    {
        int bracket;
        scanf("%d", &bracket);

        no_of_symbols++;

        nesting_depth += (bracket == OPEN ? 1 : -1);

        if(nesting_depth > max_nesting_depth)
            max_nesting_depth = nesting_depth, max_depth_location = i;

        if(nesting_depth == 0)
        {
            if(no_of_symbols > max_symbols)
                max_symbols = no_of_symbols, max_symbol_start = i - no_of_symbols + 1;

            no_of_symbols = 0;
        }
    }

    printf("%d %d %d %d\n", max_nesting_depth, max_depth_location, max_symbols, max_symbol_start);
    return 0;
}
