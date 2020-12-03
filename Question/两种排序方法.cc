#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Lexicographically(vector<string>& vs){
    for(int i = 0; i < vs.size() - 1; i++){
        int j = 0, size = vs[i].size() < vs[i + 1].size() ? vs[i].size() : vs[i + 1].size();
        
        for(; j < size; j++){
            if(vs[i][j] < vs[i + 1][j]){
                break;
            }
            else if(vs[i][j] > vs[i + 1][j]){
                return false;
            }
        }
        
        if(j == size && vs[i].size() > vs[i + 1].size()){
            return false;
        }
    }
    
    return true;
}

bool Lengths(vector<string>& vs){
    for(int i = 0; i < vs.size() - 1; i++){
        if(vs[i].size() > vs[i + 1].size()){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(cin >> n){
        vector<string> vs(n);
        
        for(int i = 0; i < n; i++){
            cin >> vs[i];
        }
        int lexicographically = Lexicographically(vs);
        int lengths = Lengths(vs);
        
        if(lexicographically){
            if(lengths){
                cout << "both" << endl;
            }
            else{
                cout << "lexicographically" << endl;
            }
        }
        else{
            if(lengths){
                cout << "lengths" << endl;
            }
            else{
                cout << "none" << endl;
            }
        }
    }
    
    return 0;
}
