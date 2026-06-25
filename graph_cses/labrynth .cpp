#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>


using namespace std; 
int fun(int i , int j , vector<vector<char>> &grid , vector<vector<char>> &backtrack, int no , queue<pair<int,int>> &que);


int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<char>> backtrack(n,vector<char>(m));
    pair<int,int> start;
    pair<int,int> end;
    
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
             cin>>grid[i][j];  
        }
    }
    
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
             if(grid[i][j]=='A')
             {
                 start.first  = i;
                 start.second = j;
             }
             
             if(grid[i][j]=='B')
             {
                 end.first  = i;
                 end.second = j;
             }
             
        }
    }
    
    
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    queue<pair<int,int>> que;
    pair<int,int> stc;
    stack<char> finall;
    backtrack[start.first][start.second] = 'A';
    
    
    que.push({start.first,start.second});
    grid[start.first][start.second] ='#';
    
    bool found = false;
    int step = 0; 
    
    while(!que.empty() && !found)
    {
        int c = que.size();
        
            while(c!=0)
            {
                int i = que.front().first;
                int j = que.front().second;
                
                for(int x=0 ; x<4 ; x++)
                {
                 int ans =    fun(i+dir[x].first,j+dir[x].second,grid,backtrack , x+1, que);
                 
                 if(ans== -1)
                 {
                     stc.first = i+dir[x].first;
                     stc.second = j+dir[x].second;
                     found = true;
                     break;
                 }
                } 
                c--; 
                que.pop();          
            }
    }
    
    if(found == true)
    {
        while(backtrack[stc.first][stc.second] != 'A')
        {
            char way = backtrack[stc.first][stc.second];
            
            if(way == 'U')
            {
                stc.first = stc.first + 1;
                finall.push('U');
            }
            else
            {
                if(way == 'R')
                {
                    stc.second = stc.second - 1;
                    finall.push('R');
                } 
                else
                {
                    if(way == 'D')
                    {
                        stc.first = stc.first - 1;
                        finall.push('D');
                    }  
                    else
                    {
                        stc.second = stc.second +1 ;
                        finall.push('L');
                    }
                }
            } 
            
        }
        
        
        cout<<"YES\n";
        cout<<finall.size()<<"\n";
        while(!finall.empty())
        {
            cout<<finall.top();
            finall.pop();
        }
    }
    else 
    {
        cout<<"NO\n";
    }   

}
   
int fun(int i , int j , vector<vector<char>> &grid , vector<vector<char>> &backtrack, int no , queue<pair<int,int>> &que)
 {
     if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
     if(grid[i][j]=='#') return 0;
     
     char chh = grid[i][j];
     
     if(chh =='.' || chh =='B')
     {
         grid[i][j]='#';  
         if(no==1)
         {
             backtrack[i][j]='D';
             que.push({i,j});
         }
         else
         {
              if(no==2)
              {
                backtrack[i][j]='R';
                que.push({i,j});
              }
              else
              {
                  if(no==3)
                  {
                    backtrack[i][j]='U';
                    que.push({i,j});
                  }
                  else
                  {
                                 
                    backtrack[i][j]='L';
                    que.push({i,j});
              
                  }           
              }
         }
         
         if(chh=='B') return -1;
     } 
     
    return 0;
 }
 
  