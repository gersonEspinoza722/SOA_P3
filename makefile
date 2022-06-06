OUTPUT=simulacion.o
CURRDIR=$(shell pwd)
HEADERS=-I$(CURRDIR)/include/
CFLAGS=-g -Wall
LIBRARIES=-lm -pthread -lrt `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
OBJECTS=$(shell ls ./src/*.c)

$(OUTPUT): $(OBJECTS)
	@echo $(objects)
	mkdir -p build
	gcc  $(CFLAGS) $(HEADERS) -o build/$(OUTPUT) $(OBJECTS) $(LIBRARIES)

clean:
	@echo Clean compile
	rm -f build/*
