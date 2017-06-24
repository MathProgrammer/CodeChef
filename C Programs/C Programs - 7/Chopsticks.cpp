#include <stdio.h>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(),(v).end()

using namespace std;

int main()
{
    int no_of_sticks, max_difference;
    scanf("%d %d", &no_of_sticks, &max_difference);

    vector <int> chopstick_length(no_of_sticks + 1);
    for(int i = 1; i <= no_of_sticks; i++)
        scanf("%d", &chopstick_length[i]);

    sort(all(chopstick_length));

    vector <int> max_chopstick_pairs(no_of_sticks + 1, 0);
    for(int i = 2; i <= no_of_sticks; i++)
    {
        max_chopstick_pairs[i] = max_chopstick_pairs[i - 1];

        if(chopstick_length[i] - chopstick_length[i - 1] <= max_difference)
            max_chopstick_pairs[i] = max(max_chopstick_pairs[i - 1], 1 + max_chopstick_pairs[i - 2]);
    }

    printf("%d\n", max_chopstick_pairs[no_of_sticks]);
    return 0;
}
