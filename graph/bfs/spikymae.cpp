#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int fun(int i , int j , vector<vector<char>> &grid , int n , int m );
int main()
{
    int n , m , s;
    
    cin>>n>>m>>s;
    pair<int,int> start;
    vector<vector<char>> grid(n,vector<char>(m));
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin>>grid[i][j];
            
            if(grid[i][j]=='@')
            {
                start.first  = i;
                start.second = j;
            }
        }
    }
    
    int obs = fun(start.first , start.second , grid , n , m);
    
    if(2*obs <= s)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
        
    }
    
}


int fun(int i , int j , vector<vector<char>> &grid, int n , int m)
{
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int obs=0;
    
    while(true)
    {
        int f = 0; 
        for(int p =0 ; p<4 ; p++)
        {
            if( (dir[p].first+i <0) || (dir[p].second + j <0) || grid[dir[p].first+i][dir[p].second+j] == '/' || (dir[p].second + j ==m) || (dir[p].second + i == n) ) continue;
            
            if(grid[dir[p].first+i][dir[p].second+j] == '#') continue;
            
            if(grid[dir[p].first+i][dir[p].second+j] == 's')
            {
              grid[dir[p].first+i][dir[p].second+j] = '/';
              
              i= dir[p].first +i;
              j= dir[p].second+j;
              obs++;
              
              break;
            }
            else
            {
             if(grid[dir[p].first+i][dir[p].second+j] == '.')
             {
              
              grid[dir[p].first+i][dir[p].second+j] = '/';
              i= dir[p].first+i;
              j= dir[p].second+j;
              
              break;
              
             }
             else
             {
                f=1;
                break;
             }
             
            }             
       
          
      
        }
        
        if( f==1 ) break;
        
    }
    
    
    return obs;
}
