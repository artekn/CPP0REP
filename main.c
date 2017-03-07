#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char* str) // funkcja obliczajaca dlugosc ciagu
{
    int i=0;
    while(str[i++]!=0);
    return i-1;
}

char* wstawdrugiciag(char* ciag1, char* ciag2, int m)
{
    char *zlaczenie;
    int i;

    zlaczenie = (char*) malloc ((mystrlen(ciag1)+mystrlen(ciag2)+1)*sizeof(char));

    i=0;

    while(i<m)
        zlaczenie[i++]=*(ciag1++); // skopiowanie poczatku ciagu 1

    while(*ciag2!=0)
        zlaczenie[i++]=*(ciag2++); // skopiowanie ciagu 2

    while(*ciag1!=0)
       zlaczenie[i++]=*(ciag1++); //dopisanie do zlaczenia koncowki ciagu 1

    return zlaczenie;

}

int main()
{
    char ciag1[50]={0}, ciag2[50];
    char *zlaczenie;
    int m;

    printf("Prosze wpisac ciag, ktore bedzie edytowany:\n");

    scanf("%50s", ciag1);

    printf("Prosze wpisac drugi ciag:\n");

    scanf("%50s", ciag2);

    printf("Prosze wpisac, na ktory znak pierwszego ciagu wpisac drugi ciag:\n");

    scanf("%d", &m);

    if (mystrlen(ciag1)<m){
        puts("Podano zle miejsce - pierwszy ciag jest zbyt krotkie");
        return 0;
    }

    printf("W ciagu \"%s\" wstawiony zostanie jako %d. znak ciag \"%s\"\n", ciag1, m, ciag2);

    zlaczenie=wstawdrugiciag(ciag1, ciag2, m);

    printf("Nowy napis: %s \n", zlaczenie);

    free(zlaczenie); // zwolnienie pamieci bufora

    return 0;
}
