#include<stdio.h>
#include "funciones.h"
/*
IDEA BASE:
EL programa se compone de dos menus interactivos y una tabla con la informacion correspondiente del producto.
El programa tendra la siguiente estructura a seguir:
Cuando el usuario ejecute el programa se mostrara el menu general en donde tendra las siguientes opciones:
 - nuevo producto (Aqui el usuario ingresara la informacion correspondiente al producto agregado)
 - Editar el inventario (Aqui el usuario podra editar, cada dato del producto seleccionado)
 - Ver inventario (Aqui se mostrara la tabla del producto)
 - calculo de demanda (aqui se podra observar el calculo de demanda del producto que se haya seleccionado)
Cuando el usuario quiera editar un producto se mostrara el menu para seleccionar un producto con las siguientes opciones:
  - renombrar 
  - nuevos recursos
  - nuevo tiempo
  - nuevo tiempo disponible
  - nuevo recuros disponibles
  - Eliminar
cuando el usuario desee salir se mostrara un texto de agradecimiento.
el usuario usuario podra moverse entre menus ingresando su seleccion y para volver al anterior menu o salir del programa ingresando 0.
valida que el usuario ingrese numeros positivos.
las opciones no van a funcionar si no ingresa el producto el usuario.
*/

int main()
{
    int id=0;
    int slc, slc2; //Variables para la interaccion de los dos menus.
    struct producto prd[100];
    int opciones;
    printf("=>>> BIENVENIDO <<<=\n\n");
    //INVENTARIO GENERAL (donde el usuario ingresara lo que desea hacer)...
    printf("=== INVENTARIO GENERAL === \n>>> Para salir ingrese 0 \n1) Nuevo Producto \n2) Editar Inventario \n3) Ver Inventario \n4) Calculo de demanda \ningrese su opcion: ");
        scanf("%d", &opciones);
    while (opciones > 0){
        switch (opciones){
            case 1: 
            id++;
            informacion(&id, &*prd);
            break;
            case 2:
            //SELECCION DE PRODUCTO (El usuario ingresa el producto que desea editar)...
            //verificara si hay producto y si este no a ingresado, le enviara a ingresarlo...
            if(id !=0 ){
                printf("=== SELECCION DE PRODUCTO === \n >>> para volver ingrese 0\n");
                printf("n | nombre |\n");
                /*
                Este hara que i se vaya sumando hasta llegar a la canitdad de productos agregados
                por el usuario, ya que cada producto tiene su respectiva id.
                Para cuando el usuario elija uno de esos productos solo se le llamara por su id.
                */
                for(int i=1; i<=id; i++) {
                    printf("%d | %s |\n", i, prd[i].nombre);
                }
                printf("ingrese su opcion: ");
                scanf("%d", &slc);
                while (slc < id+1 && slc > 0 ) {
                    //MENU DE RESTABLECIMIENTO (el usuario ingresa lo que desea hacer con el producto  seleccionado)...
                    printf("=== RESTABLECIMIENTO === \n>>> ingrese cualquier 0 para volver \n1) Renombrar \n2) Editar Cantidad \n3) Editar tiempo \n4) Editar recursos disponibles \n5) Editar tiempo disponible \n6) Eliminar \nIngrese su seleccion: ");
                    scanf("%d", &slc2);
                    while (slc2 > 0) {
                        switch(slc2){
                            case 1:
                            do {
                            printf("Ingrese el nuevo nombre del producto: ");
                            getchar(); //limpia el buffer para permitir ingresar el nombre correctamente
                            scanf("%49[^\n]", prd[slc].nombre);
                            if (!validarNombre(prd[slc].nombre)) {
                                printf("INVALIDO: El nombre %s contiene numeros (El nombre solo puede contener palabras) \n>>> vuelva a intentarlo...\n", prd[slc].nombre);
                                }
                            }   while (!validarNombre(prd[slc].nombre));
                            break;
                            case 2:
                            printf("ingrese nuevos recursos para la fabricacion del producto %s: ", prd[slc].nombre);
                            while(scanf("%d", &prd[slc].recursos)!= 1 || prd[slc].recursos < 0 ){
                                printf("\nINVALIDO: no se puede ingresar numeros negativos o decimales \n>>> vuelva a intentarlo\n");
                                while (getchar() != '\n');
                                printf("ingrese nuevos recursos para la fabricacion del producto %s: ", prd[slc].nombre);
                            }
                            break;
                            case 3:
                            printf("ingrese nuevo tiempo de fabricacion del producto %s: ", prd[slc].nombre);
                            while(scanf("%d", &prd[slc].tiempo)!= 1 || prd[slc].tiempo < 0){
                                printf("\nINVALIDO: no se puede ingresar numeros negativos o decimales \n>>> vuelva a intentarlo\n");
                                while (getchar() != '\n');
                                printf("ingrese nuevo tiempo de fabricacion del producto %s: ", prd[slc].nombre);
                            }
                            break;
                            case 4:
                            printf("ingrese nuevo tiempo disponible de produccion del producto %s: ", prd[slc].nombre);
                            while(scanf("%d", &prd[slc].tiempoD) != 1 || prd[slc].tiempoD > 0 ){
                            printf("\nINVALIDO: no se puede ingresar numeros negativos o decimales \n>>> vuelva a intentarlo\n");
                            while (getchar() != '\n');
                            printf("ingrese nuevo tiempo disponible de produccion del producto %s: ", prd[slc].nombre);
                            }
                            break;
                            case 5:
                            printf("ingrese nuevo recusos disponibles de produccion del producto %s: ", prd[slc].nombre);
                            while(scanf("%d", &prd[slc].recursoD) != 1 || prd[slc].recursoD < 0){
                            printf("INVALIDO: no se puede ingresar numeros negativos \n>>> vuelva a intentarlo\n");
                            printf("ingrese nuevo recusos disponibles de produccion del producto %s: ", prd[slc].nombre);
                            }
                            break;
                            case 6:
                            printf("Eliminando producto '%s'...\n", prd[slc].nombre);
                            //Envia la informacion completa de ese producto a una id no accesible...
                            prd[0].nombre == prd[slc].nombre;
                            id--; 
                            printf("se a eliminado correctamente...\n");
                            break;
                            }   
                        printf("=== RESTABLECIMIENTO === \n>>> ingrese cualquier 0 para volver \n1) Renombrar \n2) Editar Cantidad \n3) Editar tiempo \n4) Editar recursos disponibles \n5) Editar tiempo disponible \n6) Eliminar \nIngrese su seleccion: ");
                        scanf("%d", &slc2);
                    }
                    printf("=== SELECCION DE PRODUCTO === \n >>> para volver ingrese 0\n");
                    printf("n | nombre |\n");
                    for(int i=1; i<=id; i++) {
                        printf("%d | %s |\n", i, prd[i].nombre);   
                    }
                    printf("ingrese su opcion: ");
                    scanf("%d", &slc);
                }
            }
            else {
                printf(">>> No hay productos agregados.. \n> Porfavor agregue un nuevo producto <\n");
                id++;
                informacion(&id, &*prd);
            }
            break;
            case 3:
            //MENU INVENTARIO (Se muestra una tabla con todos los productos ingresados)...
            if (id != 0 ){
                printf("================================== INVENTARIO ======================================\n");
                printf("n | nombre | recursos | tiempo | tiempo disponible | recursos disponible | demanda |\n");
                for(int k=1; k<=id; k++ ){
                    printf("%d | %s | %d | %d | %d | %d | %d |\n", k, prd[k].nombre, prd[k].recursos, prd[k].tiempo, prd[k].tiempoD, prd[k].recursoD, prd[k].demanda); 
                }
                printf("====================================================================================\n");
            }
            else{
                printf(">>> No hay productos agregados.. \n> Porfavor agregue un nuevo producto <\n");
                id++;
                informacion(&id, &*prd);
            }
            break;
            case 4:
            //CALCULO DE DEMANDA (Aqui selecciona el usuario que producto quiere calcular)...
            if(id != 0) {
                printf("=== SELECCION DE PRODUCTO === \n >>> para volver ingrese 0\n");
                printf("n | nombre |\n");
                for(int i=1; i<=id; i++) {
                    printf("%d | %s |\n", i, prd[i].nombre);   
                }
                printf("ingrese su opcion: ");
                scanf("%d", &slc);
                demandas(&slc, prd);
            }
            else {
                printf(">>> No hay productos agregados.. \n> Porfavor agregue un nuevo producto <\n");
                id++;
                informacion(&id, &*prd);
            }
            break;
        }
        //Se vuelve a mostrar el INVENTARIO GENERAL...
        printf("=== INVENTARIO GENERAL === \n>>> Para salir ingrese 0 \n1) Nuevo Producto \n2) Editar Inventario \n3) Ver Inventario \n4) Calculo de demanda \ningrese su opcion: ");
        scanf("%d", &opciones);
    }
    //texto al salir del programa...
    printf(">>> GRACIAS POR UTILIZARME <<<");
    return 0;
}
