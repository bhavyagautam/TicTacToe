#include <iostream>
using namespace std;

void playAreaTemplate(){

    for (int i = 0; i < 9; i++)
    {
        if((i+1)%3==0){
            cout<<i+1<<"\n";
            if(i!=8)
            cout<<"-----"<<"\n";
        }
        else{
            cout<<i+1<<"|";
        }
    }
    cout<<endl;
}

void playArea(char game[]){
    for (int i = 0; i < 9; i++)
    {
        if((i+1)%3==0){
            cout<<game[i]<<"\n";
            if(i!=8)
            cout<<"-----"<<"\n";
        }
        else{
            cout<<game[i]<<"|";
        }
    }
    cout<<"\n";    
}

void resetGame(char game[]){
    for (int i = 0; i < 9; i++)
    {
        game[i]=' ';
    }
    
}

void turn(char game[],char sym,int val){
    game[val]=sym;
}

int checkWin(char game[]){
    int cnt=0;
    cnt=0;
    //checking for columns
    for (int j = 0; j < 3; j++)
    {
        for (int i = j; i < 9; i+=3)
        {
            if(game[i]=='X'){
                cnt++;
            }
            else if(game[i]=='O'){
                cnt--;
            }
        }
        if(cnt==3){
            cout<<"X won by column!";
            return 1;
        }
        else if (cnt==-3)
        {
            cout<<"O won by column!";
            return 1;
        }
        cnt=0;
    }
    
    //checking for rows
    cnt=0;
    for (int j = 0; j < 9; j+=3)
    {
       for (int i = j; i < j+3; i++)
       {
           if(game[i]=='X'){
                cnt++;
            }
            else if(game[i]=='O'){
                cnt--;
            }
       }
       if(cnt==3){
            cout<<"X won by row!";
            return 1;
        }
        else if (cnt==-3)
        {
            cout<<"O won by row!";
            return 1;
        }
       cnt=0;
    }

    //checking for left diagonal
    cnt=0;
    for (int i = 0; i < 9; i+=4)
    {
        if(game[i]=='X'){
            cnt++;
        }
        else if(game[i]=='O'){
            cnt--;
        } 
             
    }
    if(cnt==3){
        cout<<"X won by left diagonal!";
        return 1;
    }
    else if (cnt==-3)
    {
        cout<<"O won by left diagonal!";
        return 1;
    }

    //checking for right diagonal
    cnt=0;
    for (int i = 2; i < 7; i+=2)
    {
        if(game[i]=='X'){
            cnt++;
        }
        else if(game[i]=='O'){
            cnt--;
        } 
             
    }
    if(cnt==3){
        cout<<"X won by right diagonal!";
        return 1;
    }
    else if (cnt==-3)
    {
        cout<<"O won by right diagonal!";
        return 1;
    } 
    
    return 0;
}

void twoPlayerGame(){
    char game[9],sym;
    int status[9],t=0,val,cnt=0;;
    bool notRunning=0;
    float tempVal;
    for (int i = 0; i < 9; i++)status[i]=0;
    
    resetGame(game);
    
    
    while (!notRunning && cnt<9)
    {
        if(t==0){
            cout<<"Turn of first player"<<endl;
            sym='X';
            t=1;
        }
        else{
            cout<<"Turn of second player"<<endl;
            sym='O';
            t=0;
        }
        playAreaTemplate();
        playArea(game);
        //to check if the position hasn't already been played
        do{
        cout<<endl<<"Which position?";
        cin>>tempVal;
        val=tempVal;//to accomodate float type
        if(val<1 || val >9)cout<<"Value not in range, try again.";
        if(status[val-1]==1)cout<<"Already taken position, try again.";
        }while(status[val-1]==1 || val<1 || val>9);

        turn(game,sym,val-1);
        status[val-1]=1;
        notRunning=checkWin(game);
        cnt++;
    }
    if(cnt==9 && notRunning==0)cout<<"TIE!";
    cout<<endl;
    playArea(game);
}

int main(){
    
    cout<<"TIC-TAC-TOE"<<endl;
    twoPlayerGame();      
    return 0;
}