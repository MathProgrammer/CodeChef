#include <cstdio>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int no_of_subsets = (1LL << no_of_elements);
    multiset <int> sum_set;

    for(int i = 1; i <= no_of_subsets; i++)
    {
        int sum;
        scanf("%d", &sum);

        sum_set.insert(sum);
    }

    vector <long long> subset_sums;
    vector <int> original_array;

    //Dealing with null set
    sum_set.erase(0); //Deleting null set
    subset_sums.push_back(0);

    while(original_array.size() < no_of_elements)
    {
        multiset <int> :: iterator it = sum_set.begin();
        int current_element = *it;

        int current_subset_sum_stored = subset_sums.size();

        for(int i = 0; i < current_subset_sum_stored; i++)
        {
            multiset <int> :: iterator it2 = sum_set.find(current_element + subset_sums[i]);

            int current_sum = *it2;

            sum_set.erase(it2);

            subset_sums.push_back(current_sum);
        }

        original_array.push_back(current_element);
    }

    for(int i = 0; i < no_of_elements; i++)
        printf("%d ", original_array[i]);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
