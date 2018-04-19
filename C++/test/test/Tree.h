#ifndef TREE_H_
#define TREE_H_

#include <iostream>  
using namespace std;  
/* 存在的问题: 
** 1.拷贝构造,赋值 
** 2.find函数返回指针,公开的find函数让其返回逻辑值,true代表存在,false代表不存在 
** 
** 
*/  
typedef int T;  
struct Node{  
    T data;  
    Node* left;  
    Node* right;  
    Node(const T& d)  
        :data(d),left(),right(){}  
};  
class Tree{  
    Node* root;//指向根结点的指针  
    int sz;//结点个数  
    typedef Node* tree;//树类型  
    //将结点pn插入到树t中  
    void insert(Node* pn, tree& t){  
        if(pn==NULL) return;//防止插入空树  
        if(t==NULL){ t = pn; return; }  
        if(pn->data>t->data){  
            insert(pn, t->right);  
        }else{ insert(pn, t->left); }  
    }  
    //打印一棵树t  
    void travel(tree& t){  
        if(t==NULL) return;  
        travel(t->left);  
        cout << t->data << ' ';  
        travel(t->right);  
    }  
    //释放一棵树  
    void clear(tree& t){  
        if(t==NULL) return;   
        clear(t->left);  
        clear(t->right);  
        delete t;   
        t = NULL;  
    }  
    //一棵树的层数  
    int high(tree& t){  
        if(t==NULL) return 0;  
        int lh = high(t->left);  
        int rh = high(t->right);  
        return (lh>rh?lh:rh)+1;    
    }   
    //从树中查找指定的元素是否存在,如果存在,返回指向此结点的指针,不存在返回NULL  
    Node*& find(tree& t, const T& d){  
        if(t==NULL) return t;  
        if(d==t->data) return t;  
        if(d>t->data)  
            return find(t->right, d);  
        return find(t->left, d);    
    }  
public:  
    Tree():root(),sz(){}  
    ~Tree(){clear();}  
    void insert(int pos, const T& d){  
        insert(d);  
    }  
    void insert(const T& d){  
        Node* pn = new Node(d);  
        insert(pn, root);   
        sz++;  
    }    
    void travel(){  
        travel(root);  
        cout<<endl;   
    }  
    void clear(){ clear(root); sz = 0; }  
    int size(){ return sz; }   
    int high(){ return high(root);}  
    bool find(const T& d){  
        return find(root, d);  
    }  
    //从树中删除指定元素  
    bool remove(const T& d){  
        Node*& r = find(root, d);   
        if(r==NULL) return false;  
        //将此结点的左子树插入到右子树中  
        insert(r->left, r->right);   
        //将右子树向上移一级  
        Node* p = r;  
        r = r->right;  
        delete p;  
        sz--;  
        return true;  
    }  
    //删除所有值为d的元素  
    void removeAll(const T& d){  
        while(remove(d));   
    }  
    //修改指定元素的值  
    bool modify(  
        const T& old, const T&newval){  
            //删除旧值 插入新值  
            if(remove(old)) insert(newval);  
    }  
};  
int main()  
{  
    Tree t;  
    t.insert(5);t.insert(3);t.insert(1);  
    t.insert(4);t.insert(7);t.insert(6);  
    t.travel();   
    cout << t.size() << endl;  
    cout << "high=" << t.high() << endl;  
    cout << t.find(5) << endl;  
    cout << t.find(7) << endl;  
    cout << t.find(8) << endl;  
    t.remove(5);  
    t.travel();  
    t.modify(3, 30);  
    t.travel();  
    t.insert(8);  
    t.insert(8);  
    t.insert(8);  
    t.insert(8);  
    t.insert(9);  
    t.travel();  
    t.removeAll(8);  
    t.travel();  
    //以下是不好的操作  
    //t.find(4)->data = 40;  
    //t.travel();  
}  

#endif
