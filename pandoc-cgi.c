#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    int fd;
    char byte;
    int bytes_read;

    const char *pandoc_path = "pandoc";
    char * const pandoc_args[] = {
        "pandoc", "-t", "html", "--smart", "--standalone",
        (char *) NULL
    };


    if (argc > 1 && ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0))) {
        printf("usage: %s [input-file]\n\n", argv[0]);
        printf("Reads from stdin or the given input file and filters the contents\n");
        printf("through pandoc.  The first line, assumed to be a shebang calling\n");
        printf("this program, is skipped before calling pandoc.  Output is to stdout.\n");
        exit(EXIT_SUCCESS);
    }


    // Re-open the given filename on stdin (fd 0)
    if (argc > 1) {
        if ((fd = open(argv[1], O_RDONLY)) == -1)
            err(EXIT_FAILURE, "Failed to open %s", argv[1]);

        if (dup2(fd, 0) == -1)
            err(EXIT_FAILURE, "Failed to re-open stdin");
    }


    // Ignore first line of stdin if it's a shebang
    while ((bytes_read = read(0, &byte, 1)) > 0)
        if (byte == '\n')
            break;

    if (bytes_read == 0)
        errx(EXIT_FAILURE, "Failed to skip past shebang line: hit end-of-file");

    if (bytes_read == -1)
        err(EXIT_FAILURE, "Failed to skip past shebang line");


    // Output our HTTP header and hand over control to pandoc
    printf("Content-Type: text/html; charset=UTF-8\n\n");
    execvp(pandoc_path, pandoc_args);


    // Whoops, the exec failed!
    err(EXIT_FAILURE, "Failed to run pandoc");
}
