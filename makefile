CPP=g++

ITS=its.cpp its.h
CCMD=ccmd.cpp ccmd.h
LOADBAR=loadbar.cpp loadbar.h
CTVT=ctvt.cpp ctvt.h

build: $(ITS) $(CCMD) $(LOADBAR) $(CTVT)
	$(CPP) -c -fPIC $(ITS)
	$(CPP) -c -fPIC $(CCMD)
	$(CPP) -c -fPIC $(LOADBAR)
	$(CPP) -c -fPIC $(CTVT)
	$(CPP) -shared -Wl,-soname,libctvt.so -o libctvt.so *.o
install:
	cp libctvt.so /usr/lib/
	cp ctvt.h /usr/include/
	cp loadbar.h /usr/include/
uninstall:
	rm /usr/lib/libctvt.so
	rm /usr/include/ctvt.h
	rm /usr/include/loadbar.h
test: test.cpp $(CTVT) $(LOADBAR)
	export TMP_PATH=$LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
	g++ -o test test.cpp -L. -lctvt
	./test
	export LD_LIBRARY_PATH=$TMP_PATH
clean:
	rm *.o *.so.1 *.gch
