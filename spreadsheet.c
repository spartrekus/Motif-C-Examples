/* Written by Dan Heller and Paula Ferguson.  
 * Copyright 1994, O'Reilly & Associates, Inc.
 * Permission to use, copy, and modify this program without
 * restriction is hereby granted, as long as this copyright
 * notice appears in each copy of the program source code.
 * This program is freely distributable without licensing fees and
 * is provided without guarantee or warrantee expressed or implied.
 * This program is -not- in the public domain.
 */

/* spreadsheet.c -- This demo shows the most basic use of the RowColumn
 * It displays a table of widgets in a row-column format similar to a
 * spreadsheet.  This is accomplished by setting the number ROWS and
 * COLS and setting the appropriate resources correctly.
 */
#include <Xm/LabelG.h>
#include <Xm/PushB.h>
#include <Xm/RowColumn.h>

#define ROWS  8
#define COLS 10

main(argc, argv)
int argc;
char *argv[];
{
    Widget toplevel, parent;
    XtAppContext app;
    char buf[16];
    int i, j;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos", NULL, 0,
        &argc, argv, NULL, NULL);

    parent = XtVaCreateManagedWidget ("rowcolumn",
        xmRowColumnWidgetClass, toplevel,
        XmNpacking,     XmPACK_COLUMN,
        XmNnumColumns,  COLS,
        XmNorientation, XmVERTICAL,
        NULL);

    /* simply loop thru the strings creating a widget for each one */
    for (i = 0; i < COLS; i++)
        for (j = 0; j < ROWS; j++) {
            sprintf (buf, "%d-%d", i+1, j+1);
            if (i == 0 || j == 0)
                XtVaCreateManagedWidget (buf,
                    xmLabelGadgetClass, parent, NULL);
            else
                XtVaCreateManagedWidget ("",
                    xmPushButtonWidgetClass, parent, NULL);
        }

    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}
   