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
    int saved_stdout;
    saved_stdout = dup(1);
 
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
        printf("4)Wyjście.\n");
        scanf("%i", &menu);
		
		switch(menu)
		{
			case 1:
                printf("Podaj słowo!\n");
                scanf("%s", &slowo);
				if(palindrom(slowo))
                    printf("Słowo jest palindromem.\n");
                else
                    printf("Słowo nie jest palindromem.\n");
				sleep(5);
                goto menu;
			case 2:
                printf("Podaj ciąg znaków!\n");
                scanf("%s", &slowo);
                printf("Podaj znak\n");
                scanf("%s", &znak);
                count = wystapienia(slowo, znak);
                printf("Znak pojawia się: %i\n", count);
				
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
                    {
                        printf("Brak pliku!\n");
                        goto koniec;
                    }
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    printf("Liczba wystąpień znaku: %c równa się: %i\n", znak, count);
					dup2(saved_stdout, 1);
                    printf("Zapisano plik!\n");
                    close(deskryptor);
                sleep(5);
                goto menu;
			case 3:
                printf("Podaj liczbę!\n");
                scanf("%i", &liczba);
                printf("Podaj modulo!\n");
                scanf("%i", &modulo);
				temmod = liczmod(liczba, modulo);
                printf("Liczba %i mod %i równa się: %i\n", liczba, modulo, temmod);
				
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
                    {
						printf("Brak pliku!\n");
                        goto koniec;
                    }
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    printf("Liczba %i mod %i równa się: %i\n", liczba, modulo, temmod);
                    dup2(saved_stdout, 1);
                    printf("Zapisano plik\n");
                    close(deskryptor);
                sleep(5);
                goto menu;
            case 4:
                goto koniec;
			default:
				printf("Zły wybór!\n");
                sleep(5);
                goto koniec;
		}
koniec:
    printf("Dowidzenia!\n");
    return 0;
}
