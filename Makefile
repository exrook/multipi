CC= gcc
CFLAGS =
LDFLAGS = -lgmp
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = multipi

all: $(SOURCES) $(EXECUTABLE)

#build - compile my code
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
  
.c:.o
	$(CC) $(CFLAGS) -c -o $@ $<
.PHONY: clean

clean:
	rm -f $(OBJECTS)
	
