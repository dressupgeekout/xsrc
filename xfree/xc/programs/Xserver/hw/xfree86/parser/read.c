/* $XFree86: xc/programs/Xserver/hw/xfree86/parser/read.c,v 1.14 2000/11/02 19:10:58 dawes Exp $ */
/* 
 * 
 * Copyright (c) 1997  Metro Link Incorporated
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Except as contained in this notice, the name of the Metro Link shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization from Metro Link.
 * 
 */

/* View/edit this file with tab stops set to 4 */

#include "xf86Parser.h"
#include "xf86tokens.h"
#include "Configint.h"

extern LexRec val;

static xf86ConfigSymTabRec TopLevelTab[] =
{
	{SECTION, "section"},
	{-1, ""},
};

#define CLEANUP xf86freeConfig

XF86ConfigPtr
xf86readConfigFile (void)
{
	int token;
	XF86ConfigPtr ptr = NULL;

	if ((ptr = xf86confcalloc (1, sizeof (XF86ConfigRec))) == NULL)
	{
		return NULL;
	}
	memset (ptr, 0, sizeof (XF86ConfigRec));

	while ((token = xf86getToken (TopLevelTab)) != EOF_TOKEN)
	{
		switch (token)
		{
		case SECTION:
			if (xf86getToken (NULL) != STRING)
			{
				xf86parseError (QUOTE_MSG, "Section");
				CLEANUP (ptr);
				return (NULL);
			}
			xf86setSection (val.str);
			if (xf86nameCompare (val.str, "files") == 0)
			{
				HANDLE_RETURN (conf_files, xf86parseFilesSection ());
			}
			else if (xf86nameCompare (val.str, "serverflags") == 0)
			{
				HANDLE_RETURN (conf_flags, xf86parseFlagsSection ());
			}
			else if (xf86nameCompare (val.str, "keyboard") == 0)
			{
				HANDLE_LIST (conf_input_lst, xf86parseKeyboardSection,
							 XF86ConfInputPtr);
			}
			else if (xf86nameCompare (val.str, "pointer") == 0)
			{
				HANDLE_LIST (conf_input_lst, xf86parsePointerSection,
							 XF86ConfInputPtr);
			}
			else if (xf86nameCompare (val.str, "videoadaptor") == 0)
			{
				HANDLE_LIST (conf_videoadaptor_lst, xf86parseVideoAdaptorSection,
							 XF86ConfVideoAdaptorPtr);
			}
			else if (xf86nameCompare (val.str, "device") == 0)
			{
				HANDLE_LIST (conf_device_lst, xf86parseDeviceSection,
							 XF86ConfDevicePtr);
			}
			else if (xf86nameCompare (val.str, "monitor") == 0)
			{
				HANDLE_LIST (conf_monitor_lst, xf86parseMonitorSection,
							 XF86ConfMonitorPtr);
			}
			else if (xf86nameCompare (val.str, "modes") == 0)
			{
				HANDLE_LIST (conf_modes_lst, xf86parseModesSection,
							 XF86ConfModesPtr);
			}
			else if (xf86nameCompare (val.str, "screen") == 0)
			{
				HANDLE_LIST (conf_screen_lst, xf86parseScreenSection,
							 XF86ConfScreenPtr);
			}
			else if (xf86nameCompare(val.str, "inputdevice") == 0)
			{
				HANDLE_LIST (conf_input_lst, xf86parseInputSection,
							 XF86ConfInputPtr);
			}
			else if (xf86nameCompare (val.str, "module") == 0)
			{
				HANDLE_RETURN (conf_modules, xf86parseModuleSection ());
			}
			else if (xf86nameCompare (val.str, "serverlayout") == 0)
			{
				HANDLE_LIST (conf_layout_lst, xf86parseLayoutSection,
							 XF86ConfLayoutPtr);
			}
			else if (xf86nameCompare (val.str, "vendor") == 0)
			{
				HANDLE_LIST (conf_vendor_lst, xf86parseVendorSection,
							 XF86ConfVendorPtr);
			}
			else if (xf86nameCompare (val.str, "dri") == 0)
			{
				HANDLE_RETURN (conf_dri, xf86parseDRISection ());
			}
			else
			{
				Error (INVALID_SECTION_MSG, xf86tokenString ());
			}
			break;
		default:
			Error (INVALID_KEYWORD_MSG, xf86tokenString ());
		}
	}

	if (xf86validateConfig (ptr))
		return (ptr);
	else
	{
		CLEANUP (ptr);
		return (NULL);
	}
}

#undef CLEANUP

/* 
 * This function resolves name references and reports errors if the named
 * objects cannot be found.
 */
int
xf86validateConfig (XF86ConfigPtr p)
{
	if (!xf86validateDevice (p))
		return FALSE;
	if (!xf86validateScreen (p))
		return FALSE;
	if (!xf86validateInput (p))
		return FALSE;
	if (!xf86validateLayout (p))
		return FALSE;

	return (TRUE);
}

/* 
 * adds an item to the end of the linked list. Any record whose first field
 * is a GenericListRec can be cast to this type and used with this function.
 * A pointer to the head of the list is returned to handle the addition of
 * the first item.
 */
GenericListPtr
xf86addListItem (GenericListPtr head, GenericListPtr new)
{
	GenericListPtr p = head;
	GenericListPtr last = NULL;

	while (p)
	{
		last = p;
		p = p->next;
	}

	if (last)
	{
		last->next = new;
		return (head);
	}
	else
		return (new);
}

/* 
 * Test if one chained list contains the other.
 * In this case both list have the same endpoint (provided they don't loop)
 */
int
xf86itemNotSublist(GenericListPtr list_1, GenericListPtr list_2)
{
    GenericListPtr p = list_1;
    GenericListPtr last_1 = NULL, last_2 = NULL;

    while (p) {
        last_1 = p;
	p = p->next;
    }
    
    p = list_2;
    while (p) {
      last_2 = p;
      p = p->next;
    }
    
    return (!(last_1 == last_2));
}

void
xf86freeConfig (XF86ConfigPtr p)
{
	if (p == NULL)
		return;

	xf86freeFiles (p->conf_files);
	xf86freeModules (p->conf_modules);
	xf86freeFlags (p->conf_flags);
	xf86freeMonitorList (p->conf_monitor_lst);
	xf86freeModesList (p->conf_modes_lst);
	xf86freeVideoAdaptorList (p->conf_videoadaptor_lst);
	xf86freeDeviceList (p->conf_device_lst);
	xf86freeScreenList (p->conf_screen_lst);
	xf86freeLayoutList (p->conf_layout_lst);
	xf86freeInputList (p->conf_input_lst);
	xf86freeVendorList (p->conf_vendor_lst);
	xf86freeDRI (p->conf_dri);

	xf86conffree (p);
}
