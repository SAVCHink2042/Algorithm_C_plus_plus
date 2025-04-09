#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

void dangeon_function_1( unordered_map< int, int>& A, unordered_map< int, int>& B, int  number_card,  int & number_of_unique_cards ) {

    if( A[number_card] == 0) {
         ++ number_of_unique_cards;
         ++ B[number_card];
    }
    else {
        number_of_unique_cards -= abs ( A[number_card] - B[number_card] );
        ++ B[number_card];
        number_of_unique_cards += abs( A[number_card] - B[ number_card]);
    }
}

void dangeon_function_2( unordered_map< int, int>& A, unordered_map< int, int>& B, int  number_card,  int & number_of_unique_cards ) {
    if( A[number_card] == 0) {
         -- number_of_unique_cards;
         -- B[number_card];
    }
    else {
         number_of_unique_cards -= abs ( A[number_card] - B[number_card] );
         -- B[number_card];
         number_of_unique_cards += abs( A[number_card] - B[ number_card]);
    }
}

int main() {
    unordered_map <int, int>  A, B;
    int number_of_unique_cards = 0;
    int N, M, Q;
    int number_card, flag;
    char igrok;
    cin >> N >> M >> Q;

    for( int i = 0; i < N; ++i) {
        cin >> number_card;
        A [ number_card ]++;
        number_of_unique_cards++;
    }

    for( int i = 0; i < M; ++i) {
        
        cin >> number_card;
       
        if( A[number_card] == 0) {
            ++ number_of_unique_cards;
            ++ B[number_card];
        }
        else {
            number_of_unique_cards -= abs ( A[number_card] - B[number_card] );
            ++ B[number_card];
            number_of_unique_cards += abs( A[number_card] - B[ number_card]);
        }
    }

    for ( int i =0 ; i< Q; ++i) {
        cin >> flag >> igrok >> number_card ;
        if( flag == 1 ){
            if( igrok == 'A' )
                dangeon_function_1 ( B, A, number_card, number_of_unique_cards);
            else 
                dangeon_function_1 ( A, B, number_card, number_of_unique_cards);
        }
        else {
            if( igrok == 'A' ) 
                dangeon_function_2(B, A, number_card, number_of_unique_cards );
            
            else 
                dangeon_function_2(A, B, number_card, number_of_unique_cards );
       	}
        
        cout << number_of_unique_cards << " " ;
    }

    return 0;
}
