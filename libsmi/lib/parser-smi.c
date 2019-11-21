/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         smiparse
#define yylex           smilex
#define yyerror         smierror
#define yydebug         smidebug
#define yynerrs         sminerrs


/* Copy the first part of user declarations.  */
#line 17 "parser-smi.y" /* yacc.c:339  */


#include <config.h>
    
#ifdef BACKEND_SMI

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#if defined(_MSC_VER)
#include <malloc.h>
#endif

#include "smi.h"
#include "error.h"
#include "parser-smi.h"
#include "scanner-smi.h"
#include "smi-data.h"
#include "smi-check.h"
#include "util.h"
    
#ifdef HAVE_DMALLOC_H
#include <dmalloc.h>
#endif


#define thisParserPtr      ((Parser *)parserPtr)
#define thisModulePtr     (((Parser *)parserPtr)->modulePtr)


    
/*
 * NOTE: The argument lvalp is not really a void pointer. Unfortunately,
 * we don't know it better at this point. bison generated C code declares
 * YYSTYPE just a few lines below based on the `%union' declaration.
 */
extern int yylex(void *lvalp, Parser *parserPtr);



static int	   impliedFlag;
static SmiNodekind variationkind;
static SmiBasetype defaultBasetype;
static int	   indexFlag;

/*
 * Values for the indexFlag variable
 */
#define INDEXFLAG_NONE     0
#define INDEXFLAG_PIBINDEX 1
#define INDEXFLAG_AUGMENTS 2
#define INDEXFLAG_EXTENDS  3
 

#define SMI_EPOCH	631152000	/* 01 Jan 1990 00:00:00 */ 

 

static char *convertImportv2[] = {
    "RFC1155-SMI", "internet",	    "SNMPv2-SMI", "internet",
    "RFC1155-SMI", "directory",	    "SNMPv2-SMI", "directory",
    "RFC1155-SMI", "mgmt",	    "SNMPv2-SMI", "mgmt",
    "RFC1155-SMI", "experimental",  "SNMPv2-SMI", "experimental",
    "RFC1155-SMI", "private",	    "SNMPv2-SMI", "private",
    "RFC1155-SMI", "enterprises",   "SNMPv2-SMI", "enterprises",
    "RFC1155-SMI", "IpAddress",     "SNMPv2-SMI", "IpAddress",
    "RFC1155-SMI", "Counter",       "SNMPv2-SMI", "Counter32",
    "RFC1155-SMI", "Gauge",         "SNMPv2-SMI", "Gauge32",
    "RFC1155-SMI", "TimeTicks",     "SNMPv2-SMI", "TimeTicks",
    "RFC1155-SMI", "Opaque",        "SNMPv2-SMI", "Opaque",
    "RFC1065-SMI", "internet",	    "SNMPv2-SMI", "internet",
    "RFC1065-SMI", "directory",	    "SNMPv2-SMI", "directory",
    "RFC1065-SMI", "mgmt",	    "SNMPv2-SMI", "mgmt",
    "RFC1065-SMI", "experimental",  "SNMPv2-SMI", "experimental",
    "RFC1065-SMI", "private",	    "SNMPv2-SMI", "private",
    "RFC1065-SMI", "enterprises",   "SNMPv2-SMI", "enterprises",
    "RFC1065-SMI", "IpAddress",     "SNMPv2-SMI", "IpAddress",
    "RFC1065-SMI", "Counter",       "SNMPv2-SMI", "Counter32",
    "RFC1065-SMI", "Gauge",         "SNMPv2-SMI", "Gauge32",
    "RFC1065-SMI", "TimeTicks",     "SNMPv2-SMI", "TimeTicks",
    "RFC1065-SMI", "Opaque",        "SNMPv2-SMI", "Opaque",
    "RFC1213-MIB", "mib-2",         "SNMPv2-SMI", "mib-2",    
    "RFC1213-MIB", "DisplayString", "SNMPv2-TC",  "DisplayString",    
    NULL, NULL, NULL, NULL
};



static void
checkDescr(Parser *parser, char *descr)
{
    if (descr) {
	if (descr[0] == 0) {
	    smiPrintError(parser, ERR_EMPTY_DESCRIPTION);
	}
	/* we might want to add more checks since I have recently
	   seen things like DESCRIPTION "." to cirumvent warnings */
    }
}
 

 
static void
checkNameLen(Parser *parser, char *name, int error_32, int error_64)
{
    int len = strlen(name);
    
    if (len > 64) {
	smiPrintError(parser, error_64, name);
    } else if (len > 32) {
	smiPrintError(parser, error_32, name);
    }
}


 
static void
checkModuleName(Parser *parserPtr, Module *modulePtr)
{
     static char *mib_ignore[] = {
	 "SNMPv2-SMI", "SNMPv2-TC", "SNMPv2-CONF", NULL
     };
     
     static char *pib_ignore[] = {
	 "COPS-PR-SPPI", "COPS-PR-SPPI-TC",
	 "SNMPv2-SMI", "SNMPv2-TC", "SNMPv2-CONF", NULL
     };

     const char *name = thisModulePtr->export.name;
     const int len = strlen(name);
     int i;

     switch (modulePtr->export.language) {
     case SMI_LANGUAGE_SMIV1:
     case SMI_LANGUAGE_SMIV2:
     case SMI_LANGUAGE_SMING:
	 for (i = 0; mib_ignore[i]; i++) {
	     if (strcmp(mib_ignore[i], name) == 0) {
		 return;
	     }
	 }
	 if (len > 3 && (strcmp(name + len - 4, "-MIB") != 0)) {
	     smiPrintError(parserPtr, ERR_MIB_MODULENAME_SUFFIX, name);
	     return;
	 }
	 break;
     case SMI_LANGUAGE_SPPI:
	 for (i = 0; pib_ignore[i]; i++) {
	     if (strcmp(pib_ignore[i], name) == 0) {
		 return;
	     }
	 }
	 if (len > 3 && (strcmp(name + len - 4, "-PIB") != 0)) {
	     smiPrintError(parserPtr, ERR_PIB_MODULENAME_SUFFIX, name);
	 }
	 break;
     case SMI_LANGUAGE_YANG:
     case SMI_LANGUAGE_UNKNOWN:
	 break;
     }
}



static void
checkModuleIdentity(Parser *parserPtr, Module *modulePtr)
{
    if ((modulePtr->export.language == SMI_LANGUAGE_SMIV2)
	&& (modulePtr->numModuleIdentities < 1)
	&& strcmp(modulePtr->export.name, "SNMPv2-SMI")
	&& strcmp(modulePtr->export.name, "SNMPv2-CONF")
	&& strcmp(modulePtr->export.name, "SNMPv2-TC")
        && strcmp(modulePtr->export.name, "COPS-PR-SPPI")) {
	smiPrintError(parserPtr, ERR_NO_MODULE_IDENTITY);
    }
}



static void
checkObjects(Parser *parserPtr, Module *modulePtr)
{
    Object *objectPtr;
    Node *nodePtr;
    int i;
    Type *counterTypePtr, *counter32TypePtr, *counter64TypePtr;
    
    counterTypePtr = findTypeByName("Counter");
    counter32TypePtr = findTypeByModulenameAndName("SNMPv2-SMI", "Counter32");
    counter64TypePtr = findTypeByModulenameAndName("SNMPv2-SMI", "Counter64");
    
    for (objectPtr = modulePtr->firstObjectPtr;
	 objectPtr; objectPtr = objectPtr->nextPtr) {

	Object *parentPtr;
	
	if ((objectPtr->export.decl != SMI_DECL_UNKNOWN) &&
	    objectPtr->nodePtr->parentPtr &&
	    objectPtr->nodePtr->parentPtr->lastObjectPtr) {
	    parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
	} else {
	    parentPtr = NULL;
	}

	/*
	 * Set nodekinds of all newly defined objects.
	 */
	
	if (objectPtr->export.decl == SMI_DECL_MODULEIDENTITY) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NODE;
	} else if ((objectPtr->export.decl == SMI_DECL_VALUEASSIGNMENT) ||
		   (objectPtr->export.decl == SMI_DECL_OBJECTIDENTITY)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NODE;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (objectPtr->typePtr) &&
		   (objectPtr->typePtr->export.decl == SMI_DECL_IMPL_SEQUENCEOF)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_TABLE;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   ((objectPtr->export.indexkind != SMI_INDEX_UNKNOWN)
		    || (parentPtr
			&& parentPtr->export.nodekind == SMI_NODEKIND_TABLE))) {
	    objectPtr->export.nodekind = SMI_NODEKIND_ROW;
	} else if ((objectPtr->export.decl == SMI_DECL_NOTIFICATIONTYPE) ||
		   (objectPtr->export.decl == SMI_DECL_TRAPTYPE)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NOTIFICATION;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTGROUP) ||
		   (objectPtr->export.decl == SMI_DECL_NOTIFICATIONGROUP)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_GROUP;
	} else if (objectPtr->export.decl == SMI_DECL_MODULECOMPLIANCE) {
	    objectPtr->export.nodekind = SMI_NODEKIND_COMPLIANCE;
	} else if (objectPtr->export.decl == SMI_DECL_AGENTCAPABILITIES) {
	    objectPtr->export.nodekind = SMI_NODEKIND_CAPABILITIES;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (parentPtr) &&
		   ((parentPtr->export.indexkind != SMI_INDEX_UNKNOWN)
		    || (parentPtr
			&& parentPtr->export.nodekind == SMI_NODEKIND_ROW))) {
	    objectPtr->export.nodekind = SMI_NODEKIND_COLUMN;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (parentPtr) &&
		   (parentPtr->export.indexkind == SMI_INDEX_UNKNOWN)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_SCALAR;
	}
    }

    for (objectPtr = modulePtr->firstObjectPtr;
	 objectPtr; objectPtr = objectPtr->nextPtr) {

	Object *parentPtr;
	
	if (objectPtr->nodePtr->parentPtr &&
	    objectPtr->nodePtr->parentPtr->lastObjectPtr) {
	    parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
	} else {
	    parentPtr = NULL;
	}

	/*
	 * Check whether the associated type resolves to a known base type.
	 */
	
	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && objectPtr->typePtr->export.basetype == SMI_BASETYPE_UNKNOWN) {
	    smiPrintErrorAtLine(parserPtr, ERR_BASETYPE_UNKNOWN,
				objectPtr->line,
				objectPtr->typePtr->export.name ?
				objectPtr->typePtr->export.name : "[unknown]",
				objectPtr->export.name);
	}

	/*
	 * Mark types that are referenced in this module.
	 */

	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && (objectPtr->typePtr->export.decl == SMI_DECL_TYPEDEF
		|| objectPtr->typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION
		|| objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE)) {
	    addTypeFlags(objectPtr->typePtr, FLAG_INSYNTAX);
	    if (objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE) {
		addTypeFlags(objectPtr->typePtr->parentPtr, FLAG_INSYNTAX);
	    }
	}
	
	/*
	 * Check whether the status of the associated type matches the
	 * status of the object.
	 */

	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && (objectPtr->export.status < objectPtr->typePtr->export.status)) {
	    if (objectPtr->typePtr->export.status == SMI_STATUS_DEPRECATED) {
		smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_DEPRECATED,
				    objectPtr->line,
				    objectPtr->typePtr->export.name,
				    objectPtr->export.name);
	    }
	    if (objectPtr->typePtr->export.status == SMI_STATUS_OBSOLETE) {
		smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_OBSOLETE,
				    objectPtr->line,
				    objectPtr->typePtr->export.name,
				    objectPtr->export.name);
	    }
	}

	/*
	 * Check the nodekind of the parent node.
	 */

	if (parentPtr) {
	    switch (objectPtr->export.nodekind) {
	    case SMI_NODEKIND_COLUMN:
		if (parentPtr->export.nodekind != SMI_NODEKIND_ROW) {
		    smiPrintErrorAtLine(parserPtr, ERR_COLUMN_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_ROW:
		if (parentPtr->export.nodekind != SMI_NODEKIND_TABLE) {
		    smiPrintErrorAtLine(parserPtr, ERR_ROW_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}

		/* Example: crashing in JETDIRECT3-MIB where name is NULL */
		if (objectPtr->typePtr && !objectPtr->typePtr->export.name)
			return;

		if (parentPtr->typePtr && parentPtr->typePtr->parentPtr &&
		    strcmp(parentPtr->typePtr->parentPtr->export.name,
			   objectPtr->typePtr->export.name)) {
		    smiPrintErrorAtLine(parserPtr, ERR_TABLE_ROW_TYPE_MISMATCH,
					objectPtr->line,
					objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_TABLE:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_TABLE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_SCALAR:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_SCALAR_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_NOTIFICATION:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_NODE) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN)) {
		    smiPrintErrorAtLine(parserPtr, ERR_NOTIFICATION_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		if (parserPtr && parentPtr->nodePtr->parentPtr &&
		    parentPtr->nodePtr->parentPtr->lastObjectPtr) {
		    Object *parent2Ptr = parentPtr->nodePtr->parentPtr->lastObjectPtr;
		    if ((parent2Ptr->export.nodekind != SMI_NODEKIND_NODE) &&
			(parent2Ptr->export.nodekind != SMI_NODEKIND_UNKNOWN)) {
			smiPrintErrorAtLine(parserPtr,
					    ERR_NOTIFICATION_PARENT_TYPE,
					    objectPtr->line,
					    objectPtr->export.name);
		    }
		}
		break;
	    case SMI_NODEKIND_NODE:
		/* Node defined by OBJECT IDENTIFIER assignments can have
		   arbitrary parent node. */
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE) &&
		    (objectPtr->export.decl != SMI_DECL_VALUEASSIGNMENT)) {
		    smiPrintErrorAtLine(parserPtr, ERR_NODE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_GROUP:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_GROUP_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_COMPLIANCE:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_COMPLIANCE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_CAPABILITIES:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_CAPABILITIES_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    }
	}

	/*
	 * Check whether a row has only object-type children and
	 * that their types are consistent with the type of the
	 * row.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    smiCheckRowMembers(parserPtr, objectPtr);
	}
	
	/*
	 * Check whether groups only contain scalars, columns and
	 * notifications.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_GROUP) {
	    smiCheckGroupMembers(parserPtr, objectPtr);
	}

	/*
	 * Check whether compliance statements contain out of date
	 * groups or objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_COMPLIANCE) {
	    smiCheckComplianceStatus(parserPtr, objectPtr);
	}

	/*
	 * Check whether notification statements contain useful
	 * objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_NOTIFICATION) {
	    smiCheckNotificationOid(parserPtr, modulePtr, objectPtr);
	    smiCheckNotificationMembers(parserPtr, objectPtr);
	}

        if (modulePtr->export.language != SMI_LANGUAGE_SPPI) {
	    /*
	     * Check whether tables and rows are not accessible
	     * (RFC 2578 7.1.12).
	     */

	    if (objectPtr->export.nodekind == SMI_NODEKIND_TABLE
	        && objectPtr->export.access != SMI_ACCESS_NOT_ACCESSIBLE) {
	        smiPrintErrorAtLine(parserPtr, ERR_TABLE_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }

	    if (objectPtr->export.nodekind == SMI_NODEKIND_ROW
	        && objectPtr->export.access != SMI_ACCESS_NOT_ACCESSIBLE) {
	        smiPrintErrorAtLine(parserPtr, ERR_ROW_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }

	    /*
	     * Check whether counter objects are read-only or
	     * accessible-for-notify (RFC 2578, 7.1.6).
	     */
	    if (((objectPtr->export.nodekind == SMI_NODEKIND_SCALAR) ||
		 (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN)) &&
	        (objectPtr->export.access != SMI_ACCESS_NOTIFY) &&
		(objectPtr->export.access != SMI_ACCESS_READ_ONLY) &&
		(smiTypeDerivedFrom(objectPtr->typePtr, counterTypePtr) ||
		 smiTypeDerivedFrom(objectPtr->typePtr, counter32TypePtr) ||
		 smiTypeDerivedFrom(objectPtr->typePtr, counter64TypePtr))) {
	        smiPrintErrorAtLine(parserPtr, ERR_COUNTER_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }
        }
	
	/*
	 * Check whether a row's subid is 1, see RFC 2578 7.10 (1).
	 */
	
	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    int len;
	    
	    if (objectPtr->nodePtr->subid != 1) {
		smiPrintErrorAtLine(parserPtr, ERR_ROW_SUBID_ONE,
				    objectPtr->line, objectPtr->export.name);
	    }

	    len = strlen(objectPtr->export.name);
	    if (len < 6 || strcmp(objectPtr->export.name+len-5, "Entry")) {
		smiPrintErrorAtLine(parserPtr, ERR_ROWNAME_ENTRY,
				    objectPtr->line, objectPtr->export.name);
	    } else {

		/*
		 * This misreports some cases where the table name
		 * does not have the "*Table" suffix.  This is trying
		 * to allow Entry names of either fooTableEntry or
		 * fooEntry.
		 */
		if (parentPtr &&
		    !(((int)strlen(parentPtr->export.name) == len ||
		       (int)strlen(parentPtr->export.name) == len - 5) &&
		      !strncmp(objectPtr->export.name, parentPtr->export.name,
			len - 5))) {
		    smiPrintErrorAtLine(parserPtr, ERR_ROWNAME_TABLENAME,
					objectPtr->line,
					objectPtr->export.name,
					parentPtr->export.name);
		}
	    }
	}

	/*
	 * Check whether a row's SEQUENCE contains exactly the list
	 * of child nodes (columns).  An unknown SEQUENCE type
	 * is handled later.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW &&
	    ((objectPtr->typePtr->flags & FLAG_INCOMPLETE) == 0)) {
	    List *p;
	    Node *seqNodePtr, *childNodePtr;
	    Object *colPtr;
	    int i;
	    
	    /*
	     * Walk through the SEQUENCE elements and find those
	     * that are misordered or have no matching columnar object.
	     */
	    for (p = objectPtr->typePtr->listPtr, i = 1,
		     childNodePtr = objectPtr->nodePtr->firstChildPtr;
		 p && childNodePtr;
		 p = p->nextPtr, childNodePtr = childNodePtr->nextPtr, i++) {
		seqNodePtr = ((Object *)p->ptr)->nodePtr;

		if (seqNodePtr->parentPtr != childNodePtr->parentPtr) {
		    smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_NO_COLUMN,
					objectPtr->typePtr->line,
					i,
					((Object *)p->ptr)->export.name,
					objectPtr->export.name);
		    continue;
		}

		if (seqNodePtr != childNodePtr) {
		    smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_ORDER,
					objectPtr->typePtr->line,
					i,
					((Object *)p->ptr)->export.name,
					objectPtr->export.name);
		    break;
		}
	    }
	    if ((p != NULL) && (childNodePtr == NULL)) {
		smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_NO_COLUMN,
				    objectPtr->typePtr->line,
				    i, 
				    ((Object *)p->ptr)->export.name,
				    objectPtr->export.name);
	    }

	    /*
	     * Walk through all child objects and find those
	     * that were missing in the SEQUENCE.
	     */
	    for (childNodePtr = objectPtr->nodePtr->firstChildPtr;
		 childNodePtr; childNodePtr = childNodePtr->nextPtr) {
		colPtr = findObjectByModuleAndNode(modulePtr, childNodePtr);
		if (!colPtr) continue;
		for (p = objectPtr->typePtr->listPtr; p; p = p->nextPtr) {
		    if (((Object *)p->ptr)->nodePtr == colPtr->nodePtr)
			break;
		}
		if (!p) {
		    if (colPtr->export.name) {
			/*
			 * Don't complain, if it's an implcitly defined
			 * unnamed node (could happen for parent node of
			 * TRAP-TYPE definitions).
			 */
			smiPrintErrorAtLine(parserPtr,
					    ERR_SEQUENCE_MISSING_COLUMN,
					    objectPtr->typePtr->line,
					    objectPtr->typePtr->export.name,
					    colPtr->export.name);
		    }
		}
	    }
	    
	}
	
	if (objectPtr->export.nodekind == SMI_NODEKIND_TABLE) {
	    int len;

	    len = strlen(objectPtr->export.name);
	    if (len < 6 || strcmp(objectPtr->export.name+len-5, "Table")) {
		smiPrintErrorAtLine(parserPtr, ERR_TABLENAME_TABLE,
				    objectPtr->line, objectPtr->export.name);
	    }
	}

	/*
	 * TODO: check whether the row is the only node below the
         * table node
	 */

	/*
	 * Check references to unknown identifiers.
	 */

	if ((objectPtr->flags & FLAG_INCOMPLETE) &&
	    (objectPtr->export.decl != SMI_DECL_IMPL_OBJECT)) {
	    if (objectPtr->export.name) {
		smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_OIDLABEL,
				    objectPtr->line, objectPtr->export.name);
	    } else {
		smiPrintErrorAtLine(parserPtr, ERR_IMPLICIT_NODE,
				    objectPtr->line);
	    }
	}

	/*
	 * Adjust the status of implicit type definitions.
	 */
	
	if (objectPtr->typePtr
	    && (objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE)
	    && (objectPtr->typePtr->export.status == SMI_STATUS_UNKNOWN)) {
	    objectPtr->typePtr->export.status = objectPtr->export.status;
	}

	/*
	 * Link implicit type definition from refinements into
	 * the type derivation tree. Adjust the status of implicit
	 * type definitions in refinements. 
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_COMPLIANCE) {

	    List *listPtr;

	    for (listPtr = objectPtr->refinementlistPtr;
		 listPtr;
		 listPtr = listPtr->nextPtr) {

		Refinement *refinementPtr;
		Type *typePtr;
		
		refinementPtr = ((Refinement *)(listPtr->ptr));
		typePtr = refinementPtr->typePtr;
		if (typePtr) {
		    if (typePtr->export.status == SMI_STATUS_UNKNOWN) {
			typePtr->export.status = objectPtr->export.status;
		    }
		}

		typePtr = refinementPtr->writetypePtr;
		if (typePtr) {
		    if (typePtr->export.status == SMI_STATUS_UNKNOWN) {
			typePtr->export.status = objectPtr->export.status;
		    }
		}
		
	    }
	    /* relocate the refinement type into the type tree */
	    /* relocate the write refinement type into the type tree */
	}

	/*
	 * Set the oidlen/oid values that are not yet correct.
	 */

	if (objectPtr->export.oidlen == 0) {
	    if (objectPtr->nodePtr->oidlen == 0) {
		for (nodePtr = objectPtr->nodePtr, i = 1;
		     nodePtr->parentPtr != thisParserPtr->pendingNodePtr &&
			 nodePtr->parentPtr != smiHandle->rootNodePtr &&
			 nodePtr != nodePtr->parentPtr &&
			 nodePtr->parentPtr != NULL &&
			 i <= 128;
		     nodePtr = nodePtr->parentPtr, i++);
		if ((objectPtr->export.name) &&
		    ((i > 128) || (nodePtr == nodePtr->parentPtr))) {
		    smiPrintErrorAtLine(parserPtr, ERR_OID_RECURSIVE,
					objectPtr->line,
					objectPtr->export.name);
		}
		objectPtr->nodePtr->oid = smiMalloc(i * sizeof(SmiSubid));
		objectPtr->nodePtr->oidlen = i;
		for (nodePtr = objectPtr->nodePtr; i > 0; i--) {
		    objectPtr->nodePtr->oid[i-1] = nodePtr->subid;
		    nodePtr = nodePtr->parentPtr;
		}
	    }
	    objectPtr->export.oidlen = objectPtr->nodePtr->oidlen;
	    objectPtr->export.oid = objectPtr->nodePtr->oid;
	}

	if ((objectPtr->export.decl != SMI_DECL_UNKNOWN)
	    && (objectPtr->export.nodekind != SMI_NODEKIND_NODE)
	    && (objectPtr->export.nodekind != SMI_NODEKIND_UNKNOWN)
	    && objectPtr->export.name
	    && objectPtr->export.oid[objectPtr->export.oidlen-1] == 0
	    && objectPtr->export.oidlen != 2 && objectPtr->export.oid[0] != 0) {
	    smiPrintErrorAtLine(parserPtr, ERR_OID_ADMIN_ZERO,
				objectPtr->line,
				objectPtr->export.name);
	}

	/*
	 * Check whether the module identity is registered in a well
	 * known controlled location. 
	 */

	if (objectPtr->export.decl == SMI_DECL_MODULEIDENTITY) {
	    smiCheckModuleIdentityRegistration(parserPtr, objectPtr);
	}

	/*
	 * Check table linkage constraints for row objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    switch (objectPtr->export.indexkind) {
	    case SMI_INDEX_INDEX:
		smiCheckIndex(parserPtr, objectPtr);
		break;
	    case SMI_INDEX_AUGMENT:
            case SMI_INDEX_SPARSE:
		smiCheckAugment(parserPtr, objectPtr);
		break;
	    case SMI_INDEX_UNKNOWN:
		smiPrintErrorAtLine(parserPtr, ERR_INDEX_MISSING,
				    objectPtr->line,
				    objectPtr->export.name);
		break;
	    default:
		break;
	    }
	}
	
	/*
	 * Determine the longest common OID prefix of all nodes.
	 */

	if (!modulePtr->prefixNodePtr) {
	    modulePtr->prefixNodePtr = objectPtr->nodePtr;
	} else {
	    if (objectPtr->nodePtr->oidlen < modulePtr->prefixNodePtr->oidlen) {
		Node *nodePtr = findNodeByOid(objectPtr->nodePtr->oidlen,
					      modulePtr->prefixNodePtr->oid);
		if (nodePtr)
		    modulePtr->prefixNodePtr = nodePtr;
		else
		    smiPrintError(parserPtr, ERR_OTHER_ERROR,
				  "Failed to create complete object tree - "
				  "expect incorrect output");
	    }
	    for (i = 0; i < modulePtr->prefixNodePtr->oidlen; i++) {
		if (modulePtr->prefixNodePtr->oid[i] !=
		    objectPtr->nodePtr->oid[i]) {
		    modulePtr->prefixNodePtr =
			findNodeByOid(i, modulePtr->prefixNodePtr->oid);
		    break;
		}
	    }
	}
    }

    if (modulePtr->export.language == SMI_LANGUAGE_SMIV2) {
	for (objectPtr = modulePtr->firstObjectPtr;
	     objectPtr; objectPtr = objectPtr->nextPtr) {
	    
	    /*
	     * Check whether all objects and notifications are contained in at
	     * least one conformance group (RFC 2580 3.3 and 4.1).
	     */
	    
	    smiCheckGroupMembership(parserPtr, objectPtr);
	}
    }

    if (modulePtr->export.language == SMI_LANGUAGE_SPPI) {
        Object *parentPtr;
        
        for (objectPtr = modulePtr->firstObjectPtr;
             objectPtr; objectPtr = objectPtr->nextPtr) {
            /*
             * All checks for SPPI constructs
             */
            if (objectPtr->nodePtr->parentPtr)
                parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
            else
                parentPtr = NULL;
            
            /*
             * Do all rows contain a PIB-INDEX/AUGMENTS/EXTENDS ?
             * See RFC 3159 7.5, 7.7, 7.8
             */
            if (parentPtr  &&
                (parentPtr->export.nodekind == SMI_NODEKIND_TABLE) &&
                (objectPtr->export.indexkind != SMI_INDEX_INDEX) &&
                (objectPtr->export.indexkind != SMI_INDEX_AUGMENT) &&
                (objectPtr->export.indexkind != SMI_INDEX_SPARSE))
                smiPrintErrorAtLine(parserPtr, ERR_ROW_LACKS_PIB_INDEX,
                                    objectPtr->line);

            /*
             * Does any non row contain a PIB-INDEX/AUGMENTS/EXTENDS ?
             * See RFC 3159 7.5, 7.7, 7.8
             */
            if ((objectPtr->export.nodekind != SMI_NODEKIND_ROW) &&
                (objectPtr->export.indexkind != SMI_INDEX_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_INDEX_FOR_NON_ROW_TYPE,
                                    objectPtr->line);

            /*
             * Check the PIB-INDEX and other indices
             */
            if ((objectPtr->export.nodekind == SMI_NODEKIND_ROW) &&
                (objectPtr->export.indexkind == SMI_INDEX_INDEX)) {

                /*
                 * Only the first element (PIB-INDEX) has to be an InstanceId.
                 * See RFC 3159 7.5
                 */
                if (objectPtr->listPtr && objectPtr->listPtr->ptr) {
                    Object *pibindex = (Object *)objectPtr->listPtr->ptr;
                    if (pibindex->typePtr && pibindex->typePtr->export.name &&
                        strcmp(pibindex->typePtr->export.name, "InstanceId"))
                        smiPrintErrorAtLine(thisParserPtr, ERR_PIB_INDEX_NOT_INSTANCEID,
                                            pibindex->line, pibindex->export.name);
                }
            }
            
            /*
             * Do all tables contain a PIB-ACCESS clause?
             * See RFC 3159 7.3
             */
            if ((objectPtr->export.nodekind == SMI_NODEKIND_TABLE) &&
                (objectPtr->export.access == SMI_ACCESS_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_TABLE_LACKS_PIB_ACCESS,
                                    objectPtr->line);

            /*
             * Does any non table types contain a PIB-ACCESS clause?
             * See RFC 3159 7.3
             */
            if (((objectPtr->export.nodekind == SMI_NODEKIND_NODE) ||
                 (objectPtr->export.nodekind == SMI_NODEKIND_ROW) ||
                 (objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)) &&
                (objectPtr->export.access != SMI_ACCESS_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_ACCESS_FOR_NON_TABLE,
                                    objectPtr->line);

            /*
             * Check the UNIQUENESS clause and its entries
             * See RFC 3159 7.9
             */
            if (objectPtr->uniquenessPtr) {
                if (objectPtr->export.nodekind != SMI_NODEKIND_ROW)
                    smiPrintErrorAtLine(parserPtr, ERR_UNIQUENESS_FOR_NON_ROW,
                                        objectPtr->line);
                else
                    smiCheckUniqueness(parserPtr, objectPtr);
            }
            
            /*
             * Does the PIB-REFERENCES object point to a PRC (table)?
             * See RFC 3159 7.10
             */
            if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                !strcmp(objectPtr->typePtr->export.name, "ReferenceId") &&
                objectPtr->relatedPtr &&
                (objectPtr->relatedPtr->export.nodekind != SMI_NODEKIND_ROW))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_REFERENCES_NOT_ROW,
                                    objectPtr->line);

            /*
             * Do all PIB-TAGs point to objects with a SYNTAX of TagId?
             * See RFC 3159 7.12
             */
            if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                !strcmp(objectPtr->typePtr->export.name, "TagReferenceId") &&
                objectPtr->relatedPtr && objectPtr->relatedPtr->typePtr &&
                objectPtr->relatedPtr->typePtr->export.name &&
                strcmp(objectPtr->relatedPtr->typePtr->export.name, "TagId"))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_TAG_TYPE, objectPtr->line);
            
            /*
             * Is the attribute member of at least one compliance group?
             * See RFC 3159 9.1
             */
            if (objectPtr->export.nodekind & SMI_NODEKIND_COLUMN) {
                Object *group;
                int found = 0;
                
                for (group = modulePtr->firstObjectPtr; group;
                     group = group->nextPtr) {
                    if ((group->export.nodekind == SMI_NODEKIND_GROUP) &&
                        group->listPtr) {
                        List *l;
                        
                        for (l = group->listPtr; l; l = l->nextPtr)
                            if (((Object *)l->ptr)->export.name &&
                                !strcmp(((Object *)l->ptr)->export.name,
                                        objectPtr->export.name)) {
                                found = 1;
                                break;
                            }
                    }
                    if (found)
                        break;
                }
                if (!found)
                    smiPrintErrorAtLine(parserPtr, ERR_ATTRIBUTE_NOT_IN_GROUP,
                                        objectPtr->line, objectPtr->export.name);
            }
        }
    }
}



