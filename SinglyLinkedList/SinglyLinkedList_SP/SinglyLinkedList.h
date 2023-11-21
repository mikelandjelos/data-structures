#pragma once

#include <iostream>
#include <exception>
#include "Node.h"

template <class T>
class SinglyLinkedList {
protected:
	Node<T> *m_head, *m_tail;
private:
	unsigned long m_nodeCount;
public:
	// default konstruktor
	SinglyLinkedList();
	// default destruktor
	virtual ~SinglyLinkedList();
	// metodi
	// insert algoritmi
	void addToHead(T); // O(1)
	void addToTail(T); // O(1)
	// deletion algoritmi
	T deleteFromHead(); // O(1)
	T deleteFromTail(); // O(n)
	bool deleteEl(T); // O(n)
	// search algoritmi
	Node<T>* findEl(T); // O(n)
	Node<T>* findFirstGreater(T); // O(n)
	Node<T>* findFirstLower(T); // O(n)
	bool findIfInList(T);
	// miscellaneous
	std::ostream& print(std::ostream&);
	inline unsigned long getSize() const { return m_nodeCount; }
	inline bool isEmpty() const { return m_head == nullptr; }
	inline unsigned long getSizeInBytes() const { 
		return m_nodeCount * sizeof(T); 
	}
};

// inicijalizacija prazne liste -> i rep i glava su null
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() 
	: m_head(nullptr), m_tail(nullptr),
	m_nodeCount(0) {}

// brisanje svih preostalih cvorova
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	while (!isEmpty())
		deleteFromHead();
}

// dodaje novi cvor nakon glave
template <class T>
void SinglyLinkedList<T>::addToHead(T el) {
	m_head = new Node<T>(el, m_head);
	if (m_tail == nullptr)
		m_tail = m_head;
	m_nodeCount++;
}

// dodaje novi cvor na rep liste
template <class T>
void SinglyLinkedList<T>::addToTail(T el) {
	if (isEmpty()) {
		m_head = m_tail = new Node<T>(el);
		return;
	}
	m_tail = m_tail->m_next = new Node<T>(el);
	m_nodeCount++;
}

// brise sa glave - PRIMETI da je ovo O(n) za razliku od deleteFromHead() metoda!!!
template <class T>
T SinglyLinkedList<T>::deleteFromHead() {
	if (isEmpty())
		throw new std::exception("SLL_ERR: No elements to delete!");
	Node<T>* pom = m_head;
	T pomInf = *pom->m_info;

	// objasnjenje GRANICNOG SLUCAJA
	/*
		ukoliko imamo samo jedan element i brisemo sa glave ->
		dealociramo memoriju na koju pokazuje i rep pa moramo
		i njega da postavimo na nullptr inace moze da dodje do
		nezgodnog ponasanja (bacanje nekog exceptiona)
	*/
	m_head = m_head->m_next;
	if (m_head == nullptr)
		m_tail = nullptr;
	// !objasnjenje
	m_nodeCount--;
	delete pom;
	return pomInf;
}

// brise sa repa
template <class T>
T SinglyLinkedList<T>::deleteFromTail() {
	if (isEmpty())
		throw new std::exception("SLL_ERR: No elements to delete!");
	Node<T>* pom = m_tail;
	T pomInf = *pom->m_info;
	Node<T>* tmp;
	for (tmp = m_head; 
		tmp->m_next != m_tail; 
		tmp = tmp->m_next);
	m_tail = tmp;
	m_tail->m_next = nullptr;
	if (m_tail == m_head)
		m_head = m_tail = nullptr;
	m_nodeCount--;
	delete pom;
	return pomInf;
}

// stampanje liste
template <class T>
std::ostream& SinglyLinkedList<T>::print(std::ostream& izlTok) {
	Node<T>* pok = m_head;
	izlTok << "("<< getSizeInBytes() << "B)start ->\n";
	while (pok != nullptr) {
		pok->print(izlTok) << " -> ";
		pok = pok->m_next;
	}
	return izlTok << "null";
}

// brise sa prosledjenog pointera
template <class T>
bool SinglyLinkedList<T>::deleteEl(T el) {
	if (isEmpty())
		return false;
	Node<T>* ptr = m_head;
	for (;ptr->m_next != nullptr && *ptr->m_next->m_info != el ; ptr = ptr->m_next);
	if (ptr->m_next == nullptr)
		return false;
	Node<T>* forDel = ptr->m_next;
	ptr->m_next = ptr->m_next->m_next;
	delete forDel;
	m_nodeCount--;
	return true;
}

template <class T>
Node<T>* SinglyLinkedList<T>::findEl(T el) {
	Node<T> *ptr = m_head;
	while (ptr != nullptr) {
		if (*ptr->m_info == el)
			return ptr;
		ptr = ptr->m_next;
	}
	return nullptr;
}

template <class T>
Node<T>* SinglyLinkedList<T>::findFirstGreater(T el) {
	Node<T>* ptr = m_head;
	while (ptr != nullptr) {
		if (*ptr->m_info > el)
			return ptr;
		ptr = ptr->m_next;
	}
	return nullptr;
}

template <class T>
Node<T>* SinglyLinkedList<T>::findFirstLower(T el) {
	Node<T>* ptr = m_head;
	while (ptr != nullptr) {
		if (*ptr->m_info < el)
			return ptr;
		ptr = ptr->m_next;
	}
	return nullptr;
}

template <class T>
bool SinglyLinkedList<T>::findIfInList(T el) {
	return (findEl(el) == nullptr ? false : true);
}