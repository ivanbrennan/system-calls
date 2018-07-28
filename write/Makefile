bins = $(patsubst %.c, %, $(wildcard *.c))
nxfiles = /tmp/will_get_truncated

all: $(bins)

clean:
	rm -f $(bins) $(nxfiles)

.PHONY: all clean
