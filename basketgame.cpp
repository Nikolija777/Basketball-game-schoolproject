#include <iostream>
#include "basketgame.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <conio.h>
#include <windows.h>
#define N 30
using namespace std;
int binPret(string s[10000], int l, int r, string x){
		if(r>=l){
			int mid=l+(r-l)/2;
			if(s[mid]==x)return mid;
			if(s[mid]>x)return binPret(s,l,mid-1,x);
			return binPret(s,mid+1,r,x);
		}
		else return -1;
	}

void BasketGame::inic(){
	cout<<"Unesite datum odigravanja utakmice (yyyy/mm/dd): ";
	cin>>date; 
	cout<<endl;
	cout<<"Unesite naziv prvog tima: ";
	//cin>>tim1;
    getline(cin,tim1);
    getline(cin,tim1);
    cout<<endl;
 	cout<<"Broj igraca datog tima je(max 15): ";
    cin>>n1;
    cout<<"Unesite podatke o igracima datog tima:";
	cout<<endl;
	for(int i=1; i<=n1; i++){
		cout<<"Ime: ";
		//cin>>team1[i].name;
    	getline(cin,team1[i].name);
    	getline(cin,team1[i].name);
    	cout<<endl;
   		cout<<"Broj(0-99): ";
		cin>>team1[i].number;
    	cout<<endl;
   		cout<<"Visina:  ";
    	cin>>team1[i].height;
    	cout<<endl;
		cout<<"Pozicija(PG,SG,SF,PF,C,G,F): ";
    	cin>>team1[i].position;
    	cout<<endl;
   
	team1[i].pts=0;
 
    team1[i].ast=0;
 
    team1[i].dreb=0;
   
    team1[i].oreb=0;
   
    team1[i].stl=0;
   
    team1[i].blk=0;
   
    team1[i].to=0;
   
    team1[i].foul=0;
   
    team1[i].fould=0;
   
    team1[i].twoa=0;
 
    team1[i].twom=0;
   
    team1[i].threea=0;
   
    team1[i].threem=0;
 
    team1[i].fta=0;
   
    team1[i].ftm=0;
   }


	cout<<"Unesite naziv drugog tima: ";
	//cin>>tim2;
    getline(cin,tim2);
    getline(cin,tim2);
    cout<<endl;
	cout<<"Broj igraca datog tima je(max 15): ";
	cin>>n2;
	cout<<endl;
	cout<<"Unesite podatke o igracima datog tima:";
	cout<<endl;
    for(int i=1; i<=n2 ; i++){
 
		cout<<"Ime: ";
		//cin>>team2[i].name;
    	getline(cin,team2[i].name);
    	getline(cin,team2[i].name);
  		cout<<endl;
   	    cout<<"Broj(0-99): ";
    	cin>>team2[i].number;
    	cout<<endl;
    	cout<<"Visina:  ";
 	    cin>>team2[i].height;
    	cout<<endl;
   		cout<<"Pozicija(PG,SG,SF,PF,C,G,F): ";
    	cin>>team2[i].position;
    	cout<<endl;

    team2[i].pts=0;
   
    team2[i].ast=0;
 
    team2[i].dreb=0;
   
    team2[i].oreb=0;
   
    team2[i].stl=0;
   
    team2[i].blk=0;
   
    team2[i].to=0;
   
    team2[i].foul=0;
   
    team2[i].fould=0;
   
    team2[i].twoa=0;
 
    team2[i].twom=0;
   
    team2[i].threea=0;
   
    team2[i].threem=0;
 
    team2[i].fta=0;
   
    team2[i].ftm=0;
	}
}

BasketGame::BasketGame(int n){
	date="Cetvrtak";
	tim1="Team1";
    tim2="Team2";
   	n1=5;
    n2=5;
    team1[1].name="Player1";
	team1[2].name="Player2";
 	team1[3].name="Player3";
	team1[4].name="Player4";
	team1[5].name="Player5";
	team2[1].name="Player6";
	team2[2].name="Player7";
	team2[3].name="Player8";
	team2[4].name="Player9";
	team2[5].name="Player10";
 	for(int i=1; i<=n1; i++)
	{
     	team1[i].number=i;
		team2[i].number=5+i;
    	team1[i].height=195+i;
    	team2[i].height=200+i;
  	    team1[i].position="/";
    	team2[i].position="/";
    
	team1[i].pts=0;
 
    team1[i].ast=0;
 
    team1[i].dreb=0;
   
    team1[i].oreb=0;
   
    team1[i].stl=0;
   
    team1[i].blk=0;
   
    team1[i].to=0;
   
    team1[i].foul=0;
   
    team1[i].fould=0;
   
    team1[i].twoa=0;
 
    team1[i].twom=0;
   
    team1[i].threea=0;
   
    team1[i].threem=0;
 
    team1[i].fta=0;
   
    team1[i].ftm=0;
   
    team2[i].pts=0;
   
    team2[i].ast=0;
 
    team2[i].dreb=0;
   
    team2[i].oreb=0;
   
    team2[i].stl=0;
   
    team2[i].blk=0;
   
    team2[i].to=0;
   
    team2[i].foul=0;
   
    team2[i].fould=0;
   
    team2[i].twoa=0;
 
    team2[i].twom=0;
   
    team2[i].threea=0;
   
    team2[i].threem=0;
 
    team2[i].fta=0;
   
    team2[i].ftm=0;

    }
}

void BasketGame::GamePlay(string ime, string s){
    int id=-1;
    if(s!="3+"&&s!="3-"&&s!="2+"&&s!="2-"&&s!="1+"&&s!="1-"&&s!="dr"&&s!="DR"&&s!="or"&&s!="OR"&&s!="a"&&s!="A"&&s!="b"&&s!="B"&&s!="s"&&s!="S"&&s!="t"&&s!="T"&&s!="f"&&s!="F"&&s!="fd"&&s!="FD"){
    	cout<<"E ta skracenica ne postoji, tako da nista se nije desilo"<<endl;
    	Sleep(1500);
    	return;
	}
    for(int i=1; i<=n1; i++) if(team1[i].name==ime) {
        id=i;
        if(s=="3+") {
            team1[i].pts+=3;
            team1[i].threea+=1;
            team1[i].threem+=1;
            break;
        }
        if(s=="3-"){
            team1[i].threea+=1;
            break;
        }
        if(s=="2+"){
            team1[i].pts+=2;
            team1[i].twoa+=1;
            team1[i].twom+=1;
            break;
        }
        if(s=="2-"){
            team1[i].twoa+=1;
            break;
        }
        if(s=="1+"){
            team1[i].pts+=1;
            team1[i].fta+=1;
            team1[i].ftm+=1;
            break;
        }
        if(s=="1-"){
            team1[i].fta+=1;
            break;
        }
        if(s=="OR" || s=="or"){
            team1[i].oreb+=1;
            break;
        }
        if(s=="DR" || s=="dr"){
            team1[i].dreb+=1;
            break;
        }
        if(s=="A" || s=="a"){
            team1[i].ast+=1;
            //cout<<"Ko je dao kos?";
            break;
        }
        if(s=="B" || s=="b"){
            team1[i].blk+=1;
            break;
        }
        if(s=="S" || s=="s"){
            team1[i].stl+=1;
            //cout<<"Ko je onda izgubio loptu?";
            break;
        }
        if(s=="T" || s=="t"){
            team1[i].to+=1;
            break;
        }
        if(s=="F" || s=="f"){
            team1[i].foul+=1;
            //cout<<"Koga je sad faulirao?"
            break;
        }
        if(s=="FD" || s=="fd"){
            team1[i].fould+=1;
            //cout<<"Ko ga je faulirao?"
            break;
        }
    }
        if(id!=-1)return;
        for(int i=1; i<=n2; i++) if(team2[i].name==ime) {
            id=i;
            if(s=="3+") {
                team2[i].pts+=3;
                team2[i].threea+=1;
                team2[i].threem+=1;
                break;
            }
            if(s=="3-"){
                team2[i].threea+=1;
                break;
            }
            if(s=="2+"){
                team2[i].pts+=2;
                team2[i].twoa+=1;
                team2[i].twom+=1;
                break;
            }
            if(s=="2-"){
                team2[i].twoa+=1;
                break;
            }
            if(s=="1+"){
                team2[i].pts+=1;
                team2[i].fta+=1;
                team2[i].ftm+=1;
                break;
            }
            if(s=="1-"){
                team2[i].fta+=1;
                break;
            }
            if(s=="OR" || s=="or"){
                team2[i].oreb+=1;
                break;
            }
            if(s=="DR" || s=="dr"){
                team2[i].dreb+=1;
                break;
            }
            if(s=="A" || s=="a"){
                team2[i].ast+=1;
                //cout<<"Ko je dao kos?";
                break;
            }
            if(s=="B" || s=="b"){
                team2[i].blk+=1;
                break;
            }
            if(s=="S" || s=="s"){
                team2[i].stl+=1;
                //cout<<"Ko je onda izgubio loptu?";
                break;
            }
            if(s=="T" || s=="t"){
                team2[i].to+=1;
                break;
            }
            if(s=="F" || s=="f"){
                team2[i].foul+=1;
               // cout<<"Koga je sad faulirao?"
                break;
            }
            if(s=="FD" || s=="fd"){
                team2[i].fould+=1;
               // cout<<"Ko ga je faulirao?"
                break;
            }
        }
    if(id==-1) {
    	cout<<"Daj ime koje postoji"<<endl;
    	Sleep(1000);
	}
}

