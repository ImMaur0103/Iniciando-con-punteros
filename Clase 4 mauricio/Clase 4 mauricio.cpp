#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;


//Convertir de .Net hacia char*
char* ConvertDotNetAChar(System::String ^cadena) {
	char* cad2 = (char*)(void*)Marshal::StringToHGlobalAnsi(cadena);
	return cad2;
};

//Convierte de Char* a .Net
System::String ^ConvertCharADotNet(char* cadena) {
	String ^cad2 = gcnew String(cadena);
	return cad2;
};

//Convierto de char* hacia StdString
std::string ConvertCharAStdString(char* cadena) {
	std::string cad2(cadena);
	return cad2;
};

//Conviert de stdString a char*
char* ConvertStdStringAChar(std::string cadena) {
	char *cad2 = new char[cadena.length() + 1];
	cad2 = strdup(cadena.c_str());
	return cad2;
};

class Nodo {
public:
	int Edad;
	char *Nombre;
	Nodo *siguiente;
};

class Lista {
public:
	Nodo *inicio;
	Nodo *fin;

	void Insertar(Nodo *nuevo) {
		if (inicio == nullptr) { //Es el primer nodo
			inicio = nuevo;
			fin = nuevo;
		}
		else  //Si no es el primero inserto al final
		{
			fin->siguiente = nuevo;
			fin = nuevo;
		}

	};
};

int main(array<System::String ^> ^args)
{
	int hola[] = { 1,2 };
	int pri[] = { 3,7 };
	int hola2[][2] = { { 1,2 }, { 3,4 } };
	int* prueba[2] = { hola , pri };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Console::Write(prueba[j][i] + " | ");
		}
		Console::WriteLine();
	}
	Console::WriteLine("Ingrese cadena: ");
	String ^cadenaIngreso1 = Console::ReadLine();

	char *cadenaChar = ConvertDotNetAChar(cadenaIngreso1);
	std::string cadenaSalida1 = ConvertCharAStdString(cadenaChar);

	std::cout << cadenaSalida1 << "\r\n";

	//Proceso inverso
	std::cout << "Ingrese nueva cadena" << "\r\n";

	std::string cadenaIngreso2;
	std::getline(std::cin, cadenaIngreso2);

	char* cadenaChar2 = ConvertStdStringAChar(cadenaIngreso2);
	System::String ^cadenaSalida2 = ConvertCharADotNet(cadenaChar2);

	Console::WriteLine(cadenaSalida2);

	int option = 1;
	Lista *milista = new Lista();

	do {
		Console::WriteLine("Ingrese Nombre");
		System::String ^name = Console::ReadLine();

		Console::WriteLine("Ingrese la edad");
		int age;
		std::cin >> age;

		Nodo *nuevo = new Nodo();
		nuevo->Edad = age;
		nuevo->Nombre = ConvertDotNetAChar(name);

		milista->Insertar(nuevo);

		Console::WriteLine("Si desea ingresar otro presione 1 de lo contrario 0");

		option = Convert::ToInt32(Console::ReadLine());

	} while (option == 1);

	return 0;
}

