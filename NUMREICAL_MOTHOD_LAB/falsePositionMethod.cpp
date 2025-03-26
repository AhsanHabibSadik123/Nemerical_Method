#include<bits/stdc++.h>
using namespace std;
#define sadik() ios::sync_with_stdio(false);cin.tie(0)
#define nl '\n'

class falsePositionMethod{
private:
    double a , b , c , maxIteation , tolarance;
public:
    falsePositionMethod(double tol , double mxIter){
        tolarance = tol;
        maxIteation = mxIter;
        generateRandom();
    }

    double func(double x){
        return x * x * x - x * x + 2;
    }

    void generateRandom(){
        do{
            a = ((rand() % 200) - 100) / 10.0;
            b = ((rand() % 200) - 100) / 10.0;
        } while (func(a) * func(b) > 0);
    }
    double findRoot(){
        c = a;
        int i = 1;
        while(fabs(a - b) >= tolarance && i < maxIteation){
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));
            if(func(c) == 0){
                return c;
            }else if(func(a) * func(c) < 0){
                b = c;
            }else{
                a = c;
            }
            cout << "No of Iteration " << i << " = " << c << nl;
            i++;
        }
        return c;
    }
};


int main(){     
    sadik();
    double tolarance = 1e-6 , maxIteration = 100;
    falsePositionMethod falsePosition(tolarance , maxIteration);
    cout << "Root is = " << falsePosition.findRoot() << nl;
    return 0;
}
