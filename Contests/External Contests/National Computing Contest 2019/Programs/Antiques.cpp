#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 1e5 + 5, LOG_MAX = 18;
vector <int> tree[MAX_N];
int parent[MAX_N][LOG_MAX], depth[MAX_N];
long long mask[MAX_N], xor_till[MAX_N];

void set_bit(long long &n, int position)
{
    n |= (1LL << position);
}

int is_bit_set(long long n, int position)
{
    return ( (n&(1LL << position)) != 0);
}

int bit_count(long long n)
{
    int count = 0;

    while(n)
    {
        count += n%2;

        n /= 2;
    }

    return count;
}

void dfs(int v, int parent_v, int level)
{
    if(depth[v] != 0)
        return;

    xor_till[v] ^= xor_till[parent_v];

    parent[v][0] = parent_v;

    depth[v] = level;

    for(int i = 0; i < tree[v].size(); i++)
    {
        int v_child = tree[v][i];

        dfs(v_child, v, level + 1);
    }
}

void precompute_parents(int no_of_vertices)
{
    for(int bit = 1; bit < LOG_MAX; bit++)
    {
        for(int i = 1; i <= no_of_vertices; i++)
        {
            if(parent[i][bit - 1] != 0)
            {
                int ancestor = parent[i][bit - 1];

                parent[i][bit] = parent[ancestor][bit - 1];
            }
        }
    }
}

int LCA(int u, int v)
{
    if(depth[u] > depth[v])
        swap(u, v);

    int difference = depth[v] - depth[u];

    for(int bit = 0; bit < LOG_MAX; bit++)
    {
        if(is_bit_set(difference, bit))
        {
            v = parent[v][bit];
        }
    }

    if(u == v)
        return v;


    for(int bit = LOG_MAX - 1; bit >= 0; bit--)
    {
        if(parent[u][bit] != parent[v][bit])
        {
            u = parent[u][bit];
            v = parent[v][bit];
        }
    }

    return parent[v][0];
}

void solve()
{
    memset(depth, 0, sizeof(depth));
    memset(mask, 0, sizeof(mask));

    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    for(int i = 1; i <= no_of_vertices; i++)
    {
        tree[i].clear();

        int no_of_items;
        scanf("%d", &no_of_items);

        for(int j = 1; j <= no_of_items; j++)
        {
            int item;
            scanf("%d", &item);

            set_bit(mask[i], item);
        }

        xor_till[i] = mask[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0, 1);
    precompute_parents(no_of_vertices);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        int lca = LCA(x, y);

        long long x_mask = xor_till[lca]^xor_till[x]^mask[lca];
        long long y_mask = xor_till[lca]^xor_till[y]^mask[lca];

        long long result = (x_mask|y_mask);

        printf("%d\n", bit_count(result));
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
