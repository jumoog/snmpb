/*
 * This C file has been generated by smidump 0.5.0.
 * It is intended to be used with the NET-SNMP agent library.
 *
 * This C file is derived from the BRIDGE-MIB module.
 *
 * $Id$
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "bridge-mib.h"

#include <ucd-snmp/asn1.h>
#include <ucd-snmp/snmp.h>
#include <ucd-snmp/snmp_api.h>
#include <ucd-snmp/snmp_impl.h>
#include <ucd-snmp/snmp_vars.h>

/*
 * Forward declaration of read methods for groups of scalars and tables:
 */

static unsigned char *
read_dot1dBase_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dBasePortEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dStp_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dStpPortEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dTp_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dTpFdbEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dTpPortEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
static unsigned char *
read_dot1dStaticEntry_stub(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);

/*
 * Forward declaration of write methods for writable objects:
 */

static int
write_dot1dStpPriority_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpBridgeMaxAge_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpBridgeHelloTime_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpBridgeForwardDelay_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpPortPriority_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpPortEnable_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpPortPathCost_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStpPortPathCost32_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dTpAgingTime_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStaticAddress_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStaticReceivePort_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStaticAllowedToGoTo_stub(int, u_char *, u_char, int, u_char *, oid *, int);
static int
write_dot1dStaticStatus_stub(int, u_char *, u_char, int, u_char *, oid *, int);

/*
 * Definitions of tags that are used internally to read/write
 * the selected object type. These tags should be unique.
 */

#define DOT1DBASEBRIDGEADDRESS           1
#define DOT1DBASENUMPORTS                2
#define DOT1DBASETYPE                    3

static oid dot1dBase_base[] = {1, 3, 6, 1, 2, 1, 17, 1};

struct variable dot1dBase_variables[] = {
    { DOT1DBASEBRIDGEADDRESS, ASN_OCTET_STR, RONLY, read_dot1dBase_stub, 1, {1} },
    { DOT1DBASENUMPORTS, ASN_INTEGER, RONLY, read_dot1dBase_stub, 1, {2} },
    { DOT1DBASETYPE, ASN_INTEGER, RONLY, read_dot1dBase_stub, 1, {3} },
};

#define DOT1DBASEPORT                    1
#define DOT1DBASEPORTIFINDEX             2
#define DOT1DBASEPORTCIRCUIT             3
#define DOT1DBASEPORTDELAYEXCEEDEDDISCARDS 4
#define DOT1DBASEPORTMTUEXCEEDEDDISCARDS 5

static oid dot1dBasePortEntry_base[] = {1, 3, 6, 1, 2, 1, 17, 1, 4, 1};

struct variable dot1dBasePortEntry_variables[] = {
    { DOT1DBASEPORT, ASN_INTEGER, RONLY, read_dot1dBasePortEntry_stub, 1, {1} },
    { DOT1DBASEPORTIFINDEX, ASN_INTEGER, RONLY, read_dot1dBasePortEntry_stub, 1, {2} },
    { DOT1DBASEPORTCIRCUIT, ASN_OBJECT_ID, RONLY, read_dot1dBasePortEntry_stub, 1, {3} },
    { DOT1DBASEPORTDELAYEXCEEDEDDISCARDS, ASN_INTEGER, RONLY, read_dot1dBasePortEntry_stub, 1, {4} },
    { DOT1DBASEPORTMTUEXCEEDEDDISCARDS, ASN_INTEGER, RONLY, read_dot1dBasePortEntry_stub, 1, {5} },
};

#define DOT1DSTPPROTOCOLSPECIFICATION    1
#define DOT1DSTPPRIORITY                 2
#define DOT1DSTPTIMESINCETOPOLOGYCHANGE  3
#define DOT1DSTPTOPCHANGES               4
#define DOT1DSTPDESIGNATEDROOT           5
#define DOT1DSTPROOTCOST                 6
#define DOT1DSTPROOTPORT                 7
#define DOT1DSTPMAXAGE                   8
#define DOT1DSTPHELLOTIME                9
#define DOT1DSTPHOLDTIME                 10
#define DOT1DSTPFORWARDDELAY             11
#define DOT1DSTPBRIDGEMAXAGE             12
#define DOT1DSTPBRIDGEHELLOTIME          13
#define DOT1DSTPBRIDGEFORWARDDELAY       14

