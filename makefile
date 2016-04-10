CPP=g++

NODE=ctmarkovnode.cpp ctmarkovnode.h
CHAIN=ctmarkovchain.cpp ctdualmarkovchain.cpp ctmarkovchain.h

build: $(NODE) $(CHAIN)
	$(CPP) -c -fPIC $(NODE)
	$(CPP) -c -fPIC $(CHAIN)
	$(CPP) -shared -Wl,-soname,libctmarkovchain.so -o libctmarkovchain.so *.o
install:
	cp -f libctmarkovchain.so /usr/lib/
	cp -f ctmarkovchain.h /usr/include/
	cp -f ctmarkovnode.h /usr/include/
uninstall:
	rm -f /usr/lib/libctmarkovchain.so
	rm -f /usr/include/ctmarkovchain.h
	rm -f /usr/include/ctmarkovnode.h
test: test.cpp $(CHAIN) $(NODE)
	g++ -o test test.cpp $(CHAIN) $(NODE)
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
	if [ -e test ]; then rm test; fi
