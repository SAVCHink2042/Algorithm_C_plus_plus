/*3 - закончить программу. 1 - обновить элемент куба, 2 - запрос на параллелепипеде*/

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


void update(vector< vector< vector< lli>>>& vec, vector< vector< vector< lli>>>& protocol, lli n, lli x, lli y, lli z, lli new_number ) {
    lli old_number = protocol[x][y][z];
    for( int i = x; i < n ; i = i|( i+1 ) ) {
        for( int j = y; j < n ; j= j|( j+1 ) ) {
            for( int h = z; h < n ; h = h|( h+1 ) ) {
                vec[i][j][h] = vec[i][j][h]  + new_number;
            }
        }
    }
    protocol[x][y][z] += new_number;
}

lli sum(vector< vector< vector< lli > > >& vec, lli x, lli y, lli z ) {

    lli ans = 0;
		for (int i = x; i > -1; i = (i & (i + 1)) - 1) {
				for (int j = y; j > -1; j = (j & (j + 1)) - 1) {
						for (int h = z; h > -1; h = (h & (h + 1)) - 1) {
				  	    ans += vec[i][j][h];
				    }
		    }
    }
    return ans;
}

void SAVCH_inc() {
    lli  n;
    string s;
    cin >> n;
    vector< vector< vector< lli > > > vec      ( n, vector< vector< lli > > (n, vector< lli > ( n, 0 ) ) ) ;
    vector< vector< vector< lli > > > protocol ( n, vector< vector< lli > > (n, vector< lli > ( n, 0 ) ) ) ;
    
    while( true ) {
        cin >> s ;

        if( s == "3" ) {
        		break;
        }
        else if( s == "1" ) {
        		lli x, y, z, new_number ;
        		cin >> x >> y >> z >> new_number;
            update(vec, protocol, n, x, y, z, new_number);
        }
        else if( s == "2" ) {
            lli x1, x2, y1, y2, z1, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 ;
    cout<< sum(vec, x2, y2, z2 ) - sum(vec, x1-1, y2, z2 ) - sum(vec, x2, y1-1, z2 ) -sum(vec, x2, y2, z1-1 ) + sum(vec, x1-1, y1-1, z2 ) + sum(vec, x1-1, y2, z1-1 ) + sum(vec, x2, y1-1, z1-1 ) - sum(vec, x1-1, y1-1, z1-1 )<<endl; 
        }
        
    }
}

int main() {
   SAVCH_inc();
}




