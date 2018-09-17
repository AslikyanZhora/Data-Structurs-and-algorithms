template<typename T>
class Stack
{
public:
	Stack() :n(0)
	{

	}
	bool empty()
	{
		return (n == 0);
	}
	const T& top()
	{
		return list.front();
	}
	void push(T val)
	{
		if (n < capacity)
		{
			list.push_front(val);
			++n;
		}
		else
		{
			std::cout << "Stack overflow\n";
			return;
		}
	}
	void pop()
	{
		if (empty())
		{
			std::cout << "Stack is empty:\n";
			return;
		}
		list.pop_front();
		--n;
	}
	int size()
	{
		return n;
	}
	void Show()
	{
		list.ShowList();
	}

private:
	int n;
	const int capacity = 10;
	SList<T> list;
	
};
template<typename T>
class Deque
{
public:
	Deque() :n(0)
	{
	}
	bool empty()
	{
		return (n == 0);
	}
	int size()
	{
		return n;
	}
	const T& front()
	{
		return list.front();
	}
	const T& back()
	{
		return list.back();
	}
	void push_front(T val)
	{
		list.push_front(val);
		++n;
	}
	void push_back(T val)
	{
		list.push_back(val);
		++n;
	}
	void pop_front()
	{
		if (empty())
		{
			std::cout << "Error:Deque is empty:\n";
			return;
		}
		list.pop_front();
		--n;
	}
	void pop_back()
	{
		if (empty())
		{
			std::cout << "Error:Deque is empty:\n";
			return;
		}
		list.pop_back();
		--n;
	}
	void Show()
	{
		list.ShowList();
	}
private:
	int n;
	DList<T> list;
};
