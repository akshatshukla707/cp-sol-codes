
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
    
    
    pair<int,int> prS,prE;
    prS.first  = (int)strS[0]%97;
    prS.second = (int)strs[1]%49;
    
    prE.first  = (int)strE[0]%97;
    prE.second = (int)strE[1]%49;
    
    
    
    
}
