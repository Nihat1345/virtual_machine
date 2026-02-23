CFILES := $(wildcard src/*.c)
GCC := gcc
CFLAGS := -Iinclude
run: $(CFILES)
	$(GCC) $(CFLAGS) $(CFILES) -o vm


	


