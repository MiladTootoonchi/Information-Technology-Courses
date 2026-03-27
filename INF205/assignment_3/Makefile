main: main.cpp ListGraph.cpp MatrixGraph.cpp tarjan.cpp diamond.cpp
	g++ -std=c++17 main.cpp ListGraph.cpp MatrixGraph.cpp tarjan.cpp diamond.cpp -o main

pro22: main
	./main input.txt scc

pro25: main
	./main input.txt scc -v

pro31: main
	./main input.txt scc -v

pro32: main
	./main input.txt diamond -v

clean:
	rm -f main gen_graph gen_scc