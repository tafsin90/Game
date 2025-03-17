#include<bits/stdc++.h>
using namespace std;
int player;
char players_guti;
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void draw_board(){
    system("cls");

    cout<<"_____________"<<endl;
    for (int i = 0; i < 3; i++) {
        cout<<"|";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j <=2){
                cout << "|";
            }
        }
        cout << "\n";
        if (i < 2){
            cout << "|---|---|---|"<<endl;
        }
    }
    cout<<"-------------"<<endl;
}

bool available(int slot){
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if(board[row][col]!='x' && board[row][col]!='o'){
        board[row][col]=players_guti;
        return true;
    }
    else{
        return false;
    }
}

int winner(){
    for(int i =0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return player;
        }
    }
    for(int i =0; i<3; i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return player;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return player;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return player;
    }
    return 0;
}
//swap player & marker
void swapGuti(){
    if(players_guti=='x'){
        players_guti='o';
    }
    else{
        players_guti='x';
    }
    if(player==1){
        player=2;
    }
    else{
        player=1;
    }
}

void game(){
    cout<<"what do you want to play with, X or O"<<endl;
    char guti;
    cin>>guti;
    // while(guti!='x' && guti!='o'){
    //     cin>>guti;
    // }
    player=1;
    players_guti=guti;
    draw_board();
    int won;
    for(int i=0; i<9; i++){
        int slot;
        cin>>slot;
        if(slot<1 || slot>9){
            cout<<"Invalid position"<<endl;
            i--;
            continue;
        }
        if(!available(slot)){
            cout<<"Slot occupied"<<endl;
            i--;
            continue;
        }
        draw_board();
        won=winner();
        if (won) {
            cout << "Player " << won << " wins!\n";
            return;
        }
        swapGuti();
    }
    if(won==0){
        cout<<"It's a TIE";
    }

}
int main(){
    game();
return 0;
}
