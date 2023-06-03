#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool didP1Win = false;
bool didP2Win = false;

void print_board(string x[6][7])
{
    for (int i = 1; i < 8; i++){
        cout << i << " ";
    }
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j != 6){
                cout << x[i][j] << "|";
            }else{
                cout << x[i][j];
            }
        }
        cout << "|" << i+1 << endl;
        if (i != 5){
            cout << "—————————————|" << endl;
        }
    }
}

bool placePiece(string x[6][7], int col){
    for (int i = 0; i < 7; i++){
        if (i == col){
            if (x[0][col] != "_"){
                return false;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
            if (i == col) {
                int j = 0;
                while (x[j+1][i] == "_") {
                    j++; 
                }
                if (x[j][i] == "_") { 
                    x[j][i] = "0";
                }
                  
            }
        }
        return true;
}

bool didWin(string x[6][7])
{
    bool isWin = false;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (x[i][j] == x[i][j + 1] && x[i][j + 1] == x[i][j + 2] && x[i][j + 2] == x[i][j + 3] && x[i][j] != "_"){
                if (x[i][j] == "X") {
                    didP1Win = true;
                }else if (x[i][j] == "0") {
                    didP2Win = true;
                }
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (x[j][i] == x[j + 1][i] && x[j + 1][i] == x[j + 2][i] && x[j + 2][i] == x[j + 3][i] && x[j][i] != "_") {
                if (x[j][i] == "X") {
                    didP1Win = true;
                }else if (x[j][i] == ("0")) {
                    didP2Win = true;
                }
            }
        }
    }

    for (int i = 5; i >= 3; i--){
        for (int j = 0; j < 2; j++){
            if (x[i][j] == x[i - 1][j + 1] && x[i - 1][j + 1] == x[i - 2][j + 2] 
            && x[i - 2][j + 2] == x[i - 3][j + 3] && x[i][j] != "_") {
                if (x[i][j] == ("X")) {
                    didP1Win = true; 
                } else if (x[i][j] == ("0")){
                    didP2Win = true;
                }
            }
        }
    }

    for (int i = 5; i >= 3; i--) {
        for (int j = 6; j >= 4; j--) {
            if (x[i][j] == (x[i - 1][j - 1]) && x[i - 1][j - 1] == (x[i - 2][j - 2]) && x[i - 2][j - 2] == (x[i - 3][j - 3])) {
                if (x[i][j] == ("X")) {
                    didP1Win = true;
                } else if (x[i][j] == ("0")) {
                    didP2Win = true;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (x[i][j] == (x[i + 1][j + 1]) && x[i + 1][j + 1] == (x[i + 2][j + 2]) && x[i + 2][j + 2] == x[i + 3][j + 3]) {
                if (x[i][j] == ("X")) {
                    didP1Win = true;
                } else if (x[i][j] == ("0")) {
                    didP2Win = true;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 6; j > 3; j--){
            if (x[i][j] == (x[i + 1][j - 1]) && x[i + 1][j - 1] == (x[i + 2][j - 2]) && x[i + 2][j - 2] == (x[i + 3][j - 3])) {
                if (x[i][j] == ("X")) {
                    didP1Win = true;
                } else if (x[i][j] == ("0")){
                    didP2Win = true;
                }
            }
        }
    }

    if (didP1Win || didP2Win) {
        isWin = true;
    }

    return isWin;
}

bool compPlay(string x[6][7])
{
    bool didplay = false;

    if (didplay) return true;

    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 4; j++)
        {
            if (x[i][j] == x[i][j + 1] && x[i][j + 1] == x[i][j + 2] && x[i][j] == "X")
            {
                if (x[i][j+3] == "0")
                {
                    didplay = false;
                }
                else if (j + 3 < 7) 
                {
                    //x[i][j+3] = "0";
                    placePiece(x, j+3);
                    didplay = true;
                }
                else if (j + 3 > 7) 
                {
                    //x[i][j-1] = "0";
                    placePiece(x, j-1);
                    didplay = true;
                }
            }

            if ((x[i][j] == x[i][j + 2] && x[i][j + 2] == x[i][j + 3] && x[i][j] == "X"))
            {
                if (x[i+1][j+1] == "_")
                {
                    didplay = false;
                }
                else if (x[i][j+1] == "_")
                {
                    placePiece(x, j+1);
                    didplay = true;
                }
            }
            if ((x[i][j+1] == x[i][j + 2] && x[i][j + 2] == x[i][j + 3] && x[i][j] == "X"))
            {
                if (x[i+1][j] == "_")
                {
                    didplay = false;
                }
                else if (x[i][j] == "_")
                {
                    placePiece(x, j);
                    didplay = true;
                }
            }
        }
    }

    if (didplay) return true;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 6; j > -1; j--)
        {
            if (x[i][j] == x[i][j-1] && x[i][j-1] == x[i][j-2] && x[i][j] == "X")
            {
                if (x[i][j-3] == "_")
                {
                    x[i][j-3] = "0";
                    didplay = true;
                }
            }
        }
    }
    
    if (didplay) return true;

    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 3; j++) {
            if (x[j][i] == x[j + 1][i] && x[j + 1][i] == x[j + 2][i] && x[j][i] == "X" && x[j-1][i] == "_" && !didplay) 
            {
                if (j - 1 >= 0) 
                {
                    placePiece(x, i);
                    // cout<<"e"<<endl;
                    didplay = true;
                }
            }
        }
    }

    if (didplay) return true;

    for (int i = 5; i >= 3; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (x[i][j] == x[i - 1][j + 1] && x[i - 1][j + 1] == x[i - 2][j + 2] && x[i][j] == "X") 
            {
                if (x[i-3][j+3] == ("_") ) 
                {
                    if (x[i-3][j+3] == "_")
                    {
                        //x[i-3][j+3] = "0";
                        placePiece(x, j+3);
                        // cout<<"re"<<endl;
                        didplay = true;
                    }
                    if (x[i-1][j+3] == "_" && !didplay)
                    {
                        //x[i-1][j+3] = "0";
                        placePiece(x, j+3);
                        // cout<<"em"<<endl;
                        didplay = true; 
                    }
                } 
            }
        }
    }

    if (didplay) return true;

    for (int i = 5; i >= 3; i--) 
    {
        for (int j = 6; j >= 4; j--) 
        {
            if (x[i][j] == (x[i - 1][j - 1]) && x[i - 1][j - 1] == (x[i - 2][j - 2]) 
                && x[i][j] == "X") 
                {
                if (x[i-3][j-3] == ("_") || x[i-1][j-3] == ("_")) 
                {
                    //x[i-3][j-3] = "0";
                    placePiece(x, j-3);
                    // cout<<"ye"<<endl;
                    didplay = true;
                }
            }
        }
    }

    if (didplay) return true;

    if (!didplay)
    {
        int col = (rand() % 7);
        //cout<<col<<endl;
        while (!placePiece(x, col))
        {
            col = (rand() % 7);
            placePiece(x,col);
        }
        // cout<<"a"<<endl;
        didplay = true;
    }

    return didplay;
}

