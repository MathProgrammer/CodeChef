#include <iostream>

using namespace std;

void solve()
{
    int n, no_of_pairs;
    cin >> n >> no_of_pairs;
    
    int no_of_4_cycles = no_of_pairs/4;
    if(no_of_pairs%4 != 0)
    {
        no_of_4_cycles--;
    }
    
    for(int i = 0; i < no_of_4_cycles; i++)
    {
        cout << ( (i << 2)|0 ) << " " << ( (i << 2)|1 ) << "\n";
        cout << ( (i << 2)|1 ) << " " << ( (i << 2)|2 ) << "\n";
        cout << ( (i << 2)|2 ) << " " << ( (i << 2)|3 ) << "\n";
        cout << ( (i << 2)|3 ) << " " << ( (i << 2)|0 ) << "\n";
    }
    
    if(no_of_pairs == 3)
    {
        cout << "0 1\n";
        cout << "1 3\n";
        cout << "3 0\n";
        
        return;
    }
    
    int last = (1 << n) - 1;
    
    switch(no_of_pairs%4)
    {
        //0 -> 1 -> 2 -> 3 -> 5 -> 0
        case 1 :
            cout << last << " " << last - 1 << "\n";
            cout << last - 1 << " " << last - 2 << "\n";
            cout << last - 2 << " " << last - 3 << "\n";
            cout << last - 3 << " " << last - 5 << "\n";
            cout << last - 5 << " " << last << "\n";
            break;
        
        //0 -> 1 -> 2 -> 3 -> 5 -> 7 -> 0
        case 2:
            cout << last << " " << last - 1 << "\n";
            cout << last - 1 << " " << last - 2 << "\n";
            cout << last - 2 << " " << last - 3 << "\n";
            cout << last - 3 << " " << last - 5 << "\n";
            cout << last - 5 << " " << last - 7 << "\n";
            cout << last - 7 << " " << last << "\n";
            break;
        
        //0 > 1 -> 2 -> 3 -> 5 -> 4 -> 7 -> 0
        case 3 :
            cout << last << " " << last - 1 << "\n";
            cout << last - 1 << " " << last - 2 << "\n";
            cout << last - 2 << " " << last - 3 << "\n";
            cout << last - 3 << " " << last - 5 << "\n";
            cout << last - 5 << " " << last - 4 << "\n";
            cout << last - 4 << " " << last - 7 << "\n";
            cout << last - 7 << " " << last << "\n";
            break;
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
