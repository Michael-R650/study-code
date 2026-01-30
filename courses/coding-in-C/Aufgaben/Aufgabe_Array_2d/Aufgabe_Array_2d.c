#include <stdio.h>

int main(){
    //Matrizen mit Werten
    int matrix1[2][2]={{5,9},{3,6}};
    int matrix2[2][2]={{0,3},{2,1}};
    //Matrix fürs Zwischenspeichern
    int speicher[2][2]={{},{}};
    //Schleife zum vertauschen
    printf("Vor dem Vertauschen:\n");
    printf("%d\n",matrix1);
    printf("%d\n",matrix2);
    for(int i =0;i<=1;i++){
        for(int j = 0; j<=1;j++){
            speicher[i][j]= matrix1[i][j];
            matrix1[i][j]=matrix2[i][j];
            matrix2[i][j]=speicher[i][j];
            
        }
    }
    printf("Nach dem Vertauschen\n");
    printf("%d\n",matrix1);
    printf("%d\n",matrix2);

}