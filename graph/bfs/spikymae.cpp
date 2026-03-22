#include<iostream>
#include<vector>

int main()
{
    int n , m , j;
    
    cin>>n>>m>>j;
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
    
    fun(start.first , start.second , grid);
}


fun(int i , int j , vector<vector<char>> &grid)
{
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int obs=0;
    
    while(true)
    {
        for(int p =0 ; p<4 ; p++)
        {
            if( (grid[p].first+i <0) || (grid[p].second + j <0) ) continue;
            
            if(grid[grid[p].first][grid[p].second] == '#') continue;
            
            if(grid[grid[p].first][grid[p].second] == 's')
            {
              obs++;
              continue;
            }
            
            if(grid[grid[p].first][grid[p].second] == '.')
            {
              i= grid[p].first;
              j= grid[p].second;
              
              break;
            }
             
        }
    }
    
}
















