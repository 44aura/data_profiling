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
/*
PROFILING RESULTS:

CACHEGRIND HORIZONTAL:  

I   refs:      27,922,483,684  
I1  misses:             2,186  
LLi misses:             2,107  
I1  miss rate:           0.00%  
LLi miss rate:           0.00% 
D   refs:      15,308,277,427  (14,405,349,553 rd   + 902,927,874 wr)  
D1  misses:       112,709,736  (    56,363,664 rd   +  56,346,072 wr)  
LLd misses:       112,704,327  (    56,359,123 rd   +  56,345,204 wr)  
D1  miss rate:            0.7% (           0.4%     +         6.2%  )  
LLd miss rate:            0.7% (           0.4%     +         6.2%  )  
LL refs:          112,711,922  (    56,365,850 rd   +  56,346,072 wr)  
LL misses:        112,706,434  (    56,361,230 rd   +  56,345,204 wr)  
LL miss rate:             0.3% (           0.1%     +         6.2%  )  

CACHEGRIND VERTICAL:  

I   refs:      27,922,483,751  
I1  misses:             2,186  
LLi misses:             2,107  
I1  miss rate:           0.00%  
LLi miss rate:           0.00%  
D   refs:      15,308,277,449  (14,405,349,568 rd   + 902,927,881 wr)  
D1  misses:     1,068,971,002  ( 1,012,624,930 rd   +  56,346,072 wr)  
LLd misses:       956,178,975  (   899,833,771 rd   +  56,345,204 wr)  
D1  miss rate:            7.0% (           7.0%     +         6.2%  )  
LLd miss rate:            6.2% (           6.2%     +         6.2%  )  
LL refs:        1,068,973,188  ( 1,012,627,116 rd   +  56,346,072 wr)  
LL misses:        956,181,082  (   899,835,878 rd   +  56,345,204 wr)  
LL miss rate:             2.2% (           2.1%     +         6.2%  )  


TIME HORIZONTAL: 1673  
TIME VERTICAL: 5377  
*/