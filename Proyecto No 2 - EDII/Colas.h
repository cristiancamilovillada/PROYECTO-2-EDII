/*
** FUNCIONES APLICADAS A COLAS
*/

//DECLARACION DE FUNCIONES
void generar_datos_cola(int, nodo *&, nodo *&);
void cargar_datos_cola(int, nodo *&, nodo *&);
void insertar_datos_cola(int, nodo *&, nodo *&);
void visualizar_datos_cola(nodo *);
void eliminar_datos_cola(nodo *&);
void buscar_datos_cola(nodo *);
void editar_datos_colas(nodo *&);
void eliminar_cola(nodo *&);
void salvar_datos_cola(nodo *&);
void ordenar_datos_cola(nodo *);

//FUNCION PARA GENERAR DATOS COLAS
void generar_datos_cola(int opc, nodo *&inicio, nodo *&fin){
	clock_t iniciar, terminar;
	iniciar = clock();
	int cantidad, aleatorio, i;
	
	contador=1;
	while(opc != 0){
		switch(opc){
		case 1:{
			cantidad = 10;
			break;
			}
		case 2:{
			cantidad = 2000000;	
			break;
			}
		case 3:{
			cantidad = 5000000;	
			break;
			}
		case 4:{
			cantidad = 10000000;	
			break;	
			}
		case 5:{
			cantidad = 20000000;	
			break;	
			}
		}break;
	}
	srand(time(NULL));
	for(i = 1; i <= cantidad; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		//printf("%d %d \n", contador, aleatorio);
		insertar_datos_cola(aleatorio, inicio, fin);
		contador++;
		
	}
	terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f milisegundos\n", (double)(terminar - iniciar));
	printf("\n");
}

//FUNCION PARA CARGAR DATOS A LA COLA DESCDE UN ARCHIVO DE TEXTO
void cargar_datos_cola(int opc, nodo *&inicio, nodo *&fin){
	clock_t iniciar, terminar;
	iniciar = clock();
	FILE * archivo;
	int dato;
	contador=1;
	while(opc != 0){
		switch(opc){
		case 1:{
			archivo = fopen("un_millon.txt", "rb");
			break;
			}
		case 2:{
			archivo = fopen("dos_millones.txt", "rb");
			break;
			}
		case 3:{
			archivo = fopen("cinco_millones.txt", "rb");
			break;
			}
		case 4:{
			archivo = fopen("diez_millones.txt", "rb");
			break;	
			}
		case 5:{
			archivo = fopen("veinte_millones.txt", "rb");
			break;	
			}
		}break;
	}
	while(fread(&dato, sizeof(dato), 1, archivo)){
		insertar_datos_cola(dato, inicio, fin);
	}
	terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f milisegundos\n", (double)(terminar - iniciar));
	printf("\n");
}

//FUNCION PARA INSERTAR DATOS A LA COLA
void insertar_datos_cola(int aleatorio, nodo *&inicio, nodo *&fin){
	nodo * nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato = aleatorio;
	nuevo_nodo -> siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
}

//FUNCION PARA VISUALIZAR LOS DATOS DE LA COLA
void visualizar_datos_cola(nodo *inicio){
	nodo * aux = inicio;
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	printf("\n");
}

//FUNCION PARA ELIMINAR LOS DATOS DE LA COLA
void eliminar_datos_cola(nodo *&inicio, nodo *&fin){
	clock_t iniciar, terminar;
	iniciar = clock();
	int b;
	
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		fin = inicio;
		inicio = fin -> siguiente;
		free(fin);
		printf("Elemento eliminado\n");
	}
	terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f milisegundos\n", (double)(terminar - iniciar));
	printf("\n");
}

//FUNCION PARA BUSCAR DATOS EN LA COLA
void buscar_datos_cola(nodo *inicio){
	clock_t iniciar, terminar;
	iniciar = clock();
	int b, contador=1,encontrado=0;
	
	printf("Digite el elemento a buscar \n");
	scanf("%d", &b);
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		while(inicio != NULL){
			if(b == inicio->dato){
				printf("Dato encontrado en la posicion %d y su direccion de memoria es : %p \n" , contador, &inicio->dato);
				break;
				}
			inicio = inicio->siguiente;
			contador++;
			}
			if(encontrado!=1){
				printf("dato no encontrado \n");
			}
		}
		terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f milisegundos\n", (double)(terminar - iniciar));
}

//FUNCION PARA EDITAR DATOS EN COLAS
void editar_datos_colas(nodo *&inicio){
	clock_t iniciar, terminar;
	iniciar = clock();
	nodo * auxiliar = inicio;
	int b, nuevo_dato, opc=0, contador=1,encontrado=0;
	printf("Digite el elemento a buscar \n");
	scanf("%d", &b);
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		while(auxiliar != NULL){
			if(b == auxiliar -> dato){
				printf("Dato encontrado en la posicion %d y su direccion de memoria es : %p \n" , contador, &inicio->dato);
				printf("Desea editar el dato 1.Si - 2.No\n");
				scanf("%d", &opc);
				encontrado=1;
				if(opc == 1){
					printf("Ingrese el nuevo dato\n");
					scanf("%d", &nuevo_dato);
					auxiliar -> dato = nuevo_dato;
					printf("Dato editado correctamente\n");
					}
				break;
				}
			auxiliar = auxiliar -> siguiente;
			contador++;
			}
			if(encontrado!=1){
				printf("dato no encontrado \n");
			}
		}
		terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f segundos\n", (double)(terminar - iniciar));
}

//FUNCION PARA ELIMINAR LA COLA
void eliminar_cola(nodo *&inicio, nodo *&fin){
	clock_t iniciar, terminar;
	iniciar = clock();
	int b;
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		while(inicio != NULL){
			fin = inicio;
			inicio = fin -> siguiente;
			free(fin);
		}
		printf("COLA ELIMINADA\n");
	}
	terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f segundos\n", (double)(terminar - iniciar));
	printf("\n");
}

//FUNCION PARA SALVAR LOS DATOS DE LA COLA EN UN ARCHIVO DE TEXTO
void salvar_datos_cola(nodo *&inicio){
	clock_t iniciar, terminar;
	iniciar = clock();
	FILE *datos_cola;
	int aux;
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		datos_cola=fopen("datos_cola.txt", "a+b");
		while(inicio != NULL){
			aux = inicio ->dato;
			fwrite(&aux, sizeof(aux), 1, datos_cola);
			inicio = inicio ->siguiente;
		}
		fclose(datos_cola);
		printf("DATOS SALVADOS\n");
	}
	printf("El tiempo gastado en esta funcion fue de: %.0f segundos\n", (double)(terminar - iniciar));
	printf("\n");
}

//FUNCION PARA ORDENAR LOS DATOS EN LA COLA: METODO BURBUJA
void ordenar_datos_cola(nodo *inicio){
	clock_t iniciar, terminar;
	iniciar = clock();
	int aux;
	nodo * x = inicio;
	nodo * y = NULL;
	if(inicio == NULL){
		printf("COLA VACIA\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
	printf("El tiempo gastado en esta funcion fue de: %.0f segundos\n", (double)(terminar - iniciar));
	
	printf("\n");
}
