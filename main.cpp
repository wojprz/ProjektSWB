#include "./slowa.hpp"
#include "./liczby.hpp"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
	int options, menu, liczba, modulo, temmod, deskryptor, count;
	std::string slowo, jest;
	char znak, decyzja;
	while((options = getopt(argc, argv, "wp")) != -1)
	{
		switch(options)
		{
			case 'w':
                std::cout<<"Wojciech Przybyła i Przemysław Płóciennik\n";
		exit(0);
				break;
			case 'p':
                std::cout<<"Projekt na SWB\n";
		exit(0);
				break;
		}
menu:
        std::cout<<"Wybierz: \n";
        std::cout<<"1)Sprawdzanie palindromu.\n";
        std::cout<<"2)Zliczanie wystąpień.\n";
        std::cout<<"3)Obliczanie mod.\n";
        std::cin>>menu;
		
		switch(menu)
		{
			case 1:
                std::cin>>slowo;
				if(palindrom(slowo))
				{
                    std::cout<<"S¿owo jest palindromem.\n";
					jest = " jest ";
				}
				jest = " nie jest ";
                std::cout<<"Czy zapisa¿ wyniki do pliku? Y/N \n";
                std::cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						std::cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    std::cout<<"Slowo: "<<slowo<<jest<<"palindromem.\n";
					close(deskryptor);
				}	
                std::cin.ignore();
				system("cls");
				goto menu;
			case 2:
                std::cout<<"Podaj ciąg znaków!\n";
                std::cin>>slowo;
                std::cout<<"Podaj znak\n";
                std::cin>>znak;
                count = wystapienia(slowo, znak);
                std::cout<<count<<"\n";
                std::cout<<"Czy zapisać wyniki do pliku? Y/N \n";
                std::cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						std::cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    std::cout<<"Liczba wystąpień znaku: "<<znak<<"równa się: "<<count<<"\n";
					close(deskryptor);
				}	
                std::cin.ignore();
				system("cls");	
				goto menu;			
			case 3:
                std::cout<<"Podaj liczbę!\n";
                std::cin>>liczba;
                std::cout<<"Podaj modulo!\n";
                std::cin>>modulo;
				temmod = liczmod(liczba, modulo);
                std::cout<<liczba<<" mod "<<modulo<<"równa się: "<<temmod<<"\n";
				
                std::cout<<"Czy zapisa¿ wyniki do pliku? Y/N \n";
                std::cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						std::cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
                    std::cout<<liczba<<" mod "<<modulo<<" rowna się: "<<temmod<<"\n";
					close(deskryptor);
				}	
                std::cin.ignore();
				system("cls");
				goto menu;
			default:
				goto menu;
		}
	}
	return 0;
}
