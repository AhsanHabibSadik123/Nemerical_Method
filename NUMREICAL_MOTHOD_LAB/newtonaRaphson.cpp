#include<bits/stdc++.h>
using namespace std;
#define sadik() ios::sync_with_stdio(false);cin.tie(0)
#define nl '\n'

class newtonaRaphson
{
private:
    double x , h , tolarance , maxIteration;
public:

    newtonaRaphson(double tol , double mxIter){
        tolarance = tol;
        maxIteration = mxIter;
    }
    double func(double x){
        return x * x * x - x * x + 2;
    }
    double deriFunc(double x){
        return 3 * x * x - 2 * x + 2;
    }
    void geneateRandom(){
        x = (rand() % 100) / 10.0;
    }
    double findRoot(){
        int i = 1;
        h = func(x) / deriFunc(x);
        while(h > tolarance && i < maxIteration){
            h = func(x) / deriFunc(x);
            x = x - h;
            cout << "No of Iteration " << i << " = " << x << nl;
            i++;
        }
        return x;
    }
};
int main(){     
    sadik();
    double tolarance = 1e-10 , maxIteration = 100;
    newtonaRaphson newtonaRaphson(tolarance , maxIteration);
    cout << "Root is = " << newtonaRaphson.findRoot() << nl;
    return 0;
}