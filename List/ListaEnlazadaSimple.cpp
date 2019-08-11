#include<iostream>
#include<conio.h>
using namespace std;
struct Nodo{
	int dato;
	Nodo *sgte;
};
typedef Nodo *Tnodo;
Tnodo cabeza=NULL;
void menu();
void menu_insertar();
void insertar_inicio(Tnodo &,int);
void insertar_final(Tnodo &,int);
void listar(Tnodo);
bool buscar(Tnodo,int);
void insertar_antes(Tnodo &,int,int);
void insertar_despues(Tnodo &,int,int);
void menu_buscar();
void maximo_numero(Tnodo);
void minimo_numero(Tnodo);
void encontrar(Tnodo,int);
void menu_eliminar();
void eliminar_primer_elemento(Tnodo &);
void eliminar_cualquier_elemento(Tnodo &,int);
int contar_numeros_repetidos(Tnodo );
void eliminar_duplicados(Tnodo &,int);
int contar_repeticiones(Tnodo,int);
void eliminar_varios_elemento(Tnodo &,int,int);
int main(){
	system("color B1");
	setlocale(LC_ALL,"");
	int opcion;
	do{
		menu();cin>>opcion;
		switch(opcion){
			int dato;
			case 1:
				int op;
				system("cls");
				menu_insertar();cin>>op;
				switch(op){
					case 1:
						system("cls");
						cout<<"Insertar al inicio\n"<<endl;
						cout<<"Ingrese el número: ";cin>>dato;
						insertar_inicio(cabeza,dato);
						listar(cabeza);
						cout<<""<<endl;
						system("pause");
						system("cls");
						break;
					case 2:
						system("cls");
						cout<<"Insertar al final\n"<<endl;
						cout<<"Ingrese el número: ";cin>>dato;
						insertar_final(cabeza,dato);
						listar(cabeza);
						cout<<""<<endl;
						system("pause");
						system("cls");
						break;
					case 3:
						system("cls");
						cout<<"Insertar en cualquier posición"<<endl;
						listar(cabeza);
						cout<<""<<endl;
						cout<<"Ingrese el número de la lista: ";cin>>dato;
						if(!buscar(cabeza,dato)){
						    cout<<"El número no existe en la lista"<<endl;
					        break;
				        }
				        int c,numero;
				        cout<<"1. Insertar antes del número."<<endl;
						cout<<"2. Insertar despues del número."<<endl;
						cout<<"Respuesta: ";cin>>c;
						switch(c){
							case 1:
								cout<<"Indique el número a agregar: ";cin>>numero;
								insertar_antes(cabeza,dato,numero);
								listar(cabeza);
								cout<<""<<endl;
								break;
							case 2:
							    cout<<"Indique el número a agregar: ";cin>>numero;
							    insertar_despues(cabeza,dato,numero);
							    listar(cabeza);
							    cout<<""<<endl;
						        break;
						}
						system("pause");
						system("cls");
						break;
					default:
						cout<<"Ingrese un opción valida dentro del rango [1-3]"<<endl;
						system("pause");
						system("cls");
				}
				break;
			case 2:
				system("cls");
				int o1;
				menu_buscar();cin>>o1;
				switch(o1){
					case 1:
						system("cls");
						listar(cabeza);
						cout<<""<<endl;
						maximo_numero(cabeza);
						system("pause");
						system("cls");
						break;
					case 2:
						system("cls");
						listar(cabeza);
						cout<<""<<endl;
						minimo_numero(cabeza);
						system("pause");
						system("cls");
						break;
					case 3:
						system("cls");
						listar(cabeza);
						cout<<""<<endl;
						cout<<"Buscar número\n"<<endl;
						cout<<"Ingrese el número a buscar: ";cin>>dato;
						encontrar(cabeza,dato);
						system("pause");
						system("cls");
						break;
					default:
						cout<<"Ingrese un opción valida dentro del rango [1-3]"<<endl;
						system("pause");
						system("cls");
				}
				break;
			case 3:
				system("cls");
				int o2;
				menu_eliminar();cin>>o2;
				switch(o2){
					case 1:
						system("cls");
						cout<<"Eliminar el primer elemento\n"<<endl;
						eliminar_primer_elemento(cabeza);
						listar(cabeza);
						cout<<""<<endl;
						system("pause");
						system("cls");
						break;
					case 2:
						system("cls");
						cout<<"Eliminar el cualquier elemento\n"<<endl;
						listar(cabeza);
						cout<<""<<endl;
						cout<<"Ingrese el número a eliminar: ";cin>>dato;
						eliminar_cualquier_elemento(cabeza,dato);
						listar(cabeza);
						cout<<""<<endl;
						system("pause");
						system("cls");
						break;
					case 3:
						system("cls");
						cout<<"Eliminar el elementos duplicados\n"<<endl;
						{
							listar(cabeza);
							cout<<""<<endl;
							int q=contar_numeros_repetidos(cabeza);
							eliminar_duplicados(cabeza,q);
							listar(cabeza);
							cout<<""<<endl;
						    system("pause");
						    system("cls");
					    break;
				        }
				    default:
						cout<<"Ingrese un opción valida dentro del rango [1-3]"<<endl;
						system("pause");
						system("cls");
				}
				break;
			case 4:
				system("cls");
				cout<<"Gracias..."<<endl;
				break;
			default:
				system("cls");
				cout<<"Ingrese un opción valida dentro del rango [1-4]"<<endl;
				system("pause");
				system("cls");
		}
	}while(opcion!=4);
	getch();
	return 0;
}
void menu(){
	cout<<"****LISTA SIMPLE ENLAZADA****"<<endl;
	cout<<"1. Insertar"<<endl;
	cout<<"2. Buscar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Ingrese la opción: ";
}
void menu_insertar(){
	cout<<"INSERTAR"<<endl;
	cout<<"1. Insertar al inicio."<<endl;
	cout<<"2. Insertar al final."<<endl;
	cout<<"3. Insertar en cualquier posición."<<endl;
	cout<<"Ingrese la opción: "<<endl;
}
void insertar_inicio(Tnodo &cabeza,int dato){
	Tnodo nuevo_nodo=new Nodo;
	nuevo_nodo->dato=dato;
	nuevo_nodo->sgte=cabeza;
	cabeza=nuevo_nodo;
}
void insertar_final(Tnodo &cabeza,int dato){
	Tnodo nuevo_nodo=new Nodo;
	nuevo_nodo->dato=dato;
	nuevo_nodo->sgte=NULL;
	if(cabeza==NULL){
		cabeza=nuevo_nodo;
	}else{
		Tnodo temp=cabeza;
		while(temp->sgte!=NULL){
			temp=temp->sgte;
		}
		temp->sgte=nuevo_nodo;
	}
}
void listar(Tnodo cabeza){
	while(cabeza!=NULL){
		cout<<"["<<cabeza->dato<<"]->";
		cabeza=cabeza->sgte;
	}
}
bool buscar(Tnodo cabeza,int dato){
	while(cabeza!=NULL){
		if(cabeza->dato==dato)
		return true;
		cabeza=cabeza->sgte;
	}
}
void insertar_antes(Tnodo &cabeza,int dato,int numero){
	if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		Tnodo aux=cabeza,ant=cabeza;
		Tnodo nuevo_nodo=new Nodo;
		nuevo_nodo->dato=numero;
		while(aux!=NULL){
			if(aux->dato==dato){
				if(aux->dato==cabeza->dato){
					insertar_inicio(cabeza,numero);
					break;
				}
				nuevo_nodo->sgte=ant->sgte;
				ant->sgte=nuevo_nodo;
			}
			ant=aux;
			aux=aux->sgte;
		}
	}
}
void insertar_despues(Tnodo &cabeza,int dato,int numero){
if(cabeza==NULL){
		cout<<"Lista vacía"<<endl;
	}else{
		Tnodo aux=cabeza,ant=cabeza;
		Tnodo nuevo_nodo=new Nodo;
		nuevo_nodo->dato=numero;
		while(aux!=NULL){
			ant=aux;
			if(aux->dato==dato){
				nuevo_nodo->sgte=ant->sgte;
				ant->sgte=nuevo_nodo;
			}
			aux=aux->sgte;
		}
	}	
}
void menu_buscar(){
	cout<<"BUSCAR"<<endl;
	cout<<"1. Buscar el número máximo."<<endl;
	cout<<"2. Buscar el número mínimo."<<endl;
	cout<<"3. Buscar cualquier número en la lista."<<endl;
	cout<<"Ingrese la opción: "<<endl;
}
void maximo_numero(Tnodo cabeza){
	int r=cabeza->dato;
	while(cabeza!=NULL){
		if(r<cabeza->dato){
			r=cabeza->dato;
		}
		cabeza=cabeza->sgte;
	}
	cout<<"El número máximo de la lista es "<<r<<endl;
}
void minimo_numero(Tnodo cabeza){
	int r=cabeza->dato;
	while(cabeza!=NULL){
		if(r>cabeza->dato){
			r=cabeza->dato;
		}
		cabeza=cabeza->sgte;
	}
	cout<<"El número mínimo de la lista es "<<r<<endl;
}
void encontrar(Tnodo cabeza,int dato){
	if(cabeza==NULL){
		cout<<"Lista vacia."<<endl;
	}else{
		if(!buscar(cabeza,dato)){
			cout<<"Número no existe en la lista"<<endl;
		}else{
			int n=0;
			while(cabeza!=NULL){
				if(cabeza->dato!=dato){
					++n;
				}else{
					++n;
					cout<<"El número "<<dato<<" se encuentra en la posición "<<n<<". "<<endl;
				}
				cabeza=cabeza->sgte;
			}
		}
	}
}
void menu_eliminar(){
	cout<<"ELIMINAR"<<endl;
	cout<<"1. Eliminar el primer número."<<endl;
	cout<<"2. Eliminar cualquier número."<<endl;
	cout<<"3. Eliminar números duplicados."<<endl;
	cout<<"Ingrese la opción: "<<endl;
}
void eliminar_primer_elemento(Tnodo &cabeza){
	if(cabeza==NULL){
		cout<<"Lista vacía."<<endl;
	}else{
		Tnodo aux=cabeza;
		cabeza=aux->sgte;
		delete aux;
	}
}
void eliminar_cualquier_elemento(Tnodo &cabeza,int dato){
	if(cabeza==NULL){
		cout<<"Lista vacía."<<endl;
		return;
	}else{
		if(!buscar(cabeza,dato)){
			cout<<"Número no existe en la lista"<<endl;
			return;
		}else{
			Tnodo el=cabeza,ant=cabeza;
			while(el!=NULL){
				if(el->dato==dato){
					if(el==cabeza){
						eliminar_primer_elemento(cabeza);
						break;
					}else{
						ant->sgte=el->sgte;
						delete el;
						break;
					}
				}
				ant=el;
				el=el->sgte;
			}
		}
	}
}
int contar_numeros_repetidos(Tnodo cabeza){
	int n=0;
	Tnodo temp=cabeza;
	while(cabeza!=NULL){
	if(contar_repeticiones(cabeza,cabeza->dato)>1){
		n++;
	}
	cabeza=cabeza->sgte;	
	}
	return n;
}
void eliminar_duplicados(Tnodo &cabeza,int numero){
	Tnodo temp=cabeza;
	for(int i=0;i<numero;i++){
		while(temp!=NULL){
			if(contar_repeticiones(temp,temp->dato)>1){
			int d=contar_repeticiones(temp,temp->dato);
			eliminar_varios_elemento(temp,temp->dato,d);
			break;
		}
		temp=temp->sgte;
		}
		
	}
}
int contar_repeticiones(Tnodo cabeza,int dato){
	int c=0;
	while(cabeza!=NULL){
		if(cabeza->dato==dato){
		c++;	
	    }
	    cabeza=cabeza->sgte;
	}
	return c;
}
void eliminar_varios_elemento(Tnodo &cabeza,int dato,int c){
	if(cabeza==NULL){
		cout<<"Lista vacía."<<endl;
	}else{
		if(!buscar(cabeza,dato)){
			cout<<"Número no existe"<<endl;
		}else{
			Tnodo aux;
			for(int i=0;i<c;i++){
				Tnodo ant=cabeza,el=cabeza;
				while(el!=NULL){
					if(el->dato==dato){
						if(i!=0){
							if(el==cabeza){
								eliminar_primer_elemento(cabeza);
								break;
							}else{
								ant->sgte=el->sgte;
								delete el;
								break;
							}
						}else{
							aux=el;
							aux->dato=aux->dato+1;
							break;
						}
					}
					ant=el;
					el=el->sgte;
				}
			}
			aux->dato=aux->dato-1;
		}
	}
}
