CXX := llvm-g++
CXXFLLGS := -I include/*

target := CppAlgorithm
dependency := preface/CppConcurrency.o

CppAlgorithm: $(dependency)
	$(CXX) $(CXXFLLGS) -o $(target) $(dependency)

.PHONY: clean

clean:
	rm -rf $(dependency) $(target)
