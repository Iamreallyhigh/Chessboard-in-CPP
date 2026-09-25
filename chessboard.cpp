#include<iostream>
#include<iomanip>
using namespace std;

// classes can be used for the piece construction, using moves, values
// check is not added yet
// need to add that allied pieces cannot be captured, and that the king cannot move into check


char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

void printBoard() {
    cout << "    a  b  c  d  e  f  g  h" << endl << "------------------------------" << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << "   ";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << "  ";
        }
        cout << " " << 8 - i << endl;
    }
    cout << "------------------------------" << endl << "    a  b  c  d  e  f  g  h" << endl;
}

void getmove(int *r0, int *r1, int *p0, int *p1) {
    char c0, c1;
    int tr0, tr1;
    cout << "Enter your move: ";
    cin >> c0 >> tr0 >> c1 >> tr1;

    // turn into array coordinates
    *r0 = 8 - tr0;
    *r1 = 8 - tr1;
    *p0 = c0 - 'a';
    *p1 = c1 - 'a';

    // values are written through the pointers back to main
}

bool valid(int *r0, int *r1, int *p0, int *p1) {
    // it should use switch or if-elseif logic to validate the move.
    if (board[*r0][*p0] == '.') {
        cout << "Empty square selected!" << endl;
        return false; // no piece at source
    }
    if (*r1 < 0 || *r1 > 7 || *p1 < 0 || *p1 > 7) {
        cout << "Going off-board!" << endl;
        return false; // destination out of bounds
    }
    if (*r1==*r0 && *p0==*p1) {
        cout << "No move made!" << endl;
        return false;
    }
    //could used switch or isupper/islower but i did'nt remember they exist haha
    if ((board[*r0][*p0]=='p' || board[*r0][*p0]=='q' || board[*r0][*p0]=='k' || board[*r0][*p0]=='r' || board[*r0][*p0]=='b' || board[*r0][*p0]=='n') && (board[*r1][*p1]=='p' || board[*r1][*p1]=='q' || board[*r1][*p1]=='k' || board[*r1][*p1]=='r' || board[*r1][*p1]=='b' || board[*r1][*p1]=='n')){return false;}
    if ((board[*r0][*p0]=='P' || board[*r0][*p0]=='Q' || board[*r0][*p0]=='K' || board[*r0][*p0]=='R' || board[*r0][*p0]=='B' || board[*r0][*p0]=='N') && (board[*r1][*p1]=='P' || board[*r1][*p1]=='Q' || board[*r1][*p1]=='K' || board[*r1][*p1]=='R' || board[*r1][*p1]=='B' || board[*r1][*p1]=='N')){return false;}

    if (board[*r0][*p0] == 'p') {
        if (*r1==*r0-1 && *p1==*p0 && board[*r1][*p1]=='.'){return true;}
        if (*r1==*r0-2 && *p1==*p0 && *r0==6 && board[*r1][*p1]=='.'){return true;} //can jump over in this case - will be fixed out later
        if (*r1==*r0-1 && (*p1==*p0-1 || *p1==*p0+1) && board[*r1][*p1]!='.'){return true;}
        // add en-passant, too! you would need a "last move" memory for that
        return false;
    }
    if (board[*r0][*p0] == 'P') {
        if (*r1==*r0+1 && *p1==*p0 && board[*r1][*p1]=='.'){return true;}
        if (*r1==*r0+2 && *p1==*p0 && *r0==1 && board[*r1][*p1]=='.'){return true;} //can jump over in this case - will be fixed out later
        if (*r1==*r0+1 && (*p1==*p0-1 || *p1==*p0+1) && board[*r1][*p1]!='.'){return true;}
        // add en-passant, too! you would need a "last move" memory for that
        return false;
    }
    if (board[*r0][*p0] == 'b' || board[*r0][*p0] == 'B') {
        //can jump over pieces for now
        if (abs(*r1-*r0)==abs(*p1-*p0)){
            return true;}
        return false;
    }
    if (board[*r0][*p0] == 'r' || board[*r0][*p0] == 'R'){
        //can jump over pieces for now
        if (abs(*r1-*r0)!=0 && abs(*p1-*p0)!=0){return false;}
    }
    if (board[*r0][*p0] == 'q' || board[*r0][*p0] == 'Q'){
        //can jump over pieces for noq
        if (abs(*r1-*r0)==abs(*p1-*p0)){return true;}
        if (abs(*r1-*r0)!=0 && abs(*p1-*p0)!=0){return false;}
    }
    if (board[*r0][*p0] == 'k' || board[*r0][*p0] == 'K'){
        if (abs(*r1-*r0)==1 || abs(*p1-*p0)==1){return true;}
        return false;
    }
    if (board[*r0][*p0] == 'n' || board[*r0][*p0] == 'N'){
        if (abs(*r1-*r0)<3 && (abs(*r1-*r0)!=0 && abs(*p1-*p0)!=0) && abs(*r1-*r0)!=abs(*p1-*p0)){return true;}
        return false;
    }
    
    return true;
}

bool checkmate() {
    // if king is in check and has no valid moves, checkmate
    return false;
}

void promote(int *r1, int *p1) {
    char choice;
    if (board[*r1][*p1] == 'P') {
    cout << "Promote pawn to (Q, R, B, N): ";
    cin >> choice;
    if (choice != 'Q' && choice != 'R' && choice != 'B' && choice != 'N') {
        cout << "Invalid choice. Promoting to Queen by default." << endl;
        choice = 'Q';}
    }
    else{
        cout << "Promote pawn to (q, r, b, n): ";
        cin >> choice;
        if (choice != 'q' && choice != 'r' && choice != 'b' && choice != 'n') {
            cout << "Invalid choice. Promoting to queen by default." << endl;
            choice = 'q';}
    }
    board[*r1][*p1] = choice;
}


void move(int *r0, int *r1, int *p0, int *p1){
    // move piece from source (*r0,*p0) to destination (*r1,*p1)
    board[*r1][*p1] = board[*r0][*p0];
    board[*r0][*p0] = '.';
}

bool draw() {
    // 3fold repetition, 50-move rule, stalemate, insufficient material
    return false;
}

bool casepromotion(int *r1, int *p1, int *r0) {
    // check if a pawn has reached the last rank
    if (board[*r1][*p1] == 'P' && *r1 == 7 && *r0 == 6) {
        return true;
    }
    if (board[*r1][*p1] == 'p' && *r1 == 0 && *r0 == 1) {
        return true;
    }
    return false;
}

int main() {
    int r0, r1, p0, p1;
    int i=0, j=0, k=0;
    system("cls");
    cout << "White to play!" << endl;
    cout << "Move number: " << j << endl;
    printBoard();
    while(i<2){
        getmove(&r0, &r1, &p0, &p1);
        if (!valid(&r0, &r1, &p0, &p1)) {
            cout << "Invalid move!" << endl;
            continue;}
        k++;
        move(&r0, &r1, &p0, &p1);
        if (casepromotion(&r1, &p1, &r0)){promote(&r1, &p1);}
        system("cls");
        if(k==2){j++; k=0;}
        if (k==0) {cout << "White to play!" << endl;}
        else {cout << "Black to play!" << endl;}
        cout << "Move number: " << j << endl;
        printBoard();
        if (checkmate()) {
            cout << "Checkmate! Game over." << endl;
            i=3;
        }
        if (draw()) {
            cout << "Draw! Game over." << endl;
            i=3;
        }
    }

    return 0;
}