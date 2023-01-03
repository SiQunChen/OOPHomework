.PHONY: directories clean stat bin/ut_all

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_sandwich.h src/sandwich.h src/sweet_sandwich.h src/sandwich_factory.h src/beef_sandwich.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*