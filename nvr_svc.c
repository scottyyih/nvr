/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nvr.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h> 

#include "Debug.h"

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

char ClientIP[IPLEN];
unsigned short int ClientPort;
int EXIT_FLAG = 0;

int debug_level = 0;

static void
nvrprog_1(struct svc_req *rqstp, register SVCXPRT * transp)
{
	union {
		CMMNargs nvrproc_open_1_arg;
		u_int nvrproc_close_1_arg;
		READargs nvrproc_read_1_arg;
		WRITEargs nvrproc_write_1_arg;
		CMMNargs nvrproc_getheader_1_arg;
		CREATEargs nvrproc_create_1_arg;
		SEARCHargs nvrproc_searchrecord_1_arg;
		SETRECINFOargs nvrproc_setrecinfo_1_arg;
		u_int nvrproc_getvolumeinfo_1_arg;
		DELargs nvrproc_delete_1_arg;
		LOGINargs nvrproc_login_1_arg;
		u_int nvrproc_logout_1_arg;
		GETRECSIZEargs nvrproc_getrecsize_1_arg;
		CREATRECVOLargs nvrproc_creatrecvol_1_arg;
		DELRECVOLargs nvrproc_delrecvol_1_arg;
		RECORDBYORDERargs nvrproc_searchrecordbyorder_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local) (char *, struct svc_req *);

	struct sockaddr_in* psa;
	if((psa = svc_getcaller(transp)) == NULL)
	{
		fprintf(stderr, "%s", "cannot get caller.");
		TRACE_LOG("[RPC:%d]Cannnot get caller!");
		psa = 0;
		ClientIP[0] = '\0';
		ClientPort = 0;
	}
	else
	{
		bzero(ClientIP, IPLEN);
		strcpy(ClientIP, (char *)inet_ntoa(psa->sin_addr));
		ClientPort = psa->sin_port;
	}

	switch (rqstp->rq_proc) {
		case NULLPROC:
			(void)svc_sendreply(transp, (xdrproc_t) xdr_void, (char *)NULL);
			return;

		case NVRPROC_OPEN:
			_xdr_argument = (xdrproc_t) xdr_CMMNargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_open_1_svc;
			break;

		case NVRPROC_CLOSE:
			_xdr_argument = (xdrproc_t) xdr_u_int;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_close_1_svc;
			break;

		case NVRPROC_READ:
			_xdr_argument = (xdrproc_t) xdr_READargs;
			_xdr_result = (xdrproc_t) xdr_READres;
			local = (char *(*)(char *, struct svc_req *))nvrproc_read_1_svc;
			break;

		case NVRPROC_WRITE:
			_xdr_argument = (xdrproc_t) xdr_WRITEargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_write_1_svc;
			break;

		case NVRPROC_GETHEADER:
			_xdr_argument = (xdrproc_t) xdr_CMMNargs;
			_xdr_result = (xdrproc_t) xdr_HEADERinfo;
			local = (char *(*)(char *, struct svc_req *))nvrproc_getheader_1_svc;
			break;

		case NVRPROC_CREATE:
			_xdr_argument = (xdrproc_t) xdr_CREATEargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_create_1_svc;
			break;

		case NVRPROC_SEARCHRECORD:
			_xdr_argument = (xdrproc_t) xdr_SEARCHargs;
			_xdr_result = (xdrproc_t) xdr_SEARCHres;
			local = (char *(*)(char *, struct svc_req *))
			    nvrproc_searchrecord_1_svc;
			break;

		case NVRPROC_SETRECINFO:
			_xdr_argument = (xdrproc_t) xdr_SETRECINFOargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_setrecinfo_1_svc;
			break;

		case NVRPROC_GETVOLUMEINFO:
			_xdr_argument = (xdrproc_t) xdr_u_int;
			_xdr_result = (xdrproc_t) xdr_VOLUMinfo;
			local = (char *(*)(char *, struct svc_req *))
			    nvrproc_getvolumeinfo_1_svc;
			break;

		case NVRPROC_DELETE:
			_xdr_argument = (xdrproc_t) xdr_DELargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_delete_1_svc;
			break;

		case NVRPROC_LOGIN:
			_xdr_argument = (xdrproc_t) xdr_LOGINargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_login_1_svc;
			break;

		case NVRPROC_LOGOUT:
			_xdr_argument = (xdrproc_t) xdr_u_int;
			_xdr_result = (xdrproc_t) xdr_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_logout_1_svc;
			break;

		case NVRPROC_GETLASTERROR:
			_xdr_argument = (xdrproc_t) xdr_void;
			_xdr_result = (xdrproc_t) xdr_u_long;
			local = (char *(*)(char *, struct svc_req *))
			    nvrproc_getlasterror_1_svc;
			break;

		case NVRPROC_GETRECSIZE:
			_xdr_argument = (xdrproc_t) xdr_GETRECSIZEargs;
			_xdr_result = (xdrproc_t) xdr_u_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_getrecsize_1_svc;
			break;

		case NVRPROC_CREATRECVOL:
			_xdr_argument = (xdrproc_t) xdr_CREATRECVOLargs;
			_xdr_result = (xdrproc_t) xdr_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_creatrecvol_1_svc;
			break;

		case NVRPROC_DELRECVOL:
			_xdr_argument = (xdrproc_t) xdr_DELRECVOLargs;
			_xdr_result = (xdrproc_t) xdr_int;
			local = (char *(*)(char *, struct svc_req *))nvrproc_delrecvol_1_svc;
			break;
		case NVRPROC_SEARCHRECORDBYORDER:
			_xdr_argument = (xdrproc_t) xdr_RECORDBYORDERargs;
			_xdr_result = (xdrproc_t) xdr_RECORDBYORDERres;
			local = (char *(*)(char *, struct svc_req *)) nvrproc_searchrecordbyorder_1_svc;
			break;
		default:
			svcerr_noproc(transp);
			return;
	}
	memset((char *)&argument, 0, sizeof(argument));
	if (!svc_getargs(transp, (xdrproc_t) _xdr_argument, (caddr_t) & argument)) {
		svcerr_decode(transp);
		TRACE_LOG("[RPC:%d]Got args error in SERVER!\n", rqstp->rq_proc);
		return;
	}
	result = (*local) ((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr(transp);	//客户端下载过程中强退时，服务器会退出
		TRACE_LOG("[RPC:%d]Send result to client failed!", rqstp->rq_proc);
	}
	if (!svc_freeargs(transp, (xdrproc_t) _xdr_argument, (caddr_t) & argument)) {
		fprintf(stderr, "%s", "unable to free arguments");
		TRACE_LOG("[RPC%d]Unable to free argments!", rqstp->rq_proc);
		exit(1);
	}
	return;
}


void
sigpipeHandler(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
}


int
main(int argc, char **argv)
{
	register SVCXPRT *transp;
	pthread_t pid, pid1;
	pthread_t pid_sstatus;


    if(initCameraInfos()<0){
        TRACE_LOG("Init CameraInofs error!");
        exit(1);
    }

    showCameraList();
    
	//added by wsr 20121030
	//open logfile
	openlog(__FILE__, LOG_PID, LOG_LOCAL1);
	//end
	
	pmap_unset(NVRPROG, NVRVERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf(stderr, "%s", "cannot create udp service.");
		TRACE_LOG("[RPC]Cannot create udp service!*exit*");
		exit(1);
	}
	if (!svc_register(transp, NVRPROG, NVRVERS, nvrprog_1, IPPROTO_UDP)) {
		fprintf(stderr, "%s", "unable to register (NVRPROG, NVRVERS, udp).");
		TRACE_LOG("[RPC]Unable to register by udp!*exit*");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf(stderr, "%s", "cannot create tcp service.");
		TRACE_LOG("[RPC]Cannot create tcp service!*exit*");
		exit(1);
	}
	if (!svc_register(transp, NVRPROG, NVRVERS, nvrprog_1, IPPROTO_TCP)) {
		fprintf(stderr, "%s", "unable to register (NVRPROG, NVRVERS, tcp).");
		TRACE_LOG("[RPC]Unable to register by tcp!*exit*");
		exit(1);
	}
	if (pthread_create(&pid, NULL, VolOpThread, NULL) != 0) {
		fprintf(stderr, "Create VolOPThread failure.\n");
		TRACE_LOG("[RPC]Create VolOPThread failure!*exit*");
		exit(1);
	}
	if (pthread_create(&pid1, NULL, WriteTnodeThread, NULL) != 0) {
		fprintf(stderr, "Create WriteTnodeThread failure.\n");
		TRACE_LOG("[RPC]Create WriteTnodeThread failure!*exit*");
		exit(1);
	}

	
	if (pthread_create(&pid_sstatus, NULL, watch_stream_status, NULL) != 0) {
		fprintf(stderr, "Create watch_stream_status Thread failure.\n");
		TRACE_LOG("[RPC]Create watch_stream_status Thread failure!*exit*");
		exit(1);
	}
	pthread_detach(pid_sstatus);
	
	struct sigaction act;
	act.sa_handler = sigpipeHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGPIPE, &act, 0);

	svc_run();
	fprintf(stderr, "%s", "svc_run returned");
	TRACE_LOG("[RPC] Main Process return!*exit*");
	
	//added by wsr 20121030
	closelog();
	//end
	exit(1);
	/* NOTREACHED */
}
