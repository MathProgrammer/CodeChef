#include <cstdio>
#include <vector>

using namespace std;

#define get_sum_till(i) (i >= 0 ? sum_till[i] : 0)
#define get_sum_from(i, n) (i < n ? sum_from[i] : 0)

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &element[i]);

    vector <int> sum_till(no_of_elements, 0);
    sum_till[0] = element[0];
    for(int i = 1; i < no_of_elements; i++)
        sum_till[i] = element[i] + sum_till[i - 1];

    vector <int> sum_from(no_of_elements, 0);
    sum_from.back() = element.back();
    for(int i = no_of_elements - 2; i >= 0; i--)
        sum_from[i] = element[i] + sum_from[i + 1];

    int balance = -1;
    for(int i = 0; i < no_of_elements; i++)
    {
        if(get_sum_till(i - 1) == get_sum_from(i + 1, no_of_elements))
        {
            balance = i;
            break;
        }
    }

    printf("%d\n", balance);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
