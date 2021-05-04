#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5, MAX_L = 21;
int parent[MAX_N][MAX_L];
int depth[MAX_N];
int is_special[MAX_N];
int nearest_special[MAX_N];
vector <int> tree[MAX_N];

void initialise(int n)
{
    for(int i = 1; i <= n; i++)
    {
        tree[i].clear();

        is_special[i] = false;

        depth[i] = 0;

        nearest_special[i] = 0;
    }
}

int is_bit_set(int n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

int get_ancestor(int v, int length)
{
    for(int l = MAX_L; l >= 0; l--)
    {
        if(is_bit_set(length, l))
        {
            v = parent[v][l];
        }
    }

    return v;
}

void dfs(int v, int parent_v = 0)
{
    parent[v][0] = parent_v;

    depth[v] = depth[parent_v] + 1;

    if(is_special[v])
    {
        nearest_special[v] = v;
    }

    for(int child_v : tree[v])
    {
        if(child_v != parent_v)
        {
            dfs(child_v, v);

            if(nearest_special[v] == 0 && nearest_special[child_v] != 0)
            {
                nearest_special[v] = nearest_special[child_v];
            }
        }
    }
}

void fill_parents(int n)
{
    for(int l = 1; l < MAX_L; l++)
    {
        for(int v = 1; v <= n; v++)
        {
            int previous_ancestor = parent[v][l - 1];

            parent[v][l] = parent[previous_ancestor][l - 1];
        }
    }
}

void solve()
{
    int no_of_vertices, special_vertices, a;
    cin >> no_of_vertices >> special_vertices >> a;

    initialise(no_of_vertices);

    for(int i = 1; i <= special_vertices; i++)
    {
        int v;
        cin >> v;

        is_special[v] = true;
    }

    int no_of_edges = no_of_vertices - 1;

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    depth[0] = -1;
    dfs(a, 0);
    fill_parents(no_of_vertices);

    vector <pair <int, int> > answer(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(nearest_special[i] != 0)
        {
            answer[i].first = depth[i];

            answer[i].second = nearest_special[i];

            continue;
        }

        int ancestor, distance_to_ancestor;

        int v = i;

        for(int l = MAX_L - 1; l >= 0; l--)
        {
            ancestor = parent[v][l];

            if(ancestor != 0 && nearest_special[ancestor] == 0)
            {
                v = ancestor;
            }
        }


        ancestor = parent[v][0];


        distance_to_ancestor = depth[i] - depth[ancestor];

        answer[i].first = depth[ancestor] - distance_to_ancestor;

        answer[i].second = nearest_special[ancestor];
    }

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cout << answer[i].first << " ";
    }
    cout << "\n";

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cout << answer[i].second << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
