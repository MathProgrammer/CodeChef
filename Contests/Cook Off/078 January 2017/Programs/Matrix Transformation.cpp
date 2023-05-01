#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void read(vector <vector <int> > &M, int rows, int columns)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> M[i][j];
        }
    }
}

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <vector <int> > A(rows + 1, vector <int> (columns + 1));
    vector <vector <int> > B(rows + 1, vector <int> (columns + 1));
    read(A, rows, columns);
    read(B, rows, columns);

    vector <vector <int> > C(rows + 1, vector <int> (columns + 1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    int possible = true;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(C[i][j] - C[i][1] != C[1][j] - C[1][1])
            {
                possible = false;
            }
        }
    }

    if(!possible)
    {
        cout << "-1\n";

        return;
    }

    vector <long long> points;
    for(int i = 1; i <= columns; i++)
    {
        points.push_back(C[1][i]);
    }
    for(int i = 1; i <= rows; i++)
    {
        points.push_back(C[1][1] - C[i][1]);
    }

    sort(points.begin(), points.end());

    int median_index = points.size()/2 - (points.size()%2 == 0 ? 1 : 0);
    long long median = points[median_index];

    long long operations = 0;

    for(int i = 0; i < points.size(); i++)
    {
        operations += abs(points[i] - median);
    }

    cout << operations << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
