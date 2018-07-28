bins = $(patsubst %.c, %, $(wildcard *.c))
nxfiles = /tmp/does_not_exist /tmp/did_not_exist

all: $(bins)
	
clean:
	rm -f $(bins) $(nxfiles)
	
.PHONY: all clean
