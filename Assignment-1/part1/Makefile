build: main.cpp
	g++ -std=c++11 main.cpp -o sorer

test:
	./sorer -f sample.sor -print_col_type 1
	./sorer -f sample.sor -print_col_idx 0 0
	./sorer -f sample.sor -is_missing_idx 0 0

clean:
	rm sorer