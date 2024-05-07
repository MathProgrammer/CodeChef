#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements, no_of_swaps;
    scanf("%d %d", &no_of_elements, &no_of_swaps);

    vector <int> even;
    vector <int> odd;

    for(int i = 0; i < no_of_elements; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        if(i%2 == 0)
            even.push_back(a_i);
        else if(i%2 == 1)
            odd.push_back(a_i);
    }

    sort(all(even));
    reverse(all(even));

    sort(all(odd));

    for(int i = 0; i < odd.size() && i < even.size() && i < no_of_swaps; i++)
    {
        if(even[i] > odd[i])
            swap(even[i], odd[i]);
    }

    int odd_sum = 0, even_sum = 0;
    for(int i = 0; i < odd.size(); i++) odd_sum += odd[i];
    for(int i = 0; i < even.size(); i++) even_sum += even[i];

    printf(odd_sum > even_sum ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
