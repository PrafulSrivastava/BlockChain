#include <iostream>
#include <memory>
#include <time.h>

template <typename T>
class Node{
public:
    Node(const T& val);
    ~Node() = default;
    long lGetThisHashId() const;
    long lGetLastHashId() const;
    std::shared_ptr<Node> pGetNxtNodePtr() const;
    void vSetNxtNodePtr(const std::shared_ptr<Node> nxt);
    void vSetLastHashId(const long& hash);
    void displayNode();
    void vCalulateHashId();
    T tGetVal();
private:
    T m_value;
    long m_thisNodeHashId;
    long m_lastNodeHashId;
    std::shared_ptr<Node> m_nxtNodePtr;
};

template <typename T>
Node<T>::Node(const T& val){
    m_value = val;
    m_nxtNodePtr = nullptr;
}

template <typename T>
long Node<T>::lGetThisHashId() const {
    return m_thisNodeHashId;
}

template <typename T>
long Node<T>::lGetLastHashId() const {
    return m_lastNodeHashId;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::pGetNxtNodePtr() const{
    return m_nxtNodePtr;
}

template <typename T>
void Node<T>::vSetNxtNodePtr(std::shared_ptr<Node<T>> nxt){
    m_nxtNodePtr = nxt;
}

template <typename T>
void Node<T>::vSetLastHashId(const long& hash){
    m_lastNodeHashId = hash;
}

template <typename T>
T Node<T>::tGetVal(){
    return m_value;
}

template <typename T>
void Node<T>::displayNode(){
    std::cout<<"This Node hash: "<<m_thisNodeHashId<<std::endl;
    std::cout<<"Last Node hash: "<<m_lastNodeHashId<<std::endl;
    std::cout<<"This Node value: "<<m_value<<std::endl;
}

template <typename T>
void Node<T>::vCalulateHashId(){
    srand(time(NULL));
    int random = (rand() + m_value) % 7;
    m_thisNodeHashId = random;
}