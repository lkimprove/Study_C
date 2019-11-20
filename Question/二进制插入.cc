class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        
        //将m左移j位，再插入即可
        n = n | (m << j);
        return n;
    }
};