static void
checkTypes(Parser *parserPtr, Module *modulePtr)
{
    Type *typePtr;
    
    for (typePtr = modulePtr->firstTypePtr;
	typePtr; typePtr = typePtr->nextPtr) {

	/*
	 * Check references to unknown types.
	 */
	
	if ((typePtr->flags & FLAG_INCOMPLETE)
	    && typePtr->export.name
	    && (typePtr->export.decl == SMI_DECL_UNKNOWN)) {
	    smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_TYPE,
				typePtr->line, typePtr->export.name);
	}

	/*
	 * Use TCs instead of type assignments in SMIv2.
	 */

	if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2
	    && typePtr->export.decl == SMI_DECL_TYPEASSIGNMENT
	    && typePtr->export.basetype != SMI_BASETYPE_UNKNOWN
	    && strcmp(thisModulePtr->export.name, "SNMPv2-SMI")) {
	    smiPrintErrorAtLine(parserPtr, ERR_SMIV2_TYPE_ASSIGNEMENT,
				typePtr->line, typePtr->export.name);
	}

	/*
	 * Check whether we have types that are not used in this
	 * module.
	 */

	if ((typePtr->export.decl == SMI_DECL_TYPEDEF
	     || typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION)
	    && ! (typePtr->flags & FLAG_INSYNTAX)) {
	    static char *status[] = { "Unknown", "current", "deprecated",
				      "mandatory", "optional", "obsolete" };
	    smiPrintErrorAtLine(parserPtr, ERR_TYPE_UNREF,
				typePtr->line,
				status[typePtr->export.status],
				typePtr->export.name);
	}

	/*
	 * Complain about TCs derived from other TCs (RFC 2579 3.5).
	 */
	
	if (typePtr->parentPtr
	    && typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION
	    && typePtr->export.decl == typePtr->parentPtr->export.decl) {
	    smiPrintErrorAtLine(parserPtr, ERR_SMIV2_NESTED_TEXTUAL_CONVENTION,
				typePtr->line,
				typePtr->export.name,
				typePtr->parentPtr->export.name);

	    if (typePtr->export.status < typePtr->parentPtr->export.status) {
		if (typePtr->parentPtr->export.status == SMI_STATUS_DEPRECATED) {
		    smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_DEPRECATED,
					typePtr->line,
					typePtr->parentPtr->export.name,
					typePtr->export.name);
		}
		if (typePtr->parentPtr->export.status == SMI_STATUS_OBSOLETE) {
		    smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_OBSOLETE,
					typePtr->line,
					typePtr->parentPtr->export.name,
					typePtr->export.name);
		}
	    }
	}

	smiCheckTypeFormat(parserPtr, typePtr);
	smiCheckNamedNumberRedefinition(parserPtr, typePtr);
	smiCheckNamedNumberSubtyping(parserPtr, typePtr);
    }
}


				
static void
adjustDefval(Parser *parserPtr, SmiValue *valuePtr, Type *typePtr, int line)
{
    Object *object2Ptr;
    List *bitsListPtr, *valueListPtr, *p, *pp, *nextPtr, *listPtr;
    Import *importPtr;
    int nBits, bit;
    
    if (valuePtr->basetype == SMI_BASETYPE_UNKNOWN)
	return;
	
    if (valuePtr->basetype == SMI_BASETYPE_OBJECTIDENTIFIER) {
	/* a len of -1 indicates an unresolved label in ptr */
	if (valuePtr->len == -1) {
	    object2Ptr = findObjectByModuleAndName(parserPtr->modulePtr,
						  (char *)valuePtr->value.ptr);
	    if (!object2Ptr) {
		importPtr = findImportByName(
		    (char *)valuePtr->value.ptr, parserPtr->modulePtr);
		if (importPtr) {		/* imported object */
		    importPtr->use++;
		    object2Ptr = findObjectByModulenameAndName(
			importPtr->export.module,
			importPtr->export.name);
		}
	    }
	    if (!object2Ptr) {
		smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_OIDLABEL,
				    line,
				    (char *)valuePtr->value.ptr);
		smiFree(valuePtr->value.ptr);
		valuePtr->value.ptr = NULL;
		valuePtr->basetype = SMI_BASETYPE_UNKNOWN;
	    } else {
		smiFree(valuePtr->value.ptr);
		valuePtr->len = object2Ptr->export.oidlen;
		valuePtr->value.ptr = smiMalloc(object2Ptr->export.oidlen *
						sizeof(SmiSubid));
		memcpy(valuePtr->value.ptr,
		       object2Ptr->export.oid,
		       object2Ptr->export.oidlen * sizeof(SmiSubid));
	    }
	}
    } else if (valuePtr->basetype == SMI_BASETYPE_BITS) {
	bitsListPtr = typePtr->listPtr;
	valueListPtr = (void *)valuePtr->value.ptr;
	for (nBits = 0, p = bitsListPtr; p; p = p->nextPtr) {
	    if (nBits < 1+((NamedNumber *)(p->ptr))->export.value.value.integer32) {
		nBits = 1+((NamedNumber *)(p->ptr))->export.value.value.integer32;
	    }
	}
	valuePtr->value.ptr = smiMalloc((nBits+7)/8);
	memset(valuePtr->value.ptr, 0, (nBits+7)/8);
	valuePtr->len = (nBits+7)/8;
	for (p = valueListPtr; p;) {
	    for (pp = bitsListPtr; pp; pp = pp->nextPtr) {
		if (!strcmp(p->ptr,
			    ((NamedNumber *)(pp->ptr))->export.name)) {
		    bit = ((NamedNumber *)(pp->ptr))->export.value.value.integer32;
		    valuePtr->value.ptr[bit/8] |=
			1 << (7-(bit%8));
		}
	    }
	    smiFree(p->ptr);
	    nextPtr = p->nextPtr;
	    smiFree(p);
	    p = nextPtr;
	}
    } else if (valuePtr->basetype == SMI_BASETYPE_ENUM) {

	/* Example: defval=false on an Unsigned32 type object: would crash */
	if (typePtr->export.basetype != valuePtr->basetype)
		return;

	/* a len of -1 indicates an unresolved enum label in ptr */
	if (valuePtr->len == -1) {
	    for (listPtr = typePtr->listPtr; listPtr;
		 listPtr = listPtr->nextPtr) {
		if (!strcmp(((NamedNumber *)(listPtr->ptr))->export.name,
			    (char *)valuePtr->value.ptr)) {
		    smiFree(valuePtr->value.ptr);
		    valuePtr->value.integer32 =
			((NamedNumber *)(listPtr->ptr))->
			export.value.value.integer32;
		    valuePtr->len = 1;
		    break;
		}
	    }
	}
    }
}



static void
checkDefvals(Parser *parserPtr, Module *modulePtr)
{
    Object *objectPtr;
    
    /*
     * Check unknown identifiers in OID DEFVALs.
     */

    for(objectPtr = modulePtr->firstObjectPtr;
	objectPtr; objectPtr = objectPtr->nextPtr) {

	adjustDefval(parserPtr, &objectPtr->export.value,
		     objectPtr->typePtr, objectPtr->line);
	
	if (objectPtr->export.value.len == -1) {
	    smiPrintErrorAtLine(parserPtr,
				ERR_DEFVAL_SYNTAX, objectPtr->line);
	}
	
	smiCheckDefault(parserPtr, objectPtr);
    }
}



static void
checkImportsUsage(Parser *parserPtr, Module *modulePtr)
{
    Import *importPtr;
    
    /*
     * Check usage of all imported identifiers.
     */

    if (strcmp(modulePtr->export.name, "SNMPv2-TC") &&
	strcmp(modulePtr->export.name, "SNMPv2-CONF") &&
	strcmp(modulePtr->export.name, "RFC-1212") &&
	strcmp(modulePtr->export.name, "RFC-1215")) {
	for(importPtr = modulePtr->firstImportPtr;
	    importPtr; importPtr = importPtr->nextPtr) {
	    if (! strcmp(importPtr->export.module, "SNMPv2-SMI")) {
		if (! strcmp(importPtr->export.name, "ExtUTCTime")
		    || !strcmp(importPtr->export.name, "ObjectName")
		    || !strcmp(importPtr->export.name, "NotificationName")) {
		    smiPrintErrorAtLine(parserPtr, ERR_ILLEGAL_IMPORT,
					importPtr->line,
					importPtr->export.name,
					importPtr->export.module);
		}
	    }
	    /* checkImports() handles KIND_NOTFOUND */
	    if (importPtr->use == 0 && importPtr->kind != KIND_NOTFOUND) {
		smiPrintErrorAtLine(parserPtr, ERR_UNUSED_IMPORT,
				    importPtr->line,
				    importPtr->export.name,
				    importPtr->export.module);
	    }

	    if (modulePtr->export.language == SMI_LANGUAGE_SMIV2) {
		int j;
		for (j = 0; convertImportv2[j]; j += 4) {
		    if ((strcmp(convertImportv2[j],
				importPtr->export.module) == 0)
			&& (strcmp(convertImportv2[j+1],
				   importPtr->export.name) == 0)) {
			smiPrintErrorAtLine(parserPtr,
					    ERR_OBSOLETE_IMPORT,
					    importPtr->line,
					    importPtr->export.name,
					    convertImportv2[j+2],
					    importPtr->export.module);
		    }
		}
	    }
	}
    }
}



static time_t
checkDate(Parser *parserPtr, char *date)
{
    struct tm	tm;
    time_t	anytime;
    int		i, len;
    char	*p;
    
    memset(&tm, 0, sizeof(tm));
    anytime = 0;
    
    len = strlen(date);
    if (len == 11 || len == 13) {
	for (i = 0; i < len; i++) {
	    if ( (i < len-1 && ! isdigit((int) date[i]))
		 || (i == len-1 && date[len-1] != 'Z')) {
		smiPrintError(parserPtr, ERR_DATE_CHARACTER, date);
		anytime = (time_t) -1;
		break;
	    }
	}
    } else {
	smiPrintError(parserPtr, ERR_DATE_LENGTH, date);
	anytime = (time_t) -1;
    }

    if (anytime == 0) {
	for (i = 0, p = date, tm.tm_year = 0;
	     i < ((len == 11) ? 2 : 4); i++, p++) {
	    tm.tm_year = tm.tm_year * 10 + (*p - '0');
	}
	if (len == 11) {
	    tm.tm_year += 1900;
	    if (tm.tm_year < 1990)
		smiPrintError(parserPtr, ERR_DATE_YEAR_2DIGITS,
			      date, tm.tm_year);
	}
	tm.tm_mon  = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_mday = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_hour = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_min  = (p[0]-'0') * 10 + (p[1]-'0');
	
	if (tm.tm_mon < 1 || tm.tm_mon > 12) {
	    smiPrintError(parserPtr, ERR_DATE_MONTH, date);
	}
	if (tm.tm_mday < 1 || tm.tm_mday > 31) {
	    smiPrintError(parserPtr, ERR_DATE_DAY, date);
	}
	if (tm.tm_hour < 0 || tm.tm_hour > 23) {
	    smiPrintError(parserPtr, ERR_DATE_HOUR, date);
	}
	if (tm.tm_min < 0 || tm.tm_min > 59) {
	    smiPrintError(parserPtr, ERR_DATE_MINUTES, date);
	}
	
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	tm.tm_isdst = 0;

	anytime = timegm(&tm);
	
	if (anytime == (time_t) -1) {
	    smiPrintError(parserPtr, ERR_DATE_VALUE, date);
	} else {
	    if (anytime < SMI_EPOCH) {
		smiPrintError(parserPtr, ERR_DATE_IN_PAST, date);
	    }
	    if (anytime > time(NULL)) {
		smiPrintError(parserPtr, ERR_DATE_IN_FUTURE, date);
	    }
	}
    }

    return (anytime == (time_t) -1) ? 0 : anytime;
}


#line 1344 "parser-smi.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser-smi.tab.h".  */
#ifndef YY_SMI_PARSER_SMI_TAB_H_INCLUDED
# define YY_SMI_PARSER_SMI_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int smidebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOT_DOT = 258,
    COLON_COLON_EQUAL = 259,
    UPPERCASE_IDENTIFIER = 260,
    LOWERCASE_IDENTIFIER = 261,
    NUMBER = 262,
    NEGATIVENUMBER = 263,
    NUMBER64 = 264,
    NEGATIVENUMBER64 = 265,
    BIN_STRING = 266,
    HEX_STRING = 267,
    QUOTED_STRING = 268,
    ACCESS = 269,
    AGENT_CAPABILITIES = 270,
    APPLICATION = 271,
    AUGMENTS = 272,
    BEGIN_ = 273,
    BITS = 274,
    CHOICE = 275,
    CONTACT_INFO = 276,
    CREATION_REQUIRES = 277,
    COUNTER32 = 278,
    COUNTER64 = 279,
    DEFINITIONS = 280,
    DEFVAL = 281,
    DESCRIPTION = 282,
    DISPLAY_HINT = 283,
    END = 284,
    ENTERPRISE = 285,
    EXPORTS = 286,
    EXTENDS = 287,
    FROM = 288,
    GROUP = 289,
    GAUGE32 = 290,
    IDENTIFIER = 291,
    IMPLICIT = 292,
    IMPLIED = 293,
    IMPORTS = 294,
    INCLUDES = 295,
    INDEX = 296,
    INSTALL_ERRORS = 297,
    INTEGER = 298,
    INTEGER32 = 299,
    INTEGER64 = 300,
    IPADDRESS = 301,
    LAST_UPDATED = 302,
    MACRO = 303,
    MANDATORY_GROUPS = 304,
    MAX_ACCESS = 305,
    MIN_ACCESS = 306,
    MODULE = 307,
    MODULE_COMPLIANCE = 308,
    MODULE_IDENTITY = 309,
    NOT_ACCESSIBLE = 310,
    NOTIFICATIONS = 311,
    NOTIFICATION_GROUP = 312,
    NOTIFICATION_TYPE = 313,
    OBJECT = 314,
    OBJECT_GROUP = 315,
    OBJECT_IDENTITY = 316,
    OBJECT_TYPE = 317,
    OBJECTS = 318,
    OCTET = 319,
    OF = 320,
    ORGANIZATION = 321,
    OPAQUE = 322,
    PIB_ACCESS = 323,
    PIB_DEFINITIONS = 324,
    PIB_INDEX = 325,
    PIB_MIN_ACCESS = 326,
    PIB_REFERENCES = 327,
    PIB_TAG = 328,
    POLICY_ACCESS = 329,
    PRODUCT_RELEASE = 330,
    REFERENCE = 331,
    REVISION = 332,
    SEQUENCE = 333,
    SIZE = 334,
    STATUS = 335,
    STRING = 336,
    SUBJECT_CATEGORIES = 337,
    SUPPORTS = 338,
    SYNTAX = 339,
    TEXTUAL_CONVENTION = 340,
    TIMETICKS = 341,
    TRAP_TYPE = 342,
    UNIQUENESS = 343,
    UNITS = 344,
    UNIVERSAL = 345,
    UNSIGNED32 = 346,
    UNSIGNED64 = 347,
    VALUE = 348,
    VARIABLES = 349,
    VARIATION = 350,
    WRITE_SYNTAX = 351
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 1307 "parser-smi.y" /* yacc.c:355  */

    char           *text;	  		/* scanned quoted text       */
    char           *id;				/* identifier name           */
    int            err;				/* actually just a dummy     */
    time_t	   date;			/* a date value              */
    Object         *objectPtr;			/* object identifier         */
    SmiStatus      status;			/* a STATUS value            */
    SmiAccess      access;			/* an ACCESS value           */
    Type           *typePtr;
    List           *listPtr;			/* SEQUENCE and INDEX lists  */
    NamedNumber    *namedNumberPtr;		/* BITS or enum item         */
    Range          *rangePtr;			/* type restricting range    */
    SmiValue	   *valuePtr;
    SmiUnsigned32  unsigned32;			/*                           */
    SmiInteger32   integer32;			/*                           */
    SmiUnsigned64  unsigned64;			/*                           */
    SmiInteger64   integer64;			/*                           */
    struct Compl   compl;
    struct Index   index;
    Module	   *modulePtr;
    SubjectCategories *subjectCategoriesPtr;

#line 1504 "parser-smi.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int smiparse (struct Parser *parserPtr);

