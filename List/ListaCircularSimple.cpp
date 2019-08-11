#include<iostream>
#include<conio.h>
using namespace std;
struct nodo{
	int dato;
	nodo *sgte;
};
typedef nodo *Tnodo;
Tnodo cabeza=NULL,cola=NULL;
void menu();
void insertar_inicio(Tnodo &, Tnodo &, int);
void insertar_final(Tnodo &, Tnodo &, int);
void mostrar_lista(Tnodo);
void contar_elementos(Tnodo);
bool encontrar(Tnodo,int);
void buscar_elemento(Tnodo,int);
void eliminar_elemento(Tnodo &, Tnodo &,int);
void metodo_visitar(Tnodo, int);
void posicion_elemento(Tnodo, Tnodo, int);
void insertar_despues(Tnodo &, Tnodo &,int,int);
void fuera_rango();
int main(){
	setlocale(LC_ALL,"");
	int opcion;
	int dato;
	do{
		menu();cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
				cout<<"INSERTAR INICIO"<<endl;
				cout<<"Ingrese número: ";cin>>dato;
				insertar_inicio(cabeza,cola,dato);
				mostrar_lista(cabeza);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout<<"INSERTAR FINAL"<<endl;
				cout<<"Ingrese número: ";cin>>dato;
				insertar_final(cabeza,cola,dato);
				mostrar_lista(cabeza);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				cout<<"MOSTRAR LISTA"<<endl;
				mostrar_lista(cabeza);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				contar_elementos(cabeza);
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				cout<<"BUSCAR ELEMENTO"<<endl;
				mostrar_lista(cabeza);
				cout<<""<<endl;
				cout<<"Ingrese el número a buscar: ";cin>>dato;
				buscar_elemento(cabeza,dato);
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				cout<<"ELIMINAR ELEMENTO"<<endl;
				mostrar_lista(cabeza);
				cout<<""<<endl;
				cout<<"Ingrese el número a eliminar: ";cin>>dato;
				eliminar_elemento(cabeza,cola,dato);
				mostrar_lista(cabeza);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				cout<<"METODO DE VISITAR"<<endl;
				cout<<"Indique la cantidad de veces: ";cin>>dato;
				metodo_visitar(cabeza,dato);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				cout<<"POSICION DEL NÚMERO"<<endl;
				mostrar_lista(cabeza);
				cout<<""<<endl;
				cout<<"Ingrese el número a buscar: ";cin>>dato;
				posicion_elemento(cabeza,cola,dato);
				system("pause");
				system("cls");
				break;
			case 9:
				int numero;
				system("cls");
				cout<<"INSERTAR DESPUES DE UN NÚMERO"<<endl;
				mostrar_lista(cabeza);
				cout<<""<<endl;
				cout<<"Indique el número de la lista: ";cin>>dato;
				if(!encontrar(cabeza,dato)){
					cout<<"El número no existe"<<endl;
					system("pause");
				    system("cls");
					break;
				}else{
				cout<<"Indique el número a agregar: ";cin>>numero;
				insertar_despues(cabeza,cola,dato,numero);
				mostrar_lista(cabeza);
				cout<<""<<endl;
				system("pause");
				system("cls");
				break;}
			case 10:
				cout<<"Gracias..."<<endl;
				break;
			default:
				fuera_rango();
				system("pause");
				system("cls");
		}
	}while(opcion!=10);
	getch();
	return 0;
}
void menu(){
	cout<<"***LISTA CIRCULAR SIMPLE***\n"<<endl;
	cout<<"1. Insertar al inicio"<<endl;
	cout<<"2. Insertar al final"<<endl;
	cout<<"3. Mostrar lista"<<endl;
	cout<<"4. Número de elementos"<<endl;
	cout<<"5. Buscar elemento"<<endl;
	cout<<"6. Eliminar elemento"<<endl;
	cout<<"7. Método de visita"<<endl;
	cout<<"8. Posición de un elemento"<<endl;
	cout<<"9. Insertar despues de un número"<<endl;
	cout<<"10. Salir"<<endl;
	cout<<"Ingrese una opción: ";
}
void insertar_inicio(Tnodo &cabeza, Tnodo &cola, int dato){
	Tnodo nuevo_nodo=new nodo;
	nuevo_nodo->dato=dato;
	if(cabeza==NULL){
		cabeza=nuevo_nodo;
		cabeza->sgte=cabeza;
		cola=nuevo_nodo;
	}else{
		nuevo_nodo->sgte=cabeza;
		cabeza=nuevo_nodo;
		cola->sgte=cabeza;
	}
}
void insertar_final(Tnodo &cabeza, Tnodo &cola, int dato){
	Tnodo nuevo_nodo=new nodo;
	nuevo_nodo->dato=dato;
	if(cabeza==NULL){
		cabeza=nuevo_nodo;
		cabeza->sgte=cabeza;
		cola=nuevo_nodo;
	}else{
		cola->sgte=nuevo_nodo;
		cola=nuevo_nodo;
		nuevo_nodo->sgte=cabeza;
	}
}
void mostrar_lista(Tnodo cabeza){
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		Tnodo aux=cabeza;
		do{
		cout<<"["<<aux->dato<<"]->";
		aux=aux->sgte;
		}while(aux!=cabeza);
		}
}
void contar_elementos(Tnodo cabeza){
	cout<<"NUMERO DE ELEMENTOS"<<endl;
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		Tnodo aux=cabeza;
		int cont=1;
		do{
			cont++;
			aux=aux->sgte;
		}while(aux->sgte!=cabeza);
		cout<<"El número de elementos de la lista es "<<cont<<endl;
	}
}
bool encontrar(Tnodo cabeza,int dato){
	Tnodo aux=cabeza;
	do{
		if(aux->dato==dato)
			return true;
		aux=aux->sgte;
	}while(aux!=cabeza);
}
void buscar_elemento(Tnodo cabeza,int dato){
	Tnodo aux=cabeza;
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		if(!encontrar(cabeza,dato)){
			cout<<"Número no existe en la lista"<<endl;
		}else{
			int n=0;
			do{
			    if(aux->dato==dato){
				    n++;
				    cout<<"El número "<<dato<<" se encuentra en la posición "<<n<<endl;;
				    break;
				}else{
					n++;
				}
				aux=aux->sgte;
		    }while(aux!=cabeza);
		}
	}
}
void eliminar_elemento(Tnodo &cabeza, Tnodo &cola,int dato){
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		if(!encontrar(cabeza,dato)){
			cout<<"Número no existe en la lista"<<endl;
		}else{
			Tnodo anterior=cabeza, eliminar=cabeza;
			do{
				if(eliminar->dato==dato){
					if(eliminar==cabeza && eliminar==cola){
						cabeza=NULL;
						cola=NULL;
						delete eliminar;
						break;
					}else if(eliminar==cabeza){
						cabeza=cabeza->sgte;
						cola->sgte=cabeza;
						delete eliminar;
						
					}else if(eliminar==cola){
						anterior->sgte=cabeza;
						cola=anterior;
						delete eliminar;
						
					}else{
						anterior->sgte=eliminar->sgte;
						delete eliminar;
					}
				}
				anterior=eliminar;
				eliminar=eliminar->sgte;
			}while(eliminar!=cabeza);
		}
	}
}
void metodo_visitar(Tnodo cabeza, int dato){
	for(int i=0;i<dato;i++){
		mostrar_lista(cabeza);
	}
}
void posicion_elemento(Tnodo cabeza, Tnodo cola, int dato){
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		if(!encontrar(cabeza,dato)){
			cout<<"El número no existe"<<endl;
		}else{
			Tnodo buscador=cabeza;
			int n=0,m=0;
			do{
				if(buscador->dato==dato){
					Tnodo hcola=buscador, hcabeza=cabeza;
					do{
						if(hcola==cola){
							n=0;
							break;
						}
						n++;
						hcola=hcola->sgte;
					}while(hcola->sgte!=cola->sgte);
					do{
						if(buscador==cabeza){
							m=0;
							break;
						}
						m++;
						hcabeza=hcabeza->sgte;
					}while(hcabeza!=buscador);
				}
				buscador=buscador->sgte;
			}while(buscador!=cabeza);
			cout<<"El numero "<<dato<<" se ubica a "<<m<<" posiciones de la cabeza y a "<<n<<" posiciones de la cola."<<endl;
		}
	}
}
void insertar_despues(Tnodo &cabeza, Tnodo &cola,int dato,int numero){
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
			Tnodo aux=cabeza;
			do{
				if(aux->dato==dato){
					Tnodo nuevo_nodo=new nodo;
					nuevo_nodo->dato=numero;
					if(aux==cola){
						cola->sgte=nuevo_nodo;
						cola=nuevo_nodo;
						cola->sgte=cabeza;
					}else{
						nuevo_nodo->sgte=aux->sgte;
						aux->sgte=nuevo_nodo;
					}
				}
				aux=aux->sgte;
			}while(aux!=cabeza);
		}
	}
void fuera_rango(){
	cout<<"Inserte una opción dentro del rango [1-9]"<<endl;
}
