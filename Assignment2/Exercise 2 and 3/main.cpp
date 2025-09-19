#include "stack.hpp"
#include "queue.hpp"

int main() {
    //TEST 1 for exercise 2
    Stack<int> s;
    cout<<"Test123"<<endl;
    for (int i = 0; i <= 100; i++){
        s.push(i);
    }
    cout << "Top: " << s.top() << endl; // should print 20
    s.pop();
    s.top();
    s.capacity();
    s.size();

    //TEST 2 for exercise 3
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.empty();
    return 0;
}
