#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    
    vector <int> nearest_end(S.size() + 5, -1);
    stack <int> positions;
    
    for(int i = 0; i < S.size(); i++)
    {
        switch(S[i])
        {
            case '(' : positions.push(i); break;
            
            case ')' : if(!positions.empty())
                        {
                            nearest_end[positions.top()] = i;
                            positions.pop();
                        }
        }
    }
    
    for(int i = S.size() - 1; i >= 0; i--)
    {
        if(S[i] == ')')
        {
            nearest_end[i] = nearest_end[i + 1];
        }
    }
    
    int no_of_queries;
    cin >> no_of_queries;
    
    while(no_of_queries--)
    {
        int p;
        cin >> p;
        
        cout << (nearest_end[p - 1] == -1 ? -1 : nearest_end[p - 1] + 1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
        
    return 0;
}
