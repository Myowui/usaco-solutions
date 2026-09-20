#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen ("cbarn.in", "r", stdin);
    freopen ("cbarn.out", "w", stdout);

    int n;
    cin >> n;
    vector <int> cows(n);
    for (int &t :cows) cin>> t;

    int best = 1e9;
    for (int e =0; e<n; e++){
        int total = 0;
        for (int k=0; k<n; k++){

           int room = (e+k)%n;
           total += k* cows[room];

        }
     best = min(best, total);

    }
    cout << best << endl;

}
