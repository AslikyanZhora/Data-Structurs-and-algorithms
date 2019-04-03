#pragma once

#include "dlist.hpp"
#include <assert.h>

template <typename T>
DList<T>::DList() :m_head(nullptr), m_tail(nullptr), m_size(0)
{
}

template <typename T>
DList<T>::~DList()
{
	makeEmpty();
}

template <typename T>
bool DList<T>::isEmpty() const
{
	return (m_size == 0);
}

template <typename T>
size_t DList<T>::size() const
{
	return m_size;
}

template <typename T>
void DList<T>::makeEmpty()
{
	while (!isEmpty())
	{
		pop_front();
	}
}

template <typename T>
void DList<T>::push_front(const T& val)
{
	Node* temp = new Node(val);
	if (m_head == nullptr)
	{
		m_head = temp;
		m_tail = m_head;
		++m_size;
	}
	else
	{
		m_head->prev = temp;
		temp->next = m_head;
		m_head = temp;
		++m_size;
	}
}

template <typename T>
void DList<T>::push_back(const T& val)
{
	Node* temp = new Node(val);
	if (m_head == nullptr)
	{
		m_head = temp;
		m_tail = m_head;
		++m_size;
	}
	else
	{
		m_tail->next = temp;
		temp->prev = m_tail;
		m_tail = temp;
		++m_size;
	}
}

template <typename T>
void DList<T>::insert(const size_t& pos, const T& val)
{

}

template <typename T>
void DList<T>::pop_front()
{
	assert(!isEmpty());
	Node* temp = m_head;
	m_head = m_head->next;

	delete temp;
	temp = nullptr;
	--m_size;
}

template <typename T>
void DList<T>::pop_back()
{
	assert(!isEmpty());
	Node* temp = m_tail;
	m_tail = m_tail->prev;
	m_tail->next = nullptr;

	delete temp;
	temp = nullptr;
	--m_size;
}

template <typename T>
void DList<T>::erase(const size_t pos)
{

}

template <typename T>
const T& DList<T>::get(const size_t& pos)
{
	assert(!isEmpty());
	assert(pos > 0 && pos <= m_size);

	Node* current = m_head;
	for (size_t i = 1; i < pos; ++i)
	{
		current = current->next;
	}
	return current->value;
}