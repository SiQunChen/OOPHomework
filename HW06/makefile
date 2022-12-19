.PHONY: directories clean stat bin/ut_all

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_alcohol.h test/ut_sour.h test/ut_tequila.h src/alcohol.h src/sour.h src/tequila.h src/order.h src/algorithm.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*
