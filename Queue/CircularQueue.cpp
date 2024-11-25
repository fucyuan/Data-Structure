#include <iostream>
#define QueueSize 5

class CircularQueue {
private:
    int data[QueueSize];
    int front; // 队列头指针
    int rear;  // 队列尾指针

public:
    CircularQueue() : front(0), rear(0) {}

    // 判断队列是否为空
    bool isEmpty() {
        return front == rear;
    }

    // 判断队列是否已满
    bool isFull() {
        return (rear + 1) % QueueSize == front;
    }

    // 入队操作
    bool enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl;
            return false;
        }
        data[rear] = value;
        rear = (rear + 1) % QueueSize;
        return true;
    }

    // 出队操作
    bool dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return false;
        }
        front = (front + 1) % QueueSize;
        return true;
    }

    // 计算队列长度
    int length() {
        return (rear - front + QueueSize) % QueueSize;
    }

    // 打印队列
    void printQueue() {
        std::cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % QueueSize) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue();
    std::cout << "Queue length: " << q.length() << std::endl;

    q.dequeue();
    q.printQueue();
    std::cout << "Queue length: " << q.length() << std::endl;

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.printQueue();
    std::cout << "Queue length: " << q.length() << std::endl;

    return 0;
}