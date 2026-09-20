#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    freopen ("pails.in", "r", stdin);
    int buck1, buck2;
    int order;
    cin >> buck1 >> buck2 >> order;

    int closest = 0;

    for (int first = 0; first <= order; first ++){
        if (buck1*first > order){break;}
        for (int second = 0; second<= order; second ++){
            int n = (buck1 * first) + (buck2 * second);
            if (n > order) {break;}
            closest = max(n, closest);
        }
    }
    freopen ("pails.out", "w", stdout);
    cout << closest << endl;
}