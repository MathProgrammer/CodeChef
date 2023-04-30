#include <iostream>
using namespace std;

void solve()
{
    int no_of_vertices; 
    cin >> no_of_vertices;
    
    int parent_id_sum = 0, child_id_sum = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        int parent, child_sum;
        cin >> parent >> child_sum; 
        
        parent_id_sum += parent;
        child_id_sum += child_sum;
    }
    
    int root = parent_id_sum - child_id_sum;
    cout << root << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
