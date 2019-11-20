#include "HashNode.h"
#include <vector>
#include <typeinfo>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string.h> 
// #include <algorithm>
#include <bits/stdc++.h> 

#include "HashTable.h"

using namespace std;

typedef HashTable<string,int> HTSI;
typedef HashNode<string,int> HNSI;

typedef HashTable<int,int> HTII;

typedef HashTable<string,string> HTSS;
typedef HashNode<string,string> HNSS;
HNSI N;
HTSI T1(117);

float redondeo(float var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
} 

// int everything(){
// int everything(string filename){
int everything(string filename, string n){
// int everything(string filename, string n, string k, string keyword){

// string filename = "a.txt";
ifstream reader( filename );

if( ! reader ) {
    cout << "Error opening input file" << endl;
    return 1;
}
string line;
int ngrams = 0;
int i = 0;
char letter;

stringstream middle1(n);
int length = 0;
middle1>>length;
// stringstream middle2(k); 

while(reader.get(letter)) {
  line += letter;

}
//   cout << line[i] << line [i+1] << line[i+2] << endl;
//   int val = line[i] + line [i+1] + line[i+2];
//   cout << val << endl;
int filled = 0;  
for (int i = 0; i < line.size()-(length-1); i++)
{
  //   int val = 0;
  //   val = line[i] + line [i+1] + line[i+2];
  //   cout << "i: " << i << " "<< line [i] << endl;
    string inside = line.substr(i, length);
  //   cout << inside << "," << endl;
  //   cout << "i: " << i << " i+1: "<< i+1 << " i+2: " << i+2 <<endl;
  //   cout << line.substr(i,i+2) << ","<< endl;
    T1.insert(line.substr(i,length), 1);
    filled++;
}
//   T1.printTable();
  
//fill an array with the values of the  hashmap's nodes
  int values[T1.size()];
  int si = sizeof(values)/sizeof(values[0]); 
  for (int d = 0; d < T1.size(); d++)
  {
      // cout << T1.getTable()[d].getValue() << endl;        
      values [d] =  T1.getTable()[d].getValue();
  }
  sort(values, values+si,greater<int>()); 

// for (int i = 0; i < n; ++i) 
//     cout << values[i] << endl;

// T1.printTable();

int times = 0;
for (int v = 0; v < si; v++)
{
    for (int q = 0; q < T1.size(); q++)
    {
        if (values [v] == T1.getTable()[q].getValue())
        {
          float percentage = 0;
          percentage = 100;
          percentage = percentage * (values[v])/(filled);
          float final = percentage;
          cout << redondeo(final) << ":" << T1.getTable()[q].getKey() << endl;
          // cout << "values: "<< values[v] << endl;
          // cout << "size: "<< T1.getNum()<< endl;

          // cout << "TOP "<< v + 1 <<endl;
          // cout << "Key: " <<T1.getTable()[q].getKey()<< ",with value: " << T1.getTable()[q].getValue()<<endl;
          times++;

          if(times >= 10)
            break;
        }
      while (values[v]==values[v+1])
      v++;       
    }
  if(times >= 10)
    break;   
}
  // cout << "valor de filled: "<< filled << endl;

    // cout << "Value of the vector at 0: "<< values [0] << endl
    // cout << "Value of the key with value 0: "<< T1.getTable()[q].getKey() << endl

    
    // for (int q = 0; q < T1.size(); q++){

    //   cout << "Value " << q << " : " <<T1.getTable()[q].getValue() << endl;     
    // }
      
    reader.close();
    return 0;
}

// int main(){
int main(int argc,char* argv[]){

  // everything(argv[1]);
  everything(argv[1], argv[2]);
  // everything(argv[1], argv[2], argv[3]);
    
}