SHELL := /bin/bash
export SHELLOPTS:=errexit:pipefail
.DELETE_ON_ERROR:

pandoc-cgi: pandoc-cgi.c
	$(CC) -o $@ $<
