#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define INFINITY 1e9 + 1

int main()
{
    int no_of_queries, no_of_elements, i, minimum = INFINITY, maximum = -1, number_i, query_i;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &number_i);
        minimum = min(minimum, number_i);
        maximum = max(maximum, number_i);
    }

    for(i = 1; i <= no_of_queries; i++)
    {
        scanf("%d", &query_i);
        printf(minimum <= query_i && maximum >= query_i ? "Yes\n" : "No\n");
    }

    return 0;
}
