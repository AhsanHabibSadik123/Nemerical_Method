#include<bits/stdc++.h>
using namespace std;

double functionValue(double x , double y){
    return y * y - x * x;
}

void eulerMethod(double x0 , double y0 , double target , double h){
    int n = (target - x0) / h;
    for(int i = 0; i <= n; i++){
        y0 += h * functionValue(x0 , y0);
        x0 += h;
        cout << x0 << "   " << y0 << endl;
    }
}

int main(){     
    double x0 , y0;
    cout << "Initial value " << endl;
    cin >> x0 >> y0;
    double target;

    cout << "Target value " << endl;
    cin >> target;
    cout << "Step size " << endl;
    double h;
    cin >> h;
    eulerMethod(x0 , y0 , target , h);
}
