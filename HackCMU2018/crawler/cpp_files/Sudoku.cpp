#include "Sudoku.h"

using namespace std;

int Sudoku::answer = 0;
int Sudoku::depth = 0;

Sudoku::Sudoku() {
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++)
            map_inp[i*12+j] = 0;           
    }
}

Sudoku::Sudoku(int *map, int ans, int depth) {
	for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++)
            map_inp[i*12+j] = map[i*12+j];   
    }

    SetAnswer(ans);
    Solve();
}

// Output the result.
void Sudoku::Result() {
    if (answer == 1) {
        for (int i = 0; i < 144; i++) {
            if (map_inp[i] == 0) {
                 cout << "2" << endl;
                 break;
            }
        }

        cout << "1" << endl;
        for (int i = 0; i < 144; i++) {
            if ((i+1) % 12)
                cout << map_inp[i] << " ";
            else
                cout << map_inp[i] << endl;
        }
    }
    else if (answer > 1)
        cout << "2" << endl;
    else
        cout << "0" << endl;
}

// GiveInitial
void Sudoku::GiveInitial() {
	int map_init[144] = {
		0, 0, 0, 8, 0, 3, 0, 5, 0, -1, -1, -1, 
		0, 0, 3, 0, 0, 0, 6, 0, 4, -1, -1, -1,
		9, 0, 1, 0, 2, 0, 8, 0, 0, -1, -1, -1,
		-1, -1, -1, 0, 3, 0, 0, 8, 7, 0, 5, 0,
		-1, -1, -1, 0, 0, 0, 0, 0, 0, 4, 0, 0,
		-1, -1, -1, 4, 0, 6, 0, 3, 0, 0, 7, 0,
		1, 0, 0, 0, 0, 0, -1, -1, -1, 6, 9, 5,
		0, 0, 4, 0, 0, 0, -1, -1, -1, 1, 3, 7,
		0, 9, 5, 0, 1, 0, -1, -1, -1, 2, 8, 4,
		3, 0, 0, -1, -1, -1, 0, 4, 0, 5, 0, 0,
		7, 0, 8, -1, -1, -1, 0, 0, 9, 0, 0, 2,
		0, 6, 0, -1, -1, -1, 3, 1, 0, 0, 0, 8};

    for (int i = 0; i < 144; i++)
        map_out[i] = map_init[i];

    Random();
}

// RandomSwapRow1
void Sudoku::RandomSwapRow1(int a, int b) {
    int tmp[36] = {0};
    for (int i = a, j = 0; i < a+36 && j < 36; i++, j++)
        tmp[j] = map_out[i];

    for (int i = b, j = a; i < b+36 && j < a+36; i++, j++)
        map_out[j] = map_out[i];

    for (int i = b, j = 0; i < b+36 && j < 36; i++, j++)
        map_out[i] = tmp[j];
}

// RandomSwapRow2
void Sudoku::RandomSwapRow2(int a, int b) {
    int tmp[12] = {0};
    for (int i = a, j = 0; i < a+12 && j < 12; i++, j++)
        tmp[j] = map_out[i];

    for (int i = b, j = a; i < b+12 && j < a+12; i++, j++)
        map_out[j] = map_out[i];

    for (int i = b, j = 0; i < b+12 && j < 12; i++, j++)
        map_out[i] = tmp[j];
}

// RandomSwapCol1
void Sudoku::RandomSwapCol1(int a, int b) {
    int tmp[36] = {0};
    for (int k = 0; k < 3; k++) {
        for (int i = a+k, j = k*12; i <= (a+k)+12*11 && j < (k+1)*12; i+=12, j++)
            tmp[j] = map_out[i];

        for (int i = b+k, j = a+k; i <= (b+k)+12*11 && j <= (a+k)+12*11; i+=12, j+=12)
            map_out[j] = map_out[i];

        for (int i = b+k, j = k*12; i <= (b+k)+12*11 && j < (k+1)*12; i+=12, j++)
            map_out[i] = tmp[j];
    }
}

