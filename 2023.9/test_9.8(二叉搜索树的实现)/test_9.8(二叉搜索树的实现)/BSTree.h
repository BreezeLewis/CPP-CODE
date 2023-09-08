#pragma once
namespace Lewis
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key) :_key(key), _left(nullptr), _right(nullptr) {}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree() :_root(nullptr) {}

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);

			return *this;
		}
		
		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
					return false;
			}
			
			cur = new Node(key);

			if (key < parent->_key)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;

		}

		bool Find(const K& key)
		{
			Node* cur = _root;

			while (cur)
			{
				if (key < cur->_key)
					cur = cur->left;
				else if (key > cur->_key)
					cur = cur->right;
				else
					return true;
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->right;
				}
				else
				{
					//1.��Ϊ��
					//2.��Ϊ��
					//3.���Ҷ���Ϊ�գ��滻ɾ�� 
					if (cur->_left == nullptr)
					{
						Node* right = cur->_right;
						if (cur == _root)
							_root = right;
						if (parent->_left == cur)
							parent->_left = right;
						else
							parent->_right = right;
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						Node* left = cur->_left;
						if (cur == _root)
							_root = left;
						if (parent->_left = cur)
							parent->_left = left;
						else
							parent->_right = left;
						delete cur;
					}
					else
					{
						Node* parent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
							parent = minRight, minRight = minRight->_left;

						//cur->_key = minRight->_key;

						if (minRight == cur->_right)
						{
							minRight->_left = cur->_left;
							minRight->_right = nullptr;
						}
						else
						{
							minRight->_left = cur->_left;
							minRight->_right = cur->_right;
						}

						if (cur == parent->_left)
							minRight = parent->_left;
						else
							minRight = parent->_right;

						delete cur;
					}
				}
			}
		}

		void _InOrder(Node* _root)
		{
			if (_root == nullptr)
				return;

			_InOrder(_root->_left);

			cout << _root->_key << " ";

			_InOrder(_root->_right);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		Node* Copy(Node* cur)
		{
			if (cur == nullptr)
				return nullptr;

			Node* root = new Node(cur->_key);

			root->_left = Copy(cur->_left);
			root->_right = Copy(cur->_right);

			return root;
		}

		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);

			delete root;
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (key < root->_key)
				return _EraseR(root->_left, key);
			else if (key > root->_key)
				return _EraseR(root->_right, key);
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
					root = root->_right;
				else if (root->_right == nullptr)
					root = root->_left;
				else
				{
					Node* minRight = root->_right;
					while (minRight->_left)
						minRight = minRight->_left;

					swap(root->_key, minRight->_key);

					return _EraseR(root->_right, key);
				}

				delete del;

				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (key < root->_key)
				return _InsertR(root->_left, key);
			else if (key > root->_key)
				return _InsertR(root->_right, key);
			else
				return false;
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (key < root->_key)
				return _FindR(root->_left, key);
			else if (key > root->_key)
				return _FindR(root->_right, key);
			else
				return true;
		}
	private:
		Node* _root = nullptr;
	};

	void TestBSTree1()
	{
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		Lewis::BSTree<int> t;
		for (auto e : a)
		{
			t.InsertR(e);
		}

		t.InOrder();

		Lewis::BSTree<int> copyt(t);
		copyt.InOrder();

		//t.InsertR(9);
		//t.InOrder();

		t.EraseR(14);
		t.InOrder();

		t.EraseR(3);
		t.InOrder();

		t.EraseR(8);
		t.InOrder();

		for (auto e : a)
		{
			t.EraseR(e);
			t.InOrder();
		}

	}

	void TestBSTree2()
	{
		
	}
}

namespace Breeze
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value) :_left(nullptr), _right(nullptr), _key(key), _value(value) {}
		
	};
	
	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return false;
			}

			cur = new Node(key, value);
			if (key < parent->_key)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_root == nullptr)
				return nullptr;

			Node* cur = _root;

			while(cur)
			{
				if (key < cur->_key)
					cur = cur->_left;
				else if (key > cur->_key)
					cur = cur->_right;
				else
					return cur;
			}

			return nullptr;
		}

		void InOrder()
		{
			_InOrder(_root);
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);

			cout << root->_key << ":" << root->_value << endl;

			_InOrder(root->_right);
		}



	private:
		Node* _root = nullptr;
	};


	void TestBSTree2()
	{

		// ͳ��ˮ�����ֵĴ���
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		// �ʿ��е��ʶ��Ž������������
		// Key������ģ�ͣ��ж��ڲ��ڣ�
		// ��������鵥��ƴд�Ƿ���ȷ/�������ϵͳ/...
		//K::BSTree<string> dict;

		// Key/Value������ģ��,ͨ��Key���һ��޸�Value
		Breeze::BSTree<string, string> dict;
		dict.Insert("sort", "����");
		dict.Insert("string", "�ַ���");
		dict.Insert("left", "���");
		dict.Insert("right", "�ұ�");

		string str;
		while (cin >> str)
		{
			Breeze::BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "�޴˵���" << endl;
			}
		}
	}


	void TestBSTree3()
	{
		// ͳ��ˮ�����ֵĴ���
		string arr[] = { "ƻ��", "����", "�㽶", "��ݮ","ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		Breeze::BSTree<string, int> countTree;
		for (auto e : arr)
		{
			auto* ret = countTree.Find(e);
			if (ret == nullptr)
			{
				countTree.Insert(e, 1);
			}
			else
			{
				ret->_value++;
			}
		}

		countTree.InOrder();
	}
}