#include<iostream>
const int n = 10;
using namespace std;
class Que{
    private:
    int a[n];
    int rear,front;
    public:
    Que(){
        rear = -1;
        front = -1;
    }
    int peek(){
        return a[front+1];
    }
    void enqueue(int elt){
        if (full()) {
            cout << "que is full";
            return ;
        }
        a[rear+1] = elt;
        rear ++;
    }

    void dequeue(int elt){
        if (isempty()) {
            cout << "Queue is full or no elements in queue";
            return;
        }
        front ++;
        
    }
    bool isempty(){
        if (front == rear) return 1;
        return 0;
    }

    bool full(){
        if (rear == (n-1)) return 1;
        return 0;
    }




};

int main(){
    Que pipe;
    cout<<pipe.isempty();
    for (int i=0 ;i <11;i++)
    pipe.enqueue(i+1);
    cout<<pipe.peek()<<pipe.isempty()<<pipe.full();
    return 0;
    
}

