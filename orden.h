//Algoritmo de apuestas.

float victoria(int ordenEquipos[2][40],float dinero, float stats[40],int oponente,int seleccion, float apuesta){
	float porcentaje,ganancia;

	printf("\n¡¡¡HAZ GANADO!!!\n");

	//Calcula el porcentaje de ganancias segun las estadisticas de los equipos.
	porcentaje = stats[ordenEquipos[0][seleccion-1]] /  stats[ordenEquipos[0][oponente]];
	ganancia = apuesta + (apuesta / porcentaje);
	dinero += ganancia;
	printf("Tus ganancias son de: $%.2f\n[ENTER para continuar]\n", ganancia);
	getchar();

	return dinero;
}

float partidosConEmpates(int ordenEquipos[2][40], int numeroEquipos, char equipos[40][15], float dinero, float stats[],int maximo, int minimo){
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
		printf("Cantidad a apostar: ");
		scanf("%f",&apuesta);

		if (equipoSeleccionado == 'e' || equipoSeleccionado == 'l' || equipoSeleccionado == 'v')
			a = 0;
		else{
			printf("ERROR: Opcion no valida	\n [ENTER para continuar]");
			getchar();
			getchar();
		}
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
		select = ordenEquipos[0][seleccion-1];
		oponente = ordenEquipos[0][seleccion];
	}

	else if (equipoSeleccionado == 'v'){
		select = ordenEquipos[0][seleccion];
		oponente = ordenEquipos[0][seleccion-1];
	}

	else {
		select = ordenEquipos[0][seleccion];
		oponente = ordenEquipos[0][seleccion];
	}

	//Apuesta
	if (equipoSeleccionado == 'l' && ordenEquipos[0][seleccion-1] > ordenEquipos[0][seleccion])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta);
	else if (equipoSeleccionado == 'v' && ordenEquipos[0][seleccion-1] < ordenEquipos[0][seleccion])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta);
	else if (equipoSeleccionado == 'e' && ordenEquipos[0][seleccion-1] == ordenEquipos[0][seleccion])
		dinero = victoria(ordenEquipos, dinero,  stats, oponente, select, apuesta);
	else{
		dinero -= apuesta;
		printf("\nHaz perdido: $%.2f\n", apuesta);
	}


	return dinero;
}

float partidosSinEmpate (int ordenEquipos[2][40], int numeroEquipos, char equipos[40][15], float dinero, float stats[],int maximo, int minimo){
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
	printf("Cantidad a apostar: ");
	scanf("%f",&apuesta);

	if (apuesta>dinero){
		printf("ERROR: No cuetnas con el dinero suficiente para hacer esta apuesta.\n[ENTER para continuar]");
		getchar();
		getchar();
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
		dinero = victoria(ordenEquipos,dinero,stats,oponente,seleccion,apuesta);
	else{
		dinero -= apuesta;
		printf("\nHaz perdido: $%.2f\n", apuesta);
	}
	
	return dinero;
}

float generacionPartidos (int numeroEquipos, char equipos[40][15], float dinero, float stats[40], int existeEmpate, int maximo, int minimo){
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

	if(existeEmpate){
		dinero = partidosConEmpates(ordenEquipos, numeroEquipos, equipos, dinero, stats, maximo, minimo);
	}
	else{
		dinero = partidosSinEmpate(ordenEquipos, numeroEquipos, equipos, dinero, stats, maximo, minimo);
	}


	return dinero;
}

