#include <iostream>
using  namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this-> value = value;
        next = nullptr;
    }
    
};
class LinkedList {
    private:
    int length;
    Node* head;
    Node* tail;
    public:
    LinkedList(int value){
        Node* newNode= new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;

}
void printList(){
    Node* temp = head;
    while (temp != nullptr){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
    }
    void getHead(){
        cout<<"Head is "<<head->value<<endl;
    }
    void getTail(){
        cout<<"Tail is "<<tail->value<<endl;
    }
    void getLength(){
        cout<<"Length is "<<length<<endl;
        
    }
     void append(int value){
        Node* Newnode = new Node(value);
        if (length == 0){
            head = Newnode;
        tail = Newnode;
        }
        else{
            tail -> next = Newnode;
            tail = Newnode;
        }  
        length++; 
    } 
    void deleteLast(){
        if (length==0) return;
            Node* temp = head;
            Node* pre = head;
            while(temp->next){
                pre = temp;
                temp = temp->next;
               
            }
             tail = pre;
                tail->next = nullptr;
                length--;
                if(length==0){
                    head = nullptr;
                    tail = nullptr;
                }
                delete temp;

        }
      void prepend(int value){
            Node* newNode = new Node (value);
            if(length==0){
                tail = newNode;
                head = newNode;
                }
            else {
                newNode->next = head;
                head = newNode;

            }
            length ++;        
        }
  void Deletefirst(){
            Node* temp = head;
          if(length==0) return ;
          if (length==1){
            head = nullptr;
            tail=nullptr;
          }
          else{
            head= head->next;
            temp->next=nullptr;
            }
            delete temp;
            length--;
          }
    Node* get(int index){
        Node* temp = head;
        if(index<0||index>=length) return nullptr;
        for(size_t i{0};i<index;i++){
            temp =temp->next;
        }
        return temp;

    }
    bool set(int index, int value){
        Node* temp = get(index);
        if(temp!=nullptr){
            temp->value=value;
            return true;
        }
        return false;

    }
    bool insert(int index, int value){
        Node* newNode =new Node(value);
        Node* temp = get(index-1);
        if(index<0||index>length) return false;
        if(index ==0){
            prepend(value);
            return true;
        }
        if(index==length){
            append(value);
            return true;
        }
        else{
           newNode->next= temp->next;
           temp->next = newNode;
           length++;
           return true; 

        }
    }
    void deleteNode(int index){
        if(index<0||index>=length) return ;
        if(index==0){
           return Deletefirst();
        }
        if(index == length -1){
            return deleteLast();
        }
        else{
            Node* pre = get(index-1);
            Node* temp = pre->next;
            pre->next = temp->next;
            delete temp;
            length--;
        }

    }

 ~LinkedList(){
        Node * temp = head;
        while (head!=nullptr){
            head = head->next;
           delete temp;
            temp = head;
           
        }
        }
};
int main(){
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->set(1,6);
    myLinkedList->insert(2,8);
    myLinkedList->printList();
  


}
