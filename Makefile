hvh hvc: ./src/hvh.cpp ./src/hvc.cpp
	g++ -O2 ./src/hvh.cpp -o ./bin/hvh
	g++ -O2 ./src/hvc.cpp -o ./bin/hvc
clean:
	rm ./bin/hvh
	rm ./bin/hvc
