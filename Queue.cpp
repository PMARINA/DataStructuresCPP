/*
 * @author: PMARINA
 * @version: 10.03.2019
 * "I pledge my honor that I have abided by the Stevens Honor System."
 * -- PMARINA
*/
#include<iostream>

using namespace std;

class Node{
    public:
        int payload;
        Node *next;
        Node(){
            payload = 0;
            next = NULL;
        }
        
        void setNext(Node *newNext){
            next = newNext;
        }
        void setPayload(int n){
            payload = n;
        }
        Node* getNext(){
            return next;
        }
        int getPayload(){
            return payload;
        }
};

class Queue{
    public:
        Node *head;
        Queue(){
            head = NULL;
        }
        void enqueue(int n){
            Node *newHead = new Node();
            newHead->setPayload(n);
            newHead->setNext(head);
            head = newHead;
            return;
        }
        Node* dequeue(){
            Node *newhead = head;
            Node *toBeDeleted = NULL;
            if(head != NULL && head->getNext()!= NULL){
                while(newhead->getNext()->getNext()!=NULL){
                    newhead = newhead->next;
                    toBeDeleted = newhead->next;
                }
                newhead->setNext(NULL);
                return toBeDeleted;
            }
            if(head!= NULL && head->getNext() == NULL){
                Node *copyhead = head;
                head = NULL;
                return copyhead;
            }
            if(head == NULL){
                return NULL;
            }
        }
        void display(){
            if(head==NULL){
                cout<<"Empty Queue;"<<endl;
                return;
            }
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->getPayload()<<endl;
                temp= temp->getNext();
            }
        }
};

int main(){
    Queue *queue = new Queue();
    cout<<"START"<<endl;
    queue->enqueue(5);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->display();
    queue->dequeue();
    queue->display();
    queue->dequeue();
    queue->display();
    queue->dequeue();
    queue->display();
    return 0;
}
