#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long get_sum(vector <vector <long long> > &S, int R1, int C1, int R2, int C2)
{
    //cout << "Sum(" << R1 << "," << C1 << ") to (" << R2 << "," << C2 << ") = " << (S[R2][C2] - S[R1 - 1][C2] - S[R2][C1 - 1] + S[R1 - 1][C1 - 1]) << "\n";
    return (S[R2][C2] - S[R1 - 1][C2] - S[R2][C1 - 1] + S[R1 - 1][C1 - 1]);
}

long long matrix_size(int R1, int C1, int R2, int C2)
{
    return (R2 - R1 + 1)*1LL*(C2 - C1 + 1);
}

void solve()
{
    int rows, columns;
    long long k;
    cin >> rows >> columns >> k;

    vector <vector <long long> > matrix(rows + 1, vector <long long> (columns + 1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector <vector <long long> > sum(rows + 1, vector <long long> (columns + 1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

            //cout << sum[i][j] << " ";
        }//cout << "\n";
    }

    int no_of_worthy_matrices = 0;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            int remaining = min(rows - i, columns - j);

            int square_size = remaining + 1;
            //cout << "Max Square = " << i + square_size - 1 << "," << j + square_size - 1 <<
            //" Expected Sum = " << matrix_size(i, j, i + square_size - 1, j + square_size - 1)*k << " and actual = " <<
            //get_sum(sum, i, j, i + square_size - 1, j + square_size - 1) << "\n";
            if(get_sum(sum, i, j, i + square_size - 1, j + square_size - 1) < matrix_size(i, j, i + square_size - 1, j + square_size - 1)*k)
            {
                continue;
            }
            else if(matrix[i][j] >= k)
            {
                no_of_worthy_matrices += square_size;

                continue;
            }
            //cout << "From (" << i << "," << j << ") Remaining = " << remaining << "\n";
            //Square of size L is < K and R is >= K
            int left = 1, right = square_size;
            while(right - left > 1)
            {
                int mid = (left + right)/2; //cout << "Get Rectangle " << i << " " << j << " " << i + mid - 1 << " " << j + mid - 1 << "\n";

                if(get_sum(sum, i, j, i + mid - 1, j + mid - 1) < matrix_size(i, j, i + mid - 1, j + mid - 1)*k)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }

            //cout << "From (" << i << "," << j << ") Good Square Size = " << right << "\n";
            no_of_worthy_matrices += (square_size - right + 1);
        }
    }

    cout << no_of_worthy_matrices << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


