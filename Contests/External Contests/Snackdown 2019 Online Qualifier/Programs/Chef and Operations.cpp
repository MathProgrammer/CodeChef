#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%lld", &A[i]);

    vector <long long> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%lld", &B[i]);

    int possible = true;
    for(int i = no_of_elements; i > 2; i--)
    {
        if(A[i] > B[i])
            possible = false;

        int change = B[i] - A[i];

        if(change%3 != 0) possible = false;

        A[i] += change;
        A[i - 1] += 2*(change/3);
        A[i - 2] += change/3;
    }

    if(A[1] != B[1] || A[2] != B[2])
        possible = false;

    printf(possible ? "TAK\n" : "NIE\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