void BasketGame::boxscore(){
	cout<<tim1<<endl;
        cout<<"ime"<<"                 ";
        cout<<"poz ";
        cout<<"broj  ";
        cout<<"pts   ";
        cout<<"ast   ";
        cout<<"dreb  ";
        cout<<"oreb  ";
        cout<<"stl   ";
        cout<<"blk   ";
        cout<<"to   ";
        cout<<"foul  ";
        cout<<"fould   ";
        cout<<"2a    ";
        cout<<"2m    ";
        cout<<"%2    ";
        cout<<"3a    ";
        cout<<"3m    ";
        cout<<"%3    ";
        cout<<"fta   ";
        cout<<"ftm   ";
        cout<<"ft%   ";
        cout<<"fg%   ";
        cout<<endl;
        
        for(int i=1; i<=n1; i++){
            int broj=team1[i].number;
            int brBroj=1;
            
            int poeni=team1[i].pts;
            int brPoeni=1;
            
            int asistencije=team1[i].ast;
            int brAsistencije=1;
            
            int skokOdbrana=team1[i].dreb;
            int brSkokOdbrana=1;
            
            int skokNapad=team1[i].oreb;
            int brSkokNapad=1;
            
            int ukradena=team1[i].stl;
            int brUkradena=1;
            
            int banana=team1[i].blk;
            int brBanana=1;
            
            int izgubljena=team1[i].to;
            int brIzgubljena=1;
            
            int faul=team1[i].foul;
            int brFaul=1;
            
            int fauld=team1[i].fould;
            int brFauld=1;
            
            int sut2=team1[i].twoa;
            int brSut2=1;
            
            int pogodjensut2=team1[i].twom;
            int brPogodjenSut2=1;
            
            int procenat2;
            if(team1[i].twoa==0)procenat2=0;
            else procenat2=100*team1[i].twom/team1[i].twoa;
            int brProcenat2=1;
            
            int sut3=team1[i].threea;
            int brSut3=1;
            
            int pogodjensut3=team1[i].threem;
            int brPogodjenSut3=1;
            
            int procenat3;
            if(team1[i].threea==0)procenat3=0;
            else procenat3=100*team1[i].threem/team1[i].threea;
            int brProcenat3=1;
            
            int sut1=team1[i].fta;
            int brSut1=1;
            
            int pogodjensut1=team1[i].ftm;
            int brPogodjenSut1=1;
            
            int procenat1;
            if(team1[i].fta==0)procenat1=0;
            else procenat1=100*team1[i].ftm/team1[i].fta;
            int brProcenat1=1;
            
            int procenatP;
            if(team1[i].twoa+team1[i].threea==0)procenatP=0;
            else procenatP=100*(team1[i].twom + team1[i].threem)/(team1[i].twoa + team1[i].threea);
            int brProcenatP=1;
            //
            
            int x=0;
            x=team1[i].name.length();
            cout<<team1[i].name;
            for(int j=0; j<21-x; j++) cout<<" ";
            
            //
            int y=0;
            y=team1[i].position.length();
            cout<<team1[i].position;
            for(int j=0; j<3-y; j++) cout<<" ";
            
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            cout<<" "<<team1[i].number;
            for(int m=0; m<5-brBroj; m++) cout<<" ";
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            cout<<" "<<team1[i].pts;
            for(int m=0; m<5-brPoeni; m++) cout<<" ";
            
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            cout<<" "<<team1[i].ast;
            for(int m=0; m<5-brAsistencije; m++) cout<<" ";
            
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            cout<<" "<<team1[i].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) cout<<" ";
            
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            cout<<" "<<team1[i].oreb;
            for(int m=0; m<5-brSkokNapad; m++) cout<<" ";
            
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            cout<<" "<<team1[i].stl;
            for(int m=0; m<5-brUkradena; m++) cout<<" ";
            
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            cout<<" "<<team1[i].blk;
            for(int m=0; m<4-brBanana; m++) cout<<" ";
            
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            cout<<" "<<team1[i].to;
            for(int m=0; m<6-brIzgubljena; m++) cout<<" ";
            
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            cout<<" "<<team1[i].foul;
            for(int m=0; m<5-brFaul; m++) cout<<" ";
            
            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            cout<<" "<<team1[i].fould;
            for(int m=0; m<5-brFauld; m++) cout<<" ";
            
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            cout<<" "<<team1[i].twoa;
            for(int m=0; m<5-brSut2; m++) cout<<" ";
            
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            cout<<" "<<team1[i].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) cout<<" ";
            
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team1[i].twoa!=0)cout<<" "<<100*team1[i].twom/team1[i].twoa;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat2; m++) cout<<" ";
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            cout<<" "<<team1[i].threea;
            for(int m=0; m<5-brSut3; m++) cout<<" ";
            
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            cout<<" "<<team1[i].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) cout<<" ";
            
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team1[i].threea!=0)cout<<" "<<100*team1[i].threem/team1[i].threea;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat3; m++) cout<<" ";
            
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            cout<<" "<<team1[i].fta;
            for(int m=0; m<5-brSut1; m++) cout<<" ";
            
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            cout<<" "<<team1[i].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) cout<<" ";
            
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team1[i].fta!=0)cout<<" "<<100*team1[i].ftm/team1[i].fta;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat1; m++) cout<<" ";
            
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team1[i].twoa + team1[i].threea)!=0)cout<<" "<<100*(team1[i].twom + team1[i].threem)/(team1[i].twoa + team1[i].threea);
            else cout<<" 0";
            for(int m=0; m<5-brProcenatP; m++) cout<<" ";
            
            cout<<endl;
        }
        
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		int upoeni=0;
        int uasistencije=0;
        int uskokOdbrana=0;
        int uskokNapad=0;
        int uukradena=0;
        int ubanana=0;
        int uizgubljena=0;
        int ufaul=0;
        int ufauld=0;
        int usut2=0;
        int upogodjensut2=0;
        int usut3=0;
        int upogodjensut3=0;
        int usut1=0;
        int upogodjensut1=0;
        
        for(int i=1; i<=n1; i++){
        upoeni+=team1[i].pts;
        uasistencije+=team1[i].ast;
        uskokOdbrana+=team1[i].dreb;
        uskokNapad+=team1[i].oreb;
        uukradena+=team1[i].stl;
        ubanana+=team1[i].blk;
        uizgubljena+=team1[i].to;
        ufaul+=team1[i].foul;
        ufauld+=team1[i].fould;
        usut2+=team1[i].twoa;
        upogodjensut2+=team1[i].twom;
        usut3+=team1[i].threea;
        upogodjensut3+=team1[i].threem;
        usut1+=team1[i].fta;
        upogodjensut1+=team1[i].ftm;
    }
    	int uprocenat2;
		if(usut2!=0)uprocenat2=100*upogodjensut2/usut2;
    	else uprocenat2=0;
    	int uprocenat3;
    	if(usut3!=0)uprocenat3=100*upogodjensut3/usut3;
    	else uprocenat3=0;
    	int uprocenat1;
    	if(usut1!=0)uprocenat1=100*upogodjensut1/usut1;
    	else uprocenat1=0;
    	int uprocenatP;
    	if((usut2+usut3)!=0)uprocenatP=100*(upogodjensut2+upogodjensut3)/(usut2+usut3);
    	else uprocenatP=0;
    	int uupoeni=upoeni;
        int uuasistencije=uasistencije;
        int uuskokOdbrana=uskokOdbrana;
        int uuskokNapad=uskokNapad;
        int uuukradena=uukradena;
        int uubanana=ubanana;
        int uuizgubljena=uizgubljena;
        int uufaul=ufaul;
        int uufauld=ufauld;
        int uusut2=usut2;
        int uupogodjensut2=upogodjensut2;
        int uusut3=usut3;
        int uupogodjensut3=upogodjensut3;
        int uusut1=usut1;
        int uupogodjensut1=upogodjensut1;
    	int uuprocenat2=uprocenat2;
    	int uuprocenat3=uprocenat3;
    	int uuprocenat1=uprocenat1;
    	int uuprocenatP=uprocenatP;
    	
    int bruPoeni=1;
    int bruAsistencije=1;
    int bruSkokOdbrana=1;
    int bruSkokNapad=1;
    int bruUkradena=1;
    int bruBanana=1;
    int bruFaul=1;
    int bruFauld=1;
    int bruIzgubljena=1;
    int bruSut2=1;
    int bruPogodjenSut2=1;
    int bruSut3=1;
    int bruPogodjenSut3=1;
    int bruSut1=1;
    int bruPogodjenSut1=1;
    int bruProcenat2=1;
    int bruProcenat3=1;
    int bruProcenat1=1;
    int bruProcenatP=1;
    
    
    cout<<"Ukupno:";
    for(int j=0; j<21-7; j++) cout<<" ";
    
    //
    cout<<"/";
    for(int j=0; j<3-1; j++) cout<<" ";
    
    //
    cout<<" /";
    for(int m=0; m<5-1; m++) cout<<" ";
    
    //
    while(upoeni>9){
        upoeni=upoeni/10;
        bruPoeni++;
    }
    cout<<" "<<uupoeni;
    for(int m=0; m<5-bruPoeni; m++) cout<<" ";
    
    //
    while(uasistencije>9){
        uasistencije=uasistencije/10;
        bruAsistencije++;
    }
    cout<<" "<<uuasistencije;
    for(int m=0; m<5-bruAsistencije; m++) cout<<" ";
    
    //
    while(uskokOdbrana>9){
        uskokOdbrana=uskokOdbrana/10;
        bruSkokOdbrana++;
    }
    cout<<" "<<uuskokOdbrana;
    for(int m=0; m<5-bruSkokOdbrana; m++) cout<<" ";
    
    //
    while(uskokNapad>9){
        uskokNapad=uskokNapad/10;
        bruSkokNapad++;
    }
    cout<<" "<<uuskokNapad;
    for(int m=0; m<5-bruSkokNapad; m++) cout<<" ";
    
    //
    while(uukradena>9){
        uukradena=uukradena/10;
        bruUkradena++;
    }
    cout<<" "<<uuukradena;
    for(int m=0; m<5-bruUkradena; m++) cout<<" ";
    
    //
    while(ubanana>9){
        ubanana=ubanana/10;
        bruBanana++;
    }
    cout<<" "<<uubanana;
    for(int m=0; m<4-bruBanana; m++) cout<<" ";
    
    //
    while(uizgubljena>9){
        uizgubljena=uizgubljena/10;
        bruIzgubljena++;
    }
    cout<<" "<<uuizgubljena;
    for(int m=0; m<6-bruIzgubljena; m++) cout<<" ";
    
    //
    while(ufaul>9){
        ufaul=ufaul/10;
        bruFaul++;
    }
    cout<<" "<<uufaul;
    for(int m=0; m<5-bruFaul; m++) cout<<" ";
    
    //
    while(ufauld>9){
        ufauld=ufauld/10;
        bruFauld++;
    }
    cout<<" "<<uufauld;
    for(int m=0; m<5-bruFauld; m++) cout<<" ";
    
    //
    while(usut2>9){
        usut2=usut2/10;
        bruSut2++;
    }
    cout<<" "<<uusut2;
    for(int m=0; m<5-bruSut2; m++) cout<<" ";
    
    //
    while(upogodjensut2>9){
        upogodjensut2=upogodjensut2/10;
        bruPogodjenSut2++;
    }
    cout<<" "<<uupogodjensut2;
    for(int m=0; m<5-bruPogodjenSut2; m++) cout<<" ";
    
    //
    while(uprocenat2>9){
        uprocenat2=uprocenat2/10;
        bruProcenat2++;
    }
    cout<<" "<<uuprocenat2;
    for(int m=0; m<5-bruProcenat2; m++) cout<<" ";
    //
    while(usut3>9){
        usut3=usut3/10;
        bruSut3++;
    }
    cout<<" "<<uusut3;
    for(int m=0; m<5-bruSut3; m++) cout<<" ";
    
    //
    while(upogodjensut3>9){
        upogodjensut3=upogodjensut3/10;
        bruPogodjenSut3++;
    }
    cout<<" "<<uupogodjensut3;
    for(int m=0; m<5-bruPogodjenSut3; m++) cout<<" ";
    
    //
    while(uprocenat3>9){
        uprocenat3=uprocenat3/10;
        bruProcenat3++;
    }
	cout<<" "<<uuprocenat3;
    for(int m=0; m<5-bruProcenat3; m++) cout<<" ";
    
    //
    while(usut1>9){
        usut1=usut1/10;
        bruSut1++;
    }
    cout<<" "<<uusut1;
    for(int m=0; m<5-bruSut1; m++) cout<<" ";
    
    //
    while(upogodjensut1>9){
        upogodjensut1=upogodjensut1/10;
        bruPogodjenSut1++;
    }
    cout<<" "<<uupogodjensut1;
    for(int m=0; m<5-bruPogodjenSut1; m++) cout<<" ";
    
    //
    while(uprocenat1>9){
        uprocenat1=uprocenat1/10;
        bruProcenat1++;
    }
	cout<<" "<<uuprocenat1;
    for(int m=0; m<5-bruProcenat1; m++) cout<<" ";
    
    //
    while(uprocenatP>9){
        uprocenatP=uprocenatP/10;
        bruProcenatP++;
    }
    cout<<" "<<uuprocenatP;
    for(int m=0; m<5-bruProcenatP; m++) cout<<" ";
    
    cout<<endl;
        
    	cout<<endl;
    	cout<<tim2<<endl;
        cout<<"ime"<<"                 ";
        cout<<"poz ";
        cout<<"broj  ";
        cout<<"pts   ";
        cout<<"ast   ";
        cout<<"dreb  ";
        cout<<"oreb  ";
        cout<<"stl   ";
        cout<<"blk   ";
        cout<<"to   ";
        cout<<"foul  ";
        cout<<"fould   ";
        cout<<"2a    ";
        cout<<"2m    ";
        cout<<"%2    ";
        cout<<"3a    ";
        cout<<"3m    ";
        cout<<"%3    ";
        cout<<"fta   ";
        cout<<"ftm   ";
        cout<<"ft%   ";
        cout<<"fg%   ";
        cout<<endl;
        for(int i=1; i<=n2; i++){
            
            int broj=team2[i].number;
            int brBroj=1;
            
            int poeni=team2[i].pts;
            int brPoeni=1;
            
            int asistencije=team2[i].ast;
            int brAsistencije=1;
            
            int skokOdbrana=team2[i].dreb;
            int brSkokOdbrana=1;
            
            int skokNapad=team2[i].oreb;
            int brSkokNapad=1;
            
            int ukradena=team2[i].stl;
            int brUkradena=1;
            
            int banana=team2[i].blk;
            int brBanana=1;
            
            int izgubljena=team2[i].to;
            int brIzgubljena=1;
            
            int faul=team2[i].foul;
            int brFaul=1;
            
            int fauld=team2[i].fould;
            int brFauld=1;
            
            int sut2=team2[i].twoa;
            int brSut2=1;
            
            int pogodjensut2=team2[i].twom;
            int brPogodjenSut2=1;
            
            int procenat2;
            if(team2[i].twoa==0)procenat2=0;
            else procenat2=100*team2[i].twom/team2[i].twoa;
            int brProcenat2=1;
            
            int sut3=team2[i].threea;
            int brSut3=1;
            
            int pogodjensut3=team2[i].threem;
            int brPogodjenSut3=1;
            
            int procenat3;
            if(team2[i].threea==0)procenat3=0;
            else procenat3=100*team2[i].threem/team2[i].threea;
            int brProcenat3=1;
            
            int sut1=team2[i].fta;
            int brSut1=1;
            
            int pogodjensut1=team2[i].ftm;
            int brPogodjenSut1=1;
            
            int procenat1;
            if(team2[i].fta==0)procenat1=0;
            else procenat1=100*team2[i].ftm/team2[i].fta;
            int brProcenat1=1;
            
            int procenatP;
            if((team2[i].twoa + team2[i].threea)==0)procenatP=0;
            else procenatP=100*(team2[i].twom + team2[i].threem)/(team2[i].twoa + team2[i].threea);
            int brProcenatP=1;
            //
            int x=0;
            x=team2[i].name.length();
            cout<<team2[i].name;
            for(int j=0; j<21-x; j++) cout<<" ";
            
            //
            int y=0;
            y=team2[i].position.length();
            cout<<team2[i].position;
            for(int j=0; j<3-y; j++) cout<<" ";
            
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            cout<<" "<<team2[i].number;
            for(int m=0; m<5-brBroj; m++) cout<<" ";
            
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            cout<<" "<<team2[i].pts;
            for(int m=0; m<5-brPoeni; m++) cout<<" ";
            
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            cout<<" "<<team2[i].ast;
            for(int m=0; m<5-brAsistencije; m++) cout<<" ";
            
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            cout<<" "<<team2[i].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) cout<<" ";
            
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            cout<<" "<<team2[i].oreb;
            for(int m=0; m<5-brSkokNapad; m++) cout<<" ";
            
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            cout<<" "<<team2[i].stl;
            for(int m=0; m<5-brUkradena; m++) cout<<" ";
            
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            cout<<" "<<team2[i].blk;
            for(int m=0; m<4-brBanana; m++) cout<<" ";
            
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            cout<<" "<<team2[i].to;
            for(int m=0; m<6-brIzgubljena; m++) cout<<" ";
            
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            cout<<" "<<team2[i].foul;
            for(int m=0; m<5-brFaul; m++) cout<<" ";

            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            cout<<" "<<team2[i].fould;
            for(int m=0; m<5-brFauld; m++) cout<<" ";
            
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            cout<<" "<<team2[i].twoa;
            for(int m=0; m<5-brSut2; m++) cout<<" ";
            
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            cout<<" "<<team2[i].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) cout<<" ";
            
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team2[i].twoa!=0)cout<<" "<<100*team2[i].twom/team2[i].twoa;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat2; m++) cout<<" ";
            
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            cout<<" "<<team2[i].threea;
            for(int m=0; m<5-brSut3; m++) cout<<" ";
            
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            cout<<" "<<team2[i].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) cout<<" ";
            
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team2[i].threea!=0)cout<<" "<<100*team2[i].threem/team2[i].threea;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat3; m++) cout<<" ";
            
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            cout<<" "<<team2[i].fta;
            for(int m=0; m<5-brSut1; m++) cout<<" ";
            
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            cout<<" "<<team2[i].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) cout<<" ";
            
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team2[i].fta!=0)cout<<" "<<100*team2[i].ftm/team2[i].fta;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat1; m++) cout<<" ";
            
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team2[i].twoa + team2[i].threea)!=0)cout<<" "<<100*(team2[i].twom + team2[i].threem)/(team2[i].twoa + team2[i].threea);
            else cout<<" 0";
            for(int m=0; m<5-brProcenatP; m++) cout<<" ";
            
            cout<<endl;
        }
        
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		int upoeni2=0;
        int uasistencije2=0;
        int uskokOdbrana2=0;
        int uskokNapad2=0;
        int uukradena2=0;
        int ubanana2=0;
        int uizgubljena2=0;
        int ufaul2=0;
        int ufauld2=0;
        int usut22=0;
        int upogodjensut22=0;
        int usut32=0;
        int upogodjensut32=0;
        int usut12=0;
        int upogodjensut12=0;
        
        for(int i=1; i<=n2; i++){
        upoeni2+=team2[i].pts;
        uasistencije2+=team2[i].ast;
        uskokOdbrana2+=team2[i].dreb;
        uskokNapad2+=team2[i].oreb;
        uukradena2+=team2[i].stl;
        ubanana2+=team2[i].blk;
        uizgubljena2+=team2[i].to;
        ufaul2+=team2[i].foul;
        ufauld2+=team2[i].fould;
        usut22+=team2[i].twoa;
        upogodjensut22+=team2[i].twom;
        usut32+=team2[i].threea;
        upogodjensut32+=team2[i].threem;
        usut12+=team2[i].fta;
        upogodjensut12+=team2[i].ftm;
    }
    	int uprocenat22;
		if(usut2!=0)uprocenat2=100*upogodjensut22/usut22;
    	else uprocenat22=0;
    	int uprocenat32;
    	if(usut32!=0)uprocenat32=100*upogodjensut32/usut32;
    	else uprocenat32=0;
    	int uprocenat12;
    	if(usut12!=0)uprocenat12=100*upogodjensut12/usut12;
    	else uprocenat12=0;
    	int uprocenatP2;
    	if((usut22+usut32)!=0)uprocenatP2=100*(upogodjensut22+upogodjensut32)/(usut22+usut32);
    	else uprocenatP2=0;
    	int uupoeni2=upoeni2;
        int uuasistencije2=uasistencije2;
        int uuskokOdbrana2=uskokOdbrana2;
        int uuskokNapad2=uskokNapad2;
        int uuukradena2=uukradena2;
        int uubanana2=ubanana2;
        int uuizgubljena2=uizgubljena2;
        int uufaul2=ufaul2;
        int uufauld2=ufauld2;
        int uusut22=usut22;
        int uupogodjensut22=upogodjensut22;
        int uusut32=usut32;
        int uupogodjensut32=upogodjensut32;
        int uusut12=usut12;
        int uupogodjensut12=upogodjensut12;
    	int uuprocenat22=uprocenat22;
    	int uuprocenat32=uprocenat32;
    	int uuprocenat12=uprocenat12;
    	int uuprocenatP2=uprocenatP2;
    	
    int bruPoeni2=1;
    int bruAsistencije2=1;
    int bruSkokOdbrana2=1;
    int bruSkokNapad2=1;
    int bruUkradena2=1;
    int bruBanana2=1;
    int bruFaul2=1;
    int bruFauld2=1;
    int bruIzgubljena2=1;
    int bruSut22=1;
    int bruPogodjenSut22=1;
    int bruSut32=1;
    int bruPogodjenSut32=1;
    int bruSut12=1;
    int bruPogodjenSut12=1;
    int bruProcenat22=1;
    int bruProcenat32=1;
    int bruProcenat12=1;
    int bruProcenatP2=1;
    
    
    cout<<"Ukupno:";
    for(int j=0; j<21-7; j++) cout<<" ";
    
    //
    cout<<"/";
    for(int j=0; j<3-1; j++) cout<<" ";
    
    //
    cout<<" /";
    for(int m=0; m<5-1; m++) cout<<" ";
    
    //
    while(upoeni2>9){
        upoeni2=upoeni2/10;
        bruPoeni2++;
    }
    cout<<" "<<uupoeni2;
    for(int m=0; m<5-bruPoeni2; m++) cout<<" ";
    
    //
    while(uasistencije2>9){
        uasistencije2=uasistencije2/10;
        bruAsistencije2++;
    }
    cout<<" "<<uuasistencije2;
    for(int m=0; m<5-bruAsistencije2; m++) cout<<" ";
    
    //
    while(uskokOdbrana2>9){
        uskokOdbrana2=uskokOdbrana2/10;
        bruSkokOdbrana2++;
    }
    cout<<" "<<uuskokOdbrana2;
    for(int m=0; m<5-bruSkokOdbrana2; m++) cout<<" ";
    
    //
    while(uskokNapad2>9){
        uskokNapad2=uskokNapad2/10;
        bruSkokNapad2++;
    }
    cout<<" "<<uuskokNapad2;
    for(int m=0; m<5-bruSkokNapad2; m++) cout<<" ";
    
    //
    while(uukradena2>9){
        uukradena2=uukradena2/10;
        bruUkradena2++;
    }
    cout<<" "<<uuukradena2;
    for(int m=0; m<5-bruUkradena2; m++) cout<<" ";
    
    //
    while(ubanana2>9){
        ubanana2=ubanana2/10;
        bruBanana2++;
    }
    cout<<" "<<uubanana2;
    for(int m=0; m<4-bruBanana2; m++) cout<<" ";
    
    //
    while(uizgubljena2>9){
        uizgubljena2=uizgubljena2/10;
        bruIzgubljena2++;
    }
    cout<<" "<<uuizgubljena2;
    for(int m=0; m<6-bruIzgubljena2; m++) cout<<" ";
    
    //
    while(ufaul2>9){
        ufaul2=ufaul2/10;
        bruFaul2++;
    }
    cout<<" "<<uufaul2;
    for(int m=0; m<5-bruFaul2; m++) cout<<" ";
    
    //
    while(ufauld2>9){
        ufauld2=ufauld2/10;
        bruFauld2++;
    }
    cout<<" "<<uufauld2;
    for(int m=0; m<5-bruFauld2; m++) cout<<" ";
    
    //
    while(usut22>9){
        usut22=usut22/10;
        bruSut22++;
    }
    cout<<" "<<uusut22;
    for(int m=0; m<5-bruSut22; m++) cout<<" ";
    
    //
    while(upogodjensut22>9){
        upogodjensut22=upogodjensut22/10;
        bruPogodjenSut22++;
    }
    cout<<" "<<uupogodjensut22;
    for(int m=0; m<5-bruPogodjenSut22; m++) cout<<" ";
    
    //
    while(uprocenat22>9){
        uprocenat22=uprocenat22/10;
        bruProcenat22++;
    }
    cout<<" "<<uuprocenat22;
    for(int m=0; m<5-bruProcenat22; m++) cout<<" ";
    //
    while(usut32>9){
        usut32=usut32/10;
        bruSut32++;
    }
    cout<<" "<<uusut32;
    for(int m=0; m<5-bruSut32; m++) cout<<" ";
    
    //
    while(upogodjensut32>9){
        upogodjensut32=upogodjensut32/10;
        bruPogodjenSut32++;
    }
    cout<<" "<<uupogodjensut32;
    for(int m=0; m<5-bruPogodjenSut32; m++) cout<<" ";
    
    //
    while(uprocenat32>9){
        uprocenat32=uprocenat32/10;
        bruProcenat32++;
    }
	cout<<" "<<uuprocenat32;
    for(int m=0; m<5-bruProcenat32; m++) cout<<" ";
    
    //
    while(usut12>9){
        usut12=usut12/10;
        bruSut12++;
    }
    cout<<" "<<uusut12;
    for(int m=0; m<5-bruSut12; m++) cout<<" ";
    
    //
    while(upogodjensut12>9){
        upogodjensut12=upogodjensut12/10;
        bruPogodjenSut12++;
    }
    cout<<" "<<uupogodjensut12;
    for(int m=0; m<5-bruPogodjenSut12; m++) cout<<" ";
    
    //
    while(uprocenat12>9){
        uprocenat12=uprocenat12/10;
        bruProcenat12++;
    }
	cout<<" "<<uuprocenat12;
    for(int m=0; m<5-bruProcenat12; m++) cout<<" ";
    
    //
    while(uprocenatP2>9){
        uprocenatP2=uprocenatP2/10;
        bruProcenatP2++;
    }
    cout<<" "<<uuprocenatP2;
    for(int m=0; m<5-bruProcenatP2; m++) cout<<" ";
    
    cout<<endl;
}

