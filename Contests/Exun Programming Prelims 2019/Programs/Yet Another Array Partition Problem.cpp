#include <iostream>
#include <vector>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

const int MAX_N = 1e6 + 5;
int no_of_elements;
int original[MAX_N], A[MAX_N], sum_tree[3*MAX_N];

void build(int n, int left, int right)
{
    if(left == right)
    {
        sum_tree[n] = A[right];

        return;
    }

    int mid = (left + right)/2;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)]; //cout << "S(" << left << "," << right << ") = " << sum_tree[n] << "\n";
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left || query_right < query_left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum_tree[n];

    int mid = (left + right)/2;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

void update(int n, int left, int right, int position, int value)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        sum_tree[n] = A[right];

        return;
    }

    int mid = (left + right)/2;
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int main()
{
    int no_of_queries;
    cin >> no_of_elements >> no_of_queries;

    original[0] = 1e9 + 5;
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> original[i];

        A[i] = (original[i]%original[i - 1] == 0 ? 0 : 1);
    }

    build(1, 1, no_of_elements);

    const int UPDATE = 1, QUERY = 2;
    for(int i = 1; i <= no_of_queries; i++)
    {
        int query_type, position, value;
        cin >> query_type;

        if(query_type == UPDATE)
        {
            cin >> position >> value;

            original[position] = value;

            if(A[position] == 1 && original[position]%original[position - 1] == 0)
            {
                A[position] = 0;

                update(1, 1, no_of_elements, position, 0);
            }

            if(A[position] == 0 && original[position]%original[position - 1] != 0)
            {
                A[position] = 1;

                update(1, 1, no_of_elements, position, 1);
            }

            if(position == no_of_elements)
            {
                continue;
            }

            if(A[position + 1] == 1 && original[position + 1]%original[position] == 0)
            {
                A[position + 1] = 0;

                update(1, 1, no_of_elements, position + 1, 0);
            }

            if(A[position + 1] == 0 && original[position + 1]%original[position] != 0)
            {
                A[position + 1] = 1;

                update(1, 1, no_of_elements, position + 1, 1);
            }
        }
        else if(query_type == QUERY)
        {
            //for(int i = 1; i <= no_of_elements; i++) cout << A[i] << " "; cout << "\n";
            //for(int i = 1; i <= no_of_elements; i++) cout << get_sum(1, 1, no_of_elements, 1, i) << " "; cout << "\n";

            cin >> position;

            int no_of_segments_till_here = get_sum(1, 1, no_of_elements, 1, position);

            int left = 0, right = position;

            while(right - left > 1)
            {
                int mid = (left + right)/2;

                if(get_sum(1, 1, no_of_elements, 1, mid) < no_of_segments_till_here)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }

            cout << right << "\n";
        }
    }

    return 0;
}
