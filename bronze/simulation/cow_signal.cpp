#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen ("cowsignal.in", "r", stdin);
    freopen ("cowsignal.out", "w", stdout);
    int m, n, k ;
    cin >> m>> n >> k;
    char a[10][10];
    for (int i =0; i<m; ++i){
        for (int j =0; j<n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i =0; i<m; ++i){
        for (int l=0; l<k; ++l){
            for (int j =0; j<n; ++j){
                for (int o =0; o<k; ++o){
                    cout <<a[i][j];
                }
            }
            cout << "\n";
        }
    }

}