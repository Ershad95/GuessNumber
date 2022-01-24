#include "ershad.wave.h"

int main()
{
name.name();system("cls");
cout<<"player1 : "<<player1.name1<<endl;
    player1.game_up();
    system("cls");
    cout<<"your score : "<<reward<<setw(20)<<"c : continue...";getch();system("cls");
    int reward1=reward;
    reward=0;
cout<<"player2 : "<<player2.name2<<endl;
    player2.game_up();
    system("cls");
    cout<<"your score : "<<reward<<setw(20)<<"c : continue...";getch();system("cls");
    int reward2=reward;
    if(reward1>reward2){
        cout<<"winer : "<<player1.name1;}
    else if(reward2>reward1){
        cout<<"winer : "<<player2.name2;}
    if(reward1==reward2){
        cout<<"winer : "<<player1.name1<<" , "<<player2.name2;}
        file<<"RESULT.....\n\n";
        file<<player1.name1<<"         "<<reward1<<"\n\n"<<player2.name2<<"         "<<reward2;
    file.close();
   return 0;
}
