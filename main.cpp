#include <iostream>
#include <vector>


int sum_v(int** a, int cols, int rows){
    int sum = 0;
    std::cout << "Vertical sequence: ";
    for(int y = 0;y < rows;y++){
        for(int x = 0; x < cols;x++){
            sum += a[x][y];
            std::cout << a[x][y] << " ";
        }
    }
    std::cout << "\nSum: ";
    return sum;
}

int sum_g(int** a, int cols, int rows){
    int sum = 0;
    std::cout << "Horizontal sequence: ";
    for(int x = 0;x < cols;x++){
        for(int y = 0; y < rows;y++){
            sum += a[x][y];
            std::cout << a[x][y] << " ";
        }
    }
    std::cout << "\nSum: ";
    return sum;
}


int main(){
    int rows = 10;
	int cols = 10;
    int val = 0;
	int** mtx = new int*[rows];
	for(int x = 0; x < rows; x++){
		mtx[x] = new int[cols];
	}
    while(val < cols*rows){
        for(int x = 0;x < cols;x++){
            for(int y = 0; y < rows;y++){
                mtx[x][y] = val;
                val += 1;
            }
        }
    }
    std::cout << sum_v(mtx, cols, rows) << "\n";
    std::cout << sum_g(mtx, cols, rows) << "\n";
    for(int i = 0; i < rows; i++){
        delete mtx[i];
    }
    delete mtx;
    
}