static oid dot1dStp_base[] = {1, 3, 6, 1, 2, 1, 17, 2};

struct variable dot1dStp_variables[] = {
    { DOT1DSTPPROTOCOLSPECIFICATION, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {1} },
    { DOT1DSTPPRIORITY, ASN_INTEGER, RWRITE, read_dot1dStp_stub, 1, {2} },
    { DOT1DSTPTIMESINCETOPOLOGYCHANGE, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {3} },
    { DOT1DSTPTOPCHANGES, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {4} },
    { DOT1DSTPDESIGNATEDROOT, ASN_OCTET_STR, RONLY, read_dot1dStp_stub, 1, {5} },
    { DOT1DSTPROOTCOST, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {6} },
    { DOT1DSTPROOTPORT, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {7} },
    { DOT1DSTPMAXAGE, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {8} },
    { DOT1DSTPHELLOTIME, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {9} },
    { DOT1DSTPHOLDTIME, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {10} },
    { DOT1DSTPFORWARDDELAY, ASN_INTEGER, RONLY, read_dot1dStp_stub, 1, {11} },
    { DOT1DSTPBRIDGEMAXAGE, ASN_INTEGER, RWRITE, read_dot1dStp_stub, 1, {12} },
    { DOT1DSTPBRIDGEHELLOTIME, ASN_INTEGER, RWRITE, read_dot1dStp_stub, 1, {13} },
    { DOT1DSTPBRIDGEFORWARDDELAY, ASN_INTEGER, RWRITE, read_dot1dStp_stub, 1, {14} },
};

#define DOT1DSTPPORT                     1
#define DOT1DSTPPORTPRIORITY             2
#define DOT1DSTPPORTSTATE                3
#define DOT1DSTPPORTENABLE               4
#define DOT1DSTPPORTPATHCOST             5
#define DOT1DSTPPORTDESIGNATEDROOT       6
#define DOT1DSTPPORTDESIGNATEDCOST       7
#define DOT1DSTPPORTDESIGNATEDBRIDGE     8
#define DOT1DSTPPORTDESIGNATEDPORT       9
#define DOT1DSTPPORTFORWARDTRANSITIONS   10
#define DOT1DSTPPORTPATHCOST32           11

static oid dot1dStpPortEntry_base[] = {1, 3, 6, 1, 2, 1, 17, 2, 15, 1};

struct variable dot1dStpPortEntry_variables[] = {
    { DOT1DSTPPORT, ASN_INTEGER, RONLY, read_dot1dStpPortEntry_stub, 1, {1} },
    { DOT1DSTPPORTPRIORITY, ASN_INTEGER, RWRITE, read_dot1dStpPortEntry_stub, 1, {2} },
    { DOT1DSTPPORTSTATE, ASN_INTEGER, RONLY, read_dot1dStpPortEntry_stub, 1, {3} },
    { DOT1DSTPPORTENABLE, ASN_INTEGER, RWRITE, read_dot1dStpPortEntry_stub, 1, {4} },
    { DOT1DSTPPORTPATHCOST, ASN_INTEGER, RWRITE, read_dot1dStpPortEntry_stub, 1, {5} },
    { DOT1DSTPPORTDESIGNATEDROOT, ASN_OCTET_STR, RONLY, read_dot1dStpPortEntry_stub, 1, {6} },
    { DOT1DSTPPORTDESIGNATEDCOST, ASN_INTEGER, RONLY, read_dot1dStpPortEntry_stub, 1, {7} },
    { DOT1DSTPPORTDESIGNATEDBRIDGE, ASN_OCTET_STR, RONLY, read_dot1dStpPortEntry_stub, 1, {8} },
    { DOT1DSTPPORTDESIGNATEDPORT, ASN_OCTET_STR, RONLY, read_dot1dStpPortEntry_stub, 1, {9} },
    { DOT1DSTPPORTFORWARDTRANSITIONS, ASN_INTEGER, RONLY, read_dot1dStpPortEntry_stub, 1, {10} },
    { DOT1DSTPPORTPATHCOST32, ASN_INTEGER, RWRITE, read_dot1dStpPortEntry_stub, 1, {11} },
};

