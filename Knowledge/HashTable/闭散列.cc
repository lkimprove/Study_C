#include <iostream>
#include <vector>
using namespace std;

enum State {
	EMPTY, DELETE, EXIST
};

//哈希节点
template <class K, class V>
struct HashNode{
	pair<K, V> _data;	//节点值
	State _state = EMPTY;		//节点状态
};

//哈希表
template <class K, class V>
class HashTable{
public:
	typedef HashNode<K, V> Node;
	typedef Node* pNode;

	//构造函数
	HashTable(const size_t n = 10){
		_ht.resize(n);
		_size = 0;
	}

	//插入
	bool Insert(const pair<K, V> data){
		//检查容量
		CheckCapacity();

		//计算索引
		int index = data.first % _ht.size();
		//查找插入位置
		//可插入位置：EMPTY，DELETE
		while (_ht[index]._state == EXIST){
			//判断是否插入重复元素
			if (_ht[index]._data.first == data.first){
				return false;
			}

			//向下遍历
			index++;
			//如果查找到最后位置，则从头重新开始查找
			//ps：因为负载因子小于阈值，所以不存在哈希表满的情况
			if (index == _ht.size()){
				index = 0;
			}
		}

		//插入元素
		_ht[index]._data = data;
		_ht[index]._state = EXIST;
		_size++;

		return true;
	}

	//检查容量
	void CheckCapacity(){
		//当_ht.size()为 0，或者负载因子大于阈值的时候，需要扩容
		if (_ht.size() == 0 || _size * 10 / _ht.size() == 8){
			//新表的大小
			int new_size = (_ht.size() == 0 ? 10 : _ht.size() * 2);
			//创建新表
			HashTable<K, V> new_ht(new_size);
			//将旧表的元素插入新表
			for (size_t i = 0; i < _ht.size(); i++){
				//如果改位置存在元素，则插入
				if (_ht[i]._state == EXIST){
					new_ht.Insert(_ht[i]._data);
				}
			}

			//交换新表与旧表
			swap(_ht, new_ht._ht);
		}
	}

	//查找
	pNode Find(const K& key){
		//创建索引
		int index = key % _ht.size();
		//一直查找到空
		while (_ht[index]._state != EMPTY){
			//该位置存在元素
			if (_ht[index]._state == EXIST){
				//找到该元素
				if (_ht[index]._data.first == key){
					return &_ht[index];
				}
			}

			//向下遍历
			index++;
			//如果查找到最后一个位置，则从头继续开始遍历
			//负载因子小于阈值，所以哈希表不会满
			if (index == _ht.size()){
				index = 0;
			}
		}

		//没找到
		return nullptr;
	}

	//删除
	bool Erase(const K& key){
		//查找该元素
		pNode pos = Find(key);
		//判断该元素是否存在
		if (pos){
			//删除该元素
			pos->_state = DELETE;
			_size--;
			
			return true;
		}

		//没找到
		return false;
	}

	//打印
	void Input(){
		for (size_t i = 0; i < _ht.size(); i++){
			//判断该位置是否存在元素
			if (_ht[i]._state == EXIST){
				cout << _ht[i]._data.first << "-" << _ht[i]._data.second << endl;
			}
		}
		cout << endl;
	}

private:
	//哈希表
	vector<Node> _ht;
	//存储的元素个数
	size_t _size = 0;
};


void Test(){
	HashTable<int, int>  ht;
	ht.Insert(make_pair(5, 5));
	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(0, 0));
	ht.Insert(make_pair(10, 10));
	ht.Insert(make_pair(3, 3));
	ht.Insert(make_pair(30, 30));
	ht.Insert(make_pair(32, 32));
	ht.Insert(make_pair(8, 8));
	ht.Insert(make_pair(110, 110));
	ht.Insert(make_pair(23, 23));
	ht.Input();
	ht.Erase(110);
	ht.Input();

	int cur = 110;
	HashTable<int, int>::Node* pos = ht.Find(cur);
	if (pos){
		cout << "找到了" << cur << endl;
	}
	else {
		cout << "没找到" << cur << endl;
	}

	cur = 23;
	pos = ht.Find(cur);
	if (pos){
		cout << "找到了" << pos->_data.first << endl;
	}
	else {
		cout << "没找到" << cur << endl;
	}

	cur = 100;
	pos = ht.Find(cur);
	if (pos){
		cout << "找到了" << pos->_data.first << endl;
	}
	else {
		cout << "没找到" << cur << endl;
	}
}

int main(){
	//测试
	Test();

	return 0;
}
