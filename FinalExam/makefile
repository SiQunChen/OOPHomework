.PHONY: directories clean stat bin/ut_all

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_sample.h test/bike_gc.h src/bike_factory.h src/bike_rms.h src/bike.h src/electric_bike.h src/mybike.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*