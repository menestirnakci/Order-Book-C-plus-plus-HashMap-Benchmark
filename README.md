# Order-Book C++ HashMap Benchmark

## This repo is for creating a hash map benchmark. Hash maps are used in order books. 

#### Please use git clone command but not download as zip since I've uploaded datasets with Git LFS. 
#### If you download code as zip, it is not going to download datasets.
git clone https://github.com/menestirnakci/Order-Book-C-plus-plus-HashMap-Benchmark.git

# How To Run Benchmark

cmake CMakeLists.txt \
make \
./code dataset1.txt \
or \
./code dataset2.txt 

You can change map.h in as you please to try to different hash maps. I have already added many, but they are in comment lines. \
You need one map for grouped_by_price which is LEVEL 2 data, and one map for order_by_order which is LEVEL 1 data.

# How to Run DataSetGenerator 

cmake CMakeLists.txt \
make \
./dataSetGenerator

# Requirements

### Cmake
### Python 3 and numpy

except google:: and boost:: others header only, copy and paste the headers to your project folder

for google:: \
https://github.com/sparsehash/sparsehash/blob/master/INSTALL \
or if you could not install 

sudo -i \
git clone https://github.com/sparsehash/sparsehash.git \
cd  ./sparsehash/src \
cp -R sparsehash/ /usr/local/include/ \
cp -R google/ /usr/local/include/

### google::
https://github.com/sparsehash/sparsehash

### tsl::
https://github.com/Tessil/hopscotch-map \
https://github.com/Tessil/sparse-map \
https://github.com/Tessil/robin-map \
https://tessil.github.io/2016/08/29/benchmark-hopscotch-map.html

### phmap::
https://github.com/greg7mdp/parallel-hashmap

### spp::
https://github.com/greg7mdp/sparsepp

### absl::
https://github.com/abseil/abseil-cpp

### robin_hood::
https://github.com/martinus/robin-hood-hashing \
https://martin.ankerl.com/2019/04/01/hashmap-benchmarks-01-overview/

### emhash7::
https://github.com/ktprime/emhash \
https://github.com/wangyi-fudan/wyhash     //Required for emhash7

### ska::
https://github.com/skarupke/flat_hash_map

### hrd7::	
https://github.com/hordi/hash    

### boost::
https://www.boost.org/
