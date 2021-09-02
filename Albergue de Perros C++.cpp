#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 10
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;


//PROTOTIPO DE FUNCIONES
void cambio(char a[]);
void ingresar();
void vacio();
void adopcion();
void gotoxy(int x,int y);
void dibujarCuadro(int x1,int y1,int x2,int y2);
void menu();
void CursorOn(bool visible, DWORD size);
void CursorOff();
void limpia();
void adopcion();
void listar();
void eliminar();


//ESTRUCTURA PERRO CON SUS RESPECTIVAS VARIABLES
struct perro{
	char nombre[35];
	char codigo[15];
	char fecha[30];
	char raza[30];
	int edad;
	int lleno;
};

perro pe[N];


//FUNCION PRINCIPAL MAIN: ES LA PRIMER FUNCIÓN QUE EJECUTA EL PROGRAMA
int main(){
	system("mode con: cols=80 lines=25");
	system("COLOR 70");
	dibujarCuadro(1,1,78,24);//Cuadro grande
	dibujarCuadro(2,2,77,4);//Cuadro del titulo
	gotoxy(16,3); cout << "     A L B E R G U E      D E    P E R R O S";
	vacio();
	menu();
	getch();
	return 0;
}


void menu(){
	char op,op2;
	CursorOn(1,10);
	do{
		gotoxy(4,6); cout << "MENU PRINCIPAL";
		gotoxy(4,9); cout << "(1) Perros";
		gotoxy(4,11); cout << "(2) Estado";
		gotoxy(4,13); cout << "(3) Cerrar";
		gotoxy(4,17); cout << "Ingrese opcion: ";
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3'){
			gotoxy(3,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,17); cout << "                                                                       ";
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	
	if (op=='1'){
		limpia();
		do{
		gotoxy(4,6); cout << "PERROS";
		gotoxy(4,9); cout << "(1) Agregar";
		gotoxy(4,11); cout << "(2) Eliminar";
		gotoxy(4,13); cout << "(3) Listar";
		gotoxy(4,17); cout << "Ingrese opcion: ";
		cin >> op2;
		
		if(op2!='1' && op2!='2' && op2!='3'){
			gotoxy(4,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,17); cout << "                                                                       ";
			CursorOn(1,10);	
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
			CursorOff();
			gotoxy(4,21); cout << "No hay perros. Primero se debe ingresar un perro.";
			gotoxy(4,23); cout << "Presione una tecla para continuar..";
			getch();
			gotoxy(4,17); cout << "                                                       ";
			gotoxy(4,21); cout << "                                                                    ";
			gotoxy(4,23); cout << "                                       ";
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
	gotoxy(4,6); cout << "INGRESO DE PERROS";
	
	for (int i = 0; i < N && aux == 0; i++){
		
		if (pe[i].lleno == 0) {
			do{
				rep=0;
				CursorOn(1,10);
				gotoxy(4,9);  cout << "Codigo:           ";
				fflush(stdin);
				fgets(pe[i].codigo,N,stdin);
				cambio(pe[i].codigo);
				
				for(int j = 0; j < i && rep==0; j++){
					if(strcmp(pe[i].codigo,pe[j].codigo) == 0){
						rep = 1;
						CursorOff();
						gotoxy(4,22); cout << "Codigo ya guardado. Presione una tecla para volver a ingresar..";
						getch();
						gotoxy(4,22); cout << "                                                                  ";
						gotoxy(4,9); cout << "                                                           ";
					}
				}
			
			}while(rep!=0);
			
			
			fflush(stdin);
			gotoxy(4,11); cout << "Nombre:           ";
			fflush(stdin); 
			fgets(pe[i].nombre,N,stdin);
			cambio(pe[i].nombre);
			
			gotoxy(4,13); cout << "Fecha de ingreso: "; 
			fflush(stdin);
			fgets(pe[i].fecha,N,stdin);
			cambio(pe[i].fecha);
			
			
			gotoxy(4,15); cout << "Raza:             "; 
			fflush(stdin);
			fgets(pe[i].raza,N,stdin);
			cambio(pe[i].raza);
			
			gotoxy(4,17); cout << "Edad:             "; 
			fflush(stdin);
			scanf("%i",&pe[i].edad);
			
			pe[i].lleno = 1;
			
			do{
				CursorOff();
				gotoxy(4,22); cout << "Pulse una tecla: <1> Ingrese otro perro / <2> Ir al menu principal ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if(op=='1'){
					CursorOn(1,10);
					gotoxy(4,9); cout << "                                                        ";
					gotoxy(4,11); cout << "                                                        ";
					gotoxy(4,13); cout << "                                                        ";
					gotoxy(4,15); cout << "                                                        ";
					gotoxy(4,17); cout << "                                                        ";
					gotoxy(4,22); cout << "                                                                          ";
				}
				
			if (op == '2')
					aux=1;
			
			
		}
			
		
	}
	
	if (aux == 0){
		gotoxy(4,22); cout << "No quedan mas espacios. Presione una tecla para continuar..";
		getch();
		CursorOff();
	}
	
	
	limpia();
	menu();
}


void listar(){
	limpia();
	int f=10;
	gotoxy(4,6); cout << "LISTA DE PERROS";
	gotoxy(4,8); cout << "Codigo";
	gotoxy(17,8); cout << "Nombre";
	gotoxy(31,8); cout << "Fecha de ingreso";
	gotoxy(54,8); cout << "Raza";
	gotoxy(70,8); cout << "Edad";
					
	for (int i = 0; i < N ; i++){	
	   if (pe[i].lleno == 1) {
			gotoxy(4,f); cout << pe[i].codigo;
			gotoxy(17,f); cout << pe[i].nombre;
			gotoxy(31,f); cout << pe[i].fecha;
			gotoxy(54,f); cout << pe[i].raza;
			gotoxy(70,f); cout << pe[i].edad;
			f+=2;	
		}
	}
	
	CursorOff();
	gotoxy(4,23); cout << "Pulse una tecla para ir al menu principal..";
	getch();	
	limpia();
	menu();
}


void eliminar(){
	char cod[15];
	int aux = 0;
	char op,op2;
	
	limpia();
	gotoxy(4,6); cout << "ELIMINAR PERRO";
	gotoxy(4,8); cout << "Ingrese codigo: ";
	fflush(stdin);
	fgets(cod,N,stdin);
	cambio(cod);
	

	
	for (int i = 0; i < N && aux == 0; i++){
		if(strcmp(cod,pe[i].codigo)	== 0){
			aux = 1;
			gotoxy(4,11); cout << "Nombre:           " << pe[i].nombre;
			gotoxy(4,13); cout << "Fecha de ingreso: " << pe[i].fecha;
			gotoxy(4,15); cout << "Raza:             " << pe[i].raza;
			gotoxy(4,17); cout << "Edad:             " << pe[i].edad;
			do{
				CursorOff();
				gotoxy(4,22); cout << "Seguro que desea eliminar? Pulse una tecla: <1> Si / <2> No ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if (op=='1'){
				pe[i].lleno = 0;
				gotoxy(4,21); cout << "Eliminado correctamente.";
				gotoxy(4,22); cout << "                                                              ";
			}
			if (op=='2'){
				CursorOff();
				gotoxy(4,22); cout << "Codigo no eliminado. Presione una tecla para ir al menu principal..";
				getch();
				limpia();
				menu();	
			}
		}
		
	}
	
	if (aux ==1){
		CursorOff();
		gotoxy(4,22); cout << "Presione una tecla para volver al menu principal";
		getch();	
		limpia();
		menu();
	}
			
			
	else if (aux==0){
		CursorOff();
		gotoxy(4,21); cout << "¡Codigo no encontrado!";
		gotoxy(4,22); cout << "Presione una tecla para volver al menu principal..";
		getch();
		limpia();
		menu();
	}
	
	CursorOff();
	gotoxy(4,23); cout << "Pulse una tecla para ir al menu principal..";
	getch();	
	limpia();
	menu();
		
}



void adopcion(){
	char cod[15];
	int aux = 0;
	char op;
	
	limpia();
	gotoxy(4,6); cout << "ESTADO DEL PERRO";
	gotoxy(4,8); cout << "Ingrese codigo: ";
	fflush(stdin);
	fgets(cod,N,stdin);
	cambio(cod);
	
	limpia();
	gotoxy(4,6); cout << "ESTADO DEL PERRO";
	
	for (int i = 0; i < N && aux == 0; i++){
		if(strcmp(cod,pe[i].codigo)	== 0){
			aux = 1;
			dibujarCuadro(13,8,67,20);
			gotoxy(20,10); cout << "  C A R N E T     D E L     P E R R O";
			
			if(pe[i].edad>7){
				gotoxy(17,13); cout << "Estado:     No factible de dar en adopcion";
			}
			
			else{
				gotoxy(17,13); cout << "Estado:     Factible de dar en adopcion";
			}
				
			gotoxy(17,14); cout << "Codigo:     " << pe[i].codigo;
			gotoxy(17,15); cout << "Nombre:     " << pe[i].nombre;
			gotoxy(17,16); cout << "Fecha ing:  " << pe[i].fecha;
			gotoxy(17,17); cout << "Raza:       " << pe[i].raza;
			gotoxy(17,18); cout << "Edad:       " << pe[i].edad;
					
		}
	}
	
	if (aux ==1){
		CursorOff();
		gotoxy(4,22); cout << "Presione una tecla para volver al menu principal";
		getch();	
		limpia();
		menu();
	}
			
			
	else if (aux==0){
		CursorOff();
		gotoxy(4,21); cout << "¡Codigo no encontrado!";
		gotoxy(4,22); cout << "Presione una tecla para volver al menu principal..";
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


void cambio(char a[]){
	int aux;
	aux = strlen(a);
	a[aux-1] = '\0';
}


void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");}}
}


void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "Ä";
		gotoxy(i,y2); cout << "Ä";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "³";
		gotoxy(x2,i); cout << "³";
    }
    
    gotoxy(x1,y1); cout << "Ú";
    gotoxy(x1,y2); cout << "À";
    gotoxy(x2,y1); cout << "¿";
    gotoxy(x2,y2); cout << "Ù";
}



void CursorOff(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}



void CursorOn(bool visible, DWORD size) 
{
	if(size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
