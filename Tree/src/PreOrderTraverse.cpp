#include <iostream>
using namespace std;

// 定义树节点的数据类型
typedef char TElemType;

// 定义二叉树节点的结构体
struct BiTNode {
    TElemType data;              // 节点数据
    BiTNode* lchild;             // 指向左孩子的指针
    BiTNode* rchild;             // 指向右孩子的指针

    // 构造函数，用于初始化节点
    BiTNode(TElemType val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

// 定义二叉树指针类型
typedef BiTNode* BiTree;

// 前序遍历递归函数
void PreOrderTraverse(BiTree T) {
    if (T == nullptr) // 如果节点为空，直接返回
        return;

    // 访问当前节点的数据
    cout << T->data << " ";

    // 前序递归遍历左子树
    PreOrderTraverse(T->lchild);

    // 前序递归遍历右子树
    PreOrderTraverse(T->rchild);
}

int main() {
    // 构建一个示例二叉树
    BiTree root = new BiTNode('A'); // 根节点
    root->lchild = new BiTNode('B'); // 左孩子
    root->rchild = new BiTNode('C'); // 右孩子
    root->lchild->lchild = new BiTNode('D'); // 左孩子的左孩子
    root->lchild->rchild = new BiTNode('E'); // 左孩子的右孩子
    root->rchild->rchild = new BiTNode('F'); // 右孩子的右孩子

    // 前序遍历输出
    cout << "前序遍历结果: ";
    PreOrderTraverse(root);
    cout << endl;

    // 清理动态分配的内存
    delete root->lchild->lchild;
    delete root->lchild->rchild;
    delete root->lchild;
    delete root->rchild->rchild;
    delete root->rchild;
    delete root;

    return 0;
}
