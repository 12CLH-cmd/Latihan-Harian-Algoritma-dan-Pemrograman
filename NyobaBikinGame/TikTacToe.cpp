#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

void printBoard(const vector<char>& b) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        char c = b[i];
        if (c == ' ') cout << (i+1); else cout << c;
        if (i % 3 != 2) cout << " | ";
        if (i % 3 == 2 && i < 8) cout << "\n---------\n";
    }
    cout << "\n\n";
}

char checkWin(const vector<char>& b) {
    const int lines[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, 
        {0,3,6},{1,4,7},{2,5,8}, 
        {0,4,8},{2,4,6}         
    };
    for (auto &ln : lines) {
        if (b[ln[0]] != ' ' && b[ln[0]] == b[ln[1]] && b[ln[1]] == b[ln[2]])
            return b[ln[0]];
    }
    for (int i = 0; i < 9; ++i) if (b[i] == ' ') return 0; 
    return 'D';
}

int minimax(vector<char>& board, char aiChar, char humanChar, bool isAiTurn) {
    char res = checkWin(board);
    if (res == aiChar) return +10;
    if (res == humanChar) return -10;
    if (res == 'D') return 0;

    if (isAiTurn) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = aiChar;
                int val = minimax(board, aiChar, humanChar, false);
                board[i] = ' ';
                if (val > best) best = val;
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = humanChar;
                int val = minimax(board, aiChar, humanChar, true);
                board[i] = ' ';
                if (val < best) best = val;
            }
        }
        return best;
    }
}

int findBestMove(vector<char>& board, char aiChar, char humanChar) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = aiChar;
            int moveVal = minimax(board, aiChar, humanChar, false);
            board[i] = ' ';
            if (moveVal > bestVal) {
                bestVal = moveVal;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

void humanTurn(vector<char>& board, char humanChar) {
    int pos;
    while (true) {
        cout << "Giliranmu (" << humanChar << "). Masukkan nomor 1-9: ";
        if (!(cin >> pos)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Coba lagi.\n";
            continue;
        }
        if (pos < 1 || pos > 9) {
            cout << "Nomor harus 1-9.\n";
            continue;
        }
        if (board[pos-1] != ' ') {
            cout << "Kotak sudah diisi. Pilih kotak lain.\n";
            continue;
        }
        board[pos-1] = humanChar;
        break;
    }
}

int main() {
    srand((unsigned)time(nullptr));
    cout << "=== Tic-Tac-Toe (Human vs AI) ===\n";
    cout << "Pilih simbolmu (X goes first). Pilih X atau O: ";
    char humanChar;
    while (true) {
        if (!(cin >> humanChar)) return 0;
        if (humanChar == 'X' || humanChar == 'x') { humanChar = 'X'; break; }
        if (humanChar == 'O' || humanChar == 'o') { humanChar = 'O'; break; }
        cout << "Pilih X atau O: ";
    }
    char aiChar = (humanChar == 'X') ? 'O' : 'X';
    bool humanTurnFlag = (humanChar == 'X'); 

    vector<char> board(9, ' ');
    printBoard(board);

    while (true) {
        if (humanTurnFlag) {
            humanTurn(board, humanChar);
        } else {
            cout << "AI (" << aiChar << ") sedang berpikir...\n";
            int mv = findBestMove(board, aiChar, humanChar);
            if (mv == -1) {
                vector<int> freepos;
                for (int i=0;i<9;i++) if (board[i]==' ') freepos.push_back(i);
                if (!freepos.empty()) mv = freepos[rand() % freepos.size()];
            }
            board[mv] = aiChar;
            cout << "AI memilih posisi " << (mv+1) << "\n";
        }

        printBoard(board);
        char res = checkWin(board);
        if (res == humanChar) { cout << "Selamat! Kamu menang!\n"; break; }
        else if (res == aiChar) { cout << "AI menang. Coba lagi!\n"; break; }
        else if (res == 'D') { cout << "Seri!\n"; break; }

        humanTurnFlag = !humanTurnFlag;
    }

    cout << "Game selesai. Terima kasih sudah main!\n";
    return 0;
}
