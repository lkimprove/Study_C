class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        //进位
        int next = (A & B) << 1;
        //本位
        int curr = A ^ B;
        
        while(next){
            int temp = (next & curr) << 1;
            curr = next ^ curr;
            next = temp;
        }
        
        return curr;
    }
};

