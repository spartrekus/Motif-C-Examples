/*
 *    text.c
 *
 *     This file demonstrates a XmText editor widget.  In addition, it
 *  provides more examples of working with the XmString type, callbacks, 
 *  and setting widget resources.
 *
 *                                                - Dave Shreiner
 *                                                  20 March 1991
 */

#include <Xm/Xm.h>      /* X/Motif header file */
#include <Xm/Text.h>    /* header file for Text widget type. */

main(argc, argv)
int argc;
char *argv[];
{

/*----------------------------------------------------------------------------
      Declare variables and initialize the application.  [see label.c]
-----------------------------------------------------------------------------*/

   Widget   toplevel, text;
   Arg      arg;
   void     enter();

   toplevel = XtInitialize(argv[0], "MotifDemo", NULL, 0, &argc, argv);

/*----------------------------------------------------------------------------
      Create a push button widget using the XmCreateText() call.  This
      function has identical parameters to the XmCreateLabel() call in label.c.
-----------------------------------------------------------------------------*/

   text = XmCreateText(toplevel, "text", NULL, 0);

/*----------------------------------------------------------------------------
      Define the width of the widget to be 400 pixels. [see label.c]
-----------------------------------------------------------------------------*/

   XtSetArg(arg, XmNwidth, 400);

/*----------------------------------------------------------------------------
      Set the resource value of the text widget after its creation.  In some
      instances, its not possible to set up resources before the widgets is
      created, and so the function XtSetValues() allows you to use X Arg
      type structures (as above), and set them somewhere else in the code
      after the widget has been created.
-----------------------------------------------------------------------------*/

   XtSetValues(text, &arg, 1);

/*----------------------------------------------------------------------------
      Register an activation callback for the text widget.  Activation for
      the text widget occurs when the user presses the <return> key.
      [see push_button.c for more on callbacks]
-----------------------------------------------------------------------------*/

   XtAddCallback(text, XmNactivateCallback, enter, NULL);

/*----------------------------------------------------------------------------
      Manage the child widget (in this case "text"), let X know we want the
      window to appear, and then we'll process all the events sent from the
      X server.
-----------------------------------------------------------------------------*/

   XtManageChild(text);

   XtRealizeWidget(toplevel);
   XtMainLoop();
}


/*----------------------------------------------------------------------------
      Define a callback function.  This routine uses the function
      XmTextGetString() to read the text from the text widget.  In addition,
      we use the function XtFree() to release the memory back to the system.
      This is important since, X/Motif usually allocates memory for you,
      releiving the program of the responsibility of allocating memory in
      some situations.  (See the OSF/Motif Programmer's Reference to see when
      calling XtFree() is necessary)
-----------------------------------------------------------------------------*/

void enter(widget, client_data, call_data)
Widget   widget;
caddr_t  client_data, call_data;
{
   char  *string;

   string = XmTextGetString(widget);
   printf(" The text widget contains : '%s'\n", string);
   XtFree(string);
}
