#include<iostream>


struct Node{
    int data;
    Node* next;
    Node(int _data, Node* _next = nullptr) : data(_data), next(_next) {}
};

void push_back(Node*& begin, Node*& end, Node* toAdd){
    if(begin == nullptr){
        begin = end = toAdd;
    }
    else{
        end->next = toAdd;
        end = toAdd; // end = end->next
    }
}

template<class Predicate>
Node* partition(Node* list, const Predicate& pred){
    Node* trueBegin = nullptr;
    Node* trueEnd = nullptr;

    Node* falseBegin = nullptr;
    Node* falseEnd = nullptr;

    Node* walk = list;

    while(walk){
        if(pred(walk->data)){
            push_back(trueBegin, trueEnd, walk);
        }
        else{
            // push_back --- false
            push_back(falseBegin, falseEnd, walk);
        }
        walk = walk->next;
    }
    if(falseEnd != nullptr){
        //avoid cycles
        falseEnd->next = nullptr;
    }
    
    
    if(trueEnd != nullptr){
        trueEnd->next = falseBegin;
    }
    
    return trueBegin != nullptr ? trueBegin : falseBegin;
}

void print(Node* ex){
    Node* exCopy = ex;
    while(exCopy != nullptr){
        std::cout << exCopy->data<< "  ";
        exCopy = exCopy->next;
    }
}



void freeList(Node* ex){
    while(ex != nullptr){
        Node* toDelete = ex;
        ex = ex->next;
        delete toDelete;
    }
}

int main(){
    Node* ex = new Node(5, new Node(7, new Node(2, new Node(19, new Node(6)))));
    Node* output = partition(ex, [](int x){return x % 2 == 0;});
    print(output);
    freeList(output);
}