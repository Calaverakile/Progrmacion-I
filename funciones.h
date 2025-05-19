#ifndef funciones_h
#define funciones_h //Se define el header con el nombre de funciones.
/*
En este archivo las opciones de los dos menus que usara el usuario, ademas del ingreso de un nuevo producto, 
las validaciones de datos correspondientes de cada uno de estos...
*/
//aqui se definen las variables que va a necesitar cada producto...
struct producto {
    char nombre[50];
    int tiempo, demanda, recursos, recursosT, tiempoT, tiempoD, recursoD; //Se declaran las variables para la informacion del producto.
};
//valida a que el nombre solo contenga una palabra y el usuario no ingrese numeros...
int validarNombre(char nombre[]) {
    int i = 0;
    while (nombre[i] != '\0') {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z') || nombre[i] == ' ')) {
            return 0;
        }
        i++;
    }
    return 1;
}
//Esta funcion que permite al usuario agregar un nuevo producto...
int informacion (int *id2, struct producto prd[]){
    do {
        printf("Ingrese el nombre del producto: ");
        getchar(); //limpia el buffer para permitir ingresar el nombre correctamente
        scanf("%49[^\n]", prd[*id2].nombre);
        if (!validarNombre(prd[*id2].nombre)) {
            printf("INVALIDO: El nombre %s contiene numeros (El nombre solo puede contener palabras) \n>>> vuelva a intentarlo...\n", prd[*id2].nombre);
        }
    }   while (!validarNombre(prd[*id2].nombre));
    printf("ingrese los recursos necesarios producir el producto: ");
    scanf("%d", &prd[*id2].recursos);
    while(prd[*id2].recursos < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese los recursos necesarios producir el producto: ");
        scanf("%d", &prd[*id2].recursos);
    }
    printf("ingrese el tiempo de fabricacion del producto: ");
    scanf("%d", &prd[*id2].tiempo);
    while(prd[*id2].tiempo < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese el tiempo de fabricacion del producto: ");
        scanf("%d", &prd[*id2].tiempo);
    }
    printf("ingrese la demanda de produccion del producto: ");
    scanf("%d", &prd[*id2].demanda);
    while(prd[*id2].demanda < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese la demanda de produccion del producto: ");
        scanf("%d", &prd[*id2].demanda);
    }
    printf("ingrese el tiempo disponible de produccion: ");
    scanf("%d", &prd[*id2].tiempoD);
    while(prd[*id2].tiempoD < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese el tiempo disponible de produccion: ");
        scanf("%d", &prd[*id2].tiempoD);
    }
    printf("ingrese los recursos disponibles de produccion: ");
    scanf("%d", &prd[*id2].recursoD);
    while(prd[*id2].recursoD < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese los recursos disponibles de produccion: ");
        scanf("%d", &prd[*id2].recursoD);
    }
    //Mas detalles del producto
    printf("=== CALCULO DE DEMANDA ===\n");
    /* 
    Tiempo Total = Demanda del producto * tiempo de fabricacion
    Recursos totales = recusos * demanda del producto
    luego se hace una confirmacion de que si el tiempo disponble y los recursos disponibles
    puedan cumplir con la demanda dada.
    */
    prd[*id2].tiempoT = prd[*id2].demanda * prd[*id2].tiempo;
    printf("Tiempo total: %d\n", prd[*id2].tiempoT);
    prd[*id2].recursosT = prd[*id2].recursos * prd[*id2].demanda;
    printf("Recursos totales: %d\n", prd[*id2].recursosT);
    if ((prd[*id2].tiempoT <= prd[*id2].tiempoD) && (prd[*id2].recursosT <= prd[*id2].recursoD)){
        printf("La produccion disponible cumple con la demanda\n");
    } else {
        printf("La produccion disponible no cumple con la demanda\n");
    }
    return 0;
}
//Esta funcion permite al usuario editar los datos del producto seleccionado...
void restablecimiento(int *select, int *product, int *id3, struct producto prd[]){
    switch(*select){
        case 1:
        do {
        printf("Ingrese el nuevo nombre del producto: ");
        getchar(); //limpia el buffer para permitir ingresar el nombre correctamente
        scanf("%49[^\n]", prd[*product].nombre);
        if (!validarNombre(prd[*product].nombre)) {
            printf("INVALIDO: El nombre %s contiene numeros (El nombre solo puede contener palabras) \n>>> vuelva a intentarlo...\n", prd[*product].nombre);
        }
    }   while (!validarNombre(prd[*product].nombre));
        break;
        case 2:
        printf("ingrese nuevos recursos para la fabricacion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].recursos);
        while(prd[*product].recursos < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese nuevos recursos para la fabricacion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].recursos);
        }
        break;
        case 3:
        printf("ingrese nuevo tiempo de fabricacion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].tiempo);
        while(prd[*product].tiempo < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese nuevo tiempo de fabricacion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].tiempo);
        }
        break;
        case 4:
        printf("ingrese nuevo tiempo disponible de produccion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].tiempoD);
        while(prd[*product].tiempoD < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese nuevo tiempo disponible de produccion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].tiempoD);
        }
        break;
        case 5:
        printf("ingrese nuevo recusos disponibles de produccion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].recursoD);
        while(prd[*product].recursoD < 0){
        printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
        printf("ingrese nuevo recusos disponibles de produccion del producto %s: ", prd[*product].nombre);
        scanf("%d", &prd[*product].recursoD);
        }
        break;
        case 6:
        printf("Eliminando producto '%s'...\n", prd[*product].nombre);
        //Envia la informacion completa de     ese producto a una id no     accesible...
        for (int i = *product; i < *id3 - 1; i++) {
            prd[i] = prd[i + 1];
        }
        *id3--; 
        printf("se a eliminado correctamente...\n");
        break;
    }
}
//Esta funcion permite la observacion los calculos de la demanda del producto seleccionado...
void demandas (int *product2, struct producto prd[]){
    printf("=== CALCULOS DE DEMANDA ===\n");
    printf(">>> %s <<<\n", prd[*product2].nombre);
    prd[*product2].tiempoT = prd[*product2].demanda * prd[*product2].tiempo;
    printf("Tiempo total: %d\n", prd[*product2].tiempoT);
    prd[*product2].recursosT = prd[*product2].recursos * prd[*product2].demanda;
    printf("Recursos totales: %d\n", prd[*product2].recursosT);
    //verifica que se cumpla con demanda deacuerdo con el tiempo y los recursos disponibles...
    if ((prd[*product2].tiempoT <= prd[*product2].tiempoD) && (prd[*product2].recursosT <= prd[*product2].recursoD)){
        printf("La produccion disponible cumple con la demanda\n");
    } else {
        printf("La produccion disponible no cumple con la demanda\n");
    }
}
#endif