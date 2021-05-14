SOURCES = test_arm.c
OBJECTS = test_arm.exe test_intel.exe


CFLAGS=-O3 -I. 

all: arm

arm: test_arm.c
	gcc $(CFLAGS) -o test_arm.exe $<

intel: test_intel.c
	gcc  -march=native $(CFLAGS) -o test_intel.exe $<
	
clean:
	$(RM) $(OBJECTS)
