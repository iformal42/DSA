#include<iostream>
using namespace std;

class Animal{
    public:
     virtual void  speak(){
        cout<<"shout";
    }

};

class Dog:public Animal{
    public:
     void  speak(){
        cout<<"bark";
    }

};
class Cat:public Animal{
    public:
     void  speak(){
        cout<<"meow";
    }
};
int main(){
    Animal *p;
    Animal *a[] = {new Dog,new Cat,new Animal};
    
    for(int i=0;i<3;i++){
   
    a[i]->speak();
    }    

}