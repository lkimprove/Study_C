#include <iostream>
using namespace std;

//二叉搜索树节点
template <class T>
struct BSTNode{
	T _data;				//节点值
	BSTNode<T>* _left;		//左子树
	BSTNode<T>* _right;		//右子树

	//初始化
	BSTNode(const T& data = T()) :
		_data(data),
		_left(nullptr), _right(nullptr)
	{}
};

//二叉搜索树
template <class T>
class BSTree{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	//构造函数
	BSTree() :
		_root(nullptr)
	{}

	//拷贝函数
	pNode Copy(pNode root){
		//判空
		if (root == nullptr){
			return nullptr;
		}

		//创建节点
		pNode newNode = new Node(root->_data);
		//向左遍历
		newNode->_left = Copy(root->_left);
		//向右遍历
		newNode->_right = Copy(root->_right);

		return newNode;
	}

	//拷贝构造
	BSTree<T>(const BSTree& bst){
		_root = Copy(bst._root);
	}

	//重载=
	BSTree<T>& operator=(const BSTree& bst){
		//防止自己赋值给自己
		if (this != &bst){
			//释放原有的bst
			if (_root){
				Destroy(_root);
			}
			_root = Copy(bst._root);
		}
		return *this;
	}

	//删除函数
	void Destroy(pNode root){
		if (root){
			Destroy(root->_left);
			Destroy(root->_right);

			//删除节点
			delete root;
			root = nullptr;
		}
	}


	//析构函数
	~BSTree(){
		Destroy(_root);
	}

	//插入
	bool Insert(const T& data){
		//判空
		if (_root == nullptr){
			//创建根节点
			_root = new Node(data);
			
			return true;
		}

		//搜索
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur){
			parent = cur;
			//不插入重复节点
			if (data == cur->_data){
				return false;
			}
			//大于当前节点
			else if (data > cur->_data){
				cur = cur->_right;
			}
			//小于当前节点
			else{
				cur = cur->_left;
			}
		}

		//插入
		//创建 cur
		cur = new Node(data);
		//判断插入的位置
		if (cur->_data > parent->_data){
			parent->_right = cur;
		}
		else{
			parent->_left = cur;
		}

		return true;
	}

	
	//查找
	pNode Find(const T& data){
		pNode cur = _root;
		while (cur){
			if (data == cur->_data){
				return cur;
			}
			else if (data > cur->_data){
				cur = cur->_right;
			}
			else{
				cur = cur->_left;
			}
		}

		//没找到
		return false;
	}

	//删除
	bool Erase(const T& data){
		//搜索
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur){
			//找到要删除的节点
			if (data == cur->_data){
				break;
			}
			
			//更新parent
			parent = cur;
			//大于当前节点
			if (data > cur->_data){
				cur = cur->_right;
			}
			//小于当前节点
			else{
				cur = cur->_left;
			}
		}

		//是否找到要删除的节点
		if (cur == nullptr){
			return false;
		}

		//删除
		//叶子节点
		if (cur->_right == nullptr && cur->_left == nullptr){
			//判断cur是否根节点
			if (cur == _root){
				_root = nullptr;
			}
			else{
				//判断cur的位置
				if (parent->_left == cur){
					parent->_left = nullptr;
				}
				else{
					parent->_right = nullptr;
				}
			}

			//删除节点
			delete cur;
			cur = nullptr;
		}
		//只有左节点
		else if (cur->_right == nullptr){
			//判断cur是否为根节点
			if (cur == _root){
				_root = cur->_left;
			}
			else{
				//判断cur的位置
				if (parent->_left == cur){
					parent->_left = cur->_left;
				}
				else{
					parent->_right = cur->_left;
				}
			}

			//删除节点
			delete cur;
			cur = nullptr;
		}
		//只有右节点
		else if (cur->_left == nullptr){
			//判断cur是否为根节点
			if (cur == _root){
				_root = cur->_right;
			}
			else{
				//判断cur的位置
				if (parent->_left == cur){
					parent->_left = cur->_right;
				}
				else{
					parent->_right = cur->_right;
				}
			}

			//删除节点
			delete cur;
			cur = nullptr;
		}
		//左右节点均有
		else{
			//找到 cur 左子树的最右（最大）节点，或者右子树的最左（最小）节点
			//将该节点的值赋给 cur，删除该节点
			pNode left_max = cur->_left;
			pNode parent = cur;
			while (left_max->_right){
				parent = left_max;
				left_max = left_max->_right;
			}

			//将 left_max 赋给 cur
			cur->_data = left_max->_data;
			//判断 left_max 的位置
			if (parent->_left == left_max){
				parent->_left = left_max->_left;
			}
			else{
				parent->_right = left_max->_left;
			}

			//删除 left_max
			delete left_max;
			left_max = nullptr;
		}
		return true;
	}

	//中序遍历
	void Inorder(){
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(pNode root){
		if (root){
			_Inorder(root->_left);
			cout << root->_data << " ";
			_Inorder(root->_right);
		}
		return;
	}


private:
	//根节点
	pNode _root = nullptr;
};


//测试
void Test()
{
	BSTree<int> bst;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(7);
	bst.Insert(1);
	bst.Insert(4);
	bst.Insert(6);
	bst.Insert(8);
	bst.Insert(0);
	bst.Insert(2);
	bst.Insert(9);
	bst.Inorder();

	//BSTree<int> cpy(bst);
	//cpy.Inorder();

	//BSTree<int> bst2;
	//bst2.Insert(100);
	//bst2.Insert(200);
	//bst2.Insert(300);
	//bst2.Insert(400);
	//bst2.Inorder();

	//bst2 = bst;
	//bst2.Inorder();


	//bst.Erase(9);
	//bst.Inorder();
	//bst.Erase(8);
	//bst.Inorder();
	//bst.Erase(5);
	//bst.Inorder();
	//bst.Erase(3);
	//bst.Inorder();
	//bst.Erase(0);
	//bst.Inorder();
	//bst.Erase(1);
	//bst.Inorder();
	//bst.Erase(2);
	//bst.Inorder();
	//bst.Erase(4);
	//bst.Inorder();
	//bst.Erase(6);
	//bst.Inorder();
	//bst.Erase(7);
	//bst.Inorder();
}

int main(){
	//测试
	Test();

	return 0;
}
