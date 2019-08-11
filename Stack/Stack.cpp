//Stack c++
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* StackPtr;
struct Node2{
	int data2;
	Node2* next2;
};
typedef Node2* StackPtr2;
StackPtr2 stack2=NULL;
void menu(){
	cout<<"***STACKS***"<<endl;
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Show stack"<<endl;
	cout<<"4. Destroy stack"<<endl;
	cout<<"5. Unstack any data"<<endl;
	cout<<"6. Destroy even numbers"<<endl;
	cout<<"7. Transferring to another stack"<<endl;
	cout<<"8. Inserting with factorial"<<endl;
	cout<<"9. Hanoi Tower"<<endl;
	cout<<"10. Exit"<<endl;
	cout<<"Insert an option:";
}
void inserting_element(StackPtr &stack, int number){
	StackPtr new_stack=new Node();
	new_stack->data=number;
	new_stack->next=stack;
	stack=new_stack;
}
bool search_number(StackPtr stack, int number){
	while(stack!=NULL){
		if(stack->data==number){
			return true;
		}
		stack=stack->next;
	}
}
int deleting_element(StackPtr &stack){
	StackPtr aux=stack;
	stack=stack->next;
	int n=aux->data;
	delete aux;
	return n;
}
void show_list(StackPtr stack){
	while(stack!=NULL){
		cout<<stack->data<<endl;
		stack=stack->next;
	}
}
void destroy_stack(StackPtr &stack){
	while(stack!=NULL){
		StackPtr aux=stack;
		stack=stack->next;
		delete aux;
	}
}
void inserting_stack2(StackPtr2 &stack2, int number){
	StackPtr2 new_stack=new Node2();
	new_stack->data2=number;
	new_stack->next2=stack2;
	stack2=new_stack;
}
void destroy_stack2(StackPtr2 &stack2){
	while(stack2!=NULL){
		StackPtr2 aux=stack2;
		stack2=stack2->next2;
		delete aux;
	}
}
void unstack_data(StackPtr &stack, int number){
	StackPtr aux=stack;
	while(aux!=NULL){
		if(aux->data!=number){
			inserting_stack2(stack2,aux->data);
		}
		aux=aux->next;
	}
	destroy_stack(stack);
	StackPtr2 aux2=stack2;
	while(aux2!=NULL){
		inserting_element(stack,aux2->data2);
		aux2=aux2->next2;
	}
	destroy_stack2(stack2);
}
void destroy_even_number(StackPtr &stack){
	StackPtr aux=stack;
	while(aux!=NULL){
		if(aux->data%2!=0){
			inserting_stack2(stack2,aux->data);
		}
		aux=aux->next;
	}
	destroy_stack(stack);
	StackPtr2 aux2=stack2;
	while(aux2!=NULL){
		inserting_element(stack,aux2->data2);
		aux2=aux2->next2;
	}
	destroy_stack2(stack2);
}
void show_stack2(StackPtr2 stack2){
	while(stack2!=NULL){
		cout<<stack2->data2<<endl;
		stack2=stack2->next2;
	}
}
void transferring_stack(StackPtr stack){
	while(stack!=NULL){
		inserting_stack2(stack2,stack->data);
		stack=stack->next;
	}
	show_stack2(stack2);
	destroy_stack2(stack2);
}
int factorial(int n){
	if(n==0 || n==1){
		return 1;
	}else{
		return n*factorial(n-1);
	}
}
void inserting_factorial(StackPtr &stack, int number){
	for(int i=1;i<=number;i++){
		inserting_element(stack,factorial(i));
	}
}
StackPtr StackA=NULL, StackB=NULL, StackC=NULL;
void fill_data(int n){
	inserting_element(StackA,n);
	if(n!=1){
		fill_data(n-1);
	}
}
void hanoi_tower(StackPtr &StackA, StackPtr &StackC,StackPtr &StackB, char A,char C,char B, int n){
	if(n==1){
		deleting_element(StackA);
		cout<<"Moving the number "<<n<<" from "<<A<<" to "<<C<<endl;
		inserting_element(StackC,n);
	}else{
		hanoi_tower(StackA,StackB,StackC,A,B,C,n-1);
		deleting_element(StackA);
		cout<<"Moving the number "<<n<<" from "<<A<<" to "<<C<<endl;
		inserting_element(StackC,n);
		hanoi_tower(StackB,StackC,StackA,B,C,A,n-1);
	}
}
int main(){
	setlocale(LC_ALL,"");
	StackPtr stack=NULL;
	int option;
	int number;
	do{
		menu();cin>>option;
		switch(option){
			case 1:
				cout<<"\nINSERTING AN ELEMENT"<<endl;
				cout<<"Insert the numer: ";cin>>number;
				inserting_element(stack,number);
				cout<<"Number inserted.\n"<<endl;
				break;
			case 2:
				cout<<"\nDELETING AN ELEMENT"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
						cout<<"The number "<<deleting_element(stack)<<" was deleted from the stack.\n"<<endl;
				}
				break;
			case 3:
				cout<<"\nSHOW STACK"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
					show_list(stack);
					cout<<"\n"<<endl;
				}
				break;
			case 4:
				cout<<"\nDESTROY STACK"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
					destroy_stack(stack);
					cout<<"Stack destroyed.\n"<<endl;
				}
				break;
			case 5:
				cout<<"\nUNSTACK ANY DATA"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
					cout<<"Insert the number to unstack: ";cin>>number;
					if(!search_number(stack,number)){
						cout<<"Number doesn´t exist in the stack"<<endl;
					}else{
						unstack_data(stack,number);
						cout<<"Number destroyed"<<endl;
					}
				}
				break;
			case 6:
				cout<<"\nDESTROY EVEN NUMBERS"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
					destroy_even_number(stack);
					cout<<"Even numbers were destroyed.\n"<<endl;
				}
				break;
			case 7:
				cout<<"\nTRASNFERRING TO ANOTHER STACK"<<endl;
				if(stack==NULL){
					cout<<"Empty stack.\n"<<endl;
				}else{
					transferring_stack(stack);
					cout<<"\n"<<endl;
				}
				break;
			case 8:
				cout<<"\nINSERTING WITH FACTORIAL"<<endl;
				cout<<"Write the number of the factorial: ";cin>>number;
				inserting_factorial(stack,number);
				cout<<"Numbers were added by factorial.\n"<<endl;
				break;
			case 9:
				cout<<"\nHANOI TOWER"<<endl;
				cout<<"Write the number discs: ";cin>>number;
				fill_data(number);
				cout<<"\nStack A:"<<endl;
				show_list(StackA);
				hanoi_tower(StackA,StackC,StackB,'A','C','B',number);
				cout<<"\n"<<endl;
				break;
			case 10:
				cout<<"\nThanks..."<<endl;
				break;
			default:
				cout<<"\nInsert a valid option.\n"<<endl;
		}
	}while(option!=10);
}
