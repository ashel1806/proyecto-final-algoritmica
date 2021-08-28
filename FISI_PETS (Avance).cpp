#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <regex>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <iostream>

// #define N 10

using namespace std;

//Prototipo de funciones a utilizar
void elegirRol();
void menuDarAdopcion();
void reclutar();
void vacio();
void limpiarPantalla();
void adopcion();
void ingresar(string tipo);
void modificar(string tipo);
void listar(string tipo);
char menuAdoptar(string texto);
void listarV();

//Estructuras de las mascotas a adoptar
struct Mascota{
	int codigo;
	string nombre, fecha, raza, distrito, sexo;
	string tipo;
	int edad;
} mascota;

// perro pe[N];

// struct gato{
// 	int codigo;
// 	string nombre, fecha, raza, distrito, sexo;
// 	int edad;
// 	int lleno;
// };

// gato cat[N];

//Estructura de los voluntarios
struct Recluta {
	string nombre, correo, numero, dni, sexo, direccion;
	int edad;
	int lleno;
} recluta;

// recluta rec[N];

//Funcion Principal
int main(){
	srand(time(NULL));
	elegirRol();
	getch();

	return 0;
}


//Declaracion de Funciones
void elegirRol(){
	char op;
	int opcion;
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
		cout<<"  3. Voluntarios"<<endl;
		//cout<<"  0.Salir"<<endl;
		cout<<"\n  Ingresar opcion: ";
		cin>>op;
		if(op != '1' && op != '2' && op != '3')
		{
			cout<<"\n\n  Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
		
	}while(op != '1' && op != '2' && op != '3');

	switch(op) {
		case '1':
			menuDarAdopcion(); 
			break;
		case '2': 
			adopcion();
			break;
		case '3':
		{
		system("cls");
			cout<<"\tVOLUNTARIOS"<<endl;
			cout<<"1) Inscribir voluntarios"<<endl;
			cout<<"2) Lista de voluntarios"<<endl;
			cout<<"Opcion: ";
			cin>>opcion;
			switch (opcion)
			{
			case 1:
				reclutar();
				break;
			case 2:
				listarV();
			default:
				break;
			}
		}	
			break;
		default:
			cout<<"No se ha encontrado la opción. ";
	}

}