void BasketGame::SaveGame(){
	ofstream foo;
	foo.open("ShtekImena.txt", ios::app);
	cout<<"Unesi ime po kojem ce se cuvati ova tekma (savetujemo oblika yyyy/mm/dd-tim1-tim2, ali ne mora (ali mora jedna rec da bude)):"<<endl;
	string s1;
	cin>>s1;
	foo<<s1<<endl;
	foo.close();
	s1+=".txt";
	ofstream fo;
	fo.open(s1.c_str(),ios::app);
	
	fo<<"Utakmica odigrana izmedju "<<tim1<<" i "<<tim2<<" datuma "<<date<<endl<<endl;
	fo<<tim1<<endl;
		fo<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n1 ; i++){
			fo<<team1[i].name;
			int l=(team1[i].name).size();
			l=N-l;
			while(l>0){
				fo<<" ";
				l--;
			}
			fo<<team1[i].number<<"   ";
			if(team1[i].number<10)fo<<" ";
			fo<<team1[i].position<<"    ";
			if((team1[i].position).size()==1)fo<<" ";
			fo<<team1[i].height<<"cm"<<endl;
		}
	fo<<endl<<tim2<<endl;
		fo<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n2 ; i++){
			fo<<team2[i].name;
			int l=(team2[i].name).size();
			l=N-l;
			while(l>0){
				fo<<" ";
				l--;
			}
			fo<<team2[i].number<<"   ";
			if(team2[i].number<10)fo<<" ";
			fo<<team2[i].position<<"    ";
			if((team2[i].position).size()==1)fo<<" ";
			fo<<team2[i].height<<"cm"<<endl;
		}
		fo<<endl;
		
		int r1=0, r2=0;
	for(int i=1;i<=n1;i++)
	{
		r1+=team1[i].pts;	
	}
	for(int i=1;i<=n2;i++)
	{
		r2+=team2[i].pts;	
	}
	fo<<"Rezultat je:"<<endl;
	
	fo<<tim1<<"  "<<r1<<":"<<r2<<"  "<<tim2<<endl<<endl;
	
	fo<<tim1<<endl;
        fo<<"ime"<<"                 ";
        fo<<"poz ";
        fo<<"broj  ";
        fo<<"pts   ";
        fo<<"ast   ";
        fo<<"dreb  ";
        fo<<"oreb  ";
        fo<<"stl   ";
        fo<<"blk   ";
        fo<<"to   ";
        fo<<"foul  ";
        fo<<"fould   ";
        fo<<"2a    ";
        fo<<"2m    ";
        fo<<"%2    ";
        fo<<"3a    ";
        fo<<"3m    ";
        fo<<"%3    ";
        fo<<"fta   ";
        fo<<"ftm   ";
        fo<<"ft%   ";
        fo<<"fg%   ";
        fo<<endl;
       
        for(int i=1; i<=n1; i++){
            int broj=team1[i].number;
            int brBroj=1;
           
            int poeni=team1[i].pts;
            int brPoeni=1;
           
            int asistencije=team1[i].ast;
            int brAsistencije=1;
           
            int skokOdbrana=team1[i].dreb;
            int brSkokOdbrana=1;
           
            int skokNapad=team1[i].oreb;
            int brSkokNapad=1;
           
            int ukradena=team1[i].stl;
            int brUkradena=1;
           
            int banana=team1[i].blk;
            int brBanana=1;
           
            int izgubljena=team1[i].to;
            int brIzgubljena=1;
           
            int faul=team1[i].foul;
            int brFaul=1;
           
            int fauld=team1[i].fould;
            int brFauld=1;
           
            int sut2=team1[i].twoa;
            int brSut2=1;
           
            int pogodjensut2=team1[i].twom;
            int brPogodjenSut2=1;
           
            int procenat2;
            if(team1[i].twoa==0)procenat2=0;
            else procenat2=100*team1[i].twom/team1[i].twoa;
            int brProcenat2=1;
           
            int sut3=team1[i].threea;
            int brSut3=1;
           
            int pogodjensut3=team1[i].threem;
            int brPogodjenSut3=1;
           
            int procenat3;
            if(team1[i].threea==0)procenat3=0;
            else procenat3=100*team1[i].threem/team1[i].threea;
            int brProcenat3=1;
           
            int sut1=team1[i].fta;
            int brSut1=1;
           
            int pogodjensut1=team1[i].ftm;
            int brPogodjenSut1=1;
           
            int procenat1;
            if(team1[i].fta==0)procenat1=0;
            else procenat1=100*team1[i].ftm/team1[i].fta;
            int brProcenat1=1;
           
            int procenatP;
            if(team1[i].twoa+team1[i].threea==0)procenatP=0;
            else procenatP=100*(team1[i].twom + team1[i].threem)/(team1[i].twoa + team1[i].threea);
            int brProcenatP=1;
            //
           
            int x=0;
            x=team1[i].name.length();
            fo<<team1[i].name;
            for(int j=0; j<21-x; j++) fo<<" ";
           
            //
            int y=0;
            y=team1[i].position.length();
            fo<<team1[i].position;
            for(int j=0; j<3-y; j++) fo<<" ";
           
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            fo<<" "<<team1[i].number;
            for(int m=0; m<5-brBroj; m++) fo<<" ";
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            fo<<" "<<team1[i].pts;
            for(int m=0; m<5-brPoeni; m++) fo<<" ";
           
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            fo<<" "<<team1[i].ast;
            for(int m=0; m<5-brAsistencije; m++) fo<<" ";
           
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            fo<<" "<<team1[i].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) fo<<" ";
           
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            fo<<" "<<team1[i].oreb;
            for(int m=0; m<5-brSkokNapad; m++) fo<<" ";
           
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            fo<<" "<<team1[i].stl;
            for(int m=0; m<5-brUkradena; m++) fo<<" ";
           
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            fo<<" "<<team1[i].blk;
            for(int m=0; m<4-brBanana; m++) fo<<" ";
           
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            fo<<" "<<team1[i].to;
            for(int m=0; m<6-brIzgubljena; m++) fo<<" ";
           
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            fo<<" "<<team1[i].foul;
            for(int m=0; m<5-brFaul; m++) fo<<" ";
           
            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            fo<<" "<<team1[i].fould;
            for(int m=0; m<5-brFauld; m++) fo<<" ";
           
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            fo<<" "<<team1[i].twoa;
            for(int m=0; m<5-brSut2; m++) fo<<" ";
           
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            fo<<" "<<team1[i].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) fo<<" ";
           
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team1[i].twoa!=0)fo<<" "<<100*team1[i].twom/team1[i].twoa;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat2; m++) fo<<" ";
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            fo<<" "<<team1[i].threea;
            for(int m=0; m<5-brSut3; m++) fo<<" ";
           
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            fo<<" "<<team1[i].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) fo<<" ";
           
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team1[i].threea!=0)fo<<" "<<100*team1[i].threem/team1[i].threea;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat3; m++) fo<<" ";
           
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            fo<<" "<<team1[i].fta;
            for(int m=0; m<5-brSut1; m++) fo<<" ";
           
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            fo<<" "<<team1[i].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) fo<<" ";
           
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team1[i].fta!=0)fo<<" "<<100*team1[i].ftm/team1[i].fta;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat1; m++) fo<<" ";
           
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team1[i].twoa + team1[i].threea)!=0)fo<<" "<<100*(team1[i].twom + team1[i].threem)/(team1[i].twoa + team1[i].threea);
            else fo<<" 0";
            for(int m=0; m<5-brProcenatP; m++) fo<<" ";
           
            fo<<endl;
        }
       
        fo<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        int upoeni=0;
        int uasistencije=0;
        int uskokOdbrana=0;
        int uskokNapad=0;
        int uukradena=0;
        int ubanana=0;
        int uizgubljena=0;
        int ufaul=0;
        int ufauld=0;
        int usut2=0;
        int upogodjensut2=0;
        int usut3=0;
        int upogodjensut3=0;
        int usut1=0;
        int upogodjensut1=0;
       
        for(int i=1; i<=n1; i++){
        upoeni+=team1[i].pts;
        uasistencije+=team1[i].ast;
        uskokOdbrana+=team1[i].dreb;
        uskokNapad+=team1[i].oreb;
        uukradena+=team1[i].stl;
        ubanana+=team1[i].blk;
        uizgubljena+=team1[i].to;
        ufaul+=team1[i].foul;
        ufauld+=team1[i].fould;
        usut2+=team1[i].twoa;
        upogodjensut2+=team1[i].twom;
        usut3+=team1[i].threea;
        upogodjensut3+=team1[i].threem;
        usut1+=team1[i].fta;
        upogodjensut1+=team1[i].ftm;
    }
    int uprocenat2;
    if(usut2!=0)uprocenat2=100*upogodjensut2/usut2;
    else uprocenat2=0;
    int uprocenat3;
    if(usut3!=0)uprocenat3=100*upogodjensut3/usut3;
    else uprocenat3=0;
    int uprocenat1;
    if(usut1!=0)uprocenat1=100*upogodjensut1/usut1;
    else uprocenat1=0;
    int uprocenatP;
    if((usut2+usut3)!=0)uprocenatP=100*(upogodjensut2+upogodjensut3)/(usut2+usut3);
    else uprocenatP=0;
    int uupoeni=upoeni;
        int uuasistencije=uasistencije;
        int uuskokOdbrana=uskokOdbrana;
        int uuskokNapad=uskokNapad;
        int uuukradena=uukradena;
        int uubanana=ubanana;
        int uuizgubljena=uizgubljena;
        int uufaul=ufaul;
        int uufauld=ufauld;
        int uusut2=usut2;
        int uupogodjensut2=upogodjensut2;
        int uusut3=usut3;
        int uupogodjensut3=upogodjensut3;
        int uusut1=usut1;
        int uupogodjensut1=upogodjensut1;
    int uuprocenat2=uprocenat2;
    int uuprocenat3=uprocenat3;
    int uuprocenat1=uprocenat1;
    int uuprocenatP=uprocenatP;
   
    int bruPoeni=1;
    int bruAsistencije=1;
    int bruSkokOdbrana=1;
    int bruSkokNapad=1;
    int bruUkradena=1;
    int bruBanana=1;
    int bruFaul=1;
    int bruFauld=1;
    int bruIzgubljena=1;
    int bruSut2=1;
    int bruPogodjenSut2=1;
    int bruSut3=1;
    int bruPogodjenSut3=1;
    int bruSut1=1;
    int bruPogodjenSut1=1;
    int bruProcenat2=1;
    int bruProcenat3=1;
    int bruProcenat1=1;
    int bruProcenatP=1;
   
   
    fo<<"Ukupno:";
    for(int j=0; j<21-7; j++) fo<<" ";
   
    //
    fo<<"/";
    for(int j=0; j<3-1; j++) fo<<" ";
   
    //
    fo<<" /";
    for(int m=0; m<5-1; m++) fo<<" ";
   
    //
    while(upoeni>9){
        upoeni=upoeni/10;
        bruPoeni++;
    }
    fo<<" "<<uupoeni;
    for(int m=0; m<5-bruPoeni; m++) fo<<" ";
   
    //
    while(uasistencije>9){
        uasistencije=uasistencije/10;
        bruAsistencije++;
    }
    fo<<" "<<uuasistencije;
    for(int m=0; m<5-bruAsistencije; m++) fo<<" ";
   
    //
    while(uskokOdbrana>9){
        uskokOdbrana=uskokOdbrana/10;
        bruSkokOdbrana++;
    }
    fo<<" "<<uuskokOdbrana;
    for(int m=0; m<5-bruSkokOdbrana; m++) fo<<" ";
   
    //
    while(uskokNapad>9){
        uskokNapad=uskokNapad/10;
        bruSkokNapad++;
    }
    fo<<" "<<uuskokNapad;
    for(int m=0; m<5-bruSkokNapad; m++) fo<<" ";
   
    //
    while(uukradena>9){
        uukradena=uukradena/10;
        bruUkradena++;
    }
    fo<<" "<<uuukradena;
    for(int m=0; m<5-bruUkradena; m++) fo<<" ";
   
    //
    while(ubanana>9){
        ubanana=ubanana/10;
        bruBanana++;
    }
    fo<<" "<<uubanana;
    for(int m=0; m<4-bruBanana; m++) fo<<" ";
   
    //
    while(uizgubljena>9){
        uizgubljena=uizgubljena/10;
        bruIzgubljena++;
    }
    fo<<" "<<uuizgubljena;
    for(int m=0; m<6-bruIzgubljena; m++) fo<<" ";
   
    //
    while(ufaul>9){
        ufaul=ufaul/10;
        bruFaul++;
    }
    fo<<" "<<uufaul;
    for(int m=0; m<5-bruFaul; m++) fo<<" ";
   
    //
    while(ufauld>9){
        ufauld=ufauld/10;
        bruFauld++;
    }
    fo<<" "<<uufauld;
    for(int m=0; m<5-bruFauld; m++) fo<<" ";
   
    //
    while(usut2>9){
        usut2=usut2/10;
        bruSut2++;
    }
    fo<<" "<<uusut2;
    for(int m=0; m<5-bruSut2; m++) fo<<" ";
   
    //
    while(upogodjensut2>9){
        upogodjensut2=upogodjensut2/10;
        bruPogodjenSut2++;
    }
    fo<<" "<<uupogodjensut2;
    for(int m=0; m<5-bruPogodjenSut2; m++) fo<<" ";
   
    //
    while(uprocenat2>9){
        uprocenat2=uprocenat2/10;
        bruProcenat2++;
    }
    fo<<" "<<uuprocenat2;
    for(int m=0; m<5-bruProcenat2; m++) fo<<" ";
    //
    while(usut3>9){
        usut3=usut3/10;
        bruSut3++;
    }
    fo<<" "<<uusut3;
    for(int m=0; m<5-bruSut3; m++) fo<<" ";
   
    //
    while(upogodjensut3>9){
        upogodjensut3=upogodjensut3/10;
        bruPogodjenSut3++;
    }
    fo<<" "<<uupogodjensut3;
    for(int m=0; m<5-bruPogodjenSut3; m++) fo<<" ";
   
    //
    while(uprocenat3>9){
        uprocenat3=uprocenat3/10;
        bruProcenat3++;
    }
    fo<<" "<<uuprocenat3;
    for(int m=0; m<5-bruProcenat3; m++) fo<<" ";
   
    //
    while(usut1>9){
        usut1=usut1/10;
        bruSut1++;
    }
    fo<<" "<<uusut1;
    for(int m=0; m<5-bruSut1; m++) fo<<" ";
   
    //
    while(upogodjensut1>9){
        upogodjensut1=upogodjensut1/10;
        bruPogodjenSut1++;
    }
    fo<<" "<<uupogodjensut1;
    for(int m=0; m<5-bruPogodjenSut1; m++) fo<<" ";
   
    //
    while(uprocenat1>9){
        uprocenat1=uprocenat1/10;
        bruProcenat1++;
    }
    fo<<" "<<uuprocenat1;
    for(int m=0; m<5-bruProcenat1; m++) fo<<" ";
   
    //
    while(uprocenatP>9){
        uprocenatP=uprocenatP/10;
        bruProcenatP++;
    }
    fo<<" "<<uuprocenatP;
    for(int m=0; m<5-bruProcenatP; m++) fo<<" ";
   
    fo<<endl;
       
    fo<<endl;
    fo<<tim2<<endl;
        fo<<"ime"<<"                 ";
        fo<<"poz ";
        fo<<"broj  ";
        fo<<"pts   ";
        fo<<"ast   ";
        fo<<"dreb  ";
        fo<<"oreb  ";
        fo<<"stl   ";
        fo<<"blk   ";
        fo<<"to   ";
        fo<<"foul  ";
        fo<<"fould   ";
        fo<<"2a    ";
        fo<<"2m    ";
        fo<<"%2    ";
        fo<<"3a    ";
        fo<<"3m    ";
        fo<<"%3    ";
        fo<<"fta   ";
        fo<<"ftm   ";
        fo<<"ft%   ";
        fo<<"fg%   ";
        fo<<endl;
        for(int i=1; i<=n2; i++){
           
            int broj=team2[i].number;
            int brBroj=1;
           
            int poeni=team2[i].pts;
            int brPoeni=1;
           
            int asistencije=team2[i].ast;
            int brAsistencije=1;
           
            int skokOdbrana=team2[i].dreb;
            int brSkokOdbrana=1;
           
            int skokNapad=team2[i].oreb;
            int brSkokNapad=1;
           
            int ukradena=team2[i].stl;
            int brUkradena=1;
           
            int banana=team2[i].blk;
            int brBanana=1;
           
            int izgubljena=team2[i].to;
            int brIzgubljena=1;
           
            int faul=team2[i].foul;
            int brFaul=1;
           
            int fauld=team2[i].fould;
            int brFauld=1;
           
            int sut2=team2[i].twoa;
            int brSut2=1;
           
            int pogodjensut2=team2[i].twom;
            int brPogodjenSut2=1;
           
            int procenat2;
            if(team2[i].twoa==0)procenat2=0;
            else procenat2=100*team2[i].twom/team2[i].twoa;
            int brProcenat2=1;
           
            int sut3=team2[i].threea;
            int brSut3=1;
           
            int pogodjensut3=team2[i].threem;
            int brPogodjenSut3=1;
           
            int procenat3;
            if(team2[i].threea==0)procenat3=0;
            else procenat3=100*team2[i].threem/team2[i].threea;
            int brProcenat3=1;
           
            int sut1=team2[i].fta;
            int brSut1=1;
           
            int pogodjensut1=team2[i].ftm;
            int brPogodjenSut1=1;
           
            int procenat1;
            if(team2[i].fta==0)procenat1=0;
            else procenat1=100*team2[i].ftm/team2[i].fta;
            int brProcenat1=1;
           
            int procenatP;
            if((team2[i].twoa + team2[i].threea)==0)procenatP=0;
            else procenatP=100*(team2[i].twom + team2[i].threem)/(team2[i].twoa + team2[i].threea);
            int brProcenatP=1;
            //
            int x=0;
            x=team2[i].name.length();
            fo<<team2[i].name;
            for(int j=0; j<21-x; j++) fo<<" ";
           
            //
            int y=0;
            y=team2[i].position.length();
            fo<<team2[i].position;
            for(int j=0; j<3-y; j++) fo<<" ";
           
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            fo<<" "<<team2[i].number;
            for(int m=0; m<5-brBroj; m++) fo<<" ";
           
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            fo<<" "<<team2[i].pts;
            for(int m=0; m<5-brPoeni; m++) fo<<" ";
           
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            fo<<" "<<team2[i].ast;
            for(int m=0; m<5-brAsistencije; m++) fo<<" ";
           
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            fo<<" "<<team2[i].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) fo<<" ";
           
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            fo<<" "<<team2[i].oreb;
            for(int m=0; m<5-brSkokNapad; m++) fo<<" ";
           
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            fo<<" "<<team2[i].stl;
            for(int m=0; m<5-brUkradena; m++) fo<<" ";
           
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            fo<<" "<<team2[i].blk;
            for(int m=0; m<4-brBanana; m++) fo<<" ";
           
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            fo<<" "<<team2[i].to;
            for(int m=0; m<6-brIzgubljena; m++) fo<<" ";
           
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            fo<<" "<<team2[i].foul;
            for(int m=0; m<5-brFaul; m++) fo<<" ";

            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            fo<<" "<<team2[i].fould;
            for(int m=0; m<5-brFauld; m++) fo<<" ";
           
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            fo<<" "<<team2[i].twoa;
            for(int m=0; m<5-brSut2; m++) fo<<" ";
           
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            fo<<" "<<team2[i].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) fo<<" ";
           
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team2[i].twoa!=0)fo<<" "<<100*team2[i].twom/team2[i].twoa;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat2; m++) fo<<" ";
           
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            fo<<" "<<team2[i].threea;
            for(int m=0; m<5-brSut3; m++) fo<<" ";
           
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            fo<<" "<<team2[i].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) fo<<" ";
           
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team2[i].threea!=0)fo<<" "<<100*team2[i].threem/team2[i].threea;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat3; m++) fo<<" ";
           
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            fo<<" "<<team2[i].fta;
            for(int m=0; m<5-brSut1; m++) fo<<" ";
           
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            fo<<" "<<team2[i].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) fo<<" ";
           
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team2[i].fta!=0)fo<<" "<<100*team2[i].ftm/team2[i].fta;
            else fo<<" 0";
            for(int m=0; m<5-brProcenat1; m++) fo<<" ";
           
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team2[i].twoa + team2[i].threea)!=0)fo<<" "<<100*(team2[i].twom + team2[i].threem)/(team2[i].twoa + team2[i].threea);
            else fo<<" 0";
            for(int m=0; m<5-brProcenatP; m++) fo<<" ";
           
            fo<<endl;
        }
       
        fo<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        int upoeni2=0;
        int uasistencije2=0;
        int uskokOdbrana2=0;
        int uskokNapad2=0;
        int uukradena2=0;
        int ubanana2=0;
        int uizgubljena2=0;
        int ufaul2=0;
        int ufauld2=0;
        int usut22=0;
        int upogodjensut22=0;
        int usut32=0;
        int upogodjensut32=0;
        int usut12=0;
        int upogodjensut12=0;
       
        for(int i=1; i<=n2; i++){
        upoeni2+=team2[i].pts;
        uasistencije2+=team2[i].ast;
        uskokOdbrana2+=team2[i].dreb;
        uskokNapad2+=team2[i].oreb;
        uukradena2+=team2[i].stl;
        ubanana2+=team2[i].blk;
        uizgubljena2+=team2[i].to;
        ufaul2+=team2[i].foul;
        ufauld2+=team2[i].fould;
        usut22+=team2[i].twoa;
        upogodjensut22+=team2[i].twom;
        usut32+=team2[i].threea;
        upogodjensut32+=team2[i].threem;
        usut12+=team2[i].fta;
        upogodjensut12+=team2[i].ftm;
    }
    int uprocenat22;
    if(usut2!=0)uprocenat2=100*upogodjensut22/usut22;
    else uprocenat22=0;
    int uprocenat32;
    if(usut32!=0)uprocenat32=100*upogodjensut32/usut32;
    else uprocenat32=0;
    int uprocenat12;
    if(usut12!=0)uprocenat12=100*upogodjensut12/usut12;
    else uprocenat12=0;
    int uprocenatP2;
    if((usut22+usut32)!=0)uprocenatP2=100*(upogodjensut22+upogodjensut32)/(usut22+usut32);
    else uprocenatP2=0;
    int uupoeni2=upoeni2;
        int uuasistencije2=uasistencije2;
        int uuskokOdbrana2=uskokOdbrana2;
        int uuskokNapad2=uskokNapad2;
        int uuukradena2=uukradena2;
        int uubanana2=ubanana2;
        int uuizgubljena2=uizgubljena2;
        int uufaul2=ufaul2;
        int uufauld2=ufauld2;
        int uusut22=usut22;
        int uupogodjensut22=upogodjensut22;
        int uusut32=usut32;
        int uupogodjensut32=upogodjensut32;
        int uusut12=usut12;
        int uupogodjensut12=upogodjensut12;
    int uuprocenat22=uprocenat22;
    int uuprocenat32=uprocenat32;
    int uuprocenat12=uprocenat12;
    int uuprocenatP2=uprocenatP2;
   
    int bruPoeni2=1;
    int bruAsistencije2=1;
    int bruSkokOdbrana2=1;
    int bruSkokNapad2=1;
    int bruUkradena2=1;
    int bruBanana2=1;
    int bruFaul2=1;
    int bruFauld2=1;
    int bruIzgubljena2=1;
    int bruSut22=1;
    int bruPogodjenSut22=1;
    int bruSut32=1;
    int bruPogodjenSut32=1;
    int bruSut12=1;
    int bruPogodjenSut12=1;
    int bruProcenat22=1;
    int bruProcenat32=1;
    int bruProcenat12=1;
    int bruProcenatP2=1;
   
   
    fo<<"Ukupno:";
    for(int j=0; j<21-7; j++) fo<<" ";
   
    //
    fo<<"/";
    for(int j=0; j<3-1; j++) fo<<" ";
   
    //
    fo<<" /";
    for(int m=0; m<5-1; m++) fo<<" ";
   
    //
    while(upoeni2>9){
        upoeni2=upoeni2/10;
        bruPoeni2++;
    }
    fo<<" "<<uupoeni2;
    for(int m=0; m<5-bruPoeni2; m++) fo<<" ";
   
    //
    while(uasistencije2>9){
        uasistencije2=uasistencije2/10;
        bruAsistencije2++;
    }
    fo<<" "<<uuasistencije2;
    for(int m=0; m<5-bruAsistencije2; m++) fo<<" ";
   
    //
    while(uskokOdbrana2>9){
        uskokOdbrana2=uskokOdbrana2/10;
        bruSkokOdbrana2++;
    }
    fo<<" "<<uuskokOdbrana2;
    for(int m=0; m<5-bruSkokOdbrana2; m++) fo<<" ";
   
    //
    while(uskokNapad2>9){
        uskokNapad2=uskokNapad2/10;
        bruSkokNapad2++;
    }
    fo<<" "<<uuskokNapad2;
    for(int m=0; m<5-bruSkokNapad2; m++) fo<<" ";
   
    //
    while(uukradena2>9){
        uukradena2=uukradena2/10;
        bruUkradena2++;
    }
    fo<<" "<<uuukradena2;
    for(int m=0; m<5-bruUkradena2; m++) fo<<" ";
   
    //
    while(ubanana2>9){
        ubanana2=ubanana2/10;
        bruBanana2++;
    }
    fo<<" "<<uubanana2;
    for(int m=0; m<4-bruBanana2; m++) fo<<" ";
   
    //
    while(uizgubljena2>9){
        uizgubljena2=uizgubljena2/10;
        bruIzgubljena2++;
    }
    fo<<" "<<uuizgubljena2;
    for(int m=0; m<6-bruIzgubljena2; m++) fo<<" ";
   
    //
    while(ufaul2>9){
        ufaul2=ufaul2/10;
        bruFaul2++;
    }
    fo<<" "<<uufaul2;
    for(int m=0; m<5-bruFaul2; m++) fo<<" ";
   
    //
    while(ufauld2>9){
        ufauld2=ufauld2/10;
        bruFauld2++;
    }
    fo<<" "<<uufauld2;
    for(int m=0; m<5-bruFauld2; m++) fo<<" ";
   
    //
    while(usut22>9){
        usut22=usut22/10;
        bruSut22++;
    }
    fo<<" "<<uusut22;
    for(int m=0; m<5-bruSut22; m++) fo<<" ";
   
    //
    while(upogodjensut22>9){
        upogodjensut22=upogodjensut22/10;
        bruPogodjenSut22++;
    }
    fo<<" "<<uupogodjensut22;
    for(int m=0; m<5-bruPogodjenSut22; m++) fo<<" ";
   
    //
    while(uprocenat22>9){
        uprocenat22=uprocenat22/10;
        bruProcenat22++;
    }
    fo<<" "<<uuprocenat22;
    for(int m=0; m<5-bruProcenat22; m++) fo<<" ";
    //
    while(usut32>9){
        usut32=usut32/10;
        bruSut32++;
    }
    fo<<" "<<uusut32;
    for(int m=0; m<5-bruSut32; m++) fo<<" ";
   
    //
    while(upogodjensut32>9){
        upogodjensut32=upogodjensut32/10;
        bruPogodjenSut32++;
    }
    fo<<" "<<uupogodjensut32;
    for(int m=0; m<5-bruPogodjenSut32; m++) fo<<" ";
   
    //
    while(uprocenat32>9){
        uprocenat32=uprocenat32/10;
        bruProcenat32++;
    }
    fo<<" "<<uuprocenat32;
    for(int m=0; m<5-bruProcenat32; m++) fo<<" ";
   
    //
    while(usut12>9){
        usut12=usut12/10;
        bruSut12++;
    }
    fo<<" "<<uusut12;
    for(int m=0; m<5-bruSut12; m++) fo<<" ";
   
    //
    while(upogodjensut12>9){
        upogodjensut12=upogodjensut12/10;
        bruPogodjenSut12++;
    }
    fo<<" "<<uupogodjensut12;
    for(int m=0; m<5-bruPogodjenSut12; m++) fo<<" ";
   
    //
    while(uprocenat12>9){
        uprocenat12=uprocenat12/10;
        bruProcenat12++;
    }
    fo<<" "<<uuprocenat12;
    for(int m=0; m<5-bruProcenat12; m++) fo<<" ";
   
    //
    while(uprocenatP2>9){
        uprocenatP2=uprocenatP2/10;
        bruProcenatP2++;
    }
    fo<<" "<<uuprocenatP2;
    for(int m=0; m<5-bruProcenatP2; m++) fo<<" ";
   
    fo<<endl<<endl;
	
	int s[16],m,k;
	if(r1>r2)
	{
		for(int i=1;i<=n1;i++)
		{
			s[i]=team1[i].pts+team1[i].ast+team1[i].dreb+team1[i].oreb+team1[i].blk+team1[i].stl+team1[i].fould-team1[i].foul-team1[i].to-(team1[i].threea-team1[i].threem)-(team1[i].twoa-team1[i].twom)-(team1[i].fta-team1[i].ftm);	
		}
		m=s[1];
		k=1;
		for(int i=2;i<=n1;i++)
		{
			if(s[i]>m)
			{
				m=s[i];
				k=i;
			}
		}
		fo<<"MVP utakmice je "<<team1[k].name<<" sa indexom korisnosti "<<s[k]<<endl;
	}
	else
	{
		for(int i=1;i<=n2;i++)
		{
			s[i]=team2[i].pts+team2[i].ast+team2[i].dreb+team2[i].oreb+team2[i].blk+team2[i].stl+team2[i].fould-team2[i].foul-team2[i].to-(team2[i].threea-team2[i].threem)-(team2[i].twoa-team2[i].twom)-(team2[i].fta-team2[i].ftm);	
		}
		m=s[1];
		k=1;
		for(int i=2;i<=n2;i++)
		{
			if(s[i]>m)
			{
				m=s[i];
				k=i;
			}
		}
		fo<<"MVP utakmice je "<<team2[k].name<<" sa indexom korisnosti "<<s[k]<<endl;
	}
	
	fo.close();
	cout<<endl<<"Napravljen je text dokument sa imenom ["<<s1<<"] u kome su sacuvani podaci za ovu tekmu."<<endl;
}

