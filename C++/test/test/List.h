#ifndef LIST__H__
#define LIST__H__
#include <iostream>
#include <stdexcept>
using namespace std;
typedef int T;
//链表类
class List
{
	struct Node{//内部类
		T data;
		Node* next;
		Node(const T& d):data(d),next(){}
	};
	Node* head;//头指针
	int sz;//元素个数
public:
	List():head(0),sz(0){} 
	~List(){clear();};
	//向链表中插入一个元素(尾插)
	void insert(const T& d){
		Node* pn = new Node(d);
		if(head==NULL){
			head = pn; sz++; return;
		}
		Node* p = head;
		while(p->next){ p = p->next; }
		p->next = pn;
		sz++;
	} 
	//在指定位置插入元素
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		Node* pn = new Node(d);
		//如果是头插
		if(pos==0){
			pn->next = head;
			head = pn;
			sz++;
			return true;
		}
		//如果不是头插
		Node* p = head;
		for(int i=0; i<pos-1; i++){
			p = p->next;
		} 
		pn->next = p->next;
		p->next = pn;
		sz++;
		return true;
	}
	//打印链表
	void travel(){
		Node* p = head;
		while(p){
			cout << p->data << ' ';
			p = p->next;
		} 
		cout << endl;
	}
	//清空链表
	void clear(){
		Node* p = head;
		while(head){
			head = head->next;
			delete p;
			p = head;
		}  
		sz = 0;
	}
	//删除指定位置的元素
	bool erase(int pos){
		if(pos<0||pos>=sz) return false;
		Node* p = head;
		//删除0位置的元素
		if(pos==0){
			head = head->next;
			delete p;
			sz--;
			return true;
		}
		//删除非0位置的元素
		for(int i=0; i<pos-1; i++){
			p = p->next;
		}   
		Node* q = p->next;
		p->next = q->next;
		delete q; 
		sz--;
		return true;
	}
	//返回指定位置的元素
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		Node* p = head;
		for(int i=0; i<pos; i++){
			p = p->next;
		}
		return p->data;
	}
	//返回链表中的元素个数
	int size(){ return sz;} 

	//链表逆序
	void reverse()
	{
		if(!head)  //判断链表是否为空,为空即退出。  
		{  
			return ;  
		}  
		Node* next = NULL;  
		Node* pre = NULL;       
		while ( NULL != head )  //循环直到 cur.next 为空  
		{  
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
			  
		}  
		head = pre;
		//return tmp;     //f 返回头指针  
	}
};

#endif

