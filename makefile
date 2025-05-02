all:
	g++ -std=c++17 Aleynik_LR5_6_MainMediaResource.cpp -o program

run:
	./program

clean:
	rm -f program