void BasketGame::PrevGame(string s1){
	ifstream fi;
	fi.open("ShtekImena.txt");
	string ime;
	string imena[10000];
	int i=0;
	while(getline(fi,ime)){
		imena[i]=ime;
		i++;
	}
	fi.close();
	sort(imena,imena+i);
	int id=binPret(imena,0,i,s1);//binarna pretraga trazene tekme, tj imena fajla u kom je sacuvana trazena tekma
	if(id==-1){
		cout<<"Nazalost nismo pronasli fajl pod takvim imenom"<<endl;
	}
	else{
		ifstream tekma;
		s1+=".txt";
		tekma.open(s1.c_str());
		string line;
		while(getline(tekma,line)){
			cout<<line<<endl;
		}
		tekma.close();
	}
}

void BasketGame::teamispis(string teamname){
	if(tim1==teamname){
		cout<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n1 ; i++){
			cout<<team1[i].name;
			int l=(team1[i].name).size();
			l=N-l;
			while(l>0){
				cout<<" ";
				l--;
			}
			cout<<team1[i].number<<"   ";
			if(team1[i].number<10)cout<<" ";
			cout<<team1[i].position<<"    ";
			if((team1[i].position).size()==1)cout<<" ";
			cout<<team1[i].height<<"cm"<<endl;
		}
	}
	else if(tim2==teamname){
		cout<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n2 ; i++){
			cout<<team2[i].name;
			int l=(team2[i].name).size();
			l=N-l;
			while(l>0){
				cout<<" ";
				l--;
			}
			cout<<team2[i].number<<"   ";
			if(team2[i].number<10)cout<<" ";
			cout<<team2[i].position<<"    ";
			if((team2[i].position).size()==1)cout<<" ";
			cout<<team2[i].height<<"cm"<<endl;
		}
	}
	else cout<<"Taj tim ne igra ovu utakmicu molimo unesite: "<<tim1<<" ili "<<tim2<<endl;
}

