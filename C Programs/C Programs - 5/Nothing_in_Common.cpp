#include <stdio.h>
#include <algorithm>

#define MAX_SIZE 1000000 + 1
using namespace std;

int alice[MAX_SIZE], berta[MAX_SIZE];

bool bin_search(int low, int high, int key)
{
    int mid;

    while(low <= high)
    {
        mid = (high + low)/2;

        if(berta[mid] == key)
            return true;
        else if(berta[mid] > key)
            high = mid - 1;
        else if(berta[mid] < key)
            low = mid + 1;
    }

    return false;
}

void solve()
{
    int number_of_alice_elements, number_of_berta_elements, i, number_of_common_elements = 0;
    scanf("%d %d", &number_of_alice_elements, &number_of_berta_elements);

    for(i = 0; i < number_of_alice_elements; i++)
        scanf("%d", &alice[i]);

    for(i = 0; i < number_of_berta_elements; i++)
        scanf("%d", &berta[i]);

    sort(alice, alice + number_of_alice_elements);
    sort(berta, berta + number_of_berta_elements);

    for(i = 0; i < number_of_alice_elements; i++)
        number_of_common_elements += (bin_search(0, number_of_berta_elements - 1, alice[i]));


    printf("%d\n",number_of_common_elements);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
