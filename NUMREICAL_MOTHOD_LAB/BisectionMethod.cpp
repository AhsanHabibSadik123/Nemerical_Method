#include<bits/stdc++.h>
using namespace std;
#define sadik() ios::sync_with_stdio(false);cin.tie(0)
#define nl '\n'

class BisectionMethod{
private:
    double tolarance , maxIteration , a , b , c;
public:
    
    BisectionMethod(double tol , double mxIt){
        tolarance = tol;
        maxIteration = mxIt;
        generateRandom();
    }

    double func(double x){
        return x * x * x - x * x + 2;
    }

    void generateRandom(){
        do{
            a = (rand() % 200 - 100) / 10.0;
            b = (rand() % 200 - 100) / 10.0;
            a = max(a , b);
            b = min(a , b);
        }while((func(a) * func(b)) > 0);
    }
    
    double findRoot(){
        c = a;
        int i = 1;
        while(fabs(a - b) >= tolarance && i < maxIteration){
            c = (a + b) / 2;
            if(func(c) == 0){
                return c;
            }else if(func(a) * func(c) < 0){
                b = c;
            }else{
                a = c;
            }
            cout << "Iteation no " << i << " = " << c << '\n';
            i++;
        }
        return c;
    }
};

int main(){     
    sadik();
    double tolarance = 1e-6 , mxIteration = 100;
    BisectionMethod Bisection(tolarance , mxIteration);
    cout << Bisection.findRoot();
    return 0;
}