#include <cstdio>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    set <int> S;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        scanf("%d", &element);
        S.insert(element);
    }

    int no_of_distinct_elements = S.size();
    int no_of_duplicates = no_of_elements - no_of_distinct_elements;
    printf("%d\n", no_of_duplicates);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
