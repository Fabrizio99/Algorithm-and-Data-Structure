#include<iostream>
using namespace std;
struct Nodo{
	int dato;
	Nodo* der;
	Nodo* izq;
};
struct NodoCola{
	Nodo* ptr;
	NodoCola* sgte;
};
struct Cola{
	NodoCola* ant;
	NodoCola* post;
};
typedef Nodo* ABinario;
void menu(){
	cout<<"***ARBOL BINARIO***"<<endl;
	cout<<"1. Insertar"<<endl;
	cout<<"2. Mostrar"<<endl;
	cout<<"3. Recorrido preorden"<<endl;
	cout<<"4. Recorrido inorden"<<endl;
	cout<<"5. Recorrido posorden"<<endl;
	cout<<"6. Recorrido por anchura"<<endl;
	cout<<"7. Profundidad del arbol"<<endl;
	cout<<"8. Máximo valor del arbol"<<endl;
	cout<<"9. Mínimo valor del arbol"<<endl;
	cout<<"10. Tamaño del arbol"<<endl;
	cout<<"11. Hojas del arbol"<<endl;
	cout<<"12. Busqueda de un valor"<<endl;
	cout<<"13. Salir"<<endl;
	cout<<"Ingrese una opción:";
}
ABinario crear_nodo(int n){
	ABinario nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->der=NULL;
	return nuevo_nodo;
}
ABinario insertar_nodo(ABinario &arbol, int n){
	if(arbol==NULL){
		arbol=crear_nodo(n);
		cout<<"Dato insertado\n"<<endl;
	}else{
		if(n<arbol->dato){
			insertar_nodo(arbol->izq,n);
		}else{
			insertar_nodo(arbol->der,n);
		}
	}
}
void mostrar_arbol(ABinario arbol, int n){
	if(arbol==NULL){
		return;
	}else{
		mostrar_arbol(arbol->der,n+1);
		for(int i=0;i<n;i++){
			cout<<"  ";
		}
		cout<<arbol->dato<<endl;
		mostrar_arbol(arbol->izq,n+1);
	}
}
int profundidad_arbol(ABinario arbol){
	int profiz, profder;
	if(arbol==NULL){
		return 0;
	}else{
		profiz=profundidad_arbol(arbol->izq);
		profder=profundidad_arbol(arbol->der);
		if(profiz>profder){
			return profiz+1;
		}else{
			return profder+1;
		}
	}
}
bool buscar_dato(ABinario arbol, int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->dato==n){
		return true;
	}else if(n<arbol->dato){
		return buscar_dato(arbol->izq,n);
	}else if(n>arbol->dato){
		return buscar_dato(arbol->der,n);
	}
}
void recorrido_preorden(ABinario arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato<<" ";
		recorrido_preorden(arbol->izq);
		recorrido_preorden(arbol->der);
	}
}
void recorrido_inorden(ABinario arbol){
	if(arbol==NULL){
		return;
	}else{
		recorrido_inorden(arbol->izq);
		cout<<arbol->dato<<" ";
		recorrido_inorden(arbol->der);
	}
}
void recorrido_posorden(ABinario arbol){
	if(arbol==NULL){
		return;
	}else{
		recorrido_inorden(arbol->izq);
		recorrido_inorden(arbol->der);
		cout<<arbol->dato<<" ";
	}
}
void inicializar_cola_anchura(Cola &q){
	q.ant=NULL;
	q.post=NULL;
}
void encolar_anchura(Cola &q, ABinario arbol){
	NodoCola* p=new NodoCola();
	p->ptr=arbol;
	p->sgte=NULL;
	if(q.post==NULL){
		q.post=p;
	}else{
		q.ant->sgte=p;
	}
	q.ant=p;
}
ABinario desencolar_anchura(Cola &q){
	NodoCola* r;
	r=q.post;
	ABinario n=r->ptr;
	q.post=q.post->sgte;
	delete r;
	return n;
}
void recorrer_anchura(ABinario arbol){
	Cola q;
	inicializar_cola_anchura(q);
	if(arbol!=NULL){
		encolar_anchura(q,arbol);
		while(q.post!=NULL){
			arbol=desencolar_anchura(q);
			cout<<arbol->dato<<" ";
			if(arbol->izq!=NULL){
				encolar_anchura(q,arbol->izq);
			}
			if(arbol->der!=NULL){
				encolar_anchura(q,arbol->der);
			}
		}
	}
}
int maximo_arbol(ABinario arbol){
	if(arbol->der==NULL){
		return arbol->dato;
	}else{
		maximo_arbol(arbol->der);
	}
}
int minimo_arbol(ABinario arbol){
	if(arbol->izq==NULL){
		return arbol->dato;
	}else{
		minimo_arbol(arbol->izq);
	}
}
int tamano_arbol(ABinario arbol){
	if(arbol==NULL){
		return 0;
	}else{
		return 1+tamano_arbol(arbol->izq)+tamano_arbol(arbol->der);
	}
}
void mostrar_hoja(ABinario arbol){
	if(arbol->izq==NULL && arbol->der==NULL){
		cout<<arbol->dato<<" ";
	}else if(arbol->izq==NULL){
		mostrar_hoja(arbol->der);
	}else if(arbol->der==NULL){
		mostrar_hoja(arbol->izq);
	}else{
		mostrar_hoja(arbol->izq);
		mostrar_hoja(arbol->der);
	}
}
void buscar_camino(ABinario arbol, int n){
	if(arbol==NULL){
		cout<<"";
	}else if(arbol->dato==n){
		cout<<arbol->dato<<"\n"<<endl;
	}else if(n<arbol->dato){
		cout<<arbol->dato<<" ";
		buscar_camino(arbol->izq,n);
	}else if(n>arbol->dato){
		cout<<arbol->dato<<" ";
		buscar_camino(arbol->der,n);
	}
}
int main(){
	setlocale(LC_ALL,"");
	ABinario arbol=NULL;
	int opcion, n;
	do{
		menu();cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"\nINSERTAR"<<endl;
				bool ver;
				do{
					cout<<"Ingrese el dato:";cin>>n;
					if(buscar_dato(arbol,n)){
						ver=true;
					}else{
						ver=false;
					}
				}while(ver==true);
				insertar_nodo(arbol,n);
				break;
			case 2:
				cout<<"\nMOSTRAR"<<endl;
				if(arbol==NULL){
					cout<<"No existes elementos para mostrar\n"<<endl;
				}else{
					mostrar_arbol(arbol,0);
				}
				break;
			case 3:
				cout<<"\nRECORRIDO PREORDEN"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos para recorrer"<<endl;
				}else{
					recorrido_preorden(arbol);
					cout<<"\n"<<endl;
				}
				break;
			case 4:
				cout<<"\nRECORRIDO INORDEN"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos para recorrer"<<endl;
				}else{
					recorrido_inorden(arbol);
					cout<<"\n"<<endl;
				}
				break;
			case 5:
				cout<<"\nRECORRIDO POSORDEN"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos para recorrer"<<endl;
				}else{
					recorrido_posorden(arbol);
				}
				cout<<"\n"<<endl;
				break;
			case 6:
				cout<<"\nRECORRIDO POR ANCHURA"<<endl;
				if(arbol==NULL){
					cout<<"Ningún elemento por recorrer"<<endl;
				}else{
					recorrer_anchura(arbol);
				}
				cout<<"\n"<<endl;
				break;
			case 7:
				cout<<"\nPROFUNDIDAD DEL ARBOL"<<endl;
				cout<<"El arbol tiene una profundidad de "<<profundidad_arbol(arbol)<<".\n"<<endl;
				break;
			case 8:
				cout<<"\nMÍXIMO VALOR DEL ARBOL"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos.\n"<<endl;
				}else{
					cout<<"EL valor máximo del arbol es "<<maximo_arbol(arbol)<<".\n"<<endl;
				}
				break;
			case 9:
				cout<<"\nMÍNIMO VALOR DEL ARBOL"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos.\n"<<endl;
				}else{
					cout<<"EL valor mínimo del arbol es "<<minimo_arbol(arbol)<<".\n"<<endl;
				}
				break;
			case 10:
				cout<<"\nTAMAÑO DEL ARBOL"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos.\n"<<endl;
				}else{
					cout<<"EL tamaño del arbol es "<<tamano_arbol(arbol)<<".\n"<<endl;
				}
				break;
			case 11:
				cout<<"\nHOJAS DEL ARBOL"<<endl;
				if(arbol==NULL){
					cout<<"No existen elementos.\n"<<endl;
				}else{
					mostrar_hoja(arbol);
					cout<<"\n"<<endl;
				}
				break;
			case 12:
				cout<<"\nBUSCAR ELEMENTO"<<endl;
				cout<<"Indique el elemento:";cin>>n;
				if(buscar_dato(arbol,n)){
					cout<<"El elemento "<<n<<" existe en la lista.\nRuta: "<<endl;
					buscar_camino(arbol,n);
				}else{
					cout<<"Elemento no encontrado.\n"<<endl;
				}
				break;
			case 13:
				cout<<"Gracias..."<<endl;
				break;
			default:
				cout<<"Ingrese una opción válida.\n"<<endl;
		}
	}while(opcion!=13);
}
