#ifndef WAVE_H_INCLUDED
#define WAVE_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#define score 50
#include <stdio.h>
#include <fstream>
using namespace std;
int reward=0;
char c;
int count=0;
int number=100;
int n=100;
int random;
int level=0;
void randomize()
{
srand(time(NULL));
random=rand()%(100-1+1)+1;
}
class game
{
public:
    void game_up(void);
    void start_game(int,int,int);
    int  select_level(void);
    void set_level(int);
    void display(void);
    void exit_game(void);
    void error(int);
    void loop_game(int,int,int);
    void counter(int count);
    char qestion(void);
    void win (int&);
    void lose(int&);
    void detect(char);
    void name();
  char name1[100];
  char name2[100];
};
//---------------
fstream file("game.txt",ios::in | ios::out | ios::trunc);
game name;
game player1;
game player2;
//---------------
void game::name()
{
    cout<<"please enter your name:(player1) :";
    gets(player1.name1);
    file<<"player 1           "<<player1.name1<<"             READY...\n\n"
    <<"-------------------------------------------------------------------\n\n";
    cout<<"\n\n\nplease enter your name:(player2) :";
    gets(player2.name2);
    file<<"player 2           "<<player2.name2<<"             READY...\n\n\n";

}
void game::loop_game(int number,int count,int random)
{
    while(1)
{
    system("color F");
cout<<"Enter a number (1 to "<<n<<")"<<" : ";
    cin>>number;
    cout<<endl;
player1.start_game(number,random,count);
--count;
if(count==0){
        player1.lose(reward);
    system("cls");
    system("color c");
cout<<"you lose..."<<endl<<endl<<"answer : "<<random<<endl<<endl<<"score : "<<reward;
break;}
if(number==random){
        player1.win(reward);
    system("cls");
    system("color a");
cout<<endl<<endl<<"you win!!!"<<endl<<endl<<"score : "<<reward;
break;}
}

}
void game::lose(int &reward)
{
    reward=reward-score/2;
}
void game::win(int &reward)
{
    reward=reward+score;
}
void game::start_game(int n,int random,int count)
{

     if(n>random){
        cout<<count<<"-your number too hight...try again"<<endl<<endl;
        }
    if(n<random){
        cout<<count<<"-your number too low...try again"<<endl<<endl;

    }
}

void game::display()
{
     system("color E");
    cout<<setw(42);
    cout<<"please wait";
    for(int i=1;i<=4;i++)
    {
         _sleep(1000);
        cout<<".";
    }
    system("cls");

}
int game::select_level()
{
    char lev;
 system("color F");
    cout<<setw(45)<<"choose your level"<<endl<<endl;
    cout<<"1.Easy"<<endl<<endl
        <<"2.Normal"<<endl<<endl
        <<"3.Hard"<<endl<<endl;
        lev=getch();
       cout<<"your choice : "<<lev<<endl;
        switch(lev)
        {
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        default:
            return -1;
            break;
        }

}
void game::set_level(int l)
{
    switch(l)
    {
    case 1:
        count=8;
        break;
    case 2:
        count=5;
        break;
    case 3:
        count=3;
        break;
    }
}
char game::qestion()
{
    char c;
    cout<<"\n\n\ndo you want to continue?(y,n)";
    c=getche();
    return c;
}
void game::error(int number)
{
    if(number>=1 && number<=3)
        ;
    else{
    system("cls");
    cout<<"your choice out of range...";
    _sleep(3000);
    exit(1);}
}

void game::exit_game()
{
cout<<endl<<endl<<endl<<endl<<"press 'e' to exit...";
char ch=getch();
if(ch=='e')
 system("cls");
}
void game::game_up()
{
    randomize();
    level=player1.select_level();
    player1.set_level(level);
    player1.error(level);
    player1.display();
    player1.loop_game(number,count, random);
    c = player1.qestion();
    player1.detect(c);
}
void game::detect(char c)
{
    if(c=='y' || c=='Y'){
        system("cls");
        system("color F");
       game_up();}
    if(c=='n' || c=='N')
        player1.exit_game();
}

#endif // WAVE_H_INCLUDED
