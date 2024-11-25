#include <iostream>

// 定义树节点的数据类型（可以根据需要更改）
typedef int TElemType; 

// 定义二叉树节点的结构体
struct BiTNode {
    TElemType data;              // 节点数据
    BiTNode* lchild;             // 指向左孩子的指针
    BiTNode* rchild;             // 指向右孩子的指针

    // 构造函数，用于初始化节点
    BiTNode(TElemType val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

// 定义一个二叉树节点的指针类型，方便后续使用
typedef BiTNode* BiTree;

int main() {
    // 创建一个二叉树节点的示例
    BiTree root = new BiTNode(10); // 创建根节点，值为10
    root->lchild = new BiTNode(5); // 创建左孩子节点，值为5
    root->rchild = new BiTNode(15); // 创建右孩子节点，值为15

    // 打印二叉树结构
    std::cout << "根节点: " << root->data << std::endl;
    if (root->lchild)
        std::cout << "左孩子: " << root->lchild->data << std::endl;
    if (root->rchild)
        std::cout << "右孩子: " << root->rchild->data << std::endl;

    // 释放内存（删除节点）
    delete root->lchild;
    delete root->rchild;
    delete root;

    return 0;
}
