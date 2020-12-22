#include <iostream>
#include <vector>

using namespace std;

void ask(int left_1, int right_1, int left_2, int right_2, int &answer)
{
    cout << "Q " << left_1 << " " << right_1 << " " << left_2 <<  " " << right_2 << "\n";
    cout.flush();
    
    cin >> answer;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    cin >> A[1] >> A[no_of_elements];
    
    vector <int> X(no_of_elements + 1), Y(no_of_elements + 1);
    for(int i = 1; i + 2 <= no_of_elements; i++)
    {
        int left_1 = i, right_1 = i + 1;
        int left_2 = i + 1, right_2 = i + 2;
        
        ask(left_1, right_1, left_2, right_2, X[i]);
        ask(left_2, right_2, left_1, right_1, Y[i]);
    }
    
    for(int i = 1; i + 2 <= no_of_elements; i += 2)
    {
        A[i + 2] = Y[i] - X[i] + A[i];
    }
    
    for(int i = no_of_elements - 2; i >= 1; i -= 2)
    {
        A[i] = X[i] - Y[i] + A[i + 2];
    }
    
    cout << "! ";
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
