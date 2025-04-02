#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int remainder_3(string S)
{
    int remainder = 0;

    for(int i = 0; i < S.size(); i++)
    {
        remainder = remainder*10 + (S[i] - '0');

        remainder %= 3;
    }

    return remainder;
}

void solve()
{
    string M, N;
    cin >> M >> N;

    int m_mod_3 = remainder_3(M);
    int n_mod_3 = remainder_3(N);

    int answer = (m_mod_3*n_mod_3)%3;
    printf("%d\n", answer);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

