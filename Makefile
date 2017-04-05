SHELL := /bin/bash
export SHELLOPTS:=errexit:pipefail
.DELETE_ON_ERROR:

prefix  := /usr/local
bin     := $(prefix)/bin
exe 	:= pandoc-cgi

pandoc-cgi: pandoc-cgi.c
	$(CC) -o $@ $<

install: $(exe)
	@install -dv $(bin)
	@install -cv $(exe) $(bin)

uninstall:
	@rm -v $(patsubst %,$(bin)/%,$(exe)) \
		| perl -pe 'print "rm: "'

clean:
	@rm -v $(exe) \
		| perl -pe 'print "rm: "'
