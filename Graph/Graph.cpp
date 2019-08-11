#include<iostream>
#include<queue>
#include<list>
#include<stack>
using namespace std;
struct arista;
struct nodo{
	char etiqueta;
	arista* ady;
	nodo* sgte;
};
struct arista{
	nodo* destino;
	arista* sgte;
};
typedef nodo* Tnodo;
typedef arista* Tarista;
char ni,nf,ni2,nf2;
void menu(){
	cout<<"***GRAFOS***"<<endl;
	cout<<"1. Insertar nodo"<<endl;
	cout<<"2. Insertar arista"<<endl;
	cout<<"3. Mostrar grafo"<<endl;
	cout<<"4. Lista de adyacencia de un nodo"<<endl;
	cout<<"5. Grafo dirigido o no"<<endl;
	cout<<"6. Grado de un nodo"<<endl;
	cout<<"7. Recorrido profundidad"<<endl;
	cout<<"8. Recorrido anchura"<<endl;
	cout<<"9. Camino entre nodos"<<endl;
	cout<<"10. Salir"<<endl;
	cout<<"Ingrese una opción: ";
}
void insertar_nodo(Tnodo& grafo, char dato){
	Tnodo nuevo=new nodo();
	nuevo->etiqueta=dato;
	nuevo->ady=NULL;
	nuevo->sgte=NULL;
	if(grafo==NULL){
		grafo=nuevo;
	}else{
		Tnodo aux=grafo;
		while(aux->sgte!=NULL){
			aux=aux->sgte;
		}
		aux->sgte=nuevo;
	}
}
bool busqueda(Tnodo grafo, char dato){
	while(grafo!=NULL){
		if(grafo->etiqueta==dato){
			return true;
		}
		grafo=grafo->sgte;
	}
}
void agregar_arista(Tnodo &aux, Tnodo &aux2, Tarista nuevo_arista){
	if(aux->ady==NULL){
		aux->ady=nuevo_arista;
		nuevo_arista->destino=aux2;
		cout<<"Primera arista.\n"<<endl;
	}else{
		Tarista temp=aux->ady;
		while(temp->sgte!=NULL){
			temp=temp->sgte;
		}
		nuevo_arista->destino=aux2;
		temp->sgte=nuevo_arista;
		cout<<"Arista agregado.\n"<<endl;
	}
}
void insertar_arista(Tnodo& grafo){
	Tarista nuevo_arista=new arista();
	do{
		cout<<"Nodo inicial: ";cin>>ni;
		if(busqueda(grafo,ni)==false){
			cout<<"Nodo no existe, vuelva a ingresar"<<endl;
		}
	}while(busqueda(grafo,ni)==false);
	do{
		cin.ignore();
		cout<<"Nodo Final: ";cin>>nf;
		if(busqueda(grafo,nf)==false){
			cout<<"Nodo no existe, vuelva a ingresar"<<endl;
		}
	}while(busqueda(grafo,nf)==false);
	Tnodo aux=grafo,aux2=grafo;
	while(aux2!=NULL){
		if(aux2->etiqueta==nf){
			break;
		}
		aux2=aux2->sgte;
	}
	while(aux!=NULL){
		if(aux->etiqueta==ni){
			agregar_arista(aux,aux2,nuevo_arista);
		}
		aux=aux->sgte;
	}
}
void Mostrar(Tnodo grafo){
	cout<<"Nodo | Lista de adyacencia"<<endl;
	while(grafo!=NULL){
		cout<<"   "<<grafo->etiqueta<<" | ";
		Tarista aux=grafo->ady;
		while(aux!=NULL){
			cout<<aux->destino->etiqueta<<" ";
			aux=aux->sgte;
		}
		cout<<endl;
		grafo=grafo->sgte;
	}
}
void adyacencia_nodo(Tnodo grafo, char dato){
	Tnodo aux=grafo;
	while(aux!=NULL){
		if(aux->etiqueta==dato){
			break;
		}
		aux=aux->sgte;
	}
	cout<<"Nodo | Lista de adyacencia"<<endl;
	cout<<"   "<<aux->etiqueta<<" | ";
	Tarista temp=aux->ady;
	while(temp!=NULL){
		cout<<temp->destino->etiqueta<<" ";
		temp=temp->sgte;
	}
	cout<<endl;
}
bool nodo_conectado(Tnodo aux,Tnodo aux2){
	Tarista temp=aux->ady;
	while(temp!=NULL){
		if(temp->destino==aux2){
			return true;
		}
		temp=temp->sgte;
	}
}
void dirigido_no(Tnodo grafo){
	Tnodo aux=grafo,aux2=grafo->sgte;
	bool validar;
	while(aux2!=NULL){
		if(nodo_conectado(aux,aux2) && nodo_conectado(aux2,aux)){
			validar=true;
		}
		aux=aux->sgte;
		aux2=aux->sgte;
	}
	if(validar==true){
		cout<<"Grafo no dirigido.\n"<<endl;
	}else{
		cout<<"Grafo dirigido.\n"<<endl;
	}
}
int grado_entrada(Tnodo grafo,char dato){
	Tnodo aux=grafo;
	int cont=0;
	while(aux!=NULL){
		Tarista temp=aux->ady;
		while(temp!=NULL){
			if(temp->destino->etiqueta==dato){
				cont++;
			}
			temp=temp->sgte;
		}
		aux=aux->sgte;
	}
	return cont;
}
int grado_salida(Tnodo grafo, char dato){
	Tnodo aux=grafo;
	int cont=0;
	while(aux!=NULL){
		if(aux->etiqueta==dato){
			Tarista temp=aux->ady;
			while(temp!=NULL){
				cont++;
				temp=temp->sgte;
			}
			break;
		}
		aux=aux->sgte;
	}
	return cont;
}
void grado_nodo(Tnodo grafo,char dato){
	cout<<"Grado del nodo: "<<grado_entrada(grafo,dato)+grado_salida(grafo,dato)<<endl;
	cout<<"Grado de entrada: "<<grado_entrada(grafo,dato)<<endl;
	cout<<"Grado de salida: "<<grado_salida(grafo,dato)<<endl;
}
void recorrido_anchura(Tnodo grafo){
	int band,band2;
	Tnodo actual;
	queue<Tnodo>cola;
	list<Tnodo>lista;
	list<Tnodo>::iterator i;
	cola.push(grafo);
	while(!cola.empty()){
		band=0;
		actual=cola.front();
		cola.pop();
		for(i=lista.begin();i!=lista.end();i++){
			if(*i==actual){
				band=1;
			}
		}
		if(band==0){
			cout<<actual->etiqueta<<", ";
			lista.push_back(actual);
			Tarista aux=actual->ady;
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin();i!=lista.end();i++){
					if(aux->destino==*i){
						band2=1;
					}
				}
				if(band2==0){
					cola.push(aux->destino);
				}
				aux=aux->sgte;
			}
		}
	}
}
void recorrido_profundidad(Tnodo grafo){
	stack<Tnodo>pila;
	list<Tnodo>listar;
	list<Tnodo>::iterator i;
	int band,band2;
	Tnodo actual;
	pila.push(grafo);
	while(!pila.empty()){
		band=0;
		actual=pila.top();
		pila.pop();
		for(i=listar.begin();i!=listar.end();i++){
			if(*i==actual){
				band=1;
			}
		}
		if(band==0){
			cout<<actual->etiqueta<<"; ";
			listar.push_back(actual);
			Tarista aux=actual->ady;
		while(aux!=NULL){
			band2=0;
			for(i=listar.begin();i!=listar.end();i++){
				if(*i==aux->destino){
					band2=1;
				}
			}
			if(band2==0){
				pila.push(aux->destino);
			}
			aux=aux->sgte;
		}
		}
	}
}
void camino_nodos(Tnodo grafo){
	do{
		cin.ignore();
		cout<<"Nodo inicial: ";cin>>ni2;
		if(busqueda(grafo,ni2)==false){
			cout<<"Nodo no existe, vuelva a ingresar"<<endl;
		}
	}while(busqueda(grafo,ni2)==false);
	do{
		cin.ignore();
		cout<<"Nodo Final: ";cin>>nf2;
		if(busqueda(grafo,nf2)==false){
			cout<<"Nodo no existe, vuelva a ingresar"<<endl;
		}
	}while(busqueda(grafo,nf2)==false);
	Tnodo aux=grafo,aux2=grafo;
	while(aux!=NULL){
		if(aux->etiqueta==ni2){
			break;
		}
		aux=aux->sgte;
	}
	while(aux2!=NULL){
		if(aux2->etiqueta==nf2){
			break;
		}
		aux2=aux2->sgte;
	}
	bool value=nodo_conectado(aux,aux2);
	if(value){
		cout<<"Existe un camino entre los nodos"<<endl;
	}else{
		cout<<"No existe un camino entre los nodos"<<endl;
	}
}
int main(){
	setlocale(LC_ALL,"");
	Tnodo grafo=NULL;
	int op;
	char dato;
	do{
		menu();cin>>op;
		switch(op){
			case 1:
				cout<<"\nINSERTAR NODO"<<endl;
				do{
					cout<<"Ingrese etiqueta: ";cin>>dato;
					if(grafo!=NULL && busqueda(grafo,dato)==true){
						cout<<"El nodo ya existe, ingrese uno distinto"<<endl;
					}
				}while(grafo!=NULL && busqueda(grafo,dato)==true);
				insertar_nodo(grafo,dato);
				break;
			case 2:
				cout<<"\nINSERTAR ARISTA"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					insertar_arista(grafo);
				}
				break;
			case 3:
				cout<<"\nGRAFO"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					Mostrar(grafo);
				}
				break;
			case 4:
				cout<<"Lista de adyancencia de un nodo"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					do{
						cout<<"Indique el nodo: ";cin>>dato;
						if(busqueda(grafo,dato)==false){
							cout<<"El nodo no existe, vuelva a ingresar."<<endl;
						}else{
							adyacencia_nodo(grafo,dato);
						}
					}while(busqueda(grafo,dato)==false);
				}
				break;
			case 5:
				cout<<"\nGrafo dirigido o no"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío"<<endl;
				}else{
					dirigido_no(grafo);
				}
				break;
			case 6:
				cout<<"\nGrado de un nodo"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					do{
						cout<<"Indique el nodo: ";cin>>dato;
						if(busqueda(grafo,dato)==false){
							cout<<"El nodo no existe, ingrese un nodo válido.\n"<<endl;
						}
					}while(busqueda(grafo,dato)==false);
					grado_nodo(grafo,dato);
				}
				break;
			case 7:
				cout<<"Recorrido profundidad"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					recorrido_profundidad(grafo);
				}
				break;
			case 8:
				cout<<"Recorrido anchura"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacío.\n"<<endl;
				}else{
					recorrido_anchura(grafo);
				}
				break;
			case 9:
				cout<<"\nCamino entre nodos"<<endl;
				if(grafo==NULL){
					cout<<"Grafo vacio"<<endl;
				}else{
					camino_nodos(grafo);
				}
				break;
			case 10:
				cout<<"Gracias..."<<endl;
				break;
			default:
				cout<<"Ingrese una opción válida.\n"<<endl;
		}
	}while(op!=10);
}
