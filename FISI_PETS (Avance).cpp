#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

#define N 10

using namespace std;

//Prototipo de funciones a utilizar
void elegirRol();
void darEnAdopcion();
void reclutar();
void vacio();
void limpiarPantalla();
void adopcion();
void ingresar(string tipo);
void eliminar(string tipo);
void listar(string tipo);

//Estructuras de las mascotas a adoptar
struct perro{
	char codigo[15];
	char nombre[35];
	char fecha[30];
	char raza[30];
	char distrito[40];
	char sexo[10];
	int edad;
	int lleno;
};

perro pe[N];

struct gato{
	char codigo[15];
	char nombre[35];
	char fecha[30];
	char raza[30];
	char distrito[40];
	char sexo[10];
	int edad;
	int lleno;
};

gato cat[N];

int main(){
	elegirRol();
	vacio();
	getch();

	return 0;
}
//Estructura de los voluntarios
struct recluta
{
	string nombre;
	string correo;
	char numero[9];
	int edad;
	char distrito[40];
}

//Declaracion de Funciones
void elegirRol(){
	char op;

	do{
		limpiarPantalla();
		cout<<"\n\t\t/////////////////////////////////////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t////          FISI PETS          ////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t/////////////////////////////////////";
		cout<<"\n\n\n -- Elegir Accion --"<<endl;
		cout<<"\n  1. Dar en adopcion"<<endl;
		cout<<"  2. Adoptar"<<endl;
		cout<<"\n  Ingresar opcion: ";
		cin>>op;

		if(op != '1' && op != '2')
		{
			cout<<"\n\n  Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
		
	}while(op != '1' && op != '2');

	op == '1' 
		? darEnAdopcion() 
		: adopcion();

}

void darEnAdopcion(){
	char op,op2;

	do{
		limpiarPantalla();
		cout << "\n\n  -- MENU PARA DAR EN ADOPCION --"<<endl;
		cout << "\n  1. Perros"<<endl;
		cout << "  2. Gatos"<<endl;
		cout << "  3. Cerrar"<<endl;
		cout << "\n  Ingresar opcion: "; 
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3'){
			cout<<"\n\n Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	
	if (op=='1'){
		limpiarPantalla();
		do{
			cout<<"\n\t\t/////////////////////////////////////"<<endl;
			cout<<"\t\t////                             ////"<<endl;
			cout<<"\t\t////            PERROS           ////"<<endl;
			cout<<"\t\t////                             ////"<<endl;
			cout<<"\t\t/////////////////////////////////////";
			cout << "\n\n  1. Agregar"<<endl;
			cout << "  2. Descartar"<<endl;
			cout << "  3. Ver perros del albergue"<<endl;
			cout << "\n  Ingrese opcion: ";
			cin >> op2;
		
			if(op2!='1' && op2!='2' && op2!='3'){
				cout << "\n  Error al ingresar valores. Presione una tecla para volver a ingresar..";
				getch();
				limpiarPantalla();
			}
			
		}while(op2 != '1' && op2 != '2' && op2 != '3');
	
		if(op2 == '1') ingresar("perro");
		if(op2 == '2') eliminar("perro");
		if(op2 == '3') listar("perro");
	
	}
	
	if(op == '2'){
		limpiarPantalla();
		do{
			cout<<"\n\t\t/////////////////////////////////////"<<endl;
			cout<<"\t\t////                             ////"<<endl;
			cout<<"\t\t////            GATOS            ////"<<endl;
			cout<<"\t\t////                             ////"<<endl;
			cout<<"\t\t/////////////////////////////////////";
			cout << "\n\n  1. Agregar"<<endl;
			cout << "  2. Descartar"<<endl;
			cout << "  3. Ver Gatos del albergue"<<endl;
			cout << "\n  Ingrese opcion: ";
			cin >> op2;
		
			if(op2!='1' && op2!='2' && op2!='3'){
				cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
				getch();
			}
			
		}while(op2!='1' && op2!='2' && op2!='3');
	
		if(op2 == '1') ingresar("gato");
		if(op2 == '2') eliminar("gato");
		if(op2 == '3') listar("gato");
	
	}

	if (op == '2'){
		int a = 0;
		for(int i = 0; i < 10 && a == 0; i++){
			if ( pe[i].lleno == 1) a = 1;
		}

		if(a == 0){
			cout<<"No hay perros. Primero se debe ingresar un perro.";
			cout<<"Presione una tecla para continuar ...";
			getch();
			elegirRol();
		}
		else
			adopcion();
	}
		
	if (op=='3') exit(0);
}


void ingresar(string tipo){
	int aux = 0, rep =0;
	char op;

	if(tipo == "perro"){
		limpiarPantalla();
		
		cout << "\n\t//// INGRESO DE PERROS ////";
	
		for(int i = 0; i < N && aux == 0; i++){
			if (pe[i].lleno == 0) {
				do{
					rep=0;
					cout << "\n\n  Codigo: ";
					fflush(stdin);
					cin.getline(pe[i].codigo, 15);
					// cambio(pe[i].codigo);
					
					for(int j = 0; j < i && rep==0; j++){
						if(strcmp(pe[i].codigo,pe[j].codigo) == 0){
							rep = 1;
							cout << "  Codigo ya guardado. Presione una tecla para volver a ingresar ...";
							getch();
						}
					}
				
				}while(rep!=0);
			
				fflush(stdin);

				cout<<"\n  Nombre: ";
				fflush(stdin); 
				cin.getline(pe[i].nombre, 35);
				// cambio(pe[i].nombre);
				
				cout<<"\n  Fecha de ingreso: "; 
				fflush(stdin);
				cin.getline(pe[i].fecha, 30);
				// cambio(pe[i].fecha);
				
				cout<<"\n  Raza: "; 
				fflush(stdin);
				cin.getline(pe[i].raza, 30);
				// cambio(pe[i].raza);

				cout<<"\n  Distrito: "; 
				fflush(stdin);
				cin.getline(pe[i].distrito,40);

				cout<<"\n  Sexo: "; 
				fflush(stdin);
				cin.getline(pe[i].sexo, 10);
				
				cout<<"\n  Edad: "; 
				fflush(stdin);
				cin>>pe[i].edad;
				
				pe[i].lleno = 1; //Para validar que ya exista al menos una mascota
				
				do{
					cout<<"\n\n  ¿Que desea hacer ahora?"<<endl; 
					cout<<"\n  (1) Ingresar otro perro"<<endl;
					cout<<"  (2) Ir al menu principal";
					op = getch();	
				}while (op != '1' && op != '2');
				
				if(op == '1') cout<<"\n\n";
					
				if (op == '2') aux = 1;
			}
		}
	}else {
		limpiarPantalla();

		cout<<"\n\t//// INGRESO DE GATOS ////";

		for(int i = 0; i < N && aux == 0; i++){
			if (cat[i].lleno == 0) {
				do{
					rep=0;
					cout << "\n\n  Codigo: ";
					fflush(stdin);
					cin.getline(cat[i].codigo, 15);
					
					for(int j = 0; j < i && rep==0; j++){
						if(strcmp(cat[i].codigo, cat[j].codigo) == 0){
							rep = 1;
							cout << "  Codigo ya guardado. Presione una tecla para volver a ingresar ...";
							getch();
						}
					}
				
				}while(rep!=0);
			
				fflush(stdin);

				cout<<"\n  Nombre: ";
				fflush(stdin); 
				cin.getline(cat[i].nombre, 35);
				
				cout<<"\n  Fecha de ingreso: "; 
				fflush(stdin);
				cin.getline(cat[i].fecha, 30);
				
				cout<<"\n  Raza: "; 
				fflush(stdin);
				cin.getline(cat[i].raza, 30);

				cout<<"\n  Distrito: "; 
				fflush(stdin);
				cin.getline(cat[i].distrito,40);

				cout<<"\n  Sexo: "; 
				fflush(stdin);
				cin.getline(cat[i].sexo, 10);
				
				cout<<"\n  Edad: "; 
				fflush(stdin);
				cin>>cat[i].edad;
				
				cat[i].lleno = 1; //Para validar que ya exista al menos una mascota
				
				do{
					cout<<"\n\n  Que desea hacer ahora?"<<endl; 
					cout<<"\n  (1) Ingresar otro gato"<<endl;
					cout<<"  (2) Ir al menu principal";
					op = getch();	
				}while (op != '1' && op != '2');
				
				if(op == '1') cout<<"\n\n";
					
				if (op == '2') aux = 1;
			}
		}
	}
	
	if (aux == 0){
		cout << "No quedan mas espacios. Presione una tecla para continuar ...";
		getch();
	}

	elegirRol();
}


void listar(string tipo){
	int aux = 0;
	limpiarPantalla();
	
	if(tipo == "perro"){
		cout << "\n\tLISTA DE PEWITOS O^O"<<endl;

		for (int i = 0; i < N ; i++){	
			if (pe[i].lleno == 1){
				cout<<"\n  Codigo:      "<<pe[i].codigo;
				cout<<"\n  Nombre:      "<<pe[i].nombre;
				cout<<"\n  Fecha de ingreso:   "<<pe[i].fecha;
				cout<<"\n  Raza:        "<<pe[i].raza;
				cout<<"\n  Distrito:    "<<pe[i].distrito;
				cout<<"\n  Sexo: 	      "<<pe[i].sexo;
				cout<<"\n  Edad:        "<<pe[i].edad;
			}
		}

	}else {
		cout << "\n\tLISTA DE GATIWOS O^O"<<endl;

		for (int i = 0; i < N ; i++){	
			if (cat[i].lleno == 1){
				cout<<"\n  Codigo:        "<<cat[i].codigo;
				cout<<"\n  Nombre:        "<<cat[i].nombre;
				cout<<"\n  Fecha de ingreso:   "<<cat[i].fecha;
				cout<<"\n  Raza:          "<<cat[i].raza;
				cout<<"\n  Distrito:      "<<cat[i].distrito;
				cout<<"\n  Sexo:          "<<cat[i].sexo;
				cout<<"\n  Edad:          "<<cat[i].edad;
				cout<<"\n\n-----------------------"<<endl;
			}
		}
	}
	
	cout<<"\n  Pulse una tecla para ir al menu principal ...";
	getch();	
	elegirRol();
}

void eliminar(string tipo){
	char codigoMascota[15];
	int aux = 0;
	char op,op2;

	limpiarPantalla();
	
	cout << "\t-- DESCARTAR MASCOTA --"<<endl;
	cout << "\nIngrese el codigo de la mascota:   ";
	fflush(stdin);
	fgets(codigoMascota,N,stdin);
	cin.getline(codigoMascota, 15);
	
	if(tipo == "perro"){
		for (int i = 0; i < N && aux == 0; i++){
			if(strcmp(codigoMascota, pe[i].codigo)){
				aux = 1;
				cout << "\nNombre:            " << pe[i].nombre;
				cout << "\nFecha de ingreso:  " << pe[i].fecha;
				cout << "\nRaza:              " << pe[i].raza;
				cout << "\nDistrito:          " << pe[i].distrito;
				cout << "\nSexo: 		   " << pe[i].sexo;
				cout << "\nEdad:              " << pe[i].edad;
				
				do{

					cout << "\n\n  Esta seguro que desea eliminar esta informacion de manera permanente?";
					cout<<"\n\n  1. Si"<<endl;
					cout<<"  2. No";
					op = getch();	

				}while (op != '1' && op != '2');
			
				if (op == '1'){
					pe[i].lleno = 0;
					cout << "\n\nEliminado correctamente.";
				}

				if (op=='2'){
					cout << "\n\nCodigo no eliminado. Presione una tecla para ir al menu principal ...";
					getch();
					elegirRol();
				}
			}
		}
	}else {
		for (int i = 0; i < N && aux == 0; i++){
			if(strcmp(codigoMascota, cat[i].codigo)){
				aux = 1;
				cout<<"\nNombre:           "<<cat[i].nombre;
				cout<<"\nFecha de ingreso: "<<cat[i].fecha;
				cout<<"\nRaza:             "<<cat[i].raza;
				cout<<"\nDistrito:          "<<cat[i].distrito;
				cout<<"\nSexo: 		  "<<cat[i].sexo;
				cout<<"\nEdad:             "<<cat[i].edad;
				
				do{

					cout << "\n\n  ¿Esta seguro que desea eliminar esta informacion de manera permanente?";
					cout<<"\n\n  1. Si";
					cout<<"\n 2. No";
					op = getch();	

				}while (op != '1' && op != '2');
			
				if (op == '1'){
					cat[i].lleno = 0;
					cout << "\n\nEliminado correctamente.";
				}

				if (op == '2'){
					cout << "\n\nCodigo no eliminado. Presione una tecla para ir al menu principal ...";
					getch();
					elegirRol();	
				}
			}
		}
	}
	
	if (aux == 1){
		cout << "\n\nPresione una tecla para volver al menu principal ...";
		getch();	
		elegirRol();
	}else {
		if (aux==0){
			cout << "\n\n¡Codigo no encontrado!";
			cout << "\n\nPresione una tecla para volver al menu principal ...";
			getch();
			elegirRol();
		}
	}

	cout << "\n\nPulse una tecla para ir al menu principal ...";
	getch();	
	elegirRol();
}


void adopcion(){
	char codigoMascota[15];
	int aux = 0;
	char op;
	
	do{
		limpiarPantalla();
		cout<<"\n\tESPECIE DE MASCOTA A ADOPTAR";
		cout<<"\n\n  1. Perro"<<endl;
		cout<<"  2. Gato"<<endl;
		cout<<"\nIngrese una opcion: ";
		cin>>op;

			if(op!='1' && op!='2'){
				cout<<"\nOpcion invalida. Presione una tecla para elegir otra opcion. ";
				getch();
			}
	}while(op != '1' && op != '2');

	if(op == '1'){
		limpiarPantalla();
		cout<<"\n\t-- ESTADO DEL PERRO --"<<endl;
		cout<<"\nIngrese el codigo del perro: ";
		fflush(stdin);
		cin.getline(codigoMascota, 15);
		
		limpiarPantalla();
		
		cout << "\nESTADO DEL PERRO";

		for (int i = 0; i < N && aux == 0; i++){
			if(strcmp(codigoMascota,pe[i].codigo) == 0){
				aux = 1;
				cout << "\n\t\t  C A R N E T     D E L     P E R R O";
			
				if(pe[i].edad>7){
					cout << "\n\nEstado:     No factible de dar en adopcion";
				} else{
					cout << "\n\nEstado:     Factible de dar en adopcion";
				}
		
				cout<<"\n\nCodigo:      "<<pe[i].codigo;
				cout<<"\nNombre:      "<<pe[i].nombre;
				cout<<"\nFecha de ingreso:  "<<pe[i].fecha;
				cout<<"\nRaza:        "<<pe[i].raza;
				cout<<"\nDistrito:        "<<pe[i].distrito;
				cout<<"\nSexo:        "<<pe[i].sexo;
				cout<<"\nEdad:        "<<pe[i].edad;		
			}
		}
	}else {
		limpiarPantalla();
		cout<<"\n\t-- ESTADO DEL GATO --"<<endl;
		cout<<"\nIngrese el codigo del gato: ";
		fflush(stdin);
		cin.getline(codigoMascota, 15);
		
		limpiarPantalla();
		
		cout << "\nESTADO DEL GATO";

		for (int i = 0; i < N && aux == 0; i++){
			if(strcmp(codigoMascota, cat[i].codigo) == 0){
				aux = 1;

				cout << "\n\t\t  C A R N E T     D E L     G A T O";
			
				if(cat[i].edad > 7){
					cout<<"\n\nEstado:     No factible de dar en adopcion";
				}else {
					cout<<"\n\nEstado:     Factible de dar en adopcion";
				}
		
				cout<<"\n\nCodigo:     "<<cat[i].codigo;
				cout<<"\nNombre:     "<<cat[i].nombre;
				cout<<"\nFecha ing:  "<<cat[i].fecha;
				cout<<"\nRaza:       "<<cat[i].raza;
				cout<<"\nDistrito:       "<<cat[i].distrito;
				cout<<"\nSexo:       "<<cat[i].sexo;
				cout<<"\nEdad:       "<<cat[i].edad;		
			}
		}
	}

	if (aux == 1){
		cout << "\n\nPresione una tecla para volver al menu principal";
		getch();	
		elegirRol();
	}else if (aux == 0){
		cout << "\n\nCodigo no encontrado!";
		cout << "\n\nPresione una tecla para volver al menu principal..";
		getch();
		darEnAdopcion();
	}	
}


void vacio(){
	for (int i = 0; i < N; i++){
		pe[i].lleno = 0;
		cat[i].lleno = 0;
	}
}

void limpiarPantalla(){
	system("CLS");
}