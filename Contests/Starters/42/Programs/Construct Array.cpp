#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    //a(a + 3) (a + 1)(a + 2) a(a + 2) (a + 1)(a + 3)
    //gcd(1, 3) = a
    //gcd(2, 3) = a + 2
    //gcd(2, 4) = a + 1
    //gcd(1, 4) = a + 3
    int first_new = 1;
    switch(no_of_elements%4)
    {
        case 1 : A[1] = 1;
                first_new = 2;
                break;

        case 2 : A[1] = 1, A[2] = 2;
                first_new = 3;
                break;

        case 3 : A[1] = 2, A[2] = 3, A[3] = 6;
                 first_new = 4;
                 break;
    }

    for(; first_new <= no_of_elements; first_new += 4)
    {
        A[first_new] = first_new*(first_new + 3);
        A[first_new + 1] = (first_new + 1)*(first_new + 2);
        A[first_new + 2] = first_new*(first_new + 2);
        A[first_new + 3] = (first_new + 1)*(first_new + 3);
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

	return 0;
}

