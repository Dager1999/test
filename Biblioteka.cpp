#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#define L 40
#define MAX 10
using namespace std;

class biblioteka
{
		protected: //private:
			char tytul [L];
			char gatunek [L];
			char autor [L];
			char wydawnictwo [L];
			float ile_wypozyczono;
			int ile_sztuk;
		public:
				biblioteka();
			void czysc();
			void pobierz(char *tyt, char gat, char aut, char wydaw, int ile_wyp, int ile_szt);
			void drukuj(); 
			float CenaZaNieoddanie();
};

class bazabiblioteka:public biblioteka
{
	protected:
		ksiazki tab[MAX];
		int licznosc;
	private:
		int i;
	public:
		bazabiblioteka();
		void DodajKolejny (char *tyt, char gat, char aut, char wydaw, int ile_wyp, int ile_szt);
		void CzyscCalosc ();
		void DrukujCalosc ();
		void CenyZaBrakZwrotu();
		bool SaveFile();
		bool ReadFile();
		

	biblioteka::biblioteka()
		{
			strcpy(tytul," ");
			strcpy(gatunek," ");
			strcpy(autor," ");
			strcpy(wydawnictwo," ");
			ile_wypozyczono=0;
			ile_sztuk=0;
		}
	
		void biblioteka::czysc()
		{
			strcpy(tytul," ");
			strcpy(gatunek," ");
			strcpy(autor," ");
			strcpy(wydawnictwo," ");
			ile_wypozyczono=0;
			ile_sztuk=0;	
		}
	
	void biblioteka::pobierz(char *tyt, char gat, char aut, char wydaw, int ile_wyp, int ile_szt)
		{
			strcpy(tytul, tyt);
			strcpy(gatunek, gat);
			strcpy(autor, aut);
			strcpy(wydawnictwo, wydaw);
			ile_wypozyczono=ile_wyp;
			ile_sztuk=szt;
		}	
	
	void biblioteka::drukuj()
		{
			cout<<tytul<<"     "<<autor<<"     "<<gatunek<<"      "<<wydawnictwo<<"      "<<ile_wypozyczono<<"     "<<ile_sztuk<<endl;
		}	
	
	float biblioteka::CenaZaBrakZwrotu()
		{
			return ile_wypozyczono*0.10;
		}
		
		bazabiblioteka::bazabiblioteka()
		{
			for(i=0; i<MAX; i++)
			{
				tab[i].czysc
			}
			licznosc=0;
		}
		
		void bazabiblioteka::CzyscCalosc()
		{
			for(i=0; i<MAX; i++)
			{
				tab[i].czysc
			}
			licznosc=0;
		}
		
		void bazabiblioteka::DodajKolejny(char *tyt, char gat, char aut, char wydaw, int ile_wyp, int ile_szt)
		{
			if(licznosc<MAX)
			{
				tab[licznosc].pobierz(tyt, gat, aut, wydaw, ile_wyp, ile_szt)
				licznosc++
			}
		}
		
		void bazabiblioteka::DrukujCalosc()
		{
			for(i=0; i<MAX; i++)
			tab[i].drukuj();
		}
		
		void bazabiblioteka::CenyZaBrakZwrotu()
		{
			for(i=0; i<MAX; i++)
			cout<<tab[i].CenyZaBrakZwrotu()<<endl;	
		}
		
		bool bazabiblioteka::SaveFile()
		{
			FILE *fp;
			
			if((fp=fopen("dane.dat", "wb"))=NULL);
				return false;
			else
			fwrite(&ile_sztuk, sizeof(ile_sztuk), 1, fp);
			fwrite(&licznosc, sizeof(licznosc), 1, fp);
			for(i=0; i<licznosc; i++)
				fwrite(&tab[i], sizeof(tab[i]), 1, fp);
			fclose(fp);
				return true;

		}
		
		bool bazabiblioteka::ReadFile()
		{
			FILE *fp;
			
			if((fp=fopen("dane.dat", "rb"))=NULL);
				return false;
			else
			fwrite(&ile_sztuk, sizeof(ile_sztuk), 1, fp);
			fwrite(&licznosc, sizeof(licznosc), 1, fp);
			for(i=0; i<licznosc; i++)
				fwrite(&tab[i], sizeof(tab[i]), 1, fp);
			fclose(fp);
				return true		
		}
main()
{
	biblioteka, bazabiblioteka;
	char n[L], zn, g, w;
	int i_w, i_sz;
	
	do
		{
			cout<<"1.czyszczenie"<<endl;
			cout<<"2.czytanie"<<endl;
			cout<<"3.drukowanie"<<endl;
			cout<<"4.wartosc"<<endl;
			cout<<"5.koniec"<<endl<<endl;
			zn=getch();
			switch (zn)
				{
					case '1': 	biblioteka.CzyscCalosc();
								break;
					case '2': {	
									cout<<"Tytul: "; gets(n);
									cout<<"Autor: "; cin>>a;
									cout<<"Gatunek: "; cin>>g;
									cout<<"Wydawnictwo: "; cin>>w;
									cout<<"Ile wypozyczono: "; cin>>i_w;
									cout<<"Ile sztuk zostalo: "; cin>>i_sz;
									cin.ignore();
									biblioteka.DodajKolejny(n, a, g, w, i_w, i_sz);
									break;
								}
					case '3': 	biblioteka.DrukujCalosc();
								break;
					case '4' : 	cout<<biblioteka.CenaZaBrakZwrotu()<<endl;
								break;
					case '5' : 	cout<<"do widzenia"<<endl;
								break;
					case '6' :  biblioteka.SaveFile();
								cout<<"Zapisano"<<endl;
								break;
					case '7' :  biblioteka.ReadFile();
								cout<<"Zapisano"<<endl;
								break;
					getchar();
				}
		}
		while (zn!='5');
}
