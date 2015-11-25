#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "estructuras.h"
#include "registros.h"
#include "orden.h"
#include "deportes.h"
#include "cuetna.h"
#include "ayuda.h"


void ingreso(){
	char usuarioIntroducido[11],contrasenaIntroducida[11];
	int c=1,i=0,id=0,op=1;
	FILE *archivo;
	usuario usrs[100];

	archivo = fopen("usuarios.txt","r");

	while (!feof(archivo)){
		fread (&usrs[i],sizeof(usuario),1,archivo);
		i++;
	}

	fclose(archivo);

	while (c<4 && op){

		printf("\n\n||	INTENTO NUMERO: %d	||\n",c);
		printf("Usuario: "); 
		scanf("%s",usuarioIntroducido);
		printf("\ncontrasena: ");
		scanf("%s",contrasenaIntroducida);
		printf("\n");

		while (id <= i ){
			if (strcmp(usuarioIntroducido,usrs[id].nombre) == 0 || strcmp(contrasenaIntroducida,usrs[id].contrasena)==0){
				usrs[id].dinero = menu_cuenta(usrs[id].dinero,id);
				op--;
				break;
			}
			else
				id++;
		}

		c++;
	}

	if (c>2){
		puts("ERROR: Se te han acabado el numero de intentos.[Enter para regresar el MENU PRINCIPAL]\n");
		getchar();
		getchar();
	}

	archivo = fopen("usuarios.txt","w");

	for (c=0;c<=i;c++)
		fwrite(&usrs[c],sizeof(usuario),1,archivo);

	fclose(archivo);

}

void crear_usuario(){
	FILE *archivo;
	usuario usr;
	int id;

	archivo = fopen("usuarios.txt","r");

	while (!feof(archivo)){
		fread(&usr,sizeof(usuario),1,archivo);
		id = usr.id;
	}
	fclose(archivo);

	if (id>100 || id <0)
		id = 0;

	printf("Nombre de usuario [10 caracteres como maximo y sin espacios]: ");
	scanf(" %s",usr.nombre);/*FALTA VALIDACION*/

	printf("CONTRASEÑA [10 caracteres como maximo y sin espacios]: ");
	scanf(" %s",usr.contrasena);/*FALTA VALIDACION*/

	printf("Dinero inicial: ");
	scanf("%f",&usr.dinero);

	usr.id = id;

	archivo = fopen("usuarios.txt","a");
	fwrite(&usr,sizeof(usuario),1,archivo);
	fclose(archivo);


}
 
 int main (){
 	int selector=1;

 	while (selector){
 		printf("\n\n||	MENU PRINCIPAL	||\n1-Ingresar\n2-Crear usuario\n3-Ayuda\n0-Salir\n");
 		scanf("%d",&selector);

 		switch(selector){
 			case 1:
 				ingreso();
 				break;
 			case 2:
 				crear_usuario();
 				break;
 			case 3:
 				ayuda();
 				break;
 		}
 	}
 	return 0;
 }
