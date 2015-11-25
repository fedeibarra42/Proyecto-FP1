float menu_cuenta(float dinero, int id){
	int selector=1;
	float cantidadDepsito, cantidadRetiro;

	while (selector){
		printf("\n\n||	 MENU DE USUARIO 	||\n");
		printf("1-Depositar\n2-Retirar\n3-Apostar\n4-Ver historial de transacciones\n5-Ver estado de cuenta\n0-Cerrar sesion\n");
		scanf("%d",&selector);

		switch(selector){
			case 1:

				printf("\nCantidad: ");
				scanf("%f",&cantidadDepsito);

				if (cantidadDepsito<=0){
					printf("ERROR: cantidad incorrecta\n");
					getchar();
					getchar();
				}

				else{
					dinero+=cantidadDepsito;
					ingresarRegistro(id, "Deposito" , cantidadDepsito);
				}

				break;

			case 2:
				
				printf("\nCantidad: ");
				scanf("%f",&cantidadRetiro);

				if (cantidadRetiro < 0){
					printf("ERROR: cantidad incorrecta\n");
					getchar();
					getchar();
				}

				else if (cantidadRetiro > dinero){
					printf("ERROR: no cuentas con el dinero suficiente.\n");
					getchar();
					getchar();
				}

				else
					dinero -= cantidadRetiro;
					cantidadRetiro *= -1;
					ingresarRegistro(id, "Retiro" , cantidadRetiro);
				
				break;

			case 3:

				dinero = menu_deportes(dinero,id);
				break;

			case 4:
				leerRegistro(id);
				break;
			case 5:
				printf("\nCuentas con $%.2f\n",dinero);
				getchar();
				getchar();
				break;
		}
	}
	return dinero;
}
