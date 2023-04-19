#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int no_of_elements, k;
	cin >> no_of_elements >> k;

	vector <int> A(no_of_elements + 2);
	for(int i = 1; i <= no_of_elements; i++)
	{
	    cin >> A[i];
	}

	const int oo = 1e9, MOD = 1e9 + 7;
	stack <int> lesser;
	lesser.push(no_of_elements + 1);
	A[no_of_elements + 1] = -oo;
	vector <int> next_lesser(no_of_elements + 1);
	for(int i = no_of_elements; i >= 1; i--)
	{
	    while(A[lesser.top()] >= A[i])
	    {
	        lesser.pop();
	    }

	    next_lesser[i] = lesser.top();
	    lesser.push(i);
	}

	long long answer = 1;
	for(int i = 1; i <= no_of_elements; i++)
	{
	    //cout << "Next Lesser " << next_lesser[i] << "\n";
	    if(next_lesser[i] <= no_of_elements)
	    {
	        answer *= (next_lesser[i] - i + 1);
	        answer %= MOD;
	    }
	}

	cout << answer << "\n";
	return 0;
}
