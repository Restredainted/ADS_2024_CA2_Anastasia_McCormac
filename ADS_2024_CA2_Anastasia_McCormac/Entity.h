// Author: Anastasia McCormac - GD3a
// Created on: 

#pragma once
#include <iostream>

template <class K, class V> 
struct Entity {

	K key;
	V value;

	template<class K, class V>
	bool operator < (Entity<K, V> &right) {

		return key < right.key;
	};

	template<class K, class V>
	bool operator > (Entity<K, V> &right) {

		return key > right.key;
	};

	template<class K, class V>
	bool operator== (Entity<K, V> &other) {

		return key == other.key;
	};
};

template<class K, class V>
std::ostream &operator<<(std::ostream &out,  Entity<K, V> &ent) {

	out << "Key: " << ent.key 
		<< "\nValue: \n" << ent.value;

	return out;
};