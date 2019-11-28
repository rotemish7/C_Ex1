CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS = -Wall -g

all: libmybank.so libmybank.a mains maind	

mains: $(OBJECTS_MAIN) libmybank.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmybank.a
	
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmybank.so
	
libmybank.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmybank.so $(OBJECTS_LIB)
	
libmybank.a: $(OBJECTS_LIB)
	$(AR) -rcs libmybank.a $(OBJECTS_LIB)	
	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c
	
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind 
