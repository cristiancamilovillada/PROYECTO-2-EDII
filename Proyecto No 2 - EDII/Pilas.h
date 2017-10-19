/*
** FUNCIONES APLICADAS A PILAS
*/

// STRUCT PARA LAS LISTAS
struct nodo{
	int dato;
	nodo * siguiente;
};

int contador,contaux;

//DECLARACION DE FUNCIONES
void generar_datos(int , nodo *&);
void cargar_datos(int , nodo *&);
void insertar_datos_pila(int , nodo *&);
bool pila_vacia(nodo *);
void visualizar_datos(nodo *);
void eliminar_datos(nodo *&);
void buscar_datos(nodo *);
void editar_datos(nodo *&);
void eliminar_pila(nodo *&);
void salvar_datos(nodo *);
void ordenar_datos_ineficientemente(nodo *&);
void ordenar_datos_eficientemente(nodo *&);

//FUNCION PARA GENERAR DATOS EN PILAS
void generar_datos(int opc , nodo *&pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	int cantidad, num_aleatorio, x;
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
	for(x = 1;x <= cantidad; x++ ){
		num_aleatorio = (rand() % (1999999 + 1)- 999999);
		//printf("%d %d \n",contador,num_aleatorio);
		insertar_datos_pila(num_aleatorio, pila);
		contador++;
	}
	printf("datos generados \n");
	terminar = clock();
	printf("El tiempo gastado en esta funcion fue de: %.0f milisegundos\n", (double)(terminar - iniciar));
}

//FUNCION PARA INSERTAR LOS DATOS EN LA PILA
void insertar_datos_pila(int num_aleatorio , nodo *& pila){
	nodo * nuevo_nodo = reservar_memoria;
	nuevo_nodo -> dato = num_aleatorio;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;
}

//FUNCION DE PILA VACIA
bool pila_vacia(nodo *pila){
	return (pila == NULL) ? true:false;
}

//FUNCION PARA VISUALIZAR DATOS
void visualizar_datos(nodo *pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	nodo *auxiliar = pila;
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");		
	}else{
		while(auxiliar != NULL){
			printf("%d", auxiliar -> dato);
			auxiliar = auxiliar -> siguiente;
			printf(" ");
		}
		printf("\n");
	}
	terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar-iniciar));
}

//FUNCION PARA BUSCAR DATOS
void buscar_datos(nodo *pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	int b,contaux=contador-1,encontrado=0;
	printf("Digite el elemento a buscar \n");
	scanf("%d", &b);
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
		while(pila != NULL){
			if(b == pila->dato){
				printf("Dato encontrado en la posicion %d y su direccion de memoria es : %p \n" ,contaux,&pila->dato );
				encontrado=1;
				break;
			}pila = pila->siguiente;
				contaux--;
			}
			if(encontrado!=1){
				printf("dato no encontrado \n");
			}
		}terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar-iniciar));
}

//FUNCION PARA ELIMINAR DATOS
void eliminar_datos(nodo *&pila){
	int b;
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
		nodo *auxiliar = pila;
		pila = auxiliar->siguiente;
		b = auxiliar->dato;
		free(auxiliar);
		contaux=contador--;
		printf("Elemento eliminado \n");
	}
}

//FUNCION PARA EDITAR DATOS
void editar_datos(nodo *&pila){
	nodo *auxiliar = pila;
	int b, nuevo_dato,opceliminar=0,contaux=contador-1;
	printf("Digite el elemento a buscar \n");
	scanf("%d", &b);
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
		while(auxiliar != NULL){
			if(b == auxiliar->dato){
				printf("Dato encontrado en la posicion %d y su direccion de memoria es : %p \n" ,contaux,&pila->dato );
				printf("desea editar el dato 1.si - 2.no\n");
				scanf("%d",&opceliminar);
				if(opceliminar == 1){
					printf("Ingrese el nuevo dato\n");
					scanf("%d", &nuevo_dato);
					auxiliar -> dato = nuevo_dato;
					printf("Dato editado correctamente\n");
				}
					break;
				}auxiliar = auxiliar->siguiente;
					contaux--;
			}
		}
}

//FUNCION PARA ELIMINAR PILA
void eliminar_pila(nodo *&pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	int b;
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
	while(pila != NULL){
			nodo *auxiliar = pila;
			pila = auxiliar->siguiente;
			b = auxiliar->dato;
			free(auxiliar);
		}
		printf("Pila eliminada\n");
	}terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar-iniciar));
}

//FUNCION PARA SALVAR LOS DATOS
void salvar_datos(nodo *pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	int numero=0;
	FILE *datos_pila;
	datos_pila=fopen("datos_pila.txt","ab");

	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
		while(pila!= NULL){
			fwrite(&pila->dato,sizeof(pila->dato),1,datos_pila);
			pila = pila -> siguiente;
		}
		printf("datos guardados \n");
	}
	fclose(datos_pila);
	terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar-iniciar));
}
 //FUNCION PARA ORDENAR LOS DATOS: METODO BURBUJA
