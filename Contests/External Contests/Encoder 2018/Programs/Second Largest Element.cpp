#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> greater;
    greater.push_back(0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] > k)
        {
            greater.push_back(i);
        }
    }
    
    greater.push_back(no_of_elements + 1);
   
    int answer = 0;
    
    for(int i = 1; i + 1 < greater.size(); )
    {
        int left = greater[i - 1] + 1;
        int current_max = A[greater[i]];
      
        while(current_max == A[greater[i]])
        {
        	i++;
        }
        
        int right = greater[i] - 1;
        
        int segment_with_this_greater = right - (left - 1);
        answer = max(answer, segment_with_this_greater);
    }
    
    cout << answer << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
