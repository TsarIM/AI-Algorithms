#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 8;

bool is_valid(string& state, int row){
    for(int i=0; i<row; i++){
        if(state[i]==state[row] || abs(state[i]-state[row])==row-i){
            return false;
        }
    }
    return true;
}

bool dfs_limited(string& state, int row, int bound){
    if(row==N){
        return true;
    }
    if(row==bound){
        return false;
    }
    for(int col=0; col<N; col++){
        state[row] = '0'+col;
        if(is_valid(state,row)){
            if(dfs_limited(state, row+1, bound)){
                return true; 
            }
        }
    }
    return false;
}

bool dfid(string& state){
    for(int bound=0; bound<=N; bound++){
        if(dfs_limited(state,0,bound)){
            return true;
        }
    }
    return false; 
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
    if(dfid(initial_state)){
        cout<<"Solution found:"<<'\n';
        print_board(initial_state);
    } 
    else{
        cout<<"No solution found."<<'\n';
    }
    return 0;
}
