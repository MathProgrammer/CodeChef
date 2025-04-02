#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>

using namespace std;

struct information
{
    int x, frequency, index;

    information(){};

    information(int X, int Y, int Z)
    {
        x = X, frequency = Y, index = Z;
    }
};

void solve()
{
    int no_of_elements, range, no_of_triplets;
    cin >> no_of_elements >> range >> no_of_triplets;

    vector <information> M(no_of_triplets + 1);
    for(int i = 1; i <= no_of_triplets; i++)
    {
        cin >> M[i].x >> M[i].frequency >> M[i].index;
    }

    vector <int> A(no_of_elements + 1);
    vector <int> expected_frequency_index(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_triplets; i++)
    {
        if(A[M[i].index] != 0)
        {
            cout << "No\n";

            return;
        }

         //cout << "First A" << M[i].index << " = " << M[i].x << "\n";
         A[M[i].index] = M[i].x;

        expected_frequency_index[M[i].index] = M[i].frequency;
    }

    vector <int> last(range + 1, 0);
    vector <int> frequency(range + 1, 0);
    set <int> free_indices;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(expected_frequency_index[i] == 0)
        {
            free_indices.insert(i);

            continue;
        }

        int x = A[i];

        frequency[x]++;

        if(frequency[x] > expected_frequency_index[i])
        {   //cout << "Frequency " << A[i] << " exceeding the expected frequency at " << i << " = " << expected_frequency_index[i] << "\n";
            cout << "No\n";

            return;
        }

        while(frequency[x] != expected_frequency_index[i])
        {
            if(free_indices.size() == 0)
            {   //cout << "No indices available for " << A[i] << " to make up the frequency = " << expected_frequency_index[i] << " at " << i << "\n";
                cout << "No\n";

                return;
            }

            set <int> :: iterator it = free_indices.lower_bound(last[x]);

            if(it == free_indices.end())
            {
                cout << "No\n";

                return;
            }

            int index = *it;

            free_indices.erase(it);

            A[index] = x; //cout << "A" << index << " = " << x << "\n";

            frequency[x]++;
        }

        last[x] = i;
    }

    set <int> available;
    for(int i = 1; i <= range; i++)
    {
        available.insert(i);
    }

    for(int i = no_of_elements; i >= 1; i--)
    {
        if(A[i] != 0)
        {
            available.erase(A[i]);
        }
        else if(A[i] == 0)
        {
            set <int> :: iterator it = available.begin();

            A[i] = *(it);

            //cout << "A" << i << " = " << A[i] << "\n";
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] == 0)
        {
            //cout << "All elements not filled i = " << i << "\n";
            cout << "No\n";

            return;
        }
    }

    for(int i = 1; i <= range; i++)
    {
        frequency[i] = 0;
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;

        if(expected_frequency_index[i] == 0)
        {
            continue;
        }

        if(frequency[A[i]] != expected_frequency_index[i])
        {   //cout << "Last Frequency " << A[i] << " =  " << frequency[A[i]] << " != Expected " << expected_frequency_index[i] << "\n";
            cout << "No\n";

            return;
        }
    }

    cout << "Yes\n";

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

