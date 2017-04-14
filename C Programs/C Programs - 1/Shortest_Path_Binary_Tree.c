#include <stdio.h>

short find_path_length(unsigned int, unsigned int);

int main()
{
    unsigned int no_of_queries, i, start_node, last_node;
    short path_length;

    scanf("%u",&no_of_queries);
    for(i = 1; i <= no_of_queries; i++)
    {
        scanf("%u %u", &start_node, &last_node);
        path_length =  find_path_length(start_node, last_node);
        printf("%u\n",path_length);
    }
    return 0;
}

short find_path_length(unsigned int x, unsigned int y)
{
    short no_of_steps;

    for(no_of_steps = 0; x != y; no_of_steps++)
    {
        if(x > y)
        {
            x = x >> 1;
        }
        else
        {
            y = y >> 1;
        }
    }

    return no_of_steps;
}
