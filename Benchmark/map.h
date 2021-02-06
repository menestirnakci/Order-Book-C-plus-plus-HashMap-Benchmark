#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "maps/bytell_hash_map.hpp"
#include "maps/unordered_map.hpp"
#include <google/dense_hash_map>
#include <boost/unordered_map.hpp>
#include "maps/tsl/hopscotch_map.h"
#include "maps/tsl/bhopscotch_map.h"
#include "maps/tsl/sparse_map.h"
#include "maps/tsl/robin_map.h"
#include "maps/parallel_hashmap/phmap.h"
#include "maps/parallel_hashmap/btree.h"
#include "maps/abseil-cpp/absl/container/flat_hash_map.h"
#include "maps/abseil-cpp/absl/container/node_hash_map.h"
#include "maps/robin_hood.h"
#include <boost/container/flat_map.hpp>
#include "maps/hash_table7.hpp"
#include "maps/hash_set7.h"
#include "maps/sparsepp/spp.h"
struct level
{
public:
    uint32_t price;
    uint32_t qty;
};

struct order
{
    uint32_t qty;
    uint64_t oid;
    uint32_t price;
};

class oidmap
{
public:
//    tsl::hopscotch_map<int64_t,order> order_by_order;
//    tsl::bhopscotch_map<int64_t,order> order_by_order;
//    tsl::sparse_map<int64_t,order> order_by_order;
    tsl::robin_map<int64_t,order> order_by_order;

//    robin_hood::unordered_flat_map<int64_t,order> order_by_order;
//    robin_hood::unordered_map<int64_t,order> order_by_order;
//    robin_hood::unordered_node_map<int64_t,order> order_by_order;

//    google::dense_hash_map<int64_t,order> order_by_order; // Do not forget to change 79 line and 147 for order-by-order
                                                            // change line 80 and 145 for grouped-by-price
                                                            // Others required changes will be seen at compile error message
//    ska::unordered_map<int64_t,order> order_by_order;
//    ska::flat_hash_map<int64_t,order> order_by_order;
//    ska::bytell_hash_map<int64_t,order> order_by_order;
//    boost::unordered_map<int64_t,order> order_by_order;

//    phmap::flat_hash_map<int64_t,order> order_by_order;
//    phmap::node_hash_map<int64_t,order> order_by_order;
//    phmap::parallel_flat_hash_map<int64_t,order> order_by_order;
//    phmap::parallel_node_hash_map<int64_t,order> order_by_order;

//    absl::flat_hash_map<int64_t,order> order_by_order;
//    absl::node_hash_map<int64_t,order> order_by_order;

//    emhash7::HashMap<int64_t,order> order_by_order;

//    hrd7::hash_map<int64_t,order> order_by_order;

    //spp::sparse_hash_map<int64_t,order> order_by_order;
    //boost::container::flat_map<int64_t,order> order_by_order;

    tsl::hopscotch_map<uint32_t ,level> grouped_by_price;

    void reserve()
    {
        /**
         * Google Dense Hash Map requires to set an empty key
         */
//        order_by_order.set_empty_key(-1);
//        grouped_by_price.set_empty_key(-1);
//        order_by_order.reserve(20000000);
        //grouped_by_price.reserve();
    }

    void add_order(order *pkt){
        auto itr = order_by_order.find(pkt->oid);

        if(itr == order_by_order.end()){
            order_by_order.insert(std::pair<int64_t,order>(pkt->oid,*pkt)); // OTHERS
//            order_by_order.insert_or_assign(pkt->oid,*pkt); // robin_hood::

            auto itr2 = grouped_by_price.find(pkt->price);
            if(itr2 == grouped_by_price.end()){
                level newLevel{pkt->price, pkt->qty};
                grouped_by_price.insert(std::pair<uint32_t ,level>(newLevel.price, newLevel)); // OTHERS
//                grouped_by_price.insert_or_assign(newLevel.price, newLevel); // robin_hood::
            }
            else{
                grouped_by_price.at(itr2->second.price).qty += pkt->qty; // TSL
//                itr2->second.qty += pkt->qty; // OTHERS
            }
        }
    }

    void execute_order(order *pkt){
        if(order_by_order.find(pkt->oid)->second.qty == pkt->qty){
            delete_order(pkt);
        }
        else{
            /**
             * TSL find(key)->second returns const value
             * TSL must use at(key).members
             *
             * google dense hash map does not have at(key) function
             * google dense hash map must use find(key)->first,second
             */
            order_by_order.at(pkt->oid).qty -= pkt->qty; // TSL and OTHERS
//            order_by_order.find(pkt->oid)->second.qty -= pkt->qty; // OTHERS and emhash

//            grouped_by_price.at(order_by_order.at(pkt->oid).price).qty -= pkt->qty; // OTHERS
            grouped_by_price.at(order_by_order.find(pkt->oid)->second.price).qty -= pkt->qty; // TSL
//            grouped_by_price.find(order_by_order.find(pkt->oid)->second.price)->second.qty -= pkt->qty; // GOOGLE DENSE
        }
    }

    void delete_order(order *pkt){
        uint32_t price = order_by_order.find(pkt->oid)->second.price;
        uint32_t qty = order_by_order.find(pkt->oid)->second.qty;

        /**
         * TSL group_by_price or OTHERS
         * TSL find(key)->second returns const value
         * TSL must use at(key).members
         */
        grouped_by_price.at(price).qty -= qty;
        if(grouped_by_price.at(price).qty == 0)
            grouped_by_price.erase(price);

        /**
         * OTHERS
         */
        /*grouped_by_price.find(price)->second.qty -= qty;
        if(grouped_by_price.find(price)->second.qty == 0)
            grouped_by_price.erase(price);*/
//            grouped_by_price.set_deleted_key(price); // GOOGLE DENSE HASH MAP

//        order_by_order.set_deleted_key(pkt->oid); // Google dense hash map otherwise there will be error like densehashtable.h:431
        order_by_order.erase(pkt->oid); // Others

    }
};



