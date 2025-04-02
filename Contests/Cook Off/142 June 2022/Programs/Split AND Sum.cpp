#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(int n, int bit)
{
    return ( (n& (1 << bit)) != 0 );
}

void solve()
{
    int no_of_elements; 
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    int possible = false;
    vector <pair <int, int> > segments;
    
    const int MAX_BITS = 30;
    for(int bit = 0; bit < MAX_BITS; bit++)
    {
        int frequency = 0;
        for(int i = 1; i <= no_of_elements; i++)
        {
            frequency += is_bit_set(A[i], bit);
        }
        
        if(frequency >= 2)
        {
            possible = true;
            int segment_count = 0;
            
            int left = 1, right = 1;
            for(int i = 1; i <= no_of_elements; i++)
            {
                if(is_bit_set(A[i], bit))
                {
                    segment_count++;
                }
                
                if(segment_count == 1 && 
                  (i == no_of_elements || is_bit_set(A[i + 1], bit)))
                {
                    right = i;
                    segments.push_back(make_pair(left, right));
                    
                    left = right + 1;
                    segment_count = 0;
                }
            }
            
            break;
        }
    }
    
    cout << (possible ? "YES" : "NO") << "\n";
    
    if(possible)
    {
        cout << segments.size() << "\n";
        for(int i = 0; i < segments.size(); i++)
        {
            cout << segments[i].first << " " << segments[i].second << "\n";
        }
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
