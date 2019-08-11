//QUEUE IN C++
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* QueuePtr;
void menu(){
	cout<<"***QUEUE***"<<endl;
	cout<<"1. Enqueue"<<endl;
	cout<<"2. Show"<<endl;
	cout<<"3. Dequeue"<<endl;
	cout<<"4. Delete all queue"<<endl;
	cout<<"5. Queue status"<<endl;
	cout<<"6. Front element"<<endl;
	cout<<"7. Back element"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<"Insert an option: ";
}
void insert_queue(QueuePtr &front,QueuePtr &end,int n){
	QueuePtr new_node=new Node();
	new_node->data=n;
	new_node->next=NULL;
	if(front==NULL && end==NULL){
		front=new_node;
		end=new_node;
	}else{
		end->next=new_node;
		end=new_node;
	}
}
void show_queue(QueuePtr front){
	while(front!=NULL){
		cout<<front->data<<" ";
		front=front->next;
	}
}
int delete_element(QueuePtr &front, QueuePtr &end){
	QueuePtr aux=front;
	int n=aux->data;
	if(front->next==NULL){
		front=NULL;
		end=NULL;
	}else{
		front=front->next;
	}
	delete aux;
	return n;
}
void delete_queue(QueuePtr &front, QueuePtr &end){
	while(front!=NULL){
		delete_element(front,end);
	}
}
void front_element(QueuePtr front){
	cout<<"The front element is "<<front->data<<".\n"<<endl;
}
void last_element(QueuePtr end){
	cout<<"The last element is "<<end->data<<".\n"<<endl;
}
int main(){
	QueuePtr front=NULL, end=NULL;
	int option, number;
	do{
		menu();cin>>option;
		switch(option){
			case 1:
				cout<<"\nINSERT"<<endl;
				cout<<"Write the number: ";cin>>number;
				insert_queue(front,end,number);
				cout<<"Number inserted.\n"<<endl;
				break;
			case 2:
				cout<<"\nQUEUE"<<endl;
				if(front==NULL){
					cout<<"Empty queue.\n"<<endl;
				}else{
					show_queue(front);
					cout<<"\n"<<endl;
				}
				break;
			case 3:
				cout<<"\nDELETE ANE ELEMENT"<<endl;
				if(front==NULL){
					cout<<"Empty queue.\n"<<endl;
				}else{
					cout<<"Number "<<delete_element(front,end)<<" was deleted from the queue.\n"<<endl;
				}
				break;
			case 4:
				cout<<"\nDELETE A QUEUE"<<endl;
				if(front==NULL){
					cout<<"Empty queue.\n"<<endl;
				}else{
					delete_queue(front,end);
					cout<<"Queue was deleted.\n"<<endl;
				}
				break;
			case 5:
				cout<<"\nQUEUE STATUS"<<endl;
				if(front==NULL){
					cout<<"Queue is empty.\n"<<endl;
				}else{
					cout<<"Queue is full.\n"<<endl;
				}
				break;
			case 6:
				cout<<"\nFRONT ELEMENT"<<endl;
				if(front==NULL){
					cout<<"Empty queue.\n"<<endl;
				}else{
					front_element(front);
				}
				break;
			case 7:
				cout<<"\nTHE LAST ELEMENT"<<endl;
				if(front==NULL){
					cout<<"Empty queue.\n"<<endl;
				}else{
					last_element(end);
				}
				break;
			case 8:
				cout<<"Thanks..."<<endl;
				break;
			default:
				cout<<"\nInsert a valid option."<<endl;
		}
	}while(option!=8);
}
