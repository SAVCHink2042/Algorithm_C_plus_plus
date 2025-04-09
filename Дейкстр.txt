#include<bits/stdc++.h>

using namespace std;

int arg_min (unordered_set<int> S, vector< int > T) {
    int value = INT_MAX/3, arg = -1;
    for( int i = 0 ; i < T.size(); i ++) {
        if( S.find(i) == S.end()  and T[i] < value) {
            value = T[i];
            arg = i;
        }
    }
    return arg;
} 


int main() {
    int n, s, f;
    cin >> n >> s-- >> f--;

    unordered_set< int > S = {s};
    vector< int> T(n, INT_MAX/3);
    T[s]=0;
    vector< vector < int > > vec(n, vector< int > (n));
    for( int i = 0 ; i < n  ; i++) {
        for( int j = 0 ; j < n ; j++) {
            cin >> vec[i][j];
        if(vec[i][j] == -1)
        	vec[i][j] = INT_MAX/3;
        }
    }
    
    while(s != -1) {
        for( int i = 0 ; i < n ; i++) {
            if(S.find(i) == S.end()  ) {
                int buf = vec[s][i]+ T[s];
                if(buf < T[i] ) {
                    T[i]= buf;
                }
            }
        }
        s = arg_min(S, T);
        S.insert(s);
    }
    cout<< ( (T[f] == INT_MAX/3 ) ? -1 : T[f] );  
}
