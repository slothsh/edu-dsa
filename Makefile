CXX=g++
CXXFLAGS=-Wall -Wextra -O2
CXXLIBS=$(shell pkg-config --libs fmt)

all: binarySearch                      \
     firstBadVersion                   \
     mergeAlternately                  \
     gcdOfStrings                      \
     gcdOfStringsCpp17                 \
     numberOfCandies                   \
     canPlaceFlowers                   \
     searchInRotatedArray              \
     minimizeMax                       \
     coinChange                        \
     uniquePaths                       \
     uniquePathsWithObstacles          \
     validPartition                    \
     findKthLargest                    \
     partitionLinkedList               \
     maxSlidingWindow                  \
     updateMatrix                      \
     maximalNetworkRank                \
     findCriticalandPseudoCritcalEdges

# Complete ---------------------------------------------------------

binarySearch:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/complete/$@.cpp

mergeAlternately:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/complete/$@.cpp

gcdOfStrings:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++2b -o ./build/$@ ./solutions/complete/$@.cpp

numberOfCandies:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/complete/$@.cpp

searchInRotatedArray:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/complete/$@.cpp

canPlaceFlowers:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/complete/$@.cpp

# Incomplete ---------------------------------------------------------

firstBadVersion:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++2b -o ./build/$@ ./solutions/incomplete/$@.cpp

findCriticalandPseudoCritcalEdges:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

maximalNetworkRank:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

updateMatrix:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

maxSlidingWindow:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

partitionLinkedList:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

gcdOfStringsCpp17:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

minimizeMax:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

coinChange:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

uniquePaths:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

uniquePathsWithObstacles:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

validPartition:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp

findKthLargest:
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -std=c++17 -o ./build/$@ ./solutions/incomplete/$@.cpp
