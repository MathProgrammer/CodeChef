#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 1e5 + 5;
int max_tree[3*MAX_N];

struct query
{
    int left, right, query_no;
};

int sort_by_right(const query &A, const query &B)
{
    return (A.right < B.right);
}

void update(int n, int left, int right, int index, int value)
{
    if(right < index || index < left)
        return;

    if(left == right)
    {
        max_tree[n] = max(max_tree[n], value);
        return;
    }

    int mid = (left + right) >> 1;
    update(LEFT(n), left, mid, index, value);
    update(RIGHT(n), mid + 1, right, index, value);

    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

int get_max(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return max_tree[n];

    int mid = (left + right) >> 1;
    int left_answer = get_max(LEFT(n), left, mid, query_left, query_right);
    int right_answer = get_max(RIGHT(n), mid + 1, right, query_left, query_right);

    return max(left_answer, right_answer);
}

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <query> Q;
    for(int i = 1; i <= no_of_queries; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        Q.push_back({left, right, i});
    }

    sort(all(Q), sort_by_right);

    memset(max_tree, 0, sizeof(max_tree));
    map <int, int> last_occurence;
    int last_query = 0;
    vector <int> answer(no_of_queries + 1);

    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int d = 1; d*d <= A[i]; d++)
        {
            if(A[i]%d == 0)
            {
                int divisor_1 = d, divisor_2 = A[i]/d;

                if(last_occurence[divisor_1] != 0)
                {
                    update(1, 1, no_of_elements, last_occurence[divisor_1], divisor_1);
                }

                last_occurence[divisor_1] = i;

                if(divisor_1 == divisor_2)
                    continue;

                if(last_occurence[divisor_2] != 0)
                {
                    update(1, 1, no_of_elements, last_occurence[divisor_2], divisor_2);
                }

                last_occurence[divisor_2] = i;
            }
        }

        while(last_query < Q.size() && Q[last_query].right == i) //Answer all queries ending here
        {
            answer[Q[last_query].query_no] = get_max(1, 1, no_of_elements, Q[last_query].left, Q[last_query].right);

            last_query++;
        }
    }

    for(int i = 1; i <= no_of_queries; i++)
        printf("%d\n", answer[i]);

    return 0;
}
