void ingresarRegistro (int id, char concepto[], float monto){
	FILE *archivo, *archUsr;
	registro r;
	usuario u[100];
	char nombreArchivo[15], formato[5] = ".txt";
	int c = 0;

	archUsr = fopen("usuarios.txt","r");

	while (!feof(archUsr)){
		fread(&u[c],sizeof(usuario),1,archUsr);
		c++;
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
	int c=0;

	archUsr = fopen("usuarios.txt","r");

	while (!feof(archUsr)){
		fread(&u[c],sizeof(usuario),1,archUsr);
		c++;
	}

	fclose(archUsr);

	strcpy (nombreArchivo,strcat(u[id].nombre,formato));

	archivo = fopen(nombreArchivo, "r");

	fread(&l,sizeof(registro),1,archivo);

	while(!feof(archivo)){
		printf("\n________________________________\n");
		printf("\nConcepto: %s\n",l.concepto);
		printf("Monto: $%.3f\n", l.monto);
		fread(&l,sizeof(registro),1,archivo);
	}

	fclose(archivo);
}
