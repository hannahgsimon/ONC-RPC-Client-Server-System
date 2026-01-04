/*
 * Modified rpcgen-generated server stub for hwch9b.
 */

#include "hello.h"
#include <memory.h>
#include <stdio.h>

static void
display_prg_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
    int *result;

    switch (rqstp->rq_proc) {

    case NULLPROC:
        svc_sendreply(transp, (xdrproc_t)xdr_void, NULL);
        return;

    case print_hello:
        result = print_hello_1_svc(rqstp);

        if (!svc_sendreply(transp, (xdrproc_t)xdr_int, (caddr_t)result)) {
            svcerr_systemerr(transp);
        }
        return;

    default:
        svcerr_noproc(transp);
        return;
    }
}

int
display_prg_1_freeresult(SVCXPRT *transp, xdrproc_t xdr_res, caddr_t res)
{
    (void)transp;
    (void)xdr_res;
    (void)res;
    return 1;
}

int
main(int argc, char **argv)
{
    register SVCXPRT *transp;

    pmap_unset(DISPLAY_PRG, DISPLAY_VER);

    transp = svcudp_create(RPC_ANYSOCK);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create UDP service.\n");
        exit(1);
    }
    if (!svc_register(transp, DISPLAY_PRG, DISPLAY_VER, display_prg_1, IPPROTO_UDP)) {
        fprintf(stderr, "Unable to register (UDP).\n");
        exit(1);
    }

    transp = svctcp_create(RPC_ANYSOCK, 0, 0);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create TCP service.\n");
        exit(1);
    }
    if (!svc_register(transp, DISPLAY_PRG, DISPLAY_VER, display_prg_1, IPPROTO_TCP)) {
        fprintf(stderr, "Unable to register (TCP).\n");
        exit(1);
    }

    svc_run();   /* never returns */
    fprintf(stderr, "svc_run returned unexpectedly\n");
    return 1;
}