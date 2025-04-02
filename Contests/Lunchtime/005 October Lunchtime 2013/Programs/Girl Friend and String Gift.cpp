#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 5005;
int is_palindrome[MAX_N][MAX_N];

void solve()
{
    int S_length;
    string S; 
    cin >> S_length >> S;
    
    for(int length = 1; length <= S.size(); length++)
    {
        for(int left = 0, right = left + length - 1; right < S.size(); left++, right++)
        {
            is_palindrome[left][right] = false;
            
            if(length == 1)
            {
                is_palindrome[left][right] = true;
            }
            else if(length == 2)
            {
                is_palindrome[left][right] = (S[left] == S[right]);
            }
            else if(S[left] == S[right] && is_palindrome[left + 1][right - 1])
            {
                is_palindrome[left][right] = true;
            }
        }
    }
    
    vector <int> minimum_palindromes(S.size(), S.size());
    for(int right = 0; right < S.size(); right++)
    {
        for(int left = right; left >= 0; left--)
        {
            if(is_palindrome[left][right])
            {
                int palindromes_before = (left == 0 ? 0 : 
                        minimum_palindromes[left - 1]);
                minimum_palindromes[right] = min(minimum_palindromes[right], 
                            1 + palindromes_before);
                            
                //cout << "[" << left << "," << right << "] = " << minimum_palindromes[right] << "\n";
            }
        }
    }
    
    cout << minimum_palindromes[S.size() - 1] << "\n";
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
