#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main()
{
    int number_of_elements, i, number_i, length_of_current_non_zero_product = 0, max_non_zero_product_length = 0;
    scanf("%d",&number_of_elements);

    for(i = 1; i <= number_of_elements; i++)
    {
        scanf("%d", &number_i);

        length_of_current_non_zero_product = (number_i == 0 ? 0 : length_of_current_non_zero_product + 1);
        max_non_zero_product_length = max(max_non_zero_product_length, length_of_current_non_zero_product);
    }

    printf("%d\n",max_non_zero_product_length);
    return 0;
}
