//相同类型的不同对象可以互相访问对方的私有成员
//本质上是因为成员在类内进行访问，没有出类域，类内部没有访问限制

#include <iostream>
using namespace std;

class Text{
    private:
        int _text;
    public:
        Text():_text(-1){}

        int Get(){
            return _text;
        }

        void Set(Text& t2){
            t2._text = 10;
        }
};

int main(){
    Text t1, t2;
    
    cout << t2.Get() << endl;
    
    t1.Set(t2);
        
    cout << t2.Get() << endl;

    return 0;
}
