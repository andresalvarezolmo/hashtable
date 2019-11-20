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
// int everything(string filename, string n){
// int everything(string filename, string n, string k){

int ngram(string filename, string n, string k, string keyword){

// string filename = "a.txt";
ifstream reader( filename );

//check filename
if( ! reader ) {
    cout << "Error opening input file, please enter a valid filename with the extension .txt as first parameter" << endl;
    return 1;
}
//check string n is only full of numbers
for (int i = 0; (unsigned)i < n.length(); i++){
  if (isdigit(n[i]) == false){
    cout << "Please enter a valid number as 2nd parameter" << endl;
    return 1; 
  }  
}
//check string k is only full of numbers
for (int i = 0; (unsigned)i < k.length(); i++){
  if (isdigit(k[i]) == false){
    cout << "Please enter a valid number as 3rd parameter" << endl;
    return 1; 
  }  
}

string line;
char letter;

stringstream middle1(n);
int length = 0;
middle1>>length;
stringstream middle2(k); 
int ngrams = 0;
middle2>>ngrams;

while(reader.get(letter)) {
  line += letter;
}

//   cout << line[i] << line [i+1] << line[i+2] << endl;
//   int val = line[i] + line [i+1] + line[i+2];
//   cout << val << endl;
int filled = 0;

if (keyword == "word")
{
  //  // Used to split string around spaces. 
  //   istringstream ss(line); 
  
  //   // Traverse through all words 
  //   do { 
  //       // Read a word 
  //       string word; 
  //       ss >> word; 
  
  //       // Print the read word 
  //       T1.insert(word, 1);
  //       filled++;
  
  //       // While there is more to read 
  //   } while (ss); 
// }     
  string w = "";
  int counter = 0;
  for (int i = 0; (unsigned)i < line.size(); i++) 
  { 
      // cout << "i value: " << i<< endl;
    if (line[i] == ' ' || line[i] == '\n') 
    { 
      counter++;

      if (counter == length)
      {
        T1.insert(w, 1);
        filled++;
        w = "";
        counter = 0;
      }
      
    } 
    else
    { 
      w = w + line[i]; 
    } 
  }  
  // T1.insert(w, 1);
  // filled++;
} 
    
else if (keyword == "char" || keyword == "decimal")
{
  for (int i = 0; (unsigned)i < line.size()-(length-1); i++)
  {
    string inside = line.substr(i, length);
    T1.insert(line.substr(i,length), 1);
    filled++;
  }
}
else
{
  cout << "Please enter a valid option for the 4th parameter" <<endl;
  return 1;
}

//ESTE ES EL GENERICO, ARRIBA ESTAN LOS ESPECIALIZADOS PARA EL KEYWORD
// for (int i = 0; (unsigned)i < line.size()-(length-1); i++)
// {
//   //   int val = 0;
//   //   val = line[i] + line [i+1] + line[i+2];
//   //   cout << "i: " << i << " "<< line [i] << endl;
//     string inside = line.substr(i, length);
//   //   cout << inside << "," << endl;
//   //   cout << "i: " << i << " i+1: "<< i+1 << " i+2: " << i+2 <<endl;
//   //   cout << line.substr(i,i+2) << ","<< endl;
//     T1.insert(line.substr(i,length), 1);
//     filled++;
// }

//   T1.printTable();
  
//fill an array with the values of the  hashmap's nodes
  vector<int> values(T1.size());
  int si = sizeof(values)/sizeof(values[0]); 
  for (int d = 0; d < T1.size(); d++)
  {
      // cout << T1.getTable()[d].getValue() << endl;        
      values[d] = T1.getTable()[d].getValue();
  }
  sort(values.begin(), values.end(),greater<int>());

// for (int i = 0; i < si; ++i) 
//     cout << values[i] << endl;

// T1.printTable();

//PRINTING THE DETAILS
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

          if(times >= ngrams)
            break;
        }
      while (values[v]==values[v+1])
      v++;       
    }
  if(times >= ngrams)
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
  cout << "ARGC"<< argc << endl;
  if (argc == 5)
  {
    ngram(argv[1], argv[2], argv[3], argv[4]);
    return 0;
  }
  else
  {
    cout << "Please enter 4 parameters: a path to a file.txt, int, int, 'word or 'decimal' or 'char'" << endl;
    return 1;
  }
  
  // everything(argv[1]);
  // everything(argv[1], argv[2]);
  // everything(argv[1], argv[2], argv[3]);
    
}