float baseball_menu(float dinero, int id){
	char equipos[40][30] = {{"Giants"},{"Dodgers"},{"Padres"},{"Rockies"},{"Dimondbacks"},{"Blue Jays"},{"Orioles"},{"Rays"},{"Red Sox"},{"Yankees"},
				{"Royals"},{"Twins"},{"Indians"},{"White Sox"},{"Tigers"},{"Rangers"},{"Astros"},{"Angels"},{"Marineers"},{"Athletics"},{"Mets"},{"Nationals"},
				{"Marlins"},{"Braves"},{"Phillies"},{"Cardinals"},{"Pirates"},{"Cubs"},{"Brewers"},{"Reds"}};
	int c;
	
	//Es el numero de juegos que gano cada equipo en la pasada temporada.
	float stats[40] = {84,92,74,68,79,93,87,81,80,78,95,83,81,76,74,88,86,85,76,68,90,83,71,67,63,100,98,97,68,64};

	/*Divide cada numero del arreglo stats entre 162 que fue la cantidad de juegos que hubo en la temporada para generar 
	  el promedio de juegos ganados de cada equipo*/
	for (c=0;c<30;c++)
		stats[c]/=162;
	/*la sintaxis es <<dinero = generacionPartidos("cantidad de equipos",equipos,dinero,"estadisticas",[1(si hay empates] o 0 (si no hay empates),"marcador maximo","marcador minimo"*/
	dinero = generacionPartidos(30,equipos,dinero,stats,0,18,0,id); 

	return dinero;
}

float espanola_menu(float dinero, int id){
	
	
	char equipos[40][30] = {{"Barcelona"},{"Real Madrid"},{"Sevilla"},{"Real Sociedad"},{"Espanyol"},{"Malaga"},{"Valencia"},{"Las Palmas UD"},{"Getafe"},{"Deportivo"},
	{"Celta Vigo"},{"Sporting Gijon"},{"Levante"},{"Villarreal"},{"SD Eibar"},{"Granada"},{"Athletic"},{"Betis"},{"Atletico Madrid"},{"Rayo Vallecano"}};
	int c;
	

	float stats[40] = {30,30,23,11,13,14,22,10,9,7,13,10,9,16,10,7,15,10,23,15};
	for (c=0;c<20;c++)
		stats[c]/=38;
	dinero = generacionPartidos(20,equipos,dinero,stats,1,5,0,id); 

	return dinero;
}

float premier_menu(float dinero, int id){
	
	
	char equipos[40][30] = {{"Chelsea"},{"Manchester City"},{"Arsenal"},{"Manchester United"},{"Tottenham Hotspur"},{"Liverpool"},{"Southampton"},{"Swansea City"},{"Stoke City"},{"Crystal Palace"},
	{"Everton"},{"West Ham United"},{"West Bromwich Albion"},{"Leicester City"},{"Newcastle United"},{"Sunderland"},{"Aston Villa"},{"Watford"},{"Norwich City"},{"AFC Bournemouth"}};
	int c;
	

	float stats[40] = {26,24,22,20,19,18,18,16,15,13,12,12,11,11,10,7,10,12,12,12};
	for (c=0;c<20;c++)
		stats[c]/=38;
	dinero = generacionPartidos(20,equipos,dinero,stats,1,5,0,id); 

	return dinero;
}

float mx_menu(float dinero, int id){
	
	
	char equipos[40][30] = {{"America"},{"Chivas"},{"Cruz Azul"},{"Pumas"},{"Toluca"},{"Pachuca"},{"Leon"},{"Jaguares"},{"Xolos"},{"Dorados"},
	{"Veracruz"},{"Puebla"},{"Tigres"},{"Monterrey"},{"Monarcas"},{"Atlas"},{"Santos"},{"Queretaro"}};
	int c;
	

	float stats[40] = {8,5,16,11,9,6,9,7,4,3,7,8,10,6,5,6,4,7};
	for (c=0;c<18;c++)
		stats[c]/=17;
	dinero = generacionPartidos(18,equipos,dinero,stats,1,5,0,id); 

	return dinero;
}

float bundesliga_menu(float dinero, int id){
	
	
	char equipos[40][30] = {{"Bayern Munich"},{"Wolfsburg"},{"Borussia Monchengladbach"},{"Bayer Leverkusen"},{"FC Augsburg"},{"Schalke 04"},{"Borussia Dortmund"},{"TSG Hoffenheim"},{"Eintracht Frankfurt"},{"Werder Bremen"},
	{"Mainz"},{"FC Cologne"},{"Hannover 96"},{"VfB Stuttgart"},{"Hertha Berlin"},{"Hamburg SV"},{"FC Ingolstadt 04"},{"SV Darmstadt 98"}};
	int c;
	

	float stats[40] = {25,20,19,17,15,13,13,12,11,11,9,9,9,9,9,9,12,12};
	for (c=0;c<18;c++)
		stats[c]/=34;
	dinero = generacionPartidos(18,equipos,dinero,stats,1,5,0,id); 

	return dinero;
}

