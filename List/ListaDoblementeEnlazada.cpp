#include<iostream>
#include<conio.h>
using namespace std;
struct nodo{
	int dato;
	nodo *siguiente;
	nodo *anterior;
};
typedef nodo* Tnodo;
Tnodo lista=NULL;
Tnodo pnodo;
void menu(){
	cout<<"\n***LISTA DOBLEMENTE ENLAZADA***"<<endl;
	cout<<"1. Insertar al inicio."<<endl;
	cout<<"2. Insertar al final"<<endl;
	cout<<"3. Imprimir"<<endl;
	cout<<"4. Insertar despues"<<endl;
	cout<<"5. Eliminar elemento"<<endl;
	cout<<"6. Visitar elemento"<<endl;
	cout<<"7. Número de elementos"<<endl;
	cout<<"8. Buscar elemento"<<endl;
	cout<<"9. Posicion del elemento"<<endl;
	cout<<"10. Salir"<<endl;
	cout<<"Seleccione una opción: ";
}
void insertar_inicio (Tnodo &lista,int dato){
	Tnodo nuevo_nodo=new nodo;
	nuevo_nodo->dato=dato;
	nuevo_nodo->anterior=NULL;
	nuevo_nodo->siguiente=NULL;
	if(lista==NULL){
		lista=nuevo_nodo;
	}else{
		nuevo_nodo->siguiente=lista;
		lista->anterior=nuevo_nodo;
		lista=nuevo_nodo;
	}
}
void insertar_final (Tnodo &lista,int dato){
	Tnodo nuevo_nodo=new nodo;
	nuevo_nodo->dato=dato;
	nuevo_nodo->anterior=NULL;
	nuevo_nodo->siguiente=NULL;
	if(lista==NULL){
		lista=nuevo_nodo;
	}else{
		Tnodo aux=lista;
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo_nodo;
		nuevo_nodo->anterior=aux;
	}
}
void imprimir(Tnodo lista){
	if(lista==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		while(lista!=NULL){
			cout<<"["<<lista->dato<<"]->";
			lista=lista->siguiente;
		}
	}
}
bool buscar(Tnodo lista, int dato){
	Tnodo aux=lista;
	while(aux!=NULL){
		if(aux->dato==dato){
			return true;
			break;
		}
		aux=aux->siguiente;
	}
}
void insertar_despues(Tnodo &lista){
	if(lista==NULL){
		cout<<"NO existe elemento en la lista para ingresar despues de un elemento"<<endl;
	}else{
		int n;
		cout<<"Ingrese el número de la lista";cin>>n;
			if(!buscar(lista,n)){
				cout<<"El número no existe"<<endl;
			}else{
				Tnodo nuevo_nodo=new nodo;
				nuevo_nodo->anterior=NULL;
				nuevo_nodo->siguiente=NULL;
				cout<<"Ingrese el número a agregar: ";cin>>nuevo_nodo->dato;
				Tnodo aux=lista;
				while(aux->dato!=n){
					aux=aux->siguiente;
				}
				if(aux->siguiente==NULL){
					aux->siguiente=nuevo_nodo;
		            nuevo_nodo->anterior=aux;
				}else{
					aux->siguiente->anterior=nuevo_nodo;
					nuevo_nodo->siguiente=aux->siguiente;
					nuevo_nodo->anterior=aux;
					aux->siguiente=nuevo_nodo;
				}
			}
		}
	}
