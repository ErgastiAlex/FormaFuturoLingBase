#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> board(9, '-');

    bool finito = false;

    bool xTurn = true;

    char winner = '-';

    while(finito == false){
        //Stampa
        for(int i=0; i<board.size(); i++){
            cout << board.at(i);
            if((i+1)%3 == 0){
                cout << endl;
            }
        }

        char player = xTurn==true ? 'X' : 'O';

        cout << "E' il turno del giocatore: " << player << endl << "Inserire una posizione (0-8) per giocare: ";
        int pos;
        cin >> pos;
        while(pos < 0 || pos > 8 || board.at(pos)!='-'){
            cout <<"Posizione non valida, inserire una posizione valida! Posizione: ";
            cin >> pos;
        }

        board.at(pos) = player;

        xTurn = !xTurn;

        //Controllo che ci siano ancora posizione libere sulla board
        finito = true;
        for(int i=0; i < board.size(); i++){
            if(board.at(i)=='-'){
                finito=false;
                break;
            }
        }

        for(int i=0; i < 3; i++)
        {
            if(board.at(i*3) != '-' && board.at(i*3)==board.at(i*3+1) && board.at(i*3+1)==board.at(i*3+2)){
                winner = board.at(i*3);
                finito = true;
            }
        }

        for(int i=0; i < 3; i++)
        {
            if(board.at(i) != '-' && board.at(i)==board.at(i+3) && board.at(i+3)==board.at(i+6)){
                winner = board.at(i);
                finito = true;
            }
        }
        if(board.at(0) != '-' && board.at(0) == board.at(4) && board.at(4) == board.at(8))
        {
            winner = board.at(0);
            finito = true;
        }

        if(board.at(2) != '-' && board.at(2) == board.at(4) && board.at(4) == board.at(6)){
            winner = board.at(2);
            finito = true;
        }
    }

    if(winner == '-'){
        cout << "Pareggio!";
    }
    else{
        cout << "Il vincitore è " << winner;
    }


}
