/*	$OpenBSD: lstAppend.c,v 1.11 2000/09/14 13:32:08 espie Exp $	*/
/*	$NetBSD: lstAppend.c,v 1.5 1996/11/06 17:59:31 christos Exp $	*/

/*
 * Copyright (c) 1988, 1989, 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Adam de Boor.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*-
 * LstAppend.c --
 *	Add a new node with a new datum after an existing node
 */

#include	"lstInt.h"
#ifndef lint
#if 0
static char sccsid[] = "@(#)lstAppend.c	8.1 (Berkeley) 6/6/93";
#else
UNUSED
static char rcsid[] = "$OpenBSD: lstAppend.c,v 1.11 2000/09/14 13:32:08 espie Exp $";
#endif
#endif /* not lint */


/*-
 *-----------------------------------------------------------------------
 * Lst_Append --
 *	Create a new node and add it to the given list after the given node.
 *
 * Results:
 *	SUCCESS if all went well.
 *
 * Side Effects:
 *	A new ListNode is created and linked in to the List. The lastPtr
 *	field of the List will be altered if ln is the last node in the
 *	list. lastPtr and firstPtr will alter if the list was empty and
 *	ln was NULL.
 *
 *-----------------------------------------------------------------------
 */
void
Lst_Append(l, ln, d)
    Lst	  	l;	/* affected list */
    LstNode	ln;	/* node after which to append the datum */
    void 	*d;	/* said datum */
{
    LstNode	nLNode;

    if (ln == NULL && LstIsEmpty(l))
	goto ok;

    if (LstIsEmpty(l)  || ! LstNodeValid(ln, l))
	return;
    ok:

    PAlloc(nLNode, LstNode);
    nLNode->datum = d;
    nLNode->useCount = nLNode->flags = 0;

    if (ln == NULL) {
	nLNode->nextPtr = nLNode->prevPtr = NULL;
	l->firstPtr = l->lastPtr = nLNode;
    } else {
	nLNode->prevPtr = ln;
	nLNode->nextPtr = ln->nextPtr;

	ln->nextPtr = nLNode;
	if (nLNode->nextPtr != NULL)
	    nLNode->nextPtr->prevPtr = nLNode;

	if (ln == l->lastPtr)
	    l->lastPtr = nLNode;
    }
}

