#include "HashNode.h"
#include <vector>
#include <typeinfo>
#include <string>
#include <iostream>
#include <fstream>

#include "HashTable.h"

using namespace std;

void everything(){

    string line;
    string filename;
    int i=0;
    ifstream reader( filename );

    do {
        cout << "Please enter the file name" << endl;
        cin >> filename;
        ifstream reader( filename );

        if( ! reader ) {
            cout << "Error opening input file" << endl;
        }        
    }
    while( ! reader);

    cout << "File has been read" << endl;

    while(getline(reader, line)) {
    cout << line << endl;
    i++;
    }

    reader.close();
}

int main(){
    everything();
}