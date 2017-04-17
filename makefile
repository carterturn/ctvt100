CPP=g++

CCMD=ccmd.cpp
LOADBAR=loadbar.cpp
CTVT=ctvt.cpp

build: $(CCMD) $(LOADBAR) $(CTVT)
	$(CPP) -c -fPIC $(CCMD)
	$(CPP) -c -fPIC $(LOADBAR)
	$(CPP) -c -fPIC $(CTVT)
	$(CPP) -shared -Wl,-soname,libctvt.so -o libctvt.so *.o
install:
	cp -f libctvt.so /usr/lib/
	[ -d /usr/include/ctvt ] || mkdir /usr/include/ctvt
	cp -f ctvt.h /usr/include/ctvt/
	cp -f loadbar.h /usr/include/ctvt/
uninstall:
	rm -f /usr/lib/libctvt.so
	rm -f /usr/include/ctvt/ctvt.h
	rm -f /usr/include/ctvt/loadbar.h
	[ -d /usr/include/ctvt ] && rmdir /usr/include/ctvt
test: test.cpp $(CTVT) $(LOADBAR)
	g++ -g -o test test.cpp $(CCMD) $(LOADBAR) $(CTVT)
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
	if [ -e test ]; then rm test; fi
