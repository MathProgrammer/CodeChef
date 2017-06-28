#include <cstdio>

void solve()
{
    int no_of_cups, position, no_of_flips;
    scanf("%d %d %d",&no_of_cups, &position, &no_of_flips);

    for(int i = 1; i <= no_of_flips; i++)
    {
        int left, right, offset;
        scanf("%d %d", &left, &right);

        if(left <= position && right >= position)
        {
            offset = position - left;

            position = right - offset; //In the flip, l+i goes to r-i, sum = l+r remains invariant. We know the i, subtract it from r.
        }
    }

    printf("%d\n", position);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
