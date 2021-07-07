CXX := llvm-g++
INCLUDE_FLAG := -I include
CXXFLLGS := --std=c++11 $(INCLUDE_FLAG)

target := CppAlgorithm
dependency := CppConcurrency.o
source := preface/CppConcurrency.cpp

CppAlgorithm: $(dependency)
	$(CXX) $(CXXFLLGS) -o $(target) $(dependency)

$(dependency): $(source)
	$(CXX) $(CXXFLLGS) -c $(source)

.PHONY: clean

clean:
	rm -rf $(dependency) $(target)
