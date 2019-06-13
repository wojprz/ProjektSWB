#include "./slowa.hpp"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;
int main(int argc, char *argv[])
{
	int options, menu, liczba, modulo, temmod, deskryptor, count;
	string slowo, jest;
	char znak, decyzja;
	
	while((options = getopt(argc, argv, "wp")) != -1)
	{
		switch(options)
		{
			case 'w':
				cout<<"Wojciech Przyby³a i Przemys³aw P³óciennik\n";
		exit(0);
				break;
			case 'p':
				cout<<"Projekt na SWB\n";
		exit(0);
				break;
		}
menu:
		cout<<"Wybierz: \n";
		cout<<"1)Sprawdzanie palindromu.\n";
		cout<<"2)Zliczanie wyst¹pieñ.\n";
		cout<<"3)Obliczanie mod.\n";
		cin>>menu;
		
		switch(menu)
		{
			case 1:
				cin>>slowo;
				if(palindrom(slowo))
				{
					cout<<"S³owo jest palindromem.\n";
					jest = " jest ";
				}
				jest = " nie jest ";
				cout<<"Czy zapisaæ wyniki do pliku? Y/N \n";
				cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
					cout<<"Slowo: "<<slowo<<jest<<"palindromem.\n";
					close(deskryptor);
				}	
				cin.ignore();
				system("cls");
				goto menu;
			case 2:
				cout<<"Podaj ci¹g znaków!\n";
				cin>>slowo;
				cout<<"Podaj znak\n";
				cin>>znak;
				count = wystapienia(slowo, znak);
				cout<<count<<endl;
				cout<<"Czy zapisaæ wyniki do pliku? Y/N \n";
				cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
					cout<<"Liczba wyst¹pieñ znaku: "<<znak<<"równa siê: "<<count<<endl;
					close(deskryptor);
				}	
				cin.ignore();
				system("cls");	
				goto menu;			
			case 3:
				cout<<"Podaj liczbê!\n";
				cin>>liczba;
				cout<<"Podaj modulo!\n";
				cin>>modulo;
				temmod = liczmod(liczba, modulo);
				cout<<liczba<<" mod "<<modulo<<"równa siê: "<<temmod<<endl;
				
				cout<<"Czy zapisaæ wyniki do pliku? Y/N \n";
				cin>>decyzja;
				if(decyzja == 'Y')
				{
					deskryptor = open("wyniki.txt", 1);
					if((deskryptor=open("wyniki.txt", 1)) == -1)
						cout<<"Brak pliku!\n";
					dup2(deskryptor, 1);
					write(deskryptor, "Nowe zadanie\n", 13);
					cout<<liczba<<" mod "<<modulo<<" rowna siê: "<<temmod<<endl;
					close(deskryptor);
				}	
				cin.ignore();
				system("cls");
				goto menu;
			default:
				goto menu;
		}
	}
	return 0;
}
