#include <iostream>
#include <cstdlib> // for exit
using namespace std;

// 定义二叉树节点结构
struct BiTNode {
    char data;            // 数据域，存储节点值
    BiTNode* lchild;      // 左子节点指针
    BiTNode* rchild;      // 右子节点指针
};

typedef BiTNode* BiTree;  // 定义二叉树指针类型

// 全局变量，模拟输入序列
string input; // 输入的字符串序列，例如 "ABC##D##E##"
int index = 0; // 当前输入序列的位置索引

// 构造二叉树的函数
void CreateBiTree(BiTree& T) {
    char ch;
    
    // 读取当前字符
    if (index >= input.size()) return; // 防止越界
    ch = input[index++];
    
    // 如果当前字符是 '#'，表示空节点
    if (ch == '#') {
        T = nullptr; // 空节点
    } else {
        // 创建新的节点
        T = new BiTNode;
        if (!T) {
            cerr << "Memory allocation failed!" << endl;
            exit(EXIT_FAILURE); // 内存分配失败时退出程序
        }
        T->data = ch;             // 节点数据赋值
        CreateBiTree(T->lchild);  // 构造左子树
        CreateBiTree(T->rchild);  // 构造右子树
    }
}

// 中序遍历函数
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild); // 遍历左子树
        cout << T->data << " ";     // 访问根节点
        InOrderTraverse(T->rchild); // 遍历右子树
    }
}

// 主函数
int main() {
    BiTree T = nullptr; // 初始化二叉树

    // 输入节点序列，例如 "ABC##D##E##"
    cout << "Enter the node sequence (e.g., 'ABC##D##E##'): ";
    cin >> input;

    // 构造二叉树
    CreateBiTree(T);

    // 输出中序遍历结果
    cout << "In-order traversal of the binary tree: ";
    InOrderTraverse(T);
    cout << endl;

    return 0;
}