float americano_menu(float dinero, int id){
	char equipos[40][30]={{"Patriots"},{"Bills"},{"Jets"},{"Dolphins"},{"Broncos"},{"Chiefs"},{"Raiders"},
			{"Chargers"},{"Ravens"},{"Bengals"},{"Browns"},{"Steelers"},{"Texans"},{"Colts"},{"Jaguars"},
			{"Titans"},{"Cowboys"},{"Gigants"},{"Eagles"},{"Redskins"},{"Cardinals"},{"49ers"},{"Seahawks"},{"Rams"},
			{"Bears"},{"Lions"},{"Packers"},{"Vikings"},{"Falcons"},{"Panthers"},{"Saints"},{"Bucaneers"}};
	int c, numeroEquipos;
	float stats[40]={12,9,4,8,12,9,3,9,10,10,7,11,9,11,3,2,12,6,10,4,11,8,12,6,5,11,12,7,6,7,7,2};
	for (c=0;c<32;c++)
		stats[c]/=16;

	numeroEquipos=32;
	dinero = generacionPartidos(numeroEquipos,equipos,dinero,stats,0,40,2,id);
	return dinero;
}

float basketball_menu(dinero, id){
	char equipos[40][30]={{"Cavaliers"},{"Hawks"},{"Bulls"},{"Raptors"},{"Wizards"},{"Bucks"},{"Celtics"},
			{"Nets"},{"Pacers"},{"Heat"},{"Hornets"},{"Pistons"},{"Magic"},{"76ers"},{"Knicks"},
			{"Warriors"},{"Rockets"},{"Clippers"},{"Blazers"},{"Grizzlies"},{"Spurs"},{"Mavericks"},{"Pelicans"},{"Thunder"},
			{"Suns"},{"Jazz"},{"Nuggets"},{"Kings"},{"Lakers"},{"Timberwolves"}};
	int c;
	float stats[40]={53,60,50,49,46,41,40,38,38,37,33,32,25,18,17,67,56,56,51,55,55,50,45,45,39,38,30,29,21,16};
	for (c=0;c<30;c++)
		stats[c]/=82;

	dinero = generacionPartidos(30,equipos,dinero,stats,0,143,65,id);
	return dinero;
}

float hockey_menu(dinero, id){
	char equipos[40][30]={{"Ducks"},{"Blackhawks"},{"Bruins"},{"Hurricanes"},{"Coyotes"},{"Avalanche"},{"Sabres"},
			{"Blue Jackets"},{"Flames"},{"Stars"},{"Red Wings"},{"Devils"},{"Oilers"},{"Wild"},{"Panthers"},{"Islanders"},
			{"Kings"},{"Predators"},{"Canadiens"},{"Rangers"},{"Sharks"},{"Blues"},{"Senators"},{"Flyers"},{"Canucks"},
			{"Jets"},{"Lightning"},{"Penguins"},{"Maple Leafs"},{"Capitals"}};
	int c;
	float stats[40]={51,48,41,30,24,39,23,42,45,41,43,32,24,46,38,47,40,47,50,53,40,51,43,33,48,43,50,43,30,45};
	for(c=0;c<30;c++)
		stats[c]/=82;

	dinero=generacionPartidos(30,equipos,dinero,stats,0,5,0,id);
	return dinero;
}

float F1_menu(dinero, id){
	char equipos[40][30]={{"Hamilton"},{"Rosberg"},{"Vettel"},{"Räikkönen"},{"Massa"},{"Bottas"},{"Ricciardo"},{"Kvyat"},
	{"Pérez"},{"Hulkenberg"},{"Grosjean"},{"Maldonado"},{"Verstappen"},{"Sainz"},{"Ericsson"},{"Nasr"},
	{"Alonso"},{"Button"},{"Stevens"},{"Rossi"},{"Merhi"}};
	
	float stats[40]={363,297,266,135,177,136,84,94,68,52,49,27,49,18,9,27,11,16,1,1,1};

	dinero=generacionPartidos(21,equipos,dinero,stats,2,0,0,id);
	return dinero;
}

float soccer_menu(float dinero, int id){
	
		int selector=1;
		while (selector){
		
		printf("\n\n||	Ligas de Futbol	||\n");
		printf("1-Liga Espanola\n2-Premier League\n3-Liga MX\n4-Bundesliga\n0-Regresar\n");
		scanf("%d",&selector);

		switch(selector){
			
			case 1:
				dinero = espanola_menu(dinero, id);
				break;
			case 2:
				dinero = premier_menu(dinero, id);
				break;
			case 3:
				dinero = mx_menu(dinero, id);
				break;
			case 4:
				dinero = bundesliga_menu(dinero, id);
				break;
		}
	}

	return dinero;
}

float menu_deportes(float dinero, int id){
	int selector=1;

	while (selector){
		
		printf("\n\n||	 MENU DE DEPORTES	||\n");
		printf("1-Futbol (soccer)\n2-Football (americano)\n3-Basketball\n4-Baseball\n5-Hockey\n6-Formula 1\n0-Regresar\n");
		scanf("%d",&selector);

		switch(selector){
			
			case 1:
				dinero = soccer_menu(dinero, id);
				break;
			case 2:
				dinero = americano_menu(dinero, id);
				break;
			case 3:
				dinero = basketball_menu(dinero, id);
				break;
			case 4:
				dinero = baseball_menu(dinero, id);
				break;
			case 5:
				dinero = hockey_menu(dinero, id);
				break;
			case 6:
				dinero = F1_menu(dinero, id);
				break;
		}
	}

	return dinero;
}

