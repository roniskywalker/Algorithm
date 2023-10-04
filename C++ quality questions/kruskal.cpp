#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int u, int v)
    {
        u = find(u);

        v = find(v);

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                int temp = u;
                u = v;
                v = temp;
            }
            parent[v] = u;

            if (rank[u] == rank[v])
                rank[u]++;
        }
    }
};

class Edge
{
public:
    int u, v, weight;

    Edge(int U, int V, int Weight)
    {
        u = U;
        v = V;
        weight = Weight;
    }
};
class Graph
{
public:
    int V, E;
    vector<Edge> edges;
    Graph(int v, int e)
    {
        V = v;
        E = e;
    }
    static bool comparator(Edge e1, Edge e2)
    {
        return e1.weight < e2.weight;
    }
    void MST_Kruskal()
    {
        int e = 0, i = 0, sum = 0;
        DSU dsu(V);

        sort(edges.begin(), edges.end(), comparator);

        while (e < V - 1)
        {
            Edge edge = edges[i++];

            int u = dsu.find(edge.u);
            int v = dsu.find(edge.v);

            if (u != v)
            {
                cout << "Adding edge " << edge.u << " <---> " << edge.v << " to MST\n";

                sum += edge.weight;
                dsu.Union(u, v);
                e++;
            }
        }
        cout << "MST has a weight of " << sum;
    }

    void addEdge(int u, int v, int weight)
    {
        edges.push_back(Edge(u, v, weight));
    }
};
int main()
{
    Graph g(6, 9);
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 2);

    g.MST_Kruskal();
    return 0;
}
