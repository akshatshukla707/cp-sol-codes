#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
#include <functional>
using namespace std;
void dijkstra(vector<vector<pair<int,int>>> &grid);
using namespace std;

int main()
{
    int n,m;
    
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> grid(n+1);
    int u,v,d;
    
    for(int i=1 ; i<=m ; i++)
    {
        cin>>u>>v>>d;
        
        grid[u].push_back({d,v});
        grid[v].push_back({d,u});
        
    }
    
    dijikstra(grid);
    
    
    
    return 0;
}



void dijkstra(vector<vector<pair<int,int>>> &grid)
{
    int n = grid.size() - 1;

    vector<int> distance(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> visited(n+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[1] = 0;
    pq.push({0,1});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int dis  = pq.top().first;
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(auto &edge : grid[node])
        {
            int cdis  = edge.first;
            int child = edge.second;

            if(distance[node] + cdis < distance[child])
            {
                distance[child] = distance[node] + cdis;
                parent[child] = node;

                pq.push({distance[child], child});
            }
        }
    }

    // print distances
    for(int i=1;i<=n;i++)
        cout << distance[i] << " ";
}














