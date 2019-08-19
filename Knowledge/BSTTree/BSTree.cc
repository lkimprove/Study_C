#include <iostream>
#include <time.h>
using namespace std;

enum Color{
	RED, BLACK
};

//红黑树节点
template <class K, class V>
struct RBTNode{
	pair<K, V> _data;			//节点值	
	RBTNode<K, V>* _left;		//左节点
	RBTNode<K, V>* _right;		//右节点
	RBTNode<K, V>* _parent;		//父节点
	Color _color;

	//初始化
	RBTNode(const pair<K, V>& data = pair<K, V>()) :
		_data(data),
		_left(nullptr), _right(nullptr), _parent(nullptr),
		_color(RED)
	{}
};

//红黑树
template <class K, class V>
class RBTree{
public:
	typedef RBTNode<K, V> Node;
	typedef Node* pNode;

	//构造函数，初始化	_header
	RBTree(const pair<K, V>& data = pair<K, V>()){
		//创建_header
		_header = new Node(data);
		_header->_left = _header;
		_header->_right = _header;
		_header->_parent = nullptr;
	}

	//插入
	bool Insert(const pair<K, V>& data){
		//判空
		if (_header->_parent == nullptr){
			//创建根节点
			pNode root = new Node(data);

			//根节点为黑色
			root->_color = BLACK;
			
			//连接根节点
			root->_parent = _header;
			_header->_parent = root;
			
			//更新 _header 的左右节点
			_header->_left = _header->_right = root;
			
			return true;
		}

		//搜索
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur){
			//更新 parent
			parent = cur;

			//大于当前节点，往右走
			if (data.first > cur->_data.first){
				cur = cur->_right;
			}
			//小于当前节点，往左走
			else if(data.first < cur->_data.first){
				cur = cur->_left;
			}
			//不插入重复节点
			else{
				return false;
			}
		}

		//插入
		//创建 cur 节点
		cur = new Node(data);
		//更新cur的父节点
		cur->_parent = parent;

		// 确定cur节点的位置
		//大于当前节点，往右走
		if (cur->_data.first > parent->_data.first){
			parent->_right = cur;
		}
		//小于当前节点，往左走
		else{
			parent->_left = cur;
		}

		//调整
		//当新插入的节点 cur 与父节点 parent 均为红色时，需要调整
		while (cur != _header->_parent && parent->_color == RED){
			//祖父节点
			pNode grandparent = parent->_parent;
			
			//左边
			if (parent == grandparent->_left){
				//叔叔节点
				pNode uncle = grandparent->_right;
				//叔叔节点存在且为红色
				if (uncle && uncle->_color == RED){
					//调整颜色
					parent->_color = uncle->_color = BLACK;
					grandparent->_color = RED;

					//向上继续更新
					cur = grandparent;
					parent = cur->_parent;
				}
				//叔叔节点不存在，或者存在且为黑色
				else{
					//判断是否需要双旋
					//若cur 与 parent 在不同边，则需要双旋
					if (cur == parent->_right){
						//左旋
						RotateLeft(parent);
						
						//交换
						swap(cur, parent);
					}

					//cur 与 parent 在同一边
					//单旋，右旋
					RotateRight(grandparent);

					//调整颜色
					grandparent->_color = RED;
					parent->_color = BLACK;

					//结束调整
					break;
				}
			}
			//右边
			else{
				//叔叔节点
				pNode uncle = grandparent->_left;
				//叔叔节点存在且为红色
				if (uncle && uncle->_color == RED){
					//调整颜色
					parent->_color = uncle->_color = BLACK;
					grandparent->_color = RED;

					//向上继续调整
					cur = grandparent;
					parent = cur->_parent;
				}
				//叔叔节点不存在，或者存在叔叔节点且为黑色
				else{
					//判断是否需要双旋
					//parent 与 cur 不在同一边需要双旋
					if (cur == parent->_left){
						//右旋
						RotateRight(parent);

						//交换
						swap(cur, parent);
					}

					//parent 与 cur 在同一边
					//单旋，左旋
					RotateLeft(grandparent);

					//调整颜色
					parent->_color = BLACK;
					grandparent->_color = RED;

					//结束调整
					break;
				}
			}
		}

		//根节点必须为黑色
		_header->_parent->_color = BLACK;

		//更新 _header 的左右节点
		_header->_left = MostLeft();
		_header->_right = MostRight();

