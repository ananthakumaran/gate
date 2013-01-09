ERL_INCLUDE=/usr/local/lib/erlang/erts-5.9.2/include
CFLAGS=-g -O0 -Wall -Wextra -I$(ERL_INCLUDE) $(OPTFLAGS)
TARGET=build/test_gate
SOURCES=gate.c test_gate.c
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))


all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $*.c

build:
	@mkdir -p build

check-syntax: CFLAGS=-g -Wall -Wextra -I$(ERL_INCLUDE) $(OPTFLAG)
check-syntax:
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)

$(TARGET): build $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

clean:
	rm -rf build *.o