#define DOT1DTPLEARNEDENTRYDISCARDS      1
#define DOT1DTPAGINGTIME                 2

static oid dot1dTp_base[] = {1, 3, 6, 1, 2, 1, 17, 4};

struct variable dot1dTp_variables[] = {
    { DOT1DTPLEARNEDENTRYDISCARDS, ASN_INTEGER, RONLY, read_dot1dTp_stub, 1, {1} },
    { DOT1DTPAGINGTIME, ASN_INTEGER, RWRITE, read_dot1dTp_stub, 1, {2} },
};

#define DOT1DTPFDBADDRESS                1
#define DOT1DTPFDBPORT                   2
#define DOT1DTPFDBSTATUS                 3

static oid dot1dTpFdbEntry_base[] = {1, 3, 6, 1, 2, 1, 17, 4, 3, 1};

struct variable dot1dTpFdbEntry_variables[] = {
    { DOT1DTPFDBADDRESS, ASN_OCTET_STR, RONLY, read_dot1dTpFdbEntry_stub, 1, {1} },
    { DOT1DTPFDBPORT, ASN_INTEGER, RONLY, read_dot1dTpFdbEntry_stub, 1, {2} },
    { DOT1DTPFDBSTATUS, ASN_INTEGER, RONLY, read_dot1dTpFdbEntry_stub, 1, {3} },
};

#define DOT1DTPPORT                      1
#define DOT1DTPPORTMAXINFO               2
#define DOT1DTPPORTINFRAMES              3
#define DOT1DTPPORTOUTFRAMES             4
#define DOT1DTPPORTINDISCARDS            5

static oid dot1dTpPortEntry_base[] = {1, 3, 6, 1, 2, 1, 17, 4, 4, 1};

struct variable dot1dTpPortEntry_variables[] = {
    { DOT1DTPPORT, ASN_INTEGER, RONLY, read_dot1dTpPortEntry_stub, 1, {1} },
    { DOT1DTPPORTMAXINFO, ASN_INTEGER, RONLY, read_dot1dTpPortEntry_stub, 1, {2} },
    { DOT1DTPPORTINFRAMES, ASN_INTEGER, RONLY, read_dot1dTpPortEntry_stub, 1, {3} },
    { DOT1DTPPORTOUTFRAMES, ASN_INTEGER, RONLY, read_dot1dTpPortEntry_stub, 1, {4} },
    { DOT1DTPPORTINDISCARDS, ASN_INTEGER, RONLY, read_dot1dTpPortEntry_stub, 1, {5} },
};

#define DOT1DSTATICADDRESS               1
#define DOT1DSTATICRECEIVEPORT           2
#define DOT1DSTATICALLOWEDTOGOTO         3
#define DOT1DSTATICSTATUS                4

static oid dot1dStaticEntry_base[] = {1, 3, 6, 1, 2, 1, 17, 5, 1, 1};

struct variable dot1dStaticEntry_variables[] = {
    { DOT1DSTATICADDRESS, ASN_OCTET_STR, RWRITE, read_dot1dStaticEntry_stub, 1, {1} },
    { DOT1DSTATICRECEIVEPORT, ASN_INTEGER, RWRITE, read_dot1dStaticEntry_stub, 1, {2} },
    { DOT1DSTATICALLOWEDTOGOTO, ASN_OCTET_STR, RWRITE, read_dot1dStaticEntry_stub, 1, {3} },
    { DOT1DSTATICSTATUS, ASN_INTEGER, RWRITE, read_dot1dStaticEntry_stub, 1, {4} },
};



/*
 * Registration functions for the various MIB groups.
 */

int register_dot1dBase()
{
    return register_mib("dot1dBase",
         dot1dBase_variables,
         sizeof(struct variable),
         sizeof(dot1dBase_variables)/sizeof(struct variable),
         dot1dBase_base,
         sizeof(dot1dBase_base)/sizeof(oid));
};