		return true;
	}

	//左旋
	void RotateLeft(pNode parent){
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		//六次连接
		subR->_left = parent;
		parent->_right = subRL;

		//如果 subRL 不为空，则更新其父节点
		if (subRL){
			subRL->_parent = parent;
		}

		//判断 parent 是否为根节点
		if (parent == _header->_parent){
			//更新根节点
			_header->_parent = subR;
			//更新 subR 的父节点
			subR->_parent = _header;
		}
		else{
			//祖父节点
			pNode grandparent = parent->_parent;
			//更新subR的父节点
			subR->_parent = grandparent;
			//确定 subR 在 grandparent 的位置
			if (grandparent->_left == parent){
				grandparent->_left = subR;
			}
			else {
				grandparent->_right = subR;
			}
		}

		//更新parent的父节点
		parent->_parent = subR;
	}

	//右旋
	void RotateRight(pNode parent){
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		//六次连接
		subL->_right = parent;
		parent->_left = subLR;

		//如果subLR存在，则更新其父节点
		if (subLR){
			subLR->_parent = parent;
		}

		//parent是否为根节点
		if (parent == _header->_parent){
			//更新根节点
			_header->_parent = subL;
			//更新 subL 的父节点
			subL->_parent = _header;
		}
		else{
			//祖父节点
			pNode grandparent = parent->_parent;
			//更新subL的父节点
			subL->_parent = grandparent;
			//确定 subL 在grandparent 的哪一个子节点
			if (grandparent->_left == parent){
				grandparent->_left = subL;
			}
			else {
				grandparent->_right = subL;
			}
		}

		//更新parent的父节点
		parent->_parent = subL;
	}

	//中序遍历
	void Inorder(){
		_Inorder(_header->_parent);
		cout << endl;
	}

	void _Inorder(pNode root){
		//中序遍历 -> 左，根，右
		if (root){
			_Inorder(root->_left);
			cout << root->_data.first << " ";
			_Inorder(root->_right);
		}
	}

	//最左节点
	pNode MostLeft(){
		pNode cur = _header->_parent;
		//该节点存在，则往左走
		while (cur && cur->_left){
			cur = cur->_left;
		}
		return cur;
	}

	//最右节点
	pNode MostRight(){
		pNode cur = _header->_parent;
		//该节点存在，则往右走
		while (cur && cur->_right){
			cur = cur->_right;
		}
		return cur;
	}

	//判断是否为红黑树
	//1.根为黑
	//2.没有连续的红色节点
	//3.任意路径上的黑色节点的个数相等
	bool IsRBTree(){
		pNode root = _header->_parent;
		//判空
		if (root == nullptr){
			return true;
		}
		//判断根的颜色
		if (root->_color != BLACK){
			return false;
		}

		//确定路径上黑色节点基准值
		int CountBlack = 0;

		//遍历某条路径，确定路径黑色节点的基准值
		pNode cur = root;
		while (cur){
			if (cur->_color == BLACK){
				CountBlack++;
			}
			if (cur->_color == RED && cur->_parent->_color == RED){
				return false;
			}
			cur = cur->_left;
		}
	
		//前序遍历确定每条路径上的黑色节点数
		return _IsRBTree(root, CountBlack, 0);
	}

	bool _IsRBTree(pNode root, int CountBlack, int CurCountBlack){
		//比较该条路径上的黑色节点数和基准值
		if (root == nullptr){
			if (CountBlack == CurCountBlack){
				return true;
			}
			return false;
		}

		//连续红色节点，返回false
		if (root->_color == RED && root->_parent->_color == RED){
			return false;
		}

		//更新该路径的黑色节点数
		if (root->_color == BLACK){
			++CurCountBlack;
		}

		//向下递归
		return _IsRBTree(root->_left, CountBlack, CurCountBlack)
			&& _IsRBTree(root->_right, CountBlack, CurCountBlack);
	}

private:
	//pNode _root
	//用_header 代替 _root，方便实现关联容器
	//_header 的左节点指向红黑树的最左节点
	//_header 的右节点指向红黑树的最右节点
	//_header 的父节点指向 _root，_root 的父节点指向 _header
	pNode _header;
};

//测试
void Test(){
	//创建一个红黑树
	RBTree<int, int> rbt;
	
	//测试用例
	int n;
	cout << "请输入需要插入的随机数的个数" << endl;
	cin >> n;
	//改变随机种子
	srand(time(nullptr));
	//插入随机数
	cout << "插入的随机数为：" << endl;
	for (int i = 0; i < n; i++){
		int cur = rand();
		cout << cur << " ";
		//插入随机数
		rbt.Insert(make_pair(cur, i));
	}
	cout << endl;
	
	//中序遍历
	cout << "中序遍历红黑树的结果为：" << endl;
	rbt.Inorder();

	//判断是否为红黑树
	if (rbt.IsRBTree()){
		cout << "插入后为红黑树" << endl;
	}
	else{
		cout << "插入后不为红黑树" << endl;
	}
}

int main(){
	//测试
	Test();
  
	return 0;
}

