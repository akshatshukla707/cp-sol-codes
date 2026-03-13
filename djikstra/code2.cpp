#include<iostream>
#include<functional>
#include<queue>
#include<utility>

using namespace std;

int main()
{
    
    int n , m ;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> vec(n+1);
    
    int u,v,d;
    
    for(int i=1 ; i<=m ; i++)
    {
        cin>>u>>v>>d;
        
        vec[u].push_back({d,v});
        vec[v].push_back({d,u});
        
    }
    
    for(int i=1; i<=n ; i++)
    {
        
        
        int k = vec[i].size();
        
        for(int j = 0 ; j<k ; j++)
        {
           cout<<"\n "<<i<<" "<<vec[i][j].first<<" "<<vec[i][j].second;  
        }

        
    }
    
    
    
    priority_que<pair{int , int}, vector<pair{int,int}, greater<pair<int,int>>> pq;
    vector<int> check(n,-1) , dis(n,0);
    
    
    pq.push({0,1});
    
    
    while(!pq.empty())
    {
        
        int sz = vec[pq.top().second].size();
        
        for(int ii=0 ; ii<sz ; ii++)
        {
            if(check[vec[pq.top().second][ii].second]==-1)
            {
                pq.push({vec[pq.top().second][ii].first , vec[pq.top().second][ii].second});
                
                dist[vec[pq.top().second][ii].second] = dist[pq.top().second] + vec[]
            }
        }
        
        pq.pop();
    }
    

    
    return 0;
}
