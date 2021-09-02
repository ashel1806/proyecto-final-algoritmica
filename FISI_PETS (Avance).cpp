#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <regex>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <iostream>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

//Prototipo de funciones a utilizar

//Funciones Principales
void elegirRol();
void menuDarAdopcion();
void reclutar();
void ingresar(string tipo);
void listarMascotas(string tipo);
void modificar(string tipo);
char menuAdoptar(string texto);
void adopcion();
void listarVoluntarios();

// void cursorOn(bool visible, DWORD size);
// void cursorOff();
void gotoxy(int x, int y);
void drawRectangle(int x1, int y1, int x2, int y2);

//Funciones auxiliares
void limpiarPantalla();
string saveToTXT(string str);
string outputString(string str);

//Estructuras de las mascotas a adoptar
struct Mascota{
	int codigo;
	string nombre, fecha, raza, distrito, sexo, tipo;
	int edad;
} mascota;

//Estructura de los voluntarios
struct Recluta {
	string nombre, correo, numero, dni, sexo, direccion;
	int edad;
	int lleno;
} recluta;

//Funcion Principal
int main(){
  system("mode con: cols=80 lines=30");
	system("COLOR 70"); //Para cambiar el color de la consola
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
		drawRectangle(1, 1, 78, 29);
  	drawRectangle(3,3, 76, 7);
  	gotoxy(15, 5); cout<<"! B I E N V E N I D O    A    F I S I    P E T S !";
		gotoxy(30, 9); cout<<"-- ELEGIR ACCION --";
		gotoxy(3, 11); cout<<"[1] Dar en adopcion";
		gotoxy(3, 12); cout<<"[2] Adoptar una mascota";
		gotoxy(3, 13); cout<<"[3] Voluntarios";
		gotoxy(3, 15); cout<<"[0] Salir";
		gotoxy(3, 17); cout<<"Ingresar opcion: ";
		cin>>op;

		if(op != '1' && op != '2' && op != '3' && op!='0')
		{
			gotoxy(3,19); cout<<"Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}

	}while(op != '1' && op != '2' && op != '3' && op!='0');

	switch(op)
	{
		case '1':
			menuDarAdopcion();
			break;
		case '2':
			adopcion();
			break;
		case '3':
		{
			limpiarPantalla();
			drawRectangle(3,3, 76, 7);
			gotoxy(15, 5); cout<<"V O L U N T A R I O S";
			gotoxy(3, 9); cout<<"[1] Inscribir voluntarios";
			gotoxy(3, 10); cout<<"[2] Lista de voluntarios";
			gotoxy(3, 12); cout<<"Ingresar Opcion: ";
			cin>>opcion;

			switch (opcion) {
				case 1:
					reclutar();
					break;
				case 2:
					listarVoluntarios();
					break;
				default:
					gotoxy(3, 14); cout<<"Opcion no valida.";
					break;
			}
			break;
		};
		default:
			exit(0);
	}

}

