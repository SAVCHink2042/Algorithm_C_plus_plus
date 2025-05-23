#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std;

int dunc (string a, string b ) {             // b -префикс
   
    for( int i = 0 ; i < min( a.length(), b.length() ); i++ ) {
        if(a[i] > b[i] ) {              // b -лексикографически меньше
            return -1;
        }
        if(a[i] < b[i] ) {
            return 1;
        }
    }
    if( a.length() == b.length() ) 
        return 0;
    else if ( a.length() > b.length() ) 
        return -1 ;    
    else 
        return 1;
}

bool func( string a, string b) {
    if(a.length() < b.length() )
        return false;
    else {
        for( int i = 0 ; i <b.length(); i++) {
            if(a[i] != b[i] ) 
                return false;
        }
    }
    return true;
}

int main ( void ) {
    int N, Q, digit, count = 0;
    string b;
    cin>> N >> Q;
    vector< string > arr( N);
    for(int i = 0 ; i < N; i++) {
        cin>> arr[i];
    }
    for( int i = 0 ; i < Q ; i++) {
        int midle, l = 0, r = N - 1;
        cin >> digit;
        cin >> b;
        while(l <= r ) {
            midle = (l+r )/2; 
            if( dunc(arr[midle], b) ==0 ) 
                break;
            else if( dunc( arr[midle], b ) == -1  ) {
                r=midle -1;
            }
            else {
                l=midle+1;
            }
        }
        if( func(arr[midle], b) ==false  ) {
            if( func( arr[ min(N-1, midle+1) ], b) ) {
                midle++;
            }
            else if( func( arr[ max(0, midle-1) ], b) ) {
                midle--;
            }
        }
        if( func( arr[midle], b ) ) {
            if( midle + digit -1 < N  ) {
                if ( ( func( arr[midle+digit-1], b) ) ) 
                    cout <<  midle+digit<<endl;
                else 
                    cout<< -1 << endl;
            }
            else 
                cout<< -1 << endl;
        }
        else 
            cout<< -1 << endl;
    }
    
    return 0;
}