#endif /* !YY_SMI_PARSER_SMI_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 1520 "parser-smi.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  222
/* YYNRULES -- Number of rules.  */
#define YYNRULES  425
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  710

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,   102,     2,     2,   100,     2,   105,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    99,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,   106,    98,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1605,  1605,  1610,  1615,  1617,  1626,  1625,  1687,  1690,
    1693,  1695,  1704,  1707,  1710,  1725,  1727,  1726,  1747,  1750,
    1754,  1756,  1760,  1805,  1807,  1815,  1821,  1827,  1843,  1853,
    1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,
    1869,  1870,  1871,  1874,  1875,  1876,  1877,  1878,  1879,  1880,
    1883,  1884,  1887,  1899,  1902,  1906,  1908,  1912,  1917,  1922,
    1927,  1932,  1937,  1942,  1947,  1952,  1957,  1962,  1967,  1972,
    1987,  1999,  1986,  2032,  2033,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2041,  2045,  2044,  2074,  2079,  2095,  2094,  2135,
    2134,  2300,  2304,  2328,  2342,  2343,  2352,  2353,  2354,  2355,
    2356,  2359,  2360,  2361,  2364,  2365,  2368,  2385,  2416,  2384,
    2452,  2460,  2474,  2519,  2527,  2533,  2553,  2636,  2642,  2664,
    2668,  2673,  2706,  2712,  2726,  2725,  2761,  2771,  2796,  2760,
    2824,  2834,  2823,  3131,  3140,  3148,  3158,  3147,  3230,  3235,
    3240,  3250,  3272,  3278,  3284,  3287,  3291,  3300,  3303,  3307,
    3311,  3316,  3315,  3323,  3327,  3326,  3334,  3339,  3338,  3346,
    3349,  3352,  3355,  3361,  3375,  3380,  3379,  3387,  3390,  3396,
    3410,  3432,  3431,  3443,  3442,  3456,  3466,  3486,  3455,  3517,
    3527,  3552,  3556,  3560,  3567,  3574,  3578,  3516,  3624,  3631,
    3638,  3645,  3651,  3666,  3687,  3710,  3714,  3734,  3739,  3744,
    3749,  3766,  3768,  3776,  3781,  3798,  3807,  3821,  3820,  3840,
    3839,  3854,  3881,  3880,  3912,  3911,  3965,  4012,  4067,  4117,
    4123,  4122,  4134,  4180,  4221,  4228,  4235,  4241,  4248,  4255,
    4281,  4304,  4324,  4341,  4374,  4378,  4403,  4407,  4413,  4441,
    4467,  4504,  4530,  4563,  4588,  4587,  4618,  4646,  4684,  4730,
    4756,  4793,  4819,  4856,  4882,  4925,  4953,  4979,  5005,  5029,
    5057,  5097,  5123,  5148,  5175,  5192,  5209,  5228,  5235,  5245,
    5257,  5263,  5277,  5284,  5294,  5300,  5306,  5312,  5318,  5341,
    5368,  5374,  5380,  5394,  5393,  5415,  5430,  5439,  5498,  5514,
    5524,  5529,  5539,  5544,  5611,  5610,  5628,  5639,  5638,  5652,
    5658,  5657,  5691,  5696,  5702,  5716,  5721,  5727,  5737,  5743,
    5763,  5767,  5769,  5777,  5780,  5783,  5789,  5802,  5808,  5814,
    5824,  5827,  5830,  5833,  5835,  5840,  5839,  5870,  5875,  5880,
    5886,  5892,  5905,  5917,  5923,  5929,  5942,  5953,  5964,  5970,
    5970,  5985,  5989,  5998,  6092,  6196,  6220,  6280,  6349,  6353,
    6355,  6359,  6361,  6366,  6376,  6395,  6365,  6426,  6436,  6458,
    6425,  6490,  6500,  6518,  6489,  6582,  6588,  6592,  6628,  6627,
    6656,  6665,  6675,  6680,  6685,  6690,  6696,  6709,  6732,  6739,
    6746,  6750,  6817,  6823,  6832,  6831,  6865,  6864,  6912,  6926,
    6931,  6949,  6954,  6960,  6966,  6975,  6981,  6991,  7013,  6980,
    7048,  7051,  7054,  7056,  7061,  7060,  7087,  7097,  7114,  7120,
    7129,  7139,  7142,  7145,  7147,  7152,  7164,  7151,  7184,  7187,
    7190,  7255,  7265,  7268,  7270,  7274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT_DOT", "COLON_COLON_EQUAL",
  "UPPERCASE_IDENTIFIER", "LOWERCASE_IDENTIFIER", "NUMBER",
  "NEGATIVENUMBER", "NUMBER64", "NEGATIVENUMBER64", "BIN_STRING",
  "HEX_STRING", "QUOTED_STRING", "ACCESS", "AGENT_CAPABILITIES",
  "APPLICATION", "AUGMENTS", "BEGIN_", "BITS", "CHOICE", "CONTACT_INFO",
  "CREATION_REQUIRES", "COUNTER32", "COUNTER64", "DEFINITIONS", "DEFVAL",
  "DESCRIPTION", "DISPLAY_HINT", "END", "ENTERPRISE", "EXPORTS", "EXTENDS",
  "FROM", "GROUP", "GAUGE32", "IDENTIFIER", "IMPLICIT", "IMPLIED",
  "IMPORTS", "INCLUDES", "INDEX", "INSTALL_ERRORS", "INTEGER", "INTEGER32",
  "INTEGER64", "IPADDRESS", "LAST_UPDATED", "MACRO", "MANDATORY_GROUPS",
  "MAX_ACCESS", "MIN_ACCESS", "MODULE", "MODULE_COMPLIANCE",
  "MODULE_IDENTITY", "NOT_ACCESSIBLE", "NOTIFICATIONS",
  "NOTIFICATION_GROUP", "NOTIFICATION_TYPE", "OBJECT", "OBJECT_GROUP",
  "OBJECT_IDENTITY", "OBJECT_TYPE", "OBJECTS", "OCTET", "OF",
  "ORGANIZATION", "OPAQUE", "PIB_ACCESS", "PIB_DEFINITIONS", "PIB_INDEX",
  "PIB_MIN_ACCESS", "PIB_REFERENCES", "PIB_TAG", "POLICY_ACCESS",
  "PRODUCT_RELEASE", "REFERENCE", "REVISION", "SEQUENCE", "SIZE", "STATUS",
  "STRING", "SUBJECT_CATEGORIES", "SUPPORTS", "SYNTAX",
  "TEXTUAL_CONVENTION", "TIMETICKS", "TRAP_TYPE", "UNIQUENESS", "UNITS",
  "UNIVERSAL", "UNSIGNED32", "UNSIGNED64", "VALUE", "VARIABLES",
  "VARIATION", "WRITE_SYNTAX", "'{'", "'}'", "';'", "','", "'('", "')'",
  "'['", "']'", "'.'", "'|'", "$accept", "mibFile", "modules", "module",
  "$@1", "moduleOid", "definitions", "linkagePart", "linkageClause",
  "exportsClause", "$@2", "importPart", "imports", "import",
  "importIdentifiers", "importIdentifier", "importedKeyword",
  "importedSMIKeyword", "importedSPPIKeyword", "moduleName",
  "declarationPart", "declarations", "declaration", "macroClause", "$@3",
  "$@4", "macroName", "choiceClause", "$@5", "fuzzy_lowercase_identifier",
  "valueDeclaration", "$@6", "typeDeclaration", "$@7", "typeName",
  "typeSMI", "typeSMIandSPPI", "typeSMIonly", "typeSPPIonly",
  "typeDeclarationRHS", "$@8", "$@9", "conceptualTable", "row",
  "entryType", "sequenceItems", "sequenceItem", "Syntax", "sequenceSyntax",
  "NamedBits", "NamedBit", "$@10", "objectIdentityClause", "$@11", "$@12",
  "$@13", "objectTypeClause", "$@14", "$@15", "descriptionClause",
  "trapTypeClause", "$@16", "$@17", "VarPart", "VarTypes", "VarType",
  "DescrPart", "MaxOrPIBAccessPart", "PibAccessPart", "PibAccess",
  "SPPIPibReferencesPart", "$@18", "SPPIPibTagPart", "$@19",
  "SPPIUniquePart", "$@20", "UniqueTypesPart", "UniqueTypes", "UniqueType",
  "SPPIErrorsPart", "$@21", "Errors", "Error", "MaxAccessPart", "$@22",
  "$@23", "notificationTypeClause", "$@24", "$@25", "$@26",
  "moduleIdentityClause", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "SubjectCategoriesPart", "SubjectCategories",
  "CategoryIDs", "CategoryID", "ObjectSyntax", "typeTag",
  "sequenceObjectSyntax", "valueofObjectSyntax", "SimpleSyntax", "$@35",
  "$@36", "$@37", "$@38", "$@39", "valueofSimpleSyntax",
  "sequenceSimpleSyntax", "ApplicationSyntax", "$@40",
  "sequenceApplicationSyntax", "anySubType", "integerSubType",
  "octetStringSubType", "ranges", "range", "value", "enumSpec",
  "enumItems", "enumItem", "$@41", "enumNumber", "Status",
  "Status_Capabilities", "DisplayPart", "UnitsPart", "Access", "IndexPart",
  "$@42", "$@43", "MibIndex", "$@44", "IndexTypes", "IndexType", "Index",
  "Entry", "DefValPart", "Value", "BitsValue", "BitNames", "ObjectName",
  "NotificationName", "ReferPart", "RevisionPart", "Revisions", "Revision",
  "$@45", "NotificationObjectsPart", "ObjectGroupObjectsPart", "Objects",
  "Object", "NotificationsPart", "Notifications", "Notification", "Text",
  "ExtUTCTime", "objectIdentifier", "$@46", "subidentifiers",
  "subidentifier", "objectIdentifier_defval", "subidentifiers_defval",
  "subidentifier_defval", "objectGroupClause", "$@47", "$@48", "$@49",
  "notificationGroupClause", "$@50", "$@51", "$@52",
  "moduleComplianceClause", "$@53", "$@54", "$@55", "ComplianceModulePart",
  "ComplianceModules", "ComplianceModule", "$@56", "ComplianceModuleName",
  "MandatoryPart", "MandatoryGroups", "MandatoryGroup", "CompliancePart",
  "Compliances", "Compliance", "ComplianceGroup", "$@57",
  "ComplianceObject", "$@58", "SyntaxPart", "WriteSyntaxPart",
  "WriteSyntax", "AccessPart", "agentCapabilitiesClause", "$@59", "$@60",
  "$@61", "ModulePart_Capabilities", "Modules_Capabilities",
  "Module_Capabilities", "$@62", "CapabilitiesGroups", "CapabilitiesGroup",
  "ModuleName_Capabilities", "VariationPart", "Variations", "Variation",
  "$@63", "$@64", "VariationAccessPart", "VariationAccess", "CreationPart",
  "Cells", "Cell", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   123,   125,    59,
      44,    40,    41,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF -509

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-509)))

#define YYTABLE_NINF -411

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,  -509,    50,    23,  -509,  -509,  -509,  -509,   -57,  -509,
       9,   -39,    32,  -509,  -509,    70,  -509,    27,   -15,  -509,
      57,  -509,    32,  -509,    95,   130,   134,  -509,   139,    65,
      89,  -509,   153,  -509,   187,   102,   535,   351,  -509,   100,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,   108,   535,  -509,    -3,  -509,
    -509,  -509,  -509,   110,   206,    64,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,   183,   461,  -509,  -509,
    -509,   126,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,    23,   535,  -509,   154,   155,   158,   166,   161,   168,
     173,   214,  -509,  -509,   180,   171,   144,   229,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,   198,
    -509,   160,   159,   156,   184,   172,   192,   194,   163,   178,
     231,   257,   232,    15,   167,  -509,   -45,   -45,   169,   -28,
     170,   169,   -45,   233,   186,   174,   -32,  -509,   -45,   175,
     169,    -2,   176,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
      55,  -509,  -509,   262,   213,   177,   199,   181,  -509,   185,
     203,   188,   204,   262,   260,  -509,   189,  -509,    36,   191,
    -509,  -509,   281,   195,   283,  -509,  -509,  -509,  -509,  -509,
    -509,   140,  -509,   169,   191,   169,  -509,  -509,  -509,   -45,
     196,   211,  -509,   287,   288,   267,  -509,   169,  -509,   289,
     291,   296,   -17,  -509,  -509,   275,   218,  -509,   262,   297,
     261,  -509,   262,  -509,   262,   284,  -509,   230,  -509,   219,
    -509,  -509,  -509,  -509,  -509,  -509,   217,   -19,  -509,   309,
    -509,  -509,   -36,  -509,  -509,  -509,    35,  -509,  -509,  -509,
    -509,  -509,   174,  -509,  -509,   301,    38,  -509,   260,   234,
    -509,   215,   222,   -45,   260,   260,     8,  -509,    56,  -509,
    -509,   294,   221,   225,   227,  -509,   302,    59,   303,  -509,
      60,  -509,  -509,   304,   260,   322,   235,   237,   305,   140,
    -509,   140,   140,   228,  -509,   281,   236,  -509,   283,  -509,
     -45,  -509,   -45,   -45,   -45,   -45,   -45,  -509,   -45,   299,
     258,  -509,   -45,   -45,  -509,  -509,  -509,  -509,  -509,  -509,
     288,  -509,   262,   306,   311,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,   266,  -509,   334,  -509,  -509,  -509,
     260,   335,  -509,   297,  -509,  -509,  -509,   260,  -509,  -509,
     260,  -509,  -509,   314,  -509,  -509,   260,   273,    -6,  -509,
    -509,   344,  -509,   136,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,   -45,   -45,  -509,  -509,  -509,   326,  -509,  -509,
     273,   334,   334,  -509,   282,  -509,  -509,  -509,  -509,   252,
    -509,   292,  -509,  -509,  -509,   273,   260,    63,  -509,  -509,
    -509,   260,   355,   259,   269,  -509,  -509,   274,  -509,  -509,
     260,   358,  -509,  -509,   272,  -509,   298,   273,  -509,   260,
     273,   273,   312,  -509,  -509,  -509,  -509,   356,  -509,  -509,
    -509,  -509,   280,  -509,   285,   262,   375,  -509,   377,   380,
     384,   381,   312,  -509,   273,  -509,  -509,   273,  -509,   293,
    -509,  -509,   371,   313,   378,   318,   319,   122,  -509,   323,
    -509,   317,   337,   308,  -509,   321,   260,   359,  -509,   260,
    -509,  -509,  -509,   353,  -509,   398,   419,   317,  -509,   213,
    -509,  -509,  -509,  -509,   273,   327,  -509,   328,   329,   331,
       2,   332,   389,  -509,   336,  -509,  -509,   338,    40,  -509,
     397,  -509,  -509,  -509,  -509,  -509,  -509,     2,  -509,  -509,
    -509,  -509,  -509,   391,  -509,   426,   342,  -509,  -509,   393,
     260,  -509,    68,  -509,  -509,  -509,  -509,   343,   346,   340,
      78,  -509,  -509,   348,   349,  -509,   360,  -509,  -509,  -509,
     420,   365,  -509,  -509,   443,  -509,   426,   354,  -509,  -509,
     357,  -509,   425,   379,  -509,   260,   213,   361,  -509,    87,
    -509,   362,  -509,  -509,   363,   367,   417,   366,   373,   454,
     302,  -509,   379,  -509,  -509,  -509,   213,   -20,   364,  -509,
    -509,  -509,  -509,  -509,    88,  -509,  -509,  -509,   370,    96,
     374,  -509,   468,  -509,  -509,  -509,   334,   334,   446,  -509,
    -509,   364,  -509,  -509,  -509,  -509,   417,   376,   382,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,   190,
    -509,  -509,   383,  -509,   448,   386,  -509,  -509,   260,  -509,
    -509,  -509,  -509,  -509,   385,  -509,   390,   387,   395,   193,
    -509,  -509,   396,   260,  -509,  -509,   365,  -509,   470,  -509,
     473,  -509,   385,  -509,  -509,  -509,   399,   361,   400,  -509,
    -509,   466,  -509,   492,   477,  -509,  -509,   403,   425,  -509,
    -509,  -509,    91,  -509,   474,  -509,  -509,   260,  -509,  -509
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,    52,     0,     2,     4,     6,     1,     5,     9,   339,
       0,     0,     0,    10,    11,     0,     8,    86,    85,   345,
       0,   343,   340,   341,     0,     0,     0,   342,    15,     0,
     344,    16,    13,   346,     0,     0,    19,     0,    12,     0,
      17,    26,    25,    43,    30,    44,    45,    46,    31,    50,
      32,    33,    34,    35,    47,    48,    36,    37,    38,    39,
      40,    41,    49,    42,    51,     0,    18,    20,     0,    23,
      27,    28,    29,     0,    86,    85,    82,   101,   103,   102,
      99,   104,    96,    81,    73,    80,    76,    79,    77,    74,
      98,    78,    97,    75,   100,   105,     0,     0,    55,    68,
      70,    87,    58,    57,    89,    92,    94,    95,    93,    59,
      60,    61,    62,    63,    65,    66,    64,    67,   347,    14,
      21,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    56,     0,     0,     0,     0,    22,    24,
     127,   131,   176,   180,   354,   358,   362,   397,    71,     0,
     136,     0,     0,     0,   328,   189,     0,     0,     0,     0,
       0,     0,     0,   112,     0,    83,   267,   267,   241,   206,
     211,   251,   267,     0,     0,   247,     0,   107,   267,   243,
     253,     0,     0,   110,    90,   197,   198,   199,   106,   117,
       0,   195,   200,     0,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,    72,     0,   339,     0,     0,
     217,   222,     0,     0,     0,   239,   240,   265,   266,   249,
     250,     0,   242,     0,     0,     0,   252,   238,   264,   267,
     219,     0,   248,     0,     0,   290,   246,     0,   254,     0,
       0,     0,    52,   196,   287,     0,   292,   339,     0,     0,
       0,   339,     0,   339,     0,     0,   337,     0,   339,   139,
     275,   274,   277,   276,   279,   278,     0,     0,   270,   272,
     215,   124,     0,   122,    84,   283,     0,   281,   208,   210,
     213,   224,     0,   112,   111,     0,     0,   114,     0,     0,
     245,     0,     0,     0,     0,     0,   147,   332,     0,   330,
     317,     0,   193,     0,   190,   191,     0,     0,     0,   336,
       0,   334,   318,     0,     0,     0,     0,     0,   144,     0,
     268,     0,     0,     0,   118,     0,     0,   280,     0,   221,
     267,   120,   267,   267,   267,   267,   267,   262,   267,     0,
       0,   260,   267,   267,   263,   116,   119,   203,   204,   113,
       0,   289,     0,     0,     0,   218,   223,   216,   128,   291,
     173,   171,   150,   149,   153,   146,     0,   145,   327,   339,
       0,     0,   188,     0,   338,   182,   329,     0,   333,   339,
       0,   363,   288,     0,    88,   339,     0,   320,     0,   271,
     273,     0,   123,     0,   282,   121,   256,   261,   257,   234,
     235,   255,   267,   267,   259,   258,   115,     0,   201,   202,
     320,     0,     0,   151,   156,   293,   148,   331,   177,     0,
     192,     0,   355,   335,   359,   320,     0,     0,   140,   142,
     143,     0,     0,     0,     0,   285,   286,     0,   237,   236,
       0,     0,   174,   172,     0,   154,     0,   320,   194,     0,
     320,   320,     0,   398,   138,   339,   319,     0,   269,   125,
     284,   108,     0,   339,     0,     0,     0,   183,     0,     0,
     372,     0,   365,   366,   320,   141,   137,   320,   339,     0,
     308,   339,   133,     0,     0,     0,     0,   371,   368,     0,
     367,   401,     0,     0,   152,     0,     0,   167,   339,     0,
     339,   339,   370,   374,   339,     0,     0,   400,   402,     0,
     129,   155,   134,   165,   320,     0,   184,     0,     0,     0,
     379,     0,   339,   404,     0,   403,   109,     0,   299,   178,
       0,   356,   360,   339,   384,   386,   369,   378,   380,   382,
     383,   364,   409,     0,   339,     0,     0,   297,   294,   302,
       0,   377,     0,   375,   339,   339,   381,     0,     0,     0,
       0,   168,   339,     0,     0,   300,   159,   185,   373,   339,
       0,   389,   339,   399,     0,   166,     0,     0,   339,   339,
       0,   157,   310,   322,   376,     0,     0,   391,   408,     0,
     406,     0,   169,   296,     0,     0,   339,     0,     0,     0,
       0,   186,   321,   323,   385,   388,     0,   395,   412,   339,
     170,   298,   295,   339,     0,   303,   306,   307,   339,     0,
       0,   325,     0,   324,   392,   390,     0,     0,     0,   339,
     405,   411,   413,   407,   305,   301,   339,     0,   160,   162,
     164,   231,   225,   226,   227,   228,   229,   230,   232,   314,
     311,   205,     0,   339,     0,     0,   393,   394,     0,   415,
     414,   304,   158,   339,   315,   352,     0,   313,     0,   348,
     349,   309,     0,     0,   339,   387,   389,   163,     0,   312,
       0,   233,     0,   350,   132,   326,     0,   391,     0,   316,
     187,   419,   351,     0,   422,   420,   418,     0,   310,   339,
     416,   425,     0,   423,     0,   421,   339,     0,   424,   417
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -509,  -509,  -509,   500,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,   438,  -509,   388,  -509,  -509,  -509,    13,
    -509,  -509,   411,  -509,  -509,  -509,  -509,  -509,  -509,   -16,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,   276,  -509,  -509,   162,  -192,  -509,  -509,
     200,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,    61,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -152,  -509,
    -509,  -509,   -59,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,   147,  -509,  -509,  -509,  -509,   339,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -161,  -148,
    -151,   207,   209,   205,  -182,  -509,   208,  -509,  -509,  -199,
    -509,  -509,  -509,  -404,  -509,  -509,  -509,  -509,  -509,  -509,
    -105,   -81,  -508,  -165,  -509,  -509,  -509,  -246,    39,  -384,
    -509,  -509,   -68,  -509,  -509,  -509,   300,   197,  -509,  -509,
     164,  -285,   -62,    -9,  -509,  -509,   517,  -509,  -509,  -127,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,    72,  -509,  -509,  -509,  -509,   -14,
    -509,  -509,    12,  -509,  -509,  -509,  -509,  -120,  -130,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,    54,  -509,  -509,
     -47,  -509,  -509,  -509,   -67,  -509,  -509,  -509,  -509,  -509,
    -509,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    10,    15,    37,    38,    32,
      35,    65,    66,    67,    68,    69,    70,    71,    72,   182,
      96,    97,    98,    99,   134,   160,   100,   183,   213,    21,
     102,   135,   103,   137,   104,   105,   106,   107,   108,   184,
     235,   477,   185,   186,   187,   286,   287,   188,   345,   272,
     273,   323,   109,   124,   152,   410,   110,   125,   153,   497,
     111,   136,   162,   318,   427,   428,   387,   364,   365,   366,
     414,   444,   446,   464,   582,   597,   637,   638,   639,   514,
     527,   560,   561,   367,   412,   411,   112,   126,   154,   447,
     113,   127,   155,   250,   421,   484,   530,   583,   622,   198,
     303,   304,   305,   189,   190,   346,   650,   191,   223,   224,
     225,   209,   282,   651,   347,   192,   237,   348,   215,   228,
     217,   267,   268,   269,   218,   276,   277,   326,   437,   245,
     383,   289,   296,   416,   549,   564,   563,   566,   580,   614,
     615,   616,   479,   599,   652,   666,   667,   480,   309,   432,
     601,   602,   603,   654,   196,   200,   298,   299,   202,   310,
     311,   257,   375,   300,    12,    22,    23,   668,   669,   670,
     114,   128,   156,   450,   115,   129,   157,   451,   116,   130,
     158,   425,   471,   472,   473,   503,   488,   520,   552,   553,
     536,   537,   538,   539,   554,   540,   555,   587,   607,   625,
     628,   117,   131,   159,   474,   506,   507,   508,   543,   589,
     590,   523,   630,   631,   632,   676,   704,   694,   696,   698,
     702,   703
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   297,   246,   351,   255,   297,   219,   442,   443,   358,
     359,   227,   211,     5,   239,   210,     5,   236,   216,   220,
     222,   101,   360,   226,   232,    20,   441,   270,     1,   381,
     121,   626,   238,   233,    13,    20,   534,    17,    18,    19,
       9,   452,   279,   260,   261,   262,   263,   264,   265,   301,
       6,   627,   214,   308,   577,   313,   208,   546,   361,    16,
     242,   535,   324,   466,   325,   234,   468,   469,   281,  -209,
     594,   595,   547,  -207,    24,   278,   362,   280,    14,  -396,
    -214,   101,   363,   320,   208,   418,    25,   321,   240,   290,
     491,   211,   422,   492,   210,   424,   433,   122,   169,   170,
     321,   430,   641,   642,   643,   644,   645,   646,   647,   648,
     548,   357,  -214,    28,   173,   266,   208,  -361,  -179,   174,
     -52,  -357,  -175,   297,  -353,  -126,  -130,  -339,  -339,  -339,
     528,   329,   -52,   327,   138,   328,   349,    29,   350,   429,
      30,   453,   356,   435,   436,   355,   456,   260,   261,   262,
     263,   264,   265,   407,   368,   461,   369,   376,   378,   369,
     379,   454,    26,   455,   467,   163,   568,    33,   569,   395,
      31,   396,   397,   398,   399,   400,   575,   401,   576,   164,
     165,   404,   405,   166,   167,   608,   635,   609,   636,   705,
      34,   706,    36,   649,    39,   168,   664,   665,   259,   682,
     665,    40,   118,   169,   170,   171,   172,   119,   123,   429,
     -91,   512,   132,  -135,   516,   140,   142,   141,   163,   173,
     143,   144,   656,   657,   174,   145,   146,   175,   148,   147,
     149,   150,   164,   151,   161,   495,   166,   167,   176,   193,
     194,   438,   439,   203,   312,   177,   178,   195,   168,   316,
     201,   179,   180,   204,   197,   199,   169,   170,   171,   172,
     205,   206,   207,   181,   212,   567,   482,   230,   244,   229,
     221,  -212,   173,   256,   247,   231,  -244,   174,   249,   248,
     175,   241,   251,   252,   254,   253,   258,   271,   214,   275,
     266,   176,   283,   274,   285,   288,   291,  -220,   292,   178,
     604,   293,   294,   302,   179,   180,   330,   295,   306,   571,
     315,   314,   322,   317,   352,   374,   181,   526,   319,   353,
     331,   370,   371,   372,   332,   333,   354,   373,   382,   391,
     377,   380,   386,   384,   385,   402,   334,   393,   413,   403,
     415,   426,   419,   408,   335,   336,   337,   338,   409,   431,
     617,   434,    73,   440,   448,   445,    74,    75,   449,   457,
     339,   458,   462,   476,   470,   340,    76,   617,   341,   463,
     312,   459,   640,   675,    77,    78,   460,   478,   465,   483,
     -54,   485,   481,   659,   486,   489,    79,   342,   685,   487,
     617,   494,   343,   344,   605,    80,    81,    82,   496,   499,
     505,   513,   519,   522,    83,    84,   510,   672,    85,    86,
     498,    87,    88,    89,   624,   500,   501,   640,    90,   511,
     504,   509,   709,   524,   550,   529,   531,   532,   533,  -410,
     541,   557,   559,   544,   565,   545,    91,    92,    93,   562,
     572,   574,    94,    95,   573,   578,   579,   585,   581,   586,
     591,   598,   593,   701,   596,   613,   600,   606,   620,   629,
     701,   611,    73,   618,   610,   612,    74,    75,  -161,   493,
     619,   653,   655,   658,   662,   673,    76,   688,   502,   689,
     693,   671,   663,   674,    77,    78,   678,   680,   679,   312,
     -53,   517,   518,   681,   684,   521,    79,   690,   695,   697,
     699,   707,   692,     7,   120,    80,    81,    82,   133,   284,
     139,   677,   406,   542,    83,    84,   475,   592,    85,    86,
     420,    87,    88,    89,   551,   392,   388,   390,    90,   243,
     389,   661,   634,   700,   623,   558,   394,   515,   621,    27,
      41,    42,   683,   423,   490,   570,    91,    92,    93,   556,
      43,   307,    94,    95,    44,   584,   687,   691,    45,    46,
     551,   525,   633,   588,   660,   708,   417,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,     0,     0,    51,     0,     0,     0,    52,    53,
       0,     0,    54,    55,     0,    56,    57,    58,     0,     0,
     588,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   686
};

