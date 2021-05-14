# This Makefile can be used with GNU Make or BSD Make
.PHONY: all make clean

LIB=libfalcon-512_neon.a
OBJECTS = neon/codec.o neon/common.o neon/fft.o neon/fpr.o neon/keygen.o neon/pqclean.o neon/rng.o neon/sign.o neon/vrfy.o common/aes.o common/fips202.o common/randombytes.o common/sha2.o 

all: make $(LIB)

make:
	+$(MAKE) -C common
	+$(MAKE) -C neon 

$(LIB): $(OBJECTS)
	$(AR) -r $@ $(OBJECTS)
	
clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIB)
	
