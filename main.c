//
// Created by luisnegrao on 12/16/21.
//

#include "parser.h"
#include "language.h"
#include "runner.h"

int main(int argc, char **argv) {

    --argc;
    ++argv;
    if (argc != 0) {
        yyin = fopen(*argv, "r");
        if (!yyin) {
            printf("'%s': could not open file\n", *argv);
            return 1;
        }
    } //  yyin = stdin
    if (yyparse() == 0) {
        solve(programList);
    }
    return 0;
}
//TODO IMPLEMENT SKIP