static const yytype_int16 yycheck[] =
{
       9,   247,   194,   288,   203,   251,   167,   411,   412,   294,
     295,   172,   163,     0,    16,   163,     3,   178,   166,   167,
     168,    37,    14,   171,   175,    12,   410,   209,     5,   314,
      33,    51,   180,    65,    25,    22,    34,     5,     6,     7,
      97,   425,   224,     7,     8,     9,    10,    11,    12,   248,
       0,    71,    97,   252,   562,   254,   101,    17,    50,    98,
       5,    59,    98,   447,   100,    97,   450,   451,   229,    97,
     578,   579,    32,   101,     4,   223,    68,   225,    69,    15,
      97,    97,    74,   102,   101,   370,   101,   106,    90,   237,
     474,   242,   377,   477,   242,   380,   102,   100,    43,    44,
     106,   386,     6,     7,     8,     9,    10,    11,    12,    13,
      70,   293,    97,    18,    59,    79,   101,    53,    54,    64,
     105,    57,    58,   369,    60,    61,    62,     5,     6,     7,
     514,   282,   105,    98,   121,   100,    98,     7,   100,   385,
       6,   426,   293,     7,     8,   293,   431,     7,     8,     9,
      10,    11,    12,   352,    98,   440,   100,    98,    98,   100,
     100,    98,   105,   100,   449,     5,    98,   102,   100,   330,
      31,   332,   333,   334,   335,   336,    98,   338,   100,    19,
      20,   342,   343,    23,    24,    98,    98,   100,   100,    98,
     101,   100,    39,    97,     7,    35,     6,     7,   207,     6,
       7,    99,   102,    43,    44,    45,    46,    99,    98,   455,
       4,   496,    29,    87,   499,    61,    58,    62,     5,    59,
      54,    60,   626,   627,    64,    57,    53,    67,    48,    15,
      59,    87,    19,     4,    36,   481,    23,    24,    78,    80,
      84,   402,   403,    80,   253,    85,    86,    63,    35,   258,
      56,    91,    92,    75,    82,    63,    43,    44,    45,    46,
      29,     4,    30,   103,    97,   550,   465,    81,     6,    36,
     101,   101,    59,    13,    97,   101,   101,    64,    97,    80,
      67,   105,    97,    80,    80,    97,    97,     6,    97,     6,
      79,    78,     5,    98,     6,    28,     7,   101,     7,    86,
     585,     5,    27,     6,    91,    92,     5,    89,    47,   555,
      80,    27,     3,    94,    80,    13,   103,   509,   101,   104,
      19,    27,   101,    98,    23,    24,   104,   100,     6,   101,
      27,    27,    27,    98,    97,    36,    35,   101,    72,    81,
       6,    27,     7,    37,    43,    44,    45,    46,    37,    76,
     596,     7,     1,    27,   102,    73,     5,     6,    66,     4,
      59,   102,     4,     7,    52,    64,    15,   613,    67,    97,
     379,   102,   618,   658,    23,    24,   102,    97,    80,     4,
      29,     4,    97,   629,     4,     4,    35,    86,   673,     5,
     636,    98,    91,    92,   586,    44,    45,    46,    27,    21,
      83,    42,    49,     5,    53,    54,    98,   653,    57,    58,
      97,    60,    61,    62,   606,    97,    97,   663,    67,    98,
      97,    84,   707,     4,    27,    98,    98,    98,    97,    40,
      98,    40,     6,    97,    41,    97,    85,    86,    87,    97,
      97,   101,    91,    92,    98,    97,    97,    27,    88,    84,
       7,    26,    98,   699,    97,    38,    77,    96,     4,    95,
     706,    98,     1,    97,   102,    98,     5,     6,    98,   478,
      97,    97,     4,    27,    98,    27,    15,     7,   487,     6,
      14,    98,   100,    97,    23,    24,   101,   100,    98,   498,
      29,   500,   501,    98,    98,   504,    35,    98,     6,    22,
      97,    27,   102,     3,    66,    44,    45,    46,    97,   233,
     122,   663,   350,   522,    53,    54,   455,   576,    57,    58,
     373,    60,    61,    62,   533,   325,   319,   322,    67,   190,
     321,   636,   613,   698,   602,   544,   328,   498,   600,    22,
       5,     6,   669,   379,   472,   554,    85,    86,    87,   537,
      15,   251,    91,    92,    19,   569,   676,   687,    23,    24,
     569,   507,   609,   572,   631,   706,   369,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    57,    58,    -1,    60,    61,    62,    -1,    -1,
     609,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   674
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,   108,   109,   110,   126,     0,   110,   111,    97,
     112,   270,   271,    25,    69,   113,    98,     5,     6,     7,
     126,   136,   272,   273,     4,   101,   105,   273,    18,     7,
       6,    31,   116,   102,   101,   117,    39,   114,   115,     7,
      99,     5,     6,    15,    19,    23,    24,    35,    44,    45,
      46,    49,    53,    54,    57,    58,    60,    61,    62,    67,
      85,    86,    87,    91,    92,   118,   119,   120,   121,   122,
     123,   124,   125,     1,     5,     6,    15,    23,    24,    35,
      44,    45,    46,    53,    54,    57,    58,    60,    61,    62,
      67,    85,    86,    87,    91,    92,   127,   128,   129,   130,
     133,   136,   137,   139,   141,   142,   143,   144,   145,   159,
     163,   167,   193,   197,   277,   281,   285,   308,   102,    99,
     120,    33,   100,    98,   160,   164,   194,   198,   278,   282,
     286,   309,    29,   129,   131,   138,   168,   140,   126,   122,
      61,    62,    58,    54,    60,    57,    53,    15,    48,    59,
      87,     4,   161,   165,   195,   199,   279,   283,   287,   310,
     132,    36,   169,     5,    19,    20,    23,    24,    35,    43,
      44,    45,    46,    59,    64,    67,    78,    85,    86,    91,
      92,   103,   126,   134,   146,   149,   150,   151,   154,   210,
     211,   214,   222,    80,    84,    63,   261,    82,   206,    63,
     262,    56,   265,    80,    75,    29,     4,    30,   101,   218,
     226,   227,    97,   135,    97,   225,   226,   227,   231,   225,
     226,   101,   226,   215,   216,   217,   226,   225,   226,    36,
      81,   101,   227,    65,    97,   147,   225,   223,   226,    16,
      90,   105,     5,   214,     6,   236,   154,    97,    80,    97,
     200,    97,    80,    97,    80,   236,    13,   268,    97,   270,
       7,     8,     9,    10,    11,    12,    79,   228,   229,   230,
     231,     6,   156,   157,    98,     6,   232,   233,   226,   231,
     226,   225,   219,     5,   150,     6,   152,   153,    28,   238,
     226,     7,     7,     5,    27,    89,   239,   254,   263,   264,
     270,   236,     6,   207,   208,   209,    47,   263,   236,   255,
     266,   267,   270,   236,    27,    80,   270,    94,   170,   101,
     102,   106,     3,   158,    98,   100,   234,    98,   100,   227,
       5,    19,    23,    24,    35,    43,    44,    45,    46,    59,
      64,    67,    86,    91,    92,   155,   212,   221,   224,    98,
     100,   268,    80,   104,   104,   226,   227,   231,   268,   268,
      14,    50,    68,    74,   174,   175,   176,   190,    98,   100,
      27,   101,    98,   100,    13,   269,    98,    27,    98,   100,
      27,   268,     6,   237,    98,    97,    27,   173,   228,   229,
     230,   101,   157,   101,   233,   225,   225,   225,   225,   225,
     225,   225,    36,    81,   225,   225,   153,   236,    37,    37,
     162,   192,   191,    72,   177,     6,   240,   264,   268,     7,
     209,   201,   268,   267,   268,   288,    27,   171,   172,   254,
     268,    76,   256,   102,     7,     7,     8,   235,   225,   225,
      27,   256,   240,   240,   178,    73,   179,   196,   102,    66,
     280,   284,   256,   268,    98,   100,   268,     4,   102,   102,
     102,   268,     4,    97,   180,    80,   256,   268,   256,   256,
      52,   289,   290,   291,   311,   172,     7,   148,    97,   249,
     254,    97,   236,     4,   202,     4,     4,     5,   293,     4,
     291,   256,   256,   270,    98,   254,    27,   166,    97,    21,
      97,    97,   270,   292,    97,    83,   312,   313,   314,    84,
      98,    98,   268,    42,   186,   255,   268,   270,   270,    49,
     294,   270,     5,   318,     4,   314,   154,   187,   256,    98,
     203,    98,    98,    97,    34,    59,   297,   298,   299,   300,
     302,    98,   270,   315,    97,    97,    17,    32,    70,   241,
      27,   270,   295,   296,   301,   303,   299,    40,   270,     6,
     188,   189,    97,   243,   242,    41,   244,   268,    98,   100,
     270,   254,    97,    98,   101,    98,   100,   249,    97,    97,
     245,    88,   181,   204,   296,    27,    84,   304,   270,   316,
     317,     7,   189,    98,   249,   249,    97,   182,    26,   250,
      77,   257,   258,   259,   268,   154,    96,   305,    98,   100,
     102,    98,    98,    38,   246,   247,   248,   254,    97,    97,
       4,   269,   205,   259,   154,   306,    51,    71,   307,    95,
     319,   320,   321,   317,   248,    98,   100,   183,   184,   185,
     254,     6,     7,     8,     9,    10,    11,    12,    13,    97,
     213,   220,   251,    97,   260,     4,   240,   240,    27,   254,
     321,   247,    98,   100,     6,     7,   252,   253,   274,   275,
     276,    98,   254,    27,    97,   268,   322,   185,   101,    98,
     100,    98,     6,   276,    98,   268,   270,   304,     7,     6,
      98,   305,   102,    14,   324,     6,   325,    22,   326,    97,
     250,   254,   327,   328,   323,    98,   100,    27,   328,   268
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   107,   108,   108,   109,   109,   111,   110,   112,   112,
     113,   113,   114,   114,   115,   116,   117,   116,   118,   118,
     119,   119,   120,   121,   121,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   126,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     131,   132,   130,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   135,   134,   136,   136,   138,   137,   140,
     139,   141,   141,   141,   142,   142,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   146,   147,   148,   146,
     146,   149,   150,   151,   152,   152,   153,   154,   154,   155,
     155,   155,   156,   156,   158,   157,   160,   161,   162,   159,
     164,   165,   163,   166,   166,   168,   169,   167,   170,   170,
     171,   171,   172,   173,   173,   174,   174,   174,   175,   176,
     176,   178,   177,   177,   180,   179,   179,   182,   181,   181,
     183,   183,   184,   184,   185,   187,   186,   186,   188,   188,
     189,   191,   190,   192,   190,   194,   195,   196,   193,   198,
     199,   200,   201,   202,   203,   204,   205,   197,   206,   206,
     207,   208,   208,   209,   209,   210,   210,   210,   210,   210,
     210,   211,   211,   212,   212,   213,   214,   215,   214,   216,
     214,   214,   217,   214,   218,   214,   214,   214,   214,   214,
     219,   214,   214,   214,   214,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   221,   221,   221,   221,   222,   222,
     222,   222,   222,   222,   223,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   225,   225,   225,   225,   226,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     231,   232,   232,   234,   233,   235,   235,   236,   237,   238,
     238,   239,   239,   240,   242,   241,   241,   243,   241,   241,
     245,   244,   244,   246,   246,   247,   247,   248,   249,   250,
     250,   251,   251,   252,   252,   253,   253,   254,   255,   256,
     256,   257,   257,   258,   258,   260,   259,   261,   261,   262,
     263,   263,   264,   265,   266,   266,   267,   268,   269,   271,
     270,   272,   272,   273,   273,   273,   273,   273,   274,   275,
     275,   276,   276,   278,   279,   280,   277,   282,   283,   284,
     281,   286,   287,   288,   285,   289,   290,   290,   292,   291,
     293,   293,   293,   294,   294,   295,   295,   296,   297,   297,
     298,   298,   299,   299,   301,   300,   303,   302,   304,   304,
     305,   305,   306,   307,   307,   307,   309,   310,   311,   308,
     312,   312,   313,   313,   315,   314,   316,   316,   317,   318,
     318,   319,   319,   320,   320,   322,   323,   321,   324,   324,
     325,   326,   326,   327,   327,   328
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     0,    10,     3,     0,
       1,     1,     1,     0,     3,     0,     0,     3,     1,     0,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     1,     0,     8,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,    11,
       1,     3,     1,     4,     1,     3,     2,     1,     4,     1,
       1,     2,     1,     3,     0,     5,     0,     0,     0,    14,
       0,     0,    23,     0,     2,     0,     0,    11,     4,     0,
       1,     3,     1,     2,     0,     1,     1,     0,     2,     1,
       1,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       1,     0,     1,     3,     1,     0,     5,     0,     1,     3,
       4,     0,     3,     0,     3,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     4,     0,
       1,     1,     3,     1,     4,     1,     2,     1,     1,     1,
       1,     5,     5,     1,     1,     1,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     4,     2,     4,     2,
       0,     4,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     3,     3,     2,     2,
       2,     1,     2,     1,     0,     3,     2,     1,     2,     2,
       2,     1,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     0,     3,     6,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     0,     5,     1,     1,     1,     1,     2,
       0,     2,     0,     1,     0,     5,     4,     0,     5,     0,
       0,     5,     0,     1,     3,     2,     1,     1,     1,     4,
       0,     1,     3,     1,     0,     1,     3,     1,     1,     2,
       0,     1,     0,     1,     2,     0,     5,     4,     0,     4,
       1,     3,     1,     4,     1,     3,     1,     1,     1,     0,
       2,     1,     2,     1,     3,     1,     4,     6,     1,     1,
       2,     4,     1,     0,     0,     0,    15,     0,     0,     0,
      15,     0,     0,     0,    15,     1,     1,     2,     0,     5,
       2,     1,     0,     4,     0,     1,     3,     1,     1,     0,
       1,     2,     1,     1,     0,     5,     0,     8,     2,     0,
       2,     0,     1,     2,     2,     0,     0,     0,     0,    17,
       1,     0,     1,     2,     0,     8,     1,     3,     1,     2,
       1,     1,     0,     1,     2,     0,     0,    11,     2,     0,
       1,     4,     0,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parserPtr, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, parserPtr); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct Parser *parserPtr)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (parserPtr);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct Parser *parserPtr)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parserPtr);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, struct Parser *parserPtr)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , parserPtr);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parserPtr); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct Parser *parserPtr)
{
  YYUSE (yyvaluep);
  YYUSE (parserPtr);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct Parser *parserPtr)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, parserPtr);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 1606 "parser-smi.y" /* yacc.c:1646  */
    {
        (yyval.err) = 0;
    }
#line 3193 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 3:
#line 1610 "parser-smi.y" /* yacc.c:1646  */
    {
	(yyval.err) = 0;
    }
#line 3201 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 4:
#line 1616 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3207 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 5:
#line 1618 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3213 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 6:
#line 1626 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;
			    
			    thisParserPtr->modulePtr = findModuleByName((yyvsp[0].id));
			    if (!thisParserPtr->modulePtr) {
				thisParserPtr->modulePtr =
				    addModule((yyvsp[0].id),
					      smiStrdup(thisParserPtr->path),
					      0,
					      thisParserPtr);
				thisParserPtr->modulePtr->
				    numImportedIdentifiers = 0;
				thisParserPtr->modulePtr->
				    numStatements = 0;
				thisParserPtr->modulePtr->
				    numModuleIdentities = 0;
				if (!strcmp((yyvsp[0].id), "SNMPv2-SMI")) {
			            /*
				     * SNMPv2-SMI is an SMIv2 module
				     * that cannot be identified by
				     * importing from SNMPv2-SMI.
				     */
				    thisModulePtr->export.language =
					SMI_LANGUAGE_SMIV2;
				}
			    } else {
			        smiPrintError(thisParserPtr,
					      ERR_MODULE_ALREADY_LOADED,
					      (yyvsp[0].id));
				/*
				 * this aborts parsing the whole file,
				 * not only the current module.
				 */
				YYABORT;
			    }
			}
#line 3255 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 7:
#line 1670 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV1;
			    checkModuleName(thisParserPtr, thisModulePtr);
			    checkModuleIdentity(thisParserPtr, thisModulePtr);
			    checkObjects(thisParserPtr, thisModulePtr);
			    checkTypes(thisParserPtr, thisModulePtr);
			    checkDefvals(thisParserPtr, thisModulePtr);
			    checkImportsUsage(thisParserPtr, thisModulePtr);
			    smiCheckTypeUsage(thisParserPtr, thisModulePtr);
			    
			    thisParserPtr->capabilitiesModulePtr = NULL;

                            (yyval.err) = 0;
			}
#line 3275 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 8:
#line 1688 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3281 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 9:
#line 1690 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3287 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 10:
#line 1694 "parser-smi.y" /* yacc.c:1646  */
    { }
#line 3293 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 11:
#line 1696 "parser-smi.y" /* yacc.c:1646  */
    {
                            thisModulePtr->export.language = SMI_LANGUAGE_SPPI;
                        }
#line 3301 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 12:
#line 1705 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3307 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 13:
#line 1707 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3313 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 14:
#line 1711 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;

			    if ((thisModulePtr->export.language != SMI_LANGUAGE_SMIV2) &&
                                (thisModulePtr->export.language != SMI_LANGUAGE_SPPI))
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV1;
			    
			    (yyval.err) = 0;
			}
#line 3328 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 15:
#line 1725 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3334 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 16:
#line 1727 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language ==
                                 SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "EXPORTS");
                            
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;

			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI")) {
			        smiPrintError(thisParserPtr, ERR_EXPORTS);
			    }
			}
#line 3354 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 17:
#line 1744 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3360 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 18:
#line 1748 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3366 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 19:
#line 1750 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3372 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 20:
#line 1755 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3378 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 21:
#line 1757 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3384 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 22:
#line 1763 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import      *importPtr;
			    Module      *modulePtr;
                            
			    /*
			     * Recursively call the parser to suffer
			     * the IMPORTS, if the module is not yet
			     * loaded.
			     */
			    modulePtr = findModuleByName((yyvsp[0].id));
			    if (!modulePtr) {
				modulePtr = loadModule((yyvsp[0].id), thisParserPtr);
			    }
			    checkImports(modulePtr, thisParserPtr);

			    if (modulePtr && !strcmp((yyvsp[0].id), "SNMPv2-SMI")) {
			        /*
				 * A module that imports a macro or
				 * type definition from SNMPv2-SMI
				 * seems to be SMIv2 style - but only if
                                 * it is not SPPI yet.
				 */
                                if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
				    for (importPtr =
					     thisModulePtr->firstImportPtr;
				         importPtr;
				         importPtr = importPtr->nextPtr) {
				        if ((!strcmp(importPtr->export.module,
						     (yyvsp[0].id))) &&
					    ((importPtr->kind == KIND_MACRO) ||
					     (importPtr->kind == KIND_TYPE))) {
					    thisModulePtr->export.language =
					        SMI_LANGUAGE_SMIV2;
				        }
				    }
                                }
			    }

			    smiFree((yyvsp[0].id));
			}
#line 3429 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 23:
#line 1806 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3435 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 24:
#line 1809 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3441 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 25:
#line 1816 "parser-smi.y" /* yacc.c:1646  */
    {
			    addImport((yyvsp[0].id), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
#line 3451 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 26:
#line 1822 "parser-smi.y" /* yacc.c:1646  */
    {
			    addImport((yyvsp[0].id), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
#line 3461 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 27:
#line 1828 "parser-smi.y" /* yacc.c:1646  */
    {
			    addImport(smiStrdup((yyvsp[0].id)), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
#line 3471 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 28:
#line 1844 "parser-smi.y" /* yacc.c:1646  */
    {
                            /*
                             * There are PIBs that import e.g. Counter64 - so
                             * don't complain here about SMI keywords.
                             */
                           /* if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                              smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, $1);*/
                            (yyval.id) = (yyvsp[0].id);
                        }
#line 3485 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 29:
#line 1854 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				smiPrintError(thisParserPtr, ERR_SPPI_TYPE_IN_MIB, (yyvsp[0].id));
                            (yyval.id) = (yyvsp[0].id);
                        }
#line 3495 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1888 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_MODULENAME_32, ERR_MODULENAME_64);
			    (yyval.id) = (yyvsp[0].id);
			}
#line 3505 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1900 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3511 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1902 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3517 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1907 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3523 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1909 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 3529 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1913 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3538 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1918 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3547 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1923 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3556 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1928 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3565 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1933 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3574 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1938 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3583 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1943 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3592 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1948 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3601 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1953 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3610 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1958 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3619 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1963 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3628 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1968 "parser-smi.y" /* yacc.c:1646  */
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
#line 3637 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1973 "parser-smi.y" /* yacc.c:1646  */
    {
			    smiPrintError(thisParserPtr,
					  ERR_FLUSH_DECLARATION);
			    yyerrok;
			    (yyval.err) = 1;
			}
#line 3648 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1987 "parser-smi.y" /* yacc.c:1646  */
    {
			    Macro *macroPtr;

			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MACRO;

			    macroPtr = addMacro(smiStrdup((yyvsp[0].id)),
						0, thisParserPtr);
			    setMacroLine(macroPtr, thisParserPtr->firstStatementLine,
					 thisParserPtr);
			}
#line 3664 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1999 "parser-smi.y" /* yacc.c:1646  */
    {
			    /*
			     * ASN.1 macros are known to be in these
			     * modules.
			     */
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1215") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI-TC")) {
			        smiPrintError(thisParserPtr, ERR_MACRO);
			    }
			}
#line 3695 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 72:
#line 2027 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.err) = 0;
                        }
#line 3703 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 73:
#line 2032 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3709 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 74:
#line 2033 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3715 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 75:
#line 2034 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3721 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 76:
#line 2035 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3727 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 77:
#line 2036 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3733 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2037 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3739 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2038 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3745 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2039 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3751 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2040 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3757 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2041 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.id) = (yyvsp[0].id); }
#line 3763 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2045 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") && 
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_CHOICE);
			    }
			}
#line 3786 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2065 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = addType(NULL, SMI_BASETYPE_UNKNOWN, 0,
					 thisParserPtr);
			}
#line 3795 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 85:
#line 2075 "parser-smi.y" /* yacc.c:1646  */
    {
			  (yyval.id) = (yyvsp[0].id);
			}
#line 3803 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2080 "parser-smi.y" /* yacc.c:1646  */
    {
			    smiPrintError (thisParserPtr,
					   ERR_BAD_LOWER_IDENTIFIER_CASE,
					   (yyvsp[0].id));
			    /* xxx
			    if ((thisParserPtr->flags & SMI_FLAG_BE_LAX) == 0) {
			        YYERROR;
			    }
			    */
			  (yyval.id) = (yyvsp[0].id);
			}
#line 3819 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2095 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_VALUEASSIGNMENT;

			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        if (strchr((yyvsp[0].id), '-') &&
				    (strcmp((yyvsp[0].id), "mib-2") ||
				  strcmp(thisModulePtr->export.name, "SNMPv2-SMI"))) {
				    smiPrintError(thisParserPtr,
						  ERR_OIDNAME_INCLUDES_HYPHEN,
						  (yyvsp[0].id));
				}
			    }
			}
#line 3843 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2116 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-7].id), &objectPtr);
			    objectPtr = setObjectName(objectPtr, (yyvsp[-7].id), thisParserPtr);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_VALUEASSIGNMENT);
			    (yyval.err) = 0;
			}
#line 3861 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2135 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_TYPEASSIGNMENT;

			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_TYPENAME_32, ERR_TYPENAME_64);
			}
