CFILES := $(wildcard src/*.c)
SFILES := ${wildcard src/*.s}
GCC := gcc
CFLAGS := -Iinclude -fdiagnostics-color=always
run: $(CFILES)
	$(GCC) $(CFLAGS) $(CFILES) $(SFILES) -o vm


	


