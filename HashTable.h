#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>
#include <typeinfo>
#include <string>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

template <class KeyType, class ValueType>
class HashTable {
  typedef vector <HashNode<KeyType,ValueType> > Table;
  Table *table; // size of table (# of buckets) is stored in the Table data structure
  int num;   // number of entries stored in the HashTable;

public:
  HashTable();        // constructor, initializes table of size 11;
  HashTable(int);  // constructor, requires size of table as arg
  ~HashTable();       // deconstructor

  int size();      // returns size of the hash table (number of buckets)
  int hash_function(KeyType);  // the table's hash function
  ValueType getValue(KeyType);    // find and return data associated with key

  void insert(KeyType,ValueType); // insert data associated with key into table
  void erase(KeyType);            // remove key and associated data from table

  void rehash(int); // sets a new size for the hash table, rehashes the hash table 
  // extend if necessary
  Table getTable(){return *table;}
  int getNum(){return num;}
  void printTable();
};

template <class KeyType, class ValueType>
int HashTable<KeyType,ValueType>::size() {
  return table->size();
}

template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable(){
  Table f1;
  HashNode <KeyType,ValueType> node;
  f1.assign(11,node);
  table = new Table;
  *table = f1;
}

template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable(int input){
  Table f2;
  HashNode <KeyType,ValueType> node;
  f2.assign(input,node);
  table = new Table;
  *table = f2;
}

template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::~HashTable(){
  table->clear();
  table = NULL;
}

template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::insert(KeyType k,ValueType v){
  int val = hash_function(k);
  int buck = 0;
  int s = size();
  HashNode <KeyType,ValueType> nodo;
  while((*table)[val].getValue() != ValueType() && (*table)[val].getKey() != KeyType()){
    val++;
    buck++;
    if (val >= size())
    {
      val = 0;
    }
    if (buck == size())
    {     
      cout << "The vector is full" <<endl;
      throw OUT_OF_MEMORY;
    }    
  }
  nodo.assign(k,v);
  (*table)[val] = nodo;
  // cout << "A new node has been added, Key: " << (*table)[val].getKey() << " , Value: " << (*table)[val].getValue() << endl;
  num++;  
  // cout << "A new node has been added, Key: " << (*table)[val].getKey() << " , Value: " << (*table)[val].getValue() << endl;
  if (num >= (s/2))
  {
    rehash((s*2));
  }
}
template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::erase(KeyType k){
  int val = hash_function(k);
  while((*table)[val].getValue() != getValue(k)){
    val++;
    if (val >= size())
    {
      val = 0;
    }
  }
  HashNode <KeyType,ValueType> del;
  del.deleted = true;
  (*table)[val] = del;
  num--;
}  

template <class KeyType, class ValueType>
ValueType HashTable<KeyType,ValueType>::getValue(KeyType k) {
  int val = hash_function(k);
  int counter = 0;
  while((*table)[val].getKey() != k){
    val++;
    if ((*table)[val].deleted == false && (*table)[val].getValue() == ValueType() && (*table)[val].getKey() == KeyType())
    {
      cout << "A value with that key: " << k <<  "does not exist" << endl;
      throw KEY_NOT_FOUND;
    }
    if (val >= size())
    {
      val = 0;
    } 
    if (counter > size())
    {
      cout << "ERROR KEY NOT FOUND" <<  endl;
      throw KEY_NOT_FOUND;
    }
  }
  return table->at(val).getValue();
}

template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::rehash(int a) {
  Table copy;
  copy = (*table);
  (*table).resize(a);
  // (*table).clear();
  for (int b = 0; b < size(); b++)
  {
    (*table)[b].assign(KeyType(), ValueType());
  }
  num = 0;
  for (int i = 0; i < copy.size(); i++)
  {
    if (copy[i].getKey() != KeyType() || copy[i].getValue() != ValueType())
    {
      insert(copy[i].getKey(), copy[i].getValue());
    }    
  }
}

// template <class KeyType, class ValueType>
// void printTable(HashTable<KeyType,ValueType> ht){
  // for (int i = 0; i < ht.size(); i++)
  // {
  //   cout << "At position: " << [i] << (*ht.table)[i].getKey() << " , Value: " << (*ht.table)[i].getValue() << endl;
  // }
  
// }
template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::printTable(){
  for (int i = 0; i < size(); i++)
  {
    cout << "At position: " << i << ": " << "Key: " << (*table)[i].getKey() << " , Value: " << (*table)[i].getValue() << endl;
  }
}
// template <class KeyType, class ValueType>
// void HashTable<KeyType,ValueType>::hash_function(KeyType) {
  
// }
template <>
int HashTable<string,int>::hash_function(string s){ 
  int val = 0;
  for (int i = 0; i < s.length(); i++)
  {
      char x = s.at(i);
      val += x;
  }
  return val % size();
}

template <>
int HashTable<string,string>::hash_function(string s){ 
  int val = 0;
  for (int i = 0; i < s.length(); i++)
  {
      char x = s.at(i);
      val += x;
  }
  return val % size();
}

template <>
int HashTable<int,int>::hash_function(int i){ 
  return i % size();
}

/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/
#endif
