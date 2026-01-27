#include<iostream>
#include<vector>
#include<queue>
#include<pair>
#include<utility>
#include<functional>

int main()
{
    int n , m , u , v , d;
    cin>>n>>m;
    vector<vector<pair<int,int>>> grid(n+1);
    
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v>>d;
        grid[u].push_back({d,v});
        grid[v].push_back({d,u});
    }
    
    vector<vector<int>> check(n+1,vector<int>(n+1,-1));
}