#line 3873 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 90:
#line 2143 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *typePtr;
			    
			    if (strlen((yyvsp[-3].id))) {
				if ((yyvsp[0].typePtr)->export.basetype != SMI_BASETYPE_UNKNOWN) {
				    smiCheckTypeName(thisParserPtr,
						     thisModulePtr, (yyvsp[-3].id),
						     thisParserPtr->firstStatementLine);
				}
				setTypeLine((yyvsp[0].typePtr), thisParserPtr->firstStatementLine,
					    thisParserPtr);
				setTypeName((yyvsp[0].typePtr), (yyvsp[-3].id));
				(yyval.err) = 0;
			    } else {
				(yyval.err) = 0;
			    }

			    /*
			     * If we are in an SMI module, some type
			     * definitions derived from ASN.1 `INTEGER'
			     * must be modified to libsmi basetypes.
			     */
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "SNMPv2-SMI"))) {
				if (!strcmp((yyvsp[-3].id), "Counter32")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "Gauge32")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "Unsigned32")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "TimeTicks")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "Counter64")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED64;
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned64 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned64 = SMI_BASETYPE_UNSIGNED64_MAX;
				    }
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned64Ptr);
				}
			    }
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "RFC1155-SMI") ||
				 !strcmp(thisModulePtr->export.name, "RFC1065-SMI"))) {
				if (!strcmp((yyvsp[-3].id), "Counter")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "Gauge")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "TimeTicks")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "NetworkAddress")) {
				    setTypeName((yyvsp[0].typePtr), smiStrdup("NetworkAddress"));
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_OCTETSTRING;
				    setTypeParent((yyvsp[0].typePtr), findTypeByModuleAndName(
					                   thisModulePtr,
						           "IpAddress"));
				} else if (!strcmp((yyvsp[-3].id), "IpAddress")) {
				    typePtr = findTypeByModuleAndName(
					thisModulePtr, "NetworkAddress");
				    if (typePtr) 
					setTypeParent(typePtr, (yyvsp[0].typePtr));
				}
			    }
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "COPS-PR-SPPI"))) {
				if (!strcmp((yyvsp[-3].id), "Unsigned32")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "TimeTicks")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[-3].id), "Unsigned64")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED64;
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.unsigned64 = 0;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned64 = SMI_BASETYPE_UNSIGNED64_MAX;
				    }
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeUnsigned64Ptr);
				} else if (!strcmp((yyvsp[-3].id), "Integer64")) {
				    (yyvsp[0].typePtr)->export.basetype = SMI_BASETYPE_INTEGER64;
				    if ((yyvsp[0].typePtr)->listPtr) {
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_INTEGER64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.minValue.value.integer64 = SMI_BASETYPE_INTEGER64_MIN;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_INTEGER64;
					((Range *)(yyvsp[0].typePtr)->listPtr->ptr)->export.maxValue.value.integer64 = SMI_BASETYPE_INTEGER64_MAX;
				    }
				    setTypeParent((yyvsp[0].typePtr), smiHandle->typeInteger64Ptr);
				}
			    }
			}
#line 4033 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 91:
#line 2301 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.id) = (yyvsp[0].id);
			}
#line 4041 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 92:
#line 2305 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.id) = smiStrdup((yyvsp[0].id));
			    /*
			     * well known types (keywords in this grammar)
			     * are known to be defined in these modules.
			     */
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_TYPE_SMI_OR_SPPI, (yyvsp[0].id));
			    }
			}
#line 4069 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2329 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.id) = smiStrdup((yyvsp[0].id));
			    /*
			     * well known types (keywords in this grammar)
			     * are known to be defined in these modules.
			     */
			    if ((strcmp(thisParserPtr->modulePtr->export.name,
					"COPS-PR-SPPI")) &&
				(thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI))
			        smiPrintError(thisParserPtr, ERR_TYPE_SPPI, (yyvsp[0].id));
                        }
#line 4085 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 95:
#line 2344 "parser-smi.y" /* yacc.c:1646  */
    {
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName((yyvsp[0].id), thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, (yyvsp[0].id));
                            (yyval.id) = (yyvsp[0].id);
                        }
#line 4096 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 106:
#line 2369 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].typePtr)->export.name) {
				/*
				 * If we found an already defined type,
				 * we have to inherit a new type structure.
				 * (Otherwise the `Syntax' rule created
				 * a new type for us.)
				 */
				(yyval.typePtr) = duplicateType((yyvsp[0].typePtr), 0, thisParserPtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			    } else {
				(yyval.typePtr) = (yyvsp[0].typePtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			    }
			}
#line 4116 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 107:
#line 2385 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    thisParserPtr->currentDecl = SMI_DECL_TEXTUALCONVENTION;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    if (strcmp(thisModulePtr->export.name, "SNMPv2-TC")) {
				importPtr =
				    findImportByName("TEXTUAL-CONVENTION",
						     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				} else {
                                    if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "TEXTUAL-CONVENTION",
						      "SNMPv2-TC");
                                    else
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "TEXTUAL-CONVENTION",
						      "COPS-PR-SPPI");
				}
			    }
			}
#line 4149 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 108:
#line 2416 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 4157 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 109:
#line 2421 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (((yyvsp[0].typePtr)) && !((yyvsp[0].typePtr)->export.name)) {
				/*
				 * If the Type we found has just been
				 * defined, we don't have to allocate
				 * a new one.
				 */
				(yyval.typePtr) = (yyvsp[0].typePtr);
			    } else {
				if (!((yyvsp[0].typePtr)))
				    smiPrintError(thisParserPtr, ERR_INTERNAL);
				/*
				 * Otherwise, we have to allocate a
				 * new Type struct, inherited from $10.
				 */
				(yyval.typePtr) = duplicateType((yyvsp[0].typePtr), 0, thisParserPtr);
			    }
			    setTypeDescription((yyval.typePtr), (yyvsp[-4].text), thisParserPtr);
			    if ((yyvsp[-2].text)) {
				setTypeReference((yyval.typePtr), (yyvsp[-2].text), thisParserPtr);
			    }
			    setTypeStatus((yyval.typePtr), (yyvsp[-6].status));
			    if ((yyvsp[-8].text)) {
				if (smiCheckFormat(thisParserPtr,
						   (yyval.typePtr)->export.basetype, (yyvsp[-8].text),
						   thisParserPtr->firstStatementLine)) {
				    setTypeFormat((yyval.typePtr), (yyvsp[-8].text));
				}
			    }
			    setTypeDecl((yyval.typePtr), SMI_DECL_TEXTUALCONVENTION);
			}
#line 4193 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 110:
#line 2453 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			    setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			}
#line 4202 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 111:
#line 2461 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].typePtr)) {
				(yyval.typePtr) = addType(NULL,
					     SMI_BASETYPE_UNKNOWN, 0,
					     thisParserPtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_IMPL_SEQUENCEOF);
				setTypeParent((yyval.typePtr), (yyvsp[0].typePtr));
			    } else {
				(yyval.typePtr) = NULL;
			    }
			}
#line 4218 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 112:
#line 2480 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *typePtr;
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, (yyvsp[0].id));
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName((yyvsp[0].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /* 
				     * forward referenced type. create it,
				     * marked with FLAG_INCOMPLETE.
				     */
				    typePtr = addType((yyvsp[0].id),
						      SMI_BASETYPE_UNKNOWN,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				    (yyval.typePtr) = typePtr;
				} else {
				    /*
				     * imported type.
				     * TODO: is this allowed in a SEQUENCE? 
				     */
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				    smiFree((yyvsp[0].id));
				}
			    } else {
				smiFree((yyvsp[0].id));
			    }
			}
#line 4258 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 113:
#line 2520 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = addType(NULL, SMI_BASETYPE_UNKNOWN, 0,
					 thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[-1].listPtr));
			}
#line 4268 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 114:
#line 2528 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 4278 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 115:
#line 2535 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 4293 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 116:
#line 2554 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    Import *importPtr;
			    Type *typePtr;
			    
			    objectPtr =
			        findObjectByModuleAndName(thisParserPtr->modulePtr,
							  (yyvsp[-1].id));

			    if (!objectPtr) {
				importPtr = findImportByName((yyvsp[-1].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    objectPtr = addObject((yyvsp[-1].id), thisParserPtr->pendingNodePtr,
					                  0,
					                  FLAG_INCOMPLETE |
							  FLAG_SEQTYPE,
						          thisParserPtr);
				    setObjectType(objectPtr, (yyvsp[0].typePtr));
				} else {
				    /*
				     * imported object.
				     */
				    importPtr->use++;
				    objectPtr = findObjectByModulenameAndName(
					importPtr->export.module, (yyvsp[-1].id));
				    smiFree((yyvsp[-1].id));

				    if (objectPtr->typePtr->export.name) {
					typePtr = objectPtr->typePtr;
				    } else {
					typePtr = objectPtr->typePtr->parentPtr;
				    }
				    if (((yyvsp[0].typePtr) != typePtr) &&
					(((yyvsp[0].typePtr)->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					(((yyvsp[0].typePtr)->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }
				}
			    } else {
				smiFree((yyvsp[-1].id));
				if (objectPtr->typePtr) {

				    if (objectPtr->typePtr->export.name) {
					typePtr = objectPtr->typePtr;
				    } else {
					typePtr = objectPtr->typePtr->parentPtr;
				    }
				    if (((yyvsp[0].typePtr) != typePtr) &&
					(((yyvsp[0].typePtr)->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					(((yyvsp[0].typePtr)->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }

				} else {
				    setObjectType(objectPtr, (yyvsp[0].typePtr));
				    addObjectFlags(objectPtr,
						   FLAG_SEQTYPE);
				}
			    }

			    (yyval.objectPtr) = objectPtr;
			}
#line 4378 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 117:
#line 2637 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			    if ((yyval.typePtr))
				defaultBasetype = (yyval.typePtr)->export.basetype;
			}
#line 4388 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 118:
#line 2645 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *typePtr;
			    List *p;
			    
			    defaultBasetype = SMI_BASETYPE_BITS;
			    typePtr = addType(NULL, SMI_BASETYPE_BITS,
					      FLAG_INCOMPLETE,
					      thisParserPtr);
			    setTypeDecl(typePtr, SMI_DECL_IMPLICIT_TYPE);
			    setTypeParent(typePtr, smiHandle->typeBitsPtr);
			    setTypeList(typePtr, (yyvsp[-1].listPtr));
			    for (p = (yyvsp[-1].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = typePtr;
			    smiCheckNamedNumbersOrder(parserPtr, typePtr);
			    (yyval.typePtr) = typePtr;
			}
#line 4409 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 119:
#line 2665 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 4417 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 120:
#line 2669 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* TODO: */
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
#line 4426 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 121:
#line 2674 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *typePtr;
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, (yyvsp[-1].id));
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName((yyvsp[-1].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /* 
				     * forward referenced type. create it,
				     * marked with FLAG_INCOMPLETE.
				     */
				    typePtr = addType((yyvsp[-1].id), SMI_BASETYPE_UNKNOWN,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				    (yyval.typePtr) = typePtr;
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				    smiFree((yyvsp[-1].id));
				}
			    } else {
				smiFree((yyvsp[-1].id));
			    }
			}
#line 4461 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 122:
#line 2707 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].namedNumberPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 4471 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 123:
#line 2713 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[0].namedNumberPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 4486 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 124:
#line 2726 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_BITNAME_32, ERR_BITNAME_64);
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (strchr((yyvsp[0].id), '-')) {
				    smiPrintError(thisParserPtr,
						  ERR_NAMEDBIT_INCLUDES_HYPHEN,
						  (yyvsp[0].id));
				}
			    }
			}
#line 4503 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 125:
#line 2739 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.namedNumberPtr) = smiMalloc(sizeof(NamedNumber));
			    (yyval.namedNumberPtr)->export.name = (yyvsp[-4].id);
			    (yyval.namedNumberPtr)->export.value.basetype =
				                       SMI_BASETYPE_UNSIGNED32;
			    (yyval.namedNumberPtr)->export.value.value.unsigned32 = (yyvsp[-1].unsigned32);
			    /* RFC 2578 7.1.4 */
			    if ((yyvsp[-1].unsigned32) >= 65535*8) {
				smiPrintError(thisParserPtr,
					      ERR_BITS_NUMBER_TOO_LARGE,
					      (yyvsp[-4].id), (yyvsp[-1].unsigned32));
			    } else {
				if ((yyvsp[-1].unsigned32) >= 128) {
				    smiPrintError(thisParserPtr,
						  ERR_BITS_NUMBER_LARGE,
						  (yyvsp[-4].id), (yyvsp[-1].unsigned32));
				}
			    }
			}
#line 4527 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 126:
#line 2761 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTIDENTITY;

			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 4541 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 127:
#line 2771 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    if (strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
                                strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")) {
				importPtr = findImportByName("OBJECT-IDENTITY",
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				} else {
                                    if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "OBJECT-IDENTITY",
						      "SNMPv2-SMI");
                                    else
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "OBJECT-IDENTITY",
						      "COPS-PR-SPPI");
				}
			    }
			}
#line 4569 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2796 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 4577 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2802 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-13].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-13].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTIDENTITY);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectStatus(objectPtr, (yyvsp[-8].status));
			    setObjectDescription(objectPtr, (yyvsp[-6].text), thisParserPtr);
			    if ((yyvsp[-4].text)) {
				setObjectReference(objectPtr, (yyvsp[-4].text), thisParserPtr);
			    }
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    (yyval.err) = 0;
			}
#line 4601 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2824 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTTYPE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 4615 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2834 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("OBJECT-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_MACRO_NOT_IMPORTED,
						  "OBJECT-TYPE", "SNMPv2-SMI");
				} else if (thisModulePtr->export.language ==
                                    SMI_LANGUAGE_SPPI) {
                                    smiPrintError(thisParserPtr,
                                                  ERR_MACRO_NOT_IMPORTED,
                                                  "OBJECT-TYPE", "COPS-PR-SPPI");
                                } else {
				    smiPrintError(thisParserPtr,
						  ERR_MACRO_NOT_IMPORTED,
						  "OBJECT-TYPE", "RFC-1212");
				}
			    }
                            indexFlag = 0;
			    variationkind = SMI_NODEKIND_UNKNOWN;
			}
#line 4647 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2875 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr, *parentPtr;
			    Type *typePtr = NULL;
			    
			    objectPtr = (yyvsp[-1].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-22].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-22].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    if (checkObjectFlags(objectPtr, FLAG_SEQTYPE)) {
				deleteObjectFlags(objectPtr, FLAG_SEQTYPE);
				if ((yyvsp[-17].typePtr)) {
				    if ((yyvsp[-17].typePtr)->export.name) {
					typePtr = (yyvsp[-17].typePtr);
                                        /*
                                         * According to RFC 3159 7.1.3. Opaque must not be used
                                         * in a SYNTAX clause.
                                         */
                                        if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                            !strcmp(typePtr->export.name, "Opaque"))
                                            smiPrintError(thisParserPtr, ERR_OPAQUE_IN_SYNTAX);
                                        /*
                                         * According to RFC 3159 7.1.4. IpAddress must not be used
                                         * in a SYNTAX clause.
                                         */
                                        if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                            !strcmp(typePtr->export.name, "IpAddress"))
                                            smiPrintError(thisParserPtr, ERR_IPADDRESS_IN_SYNTAX);
				    } else {
					typePtr = (yyvsp[-17].typePtr)->parentPtr;
				    }
				    if ((objectPtr->typePtr != typePtr) &&
					((objectPtr->typePtr->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					((objectPtr->typePtr->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }
				}
			    }
			    setObjectType(objectPtr, (yyvsp[-17].typePtr));
			    if (!((yyvsp[-17].typePtr)->export.name)) {
				/*
				 * An inlined type.
				 */
#if 0 /* export implicitly defined types by the node's lowercase name */
				setTypeName((yyvsp[-17].typePtr), (yyvsp[-22].id));
#endif
			    }
			    setObjectUnits(objectPtr, (yyvsp[-16].text));
			    setObjectAccess(objectPtr, (yyvsp[-15].access));
			    if (thisParserPtr->flags & FLAG_CREATABLE) {
				thisParserPtr->flags &= ~FLAG_CREATABLE;
				parentPtr =
				  objectPtr->nodePtr->parentPtr->lastObjectPtr;
				if (parentPtr &&
				    parentPtr->export.indexkind !=
				       SMI_INDEX_UNKNOWN) {
				    /*
				     * add objectPtr to the parent object's
				     * listPtr, which is the list of columns
				     * needed for row creation.
				     *
				     * Note, that this would clash, if the
				     * parent row object-type is not yet
				     * defined.
				     */
				    /*
				    newlistPtr = smiMalloc(sizeof(List));
				    newlistPtr->nextPtr = NULL;
				    newlistPtr->ptr = objectPtr;
				    */
				    /*
				     * Look up the parent object-type.
				     */
				    /*
				    if (parentPtr->listPtr) {
					for(listPtr = parentPtr->listPtr;
					    listPtr->nextPtr;
					    listPtr = listPtr->nextPtr);
					listPtr->nextPtr = newlistPtr;
				    } else {
					parentPtr->listPtr = newlistPtr;
				    }
				    */
				    addObjectFlags(parentPtr, FLAG_CREATABLE);
				    setObjectCreate(parentPtr, 1);
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_SCALAR_READCREATE);
				}
			    }
			    setObjectStatus(objectPtr, (yyvsp[-11].status));
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    if ((yyvsp[-10].text)) {
				setObjectDescription(objectPtr, (yyvsp[-10].text), thisParserPtr);
			    }
			    if ((yyvsp[-8].text)) {
				setObjectReference(objectPtr, (yyvsp[-8].text), thisParserPtr);
			    }
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) {
                                /*
                                 * For SMI documents either $16 (IndexPart) or $17 (MibIndex)
                                 * are used, but not both. This is signalled via the indexFlag
                                 * which is 1 if IndexPart has been used.
                                 */
                                if (indexFlag == INDEXFLAG_AUGMENTS) { /* IndexPart was used */
			            if ((yyvsp[-7].index).indexkind != SMI_INDEX_UNKNOWN) {
				        setObjectList(objectPtr, (yyvsp[-7].index).listPtr);
				        setObjectImplied(objectPtr, (yyvsp[-7].index).implied);
				        setObjectIndexkind(objectPtr, (yyvsp[-7].index).indexkind);
				        setObjectRelated(objectPtr, (yyvsp[-7].index).rowPtr);
			            }
                                } else {
			            if ((yyvsp[-6].index).indexkind != SMI_INDEX_UNKNOWN) {
				        setObjectList(objectPtr, (yyvsp[-6].index).listPtr);
				        setObjectImplied(objectPtr, (yyvsp[-6].index).implied);
				        setObjectIndexkind(objectPtr, (yyvsp[-6].index).indexkind);
				        setObjectRelated(objectPtr, (yyvsp[-6].index).rowPtr);
			            }
                                }
                            } else {
                                /*
                                 * PIBs contain either PIB-INDEX or AUGMENTS or EXTENDS - 
                                 * but only with one Index entry. A PIB-INDEX may be
                                 * followed by a full INDEX. We get the indexkind
                                 * from the first.
                                 * Note that PIB-INDEX/AUGMENTS/EXTENS is always
                                 * the first element in objectPtr->listPtr.
                                 * If an optional INDEX exists then it is
                                 * appended to this list.
                                 */
			        if ((yyvsp[-7].index).indexkind != SMI_INDEX_UNKNOWN) {
                                    setObjectList(objectPtr, (yyvsp[-7].index).listPtr);
				    setObjectIndexkind(objectPtr, (yyvsp[-7].index).indexkind);
				    setObjectRelated(objectPtr, (yyvsp[-7].index).rowPtr);
			        }
			        if ((yyvsp[-6].index).indexkind != SMI_INDEX_UNKNOWN) {
                                    if (objectPtr->listPtr) {
                                        List *p;
                                        for (p = objectPtr->listPtr; p->nextPtr;
                                             p = p->nextPtr);
                                        p->nextPtr = (yyvsp[-6].index).listPtr;
                                    }
				    setObjectImplied(objectPtr, (yyvsp[-6].index).implied);
			        }
                            }
                            if ((yyvsp[-5].listPtr)) {
                                setObjectUniqueness(objectPtr, (yyvsp[-5].listPtr));
                            }
			    if ((yyvsp[-4].valuePtr)) {
				if (objectPtr->typePtr
				    && (((objectPtr->typePtr->export.basetype == SMI_BASETYPE_OCTETSTRING) &&
					 ((yyvsp[-4].valuePtr)->basetype != SMI_BASETYPE_OCTETSTRING))
					|| ((objectPtr->typePtr->export.basetype == SMI_BASETYPE_OBJECTIDENTIFIER) &&
					    ((yyvsp[-4].valuePtr)->basetype != SMI_BASETYPE_OBJECTIDENTIFIER)))) {
				    smiPrintError(thisParserPtr,
						  ERR_DEFVAL_SYNTAX);
				    if ((yyvsp[-4].valuePtr)->basetype == SMI_BASETYPE_OBJECTIDENTIFIER) {
					smiFree((yyvsp[-4].valuePtr)->value.oid);
				    }
				    if (((yyvsp[-4].valuePtr)->basetype == SMI_BASETYPE_BITS) ||
					((yyvsp[-4].valuePtr)->basetype == SMI_BASETYPE_OCTETSTRING)) {
					smiFree((yyvsp[-4].valuePtr)->value.ptr);
				    }
				    smiFree((yyvsp[-4].valuePtr));
				} else {
				    setObjectValue(objectPtr, (yyvsp[-4].valuePtr));
				}
			    }
                            if ((yyvsp[-14].objectPtr)) {
                                if (objectPtr->relatedPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "relatedPtr", "PIB-REFERENCES");
                                /*
                                 * PIB-REFERENCES clauses are only allowed for
                                 * objects with a SYNTAX of 'ReferenceId'.
                                 * See RFC 3159 7.10
                                 */
                                if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    strcmp(objectPtr->typePtr->export.name, "ReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_PIB_REFERENCES_WRONG_TYPE,
                                                        objectPtr->line);
                                else
                                    setObjectRelated(objectPtr, (yyvsp[-14].objectPtr));
                            } else {
                               /*
                                * Does this object have a SYNTAX of 'ReferenceId'
                                * and a PIB-REFERENCES clause?
                                * See RFC 3159 7.10
                                */
                               if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                   objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                   !strcmp(objectPtr->typePtr->export.name, "ReferenceId"))
                                   smiPrintErrorAtLine(parserPtr, ERR_LACKING_PIB_REFERENCES,
                                                       objectPtr->line);
                            }
                            if ((yyvsp[-13].objectPtr)) {
                                if (objectPtr->relatedPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "relatedPtr", "PIB-TAG");
                                /*
                                 * PIB-TAG clauses are only allowed for
                                 * objects with a SYNTAX of 'TagReferenceId'.
                                 * See RFC 3159 7.11
                                 */
                                if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    strcmp(objectPtr->typePtr->export.name, "TagReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_PIB_TAG_WRONG_TYPE,
                                                        objectPtr->line);
                                else
                                    setObjectRelated(objectPtr, (yyvsp[-13].objectPtr));
                            } else {
                                /*
                                 * Does this object have a SYNTAX of 'TagReferenceId'
                                 * and a PIB-TAG clause?
                                 * See RFC 3159 7.11
                                 */
                                if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                    objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    !strcmp(objectPtr->typePtr->export.name, "TagReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_LACKING_PIB_TAG,
                                                        objectPtr->line);

                            }
                            if ((yyvsp[-9].listPtr)) {
                                if (objectPtr->listPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "listPtr", "INSTALL-ERRORS");
                                /*
                                 * Are INSTALL-ERRORS only used with tables?
                                 * See RFC 3159 7.4
                                 */
                                if (!((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
                                    (objectPtr->typePtr) &&
                                    (objectPtr->typePtr->export.decl == SMI_DECL_IMPL_SEQUENCEOF)))
                                    smiPrintErrorAtLine(parserPtr, ERR_INSTALL_ERRORS_FOR_NON_TABLE,
                                                        objectPtr->line);
                                else
                                    setObjectList(objectPtr, (yyvsp[-9].listPtr));
                            }
			    (yyval.err) = 0;
			}
#line 4905 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 133:
#line 3131 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2) ||
                                (thisModulePtr->export.language == SMI_LANGUAGE_SPPI))
			    {
				smiPrintError(thisParserPtr,
					      ERR_MISSING_DESCRIPTION);
			    }
			    (yyval.text) = NULL;
			}
#line 4919 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 134:
#line 3141 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = (yyvsp[0].text);
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 4928 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 135:
#line 3148 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_TRAPTYPE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 4942 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 136:
#line 3158 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "TRAP-TYPE");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        smiPrintError(thisParserPtr, ERR_TRAP_TYPE);
			    }

			    importPtr = findImportByName("TRAP-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "TRAP-TYPE", "RFC-1215");
			    }
			}
#line 4967 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 137:
#line 3184 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    Node *nodePtr;
			    
			    objectPtr = (yyvsp[-5].objectPtr);
			    nodePtr = findNodeByParentAndSubid(
				objectPtr->nodePtr, 0);
			    if (nodePtr && nodePtr->lastObjectPtr &&
	       		        (nodePtr->lastObjectPtr->modulePtr == thisModulePtr)) {
				/*
				 * hopefully, the last defined Object for
				 * this Node is the one we expect.
				 */
				objectPtr = nodePtr->lastObjectPtr;
			    } else {
				objectPtr = addObject(NULL,
						      objectPtr->nodePtr,
						      0,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
			    }
			    objectPtr = addObject(NULL,
						  objectPtr->nodePtr,
						  (yyvsp[0].unsigned32),
						  FLAG_INCOMPLETE,
						  thisParserPtr);
			    
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-10].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-10].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_TRAPTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectList(objectPtr, (yyvsp[-4].listPtr));
			    setObjectStatus(objectPtr, SMI_STATUS_CURRENT); 
			    setObjectDescription(objectPtr, (yyvsp[-3].text), thisParserPtr);
			    if ((yyvsp[-2].text)) {
				setObjectReference(objectPtr, (yyvsp[-2].text), thisParserPtr);
			    }
			    (yyval.err) = 0;
			}
#line 5016 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 138:
#line 3231 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 5024 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 139:
#line 3235 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = NULL;
			}
