class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
      

        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> que;


        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                   if(grid[i][j]==2)
                   {
                     que.push({i,j});
                   }          
                
            }
        }
        
        bfs(grid,que);

        for(int i = 0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
    
        return bfs(grid,que);
    }
    
    int bfs(vector<vector<int>> &grid , queue<pair<int,int>> &que)
    {
        int mins = 0;
        
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!que.empty())
        {
            mins++;
            int sz = que.size();
            
          for(int l = 0 ; l< sz ; l++)
          {
               for(int k = 0 ; k<4 ; k++)
               {
                  fun(grid,dir[k].first + que.front().first, dir[k].second + que.front().second , que);
               }
               
               que.pop();
          }
        
        }
        
        return mins;
    }
    
    int fun(vector<vector<int>> &grid , int n , int m, queue<pair<int,int>> &que)
    {
        if(n>=grid.size() || m>=grid[0].size() || n<0 || m<0) return 0;
        
        if(grid[n][m]==-1) return 0;
        
        if(grid[n][m]==0)
        {
            return 0;
        }
        
        

        if(grid[n][m]==1)
        {
          que.push({n,m});
          grid[n][m] = -1;
        }
        return 0;
        
    }
};
