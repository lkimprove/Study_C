#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define _MYROOT "./myroot/"

bool CreateFile(string& fileName, string& fileWord){
    //文件内容长度
    int len = fileWord.size() + 1; 
    //文件创建位置
    string path = _MYROOT + fileName;

    ofstream file(path);
    //打开文件
    if(!file.is_open()){
        cerr << "open file error" << endl;
        return false;
    }

    //将文件内容写入
    file.write(&fileWord[0], len);
    
    //判断文件是否写入
    if(!file.good()){
        cout << "write file error" << endl;
        return false;
    }

    //关闭文件
    file.close();

    return true;
}

int main(){
    string fileName, fileWord;
    cout << "请输入文件名" << endl;
    getline(cin, fileName);
    cout << "请输入文件内容" << endl;
    getline(cin, fileWord);    

    bool ret = CreateFile(fileName, fileWord);
    if(ret == false){
        cout << "创建文件失败" << endl;
    }
    else {
        cout << "创建文件成功" << endl;
    }

    return 0;
}
