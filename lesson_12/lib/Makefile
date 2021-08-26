SRCS +=list_files.c
LIBNAME += liblist_files.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp list_files.h /usr/include

uninstall:
	rm -f /usr/lib/$(LIBNAME) /usr/include/list_files.h

clean:
	rm -f $(LIBNAME) *.o