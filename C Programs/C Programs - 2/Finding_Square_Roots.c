#include <stdio.h>

void solve()
{
    int square_root = 1, number;
    scanf("%d",&number);

    while(square_root*square_root <= number)
        square_root++;

    square_root--;
    printf("%d\n",square_root);
}

int main()
{
    int no_of_test_cases;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
