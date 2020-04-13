#include <iostream>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    if(no_of_elements == 1)
    {
        cout << "1\n";
        
        cout << "1 1" << "\n";
        
        return;
    }
    
    int no_of_days = no_of_elements/2;
    cout << no_of_days << "\n";
    
    for(int i = 1; i <= no_of_days; i++)
    {
        if(i == 1 && no_of_elements%2 == 1)
        {
            cout << "3 ";
            
            cout << "1 2 " << no_of_elements << "\n";
            
            continue;
        }
        
        cout << "2 ";
        
        cout << 2*i - 1 << " " << 2*i << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
