#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
    
    priority_queue <int> PQ;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);
        
        PQ.push(A[i]);
    }
    
    const int MOD = 1e9 + 7;
    long long answer = 0;
    for(int i = 0; PQ.size() > 0; i++)
    {
        while(PQ.size() > 0 && PQ.top() <= i)
        {
            PQ.pop();
        }
        
        if(PQ.size() == 0)
        {
            break;
        }
        
        answer += (PQ.top() - i);
        
        answer %= MOD;
        
        PQ.pop();
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

