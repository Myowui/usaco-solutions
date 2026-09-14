#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    freopen ("traffic.in", "r", stdin);
    freopen ("traffic.out", "w", stdout);
    
    int N;
    cin >> N;

    vector <string> type(N+1);
    vector <int> s_min(N+1);
    vector <int> s_max(N+1);

    for (int i =1; i<= N; i++){
        cin >> type[i] >> s_min[i] >> s_max[i];
    }

    vector<int> f_min(N + 1, 0);
    vector<int> f_max(N + 1, 10000000);


    for (int i=1; i<=N; i++){
        if (type[i] == "none"){
            f_min[i] = max(f_min[i-1], s_min[i]);
            f_max[i] = min(f_max[i-1], s_max[i]); 
        }
        else if (type[i] == "on"){
            f_min[i] = f_min[i-1] +s_min[i];
            f_max[i] = f_max[i-1] + s_max[i];
        }
        else if (type[i] == "off"){
            f_min[i] = f_min[i-1] - s_max[i];
            f_max[i] = f_max[i-1] - s_min[i];
        }

    }
    for (int i = N; i >= 1; i--) {
        int prev_min, prev_max;
        
        
        if (type[i] == "none") {
            prev_min = f_min[i];
            prev_max = f_max[i];
        } else if (type[i] == "on") {
            
            prev_min = f_min[i] - s_max[i];
            prev_max = f_max[i] - s_min[i];
        } else if (type[i] == "off") {
            
            prev_min = f_min[i] + s_min[i];
            prev_max = f_max[i] + s_max[i];
        }

        f_min[i-1] = max(f_min[i-1], prev_min);
        f_max[i-1] = min(f_max[i-1], prev_max);
            }

   
    cout << f_min[0] << " " << f_max[0] << "\n";
    cout << f_min[N] << " " << f_max[N] << "\n";

    return 0;
}
