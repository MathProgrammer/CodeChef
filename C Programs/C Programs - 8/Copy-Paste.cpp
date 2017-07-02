#include <cstdio>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements, element_i;
    scanf("%d", &no_of_elements);

    set <int> initial_array;
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &element_i);
        initial_array.insert(element_i);
    }

    printf("%u\n", initial_array.size());
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
