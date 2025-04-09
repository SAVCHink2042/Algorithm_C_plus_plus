#include <iostream>  

#include <vector> 
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
    int N, number;
    char symbol;
    cin >> N;
    vector< int > answer( N, -1);
    stack< int > A, B, r_a, r_b;
    unordered_map< int, char> languge_employees;
    for( int i = 1 ; i <= N; ++i) {
        cin>> symbol;
        languge_employees[i] = symbol;
    }
    
    cin>> number;
    
    A.push(number);
    B.push(number);
    r_a.push(number);
    r_b.push(number);
    
    for ( int i = 0 ; i < 2*N; i++) {
        cin>> number;
        if( A.top() == number) {
            A.pop();
      
            r_a.pop();
            r_b.pop();
            answer[number - 1 ] = r_a.top();
        }
        else if (B.top() == number ){

            B.pop();
            r_a.pop();
            r_b.pop();
            answer[number - 1 ] = r_b.top();
        }
        else if(languge_employees[number] == 'A') {
            r_a.push(0);
            r_b.push( r_b.top()+1 );
            A.push(number);
        } 
        else {
            r_b.push(0);
            r_a.push( r_a.top()+1 );
            B.push(number);
        }
    }
    
    cin>> number;
    
    
   for( int i =0 ; i < N;++ i) {
        cout << answer[i]<< " ";
    }
   return 0;
}
