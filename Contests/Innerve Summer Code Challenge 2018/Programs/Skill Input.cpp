#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
#define all(v) (v).begin(), (v).end()

const int MAX_N = 1e5 + 15;
const long long oo = 1e16;
vector <int> tree[3*MAX_N];
int Y[MAX_N];

void merge(vector <int> &S, vector <int> &A, vector <int> &B)
{
    for(int a_ptr = 0, b_ptr = 0; a_ptr < A.size() || b_ptr < B.size(); )
    {
        if(a_ptr == A.size())
        {
            S.push_back(B[b_ptr++]);
        }
        else if(b_ptr == B.size())
        {
            S.push_back(A[a_ptr++]);
        }
        else
        {
            if(A[a_ptr] <= B[b_ptr])
                S.push_back(A[a_ptr++]);
            else if(B[b_ptr] < A[a_ptr])
                S.push_back(B[b_ptr++]);
        }
    }
}

void build(int n, int left, int right)
{
    if(left == right)
    {
        tree[n].push_back(Y[left]);
        return;
    }

    int mid = (left + right) >> 1;
    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    merge(tree[n], tree[LEFT(n)], tree[RIGHT(n)]);
}

long long get_answer(int n, int left, int right, int query_left, int query_right, int k)
{
    if(query_right < left || right < query_left)
        return oo;

    if(query_left <= left && right <= query_right)
    {
        int upper = lower_bound(all(tree[n]), k) - tree[n].begin(); //First element >= k
        int lower = (upper == 0 ? 0 : upper - 1); //First element < k

        long long answer = (abs(k - tree[n][lower]) <= abs(k - tree[n][upper]) ? tree[n][lower] : tree[n][upper]);
        return answer;
    }

    int mid = (left + right) >> 1;
    long long left_answer = get_answer(LEFT(n), left, mid, query_left, query_right, k);
    long long right_answer = get_answer(RIGHT(n), mid + 1, right, query_left, query_right, k);

    return (abs(left_answer - k) <= abs(right_answer - k) ? left_answer : right_answer);
}

int main()
{
    const int SUM = 1e9;
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        scanf("%d", &x);

        Y[i] = SUM - x;
    }

    build(1, 1, no_of_elements);

    while(no_of_queries--)
    {
        int left, right, k;
        scanf("%d %d %d", &left, &right, &k);

        long long best_y = get_answer(1, 1, no_of_elements, left, right, k);
        long long best_x = SUM - best_y;

        printf("%lld\n", best_x);
    }

    return 0;
}
