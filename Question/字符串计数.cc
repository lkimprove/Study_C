#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define N 1000007
using namespace std;

int main(){
    string s1, s2;
    int len1, len2;
    while(cin >> s1 >> s2 >> len1 >> len2){
        //将s1与s2补全至len2长度
        //s1补('a')，s2补('z' + 1),保证进制依旧为26
        s1.append(len2 - s1.size(), 'a');
        s2.append(len2 - s2.size(), (char)('z' + 1));
        
        //记录每一位的差值
        vector<int> array;
        for(int i = 0; i < len2; i++){
            int cur = s2[i] - s1[i];
            
            array.push_back(cur);
        }
        
        //按26进制计算出两个字符串中间的字符串个数
        int ret = 0;
        for(int i = len1; i <= len2; i++){
            for(int j = 0; j < i; j++){
                ret += (array[j] * pow(26, i - 1 - j));
                
                ret %= N;
            }
        }
        
        //中间的字符串不包括s1与s2
        cout << ret - 1 << endl;
    }
    
    return 0;
}
