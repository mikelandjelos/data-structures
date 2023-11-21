#pragma once

#include <iostream>
#include <iomanip>

template <class T>
class Node {
public: // atributi
	T* m_info;
	Node<T>* m_next;
public: // metodi
	// konstruktori sa parametrom klasnog tipa
	Node(T* = nullptr, Node<T>* = nullptr);
	Node(T, Node<T>* = nullptr);
	// destruktor
	virtual ~Node();
	// print za primitivne tipove
	std::ostream& printPrimitive(std::ostream&);
	// print za referentne (korisnicke/klasne) tipove
	std::ostream& print(std::ostream&);
	// relacioni operatori
	template <class T>
	friend bool operator==(const Node<T>&, const Node<T>&);
	template <class T>
	friend bool operator<(const Node<T>&, const Node<T>&);
	template <class T>
	friend bool operator>(const Node<T>&, const Node<T>&);
};

template <class T>
Node<T>::Node(T* info, Node<T>* next) 
	: m_info(info), m_next(next) {}

template <class T>
Node<T>::Node(T info, Node<T>* next) 
	: m_info(new T(info)), m_next(next) {}

template <class T>
Node<T>::~Node() {
	if (m_info != nullptr)
		delete m_info, m_info = nullptr;
	m_next = nullptr;
}

template <class T>
std::ostream& Node<T>::print(std::ostream& izlTok) {
	return izlTok << *m_info;
}

template <class T>
bool operator==(const Node<T>& levi, const Node<T>& desni) {
	return *(levi->m_info) == *(desni->m_info);
}

template <class T>
bool operator>(const Node<T>& levi, const Node<T>& desni) {
	return *(levi->m_info) > *(desni->m_info);
}

template <class T>
bool operator<(const Node<T>& levi, const Node<T>& desni) {
	return *(levi->m_info) < *(desni->m_info);
}