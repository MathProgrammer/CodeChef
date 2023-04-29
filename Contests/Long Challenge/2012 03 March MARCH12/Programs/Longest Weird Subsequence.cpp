#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 2005, NO_OF_ALPHABETS = 26;
int max_length[MAX_N][NO_OF_ALPHABETS][NO_OF_ALPHABETS];

void solve()
{
    string S; 
    cin >> S;
    
    int answer = 1;
    
    memset(max_length, 0, sizeof(max_length));
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        max_length[0][S[0] - 'a'][alpha] = 1; 
        max_length[0][alpha][S[0] - 'a'] = 1;
    }
    
    for(int i = 1; i < S.size(); i++)
    {
        for(int up_alpha = 0; up_alpha < NO_OF_ALPHABETS; up_alpha++)
        {
            for(int down_alpha = 0; down_alpha < NO_OF_ALPHABETS; down_alpha++)
            {
                
               max_length[i][up_alpha][down_alpha] = max(
                   max_length[i - 1][up_alpha][down_alpha], max_length[i][up_alpha][down_alpha]);
                
                int current_alpha = S[i] - 'a';
                if(up_alpha <= current_alpha)
                {   
                    max_length[i][current_alpha][down_alpha] = max(max_length[i][current_alpha][down_alpha], 
                        1 + max_length[i - 1][up_alpha][down_alpha]);
                }
                
                if(down_alpha >= current_alpha)
                {
                    max_length[i][up_alpha][current_alpha] = max(max_length[i][up_alpha][current_alpha],
                        1 + max_length[i - 1][up_alpha][down_alpha]);
                }
                
                answer = max(answer, max_length[i][up_alpha][down_alpha]);
            }
        }
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

