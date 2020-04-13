#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

long long total(long long n)
{
    return (n*(n - 1)/2) + n;
}

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);
    }
    
    vector <int> exponent_2(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        while(A[i] != 0 && A[i]%2 == 0)
        {
            A[i] /= 2;
            
            exponent_2[i]++;
        }
    }
    
    vector <int> exponent_sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        exponent_sum[i] = exponent_sum[i - 1] + exponent_2[i];
    }
    
    long long bad_sequences = 0;
    map <long long, int> frequency;
    frequency[0]++;
    for(int i = 1; i <= no_of_elements; i++)
    {
        bad_sequences += frequency[exponent_sum[i] - 1];
        
        frequency[exponent_sum[i]]++;
    }
    
    long long good_sequences = total(no_of_elements) - bad_sequences;
    
    cout << good_sequences << "\n";
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
        solve();
    
    return  0;
}