void BasketGame::timovi(){
	cout<<tim1<<endl;
		cout<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n1 ; i++){
			cout<<team1[i].name;
			int l=(team1[i].name).size();
			l=N-l;
			while(l>0){
				cout<<" ";
				l--;
			}
			cout<<team1[i].number<<"   ";
			if(team1[i].number<10)cout<<" ";
			cout<<team1[i].position<<"    ";
			if((team1[i].position).size()==1)cout<<" ";
			cout<<team1[i].height<<"cm"<<endl;
		}
	cout<<endl<<tim2<<endl;
		cout<<"PlayerName                    "<<"#   POS   HEIGHT"<<endl;
		for(int i=1 ; i<=n2 ; i++){
			cout<<team2[i].name;
			int l=(team2[i].name).size();
			l=N-l;
			while(l>0){
				cout<<" ";
				l--;
			}
			cout<<team2[i].number<<"   ";
			if(team2[i].number<10)cout<<" ";
			cout<<team2[i].position<<"    ";
			if((team2[i].position).size()==1)cout<<" ";
			cout<<team2[i].height<<"cm"<<endl;
		}
		cout<<endl;
}
void BasketGame::spisaktekmi(){
	ifstream fi;
	fi.open("ShtekImena.txt");
	string ime;
	while(getline(fi,ime)){
		cout<<ime<<endl;
	}
	fi.close();
}

