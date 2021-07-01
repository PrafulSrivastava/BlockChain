#include <iostream>
#include "Node.hpp"
#include <list>

std::list<std::shared_ptr<Node<int>>> blockChain;
std::shared_ptr<Node<int>> prevNode = nullptr;

void menu(){
    std::cout<<"Enter Choice: 1)Add Node 2) Display Node"<<std::endl;
}

void addNode(){
    int tempVal;   ;
    std::cout<<"Enter Val: ";
    std::cin>>tempVal;
    std::shared_ptr<Node<int>> node(new Node<int>(tempVal));
    node->vCalulateHashId();
    if(prevNode != nullptr){
        node->vSetLastHashId(prevNode->lGetThisHashId());
        node->vSetNxtNodePtr(prevNode);
    }
    prevNode = node;    
    blockChain.emplace_back(node);
    node.reset();
}

void displayChain(){
    for(auto x: blockChain){
        x->displayNode();
    }
}

void createChain(){
    int ch;
    bool running= true;
    while(running){
        menu();
        std::cin>>ch;
        switch(ch){
            case 1: addNode();
            break;
            case 2: displayChain();
            break;
            case 3: running = false;
            break;
        }
    }
}

int main(){
    createChain();
    return 0;
}