#include <chrono>
#include <cstdio>
#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include "benchmark.h"
#include "map.h"

int main(int argc, char *argv[]) {

    std::ifstream dataSet(argv[1]);
    //std::ifstream dataSet("/home/enes/CLionProjects/untitled/dataSet2.txt");
    std::string line;
    size_t npkts = 0;

    std::vector<int> addOrderDurationVec;
    std::vector<int> executeOrderDurationVec;
    std::vector<int> deleteOrderDurationVec;

    std::vector<order> ADD;
    std::vector<order> EXECUTE;
    std::vector<order> DELETE;

    oidmap map;
    map.reserve();

    while(getline(dataSet,line)){
        std::stringstream s(line);
        char msgtype;
        s >> msgtype;

        order pkt{};
        switch (msgtype) {
            case ('A'): {
                s >> pkt.oid >> pkt.qty >> pkt.price;
                ADD.push_back(pkt);
                ++npkts;
                break;
            }
            case ('E'): {
                s >> pkt.oid >> pkt.qty;
                EXECUTE.push_back(pkt);
                ++npkts;
                break;
            }
            case ('D'): {
                s >> pkt.oid;
                DELETE.push_back(pkt);
                ++npkts;
                break;
            }
            default:
                printf("Unknown Message Type %d\n", char(msgtype));
                break;
        }
    }
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    for(auto & i : ADD){
        //std::cout << "ADD " << pkt.oid << "\t"<< pkt.qty << "\t" << pkt.price << std::endl;

        std::chrono::high_resolution_clock::time_point start_local = std::chrono::high_resolution_clock::now(); ;
        map.add_order(&i);
        std::chrono::high_resolution_clock::time_point end_local = std::chrono::high_resolution_clock::now();

        size_t duration =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end_local - start_local).count();
        //std::cout << duration << " - A" << std::endl;
        addOrderDurationVec.push_back(duration);
    }

    for(auto & i : EXECUTE){
        //std::cout << "EXECUTE " << pkt.oid << "\t" << pkt.qty << std::endl;

        std::chrono::high_resolution_clock::time_point start_local = std::chrono::high_resolution_clock::now();
        map.execute_order(&i);
        std::chrono::high_resolution_clock::time_point end_local = std::chrono::high_resolution_clock::now();

        size_t duration =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end_local - start_local).count();
        //std::cout << duration << " - E" << std::endl;
        executeOrderDurationVec.push_back(duration);
    }

    for(auto & i : DELETE){
        //std::cout << "DELETE " << pkt.oid << std::endl;

        std::chrono::high_resolution_clock::time_point start_local = std::chrono::high_resolution_clock::now(); ;
        map.delete_order(&i);
        std::chrono::high_resolution_clock::time_point end_local = std::chrono::high_resolution_clock::now(); ;

        size_t duration =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end_local - start_local).count();
        //std::cout << duration << " - D" << std::endl;
        deleteOrderDurationVec.push_back(duration);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    size_t nanos =
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    printf("%lu packets in %lu nanos , %.2f nanos per packet \n", npkts, nanos, nanos / (double) npkts);
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "IF SEEMS STUCK, DO NOT WORRY. PYTHON CODE STILL RUNNING..." << std::endl;

    benchmark(addOrderDurationVec, executeOrderDurationVec, deleteOrderDurationVec);

    std::cout << "FINISHED" << std::endl;

    /*for (auto itr = map.order_by_order.begin(); itr != map.order_by_order.end(); ++itr) {
        std::cout << '\t' << itr->first
                  << '\t' << itr->second.oid << "\t" << itr->second.price << "\t" << itr->second.qty <<'\n';
    }

    for (auto itr = map.grouped_by_price.begin(); itr != map.grouped_by_price.end(); ++itr) {
        std::cout << '\t' << itr->first
                  << "\t" << itr->second.price << "\t" << itr->second.qty <<'\n';
    }*/

    return 0;

}
