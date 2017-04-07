 
#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>

/* Prototype functions */

void create_dialogs(void);

/* callback for the pushbuttons.  pops up dialog */

void info_pop_up(Widget , char *, XmPushButtonCallbackStruct *),     
       quit_pop_up(Widget , char *, XmPushButtonCallbackStruct *);

void info_activate(Widget ), 
       quit_activate(Widget );

/* Global reference for dialog widgets */
Widget info, quit;
Widget info_dialog, quit_dialog;


main(int argc, char *argv[])
{
    XtAppContext app;
    Widget top_wid, main_w, menu_bar;
    
    top_wid = XtVaAppInitialize(&app, "Demos", NULL, 0,
        &argc, argv, NULL, NULL);

    main_w = XtVaCreateManagedWidget("main_window",
        xmMainWindowWidgetClass,   top_wid, 
        XmNheight, 300,
        XmNwidth,300,
        NULL);
        
        
    menu_bar = (Widget) XmCreateMenuBar(main_w, "main_list", NULL, 0);        
    XtManageChild(menu_bar);

        
    /* create quit widget + callback */
        
    quit = XtVaCreateManagedWidget( "Quit",
        xmCascadeButtonWidgetClass, menu_bar,
        XmNmnemonic, 'Q',
        NULL);
        
    /* Callback has data passed to */
    
    XtAddCallback(quit, XmNactivateCallback, quit_pop_up, NULL); 

    
    /* create help widget + callback */
        
    info = XtVaCreateManagedWidget( "Info",
        xmCascadeButtonWidgetClass, menu_bar,
        XmNmnemonic, 'I',
        NULL);    

    XtAddCallback(info, XmNactivateCallback, info_pop_up, NULL); 


    /* Create but do not show (manage) dialogs */

    create_dialogs();
    

    XtRealizeWidget(top_wid);
    XtAppMainLoop(app);
}

void create_dialogs()

 {  /* Create but do not manage dialog widgets */

    XmString xm_string;
    Arg args[1];


    /* Create InformationDialog */

    /* Label the dialog */

    xm_string = XmStringCreateLocalized("Dialog widgets added to \
                give info and check quit choice");
    XtSetArg(args[0], XmNmessageString, xm_string);

    /* Create the InformationDialog */

    info_dialog = XmCreateInformationDialog(info, "info", args, 1);

    XmStringFree(xm_string);

    XtAddCallback(info_dialog, XmNokCallback, info_activate, NULL);

    /* Create Warning DIalog */

    /* label the dialog */

    xm_string = 
      XmStringCreateLocalized("Are you sure you want to quit?");
    XtSetArg(args[0], XmNmessageString, xm_string);

    /* Create the WarningDialog */
    quit_dialog = XmCreateWarningDialog(quit, "quit", args, 1);

    XmStringFree(xm_string);

    XtAddCallback(quit_dialog, XmNokCallback, quit_activate, NULL);

}


void info_pop_up(Widget cascade_button, char *text, 
                 XmPushButtonCallbackStruct *cbs)

{
    XtManageChild(info_dialog);
}

void quit_pop_up(Widget cascade_button, char *text, 
                 XmPushButtonCallbackStruct *cbs)

{
    XtManageChild(quit_dialog);
}

/* callback routines for dialogs */

void info_activate(Widget dialog)
{
    printf("Info Ok was pressed.\n");
}

void quit_activate(Widget dialog)
{
    printf("Quit Ok was pressed.\n");
    exit(0);
}