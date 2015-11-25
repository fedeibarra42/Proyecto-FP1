//Algoritmo de apuestas.

float victoria(int ordenEquipos[2][40],float dinero, float stats[40],int oponente,int seleccion, float apuesta, int id){
	float porcentaje,ganancia;

	printf("\n¡¡¡HAZ GANADO!!!\n");

	//Calcula el porcentaje de ganancias segun las estadisticas de los equipos.
	porcentaje = stats[ordenEquipos[0][seleccion-1]] /  stats[ordenEquipos[0][oponente]];
	ganancia = apuesta + (apuesta / porcentaje);
	dinero += ganancia;
	printf("Tus ganancias son de: $%.2f\n[ENTER para continuar]\n", ganancia);

	//Funcion de guardar el registro
	ingresarRegistro(id ,"Apuesta ganada", ganancia);


	return dinero;
}

float formula1(int ordenEquipos[2][40], int numeroEquipos, char equipos[40][15], float dinero, float stats[], int id){
	int c,a=1, seleccion, hora, decimas[40],o;
	float apuesta;

	//Imprime toda la parrilla

	printf("\n\n||  CORREDORES  ||\n");
	printf("\n________________________________\n");
	for (c=0;c<numeroEquipos;c++)
		printf("[%d] %s  (%.0f pts) \n",c+1,equipos[c],stats[c]);

	//Seleccion del corredor
	while(a){
		printf("Selecciona a un corredor: ");
		scanf("%d",&seleccion);

		if (seleccion<1 || seleccion>numeroEquipos){
			printf("ERROR: seleccion no valida\n[ENTER para continuar]\n");
			getchar();
			getchar();
		}

		else 
			a--;

	}

	//Cantidad a apostar
	c=1;
	while (c){
	printf("Cantidad a apostar[0 para All In]: ");
	scanf("%f",&apuesta);

		if (apuesta>dinero){
			printf("ERROR: No cuetnas con el dinero suficiente para hacer esta apuesta.\n[ENTER para continuar]");
			getchar();
			getchar();
		}
		else if (apuesta == 0){
			apuesta = dinero;
			c--;
		}
		else 
			c--;
	}

	//Genera el tiempo de carrera
	hora = time(NULL);
	srand(hora);
	o = rand() % 15;
	o += 10;

	for (c=0;c<numeroEquipos;c++){
		o += 1;
		ordenEquipos[1][c] = o;
		decimas[c] = rand() % 950;
		decimas[c] += 40;
	}


	//Imprime los resultados
	printf("\n\n||  FIN DE LA CARRERA  ||\n");
	printf("\n________________________________\n");
	for (c=0;c<numeroEquipos;c++)
		printf("[%d] - %s__________ 1:%d.%d\n",c+1,equipos[ordenEquipos[0][c]],ordenEquipos[1][c],decimas[c]);

	printf("[presione ENTER]\n");
	getchar();
	getchar();

	seleccion--;

	if (ordenEquipos[0][0]==seleccion-1)
		dinero = victoria(ordenEquipos, dinero,  stats, seleccion, seleccion, apuesta, id);
	else{
		dinero -= apuesta;
		printf("\nHaz perdido: $%.2f\n", apuesta);
		apuesta *= -1;
		ingresarRegistro(id,"Apuesta perdida" , apuesta);
	}

	return dinero;

}

