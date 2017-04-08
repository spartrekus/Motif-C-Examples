/* Written by Dan Heller and Paula Ferguson.  
 * Copyright 1994, O'Reilly & Associates, Inc.
 * Permission to use, copy, and modify this program without
 * restriction is hereby granted, as long as this copyright
 * notice appears in each copy of the program source code.
 * This program is freely distributable without licensing fees and
 * is provided without guarantee or warrantee expressed or implied.
 * This program is -not- in the public domain.
 */

/* tick_marks.c -- demonstrate a scale widget with tick marks. */

#include <Xm/Scale.h>
#include <Xm/LabelG.h>

#define MAX_VAL 10 /* arbitrary value */

main(argc, argv)
int argc;
char *argv[];
{
    Widget        toplevel, scale;
    XtAppContext  app;
    int           i;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos", NULL, 0,
        &argc, argv, NULL, NULL);

    scale = XtVaCreateManagedWidget ("load",
        xmScaleWidgetClass, toplevel,
        XtVaTypedArg,     XmNtitleString, XmRString, "Process Load", 13,
        XmNmaximum,       MAX_VAL * 100,
        XmNminimum,       100,
        XmNvalue,         100,
        XmNdecimalPoints, 2,
        XmNshowValue,     True,
        NULL);
 
    for (i = 0; i < MAX_VAL; i++)
        XtVaCreateManagedWidget ("-", xmLabelGadgetClass, scale, NULL);

    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}
   