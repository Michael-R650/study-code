#include <stdio.h>

int main(){
    printf("Hello World");
    char test[100];
    //scanset
    //max 99 zeichen einlesen mit leerzeichen etc ^\n, bis ein zeilenumbruch kommt und diesen dann mit %*c verwerfen
    scanf("%99[^\n]%*c",test);
    return 0;
}