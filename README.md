# pandoc-cgi

Turn your Pandoc documents into self-rendering HTML documents!

## Usage

    usage: ./pandoc-cgi [input-file]

    Reads from stdin or the given input file and filters the contents
    through pandoc.  The first line, assumed to be a shebang calling
    this program, is skipped before calling pandoc.  Output is to stdout.
