#include <cstdio>

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int minimum_element_index = 0, minimum_element = 1e9;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        if(element_i < minimum_element)
            minimum_element_index = i, minimum_element = element_i;
    }

    printf("%d\n", minimum_element_index);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
