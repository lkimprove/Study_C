#include <iostream>
#include <vector>
using namespace std;

//哈希节点
template <class K, class V>
struct HashNode{
	pair<K, V> _data;			//节点值
	HashNode<K, V>* _next;		//下一个位置

	//初始化
	HashNode(const pair<K, V>& data = pair<K, V>()) :
		_data(data), _next(nullptr)
	{}
};

//哈希表
template <class K, class V>
class HashTable{
public:
	typedef HashNode<K, V> Node;
	typedef Node* pNode;

	//拷贝函数
	HashTable(const size_t n = 10){
		_ht.resize(n);
		_size = 0;
	}

	//插入
	bool Insert(const pair<K, V>& data){
		//检查容量
		CheckCapacity();

		//计算索引
		int index = data.first % _ht.size();
		//遍历单链表
		pNode cur = _ht[index];
		while (cur){
			//不插入相同的元素
			if (cur->_data.first == data.first){
				return false;
			}

			//向下遍历
			cur = cur->_next;
		}

		//插入（头插）
		//创建cur
		cur = new Node(data);
		cur->_next = _ht[index];
		_ht[index] = cur;
		_size++;

		return true;
	}

	//检查容量
	void CheckCapacity(){
		//如果单链表上的元素过多，会影响插入，删除等操作的效率
		if (_size == _ht.size()){
			//新表的大小
			size_t new_size = (_ht.size() == 0 ? 10 : _ht.size() * 2);
			//创建新表
			vector<pNode> new_ht(new_size);
			//遍历旧表
			for (size_t i = 0; i < _ht.size(); i++){
				pNode cur = _ht[i];
				//遍历头节点
				while (cur){
					//计算索引
					int index = cur->_data.first % new_size;

					pNode next = cur->_next;
					//头插进旧表
					cur->_next = new_ht[index];
					new_ht[index] = cur;

					//继续遍历
					cur = next;
				}

				//旧表置空
				_ht[i] = nullptr;
			}
			//交换
			swap(_ht, new_ht);
		}
	}

	//查找
	pNode Find(const K& key){
		//计算索引
		int index = key % _ht.size();
		//遍历单链表
		pNode cur = _ht[index];
		while (cur){
			//当前元素等于key
			if (cur->_data.first == key){
				return cur;
			}

			//向下遍历
			cur = cur->_next;
		}

		//没找到
		return false;
	}


	//删除
	bool Erase(const K& key){
		//计算索引
		int index = key % _ht.size();

		//遍历单链表
		pNode cur = _ht[index];
		pNode prev = nullptr;

		while (cur){
			if (cur->_data.first == key){
				//判断cur是否为头节点
				if (prev == nullptr){
					_ht[index] = cur->_next;
				}
				else{
					prev->_next = cur->_next;
				}

				//删除该元素
				delete cur;
				cur = nullptr;
				_size--;

				return true;
			}

			//向下遍历
			prev = cur;
			cur = cur->_next;
		}

		//没找到该元素
		return false;
	}


	//打印
	void Print(){
		for (size_t i = 0; i < _ht.size(); i++){
			pNode cur = _ht[i];
			while (cur){
				//打印
				cout << cur->_data.first << "-" << cur->_data.second << endl;
				
				//向下遍历
				cur = cur->_next;
			}
		}
		cout << endl;
	}

private:
	//指针数组
	vector<pNode> _ht;
	//已存储的元素个数
	size_t _size;
};


//测试
void Test()
{
	HashTable<int, int> _ht;
	_ht.Insert(make_pair(1, 1));
	_ht.Insert(make_pair(3, 3));
	_ht.Insert(make_pair(6, 6));
	_ht.Insert(make_pair(0, 0));
	_ht.Insert(make_pair(10, 10));
	_ht.Insert(make_pair(13, 13));
	_ht.Insert(make_pair(16, 16));
	_ht.Insert(make_pair(11, 11));
	_ht.Insert(make_pair(14, 14));
	_ht.Insert(make_pair(15, 15));
	_ht.Insert(make_pair(110, 110));
	_ht.Print();

	int cur = 11;
	bool erase = _ht.Erase(cur);
	if (!erase){
		cout << cur << "删除失败" << endl;
	}
	else{
		cout << cur << "删除成功" << endl;
	}

	cur = 6;
	erase = _ht.Erase(cur);
	if (!erase){
		cout << cur << "删除失败" << endl;
	}
	else{
		cout << cur << "删除成功" << endl;
	}

	cur = 2;
	erase = _ht.Erase(cur);
	if (!erase){
		cout << cur << "删除失败" << endl;
	}
	else{
		cout << cur << "删除成功" << endl;
	}
	cout << endl;

	_ht.Print();


	cur = 110;
	if (_ht.Find(cur) == nullptr){
		cout << cur << "没找到" << endl;
	}
	else{
		cout << cur << "找到了" << endl;
	}

	cur = 78;
	if (_ht.Find(cur) == nullptr){
		cout << cur << "没找到" << endl;
	}
	else{
		cout << cur << "找到了" << endl;
	}


}

//测试
int main()
{
	Test();
	return 0;
}
