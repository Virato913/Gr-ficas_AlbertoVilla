// Gráficas_AlbertoVilla.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

struct Coordinates
{
	float x, y, z;
	/*void operator<<(Coordinates* out)
	{
		cout << "(" << out->x << ", " << out->y << ", " << out->z << ")";
	}*/
	/*istream& operator >> (Coordinates& in)
	{

	}*/
};

int main()
{
	fstream fFile;
	vector<Coordinates*> MeshList;
	vector<Coordinates*>::iterator it;
	string sIn, sFileName;
	size_t iFound;
	char cChar, cInput;
	int iVertexCount;
	bool bMeshFound;

	do
	{
		bMeshFound = false;
		system("cls");
		cout << "Archivo a abrir: \n1.- CerdoNuevo\n2.- Drone\n3.- NuCroc\n4.- NuVenomJok\n5.- Pig\n6.- Piramid\n7.- Scene\nCualquier otro numero.- Salir\n\n";
		cInput = _getch();
		//MeshList.clear();
		switch (cInput)
		{
		case '1':
			sFileName = "CerdoNuevo";
			break;
		case '2':
			sFileName = "Drone";
			break;
		case '3':
			sFileName = "NuCroc";
			break;
		case '4':
			sFileName = "NuVenomJok";
			break;
		case '5':
			sFileName = "Pig";
			break;
		case '6':
			sFileName = "Piramid";
			break;
		case '7':
			sFileName = "Scene";
			break;
		default:
			return -1;
			break;
		}

		fFile.open(sFileName + ".X", ios::in, ios::binary);

		if (fFile.is_open())
		{
			system("cls");
			cout << "Se abrio correctamente el archivo " << sFileName << ".\n";
			system("pause");
			while (!bMeshFound)
			{
				getline(fFile, sIn);
				iFound = sIn.find(" Mesh ");
				if (iFound == 0)
				{
					fFile >> iVertexCount;
					fFile >> cChar;
					bMeshFound = true;
				}
			}
			if (bMeshFound)
			{
				for (int i = 0; i < iVertexCount; i++)
				{
					Coordinates* pivot = new Coordinates;
					fFile >> pivot->x;
					fFile >> cChar;
					fFile >> pivot->y;
					fFile >> cChar;
					fFile >> pivot->z;
					fFile >> cChar;
					fFile >> cChar;
					MeshList.push_back(pivot);
				}
				system("cls");
				cout << "Presione la barra espaciadora para mostrar una vertice a la vez, o la tecla Enter para imprimir todo.\n";
				cInput = _getch();
				for (int i = 0; i < iVertexCount; i++)
				{
					/*cout << MeshList[i];*/
					while (cInput != 32 && cInput != 13)
					{
						cout << "Presione la barra espaciadora para mostrar una vertice a la vez, o la tecla Enter para imprimir todo.\n";
						cInput = _getch();
					}
					cout << "(" << MeshList[i]->x << ", " << MeshList[i]->y << ", " << MeshList[i]->z << ")\n";
					if (cInput == 32)
					{
						cInput = _getch();
					}
				}
				system("pause");
				bMeshFound = false;
				fFile.close();
				MeshList.clear();
			}
		}
		else
		{
			cout << "No se encontro el archivo " << sIn << ".\n";
			system("pause");
		}

	} while (cInput != '8');
	return 0;
}

