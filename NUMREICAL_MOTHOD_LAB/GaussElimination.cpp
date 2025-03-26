#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<double>>&matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void gaussElimination(vector<vector<double>>&matrix , vector<double>&result , int n){
    for(int k = 0; k < n; k++){
        for(int i = k + 1; i < n; i++){
            double factor = matrix[i][k] / matrix[k][k];
            for(int j = k; j < n; j++){
                matrix[i][j] -= factor * matrix[k][j];
            }
            result[i] -= factor * result[k];
        }
    }
// ..
    vector<double> solution(n);

    for(int i = n - 1; i >= 0; i--){
        solution[i] = result[i];
        for(int j = i + 1; j < n; j++){
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i]; 
    }

    for(int i = 0; i < n; i++){
        cout << solution[i] << ' ';
    }

}

int main(){     
    int n;
    cin >> n;
    vector<vector<double>>matrix(n , vector<double>(n));
    vector<double>result(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
        cin >> result[i];
    }
    gaussElimination(matrix , result , n);
    //print(matrix);
}