void BasketGame::rezultat()
{
	int r1=0, r2=0;
	for(int i=1;i<=n1;i++)
	{
		r1+=team1[i].pts;	
	}
	for(int i=1;i<=n2;i++)
	{
		r2+=team2[i].pts;	
	}
	cout<<"Rezultat je:"<<endl;
	
	cout<<tim1<<"  "<<r1<<":"<<r2<<"  "<<tim2<<endl;
}
player BasketGame::MVP()
{
	int r1=0, r2=0;
	int s[16];
	int m, k;
	for(int i=1;i<=n1;i++)
	{
		r1+=team1[i].pts;	
	}
	for(int i=1;i<=n2;i++)
	{
		r2+=team2[i].pts;	
	}
	if(r1>r2)
	{
		for(int i=1;i<=n1;i++)
		{
			s[i]=team1[i].pts+team1[i].ast+team1[i].dreb+team1[i].oreb+team1[i].blk+team1[i].stl+team1[i].fould-team1[i].foul-team1[i].to-(team1[i].threea-team1[i].threem)-(team1[i].twoa-team1[i].twom)-(team1[i].fta-team1[i].ftm);	
		}
		m=s[1];
		k=1;
		for(int i=2;i<=n1;i++)
		{
			if(s[i]>m)
			{
				m=s[i];
				k=i;
			}
		}
		return team1[k];
	}
	else
	{
		for(int i=1;i<=n2;i++)
		{
			s[i]=team2[i].pts+team2[i].ast+team2[i].dreb+team2[i].oreb+team2[i].blk+team2[i].stl+team2[i].fould-team2[i].foul-team2[i].to-(team2[i].threea-team2[i].threem)-(team2[i].twoa-team2[i].twom)-(team2[i].fta-team2[i].ftm);	
		}
		m=s[1];
		k=1;
		for(int i=2;i<=n2;i++)
		{
			if(s[i]>m)
			{
				m=s[i];
				k=i;
			}
		}
		return team2[k];
	}
}
void BasketGame::playerstats(string ime)
{
	int k=0;
	for(int i=1;i<=n1;i++)
	{
		if(ime==team1[i].name)
		{
			k=i;
			break;
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n2;i++)
		{
			if(ime==team2[i].name)
			{
			k=i;
			break;
			}
		}
		if(k==0)
		{
			cout<<"nema trazenog igraca"<<endl;
		}
		else
		{
			cout<<"ime"<<"                 ";
       		cout<<"poz ";
        	cout<<"broj  ";
        	cout<<"pts   ";
        	cout<<"ast   ";
        	cout<<"dreb  ";
        	cout<<"oreb  ";
        	cout<<"stl   ";
        	cout<<"blk   ";
        	cout<<"to   ";
        	cout<<"foul  ";
        	cout<<"fould   ";
        	cout<<"2a    ";
        	cout<<"2m    ";
        	cout<<"%2    ";
        	cout<<"3a    ";
        	cout<<"3m    ";
        	cout<<"%3    ";
        	cout<<"fta   ";
        	cout<<"ftm   ";
        	cout<<"ft%   ";
        	cout<<"fg%   ";
        	cout<<endl;
        	int broj=team2[k].number;
            int brBroj=1;
            
            int poeni=team2[k].pts;
            int brPoeni=1;
            
            int asistencije=team2[k].ast;
            int brAsistencije=1;
            
            int skokOdbrana=team2[k].dreb;
            int brSkokOdbrana=1;
            
            int skokNapad=team2[k].oreb;
            int brSkokNapad=1;
            
            int ukradena=team2[k].stl;
            int brUkradena=1;
            
            int banana=team2[k].blk;
            int brBanana=1;
            
            int izgubljena=team2[k].to;
            int brIzgubljena=1;
            
            int faul=team2[k].foul;
            int brFaul=1;
            
            int fauld=team2[k].fould;
            int brFauld=1;
            
            int sut2=team2[k].twoa;
            int brSut2=1;
            
            int pogodjensut2=team2[k].twom;
            int brPogodjenSut2=1;
            
            int procenat2;
            if(team2[k].twoa==0)procenat2=0;
            else procenat2=100*team2[k].twom/team2[k].twoa;
            int brProcenat2=1;
            
            int sut3=team2[k].threea;
            int brSut3=1;
            
            int pogodjensut3=team2[k].threem;
            int brPogodjenSut3=1;
            
            int procenat3;
            if(team2[k].threea==0)procenat3=0;
            else procenat3=100*team2[k].threem/team2[k].threea;
            int brProcenat3=1;
            
            int sut1=team2[k].fta;
            int brSut1=1;
            
            int pogodjensut1=team2[k].ftm;
            int brPogodjenSut1=1;
            
            int procenat1;
            if(team2[k].fta==0)procenat1=0;
            else procenat1=100*team2[k].ftm/team2[k].fta;
            int brProcenat1=1;
            
            int procenatP;
            if((team2[k].twoa + team2[k].threea)==0)procenatP=0;
            else procenatP=100*(team2[k].twom + team2[k].threem)/(team2[k].twoa + team2[k].threea);
            int brProcenatP=1;
            //
            int x=0;
            x=team2[k].name.length();
            cout<<team2[k].name;
            for(int j=0; j<21-x; j++) cout<<" ";
            
            //
            int y=0;
            y=team2[k].position.length();
            cout<<team2[k].position;
            for(int j=0; j<3-y; j++) cout<<" ";
            
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            cout<<" "<<team2[k].number;
            for(int m=0; m<5-brBroj; m++) cout<<" ";
            
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            cout<<" "<<team2[k].pts;
            for(int m=0; m<5-brPoeni; m++) cout<<" ";
            
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            cout<<" "<<team2[k].ast;
            for(int m=0; m<5-brAsistencije; m++) cout<<" ";
            
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            cout<<" "<<team2[k].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) cout<<" ";
            
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            cout<<" "<<team2[k].oreb;
            for(int m=0; m<5-brSkokNapad; m++) cout<<" ";
            
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            cout<<" "<<team2[k].stl;
            for(int m=0; m<5-brUkradena; m++) cout<<" ";
            
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            cout<<" "<<team2[k].blk;
            for(int m=0; m<4-brBanana; m++) cout<<" ";
            
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            cout<<" "<<team2[k].to;
            for(int m=0; m<6-brIzgubljena; m++) cout<<" ";
            
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            cout<<" "<<team2[k].foul;
            for(int m=0; m<5-brFaul; m++) cout<<" ";

            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            cout<<" "<<team2[k].fould;
            for(int m=0; m<5-brFauld; m++) cout<<" ";
            
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            cout<<" "<<team2[k].twoa;
            for(int m=0; m<5-brSut2; m++) cout<<" ";
            
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            cout<<" "<<team2[k].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) cout<<" ";
            
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team2[k].twoa!=0)cout<<" "<<100*team2[k].twom/team2[k].twoa;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat2; m++) cout<<" ";
            
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            cout<<" "<<team2[k].threea;
            for(int m=0; m<5-brSut3; m++) cout<<" ";
            
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            cout<<" "<<team2[k].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) cout<<" ";
            
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team2[k].threea!=0)cout<<" "<<100*team2[k].threem/team2[k].threea;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat3; m++) cout<<" ";
            
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            cout<<" "<<team2[k].fta;
            for(int m=0; m<5-brSut1; m++) cout<<" ";
            
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            cout<<" "<<team2[k].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) cout<<" ";
            
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team2[k].fta!=0)cout<<" "<<100*team2[k].ftm/team2[k].fta;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat1; m++) cout<<" ";
            
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team2[k].twoa + team2[k].threea)!=0)cout<<" "<<100*(team2[k].twom + team2[k].threem)/(team2[k].twoa + team2[k].threea);
            else cout<<" 0";
            for(int m=0; m<5-brProcenatP; m++) cout<<" ";
            
            cout<<endl;
        	
		}
	}
	else
	{
		cout<<"ime"<<"                 ";
       		cout<<"poz ";
        	cout<<"broj  ";
        	cout<<"pts   ";
        	cout<<"ast   ";
        	cout<<"dreb  ";
        	cout<<"oreb  ";
        	cout<<"stl   ";
        	cout<<"blk   ";
        	cout<<"to   ";
        	cout<<"foul  ";
        	cout<<"fould   ";
        	cout<<"2a    ";
        	cout<<"2m    ";
        	cout<<"%2    ";
        	cout<<"3a    ";
        	cout<<"3m    ";
        	cout<<"%3    ";
        	cout<<"fta   ";
        	cout<<"ftm   ";
        	cout<<"ft%   ";
        	cout<<"fg%   ";
        	cout<<endl;
        	int broj=team1[k].number;
            int brBroj=1;
            
            int poeni=team1[k].pts;
            int brPoeni=1;
            
            int asistencije=team1[k].ast;
            int brAsistencije=1;
            
            int skokOdbrana=team1[k].dreb;
            int brSkokOdbrana=1;
            
            int skokNapad=team1[k].oreb;
            int brSkokNapad=1;
            
            int ukradena=team1[k].stl;
            int brUkradena=1;
            
            int banana=team1[k].blk;
            int brBanana=1;
            
            int izgubljena=team1[k].to;
            int brIzgubljena=1;
            
            int faul=team1[k].foul;
            int brFaul=1;
            
            int fauld=team1[k].fould;
            int brFauld=1;
            
            int sut2=team1[k].twoa;
            int brSut2=1;
            
            int pogodjensut2=team1[k].twom;
            int brPogodjenSut2=1;
            
            int procenat2;
            if(team1[k].twoa==0)procenat2=0;
            else procenat2=100*team1[k].twom/team1[k].twoa;
            int brProcenat2=1;
            
            int sut3=team1[k].threea;
            int brSut3=1;
            
            int pogodjensut3=team1[k].threem;
            int brPogodjenSut3=1;
            
            int procenat3;
            if(team1[k].threea==0)procenat3=0;
            else procenat3=100*team1[k].threem/team1[k].threea;
            int brProcenat3=1;
            
            int sut1=team1[k].fta;
            int brSut1=1;
            
            int pogodjensut1=team1[k].ftm;
            int brPogodjenSut1=1;
            
            int procenat1;
            if(team1[k].fta==0)procenat1=0;
            else procenat1=100*team2[k].ftm/team2[k].fta;
            int brProcenat1=1;
            
            int procenatP;
            if((team1[k].twoa + team1[k].threea)==0)procenatP=0;
            else procenatP=100*(team1[k].twom + team1[k].threem)/(team1[k].twoa + team1[k].threea);
            int brProcenatP=1;
            //
            int x=0;
            x=team1[k].name.length();
            cout<<team1[k].name;
            for(int j=0; j<21-x; j++) cout<<" ";
            
            //
            int y=0;
            y=team1[k].position.length();
            cout<<team1[k].position;
            for(int j=0; j<3-y; j++) cout<<" ";
            
            //
            while(broj>9){
                broj=broj/10;
                brBroj++;
            }
            cout<<" "<<team1[k].number;
            for(int m=0; m<5-brBroj; m++) cout<<" ";
            
            //
            while(poeni>9){
                poeni=poeni/10;
                brPoeni++;
            }
            cout<<" "<<team1[k].pts;
            for(int m=0; m<5-brPoeni; m++) cout<<" ";
            
            //
            while(asistencije>9){
                asistencije=asistencije/10;
                brAsistencije++;
            }
            cout<<" "<<team1[k].ast;
            for(int m=0; m<5-brAsistencije; m++) cout<<" ";
            
            //
            while(skokOdbrana>9){
                skokOdbrana=skokOdbrana/10;
                brSkokOdbrana++;
            }
            cout<<" "<<team1[k].dreb;
            for(int m=0; m<5-brSkokOdbrana; m++) cout<<" ";
            
            //
            while(skokNapad>9){
                skokNapad=skokNapad/10;
                brSkokNapad++;
            }
            cout<<" "<<team1[k].oreb;
            for(int m=0; m<5-brSkokNapad; m++) cout<<" ";
            
            //
            while(ukradena>9){
                ukradena=ukradena/10;
                brUkradena++;
            }
            cout<<" "<<team1[k].stl;
            for(int m=0; m<5-brUkradena; m++) cout<<" ";
            
            //
            while(banana>9){
                banana=banana/10;
                brBanana++;
            }
            cout<<" "<<team1[k].blk;
            for(int m=0; m<4-brBanana; m++) cout<<" ";
            
            //
            while(izgubljena>9){
                izgubljena=izgubljena/10;
                brIzgubljena++;
            }
            cout<<" "<<team1[k].to;
            for(int m=0; m<6-brIzgubljena; m++) cout<<" ";
            
            //
            while(faul>9){
                faul=faul/10;
                brFaul++;
            }
            cout<<" "<<team1[k].foul;
            for(int m=0; m<5-brFaul; m++) cout<<" ";

            //
            while(fauld>9){
                fauld=fauld/10;
                brFauld++;
            }
            cout<<" "<<team1[k].fould;
            for(int m=0; m<5-brFauld; m++) cout<<" ";
            
            //
            while(sut2>9){
                sut2=sut2/10;
                brSut2++;
            }
            cout<<" "<<team1[k].twoa;
            for(int m=0; m<5-brSut2; m++) cout<<" ";
            
            //
            while(pogodjensut2>9){
                pogodjensut2=pogodjensut2/10;
                brPogodjenSut2++;
            }
            cout<<" "<<team1[k].twom;
            for(int m=0; m<5-brPogodjenSut2; m++) cout<<" ";
            
            //
            while(procenat2>9){
                procenat2=procenat2/10;
                brProcenat2++;
            }
            if(team1[k].twoa!=0)cout<<" "<<100*team1[k].twom/team1[k].twoa;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat2; m++) cout<<" ";
            
            //
            while(sut3>9){
                sut3=sut3/10;
                brSut3++;
            }
            cout<<" "<<team1[k].threea;
            for(int m=0; m<5-brSut3; m++) cout<<" ";
            
            //
            while(pogodjensut3>9){
                pogodjensut3=pogodjensut3/10;
                brPogodjenSut3++;
            }
            cout<<" "<<team1[k].threem;
            for(int m=0; m<5-brPogodjenSut3; m++) cout<<" ";
            
            //
            while(procenat3>9){
                procenat3=procenat3/10;
                brProcenat3++;
            }
            if(team1[k].threea!=0)cout<<" "<<100*team1[k].threem/team1[k].threea;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat3; m++) cout<<" ";
            
            //
            while(sut1>9){
                sut1=sut1/10;
                brSut1++;
            }
            cout<<" "<<team1[k].fta;
            for(int m=0; m<5-brSut1; m++) cout<<" ";
            
            //
            while(pogodjensut1>9){
                pogodjensut1=pogodjensut1/10;
                brPogodjenSut1++;
            }
            cout<<" "<<team1[k].ftm;
            for(int m=0; m<5-brPogodjenSut1; m++) cout<<" ";
            
            //
            while(procenat1>9){
                procenat1=procenat1/10;
                brProcenat1++;
            }
            if(team1[k].fta!=0)cout<<" "<<100*team1[k].ftm/team1[k].fta;
            else cout<<" 0";
            for(int m=0; m<5-brProcenat1; m++) cout<<" ";
            
            //
            while(procenatP>9){
                procenatP=procenatP/10;
                brProcenatP++;
            }
            if((team1[k].twoa + team1[k].threea)!=0)cout<<" "<<100*(team1[k].twom + team1[k].threem)/(team1[k].twoa + team1[k].threea);
            else cout<<" 0";
            for(int m=0; m<5-brProcenatP; m++) cout<<" ";
            
            cout<<endl;
	}	
}

