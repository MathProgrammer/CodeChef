#include <stdio.h>
#include <algorithm>

#define MAX_SIZE 1000000 + 1
using namespace std;

int main()
{
    int number_of_elements, number[MAX_SIZE], i;
    scanf("%d", &number_of_elements);

    for(i = 0; i < number_of_elements; i++)
        scanf("%d", &number[i]);

    sort(number, number + number_of_elements);

    for(i = 0; i < number_of_elements; i++)
        printf("%d\n",number[i]);

    return 0;
}
