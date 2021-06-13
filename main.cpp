#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include "maze_generation.cpp"
#include "maze_solver.cpp"
#include <utility>
#include <time.h>




//done with
void view_map( int x_max, int y_max,    std::vector< std::vector<bool>> &wall_map)
{
    for(int i=0 ; i<x_max*2+1; i++,std::cout << "_");//add extra to account for space taken up be |for boxes
    std::cout << std::endl;//flushes the stream//not needed

    for(int j =0;j<y_max;j++)
    {
        std::cout << "|";
        for(int i=0;i<2*x_max;i++)
        {
            if(wall_map[i][j])//false is a wall so not is true
            {
                if( (i/2)*2 == i)//even
                {
                    std::cout << "_";
                }
                else
                {
                    std::cout << "|";
                }
            }   
            else
            {
                if( (i/2)*2 == i)//even
                    std::cout << " ";
                else
                    std::cout << ".";
            }
        }
         std::cout << std::endl;
    }



}



int main()
{


    srand(time(NULL));

    int y=10;
    int x=10;
    
	std::vector<std::vector<bool>> visited    {{false}};
    std::vector<std::vector<bool>> wall_map   {{ true}};
    std::vector<std::vector<bool>> en_route   {{ true}};

    path_(visited,wall_map,x,y);
    view_map(x, y,  wall_map);
    //solve maze


    std::stack< std::pair<int,int>> route;

    path_solver(route,visited,wall_map,x,y);
    route_to_enroute( x, y,route,en_route);
    view_map(x, y,  wall_map);

    std::cout << std::endl;
    std::cout <<".";
    for(int j=0;j<y;j++,std::cout<<".\n.")
        for(int i=0;i<x;i++)
            if(en_route[i][j])      std::cout << "*";
            else                    std::cout << " ";
    std::cout << std::endl;
	//initialize to size 2x,y	

 visited[0][0]=false;


	return 0;
}