#line 5032 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 140:
#line 3241 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].objectPtr)) {
				(yyval.listPtr) = smiMalloc(sizeof(List));
				(yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
				(yyval.listPtr)->nextPtr = NULL;
			    } else {
				(yyval.listPtr) = NULL;
			    }
			}
#line 5046 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 141:
#line 3251 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;

			    if ((yyvsp[0].objectPtr)) {
				p = smiMalloc(sizeof(List));
				p->ptr = (yyvsp[0].objectPtr);
				p->nextPtr = NULL;
				if ((yyvsp[-2].listPtr)) {
				    for (pp = (yyvsp[-2].listPtr); pp->nextPtr;
					 pp = pp->nextPtr);
				    pp->nextPtr = p;
				    (yyval.listPtr) = (yyvsp[-2].listPtr);
				} else {
				    (yyval.listPtr) = p;
				}
			    } else {
				(yyval.listPtr) = (yyvsp[-2].listPtr);
			    }
			}
#line 5070 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 142:
#line 3273 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 5078 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 143:
#line 3279 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = (yyvsp[0].text);
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 5087 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 144:
#line 3284 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.text) = NULL; }
#line 5093 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 145:
#line 3288 "parser-smi.y" /* yacc.c:1646  */
    {
                            (yyval.access) = (yyvsp[0].access);
                        }
#line 5101 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 146:
#line 3292 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "MAX-ACCESS");
                            if ((yyvsp[0].access) == SMI_ACCESS_NOT_ACCESSIBLE)
                                smiPrintError(thisParserPtr, ERR_NOT_ACCESSIBLE_IN_PIB_ACCESS);
                            (yyval.access) = (yyvsp[0].access);
                        }
#line 5113 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 147:
#line 3300 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = 0;  }
#line 5119 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 148:
#line 3304 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = (yyvsp[0].access); }
#line 5125 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 149:
#line 3308 "parser-smi.y" /* yacc.c:1646  */
    { 
                            smiPrintError(thisParserPtr, ERR_POLICY_ACCESS_IN_PIB);
                        }
#line 5133 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 150:
#line 3312 "parser-smi.y" /* yacc.c:1646  */
    { }
#line 5139 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 151:
#line 3316 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-REFERENCES");
                        }
#line 5148 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 152:
#line 3321 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.objectPtr) = (yyvsp[-1].objectPtr); }
#line 5154 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 153:
#line 3323 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.objectPtr) = 0; }
#line 5160 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 154:
#line 3327 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-TAG");
                        }
#line 5169 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 155:
#line 3332 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.objectPtr) = (yyvsp[-1].objectPtr); }
#line 5175 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 156:
#line 3334 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.objectPtr) = 0; }
#line 5181 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 157:
#line 3339 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "UNIQUENESS");
                        }
#line 5190 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 158:
#line 3344 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = (yyvsp[-1].listPtr); }
#line 5196 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 159:
#line 3346 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = NULL; }
#line 5202 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 160:
#line 3350 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = (yyvsp[0].listPtr); }
#line 5208 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 161:
#line 3352 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = NULL; }
#line 5214 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 162:
#line 3356 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 5224 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 163:
#line 3363 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
                        }
#line 5239 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 164:
#line 3376 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.objectPtr) = (yyvsp[0].objectPtr); }
#line 5245 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 165:
#line 3380 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "INSTALL-ERRORS");
                        }
#line 5254 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 166:
#line 3385 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = (yyvsp[-1].listPtr); }
#line 5260 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 167:
#line 3387 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = NULL; }
#line 5266 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 168:
#line 3391 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 5276 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 169:
#line 3398 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
                        }
#line 5291 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 170:
#line 3411 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
                            if (((yyvsp[-1].unsigned32) < 1) || ((yyvsp[-1].unsigned32) > 65536))
                                smiPrintError(thisParserPtr, ERR_ERROR_NUMBER_RANGE, (yyvsp[-1].unsigned32));
                            /*
                             * This is not a regular object that will be added vid
                             * 'addObject' as error identifier have no other
                             * meaning in PIBs. They are just used for
                             * a direct mapping to the actual protocol fields.
                             */
                            objectPtr = smiMalloc(sizeof(Object));
                            objectPtr->export.name = (yyvsp[-3].id);
                            objectPtr->export.oidlen = 1;
                            objectPtr->export.oid = (void *)(yyvsp[-1].unsigned32);
			    (yyval.objectPtr) = objectPtr;
			}
#line 5313 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 171:
#line 3432 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV1)
			    {
			        smiPrintError(thisParserPtr,
					      ERR_MAX_ACCESS_IN_SMIV1);
			    } else if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "MAX-ACCESS");
			}
#line 5326 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 172:
#line 3441 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = (yyvsp[0].access); }
#line 5332 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 173:
#line 3443 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        smiPrintError(thisParserPtr, ERR_ACCESS_IN_SMIV2);
			    } else if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "ACCESS");
			}
#line 5344 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 174:
#line 3452 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = (yyvsp[0].access); }
#line 5350 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 175:
#line 3456 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_NOTIFICATIONTYPE;

			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 5364 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 176:
#line 3466 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "NOTIFICATION-TYPE");
                                
			    importPtr = findImportByName("NOTIFICATION-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "NOTIFICATION-TYPE",
					      "SNMPv2-SMI");
			    }
			}
#line 5386 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 177:
#line 3486 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 5394 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 178:
#line 3492 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-14].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-14].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_NOTIFICATIONTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectList(objectPtr, (yyvsp[-10].listPtr));
			    setObjectStatus(objectPtr, (yyvsp[-8].status));
			    setObjectDescription(objectPtr, (yyvsp[-6].text), thisParserPtr);
			    if ((yyvsp[-4].text)) {
				setObjectReference(objectPtr, (yyvsp[-4].text), thisParserPtr);
			    }
			    (yyval.err) = 0;
			}
#line 5421 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 179:
#line 3517 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULEIDENTITY;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 5435 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 180:
#line 3527 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("MODULE-IDENTITY",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "MODULE-IDENTITY",
					      "SNMPv2-SMI");
			    }
			    
			    if (thisParserPtr->modulePtr->numModuleIdentities > 0)
			    {
			        smiPrintError(thisParserPtr,
					      ERR_TOO_MANY_MODULE_IDENTITIES);
			    }
			    if (thisParserPtr->modulePtr->numStatements > 0) {
			        smiPrintError(thisParserPtr,
					      ERR_MODULE_IDENTITY_NOT_FIRST);
			    }
			}
#line 5464 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 181:
#line 3552 "parser-smi.y" /* yacc.c:1646  */
    {
                          /* do nothing at the moment */
                        }
#line 5472 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 182:
#line 3556 "parser-smi.y" /* yacc.c:1646  */
    {
			    setModuleLastUpdated(thisParserPtr->modulePtr, (yyvsp[0].date));
			}
#line 5480 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 183:
#line 3560 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].text) && !strlen((yyvsp[0].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_ORGANIZATION);
			    }
			}
#line 5491 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 184:
#line 3567 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].text) && !strlen((yyvsp[0].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_CONTACT);
			    }
			}
#line 5502 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 185:
#line 3574 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 5510 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 186:
#line 3578 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((!thisModulePtr->firstRevisionPtr) ||
				(thisModulePtr->firstRevisionPtr->export.date !=
				 thisModulePtr->lastUpdated)) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_MISSING);
				addRevision(thisModulePtr->lastUpdated,
					    smiStrdup(
						"[Revision added by libsmi due to a LAST-UPDATED clause.]"),
					    thisParserPtr);
			    }
			}
#line 5527 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 187:
#line 3592 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-23].id), &objectPtr);

			    thisParserPtr->modulePtr->numModuleIdentities++;

			    objectPtr = setObjectName(objectPtr, (yyvsp[-23].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_MODULEIDENTITY);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectStatus(objectPtr, SMI_STATUS_CURRENT);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setModuleIdentityObject(thisParserPtr->modulePtr,
						    objectPtr);
			    setModuleOrganization(thisParserPtr->modulePtr,
						  (yyvsp[-13].text));
			    setModuleContactInfo(thisParserPtr->modulePtr,
						 (yyvsp[-10].text));
			    setModuleDescription(thisParserPtr->modulePtr,
						 (yyvsp[-7].text), thisParserPtr);
                            if ((yyvsp[-19].subjectCategoriesPtr) != NULL) {
                                setObjectList(objectPtr, (yyvsp[-19].subjectCategoriesPtr)->categories);
                                smiFree((yyvsp[-19].subjectCategoriesPtr));
                            }
			    /* setObjectDescription(objectPtr, $15); */
			    (yyval.err) = 0;
			}
#line 5562 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 188:
#line 3625 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "SUBJECT-CATEGORIES");
                            (yyval.subjectCategoriesPtr) = (yyvsp[-1].subjectCategoriesPtr);
                        }
#line 5572 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 189:
#line 3631 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_MISSING);
                            (yyval.subjectCategoriesPtr) = NULL;
                        }
#line 5582 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 190:
#line 3639 "parser-smi.y" /* yacc.c:1646  */
    {
                            (yyval.subjectCategoriesPtr) = smiMalloc(sizeof(SubjectCategories));
                            (yyval.subjectCategoriesPtr)->categories    = (yyvsp[0].listPtr);
                        }
#line 5591 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 191:
#line 3646 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 5601 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 192:
#line 3652 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
                            if ((yyvsp[-2].listPtr)->ptr == NULL)
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_ALL);
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 5618 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 193:
#line 3667 "parser-smi.y" /* yacc.c:1646  */
    {
                            Object *objectPtr;
                            
                            if (strcmp((yyvsp[0].id), "all"))
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_MISSING_SUBID);
                            else {
                                /*
                                 * This is not a regular object that will be added via
                                 * 'addObject' as subject category dentifier have no
                                 * other meaning in PIBs. They are just used for
                                 * a direct mapping to the actual protocol fields.
                                 */
                                objectPtr = smiMalloc(sizeof(Object));
                                objectPtr->export.name = "all";
                                objectPtr->export.oidlen = 0;
                                objectPtr->export.oid = 0;
                                (yyval.objectPtr) = objectPtr;
                            }
                            smiFree((yyvsp[0].id));
                        }
#line 5643 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 194:
#line 3688 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
                            if (!strcmp((yyvsp[-3].id), "all")) {
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_ALL_WITH_SUBID);
                                (yyval.objectPtr) = NULL;
                            } else {
                                /*
                                 * This is not a regular object that will be added via
                                 * 'addObject' as subject category dentifier have no
                                 * other meaning in PIBs. They are just used for
                                 * a direct mapping to the actual protocol fields.
                                 */
                                objectPtr = smiMalloc(sizeof(Object));
                                objectPtr->export.name = (yyvsp[-3].id);
                                objectPtr->export.oidlen = 1;
                                objectPtr->export.oid = (void *)(yyvsp[-1].unsigned32);
                                (yyval.objectPtr) = objectPtr;
                            }
			}
#line 5668 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 195:
#line 3711 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5676 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 196:
#line 3715 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_TYPE_TAG, (yyvsp[-1].err));
			    }
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5700 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 197:
#line 3735 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5709 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 198:
#line 3740 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5718 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 199:
#line 3745 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5727 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 200:
#line 3750 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    if ((yyvsp[0].typePtr) && (yyvsp[0].typePtr)->export.name) {
				importPtr = findImportByName((yyvsp[0].typePtr)->export.name,
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				}
			    }

			    /* TODO */
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5746 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 201:
#line 3767 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; /* TODO: check range */ }
#line 5752 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 202:
#line 3769 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; /* TODO: check range */ }
#line 5758 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 203:
#line 3777 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.typePtr) = (yyvsp[0].typePtr); }
#line 5764 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 204:
#line 3782 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    if ((yyvsp[0].typePtr) && (yyvsp[0].typePtr)->export.name) {
				importPtr = findImportByName((yyvsp[0].typePtr)->export.name,
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				}
			    }

			    /* TODO */
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 5783 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 205:
#line 3799 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.valuePtr) = (yyvsp[0].valuePtr); }
#line 5789 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 206:
#line 3808 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				&&
				(strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
				 strcmp(thisModulePtr->export.name, "SNMPv2-TC") &&
                                 strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")))
				smiPrintError(thisParserPtr,
					      ERR_INTEGER_IN_SMIV2);

			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
#line 5806 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 207:
#line 3821 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			}
#line 5814 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 208:
#line 3825 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				&&
				(strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
				 strcmp(thisModulePtr->export.name, "SNMPv2-TC") &&
                                 strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")))
				smiPrintError(thisParserPtr,
					      ERR_INTEGER_IN_SMIV2);

			    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
#line 5833 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 209:
#line 3840 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_ENUM;
			}
#line 5841 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 210:
#line 3844 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p;
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    for (p = (yyvsp[0].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			}
#line 5856 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 211:
#line 3855 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }

			    /* TODO: any need to distinguish from INTEGER? */
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
#line 5886 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 212:
#line 3881 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			}
#line 5894 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 213:
#line 3885 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }

			    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
#line 5925 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 214:
#line 3912 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_ENUM;
			}
#line 5933 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 215:
#line 3916 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    List *p;
			    
			    parentPtr = findTypeByModuleAndName(
			        thisParserPtr->modulePtr, (yyvsp[-2].id));
			    if (!parentPtr) {
			        importPtr = findImportByName((yyvsp[-2].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[-2].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				     SMI_BASETYPE_ENUM) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_BITS)) {
				    smiPrintError(thisParserPtr,
						  ERR_ILLEGAL_ENUM_FOR_PARENT_TYPE,
						  (yyvsp[-2].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[-2].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[-2].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    for (p = (yyvsp[0].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			}
#line 5987 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 216:
#line 3967 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    List *p;
			    
                            defaultBasetype = SMI_BASETYPE_ENUM;
                            parentPtr = findTypeByModulenameAndName((yyvsp[-3].id), (yyvsp[-1].id));
			    if (!parentPtr) {
				importPtr =
				    findImportByModulenameAndName((yyvsp[-3].id),
							  (yyvsp[-1].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr =
					findTypeByModulenameAndName((yyvsp[-3].id), (yyvsp[-1].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				     SMI_BASETYPE_ENUM) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_BITS)) {
				    smiPrintError(thisParserPtr,
						  ERR_ILLEGAL_ENUM_FOR_PARENT_TYPE,
						  (yyvsp[-1].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[-1].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    for (p = (yyvsp[0].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			    smiFree((yyvsp[-3].id));
			    smiFree((yyvsp[-1].id));
			}
#line 6037 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 217:
#line 4013 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[-1].id));
			    if (!parentPtr) {
				importPtr = findImportByName((yyvsp[-1].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[-1].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				    SMI_BASETYPE_INTEGER32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_INTEGER64) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED64)) {
				    smiPrintError(thisParserPtr,
					     ERR_ILLEGAL_RANGE_FOR_PARENT_TYPE,
						  (yyvsp[-1].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						       thisParserPtr);
				    defaultBasetype = SMI_BASETYPE_INTEGER32;
				} else {
				    defaultBasetype =
					parentPtr->export.basetype;
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[-1].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[-1].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				defaultBasetype = SMI_BASETYPE_INTEGER32;
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
#line 6096 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 218:
#line 4069 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName((yyvsp[-3].id), (yyvsp[-1].id));
			    if (!parentPtr) {
				importPtr = findImportByModulenameAndName((yyvsp[-3].id),
							  (yyvsp[-1].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					(yyvsp[-3].id), (yyvsp[-1].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				    SMI_BASETYPE_INTEGER32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_INTEGER64) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED64)) {
				    smiPrintError(thisParserPtr,
					     ERR_ILLEGAL_RANGE_FOR_PARENT_TYPE,
						  (yyvsp[-1].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						       thisParserPtr);
				    defaultBasetype = SMI_BASETYPE_INTEGER32;
				} else {
				    defaultBasetype =
					parentPtr->export.basetype;
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[-1].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						   thisParserPtr);
				defaultBasetype = SMI_BASETYPE_INTEGER32;
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    smiFree((yyvsp[-3].id));
			    smiFree((yyvsp[-1].id));
			}
#line 6149 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 219:
#line 4118 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
#line 6158 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 220:
#line 4123 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			}
#line 6166 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 221:
#line 4127 "parser-smi.y" /* yacc.c:1646  */
    {
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
#line 6178 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 222:
#line 4135 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    parentPtr = findTypeByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[-1].id));
			    if (!parentPtr) {
				importPtr = findImportByName((yyvsp[-1].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[-1].id));
				}
			    }
			    if (parentPtr) {
				if (parentPtr->export.basetype !=
				    SMI_BASETYPE_OCTETSTRING) {
				    smiPrintError(thisParserPtr,
					      ERR_ILLEGAL_SIZE_FOR_PARENT_TYPE,
						  (yyvsp[-1].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[-1].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[-1].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
#line 6228 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 223:
#line 4182 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    parentPtr = findTypeByModulenameAndName((yyvsp[-3].id), (yyvsp[-1].id));
			    if (!parentPtr) {
				importPtr = findImportByModulenameAndName((yyvsp[-3].id),
							  (yyvsp[-1].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					(yyvsp[-3].id), (yyvsp[-1].id));
				}
			    }
			    if (parentPtr) {
				if (parentPtr->export.basetype !=
				    SMI_BASETYPE_OCTETSTRING) {
				    smiPrintError(thisParserPtr,
					      ERR_ILLEGAL_SIZE_FOR_PARENT_TYPE,
						  (yyvsp[-1].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[-1].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    smiFree((yyvsp[-3].id));
			    smiFree((yyvsp[-1].id));
			}
#line 6272 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 224:
#line 4222 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_OBJECTIDENTIFIER;
			    (yyval.typePtr) = smiHandle->typeObjectIdentifierPtr;
			}
#line 6281 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 225:
#line 4230 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
			    (yyval.valuePtr)->value.unsigned32 = (yyvsp[0].unsigned32);
			}
#line 6291 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 226:
#line 4236 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[0].integer32);
			}
#line 6301 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 227:
#line 4242 "parser-smi.y" /* yacc.c:1646  */
    {   
                            /* The scanner already checks for the language */
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED64;
			    (yyval.valuePtr)->value.unsigned64 = (yyvsp[0].unsigned64);
			}
#line 6312 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 228:
#line 4249 "parser-smi.y" /* yacc.c:1646  */
    {
                            /* The scanner already checks for the language */
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER64;
			    (yyval.valuePtr)->value.integer64 = (yyvsp[0].integer64);
			}
#line 6323 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 229:
#line 4256 "parser-smi.y" /* yacc.c:1646  */
    {
			    char s[9];
			    int i, len, j;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[0].text));
				(yyval.valuePtr)->value.ptr =
				    smiMalloc((len+7)/8+1);
				for (i = 0; i < len; i += 8) {
				    strncpy(s, &(yyvsp[0].text)[i], 8);
				    for (j = 1; j < 8; j++) {
					if (!s[j]) s[j] = '0';
				    }
				    s[8] = 0;
				    (yyval.valuePtr)->value.ptr[i/8] =
					(unsigned char)strtol(s, 0, 2);
				}
				(yyval.valuePtr)->len = (len+7)/8;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[0].text), NULL, 2);
			    }
			}
#line 6353 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 230:
#line 4282 "parser-smi.y" /* yacc.c:1646  */
    {
			    char s[3];
			    int i, len;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[0].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+1)/2+1);
				for (i = 0; i < len; i += 2) {
				    strncpy(s, &(yyvsp[0].text)[i], 2);
				    if (!s[1]) s[1] = '0';
				    s[2] = 0;
				    (yyval.valuePtr)->value.ptr[i/2] =
					(unsigned char)strtol(s, 0, 16);
				}
				(yyval.valuePtr)->len = (len+1)/2;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[0].text), NULL, 16);
			    }
			}
#line 6380 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 231:
#line 4305 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if ((defaultBasetype != SMI_BASETYPE_ENUM) &&
				(defaultBasetype != SMI_BASETYPE_OBJECTIDENTIFIER)) {
				smiPrintError(thisParserPtr, ERR_DEFVAL_SYNTAX);
				(yyval.valuePtr)->basetype = defaultBasetype;
				if (defaultBasetype == SMI_BASETYPE_ENUM) {
				    (yyval.valuePtr)->len = 1;
				    (yyval.valuePtr)->value.unsigned32 = 0;
				} else {
				    (yyval.valuePtr)->len = 0;
				    (yyval.valuePtr)->value.ptr = NULL;
				}
			    } else {
				(yyval.valuePtr)->basetype = defaultBasetype;
				(yyval.valuePtr)->len = -1;  /* indicates unresolved ptr */
				(yyval.valuePtr)->value.ptr = (unsigned char *) (yyvsp[0].id); /* JS: needs strdup? */
			    }
			}
#line 6404 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 232:
#line 4325 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
			    (yyval.valuePtr)->value.ptr = (unsigned char *) smiStrdup((yyvsp[0].text));
			    (yyval.valuePtr)->len = strlen((yyvsp[0].text));
			}
#line 6415 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 233:
#line 4348 "parser-smi.y" /* yacc.c:1646  */
    {
			    /*
			     * SMIv1 allows something like { 0 0 } !
			     * SMIv2 does not!
			     */
			    /* TODO: make it work correctly for SMIv1 */
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2) {
				smiPrintError(thisParserPtr,
					      ERR_OID_DEFVAL_TOO_LONG_SMIV2);
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_OID_DEFVAL_TOO_LONG_SMIV1);
			    }
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_OBJECTIDENTIFIER;
			    (yyval.valuePtr)->len = 2;
			    (yyval.valuePtr)->value.oid = smiMalloc(2 * sizeof(SmiSubid));
			    (yyval.valuePtr)->value.oid[0] = 0;
			    (yyval.valuePtr)->value.oid[1] = 0;
			}
#line 6440 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 234:
#line 4375 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
#line 6448 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 235:
#line 4379 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    /* TODO: any need to distinguish from INTEGER? */
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;

			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }
			}
#line 6477 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 236:
#line 4404 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
#line 6485 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 237:
#line 4408 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = smiHandle->typeObjectIdentifierPtr;
			}
#line 6493 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 238:
#line 4414 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("IpAddress");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "IpAddress");
			    }
			    
			    importPtr = findImportByName("IpAddress",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				}
			    }
			}
#line 6525 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 239:
#line 4442 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "COUNTER32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }
			    
			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
#line 6555 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 240:
#line 4468 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    List *listPtr, *nextListPtr;
			    
			    smiPrintError(thisParserPtr,
					  ERR_ILLEGAL_RANGE_FOR_COUNTER,
					  "Counter32");
			    for (listPtr = (yyvsp[0].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)listPtr->ptr);
				smiFree(listPtr);
			    }
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }
			    
			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
#line 6596 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 241:
#line 4505 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    (yyval.typePtr) = findTypeByName("Gauge32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
			    }
			    
			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
#line 6626 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 242:
#line 4531 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    parentPtr = findTypeByName("Gauge32");
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			    
			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
#line 6663 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 243:
#line 4564 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    (yyval.typePtr) = smiHandle->typeUnsigned32Ptr;
			    
			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
#line 6691 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 244:
#line 4588 "parser-smi.y" /* yacc.c:1646  */
    {
			    defaultBasetype = SMI_BASETYPE_UNSIGNED32;
			}
#line 6699 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 245:
#line 4592 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeUnsigned32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));

			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
#line 6730 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 246:
#line 4619 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("TimeTicks");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "TimeTicks");
			    }
			    
			    importPtr = findImportByName("TimeTicks",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				}
			    }
			}
#line 6762 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 247:
#line 4647 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("Opaque");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE);
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE);
				}
			    }
			    
			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
#line 6804 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 248:
#line 4685 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByName("Opaque");
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
				(yyval.typePtr) = NULL;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE,
						  "Opaque");
				}
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }

			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
#line 6854 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 249:
#line 4731 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
#line 6884 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 250:
#line 4757 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    List *listPtr, *nextListPtr;
			    
			    smiPrintError(thisParserPtr,
					  ERR_ILLEGAL_RANGE_FOR_COUNTER,
					  "Counter64");
			    for (listPtr = (yyvsp[0].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)listPtr->ptr);
				smiFree(listPtr);
			    }
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
#line 6925 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 251:
#line 4794 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Integer64");
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName("Integer64",
							     thisModulePtr);
				if (!importPtr) {
				    (yyval.typePtr) = findTypeByName("Integer64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Integer64");
				    }
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			}
#line 6955 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 252:
#line 4820 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Integer64");
			    if (! parentPtr) {
				importPtr = findImportByName("Integer64",
							     thisModulePtr);
				if (!importPtr) {
				    parentPtr = findTypeByName("Integer64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Integer64");
				    }
				} else {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Integer64");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			}
#line 6996 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 253:
#line 4857 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Unsigned64");
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName("Unsigned64",
							     thisModulePtr);
				if (!importPtr) {
				    (yyval.typePtr) = findTypeByName("Unsigned64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Unsigned64");
				    }
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			}
#line 7026 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 254:
#line 4883 "parser-smi.y" /* yacc.c:1646  */
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Unsigned64");
			    if (! parentPtr) {
				importPtr = findImportByName("Unsigned64",
							     thisModulePtr);
				if (!importPtr) {
				    parentPtr = findTypeByName("Unsigned64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Unsigned64");
				    }
				} else {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Unsigned64");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[0].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			}
#line 7067 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 255:
#line 4926 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("IpAddress");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "IpAddress");
			    }

			    importPtr = findImportByName("IpAddress",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				}
			    }
			}
