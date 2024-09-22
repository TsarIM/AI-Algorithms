#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

const int N = 8;

bool is_valid(string& state, int row){
    for(int i = 0; i<row; i++){
        if(state[i]==state[row]||abs(state[i]-state[row])==row-i){
            return false;
        }
    }
    return true;
}

string bfs(string& initial_state){
    queue<string> open;
    open.push(initial_state);
    unordered_set<string> visited;

    while(!open.empty()){
        string state = open.front();
        open.pop();

        if(visited.find(state)!=visited.end())continue;
        visited.insert(state);
        int row = 0;
        while(row<N && is_valid(state,row))row++;
        if(row==N){
            return state;
        }
        for(int col=0; col<N; col++){
            if(col != state[row]){
                string new_state = state;
                new_state[row] = '0'+col;
                open.push(new_state);
            }
        }
    }
    return {};
}

void print_board(string& state){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<(state[i]=='0'+j ? "Q ":". ");
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    string initial_state = "10102053";
    string solution = bfs(initial_state);
    if(!solution.empty()){
        cout<<"Solution found:"<<endl;
        print_board(solution);
    }
    else{
        cout<<"No solution found."<<endl;
    }
    return 0;
}