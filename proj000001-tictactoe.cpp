/* PROJECT : TIC TAC TOE GAME */
/* This C++ program on TIC TAC TOE GAME is a simple text base game. */
/* This program is without graphics to focus on logic /algorithm used in game. */
/* Two players can play this game. */

#include <iostream>
#include <cstring>

using namespace std;

int getNumber (char t[], int p, int &u){
    char s[256];
    int n;

    while (true){
        cin.getline (s,256);

        if (strlen(s)>1 || s[0]<'1' || s[0]>'9'){
            cout << "Invalid entry! Please try again : ";
            continue;
        }

        n = s[0] - 49;
        if (t[n]=='X' || t[n]=='O'){
            cout << "Position occupied! Please try again : ";
            continue;
        }

        t[n] = (p==1) ? 'X' : 'O';
        u -= n;
        return n;
    }
}

bool isWin (char t[], int n) {
    int i, j;

    i = n / 3 * 3; // Horizontal Win
    j = n % 3;     // Vertical Win

    if ((t[i] == t[i+1] && t[i] == t[i+2]) ||
        (t[j] == t[j+3] && t[j] == t[j+6])) return true;

    // Check for diagonal win
    if (!(n%2) &&
        ((t[0] == t[4] && t[4] == t[8]) ||
         (t[2] == t[4] && t[4] == t[6])) ) return true;

    return false;
}

void printBoard (char t[]) {
    int i, j;

    for (i=0; i<=6; i+=3){
        cout << "-----------------" << endl
             << "     |     |     " << endl;

        for (j=0; j<=2; j++){
            cout << "  " << t[j+i] << "  ";
            if (j!=2) cout << "|";
            }
        cout << endl << "     |     |     " << endl;
    }
    cout << endl;
}

int main (){
    char tac[9], start  [30];
    int number, turn, unoccupied, player, i;

 do {
    cout << "Tic-Tac-Toe !" << endl << "Player 1 (X) VS Player 2 (O)" << endl;
    for (i=0; i<9; i++) tac[i] = 49 + i;
    printBoard (tac);

    for (turn=1, unoccupied=36; turn <=8; turn++){
        player = (turn%2) ? 1 : 2;
        cout << "Player " << player << ", please enter a number : ";
        number = getNumber (tac, player, unoccupied);
        printBoard (tac);

        if (turn>4) // Check for win only after 4th turn
            if (isWin (tac, number)) {
                cout << "Player " << player << " wins !" << endl;
                break;
            }
        }

    if (turn==9){ // Automatically fill in the entry on the 9th turn
        cout << "Player 1 enters "<< (unoccupied+1) << endl;
        tac [unoccupied] = 'X';
        printBoard (tac);

        if (isWin (tac, unoccupied))
            cout << "Player 1 wins !" << endl;
        else cout << "It's a draw ..." << endl;
        }

    cout << "Press any key to play again or 0 (zero) to exit : ";
    cin.getline (start,30);
    cout << endl;

    } while (!(strlen(start)==1 && start[0]=='0'));

    return 0;
}