float partidosConEmpates(int ordenEquipos[2][40], int numeroEquipos, char equipos[40][15], float dinero, float stats[],int maximo, int minimo, int id){
	int c,seleccion,o,hora, oponente, select, a=1,ab=1;
	char equipoSeleccionado;
	float apuesta;

	hora = time(NULL);
	srand(hora);

	//Imprimir los partidos
	printf("\n|| Seleccione un partido ||\n");
	for (c=0;c<numeroEquipos;c+=2){
		printf("[%d] %s (%.3f)",c+1, equipos[ordenEquipos[0][c]],stats[ordenEquipos[0][c]]);
		printf("  vs  ");
		printf("%s (%.3f)\n", equipos[ordenEquipos[0][c+1]],stats[ordenEquipos[0][c+1]]);
	}

	//Escoge el partido.

	while (ab){
		printf("Selecciona el partido al cual deseas apostar: ");
		scanf("%d",&seleccion);

		if (seleccion <= 0 || seleccion % 2 == 0|| seleccion >= numeroEquipos){
			printf("ERROR: Opcion no valida	\n [ENTER para continuar]");
			getchar();
			getchar();
		}
		else
			ab = 0;
	}

	//Seleccion de equipo

	while(a){
		printf("\n||  TU PARTIDO  ||\n");
		printf("[l] %s  vs  [v] %s\n",equipos[ordenEquipos[0][seleccion-1]],equipos[ordenEquipos[0][seleccion]]);
		printf("Selecciona entre local[l], visitante[v] o empate[e]\n");
		scanf(" %c",&equipoSeleccionado);

		if (equipoSeleccionado == 'e' || equipoSeleccionado == 'l' || equipoSeleccionado == 'v')
			a = 0;
		else{
			printf("ERROR: Opcion no valida	\n [ENTER para continuar]");
			getchar();
			getchar();
		}
	}

	//Cantidad a apostar

	c=1;
	while (c){
	printf("Cantidad a apostar[0 para All In]: ");
	scanf("%f",&apuesta);

		if (apuesta>dinero){
			printf("ERROR: No cuetnas con el dinero suficiente para hacer esta apuesta.\n[ENTER para continuar]");
			getchar();
			getchar();
		}
		else if (apuesta == 0){
			apuesta = dinero;
			c--;
		}
		else 
			c--;
	}

	//Genera los resultados
	for (c=0;c<numeroEquipos;c++){
		o = rand() % maximo;
		o += minimo;
		ordenEquipos[1][c] = o;
	}

	//Imprime los resultados
	for (c=0;c<numeroEquipos;c+=2){
		printf("%s (%d)", equipos[ordenEquipos[0][c]], ordenEquipos[1][c]);
		printf("  vs  ");
		printf("(%d)  %s\n", ordenEquipos[1][c+1], equipos[ordenEquipos[0][c+1]]);
	}

	getchar();
	getchar();

	//Identifica contendientes

	if (equipoSeleccionado == 'l'){
		select = seleccion-1;
		oponente = seleccion;
	}

	else if (equipoSeleccionado == 'v'){
		select = seleccion-1;
		oponente = seleccion;
	}

	else {
		select = seleccion-1;
		oponente = seleccion;
	}

	//Apuesta

	if (equipoSeleccionado == 'l' && ordenEquipos[1][select] > ordenEquipos[1][oponente])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta, id);

	else if (equipoSeleccionado == 'v' && ordenEquipos[1][select] < ordenEquipos[1][oponente])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta, id);

	else if (equipoSeleccionado == 'e' && ordenEquipos[1][select] == ordenEquipos[1][oponente])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta, id);

	else{
		dinero -= apuesta;
		printf("\nHaz perdido: $%.2f\n", apuesta);
		apuesta *= -1;
		ingresarRegistro(id,"Apuesta perdida" , apuesta);
	}


	return dinero;
}

