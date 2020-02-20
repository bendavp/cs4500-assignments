# Thanks to Parker Griep for helping us set up our Makefile and gtest environment 

# Install the google test framework under the test directory
install:
	cd test && cmake .

# Run all the tests
test:
	-cd test && make --no-print-directory && ./runTests

# Clean it up
clean:
	find ./test/* ! -name "CMakeLists.txt" ! -name "CMakeLists.txt.in" ! -name "test*" -exec rm -rf "{}" +;
	rm -rf a.out*