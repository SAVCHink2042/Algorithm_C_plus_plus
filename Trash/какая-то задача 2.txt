
#include<iostream>
#include <cstring>
using namespace std;

int main() {
    string line, buf="";
    int len, maxlen = 0 ;
    getline(cin, line);
    len  = line.length() ;
    while( 1 > 0 ) {
        if( line[len-1] == ' ' ){
            len--;
        }
        else {
            break;
        }
    }
    int flag = 0;
    for(int i = 0 ; i < len ; i++) { 
        if(flag == 1) {
            if(line[i] !=' ' )
                buf+=' ';
            flag = 0;
        }
        if(line[i] != ' ' and line[i] !=',' ) 
            buf += line[i];
        else if( line[i] == ',' and i ==  len-1 ){
            buf+=line[i];
        }
        else if(line[i] == ' ' and line[i+1] == ',' ) {
            buf+= line[i+1];
            i++;
            flag = 1;
        }
        else if(line[i] == ' ' and line[i+1] != ',' ) {
            buf+= line[i];
        }
        else if(line[i] == ',' and line[i+1] !=' ' ) {
            buf+=',';
            buf+=' ';
        }
        else if(line[i] == ',' and line[i+1] ==' ' ) {
            buf+=',';
        }
    }
    cout<< buf << endl;
    line = buf;
    const char* charPtr = line.c_str();

    char charArray[ line.length() + 1 ];
    strcpy(charArray, charPtr);
    
    int count = 0;
    
    
    for( int i  = 0 ; i < line.length() ; i++ ) {
        if(line[i] == ' ' or line[i] == ',') {
            maxlen=max(maxlen, count);
            count = 0;
        }
        else if(i == line.length() - 1 ) {
            maxlen = max(maxlen, count+1);
        }
        else {
            count++;
        }
    }
    
    maxlen *= 3 ;
    count = 0;
    
    char * token = strtok (charArray, " ");
    while( token != nullptr ) {
        if( count == 0 ) {
            cout<<token;
            count+=strlen(token);
        }
        else if(count+1+strlen(token) <= maxlen ) {
            cout<< " "<< token;
            count+=1+strlen(token);
        }
        else {
            cout<< endl << token;
            count=strlen(token);
        }
        
        token = strtok(nullptr, " ");
    } 
    return 0;
}
