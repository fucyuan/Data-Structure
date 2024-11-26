#include <iostream>
using namespace std;

// 定义数据类型
typedef char TElemType;

// 定义指针标志（Link 表示指向子节点，Thread 表示指向前驱/后继线索）
enum PointerTag { Link, Thread };

// 定义线索二叉树的节点结构
struct BiThrNode {
    TElemType data;           // 节点数据
    BiThrNode* lchild;        // 左孩子指针
    BiThrNode* rchild;        // 右孩子指针
    PointerTag LTag;          // 左标志，表示指针类型
    PointerTag RTag;          // 右标志，表示指针类型
};

typedef BiThrNode* BiThrTree; // 定义线索二叉树类型

// 示例：创建一个简单的线索二叉树节点
int main() {
    // 创建一个线索二叉树的根节点
    BiThrTree root = new BiThrNode;

    // 初始化根节点数据
    root->data = 'A';
    root->lchild = nullptr;
    root->rchild = nullptr;
    root->LTag = Link;  // 左指针指向子节点
    root->RTag = Link;  // 右指针指向子节点

    // 打印节点信息
    cout << "Root Node Data: " << root->data << endl;
    cout << "LTag: " << (root->LTag == Link ? "Link" : "Thread") << endl;
    cout << "RTag: " << (root->RTag == Link ? "Link" : "Thread") << endl;

    // 释放节点
    delete root;

    return 0;
}
