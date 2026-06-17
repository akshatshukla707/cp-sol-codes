#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> grid(n+1);
    
    
    
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        
        cin>>u>>v;
     
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    
    
    queue<int> que;
    vector<int> parent(n+1,0);
    vector<int> visited(n+1,-1);
    vector<pair<int,int>> connect;
    
    int roads=0;
    for(int x=1; x<grid.size() ; x++)
    {
        if(visited[x]== -1)
        {
            roads++;
            connect.push_back({x,x-1});
            que.push(x);
            
            visited[x]=1;
            
            while(!que.empty())
            {
                int c = que.size();
                 
                 while(c!=0)
                 {
                     int fr = que.front();
                     
                     for(int u : grid[fr])
                     {
                         
                        
                           if(parent[u]==fr) continue;;
                           
                           if(visited[u]== -1)
                           {
                             parent[u] = fr;
                             que.push(u);
                              
                           }
                           visited[fr]=1;
                     }
                     
                     c--;
                     que.pop();
                 }   
                
            }
            
            
            
        }
    }
    
    cout<<roads-1;
    for(int uu=0 ; uu<connect.size() ; uu++)
    {
        if(uu==0) continue;
        
        cout<<"\n"<<connect[uu].first<<" "<<connect[uu].second;
    }
    
}