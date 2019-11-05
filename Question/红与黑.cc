#include <iostream>
#include <vector>
using namespace std;

void Step(vector<vector<char>>& map, vector<vector<int>>& book, int x, int y, int m, int n, int& count){
    //防越界
    if(x < 0 || y < 0 || x >= m || y >= n){
        return;
    }
    //查看标记，防止死循环
    if(book[x][y] == 1){
        return;
    }
    //当进入判断，则改变标记
    book[x][y] = 1;
    
    //判断当前瓷砖颜色
    if(map[x][y] == '#'){
        return;
    }
    if(map[x][y] == '.'){
        count++;
    }
    
    //递归判断
    Step(map, book, x + 1, y, m, n, count);
    Step(map, book, x - 1, y, m, n, count);
    Step(map, book, x, y + 1, m, n, count);
    Step(map, book, x, y - 1, m, n, count);
}


int main(){
    int m, n;
    while(cin >> m >> n){
        //创建二维数组储存
        vector<vector<char>> map(m, vector<char>(n));
        //创建标记
        vector<vector<int>> book(m, vector<int>(n, 0));
        
        //起始位置
        int startX = 0;
        int startY = 0;
        //输入并获取起始位置
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
