#include <iostream>
using namespace std;

//AVL节点
template <class T>
struct AVLNode{
	T _data;				//节点值
	AVLNode<T>* _left;      //左节点
	AVLNode<T>* _right;		//右节点
	AVLNode<T>* _parent;	//父节点
	int _bf;				//平衡因子

	//初始化节点
	AVLNode(const T& data) :
		_data(data),
		_left(nullptr), _right(nullptr), _parent(nullptr),
		_bf(0)
	{}
};

//AVL树
template<class T>
class AVLTree{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

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
			//更新父节点
			parent = cur;
			//重复节点不插入
			if (cur->_data == data){
				return false;
			}
			//大于当前节点，往右走
			else if (data > cur->_data){
				cur = cur->_right;
			}
			//小于当前节点，往左走
			else{
				cur = cur->_left;
			}
		}

		//插入
		//创建节点
		cur = new Node(data);
		cur->_parent = parent;
		//判断插入的位置
		if (cur->_data > parent->_data){
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}

		//调整
		while (parent){
			//更新平衡因子
			//插入左边，--_bf
			if (parent->_left == cur){
				--(parent->_bf);
			}
			//插入右边，++_bf
			else{
				++(parent->_bf);
			}

			//根据平衡因子判断是否需要调整
			//平衡因子为0，不用调整
			if (parent->_bf == 0){
				break;
			}
			//平衡因子为 -1/1，向上继续判断
			else if (parent->_bf == -1 || parent->_bf == 1){
				cur = parent;
				parent = parent->_parent;
			}
			else{
				//左边的左边高，右旋
				if (parent->_bf == -2 && cur->_bf == -1){
					RotateRight(parent);
				}
				//右边的右边高，左旋
				else if (parent->_bf == 2 && cur->_bf == 1){
					RotateLeft(parent);
				}
				//左边的右边高，左右旋
				else if (parent->_bf == -2 && cur->_bf == 1){
					pNode subL = parent->_left;
					pNode subLR = subL->_right;
					int bf = subLR->_bf;

					RotateLeft(cur);
					RotateRight(parent);

					//特殊情况，判断多的那个节点在哪
					if (bf == 1){
						parent->_bf = 0;
						subL->_bf = -1;
					}
					else if(bf == -1){
						parent->_bf = 1;
						subL->_bf = 0;
					}
				}
				//右边的左边高，右左旋
				else if (parent->_bf == 2 && cur->_bf == -1){
					pNode subR = parent->_right;
					pNode subRL = subR->_left;
					int bf = subRL->_bf;

					RotateRight(cur);
					RotateLeft(parent);

					//特殊情况
					//判断多的的那个节点在哪里
					if (bf == 1){
						subR->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1){
						subR->_bf = 1;
						parent->_bf = 0;
					}
				}
				break;
			}
		}
		return true;
	}

	//左旋
	void RotateLeft(pNode parent){
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		//六次调整
		subR-> _left= parent;
		parent->_right = subRL;

		//不为空，则更新其父节点
		if (subRL){
			subRL->_parent = parent;
		}

		//parent是否为根节点
		if (parent == _root){
			//更新根节点
			_root = subR;
			//更新subR的父节点
			subR->_parent = nullptr;
		}
		else{
			pNode grandparent = parent->_parent;	//祖父节点
			//更新subR的父节点
			subR->_parent = grandparent;
			//确定subR在祖父节点的位置
			if (grandparent->_left == parent){
				grandparent->_left = subR;
			}
			else{
				grandparent->_right = subR;
			}
		}

		//更新parent的父节点
		parent->_parent = subR;

		//更新平衡因子
		parent->_bf = subR->_bf = 0;
	}

	//右旋
	void RotateRight(pNode parent){
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		//六次调整
		subL->_right = parent;
		parent->_left = subLR;

		//如果subLR不为空，则更新其父节点
		if (subLR){
			subLR->_parent = parent;
		}

		//parent是否为根节点
		if (parent == _root){
			//更新根节点
			_root = subL;
			//更新其父节点
			subL->_parent = nullptr;
		}
		else{
			pNode grandparent = parent->_parent;	//祖父节点
			//跟新subL的父节点
			subL->_parent = grandparent;
			//判断subL在祖父节点的位置
			if (grandparent->_left == parent){
				grandparent->_left = subL;
			}
			else{
				grandparent->_right = subL;
			}
		}

		//更新parent的父节点
		parent->_parent = subL;

		//更新平衡因子
		parent->_bf = subL->_bf = 0;
	}

	//中序遍历
	void InOrder(){
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(pNode root){
		if (root){
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	//树的高度
	int Height(pNode root){
		//结束条件
		if (root == nullptr){
			return 0;
		}

		//分别计算左右子树
		int height_left = Height(root->_left);
		int height_right = Height(root->_right);

		return height_left > height_right ?
			height_left + 1 : height_right + 1;
	}

	//判断是否为平衡树
	bool IsBalance(){
		return _IsBalance(_root);
	}

	bool _IsBalance(pNode root){
		//判空
		if (root == nullptr){
			return true;
		}
		//计算当前根节点的高度差
		int height_left = Height(root->_left);
		int height_rigth = Height(root->_right);
		int height_value = height_rigth - height_left;

		//比较根节点的平衡因子和高度差是否相等
		if (height_value != root->_bf){
			cout << root->_data << "：不平衡" << endl;
			cout << "平衡因子：" << root->_bf << "高度差：" << height_value << endl;
			return false;
		}
		else {
			cout << root->_data << " " << root->_bf << endl;
		}

		//向下递归
		return (abs(root->_bf) < 2 )&&
			_IsBalance(root->_left) &&
			_IsBalance(root->_right);
	}

private:
	pNode _root = nullptr;		//根节点
};

//测试
void Test(){
	//创建一个AVL树
	AVLTree<int> avl;
	//插入
	//测试用例一
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//测试用例二
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		avl.Insert(a[i]);
	}
	//中序遍历
	avl.InOrder();
	//判断是否为平衡树
	if (avl.IsBalance()){
		cout << "平衡树" << endl;
	}
	else {
		cout << "非平衡树" << endl;
	}
}

int main(){
	//测试
	Test();
	return 0;
}
