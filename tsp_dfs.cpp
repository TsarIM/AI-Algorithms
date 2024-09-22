#include <iostream>
#include <vector>
using namespace std;

void TSP_dfs(int current_city, int visited_mask, int current_dist, vector<int>& path, vector<int>& shortest_path, int& min_dist, const vector<vector<int>>& adj) {
    int n= adj.size();
    //(1<<n)-1 is the state of mask when all cities visited
    if(visited_mask==(1<<n)-1){ 
        int total_dist = current_dist+adj[current_city][0];
        if(total_dist < min_dist){
            min_dist = total_dist;
            path.push_back(0); 
            shortest_path = path;
            path.pop_back();
        }
        return;
    }

    for(int next_city = 0; next_city<n; next_city++){
        //ith bit in the mask has and next_city are diff, i.e. it not visited yet
        if(!(visited_mask & (1<<next_city))){ 
            path.push_back(next_city);
            //no explicit open set maintained here, Call Stack is used as the open set
            TSP_dfs(next_city,visited_mask|(1<<next_city),current_dist+adj[current_city][next_city],path,shortest_path,min_dist,adj);
            path.pop_back();
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
    vector<int> path = {0};

    TSP_dfs(0,1,0, path, shortest_path, min_dist, adj);

    cout<<"Minimum distance : "<<min_dist<<'\n';
    cout<<"Shortest path : ";
    for(int i=0; i<shortest_path.size()-1;i++){
        cout<<'C'<<shortest_path[i]+1<<"->";
    }
    cout<<"C1"<<'\n';

    return 0;
}