// RandomSwapCol2
void Sudoku::RandomSwapCol2(int a, int b) {
    int tmp[12] = {0};
    for (int i = a, j = 0; i <= a+12*11 && j < 12; i+=12, j++)
        tmp[j] = map_out[i];

    for (int i = b, j = a; i <= b+12*11 && j <= a+12*11; i+=12, j+=12)
        map_out[j] = map_out[i];

    for (int i = b, j = 0; i <= b+12*11 && j < 12; i+=12, j++)
        map_out[i] = tmp[j];
}

// RandomNum
int Sudoku::RandomNum(int n) {
    int rnd[2];
    srand((unsigned)time(NULL));
    rnd[0] = rand() % n;
    int gap = rand() % (n-1);
    rnd[1] = (rnd[0] + gap) % n;

    return rnd[0]*10 + rnd[1];
}

// Get Random Sudoku.
void Sudoku::Random() {
    int a = RandomNum(3) / 10;
    int b = RandomNum(3) % 10;
    int c = RandomNum(4) / 10;
    int d = RandomNum(4) % 10;

    // Rows swapping.
    for (int i = 0; i < 4; i++)
        RandomSwapRow2(36*i+a*12, 36*i+b*12);
    RandomSwapRow1(c*36, d*36);

    // Columns swapping.
    for (int i = 0; i < 4; i++) 
        RandomSwapCol2(a+3*i, b+3*i);
    RandomSwapCol1(c*3, d*3);

    // Reverse.
    int tmp[144] = {0};
    int t = rand() % 2;
    if (t == 1) {
        for (int i = 143, j = 0; i >= 0 && j < 144; i--, j++)
            tmp[j] = map_out[i];

        for (int i = 0; i < 144; i++)
            map_out[i] = tmp[i];
    }
}

// GiveQuestion
void Sudoku::GiveQuestion() {
	GiveInitial();

	// Show the question.
	for (int i = 0; i < 144; i++) {
		if ((i+1) % 12)
			cout << map_out[i] << " ";
		else
			cout << map_out[i] << endl;
	}
}

// Read the input.
void Sudoku::ReadIn() {
	for (int i = 0; i < 144; i++)
		cin >> map_inp[i];

    if (!CheckInput()) {
        SetAnswer(0);
        Result();
        exit(0);
    }
}

// Check the input.
bool Sudoku::CheckInput() {
    int check1[12] = {0}, check2[9] = {0};
    int addr, cell, count = 0;

    // Check rows.
    for (int i = 0; i < 12; i++) {
        memset(check1, 0, sizeof(check1));

        count = 0;
        for (int j = 0; j < 12; j++) {
            addr = i*12 + j;
            if (map_inp[addr] > 0)
                check1[map_inp[addr]-1] += 1;
            else if (map_inp[addr] == -1)
                count++;
        }

        for (int j = 0; j < 12; j++) {
            if (check1[j] > 1)
               return false; 
        }
            
        if (count != 3)
          return false;
    }

    // Check columns.
    for (int i = 0; i < 12; i++) {
        memset(check1, 0, sizeof(check1));
        count = 0;
        for (int j = 0; j < 12; j++) {
            addr = j*12 + i;
            if (map_inp[addr] > 0)
                check1[map_inp[addr]-1]++;
            else if (map_inp[addr] == -1)
                count++;
        }

        for (int j = 0; j < 12; j++) {
            if (check1[j] > 1)
               return false; 
        }

        if (count != 3)
            return false;
    }

    // Check cells.
    for (int i = 0; i < 118; i+=3) {
        memset(check2, 0, sizeof(check2));
        count = 0;
        for (int j = 0; j < 9; j++) {
            cell = ((i/36)*3 + j/3)*12 + ((i%12)/3)*3 + j%3;
            if (map_inp[cell] > 0)
                check2[map_inp[cell]-1]++;
            else if (map_inp[cell] == -1)
                count++;
        }

        for (int j = 0; j < 9; j++) {
            if (check2[j] > 1)
               return false; 
        }

        if (count != 9 && count != 0)
            return false; 
    }

    return true;
}

