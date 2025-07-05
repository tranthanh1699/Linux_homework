
static: bstrutils.c main.c strutils.h
	rm -rf ./static_lib/*.o ./bin/main_static
	gcc -c bstrutils.c -o ./static_lib/bstrutils.o
	ar rcs ./static_lib/libstrutils.a ./static_lib/bstrutils.o
	rm -rf ./static_lib/bstrutils.o
	gcc -o ./bin/main_static main.c ./static_lib/libstrutils.a -I.

shared: bstrutils.c main.c strutils.h
	rm -rf ./shared_lib/*.so ./bin/main_shared
	gcc -fPIC -c bstrutils.c -o ./shared_lib/bstrutils.o
	gcc -shared -o ./shared_lib/libstrutils.so ./shared_lib/bstrutils.o
	rm -rf ./shared_lib/bstrutils.o
	gcc -o ./bin/main_shared main.c -L./shared_lib -lstrutils -I.

run_static: static
	./bin/main_static

run_shared: shared
	LD_LIBRARY_PATH=/home/victor/Desktop/HomeWork/Session_1/shared_lib/ ./bin/main_shared

all: static shared
	rm -rf ./bin/main_static ./bin/main_shared
	make static
	make shared

clean:
	rm -rf ./bin/* ./shared_lib/* ./static_lib/*