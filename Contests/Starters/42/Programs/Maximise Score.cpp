#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

const int MAX_N = 1e5 + 5, oo = 1e9 + 9;

struct node
{
    int position, value;

    node(int P, int V)
    {
        position = P, value = V;
    }

    node()
    {
        position = 0, value = 0;
    }
};

node min(node &N1, node &N2)
{
    if(N1.value < N2.value)
    {
        return N1;
    }
    else if(N1.value > N2.value)
    {
        return N2;
    }
    else
    {
        return (N1.position < N2.position ? N1 : N2);
    }
}

struct segment
{
    int left, right, distance, value;

    segment()
    {
        left = right = distance = value = 0;
    }

    segment(int L, int R, int V)
    {
        left = L, right = R, value = V;
        distance = right - (left - 1);
    }

    int operator<(segment &S)
    {
        if(distance == S.distance)
        {
            return (value > S.value);
        }

        return (distance < S.distance);
    }
};

node min_tree[3*MAX_N];

void update(int n, int left, int right, int position, int value)
{
    if(right < left || position < left || right < position)
    {
        return;
    }

    if(left == right)
    {
        min_tree[n] = node(position, value);
        return;
    }

    int mid = (left + right)/2;
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

node query(int n, int left, int right, int query_left, int query_right)
{
    //cout << "Entering At [" << left << "," << right << "] And Q[" << query_left << "," << query_right << "]\n";
    if(query_right < left || right < query_left || query_right < query_left)
    {
        //cout << "Completely out At [" << left << "," << right << "] And Q[" << query_left << "," << query_right << "]\n";
        return node(-1, oo);
    }

    if(query_left <= left && right <= query_right)
    {
        //cout << "Completely in At [" << left << "," << right << "] And Q[" << query_left << "," << query_right << "]\n";
        return min_tree[n];
    }

    //cout << "Partially in At [" << left << "," << right << "] And Q[" << query_left << "," << query_right << "]\n";
    int mid = (left + right)/2;
    node left_answer = query(LEFT(n), left, mid, query_left, query_right);
    node right_answer = query(RIGHT(n), mid + 1, right, query_left, query_right);

    node answer = min(left_answer, right_answer);
    return answer;
}

void solve()
{
    int no_of_segments;
    cin >> no_of_segments;
    vector <segment> S(no_of_segments + 1);
    for(int i = 1; i <= no_of_segments; i++)
    {
        int left, right, value;
        cin >> left >> right >> value;
        S[i] = segment(left, right, value);
    }
    sort(S.begin() + 1, S.end());

    int no_of_elements = no_of_segments;
    for(int i = 1; i <= no_of_elements; i++)
    {
        update(1, 1, no_of_elements, i, 0);
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_segments; i++)
    {
        //cout << "Sorted Segment " << i << " = [" << S[i].left << "," << S[i].right << "] V = " << S[i].value << "\n";
        if(query(1, 1, no_of_elements, S[i].left, S[i].right).value < S[i].value)
        {
            node result = query(1, 1, no_of_elements, S[i].left, S[i].right);
            //cout << "Result V = " << result.value << " P = " << result.position << "\n";

            answer += (S[i].value - result.value);

            update(1, 1, no_of_elements, result.position, S[i].value);
        }
    }

    cout << answer << "\n";
}

int main()
{
	int no_of_test_cases;
	cin >> no_of_test_cases;

	while(no_of_test_cases--)
	    solve();

	return 0;
}

