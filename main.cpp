#include <iostream>
#include <chrono>
#define COLS 30000
#define ROWS 30000


int sum_v(int** a){
    int sum = 0;
    for(int y = 0;y < COLS;y++){
        for(int x = 0; x < ROWS;x++){
            sum += a[x][y];
        }
    }
    return sum;
}

int sum_g(int** a){
    int sum = 0;
    for(int x = 0;x < ROWS;x++){
        for(int y = 0; y < COLS;y++){
            sum += a[x][y];
        }
    }
    return sum;
}


int main(){
    long val = 0;
	int** mtx = new int*[ROWS];
	for(int x = 0; x < ROWS; x++){
		mtx[x] = new int[COLS];
	}
    while(val < COLS * ROWS){
        for(int x = 0; x < COLS; x++){
            for(int y = 0; y < ROWS; y++){
                mtx[x][y] = val;
                val += 1;
            }
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    sum_g(mtx);
    //sum_v(mtx);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << duration.count() << "\n";

    for(int i = 0; i < ROWS; ++i){
        delete mtx[i];
    }
    delete mtx;

}