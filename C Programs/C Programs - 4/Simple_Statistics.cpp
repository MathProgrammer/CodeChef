#include <stdio.h>
#include <algorithm>

#define MAX_SIZE 10000 + 1
using namespace std;

void solve()
{
    int number_of_elements, number[MAX_SIZE], i, k, sum = 0;
    double average;
    scanf("%d %d", &number_of_elements, &k);

    for(i = 0; i < number_of_elements; i++)
        scanf("%d", &number[i]);

    sort(number, number + number_of_elements);

    for(i = k; i < number_of_elements - k; i++)
        sum += number[i];

    average = sum/(1.0*number_of_elements - 2*k);

    printf("%.6f\n",average);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
