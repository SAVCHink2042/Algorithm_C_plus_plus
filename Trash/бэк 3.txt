#include<iostream>
#include<vector>
#include <climits>
#include <unordered_set>
#include<unordered_map>
using namespace std;

void input_matr( int N, int M, vector< vector < int >> & table_numbers ) {
    for( int i = 0; i < N; ++ i) { 
        for ( int j = 0 ; j < M; ++ j) 
            cin >> table_numbers[i][j];
    }
}

void request_processing (int N, int M, int Q, vector< vector < int >> & table_numbers, unordered_map < string, int> A ) {
    int column, value;
    char symbol;
    long long int answer = 0;
    string name_column;
    unordered_map < int, pair < int, int > > change_matrix;
    unordered_set< int> suk;
    for ( int z = 0 ; z < Q; ++ z) {
        cin >> name_column >> symbol >> value;
        int col = A[ name_column];
        if( change_matrix.count(col) == 0 ) {
            if( symbol == '<' ) {
                pair < int , int > para_intov;
                para_intov.second = value;
                para_intov.first = INT_MIN;
                change_matrix[col]= para_intov;
            }
            else {
                pair < int , int > para_intov;
                para_intov.second = INT_MAX;
                para_intov.first = value;
                change_matrix[col]= para_intov;
            }
        }
        else {
            if( symbol == '<') {
                pair < int, int >  para_intov = change_matrix[col];
                para_intov.second = min(para_intov.second, value );
                change_matrix[ col ] = para_intov;
            }
            else {
                pair < int, int >  para_intov = change_matrix[col];
                para_intov.first = max(para_intov.first, value );
                change_matrix[ col ] = para_intov;
            }
        }
    }
    for ( int i =0 ; i < N; ++i ) {
        for ( auto p : change_matrix) { 
            int value_1 = p.second.first, value_2 = p.second.second;
            if( table_numbers[i][p.first] <= value_1    or table_numbers[i][p.first] >= value_2) 
                suk.insert(i);
        }
    }
    for ( int i = 0; i < N; i++) {
        if (suk.count( i ) == 0) {
            for( int j = 0; j < M; j++) 
                answer += table_numbers[i][j];
        }
    }
    cout<< answer;
}

int main() {
    int N, M, Q;
    string name_column;
    cin >> N >> M >> Q;
    vector< vector < int >> table_numbers (N, vector<int>( M ) );
    unordered_map < string, int > A;

    for ( int i = 0; i < M; ++i ) {
        cin >> name_column;
        A[name_column] = i;
    }

    input_matr( N, M, table_numbers );

    request_processing (N, M, Q, table_numbers, A);

    return 0;
}
