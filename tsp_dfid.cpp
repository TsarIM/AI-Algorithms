#include <iostream>
#include <vector>
using namespace std;

bool TSP_DB_DFS(int current_city, int visited_mask, int current_dist, vector<int>& path, vector<int>& shortest_path, int& min_dist, const vector<vector<int>>& adj, int bound){
    int n = adj.size();
    
    if(path.size()>bound){ 
        return false;
    }

    if(visited_mask==(1<<n)-1){ 
        int total_dist = current_dist+adj[current_city][0];
        if(total_dist < min_dist){
            min_dist = total_dist;
            path.push_back(0);
            shortest_path = path;
            path.pop_back();
        }
        return true;
    }

    bool flag= false;
    for(int next_city=0; next_city<n; next_city++){
        //ith bit in the mask has and next_city are diff, i.e. it not visited yet
        if(!(visited_mask & (1<<next_city))){ 
            path.push_back(next_city);
            bool found= TSP_DB_DFS(next_city, visited_mask | (1<<next_city), current_dist+adj[current_city][next_city], path, shortest_path, min_dist, adj, bound);
            if(found)flag= true;
            path.pop_back();
        }
    }
    return flag;
}

void TSP_dfid(const vector<vector<int>>& adj, vector<int>& shortest_path, int& min_dist){
    int n= adj.size();
    int max_depth= n;

    for(int bound=1; bound<=max_depth; bound++){
        vector<int> path= {0}; 
        //depth bound dfs
        if(TSP_DB_DFS(0,1,0,path,shortest_path,min_dist,adj,bound)){
            break;
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

    TSP_dfid(adj, shortest_path, min_dist);

    cout<<"Minimum distance : "<<min_dist<<'\n';
    cout<<"Shortest path : ";
    for(int i=0; i<shortest_path.size()-1;i++){
        cout<<'C'<<shortest_path[i]+1<<"->";
    }
    cout<<"C1"<<'\n';

    return 0;
}



