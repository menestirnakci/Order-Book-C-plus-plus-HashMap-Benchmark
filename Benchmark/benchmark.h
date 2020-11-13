#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>

void benchmark(std::vector<int> &addVec, std::vector<int> &executeVec, std::vector<int> &deleteVec){

    std::ofstream outfileResults("all_results.txt");
    //ADD_ORDER
    std::ofstream outfile1("add_results.txt");
    int biggest1 = addVec[0];
    for(unsigned int i=0; i<addVec.size(); i++){
        if(biggest1 < addVec[i]){
            biggest1 = addVec[i];
        }
        outfile1 << addVec[i] << std::endl;
        outfileResults << addVec[i] << " - A" << std::endl;
    }

    //EXECUTE_ORDER
    std::ofstream outfile2("execute_results.txt");
    int biggest2 = executeVec[0];
    for(unsigned int i=0; i<executeVec.size(); i++){
        if(biggest2 < executeVec[i]){
            biggest2 = executeVec[i];
        }
        outfile2 << executeVec[i] << std::endl;
        outfileResults << executeVec[i] << " - E"  << std::endl;
    }

    //DELETE_ORDER
    std::ofstream outfile3("delete_results.txt");
    int biggest3 = deleteVec[0];
    for(unsigned int i=0; i<deleteVec.size(); i++){
        if(biggest3 < deleteVec[i]){
            biggest3 = deleteVec[i];
        }
        outfile3 << deleteVec[i] << std::endl;
        outfileResults << deleteVec[i] << " - D" << std::endl;
    }

    outfile1.close();
    outfile2.close();
    outfile3.close();
    outfileResults.close();

    std::stringstream stream;
    stream << "python3 benchmark.py";
    system(stream.str().c_str());

}