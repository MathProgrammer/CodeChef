#include <iostream>
#include <vector>
using namespace std;

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

struct node
{
    int total_mod;
    vector <long long> prefix_count, suffix_count; 
    long long total_count;
    
    node()
    {
        total_mod = 0;
        total_count = 0;
        prefix_count.resize(3, 0);
        suffix_count.resize(3, 0);
    }
    
    node(int n)
    {
        total_mod = n%3;
        
        prefix_count.resize(3, 0);
        suffix_count.resize(3, 0);
        
        prefix_count[total_mod] = suffix_count[total_mod] = 1;
        total_count = (n%3 == 0);
    }
};

const int MAX_N = 2e5;
node sum_tree[3*MAX_N];

node add(node &L, node &R)
{
    node sum;
    
    sum.total_mod = L.total_mod + R.total_mod;
    sum.total_mod %= 3;
    
    for(int m = 0; m < 3; m++)
    {
        sum.prefix_count[m] += L.prefix_count[m];
        sum.suffix_count[m] += R.suffix_count[m];
        
        int new_prefix_mod = (L.total_mod + m)%3;
        sum.prefix_count[new_prefix_mod] += R.prefix_count[m];
        
        int new_suffix_mod = (R.total_mod + m)%3;
        sum.suffix_count[new_suffix_mod] += L.suffix_count[m];
    }
    
    sum.total_count = L.total_count + R.total_count;
    for(int m = 0; m < 3; m++)
    {
        int remaining_m = (3 - m)%3;
        sum.total_count += L.suffix_count[m]*R.prefix_count[remaining_m];
    }
    
    return sum;
}

void update(int n, int left, int right, int position, int value)
{
    if(position < left || right < position)
    {
        return;
    }
    
    if(left == right)
    {
        sum_tree[n] = node(value);
        return;
    }
    
    int mid = (left + right)/2;
    
    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);
    
    sum_tree[n] = add(sum_tree[LEFT(n)], sum_tree[RIGHT(n)]);
}

node get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(query_right < left || right < query_left)
    {
        return node();
    }
    
    if(query_left <= left && right <= query_right)
    {
        return sum_tree[n];
    }
    
    int mid = (left + right)/2;
    
    node left_node = get_sum(LEFT(n), left, mid, query_left, query_right);
    node right_node = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);
    node sum = add(left_node, right_node);
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int length, no_of_queries;
    cin >> length >> no_of_queries;
    
    string S;
    cin >> S;
    
    for(int i = 0; i < S.size(); i++)
    {
        update(1, 1, length, i + 1, S[i] - '0');
    }
    
    for(int i = 0; i < no_of_queries; i++)
    {
        const int UPDATE = 1, COUNT = 2;
        int query_type;
        cin >> query_type;
        
        switch(query_type)
        {
            case UPDATE :
            {
                int position, value;
                cin >> position >> value;
                update(1, 1, length, position, value);
                
                break;
            }
            
            case COUNT :
            {
                int left, right;
                cin >> left >> right;
                
                node segment = get_sum(1, 1, length, left, right);
                cout << segment.total_count << "\n";
                
                break;
            }
        }
    }
    
    return 0;
}