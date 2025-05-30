/* Дан неориентированный граф. Над ним в заданном порядке производят операции следующих двух типов:

cut — разрезать граф, то есть удалить из него ребро;
ask — проверить, лежат ли две вершины графа в одной компоненте связности.
Известно, что после выполнения всех операций типа cut рёбер в графе не осталось. Найдите результат выполнения каждой из операций типа ask. */

#include<bits/stdc++.h>

using namespace std;

#define scl static_cast<long long int>
#define sci static_cast<int>
#define scd static_cast<long double>
#define gcd __gcd
#define vlli vector<vector<lli>> 
#define vi vector<vector<int>> 

using lli =  long long;
using ld  =  long double;
using ull =  unsigned long long;

struct Data{
    bool flag;
    int l, r;
};

void un (int l , int r, vector< int >& vec, vector< vector< int >>& matrix  ) {  // l сливаем с r короче.
    if(vec[l] != vec[r] ) {
      for( auto el: matrix[vec[l]] ) {
          vec[el] = vec[r];
          matrix[vec[r]].push_back( el );
      }
    }
}

int main () {
    int n , m , k, num_1, num_2;
    string s;
    stack< Data > st;
    cin >> n >> m >> k;
    stack< bool >  ans;
    for( int i = 0 ; i < m; i++ ) {
        cin >> num_1 >> num_2;
    }
    vector< vector< int > > matrix (n+1);
    vector< int > vec(n+1);
    for( int i = 1 ; i <= n ; i++) {
        matrix[i].push_back(i);
        vec[i] = i;
    }
    
    for( int i = 0 ; i < k ; i++  ) {
        cin >> s >> num_1 >> num_2;
        if( s == "cut" ) {      
            st.push( {false, num_1, num_2} ); 
        }
        else {                   
            st.push( {true, num_1, num_2} );
        }
    }
    while( !st.empty() ) {
        
        Data x = st.top();
        if( x.flag ) {
            ans.push( ( ( vec[x.l] == vec[x.r] ) ? 1:0 ) );
        }
        else {
            //cout<<"размерности "<< matrix[vec[x.l]].size() << " "<< matrix[vec[x.r]].size()<< endl;
            if( matrix[vec[x.l]].size() < matrix[vec[x.r] ].size() ) {
                un(x.l , x.r, vec, matrix ); 
            }
            else {
                un( x.r, x.l, vec, matrix);
            }
        }
        st.pop();
    }
    
    while(!ans.empty() ) {
        cout << (  (ans.top() ) ? "YES" : "NO" ) << endl;
        ans.pop();
    }  
}
