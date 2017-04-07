#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>
#include <Xm/SelectioB.h>
#include <Xm/RowColumn.h>

void ScrubDial(Widget, int);

Widget top_wid;

/*--------------------------*/
main(int argc, char *argv[])
/*--------------------------*/
{   

  XtAppContext app;
  Widget main_w, menu_bar, info, prompt, quit;
  void info_pop_up(), quit_pop_up(), prompt_pop_up();

    
  top_wid = XtVaAppInitialize(&app, "Demos", NULL, 0,
                              &argc, argv, NULL, NULL);

  main_w = XtVaCreateManagedWidget("main_window",
                                   xmMainWindowWidgetClass, top_wid, 
                                   XmNheight, 300,
                                   XmNwidth,300,
                                   NULL);

        
  menu_bar = XmCreateMenuBar(main_w, "main_list", 
                             NULL, 0);        
  XtManageChild(menu_bar);
       
  /* create prompt widget + callback */       
  prompt = XtVaCreateManagedWidget( "Prompt",
                                    xmCascadeButtonWidgetClass, menu_bar,
                                    XmNmnemonic, 'P',
                                    NULL);
                
  /* Callback has data passed to */   
  XtAddCallback(prompt, XmNactivateCallback, 
                prompt_pop_up, NULL);

    
    
  /* create quit widget + callback */
  quit = XtVaCreateManagedWidget( "Quit",
                                  xmCascadeButtonWidgetClass, menu_bar,
                                  XmNmnemonic, 'Q',
                                  NULL);
        
        
  /* Callback has data passed to */
  XtAddCallback(quit, XmNactivateCallback, quit_pop_up, 
                "Are you sure you want to quit?");


    
  /* create help widget + callback */
        
  info = XtVaCreateManagedWidget( "Info",
                                  xmCascadeButtonWidgetClass, menu_bar,
                                  XmNmnemonic, 'I',
                                  NULL);    

  XtAddCallback(info, XmNactivateCallback, info_pop_up, 
                "Select Prompt Option To Get Program Going."); 
    
  XtRealizeWidget(top_wid);
  XtAppMainLoop(app);
}

/*----------------------------------------------------*/
void prompt_pop_up(Widget cascade_button, char *text, 
                   XmPushButtonCallbackStruct *cbs)
/*----------------------------------------------------*/
{   
  Widget dialog, remove;
  XmString xm_string1, xm_string2;
  void prompt_activate();
  Arg args[3];
  int n;

  /* label the dialog */
  xm_string1 = XmStringCreateSimple("Enter Text Here:");
  /* default text string  */
  xm_string2 = XmStringCreateSimple("Default String");

  n=0;
  XtSetArg(args[n], XmNselectionLabelString, xm_string1); n++;
  XtSetArg(args[n], XmNtextString, xm_string2); n++;
   /* set up default button for cancel callback */
  XtSetArg(args[n], XmNdefaultButtonType, 
           XmDIALOG_CANCEL_BUTTON);  n++;

  /* Create the WarningDialog */
  dialog = XmCreatePromptDialog(cascade_button, "prompt", 
                                args, n);
    
  XmStringFree(xm_string1);
  XmStringFree(xm_string2);

   
  XtAddCallback(dialog, XmNokCallback, prompt_activate, 
                NULL);
  /* Scrub Prompt Help Button */
  remove = XmSelectionBoxGetChild(dialog, 
                                  XmDIALOG_HELP_BUTTON);
   
  XtUnmanageChild(remove);  /* scrub HELP button */ 
    
  XtManageChild(dialog);
  XtPopup(XtParent(dialog), XtGrabNone);
}

/*----------------------------------------------------*/
void info_pop_up(Widget cascade_button, char *text, 
                 XmPushButtonCallbackStruct *cbs)
/*----------------------------------------------------*/
{   
  Widget dialog;
  XmString xm_string;
  extern void info_activate();
  Arg args[2];
  int n;

  /* label the dialog */
  xm_string = XmStringCreateSimple(text);

  n=0;
  XtSetArg(args[n], XmNmessageString, xm_string); n++;
  /* set up default button for OK callback */
  XtSetArg(args[n], XmNdefaultButtonType, 
           XmDIALOG_OK_BUTTON); n++;

   
  /* Create the InformationDialog as child of 
       cascade_button passed in */
  dialog = XmCreateInformationDialog(cascade_button, 
                                     "info", args, n);
    
  ScrubDial(dialog, XmDIALOG_CANCEL_BUTTON);
  ScrubDial(dialog, XmDIALOG_HELP_BUTTON);

  XmStringFree(xm_string);

  XtManageChild(dialog);
  XtPopup(XtParent(dialog), XtGrabNone);
}

/*-------------------------------------------------*/
void quit_pop_up(Widget cascade_button, char *text, 
                 XmPushButtonCallbackStruct *cbs)
/*-------------------------------------------------*/
{   
  Widget dialog;
  XmString xm_string;
  void quit_activate();
  Arg args[1];
  int n;

  /* label the dialog */
  xm_string = XmStringCreateSimple(text);

  n=0;
  XtSetArg(args[n], XmNmessageString, xm_string); n++;
  /* set up default button for cancel callback */
  XtSetArg(args[n], XmNdefaultButtonType, 
           XmDIALOG_CANCEL_BUTTON); n++;
  /* Create the WarningDialog */
  dialog = XmCreateWarningDialog(cascade_button, "quit", 
                                 args, n);
    
  ScrubDial(dialog, XmDIALOG_HELP_BUTTON);

  XmStringFree(xm_string);

  XtAddCallback(dialog, XmNokCallback, quit_activate, 
                NULL);

  XtManageChild(dialog);
  XtPopup(XtParent(dialog), XtGrabNone);
}

/*-----------------------------------*/
void ScrubDial(Widget wid, int dial)
/*-----------------------------------*/
/* routine to remove a DialButton from a Dialog */
{  
  Widget remove;

  remove = XmMessageBoxGetChild(wid, dial);
  XtUnmanageChild(remove);
}

/*---------------------------------------------------------*/
void prompt_activate(Widget widget, XtPointer client_data,
                     XmSelectionBoxCallbackStruct *selection)
/*---------------------------------------------------------*/
/* callback function for Prompt activate */
{   
  Widget dialog;
  Arg args[2];
  XmString xm_string;
  int n;

  /* compose InformationDialog output string */
  /* selection->value holds XmString entered to prompt */
    
  xm_string = XmStringCreateSimple("You typed: ");
  xm_string = XmStringConcat(xm_string,selection->value);

  n=0;
  XtSetArg(args[n], XmNmessageString, xm_string); n++;
  /* set up default button for OK callback */
  XtSetArg(args[n], XmNdefaultButtonType, 
           XmDIALOG_OK_BUTTON);  n++;
  /* Create the InformationDialog to echo 
       string grabbed from prompt */
  dialog = XmCreateInformationDialog(top_wid, 
                                     "prompt_message", args, n);
    
  ScrubDial(dialog, XmDIALOG_CANCEL_BUTTON);
  ScrubDial(dialog, XmDIALOG_HELP_BUTTON);

  XtManageChild(dialog);
  XtPopup(XtParent(dialog), XtGrabNone);
}

/*---------------------------------*/
void quit_activate(Widget dialog)
/*---------------------------------*/
/* callback routines for quit ok dialog */
{
  printf("Quit Ok was pressed.\n");
  exit(0);
}