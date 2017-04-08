/* Written by Dan Heller and Paula Ferguson.  
 * Copyright 1994, O'Reilly & Associates, Inc.
 * Permission to use, copy, and modify this program without
 * restriction is hereby granted, as long as this copyright
 * notice appears in each copy of the program source code.
 * This program is freely distributable without licensing fees and
 * is provided without guarantee or warrantee expressed or implied.
 * This program is -not- in the public domain.
 */

/* entry_cb.c -- demonstrate how the XmNentryCallback resource works
 * in RowColumn widgets.  When a callback function is set for this
 * resource, all the callbacks for the RowColumn's children are reset
 * to point to this function.  Their original functions are no longer
 * called had they been set in favor of the entry-callback function.
 */
#include <Xm/PushBG.h>
#include <Xm/RowColumn.h>

char *strings[] = {
    "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
};

void
called(widget, client_data, call_data)
Widget widget;
XtPointer client_data; 
XtPointer call_data; 
{
    XmRowColumnCallbackStruct *cbs = 
        (XmRowColumnCallbackStruct *) call_data;
    Widget pb = cbs->widget;

    printf ("%s: %d\n", XtName (pb), cbs->data);
}

static void
never_called(widget, client_data, call_data)
Widget widget;
XtPointer client_data; 
XtPointer call_data; 
{
    puts ("This function is never called");
}

main(argc, argv)
int argc;
char *argv[];
{
    Widget toplevel, parent, w;
    XtAppContext app;
    int i;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos",
        NULL, 0, &argc, argv, NULL, NULL);

    parent = XtVaCreateManagedWidget ("rowcolumn",
        xmRowColumnWidgetClass, toplevel,
        NULL);
    XtAddCallback (parent, XmNentryCallback, called, NULL);
 
    /* simply loop thru the strings creating a widget for each one */
    for (i = 0; i < XtNumber (strings); i++) {
        w = XtVaCreateManagedWidget (strings[i],
            xmPushButtonGadgetClass, parent, NULL);
        /* Call XtAddCallback() to install client_data only! */
        XtAddCallback (w, XmNactivateCallback, never_called, i+1);
    }

    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}
  