int register_dot1dBasePortEntry()
{
    return register_mib("dot1dBasePortEntry",
         dot1dBasePortEntry_variables,
         sizeof(struct variable),
         sizeof(dot1dBasePortEntry_variables)/sizeof(struct variable),
         dot1dBasePortEntry_base,
         sizeof(dot1dBasePortEntry_base)/sizeof(oid));
};


int register_dot1dStp()
{
    return register_mib("dot1dStp",
         dot1dStp_variables,
         sizeof(struct variable),
         sizeof(dot1dStp_variables)/sizeof(struct variable),
         dot1dStp_base,
         sizeof(dot1dStp_base)/sizeof(oid));
};


int register_dot1dStpPortEntry()
{
    return register_mib("dot1dStpPortEntry",
         dot1dStpPortEntry_variables,
         sizeof(struct variable),
         sizeof(dot1dStpPortEntry_variables)/sizeof(struct variable),
         dot1dStpPortEntry_base,
         sizeof(dot1dStpPortEntry_base)/sizeof(oid));
};


int register_dot1dTp()
{
    return register_mib("dot1dTp",
         dot1dTp_variables,
         sizeof(struct variable),
         sizeof(dot1dTp_variables)/sizeof(struct variable),
         dot1dTp_base,
         sizeof(dot1dTp_base)/sizeof(oid));
};


int register_dot1dTpFdbEntry()
{
    return register_mib("dot1dTpFdbEntry",
         dot1dTpFdbEntry_variables,
         sizeof(struct variable),
         sizeof(dot1dTpFdbEntry_variables)/sizeof(struct variable),
         dot1dTpFdbEntry_base,
         sizeof(dot1dTpFdbEntry_base)/sizeof(oid));
};


int register_dot1dTpPortEntry()
{
    return register_mib("dot1dTpPortEntry",
         dot1dTpPortEntry_variables,
         sizeof(struct variable),
         sizeof(dot1dTpPortEntry_variables)/sizeof(struct variable),
         dot1dTpPortEntry_base,
         sizeof(dot1dTpPortEntry_base)/sizeof(oid));
};


int register_dot1dStaticEntry()
{
    return register_mib("dot1dStaticEntry",
         dot1dStaticEntry_variables,
         sizeof(struct variable),
         sizeof(dot1dStaticEntry_variables)/sizeof(struct variable),
         dot1dStaticEntry_base,
         sizeof(dot1dStaticEntry_base)/sizeof(oid));
};


/*
 * Read methods for groups of scalars and tables:
 */