#line 7099 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 256:
#line 4954 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }

			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
#line 7129 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 257:
#line 4980 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    (yyval.typePtr) = findTypeByName("Gauge32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
			    }

			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
#line 7159 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 258:
#line 5006 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = smiHandle->typeUnsigned32Ptr;

			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
#line 7187 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 259:
#line 5030 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("TimeTicks");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "TimeTicks");
			    }

			    importPtr = findImportByName("TimeTicks",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				}
			    }
			}
#line 7219 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 260:
#line 5058 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("Opaque");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE,
						  "Opaque");
				}
			    }

			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
#line 7263 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 261:
#line 5098 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisModulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
#line 7293 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 262:
#line 5124 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
			    (yyval.typePtr) = findTypeByName("Integer64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Integer64");
			    }

			    importPtr = findImportByName("Integer64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer64");
				}
			    }
			}
#line 7322 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 263:
#line 5149 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    importPtr = findImportByName("Unsigned64",
							 thisModulePtr);
                            if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) && (!importPtr))
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
			    (yyval.typePtr) = findTypeByName("Unsigned64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Unsigned64");
			    }

			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned64");
				}
			    }
			}
#line 7351 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 264:
#line 5176 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[0].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
#line 7372 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 265:
#line 5193 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[0].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
#line 7393 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 266:
#line 5210 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[0].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree(((NamedNumber *)(listPtr->ptr))->export.name);
				smiFree((NamedNumber *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
#line 7415 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 267:
#line 5228 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = NULL;
			}
#line 7423 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 268:
#line 5242 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = (yyvsp[-1].listPtr); }
#line 7429 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 269:
#line 5252 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 7437 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 270:
#line 5258 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].rangePtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 7447 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 271:
#line 5264 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[0].rangePtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 7463 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 272:
#line 5278 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.rangePtr) = smiMalloc(sizeof(Range));
			    (yyval.rangePtr)->export.minValue = *(yyvsp[0].valuePtr);
			    (yyval.rangePtr)->export.maxValue = *(yyvsp[0].valuePtr);
			    smiFree((yyvsp[0].valuePtr));
			}
#line 7474 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 273:
#line 5285 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.rangePtr) = smiMalloc(sizeof(Range));
			    (yyval.rangePtr)->export.minValue = *(yyvsp[-2].valuePtr);
			    (yyval.rangePtr)->export.maxValue = *(yyvsp[0].valuePtr);
			    smiFree((yyvsp[-2].valuePtr));
			    smiFree((yyvsp[0].valuePtr));
			}
#line 7486 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 274:
#line 5295 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[0].integer32);
			}
#line 7496 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 275:
#line 5301 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
			    (yyval.valuePtr)->value.unsigned32 = (yyvsp[0].unsigned32);
			}
#line 7506 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 276:
#line 5307 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER64;
			    (yyval.valuePtr)->value.integer64 = (yyvsp[0].integer64);
			}
#line 7516 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 277:
#line 5313 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED64;
			    (yyval.valuePtr)->value.unsigned64 = (yyvsp[0].unsigned64);
			}
#line 7526 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 278:
#line 5319 "parser-smi.y" /* yacc.c:1646  */
    {
			    char s[3];
			    int i, len;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[0].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+1)/2+1);
				for (i = 0; i < len; i += 2) {
				    strncpy(s, &(yyvsp[0].text)[i], 2);
				    if (!s[1]) s[1] = '0';
				    s[2] = 0;
				    (yyval.valuePtr)->value.ptr[i/2] =
					(unsigned char)strtol(s, 0, 16);
				}
				(yyval.valuePtr)->len = (len+1)/2;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[0].text), NULL, 16);
			    }
			}
#line 7553 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 279:
#line 5342 "parser-smi.y" /* yacc.c:1646  */
    {
			    char s[9];
			    int i, len, j;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[0].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+7)/8+1);
				for (i = 0; i < len; i += 8) {
				    strncpy(s, &(yyvsp[0].text)[i], 8);
				    for (j = 1; j < 8; j++) {
					if (!s[j]) s[j] = '0';
				    }
				    s[8] = 0;
				    (yyval.valuePtr)->value.ptr[i/8] =
					(unsigned char)strtol(s, 0, 2);
				}
				(yyval.valuePtr)->len = (len+7)/8;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[0].text), NULL, 2);
			    }
			}
#line 7582 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 280:
#line 5369 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 7590 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 281:
#line 5375 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].namedNumberPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 7600 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 282:
#line 5381 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[0].namedNumberPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 7615 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 283:
#line 5394 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_ENUMNAME_32, ERR_ENUMNAME_64);
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (strchr((yyvsp[0].id), '-')) {
				    smiPrintError(thisParserPtr,
					  ERR_NAMEDNUMBER_INCLUDES_HYPHEN,
						  (yyvsp[0].id));
				}
			    }
			}
#line 7632 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 284:
#line 5407 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.namedNumberPtr) = smiMalloc(sizeof(NamedNumber));
			    (yyval.namedNumberPtr)->export.name = (yyvsp[-4].id);
			    (yyval.namedNumberPtr)->export.value = *(yyvsp[-1].valuePtr);
			    smiFree((yyvsp[-1].valuePtr));
			}
#line 7643 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 285:
#line 5416 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].unsigned32) > SMI_BASETYPE_INTEGER32_MAX) {
				smiPrintError(thisParserPtr,
					      ERR_INTEGER32_TOO_LARGE, (yyvsp[0].unsigned32));
			    }
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV1) &&
				((yyvsp[0].unsigned32) == 0)) {
				smiPrintError(thisParserPtr,
					      ERR_ENUM_ZERO);
			    }
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[0].unsigned32);
			}
#line 7662 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 286:
#line 5431 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[0].integer32);
			    /* TODO: non-negative is suggested */
			}
#line 7673 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 287:
#line 5440 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        if (!strcmp((yyvsp[0].id), "current")) {
				    (yyval.status) = SMI_STATUS_CURRENT;
			        } else if (!strcmp((yyvsp[0].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_DEPRECATED;
			        } else if (!strcmp((yyvsp[0].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SMIV2_STATUS,
					          (yyvsp[0].id));
				    if (!strcmp((yyvsp[0].id), "mandatory")
				        || !strcmp((yyvsp[0].id), "optional")) {
				        /* best guess */
				        (yyval.status) = SMI_STATUS_CURRENT;
				    } else {
				        (yyval.status) = SMI_STATUS_UNKNOWN;
				    }
			        }
			    } else if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
			        if (!strcmp((yyvsp[0].id), "mandatory")) {
				    (yyval.status) = SMI_STATUS_MANDATORY;
			        } else if (!strcmp((yyvsp[0].id), "optional")) {
				    (yyval.status) = SMI_STATUS_OPTIONAL;
			        } else if (!strcmp((yyvsp[0].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else if (!strcmp((yyvsp[0].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SMIV1_STATUS,
					          (yyvsp[0].id));
				    if (!strcmp((yyvsp[0].id), "current")) {
				        /* best guess */
				        (yyval.status) = SMI_STATUS_MANDATORY; 
				    } else {
				        (yyval.status) = SMI_STATUS_UNKNOWN;
				    }
			        }
			    } else { /* it is SPPI */
			        if (!strcmp((yyvsp[0].id), "current")) {
				    (yyval.status) = SMI_STATUS_CURRENT;
			        } else if (!strcmp((yyvsp[0].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else if (!strcmp((yyvsp[0].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
                                } else {
                                    smiPrintError(thisParserPtr,
                                                  ERR_INVALID_SPPI_STATUS, (yyvsp[0].id));
                                    (yyval.status) = SMI_STATUS_UNKNOWN;
                                }
                            }
			    smiFree((yyvsp[0].id));
			}
#line 7734 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 288:
#line 5499 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (!strcmp((yyvsp[0].id), "current")) {
				(yyval.status) = SMI_STATUS_CURRENT;
			    } else if (!strcmp((yyvsp[0].id), "obsolete")) {
				(yyval.status) = SMI_STATUS_OBSOLETE;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_INVALID_CAPABILITIES_STATUS,
					      (yyvsp[0].id));
				(yyval.status) = SMI_STATUS_UNKNOWN;
			    }
			    smiFree((yyvsp[0].id));
			}
#line 7752 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 289:
#line 5515 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = (yyvsp[0].text);
			    
			    if ((yyvsp[0].text) && !strlen((yyvsp[0].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_FORMAT);
			    }
			}
#line 7765 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 290:
#line 5524 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = NULL;
			}
#line 7773 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 291:
#line 5530 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = (yyvsp[0].text);
			    
			    if ((yyvsp[0].text) && !strlen((yyvsp[0].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_UNITS);
			    }
			}
#line 7786 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 292:
#line 5539 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = NULL;
			}
#line 7794 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 293:
#line 5545 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (!strcmp((yyvsp[0].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
				} else if (!strcmp((yyvsp[0].id),
						   "accessible-for-notify")) {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
				} else if (!strcmp((yyvsp[0].id), "read-only")) {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				} else if (!strcmp((yyvsp[0].id), "read-write")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else if (!strcmp((yyvsp[0].id), "read-create")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				    thisParserPtr->flags |= FLAG_CREATABLE;
				    /* TODO:remember it's really read-create */
				} else if (!strcmp((yyvsp[0].id), "write-only")) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_WRITE_ONLY);
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_INVALID_SMIV2_ACCESS,
						  (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				}
			    } else if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
				if (!strcmp((yyvsp[0].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
				} else if (!strcmp((yyvsp[0].id), "read-only")) {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				} else if (!strcmp((yyvsp[0].id), "read-write")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else if (!strcmp((yyvsp[0].id), "write-only")) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV1_WRITE_ONLY);
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_INVALID_SMIV1_ACCESS,
						  (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				}
			    } else {
			        if (!strcmp((yyvsp[0].id), "install")) {
				    (yyval.access) = SMI_ACCESS_INSTALL;
			        } else if (!strcmp((yyvsp[0].id), "install-notify")) {
				    (yyval.access) = SMI_ACCESS_INSTALL_NOTIFY;
			        } else if (!strcmp((yyvsp[0].id), "notify")) {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
			        } else if (!strcmp((yyvsp[0].id), "report-only")) {
				    (yyval.access) = SMI_ACCESS_REPORT_ONLY;
			        } else if (!strcmp((yyvsp[0].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
                                } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SPPI_ACCESS,
					          (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
			        }
                            }
			    smiFree((yyvsp[0].id));
			}
#line 7862 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 294:
#line 5611 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-INDEX");
                        }
#line 7871 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 295:
#line 5616 "parser-smi.y" /* yacc.c:1646  */
    {
                            List *p = smiMalloc(sizeof(List));
                            
                            p->ptr       = (yyvsp[-1].objectPtr);
                            p->nextPtr   = NULL;
                            
			    (yyval.index).indexkind = SMI_INDEX_INDEX;
			    (yyval.index).implied   = impliedFlag;
			    (yyval.index).listPtr   = p;
			    (yyval.index).rowPtr    = NULL;
                            indexFlag    = INDEXFLAG_PIBINDEX;
			}
#line 7888 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 296:
#line 5631 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.index).indexkind    = SMI_INDEX_AUGMENT;
			    (yyval.index).implied      = 0;
			    (yyval.index).listPtr      = NULL;
			    (yyval.index).rowPtr       = (yyvsp[-1].objectPtr);
                            indexFlag       = INDEXFLAG_AUGMENTS;
			}
#line 7900 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 297:
#line 5639 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "EXTENDS");
                        }
#line 7909 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 298:
#line 5644 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.index).indexkind    = SMI_INDEX_SPARSE;
			    (yyval.index).implied      = 0;
			    (yyval.index).listPtr      = NULL;
			    (yyval.index).rowPtr       = (yyvsp[-1].objectPtr);
                            indexFlag       = INDEXFLAG_EXTENDS;
			}
#line 7921 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 299:
#line 5652 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.index).indexkind = SMI_INDEX_UNKNOWN;
			}
#line 7929 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 300:
#line 5658 "parser-smi.y" /* yacc.c:1646  */
    {
                            /* 
                             * To avoid ambiguity caused by merging
                             * the SMI and SPPI parser we use a flag.
                             */
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) {
                                /*
                                 * Only INDEX or AUGMENTS are allowed for SMI
                                 */
                                if (indexFlag != INDEXFLAG_NONE)
                                    smiPrintError(thisParserPtr, ERR_INDEX_AND_AUGMENTS_USED);
                            } else {
                                /*
                                 * INDEX may only be used if PIB_INDEX was used
                                 */
                                if (indexFlag != INDEXFLAG_PIBINDEX)
                                    smiPrintError(thisParserPtr, ERR_INDEX_WITHOUT_PIB_INDEX);
                            }
                            
			    /*
			     * Use a global variable to fetch and remember
			     * whether we have seen an IMPLIED keyword.
			     */
			    impliedFlag = 0;
			}
#line 7959 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 301:
#line 5684 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.index).indexkind = SMI_INDEX_INDEX;
			    (yyval.index).implied   = impliedFlag;
			    (yyval.index).listPtr   = (yyvsp[-1].listPtr);
			    (yyval.index).rowPtr    = NULL;
                        }
#line 7970 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 302:
#line 5691 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.index).indexkind = SMI_INDEX_UNKNOWN;
			}
#line 7978 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 303:
#line 5697 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 7988 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 304:
#line 5704 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 8003 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 305:
#line 5717 "parser-smi.y" /* yacc.c:1646  */
    {
			    impliedFlag = 1;
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8012 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 306:
#line 5722 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8020 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 307:
#line 5732 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8028 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 308:
#line 5738 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8036 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 309:
#line 5744 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
					      ERR_NOTIFICATION_VARIATION_DEFVAL);
			    }
			    (yyval.valuePtr) = (yyvsp[-1].valuePtr);
			    if ((defaultBasetype == SMI_BASETYPE_BITS) &&
				((yyval.valuePtr)->basetype != SMI_BASETYPE_BITS)) {
				smiPrintError(thisParserPtr,
					      ERR_DEFVAL_SYNTAX);
				if ((yyval.valuePtr)->basetype == SMI_BASETYPE_OCTETSTRING) {
				    smiFree((yyval.valuePtr)->value.ptr);
				}
				smiFree((yyval.valuePtr));
				(yyval.valuePtr) = NULL;
			    }
			}
#line 8059 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 310:
#line 5763 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.valuePtr) = NULL; }
#line 8065 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 311:
#line 5768 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.valuePtr) = (yyvsp[0].valuePtr); }
#line 8071 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 312:
#line 5770 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_BITS;
			    (yyval.valuePtr)->value.ptr = (void *)(yyvsp[-1].listPtr);
			}
#line 8081 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 313:
#line 5778 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = (yyvsp[0].listPtr); }
#line 8087 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 314:
#line 5780 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.listPtr) = NULL; }
#line 8093 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 315:
#line 5784 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].id);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 8103 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 316:
#line 5790 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].id);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 8118 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 317:
#line 5803 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8126 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 318:
#line 5809 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8134 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 319:
#line 5815 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.text) = (yyvsp[0].text);

			    if ((yyvsp[0].text) && !strlen((yyvsp[0].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_REFERENCE);
			    }
			}
#line 8147 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 320:
#line 5824 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.text) = NULL; }
#line 8153 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 321:
#line 5828 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8159 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 322:
#line 5830 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8165 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 323:
#line 5834 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8171 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 324:
#line 5836 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8177 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 325:
#line 5840 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstRevisionLine = thisParserPtr->line;

			    if (thisParserPtr->modulePtr->lastRevisionPtr &&
				((yyvsp[0].date) >= thisParserPtr->modulePtr->lastRevisionPtr->export.date)) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_NOT_DESCENDING);
			    }

			    if ((yyvsp[0].date) > thisParserPtr->modulePtr->lastUpdated) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_AFTER_LAST_UPDATE);
			    }
			}
#line 8196 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 326:
#line 5855 "parser-smi.y" /* yacc.c:1646  */
    {
			    Revision *revisionPtr;

			    checkDescr(thisParserPtr, (yyvsp[0].text));

			    revisionPtr = addRevision((yyvsp[-3].date), (yyvsp[0].text), thisParserPtr);
			    if (revisionPtr) {
				setRevisionLine(revisionPtr,
						thisParserPtr->firstRevisionLine,
						thisParserPtr);
			    }
			    (yyval.err) = revisionPtr ? 0 : -1;
			}
#line 8214 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 327:
#line 5871 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 8222 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 328:
#line 5875 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = NULL;
			}
#line 8230 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 329:
#line 5881 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 8238 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 330:
#line 5887 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 8248 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 331:
#line 5893 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 8263 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 332:
#line 5906 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			    if ((thisParserPtr->currentDecl == SMI_DECL_OBJECTGROUP) &&
				(yyval.objectPtr)->modulePtr != thisParserPtr->modulePtr) {
                                smiPrintError(thisParserPtr,
					      ERR_COMPLIANCE_MEMBER_NOT_LOCAL,
					      (yyval.objectPtr)->export.name);
			    }
			}
#line 8277 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 333:
#line 5918 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 8285 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 334:
#line 5924 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 8295 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 335:
#line 5930 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 8310 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 336:
#line 5943 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			    if ((yyval.objectPtr)->modulePtr != thisParserPtr->modulePtr) {
                                smiPrintError(thisParserPtr,
					      ERR_COMPLIANCE_MEMBER_NOT_LOCAL,
					      (yyval.objectPtr)->export.name);
			    }
			}
#line 8323 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 337:
#line 5954 "parser-smi.y" /* yacc.c:1646  */
    {
			    int len;
			    (yyval.text) = smiStrdup((yyvsp[0].text));
			    len = strlen((yyval.text));
			    while (len > 0 && (yyval.text)[len-1] == '\n') {
				(yyval.text)[--len] = 0;
			    }
			}
#line 8336 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 338:
#line 5965 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.date) = checkDate(thisParserPtr, (yyvsp[0].text));
			}
#line 8344 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 339:
#line 5970 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->parentNodePtr = smiHandle->rootNodePtr;
			}
#line 8352 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 340:
#line 5974 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			    if ((yyval.objectPtr)) {
				thisParserPtr->parentNodePtr = (yyvsp[0].objectPtr)->nodePtr;
			    } else {
				thisParserPtr->parentNodePtr = NULL;
			    }
			}
#line 8365 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 341:
#line 5986 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8373 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 342:
#line 5991 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			}
#line 8381 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 343:
#line 5999 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    Import *importPtr;
			    
			    if (thisParserPtr->parentNodePtr != smiHandle->rootNodePtr) {
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_NOT_FIRST, (yyvsp[0].id));
			    }
			    objectPtr = findObjectByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[0].id));
			    if (objectPtr) {
				(yyval.objectPtr) = objectPtr;
				smiFree((yyvsp[0].id));
			    } else {
				importPtr = findImportByName((yyvsp[0].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /*
				     * If we are in a MODULE-COMPLIANCE
				     * statement with a given MODULE...
				     */
				    if (thisParserPtr->complianceModulePtr) {
					objectPtr =
					    findObjectByModuleAndName(
						thisParserPtr->complianceModulePtr, (yyvsp[0].id));
					if (objectPtr) {
					    importPtr = addImport(
						(yyvsp[0].id),
						thisParserPtr);
					    setImportModulename(importPtr,
								thisParserPtr->complianceModulePtr->export.name);
					    addImportFlags(importPtr,
							   FLAG_INCOMPLIANCE);
					    importPtr->use++;
					} else {
					    objectPtr = addObject((yyvsp[0].id),
								  thisParserPtr->pendingNodePtr, 0,
								  FLAG_INCOMPLETE,
								  thisParserPtr);
					    smiPrintError(thisParserPtr,
							  ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[0].id),
							  thisParserPtr->complianceModulePtr->export.name);
					}
				    } else if (thisParserPtr->capabilitiesModulePtr) {
					objectPtr =
					    findObjectByModuleAndName(
						thisParserPtr->capabilitiesModulePtr, (yyvsp[0].id));
					if (objectPtr) {
					    importPtr = addImport(
						(yyvsp[0].id),
						thisParserPtr);
					    setImportModulename(importPtr,
								thisParserPtr->capabilitiesModulePtr->
								export.name);
					    addImportFlags(importPtr,
							   FLAG_INCOMPLIANCE);
					    importPtr->use++;
					} else {
					    objectPtr = addObject((yyvsp[0].id),
								  thisParserPtr->pendingNodePtr, 0,
								  FLAG_INCOMPLETE,
								  thisParserPtr);
					    smiPrintError(thisParserPtr,
							  ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[0].id),
							  thisParserPtr->capabilitiesModulePtr->export.name);
					}
				    } else {
					/* 
					 * forward referenced node.
					 * create it,
					 * marked with FLAG_INCOMPLETE.
					 */
					objectPtr = addObject((yyvsp[0].id),
							      thisParserPtr->pendingNodePtr,
							      0,
							      FLAG_INCOMPLETE,
							      thisParserPtr);
				    }
				    (yyval.objectPtr) = objectPtr;
				} else {
				    /*
				     * imported object.
				     */
				    importPtr->use++;
				    (yyval.objectPtr) = findObjectByModulenameAndName(
					importPtr->export.module, (yyvsp[0].id));
				    smiFree((yyvsp[0].id));
				}
			    }
			    if ((yyval.objectPtr))
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			}
#line 8479 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 344:
#line 6093 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    Import *importPtr;
			    char *md;
			    
			    if (thisParserPtr->parentNodePtr != smiHandle->rootNodePtr) {
				md = smiMalloc(sizeof(char) *
					       (strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 2));
				sprintf(md, "%s.%s", (yyvsp[-2].id), (yyvsp[0].id));
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_NOT_FIRST, md);
				smiFree(md);
			    } else {
				objectPtr = findObjectByModulenameAndName(
				    (yyvsp[-2].id), (yyvsp[0].id));
				if (objectPtr) {
				    (yyval.objectPtr) = objectPtr;
				    smiFree((yyvsp[-2].id));
				    smiFree((yyvsp[0].id));
				} else {
				    importPtr = findImportByModulenameAndName(
					(yyvsp[-2].id), (yyvsp[0].id), thisModulePtr);
				    if (!importPtr ||
					(importPtr->kind == KIND_NOTFOUND)) {
					/* TODO: check: $1 == thisModule ? */
					/*
					 * If we are in a MODULE-COMPLIANCE
					 * statement with a given MODULE...
					 */
					if (thisParserPtr->complianceModulePtr) {
					    objectPtr =
						findObjectByModuleAndName(
						    thisParserPtr->complianceModulePtr, (yyvsp[-2].id));
					    if (objectPtr) {
						importPtr = addImport(
						    (yyvsp[-2].id),
						    thisParserPtr);
						setImportModulename(importPtr,
						    thisParserPtr->complianceModulePtr->export.name);
						addImportFlags(importPtr,
							       FLAG_INCOMPLIANCE);
						importPtr->use++;
					    } else {
						objectPtr = addObject((yyvsp[-2].id),
						    thisParserPtr->pendingNodePtr, 0,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
						smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[-2].id),
					     thisParserPtr->complianceModulePtr->export.name);
					    }
					} else if (thisParserPtr->capabilitiesModulePtr) {
					    objectPtr =
						findObjectByModuleAndName(
						    thisParserPtr->capabilitiesModulePtr, (yyvsp[-2].id));
					    if (objectPtr) {
						importPtr = addImport(
						    (yyvsp[-2].id),
						    thisParserPtr);
						setImportModulename(importPtr,
						        thisParserPtr->capabilitiesModulePtr->
								  export.name);
						addImportFlags(importPtr,
							       FLAG_INCOMPLIANCE);
						importPtr->use++;
					    } else {
						objectPtr = addObject((yyvsp[-2].id),
						    thisParserPtr->pendingNodePtr, 0,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
						smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[-2].id),
					   thisParserPtr->capabilitiesModulePtr->export.name);
					    }
					} else {
					    /* 
					     * forward referenced node.
					     * create it,
					     * marked with FLAG_INCOMPLETE.
					     */
					    objectPtr = addObject((yyvsp[0].id),
							    thisParserPtr->pendingNodePtr,
							      0,
							      FLAG_INCOMPLETE,
							      thisParserPtr);
					    smiFree((yyvsp[-2].id));
					}
					(yyval.objectPtr) = objectPtr;
				    } else {
					/*
					 * imported object.
					 */
					importPtr->use++;
					(yyval.objectPtr) = findObjectByModulenameAndName(
					    importPtr->export.module, (yyvsp[0].id));
					smiFree((yyvsp[-2].id));
					smiFree((yyvsp[0].id));
				    }
				}
				if ((yyval.objectPtr))
				    thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			}
