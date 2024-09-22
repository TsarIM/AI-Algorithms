#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void TSP_bfs(vector<vector<int>>& adj, vector<int>& shortest_path, int &min_dist){

    int n = adj.size();
    // current city, visited_mask, current_distance, path
    queue<pair< pair<int,int> , pair<int, vector<int> >>> open;
    // Mask when all cities are covered, later used as a conditional
    int final_mask = (1<<n)-1;

    open.push({{0,1},{0,{0}}});

    while(!open.empty()){
        int current_city = open.front().first.first;
        int visited_mask = open.front().first.second;
        int current_dist = open.front().second.first;
        vector<int> partial_path = open.front().second.second;
        open.pop();

        //if all cities explored
        if(visited_mask == final_mask){
            //add dist to go back to initial city
            int total_dist = current_dist+adj[current_city][0];
            //keep track of minimum path
            if(total_dist < min_dist){
                min_dist = total_dist;
                partial_path.push_back(0); 
                shortest_path = partial_path; 
            }
            continue; 
        }

        for(int next_city=0; next_city<n; next_city++){
            //ith bit in the mask has and next_city are diff, i.e. it not visited yet
            if(!(visited_mask & (1<<next_city))){ 
                vector<int> new_path = partial_path;
                new_path.push_back(next_city); 
                //marking the visited bit in the mask
                int new_visited_mask = visited_mask | (1 << next_city);
                int new_cost = current_dist + adj[current_city][next_city];
                open.push({{next_city, new_visited_mask},{new_cost, new_path}});
            }
        }
    }
}

int main(){
    
    vector<vector<int>> adj={
        {0, 20, 23, 1},
        {20, 0, 35, 53},
        {23, 35, 0, 10},
        {1, 53, 10, 0}
    };

    int min_dist = 1e9;
    vector<int> shortest_path;

    TSP_bfs(adj, shortest_path, min_dist);

    cout<<"Minimum distance : "<<min_dist<<'\n';
    cout<<"Shortest path : ";
    for(int i=0; i<shortest_path.size()-1; i++){
        cout <<'C'<<shortest_path[i]+1<<"->";
    }
    cout<<"C1"<<'\n';

    return 0;
}
