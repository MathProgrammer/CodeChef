#include <cstdio>
#include <map>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%lld", &A[i]);

    map <long long, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = 1; j <= no_of_elements; j++)
        {
            frequency[A[i]*A[i] + A[j]*A[j]]++;
        }
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = 1; j <= no_of_elements; j++)
        {
            answer += frequency[A[i]*A[i] + A[j]];
        }
    }

    printf("%lld\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

