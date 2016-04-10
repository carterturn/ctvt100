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
	g++ -o test test.cpp $(CCMD) $(LOADBAR) $(CTVT)
clean:
	for file in $$(ls *.o); do rm $$file; done
	for file in $$(ls *.so); do rm $$file; done
	for file in $$(ls *.gch); do rm $$file; done
	if [ -e test ]; then rm test; fi
