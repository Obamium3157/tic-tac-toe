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

bool isVictory() {
    for(int c = 0; c < columns; c++) {
        if((memory[c][0] == memory[c][1]) && (memory[c][0] == memory[c][2]) && memory[c][0] != 0)
            return true;
        else
            continue;
    }
    
    for(int r = 0; r < rows; r++) {
        if((memory[0][r] == memory[1][r]) && (memory[0][r] == memory[2][r]) && (memory[0][r] != 0))
            return true;
        else
            continue;
    }
    
    return false;
}

bool isDraw() {
    for(int c = 0; c < columns; c++) {
        for(int r = 0; r < rows; r++) {
            if(memory[c][r] != 0)
                continue;
            else
                return false;
        }
    }
    
    return true;
}

State turn() {
    if(player == FIRST) {
        player = SECOND;
        return X;
    } else {
        player = FIRST;
        return ZERO;
    }
}

void changePlayer() {
    if(player == FIRST)
        player = SECOND;
    else
        player = FIRST;
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
    system("clear");
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
    system("clear");
    memory[rowN][colN] = switchTurn(turn());
    
    for(int c = 0; c < columns; c++) {
        for(int r = 0; r < rows; r++) {
            std::cout << fill(smth(memory[c][r])) << " ";
        }
        std::cout << "\n";
    }
}

int input(std::string message) {
    std::cout << message << std::endl;
    int x;
    std::cin >> x;
    if((0 < x) && (x < 4))
        return x - 1;
    else
        input(message);
    return 0;
}

void printWinner() {
    if(player == FIRST)
        std::cout << "First";
    else
        std::cout << "Second";
    std::cout << " player win!\n";
}

void printPlayer() {
    if(player == FIRST)
        std::cout << "Ход первого игрока\n";
    else {
        std::cout << "Ход второго игрока\n";
    }
}

void printDraw() {
    std::cout << "Ничья!\n";
}

int main(int argc, const char * argv[]) {
    int colN, rowN;
    reveal_field();
    
    while(inGame) {
        if(isVictory()) {
            changePlayer();
            printWinner();
            return 0;
        }
        if(isDraw()) {
            printDraw();
            return 0;
        }
        
        printPlayer();
        
        colN = input("Enter column number:");
        rowN = input("Enter row number: ");
            
        refill(colN, rowN);
    }
    
    
    return 0;
}
