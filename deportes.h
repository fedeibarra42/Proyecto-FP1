float baseball_menu(dinero){
	char equipos[40][15] = {{"Giants"},{"Dodgers"},{"Padres"},{"Roockies"},{"Dimodbacks"},{"Blue Jays"},{"Orioles"},{"Rays"},{"Red Sox"},{"Yankees"},
				{"Royals"},{"Twins"},{"Indians"},{"White Sox"},{"Tigers"},{"Rangers"},{"Astros"},{"Angels"},{"Marineers"},{"Athletics"},{"Mets"},{"Nationals"},
				{"Marlins"},{"Braves"},{"Phillies"},{"Cardinals"},{"Pirates"},{"Cubs"},{"Brewers"},{"Reds"}};
	int c;
	
	//Es el numero de juegos que gano cada equipo en la pasada temporada.
	float stats[40] = {84,92,74,68,79,93,87,81,80,78,95,83,81,76,74,88,86,85,76,68,90,83,71,67,63,100,98,97,68,64};

	/*Divide cada numero del arreglo stats entre 162 que fue la cantidad de juegos que hubo en la temporada para generar 
	  el promedio de juegos ganados de cada equipo*/
	for (c=0;c<30;c++)
		stats[c]/=162;
	/*la sintaxis es <<dinero = generacionPartidos("cantidad de equipos",equipos,dinero,"estadisticas")*/
	dinero = generacionPartidos(30,equipos,dinero,stats); 

	return dinero;
}

float menu_deportes(dinero){
	int selector=1;

	while (selector){
		
		printf("\n\n||	 MENU DE DEPORTES	||\n");
		printf("1-Futbol (soccer)\n2-Football (americano)\n3-Basketball\n4-Baseball\n0-Regresar\n");
		scanf("%d",&selector);

		switch(selector){
			case 4:
				dinero = baseball_menu(dinero);
				break;
		}
	}

	return dinero;
}