int main(int argc, const char *argv[])
{
    string x[6][7]; 
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            x[i][j] = "_";
        }
    }

    cout<<"Select gamemode. '1' for 2 players and '2' for single player. "<<endl;


    int asdf = -1;
    cin >> asdf;

    if (asdf == 1){

        print_board(x);

        int counter = 0;
        while (counter < 42 && !didWin(x))
        {
            cout << "Player 1, enter a column number from 1 to 7," << endl;
            int x1;
            cin >> x1;
            x1--;

            while (x1 < 0 || x1 > 6){
                    cout << "Invalid input, enter a number between 1 and 7" <<endl;
                    cin >> x1;
                    x1--;
                }

            for (int i = 0; i < 7; i++)
            {
                if (i == x1)
                {
                    int j = 0;
                    while (x[j+1][i] == "_"){
                        j++;
                    }
                    if (x[j][i] != "_")
                    {
                        cout<<"Invalid move"<<endl;
                    }
                    else
                    {
                        x[j][i] = "X";
                    }
                }
            }

            print_board(x);
            cout << "Player 1 played" << endl;

            if (!didWin(x))
            {
                cout << "Player 2, enter a column number from 1 to 7" << endl;
                int x2;
                cin >> x2;
                x2--;

                while (x2 < 0 || x2 > 6){
                    cout << "Invalid input, enter a number between 1 and 7" <<endl;
                    cin >> x2;
                    x2--;
                }

                for (int i = 0; i < 7; i++)
                {
                    if (i == x2)
                    {
                        int j = 0;
                        while (x[j+1][i] == "_")
                        {
                            j++;
                        }
                        if (x[j][i] != "_")
                        {
                            cout<<"Invalid move"<<endl;
                        }
                        else
                        {
                            x[j][i] = "0";
                        }
                    }
                }
                

                print_board(x);
                cout << "Player 2 played" << endl;
            }
        }
    }
    else{
        print_board(x);
        int counter = 0;
        while (counter < 42 && !didWin(x))
        {
            cout << "Player 1, enter a column number from 1 to 7," << endl;
            int x1;
            cin >> x1;
            x1--;

            while (x1 < 0 || x1 > 6)
            {
                cout << "Invalid input, enter a number between 1 and 7" <<endl;
                cin >> x1;
                x1--;
            }

            for (int i = 0; i < 7; i++)
            {
                if (i == x1)
                {
                    int j = 0;
                    while (x[j+1][i] == "_")
                    {
                        j++;
                    }
                    if (x[j][i] != "_")
                    {
                        cout<<"Invalid move"<<endl;
                    }
                    else
                    {
                        x[j][i] = "X";
                    }
                }
            }

            print_board(x);
            cout << "Player 1 played" << endl;

            if (!didWin(x))
            {
                bool temp = compPlay(x);
                cout <<"Computer played" <<endl;
                print_board(x);
            }
        }
    }


    if (didP1Win)
    {
        cout << "Congrats P1";
    }
    else if (didP2Win)
    {
        cout << "Congrats P2";
    }
    else{
        cout << "Draw";
    }
}