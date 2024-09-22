#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

const int N = 8;

bool is_valid(string& state, int row){
    for(int i=0; i<row; i++){
        if(state[i]==state[row]||abs(state[i]-state[row])==row-i){
            return false;
        }
    }
    return true;
}

bool dfs(string& state, int row){
    if(row==N){
        return true;
    }
    for(int col=0; col<N; col++){
        state[row]='0'+col;
        if(is_valid(state, row)){
            if(dfs(state, row+1)){
                return true; 
            }
        }
    }
    return false; 
}

void print_board(string& state){
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<(state[i]=='0'+j ? "Q ":". ");
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    string initial_state = "10102053"; 
    if(dfs(initial_state,0)){
        cout<<"Solution found:"<<endl;
        print_board(initial_state);
    } 
    else{
        cout<<"No solution found."<<endl;
    }
    return 0;
}
