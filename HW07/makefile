.PHONY: directories clean stat bin/ut_all

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_cake.h src/cake.h src/cake_showcase.h src/chocolate_cake.h src/geode_cake.h src/honey_cake.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*