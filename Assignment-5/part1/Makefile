# Thanks to Parker Griep for helping us set up our Makefile and gtest environment 

# Install the google test framework under the test directory
install:
	cd test && cmake .

# Run all the tests
run-tests:
	-cd ./test/ && make --no-print-directory && ./runTests

# Clean it up
clean:
	find ./test/* ! -name "CMakeLists.txt" ! -name "CMakeLists.txt.in" ! -name "test*" -exec rm -rf "{}" +;
	rm -rf a.out*
	rm bench
	rm datafile.txt

#setup benchmark
setup-bench:
	chmod u+x file_generator.py
	./file_generator.py "datafile.txt" 1278600
	g++ -std=c++11 bench.cpp -o bench

#run benchmark
run-bench:
	./bench datafile.txt > output1.txt
	./bench datafile.txt > output2.txt
	./bench datafile.txt > output3.txt

