/* Written by Dan Heller and Paula Ferguson.  
 * Copyright 1994, O'Reilly & Associates, Inc.
 * Permission to use, copy, and modify this program without
 * restriction is hereby granted, as long as this copyright
 * notice appears in each copy of the program source code.
 * This program is freely distributable without licensing fees and
 * is provided without guarantee or warrantee expressed or implied.
 * This program is -not- in the public domain.
 */

/* tictactoe.c -- demonstrate how fractionBase and XmATTACH_POSITIONs
 * work in Form widgets.
 */
#include <Xm/PushB.h>
#include <Xm/Form.h>

main(argc, argv)
int argc;
char *argv[];
{
    XtAppContext app;
    Widget toplevel, parent, w;
    int x, y;
    extern void pushed();  /* callback for each PushButton */

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos", NULL, 0,
        &argc, argv, NULL, NULL);

    parent = XtVaCreateManagedWidget ("form", 
        xmFormWidgetClass, toplevel,
        XmNfractionBase,    3,
        NULL);

    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++) {
            w = XtVaCreateManagedWidget ("   ",
                xmPushButtonWidgetClass, parent,
                XmNtopAttachment,    XmATTACH_POSITION,
                XmNtopPosition,      y,
                XmNleftAttachment,   XmATTACH_POSITION,
                XmNleftPosition,     x,
                XmNrightAttachment,  XmATTACH_POSITION,
                XmNrightPosition,    x+1,
                XmNbottomAttachment, XmATTACH_POSITION,
                XmNbottomPosition,   y+1,
                NULL);
            XtAddCallback (w, XmNactivateCallback, pushed, NULL);
        }

    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}

void
pushed(w, client_data, call_data)
Widget     w;           /* The PushButton that got activated */
XtPointer  client_data; /* unused -- NULL was passed to XtAddCallback() */
XtPointer  call_data;
{
    char buf[2];
    XmString str;
    XmPushButtonCallbackStruct *cbs = 
        (XmPushButtonCallbackStruct *) call_data;

    /* Shift key gets an O.  (xbutton and xkey happen to be similar) */
    if (cbs->event->xbutton.state & ShiftMask)
        buf[0] = '0';
    else
        buf[0] = 'X';
    buf[1] = 0;
    str = XmStringCreateLocalized (buf);
    XtVaSetValues (w, XmNlabelString, str, NULL);
    XmStringFree (str);
}
   