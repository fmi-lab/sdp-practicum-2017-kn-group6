#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, const char* const* argv) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    int res = ctx.run();              // run test cases unless with --no-run

    return res;
}
