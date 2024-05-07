#include <iostream>
#include <vector> 
using namespace std;

const int MAX_N = 1e5 + 5, MOD = 1e9 + 7;
vector <long long> down_path(MAX_N), up_down_path(MAX_N);
vector <vector <int> > tree(MAX_N);

void clear(int n)
{
    for(int i = 1; i <= n; i++)
    {
        tree[i].clear();
        down_path[i] = 0;
        up_down_path[i] = 0;
    }
}

void dfs_down(int v, int parent_v)
{
    down_path[v] = 1;
    
    for(int child_v : tree[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs_down(child_v, v);
        
        down_path[v] += 2*down_path[child_v];
        down_path[v] %= MOD;
    }
}

void dfs_combine_siblings(int v, int parent_v)
{
    int no_of_children = tree[v].size();
    long long prefix_sum_down_paths = 0;
    
    for(int child_v : tree[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs_combine_siblings(child_v, v);
        
        up_down_path[v] += 2*down_path[child_v]*prefix_sum_down_paths;
        up_down_path[v] %= MOD;
        
        prefix_sum_down_paths += down_path[child_v];
        prefix_sum_down_paths %= MOD;
    }
}

void solve()
{
    int no_of_vertices; 
    cin >> no_of_vertices; 
    
    clear(no_of_vertices);
    
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v; 
        cin >> u >> v; 
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs_down(1, 0);
    dfs_combine_siblings(1, 0);
    
    long long answer = down_path[1];
    for(int v = 1; v <= no_of_vertices; v++)
    {
        answer += up_down_path[v];
        answer %= MOD;
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
