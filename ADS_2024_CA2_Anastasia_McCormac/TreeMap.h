// Author: Anastasia McCormac - GD3a
// Created on: 18/11/2024

#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <class K, class V> 
class TreeMap {

	BinaryTree<Entity<K, V>> treeMap;

public:

	// Constructors
	TreeMap<K, V>();
	TreeMap<K, V>(K key, V Value);
	~TreeMap();

	void Clear(); // Removes all Entries from the Map.
	bool ContainsKey(K key); // Returns true if thie map contains a mapping for athe specified key.
	V &Get(K key); // Returns the value to which the specified key is mapped, or nullptr if thie map contains mo mapping for the key.
	//BinaryTree<K> KeySet(); // Returns a set view of the keys contained in this Map.
	void Put(K key, V& value); //Associates the specified value with the specified key in this map.
	int Size();	// Returns the number of key - value mappings in this map.
	bool RemoveKey(K key); // Removes the item denoted by the given key.
	V &operator[] (K key); // Returns the value to which the specified key is mapped, or nullptr if this map contains no mapping for the key.
	void PrintInOrder();
};

template <class K, class V>
TreeMap<K, V>::TreeMap() {

	treeMap = BinaryTree<Entity<K, V>>();
}

template <class K, class V>
TreeMap<K, V>::TreeMap(K key,V value) {

	treeMap = BinaryTree<Entity<K, V>>();
	Entity<K, V> newEnt {};
	newEnt.key = key;
	newEnt.value = value;
	treeMap.add(newEnt);
}

template<class K, class V>
TreeMap<K, V>::~TreeMap() {

	treeMap.clear();
}

// Removes all Entries from the Map.
template<class K, class V>
void TreeMap<K, V>::Clear() {

	treeMap.clear();
}

// Returns true if thie map contains a mapping for the specified key.
template<class K, class V>
bool TreeMap<K, V>::ContainsKey(K key) {

	Entity<K, V> byKey {key, V {}};

	//Try get the key, return true if it's found (ie. not nullptr).
	try {

		treeMap.get(byKey);
		return true;
	}

	catch (...) {

		// otherwise it's not found.
		return false;
	}
}

// Returns the value to which the specified key is mapped, or nullptr if thie map contains mo mapping for the key.
template<class K, class V>
V &TreeMap<K, V>::Get(K key) {

	Entity<K, V> byKey {key, V {}};
	
	try { 

		return  treeMap.get(byKey).value;
	}

	catch (...) {

		throw std::logic_error("Item not found");
	}
}

// TODO: Need to Fix this.
// Returns a set view of the keys contained in this Map
//template<class K, class V>
//BinaryTree<K> TreeMap<K, V>::KeySet() {
//
//	BinaryTree<K> keySet {};
//	
//	K *asArray[] = treeMap.toArray();
//
//	for (V e : asArray) {
//
//		keySet.add(e.key);
//	}
//
//	//delete[] asArray;
//
//	return keySet;
//}

//Associates the specified value with the specified key in this map.
template<class K, class V>
void TreeMap<K, V>::Put(K key, V& value) {

	Entity<K, V> newItem;
	newItem.key = key;
	newItem.value = value;

	treeMap.add(newItem);
}

// Returns the number of key - value mappings in this map.
template<class K, class V>
int TreeMap<K, V>::Size() {

	return treeMap.count();
}

// Removes the item denoted by the given key.
template<class K, class V>
bool TreeMap<K, V>::RemoveKey(K key) {

	if (this->ContainsKey(key)) {

		Entity<K, V> toRemove {key, V {}};

		treeMap.remove(toRemove);
		return true;
	}

	return false;
}

template<class K, class V>
V &TreeMap<K, V>::operator[](K key) {
	
	return Get(key);
}

template<class K, class V>
void TreeMap<K, V>::PrintInOrder() {

	treeMap.printInOrder();
}