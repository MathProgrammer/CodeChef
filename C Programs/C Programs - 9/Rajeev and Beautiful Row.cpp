#include <cstdio>

#define min(a, b) (a < b ? a : b)

void solve()
{
    const int MAX_SIZE = 50 + 3;
    char students[MAX_SIZE];
    scanf("%s", students + 1);

    students[0] = 'X';
    int no_of_left_segments = 0, no_of_right_segments = 0;

    for(int i = 1; students[i] != '\0'; i++)
    {
        if(students[i] != students[i - 1])
        {
            no_of_left_segments +=  (students[i] == 'L');
            no_of_right_segments += (students[i] == 'R');
        }
    }

    printf("%d\n", min(no_of_left_segments, no_of_right_segments));
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
