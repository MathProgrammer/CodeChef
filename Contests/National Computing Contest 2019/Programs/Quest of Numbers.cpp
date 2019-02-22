#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long left, right;
    int n1, n2;
    cin >> left >> right >> n1 >> n2;

    const int MAX_DIGIT_SUM = 9;
    long long no_of_cycles = (right - left + 1)/9;

    vector <int> frequency(MAX_DIGIT_SUM + 1, no_of_cycles);

    for(long long i = left + 9*no_of_cycles; i <= right; i++)
    {
        frequency[i%9]++;
    }

    frequency[9] = frequency[0];
    
    if(frequency[n1] == frequency[n2])
        cout << "Draw\n";
    else
        cout << (frequency[n1] > frequency[n2] ? "Onkar\n" : "Krushna\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
