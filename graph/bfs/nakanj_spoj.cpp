
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

int main()
{
    int t;
    cin>>t;
    
    while(t!=0)
    {
        process();
        t--;
    }

    
}

void process()
{
    vector<vector<int>> grid(8,vector<int>(8,-1));
    string strS , strE;
    cin>>strS>>strE;
    
    
    pair<int,int> curr,pairE;
    curr.first  = (int)strS[0]%97;
    curr.second = (int)strs[1]%49;
    
    pairE.first  = (int)strE[0]%97;
    pairE.second = (int)strE[1]%49;
    
    queue<pair<int,int>> que;
    que.push(curr);
    grid[curr.first][curr.second] = 1;
    
    vector<vector<int>> dir = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    
    bool ans = false;
    
    int steps = 0;
    
    while(!que.empty)
    {
        int u,v;
        
        u = que.front().first;
        v = que.front().second;
        
        que.pop();
        
        for(int lv = 0 ; lv<8 ; i++)
        {
           ans = bfs(dir[lv][0],dir[lv][1],u,v,que,pairE,grid,steps);
           
           if(ans==true) break;
        }
        
        
        if(ans==true) break;
    }
    
    
    cout<<steps<<"\n";
    
    
    
    
}


bool bfs(int &i , int &j , int u , int v queue<pair<int,int>> &que , pair<int,int> &pairE , vector<vector<int>> &grid, int &steps)
{
    u = u+i;
    v = v+j;
    
    if(u<0 || v<0 || grid[u][v] == 1) return false;
    
    if(u==pairE.first && v==pairE.second)
    {
        grid[u][v]=1;
        steps++;
        return true;
    }
    
    pair<int,int> curr(u,v);
    
    que.push(curr);
    grid[u][v]=1;
    steps++;
    
    return false;
    
    
}

