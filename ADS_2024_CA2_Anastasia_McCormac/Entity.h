#pragma once
#include <ostream>

template <class K, class V> 
class Entity {
	K key;
	V *value;

public:
	Entity<K, V>();
	Entity<K, V>(K key, V value);
	~Entity();
	V &GetValue();
	friend ostream &operator<< (ostream &out, const Entity<K, V> &ent);

};

// Default Construtor.
template<class K, class V>
Entity<K, V>::Entity() {

}

// Constructor 
template<class K, class V>
Entity<K, V>::Entity(K key, V value) {

	// Check if the key is valid.
	if (key == null || value == null) {

		throw new logic_error("invalid key");
	}

	// if key and value are valid create ,
	this -> key = key;
	this -> value = new V(value);
}

// Destructor should delete anything in dynamic memory.
template<class K, class V>
Entity<K, V>::~Entity() {

	delete value;
}

template<class K, class V>
V &Entity<K, V>::GetValue() {
	
	return value;
}

template<class K, class V>
ostream &operator<<(ostream& out, const Entity<K, V>& ent) {

	return out << "Key: " << key << " Value: " << value;
}
