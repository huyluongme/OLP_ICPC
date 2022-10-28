#include <bits/stdc++.h>
using namespace std;

int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main(){
    iostream::sync_with_stdio(false); cin.tie(NULL);
    int y;
    cin >> y;

    if(y == 1){
        cout << 0;
        return 0;
    }
    string res = "";
    while(y > 0){
        int i;
        for(i = 9; i >= 0; --i)
            if(f[i] <= y) break;
        res = to_string(i) + res;
        y -= f[i];
    }
    cout << res;
    return 0;
}