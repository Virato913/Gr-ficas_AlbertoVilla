// Gráficas_AlbertoVilla.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
	char cChar;
	int iVertexCount, iOption;

	do
	{
		cout << "Archivo a abrir: \n1.- CerdoNuevo\n2.- Drone\n3.- NuCroc\n4.- NuVenomJok\n5.- Pig\n6.- Piramid\n7.- Scene\n8.- Salir\n\n";
		cin >> iOption;
		MeshList.clear();
		switch (iOption)
		{
		case 1:
			sFileName = "CerdoNuevo";
			break;
		case 2:
			sFileName = "Drone";
			break;
		case 3:
			sFileName = "NuCroc";
			break;
		case 4:
			sFileName = "NuVenomJok";
			break;
		case 5:
			sFileName = "Pig";
			break;
		case 6:
			sFileName = "Piramid";
			break;
		case 7:
			sFileName = "Scene";
			break;
		default:
			break;
		}

		fFile.open(sFileName + ".X", ios::in, ios::binary);

		if (fFile.is_open())
		{
			cout << "Se abrio correctamente el archivo.\n";
			system("pause");
			while (!fFile.eof())
			{
				getline(fFile, sIn);
				size_t iFound = sIn.find("Mesh");
				if (iFound == 1)
				{
					fFile >> iVertexCount;
					fFile >> cChar;
					for (int i = 0;i < iVertexCount;i++)
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
					for (int i = 0;i < iVertexCount;i++)
					{
						/*cout << MeshList[i];*/
						cout << "(" << MeshList[i]->x << ", " << MeshList[i]->y << ", " << MeshList[i]->z << ")\n";
					}
					break;
				}
			}
		}
		else
		{
			cout << "No se encontro el archivo.\n";
			system("pause");
		}

	} while (iOption != 8);

	fFile.close();
	return 0;
}