double BasketGame::stat(string ime, string s)
{
	int k=0;
	for(int i=1;i<=n1;i++)
	{
		if(ime==team1[i].name)
		{
			k=i;
			break;
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n2;i++)
		{
			if(ime==team2[i].name)
			{
				k=i;
				break;
			}
		}
		if(k==0)
		{
			return -1;
		}
		else
		{
			if(s=="pts")
			{
				return team2[k].pts;
			}
			else if(s=="ast")
			{
				return team2[k].ast;
			}
			else if(s=="dreb")
			{
				return team2[k].dreb;
			}	
			else if(s=="oreb")
			{
				return team2[k].oreb;
			}
			else if(s=="reb")
			{
				return team2[k].oreb+team2[k].dreb;
			}
			else if(s=="stl")
			{
				return team2[k].stl;
			}
			else if(s=="blk")
			{
				return team2[k].blk;
			}
			else if(s=="to")
			{
				return team2[k].to;
			}
			else if(s=="foul")
			{
				return team2[k].foul;
			}
			else if(s=="fould")
			{
				return team2[k].fould;
			}
			else if(s=="2a")
			{
				return team2[k].twoa;
			}
			else if(s=="2m")
			{
				return team2[k].twom;
			}
			else if(s=="%2")
			{
				int procenat2;
        	    if(team2[k].threea==0) procenat2=0;
        	    else procenat2=100*team2[k].twom/team2[k].twoa;
        	    return procenat2;
			}
			else if(s=="3a")
			{
				return team2[k].threea;
			}
			else if(s=="3m")
			{
				return team2[k].threem;
			}
			else if(s=="%3")
			{
				int procenat3;
        	    if(team2[k].threea==0) procenat3=0;
        	    else procenat3=100*team2[k].threem/team2[k].threea;
        	    return  procenat3;
			}
			else if(s=="fta")
			{
				return team2[k].fta;
			}
			else if(s=="ftm")
			{
				return team2[k].ftm;
			}
			else if(s=="ft%")
			{
				int procenat1;
        	    if(team2[k].fta==0)procenat1=0;
        	    else procenat1=100*team2[k].ftm/team2[k].fta;
        	    return procenat1;
			}
			else if(s=="fg%")
			{
				int procenatP;
        	    if((team2[k].twoa + team2[k].threea)==0)procenatP=0;
            	else procenatP=100*(team2[k].twom + team2[k].threem)/(team2[k].twoa + team2[k].threea);
            	return procenatP;
			}
		}
	}
	else
	{
		if(s=="pts")
		{
			return team1[k].pts;
		}
		else if(s=="ast")
		{
			return team1[k].ast;
		}
		else if(s=="dreb")
		{
			return team1[k].dreb;
		}
		else if(s=="oreb")
		{
			return team1[k].oreb;
		}
		else if(s=="reb")
		{
			return team1[k].oreb+team1[k].dreb;
		}
		else if(s=="stl")
		{
			return team1[k].stl;
		}
		else if(s=="blk")
		{
			return team1[k].blk;
		}
		else if(s=="to")
		{
			return team1[k].to;
		}
		else if(s=="foul")
		{
			return team1[k].foul;
		}
		else if(s=="fould")
		{
			return team1[k].fould;
		}
		else if(s=="2a")
		{
			return team1[k].twoa;
		}
		else if(s=="2m")
		{
			return team1[k].twom;
		}
		else if(s=="%2")
		{
			int procenat2;
            if(team1[k].threea==0) procenat2=0;
            else procenat2=100*team1[k].twom/team1[k].twoa;
            return procenat2;
		}
		else if(s=="3a")
		{
			return team1[k].threea;
		}
		else if(s=="3m")
		{
			return team1[k].threem;
		}
		else if(s=="%3")
		{
			int procenat3;
            if(team1[k].threea==0) procenat3=0;
            else procenat3=100*team1[k].threem/team1[k].threea;
            return  procenat3;
		}
		else if(s=="fta")
		{
			return team1[k].fta;
		}
		else if(s=="ftm")
		{
			return team1[k].ftm;
		}
		else if(s=="ft%")
		{
			int procenat1;
            if(team1[k].fta==0) procenat1=0;
            else procenat1=100*team1[k].ftm/team1[k].fta;
            return procenat1;
		}
		else if(s=="fg%")
		{
			int procenatP;
            if((team1[k].twoa + team1[k].threea)==0)procenatP=0;
            else procenatP=100*(team1[k].twom + team1[k].threem)/(team1[k].twoa + team1[k].threea);
            return procenatP;
		}
	}
	return -1;
}

