#include<iostream>
const int n = 10;
using namespace std;

class CircularQ{
    private:
    int a[n];
    //rear tacked insert position for enqueue 
    int rear;
    // front tacked delete position for dequeue  
    int front;
    // count will use to track the number of elements
    int count;
    public:
    CircularQ(){
        rear = -1;
        front = -1;
        count = 0;
    }
    int peek(){
        if(!isempty())
        return a[(front+1)%n];
        else
            cout<< "Queue is empty"<<endl;
        return -1;
    }
    void enqueue(int elt){
        if (!full()) {
            rear ++;
            rear %= n;
            a[rear] = elt;
            count ++;
        }
        else 
        cout<< "Queue is full"<<endl;
        
    }

    void dequeue(){
        if (!isempty()) {
            front ++;
            front %= n;
            count --;
        }
        else
        cout << "Queue is full or no elements in queue";
        
    }
    bool isempty(){
        if (count==0) return 1;
        return 0;
    }

    bool full(){
        if (count == n) return 1;
        return 0;
    }




};

int main(){
    CircularQ pipe;
    //cout<<pipe.isempty();
    ////cout<< pipe.peek();
    for (int i=0 ;i <10;i++)
    pipe.enqueue(i+1);
    //cout<<pipe.peek()<<pipe.isempty()<<pipe.full();
    pipe.dequeue();
    pipe.enqueue(5);
   
    cout<<pipe.peek();
    pipe.dequeue();
    pipe.enqueue(20);
    return 0;
    
}

