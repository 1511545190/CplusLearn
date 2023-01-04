//
// Created by 刘日亮 on 2023/1/2.
//
/*
 * 满二叉树 Full BT
 *      要么有两个儿子
 *      要么没有儿子
 * 完全二叉树 Complete BT
 *      右边可缺节点
 *
 * 完美二叉树Perfect Tree
 */
/*
 * 二叉树的遍历
 * 前序遍历：先访问根节点，再（按照前序遍历）访问左子树，最后(前序遍历）访问右节点
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
// Tree Node
template<class Element>
struct BinNode{
    Element data;//data
    //int depth;//depth
    BinNode<Element>* left;//left pointer
    BinNode<Element>* right;//right pointer
    //constructor
    BinNode(Element X);
};

template<class Element>
BinNode<Element>::BinNode(Element X) {
    data = X;

    left = right =NULL;
}

// class BinTree
template<class Element>
class BinTree{
    protected:
        BinNode<Element>* root;//root Node
        //为了能够递归访问
        void rpreprint(BinNode<Element>* root);//前序遍历
        void rin_print(BinNode<Element>* root); //中序遍历
        BinNode<Element> *rfindX(Element X, BinNode<Element>* root);//前序查找
        void rprint(BinNode<Element>* root,int depth);//格式打印


    public:
    //construct
        BinTree(){root=NULL;}
        BinTree(Element r){
        //嵌套构造
            root = new BinNode<Element>(r);//construct
        }
    //destruct
        ~BinTree(){}

    //前序遍历
        void preprint();

    //中序遍历
        void in_print();

    //格式打印
        void print(){
        rprint(root,0);
        }

    //find
        BinNode<Element> * findX(Element X);



    //插入节点:
    //       在哪一个节点之下插入节点，
    //       是左还是右边
    //       插入值
    //空不可插入，被占不可插入
        bool insert(Element p, int position, Element insert_value);


};

//普通遍历//树的深度
template<class Element>
void BinTree<Element>::rprint(BinNode<Element> *root,int depth) {
    for(int i = 0 ;i<depth;i++)cout <<"  ";//空格

    if(!root)cout<<"[\]"<<endl;
    else {
        cout << root->data << endl;
        rprint(root->right, depth + 1);
        rprint(root->left, depth + 1);
    }

    /*
11
  22
    []
    []
  33
    []
    []
     */
}

//前序遍历
template<class Element>//注意：凡是指针都可能是空的
void BinTree<Element>::rpreprint(BinNode<Element>* r) {
    //递归终止的条件
    if(!r) return;

    cout<< r->data<<" ";
    rpreprint(r->left);
    rpreprint(r->right);
}

template<class Element>
void BinTree<Element>::preprint(){
    //嵌套调用
    rpreprint(root);
    cout<<endl;
}

//中序遍历
template<class Element>
void BinTree<Element>::rin_print(BinNode<Element> *root) {
    if(!root)
        return;
    rin_print(root->left);
    cout<<root->data<<" ";
    rin_print(root->right);

}
template<class Element>
void BinTree<Element>::in_print() {
    //嵌套调用
    rin_print(root);
}



//find,找到位置才能插入
template<class Element>
BinNode<Element> * BinTree<Element>::rfindX(Element X,BinNode<Element> *root) {
    if(!root)//如果根节点为空
        return NULL;
    //如果根为要找的节点
    if(root->data == X)
        return root;
    //如果左边找得到
    BinNode<Element> *found = rfindX(X,root->left);
    if(found) return found;
    //如果右边找得到
    return found?found: rfindX(X,root->right);
}
template<class Element>
BinNode<Element> * BinTree<Element>::findX(Element X) {
    return rfindX(X,root);
}



//插入
template<class Element>
bool BinTree<Element>::insert(Element p, int position, Element insert_value){
    BinNode<Element> *found = findX(p);
    //如果没找到，说明没有这个节点
    if(!found)
    {
        cout<<"Insert position not found\n";
        return false;
    }

    //position 1 左边;左边有值
    if(position&&found->left){
        cout<<"left have already have node"<<endl;
        return false;
    }else if(position){//左边没有值,可以插入
        found->left = new BinNode<Element>(insert_value);
        return true;
    }

    //position 0 is right
    if(found->right&&!position){
        cout<<"right have already have node"<<endl;
        return false;
    }else if(!position){//左边没有值,可以插入
        found->right = new BinNode<Element>(insert_value);
        return true;
    }

    return false;
}


int main()
{
    BinTree<int> bt(11);
    bt.insert(11,1,22);
    bt.insert(11,0,33);

    bt.insert(22,1,44);
    bt.insert(22,0,55);

    bt.insert(33,1,66);
    bt.insert(33,0,77);

    //访问
    cout<<"pre print\n";
    bt.preprint();
    cout<<"simple print:"<<endl;
    bt.print();

    cout<<"in print\n";
    bt.in_print();





    return 0;
}
