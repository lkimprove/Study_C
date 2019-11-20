#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//获取约数
void AppNumber(int x, vector<int>& step){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            step.push_back(i);
            if(i != sqrt(x)){
                step.push_back(x / i);
            }
        }
    }
}

int main(){
    int M, N;
    while(cin >> N >> M){
        vector<int> map(M + 1, 0);
        map[N] = 1;    //起始位置置1
        
        //遍历每一个石板
        for(int i = N; i < M; i++){
            //越过不能到达的石板
            if(map[i] == 0){
                continue;
            }
            
            //储存当前石板的约数
            vector<int> step;
            AppNumber(i, step);
            
            //遍历目标石板
            for(int j = 0; j < step.size(); j++){
                //目标石板
                int ret = i + step[j];
                //防止越界
                if(ret > M){
                    continue;
                }
                
                //目标石板没有被到达
                if(map[ret] == 0){
                    map[ret] = map[i] + 1;
                }
                //如果目标石板被到达过，则更新目标石板的值，取最小值
                else{
                    if(map[ret] > map[i] + 1){
                        map[ret] = map[i] + 1;
                    }
                }
            }
        }
        
        //判断M石板是否可以到达
        if(map[M] == 0){
            cout << -1 << endl;
        }
        else{
            cout << map[M] - 1 << endl;
        }
    }
    
    return 0;
}