#line 8587 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 345:
#line 6197 "parser-smi.y" /* yacc.c:1646  */
    {
			    Node *nodePtr;
			    Object *objectPtr;

			    nodePtr = findNodeByParentAndSubid(thisParserPtr->parentNodePtr,
							       (yyvsp[0].unsigned32));
			    if (nodePtr && nodePtr->lastObjectPtr &&
	       		(nodePtr->lastObjectPtr->modulePtr == thisModulePtr)) {
				/*
				 * hopefully, the last defined Object for
				 * this Node is the one we expect.
				 */
				(yyval.objectPtr) = nodePtr->lastObjectPtr;
			    } else {
				objectPtr = addObject(NULL,
						      thisParserPtr->parentNodePtr,
						      (yyvsp[0].unsigned32),
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				(yyval.objectPtr) = objectPtr;
			    }
			    thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			}
#line 8615 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 346:
#line 6221 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr = NULL;
			    Object *oldObjectPtr = NULL;
			    Node *oldNodePtr = NULL;
			    
			    /* TODO: search in local module and
			     *       in imported modules
			     */

			    oldNodePtr = findNodeByParentAndSubid(
				thisParserPtr->parentNodePtr, (yyvsp[-1].unsigned32));
			    oldObjectPtr = findObjectByModuleAndName(
                                thisParserPtr->modulePtr, (yyvsp[-3].id));

			    if (oldObjectPtr &&
				((oldObjectPtr->nodePtr->subid != (yyvsp[-1].unsigned32)) ||
				 (oldObjectPtr->nodePtr->parentPtr != thisParserPtr->parentNodePtr))) {
				smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_OID_CHANGED,
					      (yyvsp[-3].id));
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldObjectPtr->line,
						    oldObjectPtr->export.name);
				objectPtr = addObject((yyvsp[-3].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else if (oldNodePtr &&
				       oldNodePtr->lastObjectPtr &&
				       oldNodePtr->lastObjectPtr->export.name &&
				       strcmp(oldNodePtr->lastObjectPtr->export.name, (yyvsp[-3].id))) {
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_CHANGED,
					      (yyvsp[-3].id), oldNodePtr->lastObjectPtr->export.name);
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldNodePtr->lastObjectPtr->line,
						    oldNodePtr->lastObjectPtr->export.name);
				objectPtr = addObject((yyvsp[-3].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else {
				objectPtr = addObject((yyvsp[-3].id), thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0,
						      thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			}
#line 8679 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 347:
#line 6281 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr = NULL;
			    Object *oldObjectPtr = NULL;
			    Node *oldNodePtr = NULL;
			    char *md;

			    md = smiMalloc(sizeof(char) *
					   (strlen((yyvsp[-5].id)) + strlen((yyvsp[-3].id)) + 2));
			    sprintf(md, "%s.%s", (yyvsp[-5].id), (yyvsp[-3].id));

			    oldNodePtr = findNodeByParentAndSubid(
				thisParserPtr->parentNodePtr, (yyvsp[-1].unsigned32));
			    oldObjectPtr = findObjectByModulenameAndName(
                                (yyvsp[-5].id), (yyvsp[-3].id));

			    if (oldObjectPtr &&
				((oldObjectPtr->nodePtr->subid != (yyvsp[-1].unsigned32)) ||
				 (oldObjectPtr->nodePtr->parentPtr != thisParserPtr->parentNodePtr))) {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_OID_CHANGED,
					      (yyvsp[-3].id));
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldObjectPtr->line,
						    oldObjectPtr->export.name);
				objectPtr = addObject((yyvsp[-3].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else if (oldNodePtr &&
				       oldNodePtr->lastObjectPtr &&
				       strcmp(oldNodePtr->lastObjectPtr->export.name, (yyvsp[-3].id))) {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_CHANGED,
					      (yyvsp[-3].id), oldNodePtr->lastObjectPtr->export.name);
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldNodePtr->lastObjectPtr->line,
						    oldNodePtr->lastObjectPtr->export.name);
				objectPtr = addObject((yyvsp[-3].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				objectPtr = addObject((yyvsp[-3].id), thisParserPtr->parentNodePtr,
						      (yyvsp[-1].unsigned32), 0,
						      thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			    smiFree(md);
			}
#line 8750 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 348:
#line 6350 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.text) = NULL; }
#line 8756 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 349:
#line 6354 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8762 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 350:
#line 6356 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8768 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 351:
#line 6360 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8774 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 352:
#line 6362 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 8780 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 353:
#line 6366 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTGROUP;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 8794 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 354:
#line 6376 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("OBJECT-GROUP",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "OBJECT-GROUP", "SNMPv2-CONF");
			    }
			}
#line 8815 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 355:
#line 6395 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 8823 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 356:
#line 6400 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-14].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-14].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTGROUP);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[-8].status));
			    setObjectDescription(objectPtr, (yyvsp[-6].text), thisParserPtr);
			    if ((yyvsp[-4].text)) {
				setObjectReference(objectPtr, (yyvsp[-4].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[-10].listPtr));
			    (yyval.err) = 0;
			}
#line 8851 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 357:
#line 6426 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_NOTIFICATIONGROUP;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 8865 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 358:
#line 6436 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "NOTIFICATION-GROUP");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("NOTIFICATION-GROUP",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "NOTIFICATION-GROUP",
					      "SNMPv2-CONF");
			    }
			}
#line 8889 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 359:
#line 6458 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 8897 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 360:
#line 6463 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-14].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[-14].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_NOTIFICATIONGROUP);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[-8].status));
			    setObjectDescription(objectPtr, (yyvsp[-6].text), thisParserPtr);
			    if ((yyvsp[-4].text)) {
				setObjectReference(objectPtr, (yyvsp[-4].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[-10].listPtr));
			    (yyval.err) = 0;
			}
#line 8926 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 361:
#line 6490 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULECOMPLIANCE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 8940 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 362:
#line 6500 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;
			    importPtr = findImportByName("MODULE-COMPLIANCE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "MODULE-COMPLIANCE",
					      "SNMPv2-CONF");
			    }
			}
#line 8961 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 363:
#line 6518 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 8969 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 364:
#line 6524 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    Option *optionPtr;
			    Refinement *refinementPtr;
			    List *listPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-14].id), &objectPtr);

			    setObjectName(objectPtr, (yyvsp[-14].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_MODULECOMPLIANCE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[-9].status));
			    setObjectDescription(objectPtr, (yyvsp[-7].text), thisParserPtr);
			    if ((yyvsp[-5].text)) {
				setObjectReference(objectPtr, (yyvsp[-5].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[-4].compl).mandatorylistPtr);
			    objectPtr->optionlistPtr = (yyvsp[-4].compl).optionlistPtr;
			    objectPtr->refinementlistPtr =
				                          (yyvsp[-4].compl).refinementlistPtr;

			    if ((yyvsp[-4].compl).optionlistPtr) {
				for (listPtr = (yyvsp[-4].compl).optionlistPtr;
				     listPtr;
				     listPtr = listPtr->nextPtr) {
				    optionPtr = ((Option *)(listPtr->ptr));
				    optionPtr->compliancePtr = objectPtr;
				}
			    }

			    /*
			     * Dirty: Fake the types' names in the
			     * refinement list:
			     * ``<compliancename>+<objecttypename>+type''
			     * ``<compliancename>+<objecttypename>+writetype''
			     */
			    if ((yyvsp[-4].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[-4].compl).refinementlistPtr;
				     listPtr;
				     listPtr = listPtr->nextPtr) {
				    refinementPtr =
					((Refinement *)(listPtr->ptr));
				    refinementPtr->compliancePtr = objectPtr;
				}
			    }

			    (yyval.err) = 0;
			}
#line 9030 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 365:
#line 6583 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl) = (yyvsp[0].compl);
			}
#line 9038 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 366:
#line 6589 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl) = (yyvsp[0].compl);
			}
#line 9046 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 367:
#line 6593 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *listPtr;
			    
			    /* concatenate lists in $1 and $2 */
			    if ((yyvsp[-1].compl).mandatorylistPtr) {
				for (listPtr = (yyvsp[-1].compl).mandatorylistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[0].compl).mandatorylistPtr;
				(yyval.compl).mandatorylistPtr = (yyvsp[-1].compl).mandatorylistPtr;
			    } else {
				(yyval.compl).mandatorylistPtr = (yyvsp[0].compl).mandatorylistPtr;
			    }
			    if ((yyvsp[-1].compl).optionlistPtr) {
				for (listPtr = (yyvsp[-1].compl).optionlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[0].compl).optionlistPtr;
				(yyval.compl).optionlistPtr = (yyvsp[-1].compl).optionlistPtr;
			    } else {
				(yyval.compl).optionlistPtr = (yyvsp[0].compl).optionlistPtr;
			    }
			    if ((yyvsp[-1].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[-1].compl).refinementlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[0].compl).refinementlistPtr;
				(yyval.compl).refinementlistPtr = (yyvsp[-1].compl).refinementlistPtr;
			    } else {
				(yyval.compl).refinementlistPtr = (yyvsp[0].compl).refinementlistPtr;
			    }
			}
#line 9083 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 368:
#line 6628 "parser-smi.y" /* yacc.c:1646  */
    {
			    /*
			     * Remember the module. SMIv2 is broken by
			     * design to allow subsequent clauses to
			     * refer identifiers that are not
			     * imported.  Although, SMIv2 does not
			     * require, we will fake it by inserting
			     * appropriate imports.
			     */
			    if ((yyvsp[0].modulePtr) == thisModulePtr)
				thisParserPtr->complianceModulePtr = NULL;
			    else
				thisParserPtr->complianceModulePtr = (yyvsp[0].modulePtr);
			}
#line 9102 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 369:
#line 6644 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl).mandatorylistPtr = (yyvsp[-1].listPtr);
			    (yyval.compl).optionlistPtr = (yyvsp[0].compl).optionlistPtr;
			    (yyval.compl).refinementlistPtr = (yyvsp[0].compl).refinementlistPtr;
			    if (thisParserPtr->complianceModulePtr) {
				checkImports(thisParserPtr->complianceModulePtr,
					     thisParserPtr);
				thisParserPtr->complianceModulePtr = NULL;
			    }
			}
#line 9117 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 370:
#line 6657 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[-1].id));
			    /* TODO: handle objectIdentifier */
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[-1].id), thisParserPtr);
			    }
			    smiFree((yyvsp[-1].id));
			}
#line 9130 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 371:
#line 6666 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[0].id));
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[0].id), thisParserPtr);
			    }
			    smiFree((yyvsp[0].id));
			}
#line 9142 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 372:
#line 6675 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.modulePtr) = thisModulePtr;
			}
#line 9150 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 373:
#line 6681 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = (yyvsp[-1].listPtr);
			}
#line 9158 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 374:
#line 6685 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = NULL;
			}
#line 9166 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 375:
#line 6691 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
#line 9176 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 376:
#line 6697 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
			}
#line 9191 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 377:
#line 6710 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* TODO: check that objectIdentifier is
			       found, is defined in thisParserPtr->complianceModulePtr,
			       and is a group node. */
			    Import *importPtr;

			    (yyval.objectPtr) = (yyvsp[0].objectPtr);
			    if (thisParserPtr->complianceModulePtr) {
				(yyval.objectPtr) = findObjectByModuleAndName(
				                           thisParserPtr->complianceModulePtr,
							   (yyvsp[0].objectPtr)->export.name);
			    }
			    if (thisParserPtr->complianceModulePtr && (yyvsp[0].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
				    thisParserPtr->complianceModulePtr->export.name,
				    (yyvsp[0].objectPtr)->export.name, thisModulePtr);
				if (importPtr)
				    importPtr->use++;
			    }
			}
#line 9216 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 378:
#line 6733 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = (yyvsp[0].compl).optionlistPtr;
			    (yyval.compl).refinementlistPtr = (yyvsp[0].compl).refinementlistPtr;
			}
#line 9226 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 379:
#line 6739 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = NULL;
			    (yyval.compl).refinementlistPtr = NULL;
			}
#line 9236 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 380:
#line 6747 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl) = (yyvsp[0].compl);
			}
#line 9244 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 381:
#line 6751 "parser-smi.y" /* yacc.c:1646  */
    {
			    List *listPtr;
			    int stop;
			    
			    (yyval.compl).mandatorylistPtr = NULL;

			    /* check for duplicates in optionlist */
			    stop = 0;
			    if ((yyvsp[0].compl).optionlistPtr) {
				for (listPtr = (yyvsp[-1].compl).optionlistPtr; listPtr;
				     listPtr = listPtr->nextPtr) {
				    if (((Option *)listPtr->ptr)->objectPtr ==
					((Option *)(yyvsp[0].compl).optionlistPtr->ptr)->objectPtr) {
					smiPrintError(thisParserPtr,
						      ERR_OPTIONALGROUP_ALREADY_EXISTS,
						      ((Option *)(yyvsp[0].compl).optionlistPtr->ptr)->objectPtr->export.name);
					stop = 1;
					(yyval.compl).optionlistPtr = (yyvsp[-1].compl).optionlistPtr;
				    }
				}
			    }
	
                            /* concatenate optionlists */
			    if ((yyvsp[-1].compl).optionlistPtr) {
				for (listPtr = (yyvsp[-1].compl).optionlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				if (!stop) {
				    listPtr->nextPtr = (yyvsp[0].compl).optionlistPtr;
				}
				(yyval.compl).optionlistPtr = (yyvsp[-1].compl).optionlistPtr;
			    } else {
				(yyval.compl).optionlistPtr = (yyvsp[0].compl).optionlistPtr;
			    }

			    /* check for duplicates in refinementlist */
			    stop = 0;
			    if ((yyvsp[0].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[-1].compl).refinementlistPtr; listPtr;
				     listPtr = listPtr->nextPtr) {
				    if (((Refinement *)listPtr->ptr)->objectPtr ==
					((Refinement *)(yyvsp[0].compl).refinementlistPtr->ptr)->objectPtr) {
					smiPrintError(thisParserPtr,
						      ERR_REFINEMENT_ALREADY_EXISTS,
						      ((Refinement *)(yyvsp[0].compl).refinementlistPtr->ptr)->objectPtr->export.name);
					stop = 1;
					(yyval.compl).refinementlistPtr = (yyvsp[-1].compl).refinementlistPtr;
				    }
				}
			    }
			    
                            /* concatenate refinementlists */
			    if ((yyvsp[-1].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[-1].compl).refinementlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				if (!stop) {
				    listPtr->nextPtr = (yyvsp[0].compl).refinementlistPtr;
				}
				(yyval.compl).refinementlistPtr = (yyvsp[-1].compl).refinementlistPtr;
			    } else {
				(yyval.compl).refinementlistPtr = (yyvsp[0].compl).refinementlistPtr;
			    }
			}
#line 9313 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 382:
#line 6818 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = (yyvsp[0].listPtr);
			    (yyval.compl).refinementlistPtr = NULL;
			}
#line 9323 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 383:
#line 6824 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = NULL;
			    (yyval.compl).refinementlistPtr = (yyvsp[0].listPtr);
			}
#line 9333 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 384:
#line 6832 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstNestedStatementLine = thisParserPtr->line;
			}
#line 9341 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 385:
#line 6837 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
			    
			    if (thisParserPtr->complianceModulePtr && (yyvsp[-2].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
						    thisParserPtr->complianceModulePtr->export.name,
						    (yyvsp[-2].objectPtr)->export.name,
						    thisModulePtr);
				if (importPtr)
				    importPtr->use++;
			    }

			    checkDescr(thisParserPtr, (yyvsp[0].text));
			    
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->nextPtr = NULL;
			    (yyval.listPtr)->ptr = smiMalloc(sizeof(Option));
			    ((Option *)((yyval.listPtr)->ptr))->line = thisParserPtr->firstNestedStatementLine;
			    ((Option *)((yyval.listPtr)->ptr))->objectPtr = (yyvsp[-2].objectPtr);
			    if (! (thisModulePtr->flags & SMI_FLAG_NODESCR)) {
				((Option *)((yyval.listPtr)->ptr))->export.description = (yyvsp[0].text);
			    } else {
				smiFree((yyvsp[0].text));
			    }
			}
#line 9371 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 386:
#line 6865 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstNestedStatementLine = thisParserPtr->line;
			    variationkind = SMI_NODEKIND_UNKNOWN;
			}
#line 9380 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 387:
#line 6874 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;

			    if (thisParserPtr->complianceModulePtr && (yyvsp[-5].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
						    thisParserPtr->complianceModulePtr->export.name,
						    (yyvsp[-5].objectPtr)->export.name,
						    thisModulePtr);
				if (importPtr) 
				    importPtr->use++;
			    }

			    checkDescr(thisParserPtr, (yyvsp[0].text));
			    
			    thisParserPtr->flags &= ~FLAG_CREATABLE;
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->nextPtr = NULL;
			    (yyval.listPtr)->ptr = smiMalloc(sizeof(Refinement));
			    ((Refinement *)((yyval.listPtr)->ptr))->line =
				thisParserPtr->firstNestedStatementLine;
			    ((Refinement *)((yyval.listPtr)->ptr))->objectPtr = (yyvsp[-5].objectPtr);
			    ((Refinement *)((yyval.listPtr)->ptr))->typePtr = (yyvsp[-4].typePtr);
			    if ((yyvsp[-4].typePtr)) {
				(yyvsp[-4].typePtr)->parentPtr = (yyvsp[-5].objectPtr)->typePtr;
			    }
			    ((Refinement *)((yyval.listPtr)->ptr))->writetypePtr = (yyvsp[-3].typePtr);
			    if ((yyvsp[-3].typePtr)) {
				(yyvsp[-3].typePtr)->parentPtr = (yyvsp[-5].objectPtr)->typePtr;
			    }
			    ((Refinement *)((yyval.listPtr)->ptr))->export.access = (yyvsp[-2].access);
			    if (! (thisParserPtr->flags & SMI_FLAG_NODESCR)) {
				((Refinement *)((yyval.listPtr)->ptr))->export.description = (yyvsp[0].text);
			    } else {
				smiFree((yyvsp[0].text));
			    }
			}
#line 9421 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 388:
#line 6913 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_SYNTAX);
			    }
			    if ((yyvsp[0].typePtr)->export.name) {
				(yyval.typePtr) = duplicateType((yyvsp[0].typePtr), 0, thisParserPtr);
			    } else {
				(yyval.typePtr) = (yyvsp[0].typePtr);
			    }
			}
#line 9438 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 389:
#line 6926 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = NULL;
			}
#line 9446 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 390:
#line 6932 "parser-smi.y" /* yacc.c:1646  */
    {
                            /* must not be present in PIBs */
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) {
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "WRITE-SYNTAX");
			    }
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_WRITESYNTAX);
			    }
			    if ((yyvsp[0].typePtr)->export.name) {
				(yyval.typePtr) = duplicateType((yyvsp[0].typePtr), 0, thisParserPtr);
			    } else {
				(yyval.typePtr) = (yyvsp[0].typePtr);
			    }
			}
#line 9467 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 391:
#line 6949 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = NULL;
			}
#line 9475 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 392:
#line 6955 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.typePtr) = (yyvsp[0].typePtr);
			}
#line 9483 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 393:
#line 6961 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "MIN-ACCESS");
			    (yyval.access) = (yyvsp[0].access);
			}
#line 9493 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 394:
#line 6967 "parser-smi.y" /* yacc.c:1646  */
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-MIN-ACCESS");
                            if ((yyvsp[0].access) == SMI_ACCESS_REPORT_ONLY)
                                smiPrintError(thisParserPtr, ERR_REPORT_ONLY_IN_PIB_MIN_ACCESS);
                            (yyval.access) = (yyvsp[0].access);
                        }
#line 9505 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 395:
#line 6975 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.access) = SMI_ACCESS_UNKNOWN;
			}
#line 9513 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 396:
#line 6981 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_AGENTCAPABILITIES;
			    
			    checkNameLen(thisParserPtr, (yyvsp[0].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[0].id));
			}
#line 9527 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 397:
#line 6991 "parser-smi.y" /* yacc.c:1646  */
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "AGENT-CAAPABILITIES");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("AGENT-CAPABILITIES",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "AGENT-CAPABILITIES",
					      "SNMPv2-CONF");
			    }
			}
#line 9551 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 398:
#line 7013 "parser-smi.y" /* yacc.c:1646  */
    {
			    checkDescr(thisParserPtr, (yyvsp[0].text));
			}
#line 9559 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 399:
#line 7019 "parser-smi.y" /* yacc.c:1646  */
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[-1].objectPtr);
			    
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[-16].id), &objectPtr);

			    setObjectName(objectPtr, (yyvsp[-16].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_AGENTCAPABILITIES);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[-9].status));
			    setObjectDescription(objectPtr, (yyvsp[-7].text), thisParserPtr);
			    if ((yyvsp[-5].text)) {
				setObjectReference(objectPtr, (yyvsp[-5].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
				/*
				 * TODO: PRODUCT_RELEASE Text
				 * TODO: ModulePart_Capabilities
				 */
			    (yyval.err) = 0;
			}
#line 9591 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 400:
#line 7049 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9597 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 401:
#line 7051 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9603 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 402:
#line 7055 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9609 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 403:
#line 7057 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9615 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 404:
#line 7061 "parser-smi.y" /* yacc.c:1646  */
    {
			    /*
			     * Remember the module. SMIv2 is broken by
			     * design to allow subsequent clauses to
			     * refer identifiers that are not
			     * imported.  Although, SMIv2 does not
			     * require, we will fake it by inserting
			     * appropriate imports.
			     */
			    if ((yyvsp[0].modulePtr) == thisModulePtr)
				thisParserPtr->capabilitiesModulePtr = NULL;
			    else
				thisParserPtr->capabilitiesModulePtr = (yyvsp[0].modulePtr);
			}
#line 9634 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 405:
#line 7077 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (thisParserPtr->capabilitiesModulePtr) {
				checkImports(thisParserPtr->capabilitiesModulePtr,
					     thisParserPtr);
				thisParserPtr->capabilitiesModulePtr = NULL;
			    }
			    (yyval.err) = 0;
			}
#line 9647 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 406:
#line 7088 "parser-smi.y" /* yacc.c:1646  */
    {
#if 0
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[0].listPtr);
			    (yyval.listPtr)->nextPtr = NULL;
#else
			    (yyval.listPtr) = NULL;
#endif
			}
#line 9661 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 407:
#line 7098 "parser-smi.y" /* yacc.c:1646  */
    {
#if 0
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[0].listPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[-2].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[-2].listPtr);
#else
			    (yyval.listPtr) = NULL;
#endif
			}
#line 9680 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 408:
#line 7115 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.listPtr) = NULL;
			}
#line 9688 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 409:
#line 7121 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[-1].id));
			    /* TODO: handle objectIdentifier */
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[-1].id), thisParserPtr);
			    }
			    smiFree((yyvsp[-1].id));
			}
#line 9701 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 410:
#line 7130 "parser-smi.y" /* yacc.c:1646  */
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[0].id));
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[0].id), thisParserPtr);
			    }
			    smiFree((yyvsp[0].id));
			}
#line 9713 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 411:
#line 7140 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9719 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 412:
#line 7142 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9725 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 413:
#line 7146 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9731 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 414:
#line 7148 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9737 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 415:
#line 7152 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].objectPtr)) {
				variationkind = (yyvsp[0].objectPtr)->export.nodekind;
			    } else {
				variationkind = SMI_NODEKIND_UNKNOWN;
			    }
			}
#line 9749 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 416:
#line 7164 "parser-smi.y" /* yacc.c:1646  */
    {
			    if ((yyvsp[0].valuePtr)) {
				adjustDefval(thisParserPtr,
					     (yyvsp[0].valuePtr), (yyvsp[-6].objectPtr)->typePtr,
					     thisParserPtr->line);
				smiCheckValueType(thisParserPtr,
						  (yyvsp[0].valuePtr), (yyvsp[-6].objectPtr)->typePtr,
						  thisParserPtr->line);
			    }
			}
#line 9764 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 417:
#line 7175 "parser-smi.y" /* yacc.c:1646  */
    {
			    thisParserPtr->flags &= ~FLAG_CREATABLE;
			    (yyval.err) = 0;
			    variationkind = SMI_NODEKIND_UNKNOWN;

			    checkDescr(thisParserPtr, (yyvsp[-1].id));
			}
#line 9776 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 418:
#line 7185 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = (yyvsp[0].access); }
#line 9782 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 419:
#line 7187 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.access) = 0; }
#line 9788 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 420:
#line 7191 "parser-smi.y" /* yacc.c:1646  */
    {
			    if (!strcmp((yyvsp[0].id), "not-implemented")) {
				(yyval.access) = SMI_ACCESS_NOT_IMPLEMENTED;
			    } else if (!strcmp((yyvsp[0].id), "accessible-for-notify")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
				}
			    } else if (!strcmp((yyvsp[0].id), "read-only")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				}
			    } else if (!strcmp((yyvsp[0].id), "read-write")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				}
			    } else if (!strcmp((yyvsp[0].id), "read-create")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				}
			    } else if (!strcmp((yyvsp[0].id), "write-only")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[0].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE; /* TODO */
				    smiPrintError(thisParserPtr,
					       ERR_SMIV2_WRITE_ONLY);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_INVALID_VARIATION_ACCESS,
					      (yyvsp[0].id));
				(yyval.access) = SMI_ACCESS_UNKNOWN;
			    }
			}
#line 9855 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 421:
#line 7256 "parser-smi.y" /* yacc.c:1646  */
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_CREATION);
			    }
			    (yyval.err) = 0;
			}
#line 9868 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 422:
#line 7265 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9874 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 423:
#line 7269 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9880 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 424:
#line 7271 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9886 "parser-smi.c" /* yacc.c:1646  */
    break;

  case 425:
#line 7275 "parser-smi.y" /* yacc.c:1646  */
    { (yyval.err) = 0; }
#line 9892 "parser-smi.c" /* yacc.c:1646  */
    break;


#line 9896 "parser-smi.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parserPtr, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parserPtr, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parserPtr);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, parserPtr);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parserPtr, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parserPtr);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, parserPtr);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 7278 "parser-smi.y" /* yacc.c:1906  */


#endif
