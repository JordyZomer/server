/* -*- mode: C; c-basic-offset: 4 -*- */
#ident "Copyright (c) 2007 Tokutek Inc.  All rights reserved."

#include "portability.h"
#include <db.h>
#include <assert.h>

#include "test.h"

int main (int argc, char *argv[]) {
    const char *v;
    int major, minor, patch;
    int i;
    for (i=1; i<argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "-v") == 0)
            verbose++;
    }
    v = db_version(0, 0, 0);
    assert(v!=0);
    v = db_version(&major, &minor, &patch);
    assert(major==DB_VERSION_MAJOR);
    assert(minor==DB_VERSION_MINOR);
    assert(patch==DB_VERSION_PATCH);
    if (verbose)
        printf("%d.%d.%d %s\n", major, minor, patch, v);
    return 0;
}
