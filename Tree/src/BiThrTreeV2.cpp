#include <iostream>
using namespace std;

// 定义二叉线索树节点
struct BiThrNode {
    char data;           // 节点数据
    BiThrNode* lchild;   // 左孩子指针
    BiThrNode* rchild;   // 右孩子指针
    int LTag;            // 左标志（0: 指向孩子，1: 指向前驱）
    int RTag;            // 右标志（0: 指向孩子，1: 指向后继）
};

typedef BiThrNode* BiThrTree;

BiThrTree pre = nullptr; // 全局变量，指向当前节点的前驱

// 中序遍历进行中序线索化
void InThreading(BiThrTree p) {
    if (p) {
        // 递归线索化左子树
        InThreading(p->lchild);

        // 如果没有左孩子
        if (!p->lchild) {
            p->LTag = 1;        // 标记为前驱线索
            p->lchild = pre;    // 左孩子指向前驱
        }

        // 如果前驱没有右孩子
        if (pre && !pre->rchild) {
            pre->RTag = 1;      // 标记为后继线索
            pre->rchild = p;    // 前驱的右孩子指向当前节点
        }

        pre = p; // 更新前驱为当前节点

        // 递归线索化右子树
        InThreading(p->rchild);
    }
}

// 创建一个简单二叉树（示例）
void CreateSimpleTree(BiThrTree& T) {
    T = new BiThrNode{'A', nullptr, nullptr, 0, 0};
    T->lchild = new BiThrNode{'B', nullptr, nullptr, 0, 0};
    T->rchild = new BiThrNode{'C', nullptr, nullptr, 0, 0};
    T->lchild->lchild = new BiThrNode{'D', nullptr, nullptr, 0, 0};
    T->lchild->rchild = new BiThrNode{'E', nullptr, nullptr, 0, 0};
    T->rchild->rchild = new BiThrNode{'F', nullptr, nullptr, 0, 0};
}

// 中序遍历线索二叉树
void InOrderTraverse(BiThrTree T) {
    BiThrTree p = T;
    while (p) {
        // 找到第一个中序节点
        while (p->LTag == 0) p = p->lchild;

        cout << p->data << " "; // 访问当前节点

        // 按后继线索遍历
        while (p->RTag == 1) {
            p = p->rchild;
            cout << p->data << " ";
        }

        // 转向右子树
        p = p->rchild;
    }
}

int main() {
    BiThrTree T = nullptr; // 初始化二叉树
    CreateSimpleTree(T);   // 创建简单二叉树

    // 对二叉树进行中序线索化
    pre = nullptr;         // 初始化前驱指针
    InThreading(T);

    // 遍历线索化后的二叉树
    cout << "In-order traversal of the threaded binary tree: ";
    InOrderTraverse(T);
    cout << endl;

    return 0;
}
