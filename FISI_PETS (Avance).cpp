#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

#define N 10

using namespace std;

//Prototipo de funciones a utilizar
void cuadro();
void elegirRol();
void darEnAdopcion();
void cambio(char a[]);
void ingresar();
void vacio();
void adopcion();
void menu();
void limpia();
void adopcion();
void listar();
void eliminar();
//luffi
//Estructuras de las mascotas a adoptar
struct mascota{
	char codigo[15];
	char nombre[35];
	char fecha[30];
	char raza[30];
	char tipo[5];
	char distrito[40];
	char sexo[6];
	int edad;
	int lleno;
};

mascota pe[N];

int main(){
	elegirRol();
	cuadro();
	vacio();
	menu();
	getch();
	return 0;
}

//Declaracion de Funciones
void elegirRol(){
	char op;

	do{
		limpia();
		cout<<"\n -- Elegir Accion --"<<endl;
		cout<<"\n  1. Dar en adopcion"<<endl;
		cout<<"  2. Adoptar"<<endl;
		cout<<"\n  Ingresar opcion: ";
		cin>>op;

		if(op != '1' && op != '2')
		{
			cout<<"\nOpcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
		
	}while(op != '1' && op != '2');

	op == '1' 
		? darEnAdopcion() 
		: adopcion();

}

void menu(){
	char op,op2;

	do{
		cuadro();
		cout << "\n\n  -- MENU PARA DAR EN ADOPCION --"<<endl;
		cout << "\n  1. Perros"<<endl;
		cout << "  2. Gatos"<<endl;
		cout << "  3. Cerrar"<<endl;
		cout << "\n  Ingresar opcion: "; 
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3'){
			cout<<"\nOpcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	
	if (op=='1'){
		limpia();
		do{
		cout<<"\n\t\t/////////////////////////////////////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t////            PERROS           ////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t/////////////////////////////////////";
		cout << "\n\n  (1) Agregar"<<endl;
		cout << "  (2) Eliminar"<<endl;
		cout << "  (3) Listar"<<endl;
		cout << "\n  Ingrese opcion: ";
		cin >> op2;
		
		if(op2!='1' && op2!='2' && op2!='3'){
			cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			getch();
			cout << "                                                                       ";
			cout << "                                                                       ";
		}
			
	}while(op2!='1' && op2!='2' && op2!='3');
	
		if (op2=='1')
			ingresar();
		if (op2=='2')
			eliminar();
		if(op2=='3')
			listar();
	
	}
	
	
	
	if (op=='2'){
		int a = 0;
		for(int i = 0; i < 10 && a==0; i++){
			if ( pe[i].lleno == 1)
				a = 1;
		}
		if (a==0){
			cout << "No hay perros. Primero se debe ingresar un perro.";
			cout << "Presione una tecla para continuar..";
			getch();
			cout << "                                                       ";
			cout << "                                                                    ";
			cout << "                                       ";
			menu();
		}
		else
			adopcion();
	}
	
	
	if (op=='3')
		exit(0);
	
}


void ingresar(){
	int aux = 0, rep =0;
	char op;
	
	limpia();
	cout << "\n\t//// INGRESO DE PERROS ////";
	
	for (int i = 0; i < N && aux == 0; i++){
		
		if (pe[i].lleno == 0) {
			do{
				rep=0;
				cout << "\n\n  Codigo: ";
				fflush(stdin);
				fgets(pe[i].codigo,N,stdin);
				cambio(pe[i].codigo);
				
				for(int j = 0; j < i && rep==0; j++){
					if(strcmp(pe[i].codigo,pe[j].codigo) == 0){
						rep = 1;
						cout << "  Codigo ya guardado. Presione una tecla para volver a ingresar..";
						getch();
						cout << "                                                                  ";
						cout << "                                                           ";
					}
				}
			
			}while(rep!=0);
			
			
			fflush(stdin);
			cout << "\n  Nombre: ";
			fflush(stdin); 
			fgets(pe[i].nombre,N,stdin);
			cambio(pe[i].nombre);
			
			cout << "\n  Fecha de ingreso: "; 
			fflush(stdin);
			fgets(pe[i].fecha,N,stdin);
			cambio(pe[i].fecha);
			
			
			cout << "\n  Raza: "; 
			fflush(stdin);
			fgets(pe[i].raza,N,stdin);
			cambio(pe[i].raza);
			
			cout << "\n  Edad: "; 
			fflush(stdin);
			scanf("%i",&pe[i].edad);
			
			pe[i].lleno = 1;
			
			do{
				cout << "\n\n  Pulse una tecla: <1> Ingrese otro perro / <2> Ir al menu principal ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if(op=='1') cout<<"\n\n";
				
			if (op == '2') aux = 1;
		}
	}
	
	if (aux == 0){
		cout << "No quedan mas espacios. Presione una tecla para continuar..";
		getch();
	}
	
	
	limpia();
	menu();
}


void listar(){
	limpia();
	for (int i = 0; i < N ; i++)
	{	
	   if (pe[i].lleno == 1) 
		{
			cout << "\n\tLISTA DE MASCOTAS O^O"<<endl;
			cout << "\n\nCodigo:     " << pe[i].codigo;
			cout << "\nNombre:     " << pe[i].nombre;
			cout << "\nFecha ing:  " << pe[i].fecha;
			cout<<  "\nEspecie:    " << pe[i].tipo;
			cout << "\nSexo: 	    " << pe[i].sexo;
			cout << "\nRaza:       " << pe[i].raza;
			cout << "\nEdad:       " << pe[i].edad;
					 

		}
	}
	
	cout << "\nPulse una tecla para ir al menu principal ...";
	getch();	
	limpia();
	menu();
}

void eliminar(){
	char cod[15];
	int aux = 0;
	char op,op2;
	
	limpia();
	cout << "\tDESCARTAR MASCOTA"<<endl;
	cout << "\nIngrese codigo:   ";
	fflush(stdin);
	fgets(cod,N,stdin);
	cambio(cod);
	
	for (int i = 0; i < N && aux == 0; i++)
	{
		if(strcmp(cod,pe[i].codigo)	== 0)
		{
			aux = 1;
			cout << "\nNombre:           " << pe[i].nombre;
			cout << "\nFecha de ingreso: " << pe[i].fecha;
			cout << "\nEspecie:          " << pe[i].tipo;
			cout << "\nSexo: 		  " << pe[i].sexo;
			cout << "\nRaza:             " << pe[i].raza;
			cout << "\nEdad:             " << pe[i].edad;
			do{
			cout << "\n\nEsta seguro que desea eliminar esta informacion de manera permanente? Pulse una tecla: <1> Si / <2> No  ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if (op=='1')
			{
				pe[i].lleno = 0;
				cout << "\n\nEliminado correctamente.";
				cout << "                                                              ";
			}
			if (op=='2')
			{
				cout << "\n\nCodigo no eliminado. Presione una tecla para ir al menu principal ...";
				getch();
				limpia();
				menu();	
			}
		}
		
	}
	
	if (aux ==1)
	{
		cout << "\n\nPresione una tecla para volver al menu principal ...";
		getch();	
		limpia();
		menu();
	}
					
	else{
 	if (aux==0){
		cout << "\n\n¡Codigo no encontrado!";
		cout << "\n\nPresione una tecla para volver al menu principal ...";
		getch();
		limpia();
		menu();
	}}
	cout << "\n\nPulse una tecla para ir al menu principal ...";
	getch();	
	limpia();
	menu();
}


void adopcion(){
	char cod[15];
	int aux = 0;
	char op;
	
	limpia();
	cout << "\n\tESTADO DEL PERRO";
	cout << "\n\nIngrese codigo: ";
	fflush(stdin);
	fgets(cod,N,stdin);
	cambio(cod);
	
	limpia();
	cout << "\nESTADO DEL PERRO";
	
	for (int i = 0; i < N && aux == 0; i++){
		if(strcmp(cod,pe[i].codigo) == 0){
			aux = 1;
			cout << "\n\t\t  C A R N E T     D E L     P E R R O";
			
			if(pe[i].edad>7){
				cout << "\n\nEstado:     No factible de dar en adopcion";
			}
			
			else{
				cout << "\n\nEstado:     Factible de dar en adopcion";
			}
				
			cout << "\n\nCodigo:     " << pe[i].codigo;
			cout << "\nNombre:     " << pe[i].nombre;
			cout << "\nFecha ing:  " << pe[i].fecha;
			cout << "\nRaza:       " << pe[i].raza;
			cout << "\nEdad:       " << pe[i].edad;
					
		}
	}
	
	if (aux ==1){
		cout << "\n\nPresione una tecla para volver al menu principal";
		getch();	
		limpia();
		menu();
	}
			
			
	else if (aux==0){
		cout << "\n\n¡Codigo no encontrado!";
		cout << "\n\nPresione una tecla para volver al menu principal..";
		getch();
		limpia();
		menu();
	}
		
}


void vacio(){
	for (int i = 0; i < N; i++){
		pe[i].lleno = 0;
	}
}

void darEnAdopcion(){
	limpia();
	cout<<"has elegido la opcion de dar en adopcion"<<endl;
	getch();
}

void cambio(char a[]){
	int aux;
	aux = strlen(a);
	a[aux-1] = '\0';
}

void cuadro(){
	cout<<"\n\t\t/////////////////////////////////////////////"<<endl;
	cout<<"\t\t////                                     ////"<<endl;
	cout<<"\t\t////          F I S I    P E T S         ////"<<endl;
	cout<<"\t\t////                                     ////"<<endl;
	cout<<"\t\t/////////////////////////////////////////////";
}

void limpia(){
	system("CLS");
}

