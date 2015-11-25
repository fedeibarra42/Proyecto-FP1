void ingresarRegistro (int id, char concepto[], float monto){
	FILE *archivo, *archUsr;
	registro r;
	usuario u[100];
	char nombreArchivo[15], formato[5] = ".txt";

	archUsr = fopen("usuarios.txt","r");

	while (!feof(archUsr)){
		fread(&u,sizeof(usuario),1,archUsr);
	}
	fclose(archUsr);

	strcpy (nombreArchivo,strcat(u[id].nombre,formato));

	archivo= fopen(nombreArchivo,"a");

	strcpy(r.concepto,concepto);
	r.monto = monto;

	fwrite(&r,sizeof(registro),1,archivo);
	fclose(archivo);

	
}

		


void leerRegistro (int id){
	FILE *archivo, *archUsr;
	registro l;
	usuario u[100];
	char nombreArchivo[15], formato[5] = ".txt";

	archUsr = fopen("usuarios.txt","r");

	while (!feof(archUsr)){
		fread(&u,sizeof(usuario),1,archUsr);
	}
	
	fclose(archUsr);

	strcpy (nombreArchivo,strcat(u[id].nombre,formato));

	archivo = fopen(nombreArchivo, "r");

	while(!feof(archivo)){
		fread(&l,sizeof(registro),1,archivo);
		printf("Concepto: %s\n",l.concepto);
		printf("Monto: $%.3f\n", l.monto);
	}

	fclose(archivo);
}
