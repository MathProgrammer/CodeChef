#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

struct segment
{
    int left, right, index;

};

const int MAX_N = 1e5 + 5, oo = 1e9 + 1;
vector <int> A(MAX_N, 0), zero_left(MAX_N, 0), zero_right(MAX_N, 0), first_segment_with_left(MAX_N, 0);
pair <int, int> min_tree[3*MAX_N];

int get_zero_left(int i)
{
    if(i == zero_left[i])
    {
        return zero_left[i];
    }

    zero_left[i] = get_zero_left(zero_left[i]);
    return zero_left[i];
}

int get_zero_right(int i)
{
    if(i == zero_right[i])
    {
        return zero_right[i];
    }

    zero_right[i] = get_zero_right(zero_right[i]);
    return zero_right[i];
}

void calculate_earliest_segment_for_each_position(int no_of_elements, int no_of_segments, vector <pair <int, int> > &S)
{
    for(int i = 1; i <= no_of_elements + 1; i++)
    {
        first_segment_with_left[i] = no_of_segments + 1;
    }

    for(int i = no_of_segments; i >= 1; i--)
    {
        first_segment_with_left[S[i].first] = i;

        //cout << "Segment First segment with left " << S[i].first << " = " << first_segment_with_left[S[i].first] << "\n";
    }

    for(int i = no_of_elements; i >= 1; i--)
    {
        if(first_segment_with_left[i] == no_of_segments + 1)
        {
            first_segment_with_left[i] = first_segment_with_left[i + 1];
        }

        //cout << "First segment with left " << i << " = " << first_segment_with_left[i] << "\n";
    }
}

pair <int, int> min(pair <int, int> A, pair <int, int> B)
{
    return (A.first < B.first ? A : B);
}

void build(int n, int left, int right, vector <pair <int, int> > &S)
{
    if(left == right)
    {
        int index = left;
        min_tree[n].first = S[index].second;
        min_tree[n].second = index;
        return;
    }

    int mid = (left + right)/2;
    build(LEFT(n), left, mid, S);
    build(RIGHT(n), mid + 1, right, S);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

void update(int n, int left, int right, int index, int value)
{
    if(index < left || right < index)
    {
        return;
    }

    if(left == right)
    {
        min_tree[n].first = value;
        return;
    }

    int mid = (left + right)/2;
    update(LEFT(n), left, mid, index, value);
    update(RIGHT(n), mid + 1, right, index, value);

    min_tree[n] = min(min_tree[LEFT(n)], min_tree[RIGHT(n)]);
}

pair <int, int> get_minimum(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left || right < left || query_right < query_left)
    {
        return make_pair(oo, 0);
    }

    if(query_left <= left && right <= query_right)
    {
        return min_tree[n];
    }

    int mid = (left + right)/2;
    pair <int, int> left_answer = get_minimum(LEFT(n), left, mid, query_left, query_right);
    pair <int, int> right_answer = get_minimum(RIGHT(n), mid + 1, right, query_left, query_right);

    pair <int, int> answer = min(left_answer, right_answer);

    return answer;
}

void subtract(int index)
{
    A[index]--;

    if(A[index] == 0 && A[index - 1] == 0)
    {
        zero_left[index] = zero_left[index - 1];
        zero_right[index - 1] = index;
    }

    if(A[index] == 0 && A[index + 1] == 0)
    {
        zero_right[index] = zero_right[index + 1];
        zero_left[index + 1] = index;
    }

    //cout << index << " is now " << A[index] << " New left = " << get_zero_left(index) << " New right = " << get_zero_right(index) << "\n";
}

int get_segments(int left, int right, int no_of_segments)
{
    int count = 0;
    while(get_minimum(1, 1, no_of_segments, first_segment_with_left[left], no_of_segments).first <= right)
    {
        count++;

        int index = get_minimum(1, 1, no_of_segments, first_segment_with_left[left], no_of_segments).second;

        //cout << "L = " << left << " First segment = " << first_segment_with_left[left] << "\n";
        //cout << "Minimum in [" << first_segment_with_left[left] << "," << no_of_segments << "] is "
        //<< get_minimum(1, 1, no_of_segments, first_segment_with_left[left], no_of_segments).first << " at index " << index << "\n";
        update(1, 1, no_of_segments, index, oo);
    }

   // cout << "Count = " << count << "\n";

    return count;
}

int main()
{
	int no_of_elements, no_of_segments;
	cin >> no_of_elements >> no_of_segments;

	for(int i = 1; i <= no_of_elements; i++)
	{
	    cin >> A[i];
	}

	zero_left[0] = 1;
	zero_right[no_of_elements + 1] = no_of_elements;
	for(int i = 1; i <= no_of_elements; i++)
    {
        zero_left[i] = zero_right[i] = i;
    }

	vector <pair <int, int> > S(no_of_segments + 1);
	for(int i = 1; i <= no_of_segments; i++)
	{
	    cin >> S[i].first >> S[i].second;
	}
	sort(S.begin(), S.end());
	calculate_earliest_segment_for_each_position(no_of_elements, no_of_segments, S);

	/*for(int i = 1; i <= no_of_segments; i++)
    {
        cout << "Segment " << i << " " << S[i].first << " " << S[i].second << "\n";
    }*/

	build(1, 1, no_of_segments, S);

	int no_of_operations;
	cin >> no_of_operations;

	vector <int> answer(no_of_operations + 1);
	for(int i = 1; i <= no_of_operations; i++)
	{
	    int encrypted_index;
	    cin >> encrypted_index;

	    int actual_index = encrypted_index + answer[i - 1];
	    subtract(actual_index);
	    answer[i] = answer[i - 1] + get_segments(get_zero_left(actual_index), get_zero_right(actual_index), no_of_segments);

	    //cout << "Answer = " << answer[i] << "\n";
	    cout << answer[i] << "\n";
	}

	return 0;
}

