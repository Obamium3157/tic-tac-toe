#include <iostream>

int columns = 3, rows = 3;
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

std::string fill(State state) {
    switch (state) {
        case EMPTY:
            return "[ ]";
        case X:
            return "[X]";
        case ZERO:
            return "[0]";
            
        default:
            return "[ ]";
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

void refill(int colN, int rowN) {
    // system("clear");
//    for(int i = 0; i < columns; i++) {
//        for(int j = 0; i < rows; i++) {
//            if(colN == i && rowN == j)
//                std::cout << fill(turn()) << " ";
//            else {
//                std::cout << fill(EMPTY) << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
    
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            if((j == rowN) && (i == colN))
                std::cout << fill(turn()) << " ";
            else {
                std::cout << fill(EMPTY) << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    int colN, rowN;
    reveal_field();
    
    while(true) {
        std::cout << "Enter column number: ";
            // TODO:  сделать проверку правильности ввода
            std::cin >> colN;
            std::cout << "Enter row number: ";
            std::cin >> rowN;
            
            refill(colN, rowN);
    }
    
    
    return 0;
}
