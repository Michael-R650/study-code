#include <stdio.h>
#include <string.h>
int main(){
char content[] = "Curly bird catches the worm";
char *p1 = content;
printf("Content 1: %s\n",content);
printf("Content 2: %c\n",*p1);
*p1='E';
*(p1+1)='a';
printf("Content 1: %s\n",content);
char buffer[99];
char *p2 = buffer;
printf("PLeas insert a phrase");
if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    *(p2+1)='c';
        printf("Input user: %s\n",buffer);
    }
}