void BasketGame::SplashEffect(){
	cout<<"****  ****  *     ****  *****  *   *"<<endl;
	cout<<"*     *  *  *     *  *  *      *   *"<<endl;
	cout<<"****  ****  *     ****  *****  *****"<<endl;
	cout<<"   *  *     *     *  *      *  *   *"<<endl;
	cout<<"****  *     ****  *  *  *****  *   *"<<endl;
	Sleep(300);
	system("cls");
	cout<<"******  ******   *       ******  ******  *    *"<<endl;
	cout<<"*       *    *   *       *    *  *       *    *"<<endl;
	cout<<"*       *    *   *       *    *  *       *    *"<<endl;
	cout<<"******  ******   *       ******  ******  ******"<<endl;
	cout<<"     *  *        *       *    *       *  *    *"<<endl;
	cout<<"     *  *        *       *            *  *    *"<<endl;
	cout<<"******  *        ******  *    *  ******  *    *"<<endl;
	Sleep(300);
	system("cls");
	cout<<"********  ********   *         ********  ********  *      *"<<endl;
	cout<<"*         *      *   *         *      *  *         *      *"<<endl;
	cout<<"*         *      *   *         *      *  *         *      *"<<endl;
	cout<<"********  ********   *         ********  ********  ********"<<endl;
	cout<<"       *  *          *         *      *         *  *      *"<<endl;
	cout<<"       *  *          *         *      *         *  *      *"<<endl;
	cout<<"********  *          ********  *      *  ********  *      *"<<endl;
	Sleep(300);
	system("cls");
	cout<<"********  ********   **        ********  ********  **    **"<<endl;
	cout<<"**        **    **   **        **    **  **        **    **"<<endl;
	cout<<"**        **    **   **        **    **  **        **    **"<<endl;
	cout<<"********  ********   **        ********  ********  ********"<<endl;
	cout<<"      **  **         **        **    **        **  **    **"<<endl;
	cout<<"      **  **         **        **    **        **  **    **"<<endl;
	cout<<"********  **         ********  **    **  ********  **    **"<<endl;
	Sleep(300);
	system("cls");
	cout<<"********  ********   **        ********  ********  **    **"<<endl;
	cout<<"********  ********   **        ********  ********  **    **"<<endl;
	cout<<"**        **    **   **        **    **  **        **    **"<<endl;
	cout<<"**        **    **   **        **    **  **        **    **"<<endl;
	cout<<"********  ********   **        ********  ********  ********"<<endl;
	cout<<"********  ********   **        ********  ********  ********"<<endl;
	cout<<"      **  **         **        **    **        **  **    **"<<endl;
	cout<<"      **  **         **        **    **        **  **    **"<<endl;
	cout<<"********  **         ********  **    **  ********  **    **"<<endl;
	cout<<"********  **         ********  **    **  ********  **    **"<<endl;
}
