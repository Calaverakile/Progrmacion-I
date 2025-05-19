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
                        restablecimiento(&slc2, &slc, &id, &*prd);
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