CPP=g++

NODE=ctmarkovnode.cpp ctmarkovnode.h
CHAIN=ctmarkovchain.cpp ctmarkovchain.h

build: $(NODE) $(CHAIN)
	$(CPP) -c -fPIC $(NODE)
	$(CPP) -c -fPIC $(CHAIN)
	$(CPP) -shared -Wl,-soname,libctmarkovchain.so -o libctmarkovchain.so *.o
install:
	cp libctmarkovchain.so /usr/lib/
	cp ctmarkovchain.h /usr/include/
	cp ctmarkovnode.h /usr/include/
uninstall:
	rm /usr/lib/libctmarkovchain.so
	rm /usr/include/ctmarkovchain.h
	rm /usr/include/ctmarkovnode.h
test: test.cpp $(CHAIN) $(NODE)
	export TMP_PATH=$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
	g++ -o test test.cpp -L. -lctmarkovchain
clean:
	rm *.o *.so *.gch test
