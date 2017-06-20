#include <stdio.h>
#include <vector>
using namespace std;

void solve()
{
    vector <int> chef_set(4 + 1);
    const int no_of_subsets = (4*4 - 1);
    bool zero_sum_subset_exists = false;

    for(int i = 0; i < 4; i++)
        scanf("%d", &chef_set[i]);

    //Each bitmask uniquely represents 1 subset
    for(int bitmask = 1; bitmask <= no_of_subsets; bitmask++)
    {
        int subset_sum = 0;

        for(int i = 0; i < 4; i++)
            if( (bitmask& (1 << i)) != 0 )
               subset_sum += chef_set[i];

        if(subset_sum == 0)
            zero_sum_subset_exists = true;
    }

    printf(zero_sum_subset_exists ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
