#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void StepNum(int n, vector<int>& step_num){
    for(int i = 2; i <= sqrt(n); i++){
        //判断是否为n的约数
        if(n % i == 0){
            step_num.push_back(i);
            //如果不为平方数，则还有一个约数
            if(n / i != i){
                step_num.push_back(n / i);
            }
        }
    }
}

int main(){
    int N, M;
    //输入
    while(cin >> N >>M){
        //创建一个结果数组
        vector<int> step;
        step.resize(M + 1, 0);
        step[N] = 1;
        //遍历结果数组
        for(int i = N; i < M; i++){
            //如果元素的值为0,表示该石板无法到达，跳过
            if(step[i] == 0){
                continue;
            }
            //创建一个数组，储存该石板可以到达的石板
            vector<int> step_num;
            StepNum(i, step_num);
            //遍历目标石板
            for(int j = 0; j < step_num.size(); j++){
                //可以到达的石板
                int ret = step_num[j] + i;
                if(ret <= M && step[ret] != 0){
                    step[ret] = min(step[i] + 1, step[ret]);
                }
                else if(ret <= M){
                    step[ret] = step[i] + 1;
                }
            }
        }
        //判断是否能到达M石板
        if(step[M] == 0){
            cout << -1 << endl;
        }
        else{
            cout << step[M] - 1 << endl;
        }
        
    }
    return 0;
}
