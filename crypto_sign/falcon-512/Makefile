# This Makefile can be used with GNU Make or BSD Make

LIB=libfalcon-512_neon.a

SOURCES = codec.c common.c fft.c fpr.c keygen.c pqclean.c rng.c sign.c vrfy.c 
OBJECTS = codec.o common.o fft.o fpr.o keygen.o pqclean.o rng.o sign.o vrfy.o 
HEADERS = api.h fpr.h inner.h 

CFLAGS=-O3 -Wconversion -Wall -Wextra -Wpedantic -Wvla -Werror -Wmissing-prototypes -Wredundant-decls -std=c99 -I../../common -I../../intelarm $(EXTRAFLAGS)

all: $(LIB)

%.o: %.s $(HEADERS)
	$(AS) -o $@ $<

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIB)
