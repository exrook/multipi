CC= gcc
CFLAGS = -g -O3 -fopenmp
LDFLAGS = -lgmp -fopenmp
SOURCES = main.c pi.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = multipi

all: $(SOURCES) $(EXECUTABLE)

compute: compute.o pi.o
	$(CC) $(LDFLAGS) -o $@ $^


#build - compile my code
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
  
.c:.o
	$(CC) $(CFLAGS) -c -o $@ $<
.PHONY: clean

clean:
	rm -f $(OBJECTS)
	
