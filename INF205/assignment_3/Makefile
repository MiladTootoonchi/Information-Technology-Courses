run: main
	./main input.txt -v

main: main.cpp ListGraph.cpp MatrixGraph.cpp tarjan.cpp
	g++ -std=c++17 main.cpp ListGraph.cpp MatrixGraph.cpp tarjan.cpp -o main

clean:
	rm -f main output_list.txt output_matrix.txt