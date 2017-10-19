/*
** MENU PRICIPAL, CON LOS SUBMENUS
*/

void menu();

void menu(){
	nodo * pila = NULL;
	nodo * inicio = NULL;
	nodo * fin = NULL;
	int opc=1;
	while(opc!=0){
		printf("MENU \n");
		printf("1. Pila \n");
		printf("2. Cola \n");
		printf("0. Salir \n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:{
				int opc=1;
				while(opc!=0){
					printf("OPERACIONES CON PILA \n");
					printf("1. Generar Datos\n");
					printf("2. Cargar Datos \n");
					printf("3. Visualizar Datos \n");
					printf("4. Eliminar Datos \n");
					printf("5. Buscar Datos \n");
					printf("6. Editar Datos \n");
					printf("7. Eliminar Pila \n");
					printf("8. Salvar Datos \n");
					printf("9. Ordenar Datos \n");
					printf("0. Salir \n");
					printf("Seleccione una opcion: ");
					scanf("%d", &opc);
					
					switch(opc){
						case 1:{
							int opc=1;
							while(opc!=0){
								printf("1. Un Millon de Datos \n");
								printf("2. Dos Millones de Datos \n");
								printf("3. Cinco Millones de Datos \n");
								printf("4. Diez Millones de Datos \n");
								printf("5. Veinte Millones de Datos \n");
								printf("0. Salir \n");
								printf("Seleccione una opcion: ");
								scanf("%d", &opc);
								switch(opc){
									case 1:{
										printf("Generando Un Millon de Datos \n");
										generar_datos(opc,pila);
										break;
									} 
									case 2:{
										printf("Generando Dos Millones de Datos \n");
										generar_datos(opc,pila);
										break;
									}
									case 3:{
										printf("Generando Cinco Millones de Datos \n");
										generar_datos(opc,pila);
										break;
									}
									case 4:{
										printf("Generando Diez Millones de Datos \n");
										generar_datos(opc,pila);
										break;
										
									}
									case 5:{
										printf("Generando Veinte Millones de Datos \n");
										generar_datos(opc,pila);
									
										break;
									}
									case 0:{
										break;
										}
									default:{
										printf("OPCION INVALIDA \n");;
										break;
									}	
								}
							}
							break;
						}
						case 2:{
							int opc=1;
							while(opc!=0){
								printf("Cargar Datos \n");
								printf("1. Un Millon de Datos \n");
								printf("2. Dos Millones de Datos \n");
								printf("3. Cinco Millones de Datos \n");
								printf("4. Diez Millones de Datos \n");
								printf("5. Veinte Millones de Datos \n");
								printf("0. Salir \n");
								printf("Seleccione una opcion: ");
								scanf("%d", &opc);
								switch(opc){
									case 1:{
										printf("Cargando Archivo con Un Millon de Datos\n");
										cargar_datos(opc,pila);
										break;
									}
									case 2:{
										printf("Cargando Archivo con  Dos Millones de Datos\n");
										cargar_datos(opc,pila);
										break;
									}
									case 3:{
										printf("Cargando Archivo con Cinco Millones de Datos\n");
										cargar_datos(opc,pila);
										break;
									}
									case 4:{
										printf("Cargando Archivo con Diez Millones de Datos\n");
										cargar_datos(opc,pila);
										break;
									}
									case 5:{
										printf("Cargando Archivo con Veinte Millon de Datos\n");
										cargar_datos(opc,pila);
										break;
									}
									case 0:{
										break;
									}
									default:{
										printf("OPCION INVALIDA \n");
										break;
									}
								}
							}
							break;
						}
						case 3:{
							printf("Visualizar Datos \n");
							visualizar_datos(pila);
							break;
						}
						case 4:{
							printf("Eliminar Datos \n");
							eliminar_datos(pila);
							break;
						}
						case 5:{
							printf("Buscar Datos \n");
							buscar_datos(pila);
							break;
						}
						case 6:{
							printf("Editar Datos \n");
							editar_datos(pila);
							break;
						}
						case 7:{
							printf("Eliminar Pila \n");
							eliminar_pila(pila);
							break;	
						}	
						case 8:{
							printf("Salvar Datos \n");
							salvar_datos(pila);
							break;	
						}
						case 9:{
							int opc = 1;
							while (opc != 0){;
							printf("Ordenar Datos \n");
							printf("1. Metodo No Eficiente \n");
							printf("2. Metodo  Eficiente \n");
							printf("Seleccione una opcion: ");
							scanf("%d", &opc);
							switch(opc){
								case 1:{
									printf("Metodo No Eficiente \n");
									ordenar_datos_ineficientemente(pila);
									break;
									}
								case 2:{
									printf("Metodo Eficiente \n");
									ordenar_datos_eficientemente(pila);
									break;
									}
								case 0:{
									break;
									}
								default:{
									printf("OPCION INVALIDA \n");
									break;
									}
								}	
							}
							break;	
						}	
						case 0:{
							break;
							}
						default:{
							printf("OPCION INVALIDA \n");
							break;
						}
					}
				}
			break;
			}
			case 2:{
					int opc=1;
					while(opc!=0){
						printf("OPERACIONES CON COLA \n");
						printf("1. Generar Datos\n");
						printf("2. Cargar Datos \n");
						printf("3. Visualizar Datos \n");
						printf("4. Eliminar Datos \n");
						printf("5. Buscar Datos \n");
						printf("6. Editar Datos \n");
						printf("7. Eliminar Cola \n");
						printf("8. Salvar Datos \n");
						printf("9. Ordenar Datos \n");
						printf("0. Salir \n");
						printf("Seleccione una opcion: ");
						scanf("%d", &opc);
						
						switch(opc){
						case 1:{
							int opc=1;
							while(opc!=0){
								printf("1. Un Millon de Datos \n");
								printf("2. Dos Millones de Datos \n");
								printf("3. Cinco Millones de Datos \n");
								printf("4. Diez Millones de Datos \n");
								printf("5. Veinte Millones de Datos \n");
								printf("0. Salir \n");
								printf("Seleccione una opcion: ");
								scanf("%d", &opc);
								switch(opc){
									case 1:{
										printf("Generando Un Millon de Datos \n");
										generar_datos_cola(opc, inicio, fin);
										break;
									} 
									case 2:{
										printf("Generando Dos Millones de Datos \n");
										generar_datos_cola(opc, inicio, fin);
										break;
									}
									case 3:{
										printf("Generando Cinco Millones de Datos \n");
										generar_datos_cola(opc, inicio, fin);
										break;
									}
									case 4:{
										printf("Generando Diez Millones de Datos \n");
										generar_datos_cola(opc, inicio, fin);
										break;
									}
									case 5:{
										printf("Generando Veinte Millones de Datos \n");
										generar_datos_cola(opc, inicio, fin);
										break;
									}
									case 0:{
										break;
									}
									default:{
										printf("OPCION INVALIDA \n");
										break;
									}	
								}
							}
						break;
						}
						case 2:{
							int opc=1;
							while(opc!=0){
								printf("Cargar Datos \n");
								printf("1. Un Millon de Datos \n");
								printf("2. Dos Millones de Datos \n");
								printf("3. Cinco Millones de Datos \n");
								printf("4. Diez Millones de Datos \n");
								printf("5. Veinte Millones de Datos \n");
								printf("0. Salir \n");
								printf("Seleccione una opcion: ");
								scanf("%d", &opc);
								switch(opc){
									case 1:{
										printf("Cargando Archivo con Un Millon de Datos\n");
										cargar_datos_cola(opc, inicio, fin);
										break;
									}
									case 2:{
										printf("Cargando Archivo con  Dos Millones de Datos\n");
										cargar_datos_cola(opc, inicio, fin);
										break;
									}
									case 3:{
										printf("Cargando Archivo con Cinco Millones de Datos\n");
										cargar_datos_cola(opc, inicio, fin);
										break;
									}
									case 4:{
										printf("Cargando Archivo con Diez Millones de Datos\n");
										cargar_datos_cola(opc, inicio, fin);
										break;
									}
									case 5:{
										printf("Cargando Archivo con Veinte Millon de Datos\n");
										cargar_datos_cola(opc, inicio, fin);
										break;
									}
									case 0:{
										break;
									}
									default:{
										printf("OPCION INVALIDA \n");
										break;
									}
								}
							}
							break;
						}
						case 3:{
							printf("Visualizar Datos \n");
							visualizar_datos_cola(inicio);
							break;
						}
						case 4:{
							printf("Eliminar Datos \n");
							eliminar_datos_cola(inicio, fin);							
							break;
						}
						case 5:{
							printf("Buscar Datos \n");
							buscar_datos_cola(inicio);							
							break;
						}
						case 6:{
							printf("Editar Datos \n");
							editar_datos_colas(inicio);							
							break;
						}
						case 7:{
							printf("Eliminar Cola \n");
							eliminar_cola(inicio, fin);							
							break;	
						}	
						case 8:{
							printf("Salvar Datos \n");
							salvar_datos_cola(inicio);							
							break;	
						}
						case 9:{
								int opc = 1;
								while (opc != 0){
								printf("Ordenar Datos \n");
								printf("1. Metodo No Eficiente \n");
								printf("2. Metodo  Eficiente \n");
								printf("Seleccione una opcion: ");
								scanf("%d", &opc);
								switch(opc){
									case 1:{
										printf("Metodo No Eficiente \n");
										ordenar_datos_cola(inicio);
										break;
									}
									case 2:{
										printf("Metodo Eficiente \n");
										
										break;
									}
									case 0:{
										break;
									}
									default:{
										printf("OPCION INVALIDA \n");
										break;
									}
								}	
							}
							break;	
						}	
						case 0:{
							break;
						}
						default:{
							printf("OPCION INVALIDA \n");
							break;
						}
					}
				}
			break;	
			}
		}
	}
}
