#include <iostream>
#include <vector>
#include <utility>
#include <stack>

void route_to_enroute(int x_max,int y_max,std::stack< std::pair<int,int>> &route,std::vector<std::vector<bool>> &en_route)
{
    std::pair<int,int> trace;

    en_route.resize(x_max);
    for(int i=0;i<x_max;i++)
        en_route[i].resize(y_max);

    for(int i=0;!route.empty();i++)
    {
        trace = route.top();
        route.pop();
        en_route[trace.first][trace.second] = true;
    }

}

void path_solver(std::stack< std::pair<int,int>> &route, std::vector<std::vector<bool>> &visited, std::vector<std::vector<bool>> &wall_map,int x_max,int y_max,int x_min=0,int y_min=0)
{
    //0-3 direct
    std::pair<int,int>next;
    next.first = 0;
    next.second = 0;
    route.push(next);
    bool success=true;

    for(int direction=-1,fail=0;     ((next.first != x_max-1) || (next.second != y_max-1))     ;)
    {

        if(success)
            direction++;
        else
            direction--;

        success=false;

        if(direction == 4)
            direction=0;  
        if(direction < 0)
            direction = 3;

        fail++;
        if (fail == 4)
            {
            next = route.top();
            route.pop();
            fail=0;
            }
            

        switch(direction)// check for wall
        {
                               
        case 0://right
            if(x_max <= next.first+1)//no go right
        continue;
            if(!visited[next.first+1][next.second])//already gone
        continue;
            if(wall_map[2*next.first+1][next.second])//wall
        continue;
                next.first++;
        break;


        case 1://up
            if(next.second == 0) //no go up
        continue;
            if(!visited[next.first][next.second-1])//checking if been there
        continue;
            if(wall_map[2*next.first][next.second-1])
        continue;
                next.second--;
        break;


        case 2://left
            if(next.first == 0)//no go 1 /left
        continue;            
            if(!visited[next.first-1][next.second])
        continue;
            if(wall_map[2*next.first-1][next.second])
        continue;
                next.first--;
        break;

        case 3://down
            if(y_max <= next.second+1)//no go 3 /down
        continue;
            if(!visited[next.first][next.second+1])
        continue;
            if(wall_map[2*next.first][next.second])
        continue;
                next.second++;
        break;

        default:
            std::cout << "ERROR inner/MY_RAND ERROR";
        break;

        }

        //suceed
        success=true;
        route.push(next);
        visited[next.first][next.second]=false;
        fail=0;

    }
}
