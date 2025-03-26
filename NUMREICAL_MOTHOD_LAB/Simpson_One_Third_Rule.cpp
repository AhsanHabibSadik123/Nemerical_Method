#include<bits/stdc++.h>
using namespace std;

double functionValue(double x){
    return 1 / (1 + x * x);
}

double simpsonOneThird(double a , double b , int n){
    double h = (b - a) / n;

    double sum = functionValue(a) + functionValue(b);

    for(int i = 1; i < n; i++){
        if(i & 1){
            sum += 4 * functionValue(a + i * h);
        }else{
            sum += 2 * functionValue(a + i * h);
        }
    }
    return (h / 3) * sum;
}

int main(){     
    double a , b;
    int n;
    cout << "Lower limit " << endl;
    cin >> a;
    cout << "Upper limit " << endl;
    cin >> b;
    cout << "Number of step " << endl;
    cin >> n;

    cout << "Approximate value is " << simpsonOneThird(a , b , n) << endl;
}