void eliminar_elemento(Tnodo &lista){
	if(lista==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		int n;
		cout<<"Indique el elemento a eliminar:";cin>>n;
		if(!buscar(lista,n)){
			cout<<"El número no existe en la lista"<<endl;
		}else{
			Tnodo aux=lista;
			while(aux->dato!=n){
				aux=aux->siguiente;
			}
			if(aux->anterior==NULL && aux->siguiente==NULL){
				lista=NULL;
				delete aux;
			}else if(aux->siguiente==NULL){
				aux->anterior->siguiente=NULL;
				delete aux;
			}else if(aux->anterior==NULL){
				lista=aux->siguiente;
				lista->anterior=NULL;
				delete aux;
			}else{
				aux->anterior->siguiente=aux->siguiente;
				aux->siguiente->anterior=aux->anterior;
			}
		}
	}
}
void ver_veces(){
	if(lista==NULL){
		cout<<"Lista vacia"<<endl;
	}else{
	    int n;
	    cout<<"Indique el número de veces para ver la lista: ";cin>>n;
	    for(int i=0;i<n;i++){
		    imprimir(lista);
	    }
    }   
}
void numero_elementos(Tnodo lista){
	int n=0;
	if(lista==NULL){
		cout<<"Lista vacia"<<endl;
	}else{
	while(lista!=NULL){
		n++;
		lista=lista->siguiente;
	}
	cout<<"Existen "<<n<<" elementos en la lista"<<endl;
}
}
void buscar_elemento(Tnodo lista){
	if(lista==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		int n;
		cout<<"Ingrese el dato a buscar: ";cin>>n;
		if(!buscar(lista,n)){
			cout<<"El número no existe en la lista"<<endl;
		}else{
			Tnodo aux=lista;
			int c=0;
			while(lista!=NULL){
				if(lista->dato!=n){
					c++;
				}else{
					c++;
					cout<<"El número "<<n<<" se encuentra en la posición "<<c<<endl;
					break;
				}
				lista=lista->siguiente;
			}
		}
	}
}
void posicion_elemento(Tnodo lista){
	if(lista==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		int n;
		cout<<"Ingrese el número a buscar:";cin>>n;
		if(!buscar(lista,n)){
			cout<<"El número no existe en la lista"<<endl;
		}else{
			Tnodo aux=lista;
			Tnodo hultimo=lista;
			int p=1;
			while(lista->dato!=n){
				p++;
				lista=lista->siguiente;
			} 
			while(hultimo->siguiente!=NULL){
				hultimo=hultimo->siguiente;
			}
			int u=1;
			while(hultimo->dato!=n){
				u++;
				hultimo=hultimo->anterior;
			}
			cout<<"El número "<<n<<" se ubica en la posición "<<p<<"con respecto al inicio y en la posición "<<u<<" respecto al final."<<endl;
		}
	}
}
int main(){
	setlocale(LC_ALL,"");
	int opcion;
	int dato;
	do{
		menu();cin>>opcion;
		switch (opcion){
			case 1:
				cout<<"\nINSERTAR AL INICIO"<<endl;
				cout<<"Ingrese el número a insertar: ";cin>>dato;
				insertar_inicio(lista,dato);
				imprimir(lista);
				break;
			case 2:
				cout<<"\nINSERTAR AL FINAL"<<endl;
				cout<<"Ingrese el número a insertar: ";cin>>dato;
				insertar_final(lista,dato);
				imprimir(lista);
				break;
			case 3:
				cout<<"\nIMPRIMIR"<<endl;
				imprimir(lista);
				break;
			case 4:
				cout<<"\nINSERTAR DESPUES"<<endl;
				insertar_despues(lista);
				imprimir(lista);
				break;
			case 5:
				cout<<"\nELIMINAR ELEMENTO"<<endl;
				imprimir(lista);
				cout<<endl;
				eliminar_elemento(lista);
				imprimir(lista);
				break;
			case 6:
				cout<<"\nVISITAR LISTA"<<endl;
				ver_veces();
				break;
			case 7:
				cout<<"\nNÚMERO DE ELEMENTOS"<<endl;
				numero_elementos(lista);
				break;
			case 8:
				cout<<"BUSCAR ELEMENTO"<<endl;
				buscar_elemento(lista);
				break;
			case 9:
				cout<<"POSICION DEL ELEMENTO"<<endl;
				posicion_elemento(lista);
				break;
		}
	}while(opcion!=10);
}

