#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int number_of_elements;
    scanf("%d", &number_of_elements);

    vector <int> frequency(1e4 + 1, 0);
    for(int i = 1; i <= number_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency[element_i]++;
    }

    int most_frequent_element = 1;
    for(int i = 2; i <= 1e4; i++)
        if(frequency[i] > frequency[most_frequent_element])
            most_frequent_element = i;

    printf("%d %d\n", most_frequent_element, frequency[most_frequent_element]);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
