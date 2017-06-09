#include <stdio.h>

int main()
{
    int no_of_test_cases;
    int angle_a, angle_b, angle_c;

    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
    {
        scanf("%d %d %d", &angle_a, &angle_b, &angle_c);

        printf( (angle_a > 0 && angle_b > 0 && angle_c > 0) && (angle_a + angle_b + angle_c == 180) ? "YES\n" : "NO\n");
    }
    return 0;
}