void menuDarAdopcion(){
	char op;
	char seguir;
	do {
		limpiarPantalla();
  	drawRectangle(3,3, 76, 7);
  	gotoxy(15, 5); cout<<"D A R   E N   A D O P C I O N";
		gotoxy(3, 10); cout<<"[1] Perro";
		gotoxy(3, 11); cout<<"[2] Gato";
		gotoxy(3, 12); cout<<"[3] Volver atras";
		gotoxy(3, 14); cout<<"Ingresar opcion: ";
		cin>>op;

		if(op != '1' && op != '2' && op != '3'){
			gotoxy(3, 16); cout<<"Opcion invalida. Presione una tecla para elegir otra opcion. ";
			getch();
		}

	}while(op != '1' && op != '2' && op != '3');

	switch(op)
	{
		case '1':
			{
				limpiarPantalla();
				char opcion = menuAdoptar("perro");

				if(opcion == '1') ingresar("perro");
				if(opcion == '2') modificar("perro");
				if(opcion == '3')
				{
					listarMascotas("perro");
					gotoxy(3, 10); cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
					cout<<"\nOpcion: "; cin>>seguir;

					if(seguir == 'S' || seguir == 's')
					{
						main();
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
				char opcion = menuAdoptar("gato");

				if(opcion == '1') ingresar("gato");
				if(opcion == '2') modificar("gato");
				if(opcion == '3')
				{
					listarMascotas("gato");
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
}

void reclutar()
{
	char seguir;
	ofstream archivo;
	archivo.open("voluntariosDB.txt", ios::app);

	if(archivo.fail()) cout<<"\nHa ocurrido un eror al abrir el registro de voluntarios...";

	limpiarPantalla();
	drawRectangle(3,3, 76, 7);
	gotoxy(15, 5); cout<<"F O R M U L A R I O   D E   I N S C R I P C I O N";

	do {
		fflush(stdin);
		gotoxy(3, 9); cout<<"Nombre: ";
		getline(cin, recluta.nombre);

		gotoxy(40, 9); cout<<"Edad: ";
		cin>>recluta.edad;
		fflush(stdin);

		gotoxy(3, 11); cout<<"Sexo: ";
		getline(cin, recluta.sexo);
		fflush(stdin);

		do {
			gotoxy(40, 11); cout<<"                   ";
			gotoxy(40, 11); cout<<"DNI: ";
			getline(cin, recluta.dni);
			fflush(stdin);

			if(!regex_match(recluta.dni, regex("\\d{8}")))
			{
				gotoxy(40, 13); cout<<"El numero de DNI debe tener 8 numeros.";
				Sleep(1000);
				gotoxy(40, 13); cout<<"                                      ";
			}

		} while(!regex_match(recluta.dni, regex("\\d{8}")));

		do {
			gotoxy(3, 13); cout<<"                                        ";
			gotoxy(3, 13); cout<<"Correo electronico: ";
			getline(cin, recluta.correo);

			if(!regex_match(recluta.correo, regex("^[^@\\s]+@[^@\\s]+\.[^@\\s]+$")))
			{
				gotoxy(3, 15); cout<<"Digite un correo valido por favor.";
				Sleep(1000);
				gotoxy(3, 15); cout<<"                                     ";
			}

		} while(!regex_match(recluta.correo, regex("^[^@\\s]+@[^@\\s]+\.[^@\\s]+$")));

		do {
			gotoxy(3, 15); cout<<"                               ";
			gotoxy(3, 15); cout<<"Numero de celular: ";
			getline(cin, recluta.numero);
			fflush(stdin);

			if(!regex_match(recluta.numero, regex("\\d{9}")))
			{
				gotoxy(3, 17); cout<<"El numero de celular debe tener 9 digitos.";
				Sleep(1000);
				gotoxy(3, 17); cout<<"                                            ";
			}

		} while(!regex_match(recluta.numero, regex("\\d{9}")));

		gotoxy(3, 17); cout<<"Direccion de residencia: ";
		getline(cin, recluta.direccion);
		fflush(stdin);

		archivo<<recluta.nombre<<endl;
		archivo<<recluta.edad<<endl;
		archivo<<recluta.sexo<<endl;
		archivo<<recluta.dni<<endl;
		archivo<<recluta.correo<<endl;
		archivo<<recluta.numero<<endl;
		archivo<<saveToTXT(recluta.direccion)<<endl;

		gotoxy(3, 19); cout<<"Que desea hacer ahora?";
		gotoxy(3, 20); cout<<"[1] Ingresar los datos de otro voluntario";
		gotoxy(3, 21); cout<<"[2] Ir al menu principal";
		gotoxy(3, 23); cout<<"Ingresar Opcion: "; cin>>seguir;

	}while (seguir != '2');

	archivo.close();
	main();
}

void ingresar(string tipo){
	char seguir;
	string text;

	text = tipo == "perro" ? "P E R R O S" : "G A T O S";

	ofstream archivo;
	archivo.open("mascotasDB.txt", ios::app);

	if(archivo.fail())
	{
	  gotoxy(3, 9); cout<<"Ha ocurrido un error al abrir el archivo...";
	}

	limpiarPantalla();
	drawRectangle(3,3, 76, 7);
	gotoxy(15, 5); cout<<"I N G R E S O   DE   "<<text;

	do {
		limpiarPantalla();
		drawRectangle(3,3, 76, 7);
		gotoxy(15, 5); cout<<"I N G R E S O   DE   "<<text;

		mascota.codigo = 1000 + rand()%(2001 - 1000);

		gotoxy(3, 9); cout<<"Codigo: "<<mascota.codigo;

		fflush(stdin);
		gotoxy(40, 9); cout<<"Nombre: ";
		getline(cin, mascota.nombre);
		fflush(stdin);

		//Inicializando la hora local
		time_t now = time(0); //Obtener la fecha actual
		tm* localtm = localtime(&now); //Obtener la fecha de la pc

		gotoxy(3, 11); cout<<"Fecha de ingreso: "<<asctime(localtm);
		mascota.fecha = asctime(localtm);
		//Modificando la ultima linea por un espacio simple
		int tam = mascota.fecha.length();
		mascota.fecha[tam-1] = ' ';
		fflush(stdin);

		gotoxy(3, 13); cout<<"Raza: ";
		getline(cin, mascota.raza);
		fflush(stdin);

		gotoxy(40, 13); cout<<"Sexo: ";
		getline(cin, mascota.sexo);
		fflush(stdin);

		gotoxy(3, 15); cout<<"Distrito: ";
		getline(cin, mascota.distrito);
		fflush(stdin);

		gotoxy(40, 15); cout<<"Edad: ";
		cin>>mascota.edad;
		fflush(stdin);

		mascota.tipo = tipo;
		archivo<<mascota.codigo<<endl;
		archivo<<mascota.nombre<<endl;
		archivo<<saveToTXT(mascota.fecha)<<endl;
		archivo<<mascota.raza<<endl;
		archivo<<saveToTXT(mascota.distrito)<<endl;
		archivo<<mascota.sexo<<endl;
		archivo<<mascota.tipo<<endl;
		archivo<<mascota.edad<<endl;

		gotoxy(3, 17); cout<<"Que desea hacer ahora?";
		gotoxy(3, 18); cout<<"[1] Ingresar los datos de otro "<<tipo;
		gotoxy(3, 19); cout<<"[2] Ir al menu principal";
		gotoxy(3, 21); cout<<"Ingresar Opcion: "; cin>>seguir;

	}while (seguir != '2');

	archivo.close();
	main();
}

void listarMascotas(string tipo)
{
	int y = 12;
	string text;

	text = tipo == "perro" ? "P E R R O S" : "G A T O S";

	ifstream archivo;
	archivo.open("mascotasDB.txt", ios::in);

	limpiarPantalla();
	if(archivo.fail())
	{
		gotoxy(3, 9); cout<<"Hubo un error al abrir el archivo...";
	}

	drawRectangle(3,3, 76, 7);
	gotoxy(15, 5); cout<<"L I S T A   DE   "<<text;

	archivo>>mascota.codigo;
	if(mascota.codigo == NULL)
	{
		gotoxy(3, 9); cout<<"Aun no hay "<<tipo<<"s en el albergue."<<endl<<endl;
		getch();
		main();
	}

	gotoxy(4, 10); cout<<"Codigo";
	gotoxy(13, 10); cout<<"Nombre";
	gotoxy(24, 10); cout<<"Raza";
	gotoxy(36, 10); cout<<"Distrito";
	gotoxy(60, 10); cout<<"Sexo";
	gotoxy(68, 10); cout<<"Edad";
	for(int i = 4; i < 75; i++)
	{
		gotoxy(i, 11); printf("%c", 196);
	}

	while(!archivo.eof())
	{
		archivo>>mascota.nombre;
		archivo>>mascota.fecha;
		archivo>>mascota.raza;
		archivo>>mascota.distrito;
		archivo>>mascota.sexo;
		archivo>>mascota.tipo;
		archivo>>mascota.edad;

		if(mascota.tipo == tipo)
		{
			gotoxy(4, y); cout<<mascota.codigo;
			gotoxy(13, y); cout<<mascota.nombre;
			gotoxy(24, y); cout<<mascota.raza;
			gotoxy(36, y); cout<<outputString(mascota.distrito);
			gotoxy(60, y); cout<<mascota.sexo;
			gotoxy(68, y); cout<<mascota.edad;
		}

		archivo>>mascota.codigo;
		y++;
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

	if(archivo.fail()) gotoxy(3, 9); cout<<"Hubo un error al abrir el archivo...";

	limpiarPantalla();

	drawRectangle(3,3, 76, 7);
	gotoxy(15, 5); cout<<"M O D I F I C A R   M A S C O T A";

	tipo == "perro" ? listarMascotas("perro") : listarMascotas("gato");

	gotoxy(3, 23); cout<<"Ingrese el codigo de la mascota a modificar: ";
	cin>>codigo;
	gotoxy(3, 23); cout<<"                                                    ";

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
			limpiarPantalla();
			drawRectangle(3,3, 76, 7);
			gotoxy(15, 5); cout<<"M O D I F I C A R   M A S C O T A";

			gotoxy(3, 9); cout<<"/// Datos del "<<tipo<<" a modificar ///";
			gotoxy(3, 11); cout<<"Codigo:            "<<mascota.codigo;
			gotoxy(3, 12); cout<<"Nombre:            "<<mascota.nombre;
			gotoxy(3, 13); cout<<"Fecha de ingreso:  "<<mascota.fecha;
			gotoxy(3, 14); cout<<"Raza:              "<<mascota.raza;
			gotoxy(3, 15); cout<<"Distrito:          "<<mascota.distrito;
			gotoxy(3, 16); cout<<"Sexo: 		         "<<mascota.sexo;
			gotoxy(3, 17); cout<<"Edad:              "<<mascota.edad;

			struct newMascota {
				int nCodigo, nEdad;
				string nNombre, nFecha, nRaza, nDistrito, nSexo;
			} N;

			gotoxy(3, 18); cout<<"Ingrese un nuevo codigo o 0 para no modificar: ";
			cin>>N.nCodigo;

			if(N.nCodigo == 0) N.nCodigo == mascota.codigo;
			fflush(stdin);

			gotoxy(3, 19); cout<<"Ingrese un nuevo nombre o 'f' para no modificar: ";
			getline(cin, N.nNombre);
			fflush(stdin);

      if(N.nNombre == "f" || N.nNombre == "F") N.nNombre = mascota.nombre;

      N.nFecha = mascota.fecha;

			gotoxy(3, 20); cout<<"\n\nIngrese la nueva raza o 'f' para no modificar: ";
			getline(cin, N.nRaza);
			fflush(stdin);

      if(N.nRaza == "f" || N.nRaza == "F") N.nRaza = mascota.raza;

			gotoxy(3, 21); cout<<"Ingrese el nuevo distrito o 'f' para no modificar: ";
			getline(cin, N.nDistrito);
			fflush(stdin);

      if(N.nDistrito == "f" || N.nDistrito == "F") N.nDistrito = mascota.distrito;

			gotoxy(3, 22); cout<<"Ingrese el nuevo sexo o 'f' para no modificar: ";
			getline(cin, N.nSexo);
			fflush(stdin);

      if(N.nSexo == "f" || N.nSexo == "F") N.nSexo = mascota.sexo;

			gotoxy(3, 23); cout<<"Ingrese la nueva edad o 0 para no modificar: ";
			cin>>N.nEdad;

      if(N.nEdad == 0) N.nEdad = mascota.codigo;

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
		gotoxy(3, 9); cout<<"El "<<tipo<<" con codigo "<<codigo<<" no se encuentra en el albergue.";
	}

	archivo.close();
	tempo.close();
	remove("mascotasDB.txt");
	rename("tempo.txt", "mascotasDB.txt");

	gotoxy(3, 24); cout<<"  Desea ir al menu principal? (S)i/(N)o: "<<endl;
	cin>>seguir;

	if(seguir == 'S' || seguir == 's') elegirRol();
	else exit(0);
}

void adopcion()
{
	int codigo;
	string tipo = "";
	char op, opAdoptar, seguir;
	bool existe = false;

	ifstream archivo;
	ofstream tempo;
	archivo.open("mascotasDB.txt", ios::in);
	tempo.open("tempo.txt", ios::out);

	if(archivo.fail())
	{
	 	gotoxy(3,9); cout<<"Hubo un error al abrir el archivo...";
	}

	do{
		limpiarPantalla();
		drawRectangle(3,3, 76, 7);
		gotoxy(15, 5); cout<<"A D O P T A R   U N A   M A S C O T A";
		gotoxy(3, 9); cout<<"Elija el tipo de mascota que desee adoptar: ";
		gotoxy(3, 11); cout<<"[1] Perro"<<endl;
		gotoxy(3, 12); cout<<"[2] Gato"<<endl;
		gotoxy(3, 14); cout<<"Ingrese una opcion: ";
		cin>>op;

		if(op!='1' && op!='2')
		{
			gotoxy(3, 16); cout<<"\nOpcion invalida. Ingrese otra.";
		}
	}while(op != '1' && op != '2');

	limpiarPantalla();
	drawRectangle(3,3, 76, 7);

	if(op == '1')
	{
		tipo = "perro";
		gotoxy(15, 5); cout<<"A D O P T A R   U N   P E R R O";
		listarMascotas("perro");
	} else {
		tipo = "gato";
		gotoxy(15, 5); cout<<"A D O P T A R   U N   G A T O";
		listarMascotas("gato");
	}

	gotoxy(3, 9); cout<<"Ingrese el codigo de la mascota que desea adoptar: ";
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

		if(mascota.tipo == tipo && mascota.codigo == codigo)
		{
			limpiarPantalla();
			drawRectangle(1, 1, 78, 24);
  		drawRectangle(3,3, 76, 7);
			gotoxy(15, 5); cout<<" C A R N E T ";

			if(mascota.edad > 7) {
				gotoxy(3, 9); cout<<"Estado:             No factible para dar en adopcion";
			} else {
				gotoxy(3, 9); cout<<"Estado:             Factible de dar en adopcion";
			}

			gotoxy(3, 11); cout<<"Codigo:             "<<mascota.codigo;
			gotoxy(3, 13); cout<<"Nombre:             "<<mascota.nombre;
			gotoxy(3, 15); cout<<"Fecha de ingreso:   "<<mascota.fecha;
			gotoxy(3, 17); cout<<"Raza:               "<<mascota.raza;
			gotoxy(3, 19); cout<<"Distrito:           "<<mascota.distrito;
			gotoxy(3, 21); cout<<"Sexo:               "<<mascota.sexo;
			gotoxy(3, 23); cout<<"Edad:               "<<mascota.edad;

			drawRectangle(1, 25, 78, 30);
			do {
				gotoxy(3, 26); cout<<"Desea adoptar la mascota? (S)i/(N)o: ";
				cin>>opAdoptar;
			} while (opAdoptar != 'S' && opAdoptar != 's');

			if(opAdoptar == 's' || opAdoptar == 'S')
			{
				gotoxy(3, 26); cout<<"                                        ";
				Sleep(700);
				gotoxy(3, 26); cout<<"MASCOTA ADOPTADA CORRECTAMETE !";
			} else {
				char otraMascota;
				do {
					gotoxy(3, 26); cout<<"                                        ";
					gotoxy(3, 26); cout<<"Desea adoptar otra mascota? (S)i/(N)o: ";
					cin>>otraMascota;
				} while (otraMascota != 'S' && otraMascota != 's');

				if(otraMascota == 'S' || otraMascota == 's') {
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

	if(!existe)
	{
		gotoxy(3, 11); cout<<"El "<<tipo<<" con codigo "<<codigo<<" no se encuentra en el albergue.";
	}

	archivo.close();
	tempo.close();
	remove("mascotasDB.txt");
	rename("tempo.txt", "mascotasDB.txt");

	gotoxy(3, 28); cout<<"Desea ir al menu principal? (S)i/(N)o: ";
	cin>>seguir;

	if(seguir == 'S' || seguir == 's') {
		main();
	}else {
		exit(0);
	}
}

char menuAdoptar(string tipo)
{
	char opcion;
	string text;

	text = tipo == "perro" ? "P E R R O S" : "G A T O S";

	do{
		limpiarPantalla();
  	drawRectangle(3,3, 76, 7);
  	gotoxy(15, 5); cout<<"M E N U   D E   "<<text;
		gotoxy(3, 9); cout<<"[1] Agregar";
		gotoxy(3, 10); cout<<"[2] Modificar";
		gotoxy(3, 11); cout<<"[3] Ver "<<tipo<<"s del albergue";
		gotoxy(3, 13); cout<<"Ingrese opcion: ";
		cin>>opcion;

		if(opcion != '1' && opcion != '2' && opcion != '3'){
			gotoxy(3, 15); cout<<"Error al ingresar valores. Presione una tecla para volver a ingresar...";
			getch();
		}

	}while(opcion != '1' && opcion != '2' && opcion != '3');

	return opcion;
}

void listarVoluntarios()
{
  int cont = 0, y = 12;
  ifstream read("voluntariosDB.txt", ios::in);

	limpiarPantalla();

	drawRectangle(3,3, 76, 7);
  gotoxy(15, 5); cout<<"L I S T A   D E   V O L U N T A R I O S";

	gotoxy(4, 10); cout<<"N";
  gotoxy(8, 10); cout<<"Nombre";
  gotoxy(20, 10); cout<<"Edad";
  gotoxy(30, 10); cout<<"Genero";
  gotoxy(45, 10); cout<<"N Celular";

	for(int i = 4; i < 50; i++)
	{
		gotoxy(i, 11); printf("%c", 196);
	}

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

		gotoxy(4, y); cout<<cont;
		gotoxy(8, y); cout<<recluta.nombre;
		gotoxy(20, y); cout<<recluta.edad;
		gotoxy(30, y); cout<<recluta.sexo;
		gotoxy(45, y); cout<<recluta.numero;

		// cout<<"\n\t\tRECLUTA #"<<cont<<endl;
    // cout<<"\n\t  Nombre:      "<<recluta.nombre<<endl;
    // cout<<"\t  Edad:        "<<recluta.edad<<endl;
    // cout<<"\t  Genero:      "<<recluta.sexo<<endl;
    // cout<<"\t  DNI:         "<<recluta.dni<<endl;
    // cout<<"\t  Correo:      "<<recluta.correo<<endl;
    // cout<<"\t  Numero:      "<<recluta.numero<<endl;
    // cout<<"\t  Direccion:   "<<outputString(recluta.direccion)<<endl<<endl;
    read>>recluta.nombre;
		y++;
  }

  read.close();
	// elegirRol();
}

string saveToTXT(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ') str[i] = '.';
	}

	return str;
}

string outputString(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '.') str[i] = ' ';
	}

	return str;
}

void limpiarPantalla(){
	for(int i = 2; i <= 28; i++)
	{
		for(int j = 2; j <= 75; j++)
		{
			gotoxy(j, i); cout<<" ";
		}
	}
}

// void cursorOn(bool visible, DWORD size)
// {
//   if (size == 0) size = 20;

//   CONSOLE_CURSOR_INFO cursor;
//   cursor.bVisible =  visible;
//   cursor.dwSize = size;
//   SetConsoleCursorInfo(console,&cursor);
// }

// void cursorOff()
// {
//   CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
//   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
// }

void gotoxy(int x, int y)
{
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
  int i;
  for(i = x1; i < x2; i++)
  {
    gotoxy(i, y1); printf("%c", 196);
    gotoxy(i, y2); printf("%c", 196);
  }

  for(i = y1; i < y2; i++)
  {
    gotoxy(x1, i); printf("%c", 179);
    gotoxy(x2, i); printf("%c", 179);
  }

  gotoxy(x1, y1); printf("%c", 218);
  gotoxy(x1, y2); printf("%c", 192);
  gotoxy(x2, y1); printf("%c", 191);
  gotoxy(x2, y2); printf("%c", 217);
}