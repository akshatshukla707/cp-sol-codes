#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

void process();
bool dfs(int s , int p , vector<vector<int>> &connect , vector<int> &check ,int &N);

int main()
{
    int t ;
    cin>>t;
    
    while(t!=0)
    {
        process();
        
        t--;
    }

    return 0;
}

void process()
{
    int N, R , M;
    cin>>N>>R>>M;
    
    vector<vector<int>> connect(N+1);
    vector<pair<int,int>> power(M+1);
    
    for(int i=1 ; i<=R ; i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    
    for(int j = 0; j<M ; j++)
    {
       cin>>power[j].first>>power[j].second;
    }
    
    
    vector<int> check(N+1,0);
    
    bool ans = true;
    
    for(int z=0 ; z<M ; z++)
    {
        
        ans = dfs(power[z].first , power[z].second , connect , check ,N);
        
        if(ans==false)
        { 
            cout<<"No\n";
            return;
        }
        
    }
    
    for(int i = 1 ; i<N+1 ; i++)
    {
        if(check[i]==0)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

bool dfs(int s , int p , vector<vector<int>> &connect , vector<int> &check ,int &N)
{
   
   if(check[s]==1) return false;
   
   if(p==0){check[s]=1; return true;}
   
   
    queue<int> que;
    que.push(s);
    vector<int> parent(N+1,-1);
    
    parent[s]=-1;
    check.push_back(s);
    
    while(p!=0)
    {
        int c = que.size();
        
        while(c!=0)
        {
            int v = que.front();
            que.pop();
            
            for(int val : connect[v])
            {
                if(val == parent[v]) continue;
                
                parent[val] = v;
                
                if(check[val]==1) return false;
                
                que.push(val);
                check[val]=1;
                
            }
            c--;
        }
        p--;
    }
    
    
    
    return true;
}




#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

void process();
bool dfs(int s , int p , vector<vector<int>> &connect , vector<int> &check ,int &N);

int main()
{
    int t ;
    cin>>t;
    
    while(t!=0)
    {
        process();
        
        t--;
    }

    return 0;
}

void process()
{
    int N, R , M;
    cin>>N>>R>>M;
    
    vector<vector<int>> connect(N+1);
    vector<pair<int,int>> power(M+1);
    
    for(int i=1 ; i<=R ; i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    
    for(int j = 0; j<M ; j++)
    {
       cin>>power[j].first>>power[j].second;
    }
    
    
    vector<int> check(N+1,0);
    
    bool ans = true;
    
    for(int z=0 ; z<M ; z++)
    {
        
        ans = dfs(power[z].first , power[z].second , connect , check ,N);
        
        if(ans==false)
        { 
            cout<<"No\n";
            return;
        }
        
    }
    
    for(int i = 1 ; i<N+1 ; i++)
    {
        if(check[i]==0)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

bool dfs(int s , int p , vector<vector<int>> &connect , vector<int> &check ,int &N)
{
   
   if(check[s]==1) return false;
   
   if(p==0){check[s]=1; return true;}
   
   
    queue<int> que;
    que.push(s);
    vector<int> parent(N+1,-1);
    
    parent[s]=-1;
    check.push_back(s);
    
    while(p!=0)
    {
        int c = que.size();
        
        while(c!=0)
        {
            int v = que.front();
            que.pop();
            
            for(int val : connect[v])
            {
                if(val == parent[v]) continue;
                
                parent[val] = v;
                
                if(check[val]==1) return false;
                
                que.push(val);
                check[val]=1;
                
            }
            c--;
        }
        p--;
    }
    
    
    
    return true;
}



