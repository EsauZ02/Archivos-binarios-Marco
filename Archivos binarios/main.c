/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 *
 */

#include <stdio.h>
#include <stdlib.h>

 

void Nuevo();
void EscribirN();
void Agregar();
void Leer();

 


struct Fecha{
    int dia;
    int mes;
    int anio;
};

 

FILE*binario;

 

int main() {
     int numero=0;
    while(numero!=5){
        opciones:
        printf("¿Que es lo que desea relizar?\n");
        printf("1. Creacion de archivo\n");
        printf("2. Escritura en archivo nuevo\n");
        printf("3. Escritura al final en archivo existente\n");
        printf("4. Lectura de archivo\n");
        printf("5. Salir\n");
        scanf("%d",&numero);
        
        if((numero<=0) || (numero>5)){
            printf("Esta no es una opción valida\n\n");
            goto opciones;
        }
        
        switch(numero){
            case 1: Nuevo(); break;
            case 2: EscribirN(); break;
            case 3: Agregar(); break;
            case 4: Leer(); break;
        }
    }
    return 0;
    
  
}

 

void Nuevo(){
    binario=fopen("bianrio.dat","wb");
    if(binario==NULL){
        printf("Hubo un problema al crear su archivo\n\n");
    }else{
        printf("Su archivo se ha creado con éxito\n\n");
    }
    fclose(binario);
}
void EscribirN(){
    struct Fecha marco;
    binario=fopen("binario.dat","wb");
    printf("Fecha de nacimiento\n");
    printf("Día: ");
    scanf("%d",&marco.dia);
    printf("Mes: ");
    scanf("%d",&marco.mes);
    printf("Año: ");
    scanf("%d",&marco.anio);
    
    fwrite(&marco,sizeof(struct Fecha),1,binario);
    fclose(binario);
    
    printf("\n");
}
void Agregar(){
    struct Fecha marco2;
    binario=fopen("binario.dat","ab");
    printf("Fecha de nacimiento\n");
    printf("Día: ");
    scanf("%d",&marco2.dia);
    printf("Mes: ");
    scanf("%d",&marco2.mes);
    printf("Año: ");
    scanf("%d",&marco2.anio);
    
    fwrite(&marco2,sizeof(struct Fecha),1,binario);
    fclose(binario);
    
    printf("\n");
}
void Leer(){
    int n=0;
    int n2=0;
    struct Fecha m[10000];
    binario=fopen("binario.dat","rb");
    if(binario==NULL){
        printf("\nHubo un error al abrir el archivo\n");
    }else{
        while(feof(binario)==0){
            fread(&m[n],sizeof(m[n]),1,binario);
            n++;
        }
        printf("\n");
        while(n2<(n-1)){
            printf("%d/%d/%d\n",m[n2].dia, m[n2].mes, m[n2].anio);
            n2++;
        }
    }
    printf("\n");
    fclose(binario);
}