void menuDarAdopcion(){
	char op;
	char seguir;
	do{
		limpiarPantalla();
		cout<<"\n\n  -- MENU PARA DAR EN ADOPCION --"<<endl;
		cout<<"\n  1. Perro"<<endl;
		cout<<"  2. Gato"<<endl;
		cout<<"  3. Salir"<<endl;
		cout<<"\n  Ingresar opcion: "; 
		cin>>op;
		
		if(op != '1' && op != '2' && op != '3'){
			cout<<"\n\n Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}
			
	}while(op != '1' && op != '2' && op != '3');
	

	switch(op) {
		case '1': 
			{
				limpiarPantalla();
				char opcion = menuAdoptar("PERROS");
			
				if(opcion == '1') ingresar("perro");
				if(opcion == '2') modificar("perro");
				if(opcion == '3')
				{	
					listar("perro");
					cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
					cout<<"\nOpcion: "; cin>>seguir;

					if(seguir == 'S' || seguir == 's') {
					elegirRol();
					}
					else 
					{
						exit(0);
					}
				}
				
				break;
			};
		case '2': 
			{
				limpiarPantalla();
				char opcion = menuAdoptar("GATOS");
			
				if(opcion == '1') ingresar("gato");
				if(opcion == '2') modificar("gato");
				if(opcion == '3')
				{	
					listar("gato");
					cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
					cout<<"\nOpcion: "; cin>>seguir;

					if(seguir == 'S' || seguir == 's') {
					elegirRol();
					}
					else 
					{
						exit(0);
					}
				}
				break;
			};
		default:
			exit(0);
	}
	
	// if (op == '2'){
	// 	int a = 0;
	// 	for(int i = 0; i < 10 && a == 0; i++){
	// 		if ( pe[i].lleno == 1) a = 1;
	// 	}

	// 	if(a == 0){
	// 		cout<<"No hay gatos. Primero se debe ingresar un gato.";
	// 		cout<<"Presione una tecla para continuar..";
	// 		getch();
	// 		elegirRol();
	// 	}
	// 	else       
	// 		adopcion();
	// }		
}
 
void reclutar()
{	
	char seguir;
	ofstream archivo;
	archivo.open("voluntariosDB.txt", ios::app);

	if(archivo.fail()) cout<<"\nHa ocurrido un eror al abrir el registro de voluntarios...";
	
	limpiarPantalla();
	cout<<"FORMULARIO DE INSCRIPCION A VOLUNTARIOS"<<endl;
	
	do {
		fflush(stdin);
		cout<<"\n Nombre: ";
		getline(cin, recluta.nombre);
		
		cout<<"\n Edad: ";
		cin>>recluta.edad;
		fflush(stdin);

		cout<<"\n Sexo(M o F): ";
		getline(cin, recluta.sexo);
		fflush(stdin);
		
		cout<<"\n DNI: ";
		getline(cin, recluta.dni);
		fflush(stdin);
		
		cout<<"\n Correo electronico: ";
		getline(cin, recluta.correo);
		fflush(stdin);
		
		cout<<"\n Numero de celular: ";		
		getline(cin, recluta.numero);
		fflush(stdin);
		
		cout<<"\n Direccion de residencia ";		
		getline(cin, recluta.direccion);
		fflush(stdin);

		archivo<<recluta.nombre<<endl; 
		archivo<<recluta.edad<<endl;
		archivo<<recluta.sexo<<endl;
		archivo<<recluta.dni<<endl;
		archivo<<recluta.correo<<endl;
		archivo<<recluta.numero<<endl;
		archivo<<recluta.direccion<<endl;
	
		cout<<"\n\n  Que desea hacer ahora?"<<endl; 
		cout<<"\n  (1) Ingresar los datos de otro voluntario"<<endl;
		cout<<"  (2) Ir al menu principal"<<endl;
		cout<<"\nOpcion: "; cin>>seguir;

	}while (seguir != '2');

	archivo.close();
	elegirRol();
}

void ingresar(string tipo){
	char seguir;

	ofstream archivo;
	archivo.open("mascotasDB.txt", ios::app);

	if(archivo.fail()) cout<<"Ha ocurrido un error al abrir el archivo...";

	limpiarPantalla();
	cout<<"\n\t//// INGRESO DE "<<tipo<<" ////";
	
	do {	
		fflush(stdin); 
		cout<<"\n  Nombre: ";
		getline(cin, mascota.nombre);
		fflush(stdin); 
				
		cout<<"\n  Fecha de ingreso: "; 
		getline(cin, mascota.fecha);
		fflush(stdin);
				
		cout<<"\n  Raza: "; 
		getline(cin, mascota.raza);
		fflush(stdin);

		cout<<"\n  Distrito: "; 
		getline(cin, mascota.distrito);
		fflush(stdin);

		cout<<"\n  Sexo: "; 
		getline(cin, mascota.sexo);
		fflush(stdin);
				
		cout<<"\n  Edad: "; 
		cin>>mascota.edad;
		fflush(stdin);

		mascota.codigo = 1000 + rand()%(2001 - 1000);
		mascota.tipo = tipo;
		archivo<<mascota.codigo<<endl; 
		archivo<<mascota.nombre<<endl; 
		archivo<<mascota.fecha<<endl; 
		archivo<<mascota.raza<<endl; 
		archivo<<mascota.distrito<<endl; 
		archivo<<mascota.sexo<<endl; 
		archivo<<mascota.tipo<<endl; 
		archivo<<mascota.edad<<endl;
	
		cout<<"\n\n  Que desea hacer ahora?"<<endl; 
		cout<<"\n  (1) Ingresar los datos de otro "<<tipo<<endl;
		cout<<"  (2) Ir al menu principal"<<endl;
		cout<<"\nOpcion: "; cin>>seguir;

	}while (seguir != '2');

	archivo.close();
	elegirRol();
}

void listar(string tipo){
	ifstream archivo;
	archivo.open("mascotasDB.txt", ios::in);

	if(archivo.fail()) cout<<"Hubo un error al abrir el archivo...";

	limpiarPantalla();
	
	tipo == "perro"
		?	cout<<"\n\tLISTA DE PERRITOS "<<endl
		: cout<<"\n\tLISTA DE GATITOS "<<endl;
	archivo>>mascota.codigo;
	while(!archivo.eof()) 
	{
		cout<<"\n\n  ///////////////////////////////////////////////////";
		cout<<"\n\n\t\t C A R N E T "<<endl;
			
		if(mascota.edad > 7) 
		{
			cout<<"\n\nEstado: \tNo factible para dar en adopcion";
		}
		else
		{
			cout<<"\n\nEstado: \tFactible de dar en adopcion";
		}
		archivo>>mascota.nombre;
		archivo>>mascota.fecha;
		archivo>>mascota.raza;
		archivo>>mascota.distrito;
		archivo>>mascota.sexo;
		archivo>>mascota.tipo;
		archivo>>mascota.edad;

		if(mascota.tipo == tipo) {
			cout<<"\n  Codigo:             "<<mascota.codigo;
			cout<<"\n  Nombre:             "<<mascota.nombre;
			cout<<"\n  Fecha de ingreso:   "<<mascota.fecha;
			cout<<"\n  Raza:               "<<mascota.raza;
			cout<<"\n  Distrito:           "<<mascota.distrito;
			cout<<"\n  Sexo: 	      "<<mascota.sexo;
			cout<<"\n  Edad:               "<<mascota.edad;
			cout<<"\n\n-----------------------"<<endl;
		}
		
		archivo>>mascota.codigo;
	}

	archivo.close();

}

void modificar(string tipo){
	int codigo;
	char op, seguir;
	bool existe = false;

	ifstream archivo;
	ofstream tempo;
	archivo.open("mascotasDB.txt", ios::in);
	tempo.open("tempo.txt", ios::out);

	if(archivo.fail()) cout<<"Hubo un error al abrir el archivo...";

	limpiarPantalla();
	
	cout<<"\n\t-- MODIFICAR MASCOTA --"<<endl;
		if(tipo =="perro")
		{
		listar("perro");
	} 
	else 
	{
		//tipo = "gato";
		listar("gato");
	}
	cout<<"\nIngrese el codigo de la mascota a modificar: ";
	cin>>codigo;
	
	archivo>>mascota.codigo;
	while(!archivo.eof()) {
		archivo>>mascota.nombre;
		archivo>>mascota.fecha;
		archivo>>mascota.raza;
		archivo>>mascota.distrito;
		archivo>>mascota.sexo;
		archivo>>mascota.tipo;
		archivo>>mascota.edad;

		if(mascota.tipo == tipo && mascota.codigo == codigo) {
			cout<<"\n///Datos del "<<tipo<<" a modificar///"<<endl;
			cout<<"\nCodigo: "<<mascota.codigo;
			cout<<"\nNombre:            "<<mascota.nombre;
			cout<<"\nFecha de ingreso:  "<<mascota.fecha;
			cout<<"\nRaza:              "<<mascota.raza;
			cout<<"\nDistrito:          "<<mascota.distrito;
			cout<<"\nSexo: 		   "<<mascota.sexo;
			cout<<"\nEdad:              "<<mascota.edad;
			cout<<"\n----------------------------------------";

			struct newMascota {
				int nCodigo, nEdad;
				string nNombre, nFecha, nRaza, nDistrito, nSexo;
			} N;

			cout<<"\n\nIngrese un nuevo codigo o 0 para no modificar: ";
			cin>>N.nCodigo;

			if(N.nCodigo == 0) N.nCodigo == mascota.codigo;
			fflush(stdin);
			cout<<"\n\nIngrese un nuevo nombre o 'f' para no modificar: ";
			getline(cin, N.nNombre);
			fflush(stdin);

      if(N.nNombre == "f" || N.nNombre == "F") N.nNombre = mascota.nombre;

			cout<<"\n\nIngrese la nueva fecha o 'f' para no modificar: ";
			getline(cin, N.nFecha);
			fflush(stdin);

      if(N.nFecha == "f" || N.nFecha == "F") N.nFecha = mascota.fecha;

			cout<<"\n\nIngrese la nueva raza o 'f' para no modificar: ";
			getline(cin, N.nRaza);
			fflush(stdin);

      if(N.nRaza == "f" || N.nRaza == "F") N.nRaza = mascota.raza;

			cout<<"\n\nIngrese el nuevo distrito o 'f' para no modificar: ";
			getline(cin, N.nDistrito);
			fflush(stdin);

      if(N.nDistrito == "f" || N.nDistrito == "F") N.nDistrito = mascota.distrito;

			cout<<"\n\nIngrese el nuevo sexo o 'f' para no modificar: ";
			getline(cin, N.nSexo);
			fflush(stdin);

      if(N.nSexo == "f" || N.nSexo == "F") N.nSexo = mascota.sexo;

			cout<<"\n\nIngrese la nueva edad o 0 para no modificar: ";
			cin>>N.nEdad;

      if(N.nEdad == 0) N.nEdad = mascota.codigo;

			//tempo<<N.nCodigo<<" "<<N.nNombre<<" "<<N.nFecha<<" "<<N.nRaza<<" "<<N.nDistrito<<" "<<N.nSexo<<" "<<mascota.tipo<<" "<<N.nEdad;
			tempo<<N.nCodigo<<endl; 
			tempo<<N.nNombre<<endl; 
			tempo<<N.nFecha<<endl; 
			tempo<<N.nRaza<<endl; 
			tempo<<N.nDistrito<<endl; 
			tempo<<N.nSexo<<endl; 
			tempo<<mascota.tipo<<endl; 
			tempo<<N.nEdad<<endl;	
			existe = true;
		} 
		else 
		{
			tempo<<mascota.codigo<<endl; 
			tempo<<mascota.nombre<<endl; 
			tempo<<mascota.fecha<<endl; 
			tempo<<mascota.raza<<endl; 
			tempo<<mascota.distrito<<endl; 
			tempo<<mascota.sexo<<endl; 
			tempo<<mascota.tipo<<endl; 
			tempo<<mascota.edad<<endl;	
		}

		archivo>>mascota.codigo;
	}

	if(!existe) {
		cout<<"\nEl "<<tipo<<" con codigo "<<codigo<<" no se encuentra en el albergue.";
	}

	archivo.close();
	tempo.close();
	remove("mascotasDB.txt");
	rename("tempo.txt", "mascotasDB.txt");

	cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
	cout<<"\nOpcion: "; cin>>seguir;

	if(seguir == 'S' || seguir == 's') {
		elegirRol();
	}else {
		exit(0);
	}
}

void adopcion(){
	int codigo;
	string tipo = "";
	char op, opAdoptar, seguir;
	bool existe = false;

	ifstream archivo;
	ofstream tempo;
	archivo.open("mascotasDB.txt", ios::in);
	tempo.open("tempo.txt", ios::out);

	if(archivo.fail()) cout<<"Hubo un error al abrir el archivo...";
	
	do{
		limpiarPantalla();
		cout<<"\n\tESPECIE DE MASCOTA A ADOPTAR";
		cout<<"\n\n  1. Perro"<<endl;
		cout<<"  2. Gato"<<endl;
		cout<<"\nIngrese una opcion: ";
		cin>>op;

		if(op!='1' && op!='2') cout<<"\nOpcion invalida. Ingrese otra.";

	}while(op != '1' && op != '2');

	limpiarPantalla();
	if(op == '1'){
		tipo = "perro";
		listar("perro");
	} else {
		tipo = "gato";
		listar("gato");
	}
	
	cout<<"\nIngrese el codigo de la mascota que desea adoptar: ";
	cin>>codigo;

	archivo>>mascota.codigo;
	while(!archivo.eof()) {
		archivo>>mascota.nombre;
		archivo>>mascota.fecha;
		archivo>>mascota.raza;
		archivo>>mascota.distrito;
		archivo>>mascota.sexo;
		archivo>>mascota.tipo;
		archivo>>mascota.edad;

		if(mascota.tipo == tipo && mascota.codigo == codigo) {
			cout<<"\n\n  ///////////////////////////////////////////////////";
			cout<<"\n\n\t\t C A R N E T "<<endl;
			
			if(mascota.edad > 7) {
				cout<<"\n\nEstado: \tNo factible para dar en adopcion";
			} else {
				cout<<"\n\nEstado: \tFactible de dar en adopcion";
			}

			cout<<"\n\tCodigo:            "<<mascota.codigo;
			cout<<"\n\tNombre:            "<<mascota.nombre;
			cout<<"\n\tFecha de ingreso:            "<<mascota.fecha;
			cout<<"\n\tRaza:            "<<mascota.raza;
			cout<<"\n\tDistrito:            "<<mascota.distrito;
			cout<<"\n\tSexo:            "<<mascota.sexo;
			cout<<"\n\tEdad:            "<<mascota.edad;
			cout<<"\n\n  ///////////////////////////////////////////////////";

			do {
				cout<<"\n\nDesea adoptar la mascota?";
				cout<<"\n\n 1. Si"<<endl;
				cout<<" 2. No"<<endl;
				cout<<"\nOpcion: ";
				cin>>opAdoptar;
			} while (opAdoptar != '1' && opAdoptar != '2');

			if(opAdoptar == '1') {
				Sleep(700);
				cout<<"\n\nMASCOTA ADOPTADA CORRECTAMETE";
			} else {
				char otraMascota;
				do {
					cout<<"\n\nDesea adoptar otra mascota?";
					cout<<"\n\n 1. Si"<<endl;
					cout<<" 2. No"<<endl;
					cout<<"\nOpcion: ";
					cin>>otraMascota;
				} while (otraMascota != '1' && otraMascota != '2');

				if(otraMascota == '1') {
					adopcion();
				}else {
					getch();
					main();
				}

			}

			existe = true;
		} 
		else 
		{
			tempo<<mascota.codigo<<endl; 
			tempo<<mascota.nombre<<endl; 
			tempo<<mascota.fecha<<endl; 
			tempo<<mascota.raza<<endl; 
			tempo<<mascota.distrito<<endl; 
			tempo<<mascota.sexo<<endl; 
			tempo<<mascota.tipo<<endl; 
			tempo<<mascota.edad<<endl;			
		}
		
		archivo>>mascota.codigo;
	}

	if(!existe) {
		cout<<"\nEl "<<tipo<<" con codigo "<<codigo<<" no se encuentra en el albergue.";
	}

	archivo.close();
	tempo.close();
	remove("mascotasDB.txt");
	rename("tempo.txt", "mascotasDB.txt");

	cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
	cout<<"\nOpcion: "; cin>>seguir;

	if(seguir == 'S' || seguir == 's') {
		main();
	}else {
		exit(0);
	}
}

char menuAdoptar(string texto) {
	char opcion;
	do{
		cout<<"\n\t\t/////////////////////////////////////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t////            "<<texto<<"           ////"<<endl;
		cout<<"\t\t////                             ////"<<endl;
		cout<<"\t\t/////////////////////////////////////";
		cout<<"\n\n  1. Agregar"<<endl;
		cout<<"  2. Modificar"<<endl;
		cout<<"  3. Ver "<<texto<<" del albergue"<<endl;
		cout<<"\n  Ingrese opcion: ";
		cin>>opcion;
		
		if(opcion != '1' && opcion != '2' && opcion != '3'){
			cout << "\n  Error al ingresar valores. Presione una tecla para volver a ingresar..";
			getch();
			limpiarPantalla();
		}
			
	}while(opcion != '1' && opcion != '2' && opcion != '3');

	return opcion;	
}

void limpiarPantalla(){
	system("CLS");
}
void listarV()
{
    int cont=0;
    ifstream read("voluntariosDB.txt", ios::in);
    read>>recluta.nombre;
    while(!read.eof())
    {
        cont++;
        read>>recluta.edad;
        read>>recluta.sexo; 
        read>>recluta.dni; 
        read>>recluta.correo; 
        read>>recluta.numero; 
        read>>recluta.direccion;
        cout<<"\tRECLUTA "<<cont<<endl;
        cout<<"Nombre: "<<recluta.nombre<<endl;
        fflush(stdin);
        cout<<"Edad: "<<recluta.edad<<endl;
        cout<<"Genero: "<<recluta.sexo<<endl;
        cout<<"DNI: "<<recluta.dni<<endl;
        cout<<"Correo: "<<recluta.correo<<endl;
        cout<<"Numero: "<<recluta.numero<<endl;
        cout<<"Direccion: "<<recluta.direccion<<endl; 
        read>>recluta.nombre;
    }
    
    read.close();
    system("pause");
	elegirRol();
    system("cls");
}
