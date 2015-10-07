class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rect1 = abs((A-C) * (B-D));
        int rect2 = abs((E-G) * (F-H));
        int rect3 = 0;
        if (C <= E || G <= A || D <= F || H <= B) {
        }
        else {
            vector<int> x;
            x.push_back(A);
            x.push_back(C);
            x.push_back(E);
            x.push_back(G);
            sort(x.begin(), x.end());
            vector<int> y;
            y.push_back(B);
            y.push_back(D);
            y.push_back(F);
            y.push_back(H);
            sort(y.begin(), y.end());
            rect3 = (x[2]-x[1])*(y[2]-y[1]);
        }
        return rect1 + rect2 - rect3;
            
        
    }
};

