#include "Board.hpp"
using namespace std;

uint Board::size[512] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 
    3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 
    4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 
    6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 
    3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 
    5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 
    6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 
    6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 
    4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 
    6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 
    6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 3, 4, 4, 5, 4, 5, 5, 
    6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 5, 
    6, 6, 7, 6, 7, 7, 8, 6, 7, 7, 8, 7, 8, 8, 9};

Board::Board() : Board("000000000000000000000000000000000000000000000000000000000000000000000000000000000")
{
}

Board::Board(string sudoku){
    for(uint i = 0; i < 81; i++){
        uint val = (sudoku[i] == '0') ? 511u : 1 << (sudoku[i] - '1');
        this->setChoices(i, val);
    }
    this->solve();
}

void Board::addChoice(uint i, uint n){
    assert(n > 0 and n < 10);
    assert(i < 81);
    cell[i] |= (1 << (n - 1));
    cell[i] %= 512;
}

void Board::discardChoice(uint i, uint n){
    assert(n < 10 and n > 0);
    assert(i < 81);
    cell[i] &= (~(1 << (n - 1)));
    cell[i] %= 512;
}

void Board::setChoices(uint i, uint val){
    assert(i < 81);
    cell[i] = val % 512;
}

uint Board::getChoices(uint i){
    assert(i < 81 and cell[i] < 512);
    return cell[i];
}

uint Board::status(){
    bool solved = true;
    for(uint i = 0; i < 81; i++){
        if(this->getSize(i) == 0){
            return UNSOLVABLE;
        }
        else if(this->getSize(i) > 1){
            solved = false;
        }
    }
    return solved ? SOLVED : SOLVABLE;
}

uint Board::leastSizeIndex(){
    assert(this->status() != UNSOLVABLE);
    uint l = 0, size = 10, iSize;
    for(uint i = 0; i < 81; i++){
        iSize = this->getSize(i);
        if(iSize > 1 and iSize < size){
            l = i;
            size = iSize;
        }
    }
    assert(l < 81);
    return l;
}

void Board::solve(){
    uint count1 = 0, count2 = 0;
    for(uint i = 0; i < 81; i++){
    	count1 += (this->getSize(i) == 1);
    }
    for(uint i = 0; i < 81; i++){
        if(this->getSize(i) == 1){
            uint val = this->valueAt(i), row = i / 9, col = i % 9;
            for(uint j = 0; j < 9; j++){
                this->discardChoice(row * 9 + j, val); //discarding val from all cells of row
                this->discardChoice(j * 9 + col, val); //discarding val from all cells of column
                this->discardChoice((row / 3 * 3 + j / 3) * 9 + col / 3 * 3 + j % 3, val);
                                                       //discarding val from all cells of block
            }
            this->addChoice(i, val); //re-adding val to the original cell with single choice
        }
    }
    for(uint i = 0; i < 81; i++){
    	count2 += (this->getSize(i) == 1);
    }
    if(count2 > count1){
    	this->solve();
    }
}

uint Board::getSize(uint i){
    assert(i < 81);
    assert(cell[i] < 512);
    return Board::size[cell[i]];
}

istream& operator>>(istream& input, Board& b){
	char ch;
    string s;
    while(s.length() < 81 and input >> ch){
        ch = (ch == '.') ? '0' : ch;
        if(isdigit(ch))
            s += ch;
    }
    b = Board(s);
    return input;
}

ostream& operator<<(ostream& output, Board& b){
    string seperator = "+-------+-------+-------+\n";
    output << endl;
    for(uint i = 0; i < 81; i++){
        if(i % 27 == 0){
            output << seperator;
        }
        if(i % 3 == 0){
            output << "| ";
        }
        cout << b.valueAt(i) << " ";
        if(i % 9 == 8){
            output << "|\n";
        }
    }
    output << seperator;
    return output;
}

uint Board::valueAt(uint i){
    //assert(this->getSize(i) == 1);
    assert(i < 81);
    assert(cell[i] < 512);
    uint counter = 1, num = cell[i], output = 0;
    while(num > 0){
        output = (num % 2 == 1) ? 10 * output + counter : output;
        num /= 2;
        counter++;
    }
    return output;
}