float partidosSinEmpate (int ordenEquipos[2][40], int numeroEquipos, char equipos[40][15], float dinero, float stats[],int maximo, int minimo, int id){
	int c,seleccion,o,hora,oponente,co,a=1;
	char equipoSeleccionado;
	float apuesta;

	hora = time(NULL);
	srand(hora);

	//Genera los partidos
	printf("\n\n|| 	 PARTIDOS 	||\n");
	for (c=0;c<numeroEquipos;c+=2){
		printf("[%d] %s (%.3f)   ",c+1,equipos[ordenEquipos[0][c]],stats[ordenEquipos[0][c]]);
		printf("vs");
		printf("   [%d] %s  (%.3f)\n",c+2,equipos[ordenEquipos[0][c+1]],stats[ordenEquipos[0][c+1]]);
	}

	while (a){
		printf("Selecciona el equipo al cual quieres apostar: ");
		scanf("%d",&seleccion);

		if (seleccion>numeroEquipos || seleccion<=0){
			printf("ERROR: Seleccion no valida\n[ENTER para continuar]");
			getchar();
			getchar();
		}
		else
			a=0;
	}

	//Cantidad a apostar
	c=1;
	while (c){
	printf("Cantidad a apostar[0 para All In]: ");
	scanf("%f",&apuesta);

		if (apuesta>dinero){
			printf("ERROR: No cuetnas con el dinero suficiente para hacer esta apuesta.\n[ENTER para continuar]");
			getchar();
			getchar();
		}
		else if (apuesta == 0){
			apuesta = dinero;
			c--;
		}
		else 
			c--;
	}

	//Genera los resultados
	for (c=0;c<numeroEquipos;c++){
		o = rand() % maximo;
		o += minimo;
		ordenEquipos[1][c] = o;
	}

	printf("\n\n|| 	 RESULTADOS 	||\n");
	for (c=0;c<numeroEquipos;c+=2){

		//Evita los empates
		if (ordenEquipos[1][c]==ordenEquipos[1][c+1])
			ordenEquipos[1][c+1]++;

		printf("%s( %d)   vs   (%d) %s\n",equipos[ordenEquipos[0][c]],ordenEquipos[1][c],ordenEquipos[1][c+1],equipos[ordenEquipos[0][c+1]]);
	}
	
	printf("[ENTER para continuar]\n");
	getchar();
	getchar();

	//Identificador de equipos.

	if (seleccion & 1)
		oponente = seleccion;
	else
		oponente = seleccion - 2;

	printf("\n\n|| 	 TU PARTIDO  ||\n");
	printf("%s  (%d)\n  vs  \n%s  (%d)",equipos[ordenEquipos[0][seleccion-1]],ordenEquipos[1][seleccion-1],equipos[ordenEquipos[0][oponente]],ordenEquipos[1][oponente]);

	//Hace los calculos monetarios.
	if (ordenEquipos[1][seleccion-1] > ordenEquipos[1][oponente])
		dinero = victoria(ordenEquipos,dinero,stats,oponente,seleccion,apuesta,id);
	else{
		dinero -= apuesta;
		printf("\nHaz perdido: $%.2f\n", apuesta);
		apuesta *= -1;
		ingresarRegistro(id,"Apuesta perdida" , apuesta);
	}
	
	return dinero;
}

float generacionPartidos (int numeroEquipos, char equipos[40][15], float dinero, float stats[40], int existeEmpate, int maximo, int minimo,int id){
	int ordenEquipos[2][40],c=1,o,i,hora,co;

	hora = time(NULL);
	srand(hora);
	o = rand() % numeroEquipos;

	ordenEquipos[0][0] = o;


	//Genera el orden de los partidos
	while (c<numeroEquipos){
		co=0;
		i=0;

		while (co<c){

			if (ordenEquipos[0][co] == o)
				i++;

			co++;
		}

		if (i != 0){
			o = rand()%numeroEquipos;
		}
		else {
			ordenEquipos[0][c]=o;
			c++;
		}
	}

	if(existeEmpate==1){
		dinero = partidosConEmpates(ordenEquipos, numeroEquipos, equipos, dinero, stats, maximo, minimo,id);
	}
	else if (existeEmpate == 2){
		dinero = formula1(ordenEquipos, numeroEquipos, equipos, dinero, stats, id);
	}
	else{
		dinero = partidosSinEmpate(ordenEquipos, numeroEquipos, equipos, dinero, stats, maximo, minimo,id);
	}


	return dinero;
}

