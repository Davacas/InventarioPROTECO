#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto {
	char nombre[15];
	float precio;
	int cantidad;	
} producto_t;

int logueo ();
producto_t* creaProductos (producto_t *);
void llenaArchivo (FILE *, producto_t *);
void imprimeInventario (FILE *, producto_t *);

int main (int argc, char *argv[])
{
	FILE *archivo = NULL;
	producto_t *producto;
	int salir = 0, opc = 0;

	if (logueo() == 1)
	{
		producto = creaProductos(producto);
		llenaArchivo(archivo, producto);
		do
		{
			system("clear");
			printf("\n\n\t\tINVENTARIO ACTUAL DE 'EL PREBE INFELIZ':\n\n");
			imprimeInventario(archivo, producto);
			printf("\n\n\t\t¿Qué deseas hacer?\n");
			printf("\t\t\t1) Actualizar cantidad\n\t\t\t2) Actualizar precio\n\t\t\t3) Salir");
			scanf("%d", &opc);

			switch (opc)
			{
				case 1 :


					break;
				case 2 :


					break;
				case 3 :
					salir = 1;
					break;
				default :
					printf(" ");	
			}
		} while (salir == 0);
	}

	fclose(archivo);
	return 0;
}


int logueo ()
{
	int acceso = 1, intento = 0;
	char usuario[16], pass[16];

	while (1)
	{
		system("clear");
		printf("\n\n\t\t\tABARROTES ~EL PREBE INFELIZ~\n\n\n\t\tPor favor, inicia sesión para continuar:");
		printf("\n\n\t\t\tUsuario: ");
		scanf(" %[^\n]", usuario);
		printf("\n\t\t\tContraseña: ");
		scanf(" %[^\n]", pass);

		if (strcmp(usuario, "Davacas") == 0 && strcmp(pass, "davacas") == 0)
			return acceso;
		else if (strcmp(usuario, "Davacas") == 0 && strcmp(pass, "proteco123") == 0)
			return acceso;
		else 
		{
			intento ++;

			if (intento == 3) 
			{
				printf("\n\n\t\tERROR: Acceso denegado. Contactando al administrador...\n\n");
				exit (0);
			}
			else
			{
				printf("\n\n\t\tACCESO DENEGADO. Intente de nuevo.");
				getchar();
				getchar();
			}
		}
	}
	return 0;
}


producto_t *creaProductos (producto_t *producto)
{
	int i;

	producto = (producto_t *) calloc(20, sizeof(producto_t));
	strcpy(producto[0].nombre, "leche");
	producto[0].precio = 15.50;
	strcpy(producto[1].nombre, "manzana");
	producto[1].precio = 40;
	strcpy(producto[2].nombre, "aguacate");
	producto[2].precio = 9999.00;
	strcpy(producto[3].nombre, "maruchan");
	producto[3].precio = 7.50;
	strcpy(producto[4].nombre, "condones");
	producto[4].precio = 0.50;
	strcpy(producto[5].nombre, "pan");
	producto[5].precio = 30.00;
	strcpy(producto[6].nombre, "huevos");
	producto[6].precio = 15.50;
	strcpy(producto[7].nombre, "jamon");
	producto[7].precio = 75.00;
	strcpy(producto[8].nombre, "queso");
	producto[8].precio = 80.00;
	strcpy(producto[9].nombre, "cereal");
	producto[9].precio = 40.00;
	strcpy(producto[10].nombre, "pasta");
	producto[10].precio = 5.50;
	strcpy(producto[11].nombre, "arroz");
	producto[11].precio = 10.00;
	strcpy(producto[12].nombre, "drogas");
	producto[12].precio = 1.50;
	strcpy(producto[13].nombre, "sabritas");
	producto[13].precio = 8.50;
	strcpy(producto[14].nombre, "refresco");
	producto[14].precio = 10.00;
	strcpy(producto[15].nombre, "cafe");
	producto[15].precio = 10.00;
	strcpy(producto[16].nombre, "platano");
	producto[16].precio = 12.00;
	strcpy(producto[17].nombre, "nutella");
	producto[17].precio = 45.00;
	strcpy(producto[18].nombre, "azucar");
	producto[18].precio = 10.00;
	strcpy(producto[19].nombre, "sal");
	producto[19].precio = 10.00;
	for (i = 0; i < 20; i++)
		producto[i].cantidad = 50;
	return producto;
}

void llenaArchivo (FILE *archivo, producto_t *producto)
{
	int i;
	if ((archivo = fopen("archivo.txt", "r")) == NULL)
		if ((archivo = fopen("archivo.txt", "a+")) == NULL)
		{
			printf("\n\n\t\tERROR: No se pudo manipular el archivo.\nEl programa se cerrará\n");
			exit(0);
		}
		else
		{
			fprintf(archivo, "\tPRODUCTO    PRECIO\tCANTIDAD\n\n");
			for (i = 0; i < 20; i++)
				fprintf(archivo, "%16s%10.2f\t%d\n", producto[i].nombre, producto[i].precio, producto[i].cantidad);
		}

	fclose(archivo);
	return;
}


void imprimeInventario (FILE *archivo, producto_t *producto)
{
	if ((archivo = fopen("archivo.txt", "a+")) == NULL)
	{
		printf("\n\n\n\tERROR: No se pudo manipular el archivo.\nEl programa se cerrará\n");
		exit(0);
	}
	else 
	{
		char c = fgetc(archivo);
		while (c != -1)
		{
			printf("%c", c);
			c = fgetc(archivo);
		}
	}
	fclose(archivo);
	return;
}