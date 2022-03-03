#include <iostream>
using namespace std;
struct player{
		string name;
		int number;
		int height;//u cm
		string position;
		int pts;//poeni
		int ast;//asistencije
		int dreb;//skok u odbrani
		int oreb;//skok u napadu
		int stl;//ukradene lopte
		int blk;//banane
		int to;//izgubljene lopte
		int foul;
		int fould;//iznudjeni faul
		int twoa;//sut za 2
		int twom;//pogodjen sut za 2
		int threea;//sut za 3
		int threem;//pogodjen sut za 3
		int fta;//sut za 1
		int ftm;//pogodjen sut za 1
	};
class BasketGame{
	string date;//datum yyyy/mm/dd
	int n1,n2;//broj igraca u timovima
	string tim1,tim2;//imena timova;
	player team1[16],team2[16];
	public:
		BasketGame(int n);
		void inic();//unos dva tima sa igracima
		void GamePlay(string ime, string play);//ime igraca i skarcenica za ono sto je uradio
		void boxscore();//ispis trenutne statistike
		void rezultat();//samo ispis trenutnog rezultata tekme
		void playerstats(string ime);//statistika odredjenog igraca
		player MVP();//najkorisniji igrac utakmice, ako je gotova tekma
		void SaveGame();//u fajl ispisujemo sve podatke vezane za tekmu, za svaku tekmu razlicit fajl, ime fajla=date-tim1-tim2
		void PrevGame(string s1);//s1 ime fjala trazene tekme(sva imena se nalaze u fajlu "ShtekImena.txt"; ova funkc pravi niz stringova(imena fajlova) i sortira ga i pretrazuje odredjenu tekmu koja nas zanima
		double stat(string ime, string s);//ime igraca i skarcenica za odrejedni statisticki parametar koji nas zanima
		void teamispis(string teamname);//ispis clanova ekipe;
		void timovi();
		void spisaktekmi();
		void SplashEffect();
};
