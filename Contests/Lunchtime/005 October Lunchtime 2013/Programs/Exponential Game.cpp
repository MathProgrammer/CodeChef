#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 1e5 + 5, MAX_MOVES = 7;
int grundy[MAX_N], moves[MAX_MOVES + 1];

int power(int x, int p)
{
    int answer = 1;
    for(int i = 1; i <= p; i++)
    {
        answer *= x;
    }
    return answer;
}

void precompute_moves()
{
    for(int i = 1; i <= MAX_MOVES; i++)
    {
        moves[i] = power(i, i);
    }
}

void precompute_grundy()
{
    grundy[0] = 0;
    for(int i = 1; i < MAX_N; i++)
    {
        set <int> S;
        grundy[i] = 0;
        for(int j = 1; j < MAX_MOVES; j++)
        {
            int move = moves[j];
            if(move <= i)
            {
                S.insert(grundy[i - move]);
                //cout << "Inserting " << move << " G = " << grundy[i - move] << "\n";
            }
        }
        
        for(int mex = 0; ; mex++)
        {
            //cout << "Mex = " << mex << " Coung = " << S.count(mex) << "\n";
            if(S.count(mex) == 0)
            {
                grundy[i] = mex;
                break;
            }
        }
        
        //cout << "Grundy " << i << " = " << grundy[i] << "\n";
    }
}

void precompute()
{
    precompute_moves();
    precompute_grundy();
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
    
    int total_xor = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        total_xor ^= grundy[A[i]];
    }
    
    cout << (total_xor != 0 ? "Little Chef" : "Head Chef") << "\n";
}

int main() 
{
    precompute();
    
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
