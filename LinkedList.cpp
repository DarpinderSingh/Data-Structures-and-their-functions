#include <iostream>
using  namespace std;
//Node class Constructor
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this-> value = value;
        next = nullptr;
    }
    
};
//Linked List Constructor
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
//Print List function
void printList(){
    Node* temp = head;
    while (temp != nullptr){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
    }
    //GET Head
    void getHead(){
        cout<<"Head is "<<head->value<<endl;
    }
    //GET Tail
    void getTail(){
        cout<<"Tail is "<<tail->value<<endl;
    }
    //GET Tail
    void getLength(){
        cout<<"Length is "<<length<<endl;
        
    }
    //Append Function
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
 //Delete Last function
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
  //Prepend Function
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
//Delete First Function
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
//Get Node Function
    Node* get(int index){
        Node* temp = head;
        if(index<0||index>=length) return nullptr;
        for(size_t i{0};i<index;i++){
            temp =temp->next;
        }
        return temp;

    }
//Set Function
    bool set(int index, int value){
        Node* temp = get(index);
        if(temp!=nullptr){
            temp->value=value;
            return true;
        }
        return false;

    }
//Insert Function
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
//Delete Node
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
//Destructor
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
    //Object Creation
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(3);
    //Call any function by using myLinkedList(Object name)->function_name();
}

