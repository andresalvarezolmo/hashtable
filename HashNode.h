#ifndef MY_HASH_NODE
#define MY_HASH_NODE

using namespace std;

template <class KeyType, class ValueType>
class HashNode {
  KeyType key;     // The hash node's key
  ValueType value; // The key's associated data
  /* extend if necessary */

public:

  HashNode();  // constructor

  KeyType getKey() { return key; }
  ValueType getValue() { return value; }
  void assign(KeyType key, ValueType value); 
  bool deleted;
  void printTable();
  // extend if necessary
};

template <class KeyType, class ValueType>
HashNode<KeyType,ValueType>::HashNode(){
  key = KeyType();
  value = ValueType();
  deleted = false;
}

template <class KeyType, class ValueType>
void HashNode<KeyType,ValueType>::assign(KeyType key, ValueType value){
  this->key = key;
  this->value = value;
}


/* 
   Implement the constructor, the assign method 
   and any methods that you may additionally need for the HashTable to work.
*/

#endif
