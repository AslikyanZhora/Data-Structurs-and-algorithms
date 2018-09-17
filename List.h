template<typename T>
// Singly linked list implementation
class SList
{

public:
	void push_front(T val) // adding new element at front
	{
		ListNode* temp = new ListNode(val);
		temp->next = head;
		head = temp;
	}
	void pop_front()  // removing first element
	{
		ListNode* temp = head;
		head = temp->next;
		delete temp;
		temp = nullptr;
	}
	bool empty()  // check if the list empty
	{
		return head == nullptr;
	}
	SList() :head(nullptr) // constructor
	{

	}
	~SList() // destructor
	{
		while (!empty())
		{
			pop_front();
		}
	}
	void ShowList() // Show whole list
	{
		Show(head);
	}
	const T&  front() // returns the first element
	{
		return head->value;
	}
private:
	struct ListNode	  // linked list node
	{

		ListNode(T val) :next(nullptr)
		{
			value = val;
		}
		T value;
		ListNode* next;
	};
	ListNode* head;
	void Show(ListNode* head)
	{
		while (head != NULL)
		{
			std::cout << head->value << "  ";
			head = head->next;
		}
		std::cout << std::endl;
	}

};
// Doubly Linked list implementation
template<typename T>
class DList
{
public:
	DList() :head(nullptr), tail(nullptr) // constructor
	{
	}
	~DList() // destructor
	{
		while (!empty())
			pop_front();
		std::cout << "Destructor\n";
	}
	void push_front(T val) // adding a new element at front
	{
		ListNode* temp = new ListNode(val);
		if (head == nullptr)
		{
			head = temp;
			tail = head;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	void push_back(T val)  // adding a new element at back
	{
		ListNode* temp = new ListNode(val);
		if (head == nullptr)
		{
			head = temp;
			tail = head;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	void ShowList()	// Show whole list
	{
		ShowList(head);
	}
	const T& front()  // returns the first element of the list
	{
		return head->value;
	}
	const T& back()	// returns the last element of the list
	{
		return tail->value;
	}
	bool empty()  // checks if list empty
	{
		return (head == nullptr);
	}
	void pop_front()  // removing at front
	{
		if (empty())
			return;
		ListNode* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	void pop_back()	 // removing at back
	{
		if (empty())
			return;
		ListNode* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		temp = nullptr;
	}
private:
	struct ListNode	// linked list node structure
	{
		T value;
		ListNode* prev;
		ListNode* next;
		ListNode(T val) :prev(nullptr), next(nullptr)
		{
			value = val;
		}
	};
	ListNode* head;
	ListNode* tail;
	void ShowList(ListNode* temp)
	{
		while (temp != nullptr)
		{
			std::cout << temp->value << "  ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

};
