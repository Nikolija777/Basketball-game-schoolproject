#include <iostream>
#include "basketgame.h"
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
int main(){
	BasketGame b(5);
	start:
	system("Color 0E");
	system("cls");
	cout<<"Odaberite jednu od sledecih opcija klikom odredjenog dugmeta na tastaturi:"<<endl;
	cout<<"a-Nova utakmica"<<endl<<"b-Pretrazi stare utakmice"<<endl<<"c-Napusti program"<<endl;
	char ch;
	cin>>ch;
	if(ch=='a'){
		tekma:
		system("cls");
		system("Color 0E");
		cout<<"Izaberite nacin unosa timova:"<<endl<<"d-default inicijalizacija"<<endl<<"u-unos podataka"<<endl;
		char c;
		cin>>c;
		if(c=='d'){
			system("cls");
			cout<<"Utakmica je pocela."<<endl;
			pekijeglup:
			cout<<"Evo skracenica za unos desavanja na utakmici:"<<endl<<"3+ - pogodjena trojka"<<endl<<"3- - promasena trojka"<<endl<<"2+ - pogodjena dvojka"<<endl<<"2- - promasena dvojka "<<endl<<"1+ - pogodjeno bacanje"<<endl<<"1- - promaseno bacanje"<<endl<<"OR - skok u napadu"<<endl<<"DR - skok u odbrani"<<endl<<"A - asistencija"<<endl<<"B - blokada(banana)"<<endl<<"S - ukradena lopta"<<endl<<"T - izgubljena lopta"<<endl<<"F - faul"<<endl<<"FD - iznudjen faul"<<endl;
			cout<<"Unosite desavanja na sledeci nacin - Prvo unesete ime igraca u jednom redu a zatim skracenicu sta je on uradio u drugom redu"<<endl<<"Kada je utakmica gotova unesite String END"<<endl;
			cout<<"Dodatne opcije:"<<endl<<"b - pogled na trenutnu statisktiku"<<endl<<"p - pogled na statistiku odredjenog igraca"<<endl<<"s - samo jedan statisticki parametar odredjenog igraca"<<endl;
			cout<<endl<<"Timovi na ovoj utakmici su:"<<endl;
			b.timovi();
			cout<<endl;
			b.rezultat();
			cout<<endl;
			string s1,s2;
			getline(cin,s1);
			//cout<<s1<<endl;
			getline(cin,s1);
			//cout<<s1<<endl;
			if(s1=="b"||s1=="B"){
				cout<<"Samo sekund";
				Sleep(1000);
				system("cls");
				b.boxscore();
				cout<<endl<<"Unesite bilo koji karakter ukoliko zelite da nastavite unos:";
				char djole;
				cin>>djole;
				if(djole){
					system("cls");
					goto pekijeglup;
				}
			}
			else if(s1=="p"||s1=="P"){
				cout<<"Samo sekund";
				Sleep(1000);
				system("cls");
				cout<<"Unesite ime trazenog igraca: ";
				string igrac;
				getline(cin,igrac);
				b.playerstats(igrac);
				cout<<endl<<"Unesite bilo koji karakter ukoliko zelite da nastavite unos:";
				char djole2;
				cin>>djole2;
				if(djole2){
					system("cls");
					goto pekijeglup;
				}
			}
			else if(s1=="s"||s1=="S"){
				cout<<"Samo sekund";
				Sleep(1000);
				system("cls");
				cout<<"Unesite ime trazenog igraca: ";
				string igrac;
				getline(cin,igrac);
				cout<<"Unesite skracenicu za podatak koji vas zanima (pts,ast,dreb,oreb,reb,stl,blk,to,foul,fould,2a,2m,%2,3a,3m,%3,fta,ftm,ft%,fg%): ";
				string skr;
				cin>>skr;
				int jbro=b.stat(igrac,skr);
				if(jbro==-1)cout<<"Nesto si pogresno uneo sta da se radi"<<endl;
				else cout<<igrac<<" - "<<skr<<": "<<jbro<<endl;
				cout<<endl<<"Unesite bilo koji karakter ukoliko zelite da nastavite unos:";
				char djole3;
				cin>>djole3;
				if(djole3){
					system("cls");
					goto pekijeglup;
				}
			}
			else if(s1=="END"||s1=="end"||s1=="End"){
				cout<<"Samo sekund";
				Sleep(1000);
				system("cls");
				cout<<"Utakmica je zavrsena"<<endl;
				b.rezultat();
				cout<<endl;
				player p1=b.MVP();
				int index=p1.pts+p1.ast+p1.dreb+p1.oreb+p1.blk+p1.stl+p1.fould-p1.foul-p1.to-(p1.threea-p1.threem)-(p1.twoa-p1.twom)-(p1.fta-p1.ftm);
				cout<<"MVP utakmice je "<<p1.name<<" sa indexom korisnosti (PIR) "<<index<<endl<<endl;
				b.boxscore();
				Sleep(1000);
				b.SaveGame();
				Sleep(1000);
				cout<<endl<<endl<<"B(b) - vrati se na pocetak, a bilo koji drugi karakter napusta program: ";
				char mitar;
				cin>>mitar;
				if(mitar=='B'||mitar=='b'){
					goto start;
				}
				else return 0;
			}
			cin>>s2;
			//cout<<s2<<endl;
			b.GamePlay(s1,s2);
			cout<<"Cek malo";
			Sleep(500);
			system("cls");
			goto pekijeglup;
		}
		else if(c=='u'){
			b.inic();
			cout<<"Utakmica je pocela"<<endl;
			Sleep(1000);
			system("cls");
			goto pekijeglup;
		}
		else{
			cout<<"Ne postoji komanda za karakter '"<<c<<"' molimo unesite nesto od ponudjenih opcija"<<endl;
			HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(color, 2);
			Sleep(1000);
			cout<<"Loading.";
			Sleep(400);
			cout<<".";
			Sleep(400);
			cout<<".";
			Sleep(1000);
			cout<<"Loading.";
			Sleep(400);
			cout<<".";
			Sleep(400);
			cout<<".";
			goto tekma;
		}
	}
	else if(ch=='b'){
		cout<<"Da li Vas zanimaju imena svih prethodnih tekmi koje imamo sacuvane? (DA/NE)"<<endl;
		string dane;
		cin>>dane;
		if(dane=="da"||dane=="DA"||dane=="Da")b.spisaktekmi();
		cout<<endl;
		cout<<"Unesite ime tekme koju trazite:"<<endl;
		string tekma;
		cin>>tekma;
		cout<<"Samo sekund"<<endl;
		Sleep(1000);
		system("cls");
		b.PrevGame(tekma);
	}
	else if(ch=='c');
	else {
		cout<<"Ne postoji komanda za karakter '"<<ch<<"' molimo unesite nesto od ponudjenih opcija"<<endl;
		HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(color, 11);
		Sleep(1000);
		cout<<"Loading.";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		Sleep(1000);
		cout<<"Loading.";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		goto start;
	}
}

