/* Written by Dan Heller and Paula Ferguson.  
 * Copyright 1994, O'Reilly & Associates, Inc.
 * Permission to use, copy, and modify this program without
 * restriction is hereby granted, as long as this copyright
 * notice appears in each copy of the program source code.
 * This program is freely distributable without licensing fees and
 * is provided without guarantee or warrantee expressed or implied.
 * This program is -not- in the public domain.
 */

/* arrow_timer.c -- demonstrate continuous callbacks using
 * ArrowButton widgets.  Display up and down ArrowButtons and
 * attach arm and disarm callbacks to them to start and stop timer
 * that is called repeatedly while the button is down.  A label
 * that has a value changes either positively or negatively
 * by single increments while the button is depressed.
 */
#include <Xm/ArrowBG.h>
#include <Xm/Form.h>
#include <Xm/RowColumn.h>
#include <Xm/LabelG.h>

XtAppContext app;
Widget label;
XtIntervalId arrow_timer_id;
typedef struct value_range {
    int value, min_, max_;
} ValueRange;

main(argc, argv)
int argc;
char *argv[];
{
    Widget w, toplevel, rowcol;
    void start_stop();
    ValueRange range;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos",
        NULL, 0, &argc, argv, NULL, NULL);

    rowcol = XtVaCreateWidget ("rowcol",
        xmRowColumnWidgetClass, toplevel,
        XmNorientation, XmHORIZONTAL,
        NULL);

    w = XtVaCreateManagedWidget ("arrow_up",
        xmArrowButtonGadgetClass, rowcol,
        XmNarrowDirection,   XmARROW_UP,
        NULL);
    /*XtAddCallback (w, XmNarmCallback, start_stop, 1);
    XtAddCallback (w, XmNdisarmCallback, start_stop, 1);*/
    XtAddCallback (w, XmNarmCallback, start_stop, (XtPointer)1);
    XtAddCallback (w, XmNdisarmCallback, start_stop, (XtPointer)1);

    w = XtVaCreateManagedWidget ("arrow_dn",
        xmArrowButtonGadgetClass, rowcol,
        XmNarrowDirection,   XmARROW_DOWN,
        NULL);
    /*XtAddCallback (w, XmNarmCallback, start_stop, -1);
    XtAddCallback (w, XmNdisarmCallback, start_stop, -1);*/
    XtAddCallback (w, XmNarmCallback, start_stop, (XtPointer)-1);
    XtAddCallback (w, XmNdisarmCallback, start_stop, (XtPointer)-1);

    range.value = 0;
    range.min_ = -50;
    range.max_ = 50;
    label = XtVaCreateManagedWidget ("label",
        xmLabelGadgetClass, rowcol,
        XtVaTypedArg, XmNlabelString, XmRString, "0   ", 3,
        XmNuserData, &range,
        NULL);

    XtManageChild (rowcol);
    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}

/* start_stop is used to start or stop the incremental changes to
 * the label's value.  When the button goes down, the reason is
 * XmCR_ARM and the timer starts.  XmCR_DISARM disables the timer.
 */
void
start_stop(w, client_data, call_data)
Widget w;
XtPointer client_data;
XtPointer call_data;
{
    int incr = (int) client_data;
    XmArrowButtonCallbackStruct *cbs = 
        (XmArrowButtonCallbackStruct *) call_data;
    void change_value();

    if (cbs->reason == XmCR_ARM)
        change_value (incr, 1 );
    else if (cbs->reason == XmCR_DISARM)
        XtRemoveTimeOut (arrow_timer_id);
}

/* change_value is called each time the timer expires.  This function
 * is also used to initiate the timer.  The "id" represents that timer
 * ID returned from the last call to XtAppAddTimeOut().  If id == 1,
 * the function was called from start_stop(), not a timeout.  If the value 
 * has reached its max_imum or min_imum, don't restart timer, just return.
 * If id == 1, this is the first timeout so make it be longer to allow
 * the user to release the button and avoid getting into the "speedy"
 * part of the timeouts.
 */
void
change_value(client_data, id)
XtPointer client_data; 
XtIntervalId* id;
{
    ValueRange *range;
    char buf[8];
    int incr = (int) client_data;

    XtVaGetValues (label, XmNuserData, &range, NULL);
    if (range->value + incr > range->max_ ||
        range->value + incr < range->min_)
        return;
    range->value += incr;
    sprintf (buf, "%d", range->value);
    XtVaSetValues (label,
        XtVaTypedArg, XmNlabelString, XmRString, buf, strlen(buf),
        NULL);
    arrow_timer_id =
        XtAppAddTimeOut (app, (int)id==1? 500 : 100, change_value, (XtPointer)incr);
}
   