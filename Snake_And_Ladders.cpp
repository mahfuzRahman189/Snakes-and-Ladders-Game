#include<iostream>
#include <thread>
#include <chrono>
#include <random>
#include<map>
using namespace std;
#define red "\033[1;31m"
#define resetc "\033[1;0m"

int board[10][10];
map<int,int>snakes,ladders;
void setBoard()
{
    int ct=100;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            board[i][j]=ct;
            ct--;
        }
    }

    ladders[5]=48;
    ladders[9]=30;
    ladders[20]=42;
    ladders[25]=58;
    ladders[36]=95;
    ladders[41]=79;
    ladders[49]=71;
    ladders[69]=94;

    snakes[40]=3;
    snakes[53]=10;
    snakes[61]=3;
    snakes[74]=26;
    snakes[85]=28;
    snakes[98]=15;
}
void currentBoard(int pos,int dest)
{

    cout<<"Current Board:\n";
    int det=1;
    for(int i=0;i<10;i++)
    {
        if(det)
        {
            for(int j=0;j<10;j++)
            {
                if(board[i][j]==pos)cout<<red<<'['<<pos<<']'<<resetc<<"\t";
                else cout<<board[i][j]<<"\t";
            }
            cout<<"\n\n";
        }
        else
        {
            for(int j=9;j>=0;j--)
            {
                if(board[i][j]==pos)cout<<red<<'['<<pos<<']'<<resetc<<"\t";
                else cout<<board[i][j]<<"\t";
            }
            cout<<"\n\n";
        }
        det=!det;
    }
    if(pos!=dest){
    this_thread::sleep_for(chrono::milliseconds(500));
    system("cls");

    }
}

int main()
{
    setBoard();
    srand(time(0));
    int position=1;
    int randnum;

    currentBoard(position,position);
    cout<<"Press enter to continue: ";
    cin.get();
    system("cls");

    start:
    randnum = rand() % 6 + 1;
    cout<<"Current turn: "<<randnum<<endl;
    if(position+randnum>100)
    {
        cout<<"Invalid turn"<<endl;
    }
    else{
        for(int i=position;i<=position+randnum;i++)
        {
            if(i!=position)cout<<"Current turn: "<<randnum<<endl;
            currentBoard(i,position+randnum);
        }
        position+=randnum;
    }
    if(snakes[position])
    {
        system("cls");
        cout<<"Snake bit you"<<endl;
        position=snakes[position];
        cout<<"Now you are at "<<position<<endl;
        currentBoard(position,position);
    }
    else if(ladders[position])
    {
        system("cls");
        cout<<"You got a ladder"<<endl;
        position=ladders[position];
        cout<<"Now you are at "<<position<<endl;
        currentBoard(position,position);
    }
    cout<<"Press enter to continue: ";
    cin.get();
    system("cls");
    if(position!=100)goto start;
    else
    {
        cout<<"You won"<<endl;
    }


}
