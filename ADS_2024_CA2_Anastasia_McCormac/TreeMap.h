#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <class K, class V> 
class TreeMap {

	BinaryTree<Entity<K, V>*> treeMap;


public:

	// Constructors
	TreeMap<K, V>();
	//TreeMap<K, V>(K key, V Value);
	// BinaryTree<Entity<K, V>>();
	~TreeMap();

	void Clear(); // Removes all Entries from the Map.
	bool ContainsKey(K key); // Returns true if thie map contains a mapping for athe specified key.
	//V &Get(K key); // Returns the value to which the specified key is mapped, or nullptr if thie map contains mo mapping for the key.
	BinaryTree<K> KeySet(); // Returns a set view of the keys contained in this Map.
	void Put(K key, V value); //Associates the specified value with the specified key in this map.
	int Size();	// Returns the number of key - value mappings in this map.
	bool RemoveKey(K key); // Removes the item denoted by the given key.
	V &operator[] (K key); // Returns the value to which the specified key is mapped, or nullptr if this map contains no mapping for the key.

};

template <class K, class V>
TreeMap<K, V>::TreeMap() {

	treeMap = BinaryTree<Entity<K, V>*>();
}

//template <class K, class V>
//TreeMap<K, V>::TreeMap(K key,V value) {
//
//	treeMap = BinaryTree<Entity<K, V>>();
//	treeMap.add(new Entity<K, V>(key, value));
//
//}

template<class K, class V>
TreeMap<K, V>::~TreeMap() {

	treeMap.clear();
	delete this;
}

// Removes all Entries from the Map.
template<class K, class V>
void TreeMap<K, V>::Clear() {

	treeMap.clear();
}


// Returns true if thie map contains a mapping for athe specified key.
template<class K, class V>
 bool TreeMap<K, V>::ContainsKey(K key) {


	 // Validate the given key.
	 //if (key) {

		 //bool found = false;
		 //Entity<K, V> 

		 // Try get the key, return true if it's found (ie. not nullptr).
		/* if (treeMap.get(key) != nullptr) 
			 return true;*/
	 //}

	 // otherwise it's not found.
	 return false;
}

 // Returns the value to which the specified key is mapped, or nullptr if thie map contains mo mapping for the key.
//template<class K, class V>
//V &TreeMap<K, V>::Get(K key) {
//
//	//ent = treeMap.get(new Entity<K, V>(key, new typeid(treeMap).name());
//
//	//if (ent.GetKey() != nullptr) {
//
//	//	return ent.GetValue();
//	//}
//
//	return ent.GetValue();
//}

// Returns a set view of the keys contained in this Map.
template<class K, class V>
BinaryTree<K> TreeMap<K, V>::KeySet() {


	return BinaryTree<K>();
}

//Associates the specified value with the specified key in this map.
template<class K, class V>
void TreeMap<K, V>::Put(K key, V value) {

	Entity<K, V> *node = new Entity<K, V>(key, value);

	if (!(this->ContainsKey(key)))
		treeMap.add(node);
}

// Returns the number of key - value mappings in this map.
template<class K, class V>
int TreeMap<K, V>::Size() {

	return treeMap.count();
}

// Removes the item denoted by the given key.
template<class K, class V>
bool TreeMap<K, V>::RemoveKey(K key) {

	if (key != nullptr) {

		Entity<K, V> ent = nullptr;

		ent = treeMap.get(key);

		treeMap.remove(ent);

	}
	return false;
}

template<class K, class V>
V &TreeMap<K, V>::operator[](K key) {
	
	Entity<K, V> *ent = nullptr;

	if (ent = treeMap.get(key) != nullptr) {

		return ent -> GetValue();
	}
}


