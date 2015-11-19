#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "orden.h"
#include "deportes.h"
#include "cuetna.h"
#include "ayuda.h"


void ingreso(char usuarioGuardado[10], char contraseñaGuardada[10]){
	char usuario[10],contraseña[10];
	int c=1;

	while (c<4){

		printf("\n\n||	INTENTO NUMERO: %d	||\n",c);
		printf("Usuario: "); 
		scanf("%s",usuario);
		printf("\nContraseña: ");
		scanf("%s",contraseña);
		printf("\n");

		
		if (strcmp (usuario,usuarioGuardado) && strcmp(contraseña,contraseñaGuardada)){
			printf("Usuario no valido\n");
		}
		else{
			printf("Usuario valido\n");
			menu_cuenta();
			c=0;
			break;
		}

		c++;
	}

	if (c>2){
		puts("ERROR: Se te han acabado el numero de intentos.[Enter para regresar el MENU PRINCIPAL]\n");
		getchar();
		getchar();
	}
}
 
 int main (){
 	int selector=1;
 	char usr[10]= "q" , csñ[10] = "q";

 	while (selector){
 		printf("\n\n||	MENU PRINCIPAL	||\n1-Ingresar\n2-Crear usuario\n3-Ayuda\n0-Salir\n");
 		scanf("%d",&selector);

 		switch(selector){
 			case 1:
 				ingreso(usr,csñ);
 				break;
 			/*case 2:
 				crear_usuario();
 				break;*/
 			case 3:
 				ayuda();
 				break;
 		}
 	}
 	return 0;
 }
