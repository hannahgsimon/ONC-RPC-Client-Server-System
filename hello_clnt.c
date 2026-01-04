/*
 * Modified rpcgen-generated client stub for hwch9b.
 * Removes the filler argument (void *argp).
 */

#include <memory.h>
#include "hello.h"

static struct timeval TIMEOUT = { 25, 0 };

int *
print_hello_1(CLIENT *clnt)
{
    static int clnt_res;

    memset((char *)&clnt_res, 0, sizeof(clnt_res));

    if (clnt_call(clnt, print_hello,
                  (xdrproc_t)xdr_void, NULL,
                  (xdrproc_t)xdr_int, (caddr_t)&clnt_res,
                  TIMEOUT) != RPC_SUCCESS)
    {
        return NULL;
    }

    return &clnt_res;
}