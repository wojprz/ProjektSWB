#include "./slowa.h"
#include "./liczby.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	int options, menu, liczba, modulo, temmod, deskryptor, count;
	char znak, decyzja;
    char slowo[100];
 
	while((options = getopt(argc, argv, "wp")) != -1)
	{
		switch(options)
		{
			case 'w':
                printf("Wojciech Przybyła i Przemysław Płóciennik\n");
		exit(0);
				break;
			case 'p':
                printf("Projekt na SWB\n");
		exit(0);
				break;
		}
    }
menu:
        printf("Wybierz: \n");
        printf("1)Sprawdzanie palindromu.\n");
        printf("2)Zliczanie wystąpień.\n");
        printf("3)Obliczanie mod.\n");
        scanf("%i", &menu);
		
		switch(menu)
		{
			case 1:
                printf("Podaj słowo!\n");
                scanf("%s", &slowo);
				if(palindrom(slowo))
                    printf("Słowo jest palindromem.\n");
				sleep(10);
				goto menu;
			case 2:
                printf("Podaj ciąg znaków!\n");
                scanf("%s", &slowo);
                printf("Podaj znak\n");
                scanf("%c", &znak);
                count = wystapienia(slowo, znak);
                printf("%i\n", count);
                printf("Czy zapisać wyniki do pliku? Y/N \n");
                scanf("%c", decyzja);
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						printf("Brak pliku!\n");
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    printf("Liczba wystąpień znaku: %c równa się: %i\n", znak, count);
					close(deskryptor);
				}	
                sleep(10);	
				goto menu;			
			case 3:
                printf("Podaj liczbę!\n");
                scanf("%i", &liczba);
                printf("Podaj modulo!\n");
                scanf("%i", &modulo);
				temmod = liczmod(liczba, modulo);
                printf("Liczba %i mod %i równa się: %i\n", liczba, modulo, temmod);
				
                printf("Czy zapisać wyniki do pliku? Y/N \n");
                scanf("%c", &decyzja);
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						printf("Brak pliku!\n");
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    printf("Liczba %i mod %i równa się: %i\n", liczba, modulo, temmod);
				    close(deskryptor);
				}	
                sleep(10);
				goto menu;
			default:
				goto menu;
		}
	
	return 0;
}
