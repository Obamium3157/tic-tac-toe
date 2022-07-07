#include <iostream>

int columns = 3, rows = 3;
bool inGame = true;
int memory[3][3] = { // 0 = EMPTY, 1 = X, 2 = ZERO
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
};
enum State { EMPTY, X, ZERO };
enum Player { FIRST, SECOND };
Player player = FIRST;

State turn() {
    if(player == FIRST) {
        player = SECOND;
        return X;
    } else {
        player = FIRST;
        return ZERO;
    }
}

int switchTurn(State state) {
    switch(state) {
        case X:
            return 1;
            break;
        case ZERO:
            return 2;
        case EMPTY:
            return 0;
    }
}

int switchTurn() {
    switch(player) {
        case FIRST:
            return 1;
            break;
        case SECOND:
            return 2;
            break;
    }
}

std::string fill(State state) {
    switch (state) {
        case EMPTY:
            return "[ ]";
            break;
        case X:
            return "[X]";
            break;
        case ZERO:
            return "[0]";
            break;
            
        default:
            return "[ ]";
            break;
    }
}

void reveal_field() {
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            std::cout << fill(EMPTY) << " ";
        }
        std::cout << "\n";
    }
}

State smth(int index) {
    switch(index) {
        case 0:
            return EMPTY;
            break;
        case 1:
            return X;
            break;
        case 2:
            return ZERO;
            break;
            
        default:
            return EMPTY;
            break;
    }
}

void refill(int colN, int rowN) {
    memory[rowN][colN] = switchTurn(turn());
    
    for(int c = 0; c < columns; c++) {
        for(int r = 0; r < rows; r++) {
            std::cout << fill(smth(memory[c][r])) << " ";
        }
        std::cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    int colN, rowN;
    reveal_field();
    
    while(true) {
        std::cout << "Enter column number: ";
        // TODO:  сделать проверку правильности ввода
        std::cin >> colN;
        colN--;
        std::cout << "Enter row number: ";
        std::cin >> rowN;
        rowN -= 1;
            
        refill(colN, rowN);
    }
    
    
    return 0;
}
