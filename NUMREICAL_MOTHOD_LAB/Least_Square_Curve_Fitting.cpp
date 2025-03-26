#include<bits/stdc++.h>
using namespace std;

double sum(vector<double> &x){
    double s = 0;
    for(int i = 0; i < x.size(); i++){
        s += x[i];
    }
    return s;
}
double sum2(vector<double> &x){
    double s = 0;
    for(int i = 0; i < x.size(); i++){
        s += (x[i] * x[i]);
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<double>x(n) , y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    double sx = sum(x);
    double sy = sum(y);
    double sxsy = 0;
    for(int i = 0; i < n; i++){
        sxsy += (x[i] * y[i]);
    }
    double sx2 = sum2(x);

    double m = ((n * sxsy) - sx * sy) / ((n * sx2) - sx * sx);

    double c = (sy / n) - m * (sx / n);

    cout << "y = " << m << "x " << "+ " << c << endl;

}
