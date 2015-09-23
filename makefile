CPP=g++

CCMD=ccmd.cpp ccmd.h
LOADBAR=loadbar.cpp loadbar.h
CTVT=ctvt.cpp ctvt.h

build: $(CCMD) $(LOADBAR) $(CTVT)
	$(CPP) -c -fPIC $(CCMD) --std=c++11
	$(CPP) -c -fPIC $(LOADBAR) --std=c++11
	$(CPP) -c -fPIC $(CTVT) --std=c++11
	$(CPP) -shared -Wl,-soname,libctvt.so -o libctvt.so *.o
install:
	cp libctvt.so /usr/lib/
	mkdir /usr/include/ctvt
	cp ctvt.h /usr/include/ctvt/
	cp loadbar.h /usr/include/ctvt/
uninstall:
	rm /usr/lib/libctvt.so
	rm /usr/include/ctvt/ctvt.h
	rm /usr/include/ctvt/loadbar.h
	rmdir /usr/include/ctvt
test: test.cpp $(CTVT) $(LOADBAR)
	export TMP_PATH=$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
	g++ -o test test.cpp -L. -lctvt
	./test
	export LD_LIBRARY_PATH=$TMP_PATH
clean:
	rm *.o *.so *.gch
