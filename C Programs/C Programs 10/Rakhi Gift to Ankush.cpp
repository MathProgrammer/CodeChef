#include <iostream>

using namespace std;

void solve()
{
	long long n;
	cin >> n;
	
	cout << (n%11 == 0 ? "A\n" : "S\n");
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
		solve();
		
	return 0;
}
