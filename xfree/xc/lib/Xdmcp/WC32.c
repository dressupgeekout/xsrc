/*
 * $Xorg: WC32.c,v 1.3 2000/08/17 19:45:50 cpqbld Exp $
 *
 * 
Copyright 1989, 1998  The Open Group

All Rights Reserved.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.
 * *
 * Author:  Keith Packard, MIT X Consortium
 */
/* $XFree86: xc/lib/Xdmcp/WC32.c,v 1.4 2001/01/17 19:42:44 dawes Exp $ */

#include <X11/Xos.h>
#include <X11/X.h>
#include <X11/Xmd.h>
#include <X11/Xdmcp.h>

int
XdmcpWriteCARD32 (
    XdmcpBufferPtr  buffer,
    unsigned	    value)
{
    if (!XdmcpWriteCARD8 (buffer, value >> 24))
	return FALSE;
    if (!XdmcpWriteCARD8 (buffer, (value >> 16) & 0xff))
	return FALSE;
    if (!XdmcpWriteCARD8 (buffer, (value >> 8) & 0xff))
	return FALSE;
    if (!XdmcpWriteCARD8 (buffer, value & 0xff))
	return FALSE;
    return TRUE;
}
