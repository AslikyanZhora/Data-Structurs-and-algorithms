#pragma once

template <typename T>
class DList
{
public:
	DList();
	~DList();
	bool isEmpty() const;
	size_t size() const;
	void makeEmpty();
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	const T& get(const size_t& pos);
private:
	struct Node
	{
		Node(const T& val = 0) :next(nullptr), prev(nullptr), value(val){}

		Node* next;
		Node* prev;
		T value;
	};
	Node* m_head;
	Node* m_tail;
	size_t m_size;
};
