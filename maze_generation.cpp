#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <utility>




void path_(std::vector<std::vector<bool>> &visited, std::vector<std::vector<bool>> &wall_map,int x_max,int y_max)
{
    
    int num=0;
    bool been[4];
    int fail=0;

    std::stack< std::pair<int,int>> wall_breaker;
    std::pair<int,int> next;
    next.first = 0;
    next.second = 0;
    visited[next.first][next.second]=true;
    wall_breaker.push(next);


    
    //resizeing visited
    visited.resize(x_max);
    for(int i=0;i<x_max;i++)
        visited[i].resize(y_max);
    

    //resizeing wallmap
    wall_map.resize(2*x_max+1);
    for(int i=0;i<2*x_max+1;i++)
        wall_map[i].resize(y_max+1);


    //initiallizing walls
    for (int i=0;i<x_max*2+1;i++)
        for(int j=0;j<y_max+1;j++)
            wall_map[i][j]=true;

    for(;   !wall_breaker.empty() ;num=rand()%4)//all here
    {
        if(been[num])
        {
            fail++;
            if(fail==4)
            {
                next = wall_breaker.top();
                wall_breaker.pop();
                fail=0;
                been[0]=false;
                been[1]=false;
                been[2]=false;
                been[3]=false;
            }
            continue;
        }
        been[num]=true;


        switch(num)//total rand
        {
    

                              
        case 0://right
            if(x_max <= next.first+1)//no go 0 /right
        continue;
            if(visited[next.first+1][next.second])
        continue;
                next.first++;
        break;


        case 1://left
            if(next.first == 0)//no go 1 /left
        continue;            
            if(visited[next.first-1][next.second])
        continue;
               next.first--;
        break;


        case 2://up
            if(next.second == 0) 
        continue;
            if(visited[next.first][next.second-1])//checking if been there
        continue;
            next.second--;
        break;


        case 3://down
           if(y_max <= next.second+1)//no go 3 /down
        continue;
             if(visited[next.first][next.second+1])
        continue;
            next.second++;
        break;


        default:
            std::cout << "ERROR inner/MY_RAND ERROR";
        break;
        }


        //reset bools
        fail=0;
        been[0]=false;
        been[1]=false;
        been[2]=false;
        been[3]=false;
        wall_breaker.push(next);//was going down i think??
        visited[next.first][next.second]=true;

        switch(num)
        {
        case 0://x++;
            wall_map[2*next.first-1][next.second]=false;
            break;
        case 1://x--;
            wall_map[2*next.first+1][next.second]=false;
            break;
        case 2://y-- going up
            wall_map[2*next.first][next.second]=false;
            break;
        case 3://y++;//going down
            wall_map[2*next.first][next.second-1]=false;
            break;
        default:
        std::cout << "ERROR with wall deletion";
            break;
        }

    }


}
