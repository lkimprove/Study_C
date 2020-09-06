#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define N 1000007
using namespace std;

int main(){
    string s1, s2;
    int len1, len2;
    while(cin >> s1 >> s2 >> len1 >> len2){
        //将s1，s2补长到len2的长度
        s1.append(len2 - s1.size(), 'a');
        s2.append(len2 - s2.size(), (char)('z' + 1));
        
        //计算出相对应位置的差值
        vector<int> array;
        for(int i = 0; i < len2; i++){
            array.push_back(s2[i] - s1[i]);
        }
        
        //计算s1与s2之间的字符串个数
        int ret = 0;
        for(int i = len1; i <= len2; i++){
            for(int j = 0; j < i; j++){
                ret += (array[j] * pow(26, i - 1 - j));
                ret %= N;
            }
        }
        
        //不包含s2本身
        cout << ret - 1 << endl;
        
    }
    
    return 0;
}