// Solve the Sudoku.
void Sudoku::Solve() {
	int cell, addr, Max, iMax, total = 0;
    int map_cnt[SIZE*SIZE] = {0};
    bool record[SIZE*SIZE][9] = {false};

    // Get all possible numbers in each block.
    for (int i = 0; i < 144; i++) {
        if (map_inp[i]) 
            total++;
        else if (map_inp[i] == 0) {
            for (int j = 0; j < 12; j++) {
            	// Check rows.
            	addr = (i/12)*12 + j;
                if (map_inp[addr] && !record[i][map_inp[addr]-1] && map_inp[addr] != -1) {
                   	map_cnt[i]++;
                    record[i][map_inp[addr]-1] = true;
                }

                // Check columns.
                addr = j*12 + i%12;
                if (map_inp[addr] && !record[i][map_inp[addr]-1] && map_inp[addr] != -1) {
                    map_cnt[i]++;
                    record[i][map_inp[addr]-1] = true;
                }

                // Check cells.
                if (j < 9) {
                    cell = ((i/36)*3 + j/3)*12 + ((i%12)/3)*3 + j%3;
                    if (map_inp[cell] && !record[i][map_inp[cell] - 1] && map_inp[cell] != -1) {
                        map_cnt[i]++;
                        record[i][map_inp[cell] - 1] = true;
                    } 
                }
            }  
        }
    }
    
    // Solve the block which has only one possible number.
    for (int i = 0; i < 144; i++) {
        if (map_inp[i] == 0 && map_cnt[i] == 8) {
            map_cnt[i] = 0;
            total++;
           	for (int j = 0; j < 9; j++) {
                if(!record[i][j]) {
                    map_inp[i] = j + 1;
                    for (int k = 0; k < 12; k++) {
                    	// Check rows.
                    	addr = (i/12)*12 + k;
                        if (map_inp[addr] == 0 && !record[addr][j]) {
                            map_cnt[addr]++;
                            record[addr][j] = true;
                        }

						// Check columns.
						addr = k*12 + i%12;
                        if (map_inp[addr] == 0 && !record[addr][j]) {
                            map_cnt[addr]++;
                            record[addr][j] = true;
                        }

                        // Check cells.
                        if (k < 9) {
                            cell = ((i/36)*3 + k/3)*12 + ((i%12)/3)*3 + k%3;
                            if (map_inp[cell] == 0 && !record[cell][j]) {
                                map_cnt[cell]++;
                                record[cell][j] = true;
                            }
                        }
                    }
                }
            }

            i = -1;
        }
    }

    SetDepth(depth + 1);

    if (total == 144)
        SetAnswer(answer + 1);
    else {
        Max = 0;
        iMax = -1;
        for (int i = 0; i < 144; i++) {
            if (map_cnt[i] > Max && map_inp[i] != -1) {
                Max = map_cnt[i];
                iMax = i;
            }
        }
       
        for (int j = 0; j < 9; j++) {
            if (!record[iMax][j] && map_inp[iMax] != -1) {
                map_inp[iMax] = j + 1;
                Sudoku *tmp = new Sudoku(GetMap(), GetAnswer(), GetDepth());
                delete tmp;
                SetDepth(depth - 1);
            }
        }
    }

    if (depth == 1)
        Result();
}

// GetMap
int* Sudoku::GetMap() {
    for (int i = 0; i < 144; i++)
        map_out[i] = map_inp[i];
    
    return map_out;
}

// GetDepth
int Sudoku::GetDepth() {
    return depth;
}

// SetDepth
void Sudoku::SetDepth(int dep) {
    depth = dep;
}

// GetAnswer
int Sudoku::GetAnswer() {
    return answer;
}

// SetAnswer
void Sudoku::SetAnswer(int ans) {
    answer = ans;
}