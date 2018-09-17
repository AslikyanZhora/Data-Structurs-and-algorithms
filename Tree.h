template<typename T>
class BSTree
{
public:
	BSTree()
	{
		root = nullptr;
	}
	~BSTree()
	{
		Destroy(root);
	}
	void Insert(T val)
	{
		root = Insert(root, val);
	}
	void Inorder()
	{
		Inorder(root);
		std::cout << "\n";
	}
	void Preorder()
	{
		Preorder(root);
		std::cout << "\n";
	}
	void Postorder()
	{
		Postorder(root);
		std::cout << "\n";
	}
	int height()
	{
		return height(root);
	}
	T Min()
	{
		TreeNode* min = findMin(root);
		if (min == nullptr)
			return 0;
		return min->value;

	}
	T Max()
	{
		TreeNode* max = findMax(root);
		if (max == nullptr)
			return 0;
		return max->value;
	}
	void Remove(T val)
	{
		root = Remove(root, val);
	}
	void Search(T val)
	{
		TreeNode* temp = Search(root, val);
		if (temp == nullptr)
			std::cout << "Element not found\n";
		else
			std::cout << temp->value << "\n";
	}
private:
	struct TreeNode
	{
		T value;
		TreeNode* left;
		TreeNode* right;

		TreeNode(T val) :value(val), left(nullptr), right(nullptr)
		{

		}
	};
	TreeNode* root;
	TreeNode* Insert(TreeNode* temp, T val)
	{
		if (temp == nullptr)
		{
			temp = new TreeNode(val);
		}
		else if (val < temp->value)
			temp->left = Insert(temp->left, val);
		else
			temp->right = Insert(temp->right, val);
		return temp;
	}
	void Inorder(TreeNode* temp)
	{
		if (temp == nullptr)
			return;

		Inorder(temp->left);
		std::cout << temp->value << "  ";
		Inorder(temp->right);
		
	}
	void Preorder(TreeNode* temp)
	{
		if (temp == nullptr)
			return;

		std::cout << temp->value << "  ";
		Inorder(temp->left);
		Inorder(temp->right);
	}
	void Postorder(TreeNode* temp)
	{
		if (temp == nullptr)
			return;

		Inorder(temp->left);
		Inorder(temp->right);
		std::cout << temp->value << "  ";
	}
	int height(TreeNode* temp)
	{
		if (temp == nullptr)
			return 0;
		int l = height(temp->left);
		int r = height(temp->right);
		if (l > r)
			return (l + 1);
		else
			return (r + 1);
	}
	TreeNode* findMin(TreeNode* temp)
	{
		if (temp == nullptr)
			return nullptr;
		if (temp->left == nullptr)
			return temp;
		return findMin(temp->left);
	}
	TreeNode* findMax(TreeNode* temp)
	{
		if (temp == nullptr)
			return nullptr;
		if (temp->right == nullptr)
			return temp;
		return findMax(temp->right);
	}
	void Destroy(TreeNode* temp)
	{
		if (temp != nullptr)
		{
			Destroy(temp->left);
			Destroy(temp->right);
		}
		delete temp;
		temp = nullptr;
	}
	TreeNode* Remove(TreeNode* temp, T val)
	{
		if (temp == nullptr)
			return nullptr;
		else if (val < temp->value)
			temp->left = Remove(temp->left, val);
		else if (val > temp->value)
			temp->right = Remove(temp->right, val);
		else
		{
			if (temp->left == nullptr && temp->right == nullptr)
			{
				delete temp;
				temp = nullptr;
			}
			else if (temp->left == nullptr)
			{
				TreeNode* t = temp;
				temp = temp->left;
				delete t;
				t = nullptr;
			}
			else if (temp->right == nullptr)
			{
				TreeNode* t = temp;
				temp = temp->right;
				delete t;
				t = nullptr;
			}
			else
			{
				TreeNode* t = findMin(temp->right);
				temp->value = t->value;
				temp->right = Remove(temp->right, t->value);
			}
		}
		return temp;
	}
	TreeNode* Search(TreeNode* temp, T val)
	{
		if (temp == nullptr)
			return nullptr;
		else
		{
			if (val < temp->value)
					return Search(temp->left, val);
			if (val > temp->value)
				return Search(temp->right, val);
			else if (val == temp->value)
				return temp;
			else
				return nullptr;
		}

	}
};															  
