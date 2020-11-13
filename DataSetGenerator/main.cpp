#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;


int main(){

    /*
     * A - 65
     * E - 69
     * D - 68
     *
     * B - 66
     * S - 83
     * */

	vector<vector<uint64_t>> book_order;

    book_order.resize(1500000);
    for(size_t i=0; i < 1500000; i++){
        book_order[i].resize(4);
    }

	random_device device;
    mt19937_64 generator(device());
    //uniform_int_distribution<int> buy_sell(0,1);
    uniform_int_distribution<uint64_t> qty(250,4000);
    //uniform_int_distribution<uint64_t> stock_locate(0,25000);
    uniform_int_distribution<uint64_t> price(8000,12000);
    uniform_int_distribution<uint64_t> order_type(0,2);
    uniform_int_distribution<uint64_t> qty_execute(10,50);
    uniform_int_distribution<uint64_t> buy_sell(0,1); // B: 0, S: 1
    //uniform_int_distribution<uint64_t> random_oid(1,2499999); // B: 0, S: 1

    for (uint32_t i = 0; i < 250000; i++){
        for(uint32_t j = 0; j < 4; j++){
            if(j == 0){
                book_order[i][j] = 65; // A
            }
            else if(j == 1){
                book_order[i][j] = i+1; // oid
            }
            /*else if(j == 2){
                if(buy_sell(generator) == 0){
                    book_order[i][j] = 0; // buy
                }
                else{
                    book_order[i][j] = 1; // sell
                }
            }*/
            else if(j == 2){
                book_order[i][j] = qty(generator);
            }
            else if(j == 3){
                book_order[i][j] = price(generator);
            }
        }

    }

    for(uint32_t i = 250000; i < 1250000; i++){
        for(uint32_t j = 0; j < 3; j++){
            if(j == 0){
                book_order[i][j] = 69; // E
            }
            else if(j == 1){
                if(i < 500000){
                    book_order[i][j] = book_order[i-250000][j];
                }
                else if(i>=500000 && i < 750000){
                    book_order[i][j] = book_order[i-500000][j];
                }
                else if(i>=750000 && i < 1000000){
                    book_order[i][j] = book_order[i-750000][j];
                }
                else{
                    book_order[i][j] = book_order[i-1000000][j];
                }

            }
            /*else if(j == 2){
                book_order[i][j] = book_order[i-50000][j]; // buy_sell
            }*/
            else if(j == 2){
                book_order[i][j] = qty_execute(generator); // qty
            }
        }
    }

    for(uint32_t i = 1250000; i < 1500000; i++){
        for(uint32_t j = 0; j < 2; j++){
            if(j == 0){
                book_order[i][j] = 68; // D
            }
            else{
                book_order[i][j] = book_order[i-1250000][j] ; // oid
            }

        }
    }

    ofstream outfile("dataSet.txt");
    //outfile << "MessageType,oid,stock_locate,buy_sell,qty,price" << endl;
    for(uint32_t i = 0; i < 1500000; i++){
        int count = 0;
        if(i < 250000){
            for(int j=0; j < 4; j++){
                if(j == 0){
                    outfile << "A" << " ";
                }
                /*else if(j == 2){
                    if(book_order[i][j] == 0) outfile << "B" << " ";
                    else outfile << "S" << " ";
                }*/
                else{
                    outfile << book_order[i][j] << " ";
                }
            }
            outfile << endl;
        }
        else if(i >= 250000 && i < 1250000){
            for(int j=0; j < 3; j++){
                if(j == 0){
                    outfile << "E" << " ";
                }
                /*else if(j == 2){
                    if(book_order[i][j] == 0) outfile << "B" << " ";
                    else outfile << "S" << " ";
                }*/
                else{
                    outfile << book_order[i][j] << " ";
                }
            }
            outfile << endl;
        }
        else{
            for(int j=0; j < 2; j++){
                if(j == 0){
                    outfile << "D" << " ";
                }
                /*else if(j == 2){
                    if(book_order[i][j] == 0) outfile << "B" << " ";
                    else outfile << "S" << " ";
                }*/
                else{
                    outfile << book_order[i][j] << " ";
                }
            }
            outfile << endl;
        }
    }

    outfile.close();

    return 0;

}