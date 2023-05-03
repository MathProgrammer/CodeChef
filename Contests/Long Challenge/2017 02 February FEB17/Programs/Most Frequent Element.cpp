#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int no_of_elements, no_of_queries;
    cin >> no_of_elements >> no_of_queries;

    vector <int> A(no_of_elements + 5);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> left_equal(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        left_equal[i] = (A[i] == A[i - 1] ? left_equal[i - 1] : i);
    }

    vector <int> right_equal(no_of_elements + 1);
    for(int i = no_of_elements; i >= 1; i--)
    {
        right_equal[i] = (A[i] == A[i + 1] ? right_equal[i + 1]: i);
    }

    for(int i = 1; i <= no_of_queries; i++)
    {
        int left, right, k;
        cin >> left >> right >> k;

        int mid = left + (right - left)/2;
        int segment_left = max(left, left_equal[mid]);
        int segment_right = min(right, right_equal[mid]);
        int segment = segment_right - segment_left + 1;

        cout << (segment < k ? -1 : A[mid]) << "\n";
    }

    return 0;
}