static unsigned char *
read_dot1dBase_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dBase_t dot1dBase;

    /* check whether the instance identifier is valid */

    if (header_generic(vp, name, length, exact, var_len,
                       write_method) == MATCH_FAILED) {
        return NULL;
    }

    /* call the user supplied function to retrieve values */

    read_dot1dBase(&dot1dBase);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DBASEBRIDGEADDRESS:
        *var_len = dot1dBase._dot1dBaseBridgeAddressLength;
        return (unsigned char *) dot1dBase.dot1dBaseBridgeAddress;

    case DOT1DBASENUMPORTS:
        return (unsigned char *) &dot1dBase.dot1dBaseNumPorts;

    case DOT1DBASETYPE:
        return (unsigned char *) &dot1dBase.dot1dBaseType;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dBasePortEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dBasePortEntry_t dot1dBasePortEntry;

    /* call the user supplied function to retrieve values */

    read_dot1dBasePortEntry(&dot1dBasePortEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DBASEPORT:
        return (unsigned char *) &dot1dBasePortEntry.dot1dBasePort;

    case DOT1DBASEPORTIFINDEX:
        return (unsigned char *) &dot1dBasePortEntry.dot1dBasePortIfIndex;

    case DOT1DBASEPORTCIRCUIT:
        *var_len = dot1dBasePortEntry._dot1dBasePortCircuitLength;
        return (unsigned char *) dot1dBasePortEntry.dot1dBasePortCircuit;

    case DOT1DBASEPORTDELAYEXCEEDEDDISCARDS:
        return (unsigned char *) &dot1dBasePortEntry.dot1dBasePortDelayExceededDiscards;

    case DOT1DBASEPORTMTUEXCEEDEDDISCARDS:
        return (unsigned char *) &dot1dBasePortEntry.dot1dBasePortMtuExceededDiscards;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dStp_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dStp_t dot1dStp;

    /* check whether the instance identifier is valid */

    if (header_generic(vp, name, length, exact, var_len,
                       write_method) == MATCH_FAILED) {
        return NULL;
    }

    /* call the user supplied function to retrieve values */

    read_dot1dStp(&dot1dStp);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DSTPPROTOCOLSPECIFICATION:
        return (unsigned char *) &dot1dStp.dot1dStpProtocolSpecification;

    case DOT1DSTPPRIORITY:
        return (unsigned char *) &dot1dStp.dot1dStpPriority;

    case DOT1DSTPTIMESINCETOPOLOGYCHANGE:
        return (unsigned char *) &dot1dStp.dot1dStpTimeSinceTopologyChange;

    case DOT1DSTPTOPCHANGES:
        return (unsigned char *) &dot1dStp.dot1dStpTopChanges;

    case DOT1DSTPDESIGNATEDROOT:
        *var_len = dot1dStp._dot1dStpDesignatedRootLength;
        return (unsigned char *) dot1dStp.dot1dStpDesignatedRoot;

    case DOT1DSTPROOTCOST:
        return (unsigned char *) &dot1dStp.dot1dStpRootCost;

    case DOT1DSTPROOTPORT:
        return (unsigned char *) &dot1dStp.dot1dStpRootPort;

    case DOT1DSTPMAXAGE:
        return (unsigned char *) &dot1dStp.dot1dStpMaxAge;

    case DOT1DSTPHELLOTIME:
        return (unsigned char *) &dot1dStp.dot1dStpHelloTime;

    case DOT1DSTPHOLDTIME:
        return (unsigned char *) &dot1dStp.dot1dStpHoldTime;

    case DOT1DSTPFORWARDDELAY:
        return (unsigned char *) &dot1dStp.dot1dStpForwardDelay;

    case DOT1DSTPBRIDGEMAXAGE:
        return (unsigned char *) &dot1dStp.dot1dStpBridgeMaxAge;

    case DOT1DSTPBRIDGEHELLOTIME:
        return (unsigned char *) &dot1dStp.dot1dStpBridgeHelloTime;

    case DOT1DSTPBRIDGEFORWARDDELAY:
        return (unsigned char *) &dot1dStp.dot1dStpBridgeForwardDelay;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dStpPortEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dStpPortEntry_t dot1dStpPortEntry;

    /* call the user supplied function to retrieve values */

    read_dot1dStpPortEntry(&dot1dStpPortEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DSTPPORT:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPort;

    case DOT1DSTPPORTPRIORITY:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortPriority;

    case DOT1DSTPPORTSTATE:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortState;

    case DOT1DSTPPORTENABLE:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortEnable;

    case DOT1DSTPPORTPATHCOST:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortPathCost;

    case DOT1DSTPPORTDESIGNATEDROOT:
        *var_len = dot1dStpPortEntry._dot1dStpPortDesignatedRootLength;
        return (unsigned char *) dot1dStpPortEntry.dot1dStpPortDesignatedRoot;

    case DOT1DSTPPORTDESIGNATEDCOST:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortDesignatedCost;

    case DOT1DSTPPORTDESIGNATEDBRIDGE:
        *var_len = dot1dStpPortEntry._dot1dStpPortDesignatedBridgeLength;
        return (unsigned char *) dot1dStpPortEntry.dot1dStpPortDesignatedBridge;

    case DOT1DSTPPORTDESIGNATEDPORT:
        *var_len = dot1dStpPortEntry._dot1dStpPortDesignatedPortLength;
        return (unsigned char *) dot1dStpPortEntry.dot1dStpPortDesignatedPort;

    case DOT1DSTPPORTFORWARDTRANSITIONS:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortForwardTransitions;

    case DOT1DSTPPORTPATHCOST32:
        return (unsigned char *) &dot1dStpPortEntry.dot1dStpPortPathCost32;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dTp_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dTp_t dot1dTp;

    /* check whether the instance identifier is valid */

    if (header_generic(vp, name, length, exact, var_len,
                       write_method) == MATCH_FAILED) {
        return NULL;
    }

    /* call the user supplied function to retrieve values */

    read_dot1dTp(&dot1dTp);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DTPLEARNEDENTRYDISCARDS:
        return (unsigned char *) &dot1dTp.dot1dTpLearnedEntryDiscards;

    case DOT1DTPAGINGTIME:
        return (unsigned char *) &dot1dTp.dot1dTpAgingTime;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dTpFdbEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dTpFdbEntry_t dot1dTpFdbEntry;

    /* call the user supplied function to retrieve values */

    read_dot1dTpFdbEntry(&dot1dTpFdbEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DTPFDBADDRESS:
        *var_len = dot1dTpFdbEntry._dot1dTpFdbAddressLength;
        return (unsigned char *) dot1dTpFdbEntry.dot1dTpFdbAddress;

    case DOT1DTPFDBPORT:
        return (unsigned char *) &dot1dTpFdbEntry.dot1dTpFdbPort;

    case DOT1DTPFDBSTATUS:
        return (unsigned char *) &dot1dTpFdbEntry.dot1dTpFdbStatus;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dTpPortEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dTpPortEntry_t dot1dTpPortEntry;

    /* call the user supplied function to retrieve values */

    read_dot1dTpPortEntry(&dot1dTpPortEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DTPPORT:
        return (unsigned char *) &dot1dTpPortEntry.dot1dTpPort;

    case DOT1DTPPORTMAXINFO:
        return (unsigned char *) &dot1dTpPortEntry.dot1dTpPortMaxInfo;

    case DOT1DTPPORTINFRAMES:
        return (unsigned char *) &dot1dTpPortEntry.dot1dTpPortInFrames;

    case DOT1DTPPORTOUTFRAMES:
        return (unsigned char *) &dot1dTpPortEntry.dot1dTpPortOutFrames;

    case DOT1DTPPORTINDISCARDS:
        return (unsigned char *) &dot1dTpPortEntry.dot1dTpPortInDiscards;

    default:
         ERROR_MSG("");
    }

    return NULL;
}

static unsigned char *
read_dot1dStaticEntry_stub(struct variable *vp,
    oid     *name,
    size_t  *length,
    int     exact,
    size_t  *var_len,
    WriteMethod **write_method)
{
    static dot1dStaticEntry_t dot1dStaticEntry;

    /* call the user supplied function to retrieve values */

    read_dot1dStaticEntry(&dot1dStaticEntry);

    /* return the current value of the variable */

    switch (vp->magic) {

    case DOT1DSTATICADDRESS:
        *var_len = dot1dStaticEntry._dot1dStaticAddressLength;
        return (unsigned char *) dot1dStaticEntry.dot1dStaticAddress;

    case DOT1DSTATICRECEIVEPORT:
        return (unsigned char *) &dot1dStaticEntry.dot1dStaticReceivePort;

    case DOT1DSTATICALLOWEDTOGOTO:
        *var_len = dot1dStaticEntry._dot1dStaticAllowedToGoToLength;
        return (unsigned char *) dot1dStaticEntry.dot1dStaticAllowedToGoTo;

    case DOT1DSTATICSTATUS:
        return (unsigned char *) &dot1dStaticEntry.dot1dStaticStatus;

    default:
         ERROR_MSG("");
    }

    return NULL;
}


/*
 * Forward declaration of write methods for writable objects:
 */

static int
write_dot1dStpPriority_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpBridgeMaxAge_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpBridgeHelloTime_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpBridgeForwardDelay_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpPortPriority_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpPortEnable_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpPortPathCost_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStpPortPathCost32_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dTpAgingTime_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStaticAddress_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStaticReceivePort_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStaticAllowedToGoTo_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}

static int
write_dot1dStaticStatus_stub(int action,
    u_char   *var_val,
    u_char   var_val_type,
    int      var_val_len,
    u_char   *statP,
    oid      *name,
    int      name_len)
{
    return SNMP_ERR_NOERROR;
}


