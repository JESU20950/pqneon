SOURCES = codec.c common.c fft.c fpr.c keygen.c pqclean.c rng.c sign.c vrfy.c 
OBJECTS = codec.o common.o fft.o fpr.o keygen.o pqclean.o rng.o sign.o vrfy.o 
HEADERS = api.h fpr.h inner.h 
LIB=libfalcon-512_neon.a

CFLAGS=-O3 -Wconversion -Wall -Wextra -Wpedantic -Wvla -Werror -Wmissing-prototypes -Wredundant-decls -std=c99 -I../../common -I../../intelarm -I. $(EXTRAFLAGS)

all: $(OBJECTS) $(LIB)


%.o: %.c $(HEADERS)
	$(CC) -g $(CFLAGS) -c -o $@ $<

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)
	$(RM) $(OBJECTS)
clean:
	$(RM) $(LIB)
