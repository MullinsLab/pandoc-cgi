# pandoc-cgi

Turn your Pandoc documents into self-rendering HTML documents!

 1. Add a shebang to the top of your Pandoc documents pointing to `pandoc-cgi`

 2. Mark your documents executable with `chmod +x`

 3. Register your documents as CGI scripts in your web browser, for example, using
    an Apache `.htaccess` file:

        AddHandler cgi-script .md


## Command-line usage

    usage: ./pandoc-cgi [input-file]

    Reads from stdin or the given input file and filters the contents
    through pandoc.  The first line, assumed to be a shebang calling
    this program, is skipped before calling pandoc.  Output is to stdout.


## Installation

Just type `make install` inside a checkout of this repository to compile and
install pandoc-cgi to `/usr/local/bin`.