void ordenar_datos_ineficientemente(nodo *&pila){
	clock_t iniciar, terminar;
	iniciar = clock();
	int aux;
	nodo * nodo_auxiliar_1 = pila;
	nodo * nodo_auxiliar_2 = NULL;
	if(pila_vacia(pila)){
		printf("Pila Vacia \n");
	}else{
		while(nodo_auxiliar_1 != NULL){
			nodo_auxiliar_2 = nodo_auxiliar_1 -> siguiente;
			while(nodo_auxiliar_2 != NULL){
				if(nodo_auxiliar_1 -> dato > nodo_auxiliar_2 -> dato){
					aux = nodo_auxiliar_1 -> dato;
					nodo_auxiliar_1 -> dato = nodo_auxiliar_2 -> dato;
					nodo_auxiliar_2 -> dato = aux;
				}
				nodo_auxiliar_2 = nodo_auxiliar_2 -> siguiente;
			}
			nodo_auxiliar_1 = nodo_auxiliar_1 -> siguiente;
		}
	}
	terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar-iniciar));
	printf("datos ordenados\n");
}

//FUNCION PARA ORDENAR DATOS: METODO QUICK SORT
void ordenar_datos_eficientemente(nodo *&pila){
nodo *nodo_auxiliar_1=pila;
nodo *nodo_auxiliar_2=NULL;
nodo *nodo_auxiliar_3=NULL;
nodo *copia_nodo_aux1=nodo_auxiliar_1;


int inicio,ultimo,pivote,central,i,j,con_pos=1,aux;
	while(nodo_auxiliar_1 != NULL){
		nodo_auxiliar_1 = nodo_auxiliar_1->siguiente;
		if(nodo_auxiliar_1==NULL)
		{
			ultimo = con_pos;
		}
		con_pos++;
	}
	inicio = 1;
	central = (inicio+ultimo)/2;
	nodo_auxiliar_1 = copia_nodo_aux1;
	while(nodo_auxiliar_1 != NULL)
	{
		int con_pos_aux=con_pos--;
		nodo_auxiliar_1=nodo_auxiliar_1->siguiente;
		if (central == con_pos-1)
		{	
			pivote = nodo_auxiliar_1 -> dato;
		}con_pos_aux--;
	}
	//i = inicio;
	//j = ultimo;
	//printf("%d\n", pivote);
	//printf("%d\n", central);
	//printf("%d\n", inicio);
	//printf("%d\n", ultimo);
	//printf("%d\n", con_pos);
	nodo_auxiliar_1 = copia_nodo_aux1;
	while(nodo_auxiliar_1!= NULL){
		if(nodo_auxiliar_1->dato > pivote){
			insertar_datos_pila(nodo_auxiliar_1->dato, nodo_auxiliar_2);
			
		}else{
			insertar_datos_pila(nodo_auxiliar_1->dato, nodo_auxiliar_3);
					
		}nodo_auxiliar_1=nodo_auxiliar_1->siguiente;
	}
	nodo_auxiliar_1 = copia_nodo_aux1;
	//se realiza copia de los nodos para que vuelvan a la poscicion inicial
	nodo *copia_nodo_aux2=nodo_auxiliar_2;
	nodo *copia_nodo_aux3=nodo_auxiliar_3;
	//nodo_auxiliar_3 = copia_nodo_aux3;
	while(nodo_auxiliar_3!=NULL){
		nodo_auxiliar_1->dato=nodo_auxiliar_3->dato;
		nodo_auxiliar_3=nodo_auxiliar_3->siguiente;
		nodo_auxiliar_1=nodo_auxiliar_1->siguiente;
	}
	while(nodo_auxiliar_2!=NULL){
		nodo_auxiliar_1->dato=nodo_auxiliar_2->dato;
		nodo_auxiliar_2=nodo_auxiliar_2->siguiente;
		nodo_auxiliar_1=nodo_auxiliar_1->siguiente;
	}	
		
	nodo_auxiliar_1=copia_nodo_aux1;
	nodo_auxiliar_2 = copia_nodo_aux2;
	nodo_auxiliar_3 = copia_nodo_aux3;
	int bandera,tem_aux;
	do{
		bandera=0;
		nodo_auxiliar_1=copia_nodo_aux1;
		for(int i=0;i < con_pos-1;i++){
		aux=nodo_auxiliar_1->siguiente->dato;
		if(nodo_auxiliar_1->dato > aux){
			tem_aux = nodo_auxiliar_1->dato;
			nodo_auxiliar_1->dato = aux;
			nodo_auxiliar_1->siguiente->dato=tem_aux;
			bandera++;
		}
		nodo_auxiliar_1=nodo_auxiliar_1->siguiente;
		}
	}while( bandera > 0);
}

//FUNCION PARA CARGAR DATOS DE UN ARCHIVO
void cargar_datos(int opc , nodo *&pila){
	clock_t iniciar,terminar;
	iniciar = clock();
	FILE *archivo;
	int dato;
	contador=1;
	while(opc != 0){
		switch(opc){
		case 1:{			
			archivo = fopen("un_millon.txt","rb");
			break;
			}
		case 2:{			
			archivo = fopen("dos_millones.txt","rb");	
			break;
			}
		case 3:{			
			archivo = fopen("cinco_millones.txt","rb");	
			break;
			}
		case 4:{			
			archivo = fopen("diez_millones.txt","rb");	
			break;	
			}
		case 5:{
			archivo = fopen("veinte_millones.txt","rb");	
			break;	
			}
		}break;
	}
	while(fread(&dato,sizeof(dato),1,archivo)){
		insertar_datos_pila(dato, pila);
	}
	terminar = clock();
	printf("el tiempo de duracion es: %f \n",(double)(terminar - iniciar));
}