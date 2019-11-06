// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

static int Point[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
void Step(vector<vector<char>>& map, vector<vector<int>>& book, int x, int y, int m, int n, int& count){
    //防止越界
    if(x < 0 || y < 0 || x >= m || y >= n){
        return;
    }
    
    //判断当前位置是否判断过
    if(book[x][y] == 1){
        return;
    }
    book[x][y] = 1;
    
    if(map[x][y] == '#'){
        return;
    }
    
    if(map[x][y] == '.'){
        count++;
    }
    
    //DFS
    for(int i = 0; i < 4; i++){
        int newx = x + Point[i][0];
        int newy = y + Point[i][1];
        Step(map, book, newx, newy, m, n, count);
    }
}


int main(){
    int m, n;
    while(cin >> m >> n){
        vector<vector<char>> map(m, vector<char>(n));
        vector<vector<int>> book(m, vector<int>(n, 0));
        
        //起始位置
        int startX = 0;
        int startY = 0;
        
        //输入
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
                if(map[i][j] == '@'){
                    startX = i;
                    startY = j;
                }
            }
        }
        
        int count = 1;
        
        Step(map, book, startX, startY, m, n, count);
        
        cout << count << endl;
        
    }
    return 0;
}
