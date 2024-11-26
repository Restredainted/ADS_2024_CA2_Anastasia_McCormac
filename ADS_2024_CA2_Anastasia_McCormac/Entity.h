#pragma once
#include <iostream>

template <class K, class V> 
struct Entity {

	K key;
	V value;
	
	//typedef _KType;
	//typedef _VType;
	


public:
	//Entity<K, V>();
	//Entity<K, V>(K key, V value);
//	~Entity();
	//K &GetKey();
	//V &GetValue();
	//const typedef _KType GetKType();
	//const _VType GetVType();

	//// == operator overload required for use in binary tree.
	//template<class K, class V>
	//friend bool operator== (Entity<K, V> &left, Entity<K, V> &right);

	//// < operator overload required for use in binary tree.
	//template<class K, class V>
	//friend bool operator< (Entity<K, V> &left, Entity<K, V> &right);

	//// << operator, required to print out elements. 
	//friend ostream &operator<< (ostream &out, const Entity<K, V> &ent);

	template<class K, class V>
	bool addItem(K key, V Value) {

	};

	template<class K, class V>
	bool operator < (Entity<K, V> &right) {
		return key < right.key;
	};

	template<class K, class V>
	bool operator > (Entity<K, V> &right) {
		return key > right.key;
	};

	template<class K, class V>
	bool operator==(Entity<K, V> &other) {

		return key == other.key;
	};
};

template<class K, class V>
std::ostream &operator<<(std::ostream &out, const Entity<K, V> &ent) {

	out << "Key: " << ent.key 
		<< " Value: " << ent.value;

	return out;
};

//// Default Construtor.
//template<class K, class V>
//Entity<K, V>::Entity() {
//	key = K {};
//	value = V {};
//}
//
//// Constructor 
//template<class K, class V>
//Entity<K, V>::Entity(K key, V value) {
//
//	// Check if the key is valid.
//	//if (key == nullptr || value == nullptr) {
//
//	//	throw new logic_error("Invalid Key or Value");
//	//}
//
//	// if key and value are valid create ,
//	this -> key = key;
//	this -> value = value;
//}

//template<class K, class V>
//bool Entity<K, V>::operator== (const Entity<K, V> &other) {
//	return (key == other.getKey);
//	// return false;
//}

// Destructor should delete anything in dynamic memory.
//template<class K, class V>
//Entity<K, V>::~Entity() {
//
//	//delete value;
//}

//template<class K, class V>
//K &Entity<K, V>::GetKey() {
//	
//	return key;
//}
//
//template<class K, class V>
//V &Entity<K, V>::GetValue() {
//	
//	return value;
//}

//template<class K, class V>
//bool operator<(Entity<K, V> &left, Entity<K, V> &right) {
//	return left.GetKey() < right.GetKey();
//}
//
//template<class K, class V>
//ostream &operator<<(ostream& out, Entity<K, V>& ent) {
//
//	out << "Key: " << ent.GetKey() << " Value: " << ent.GetValue();
//	return out;
//}
//
//template<class K, class V>
//bool operator==(Entity<K,  V> &left, Entity<K, V> &other) {
//
//	return left.GetKey() == other.GetKey();
//}
