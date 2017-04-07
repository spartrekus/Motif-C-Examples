#include <Xm/Xm.h> 
#include <Xm/PushB.h> 
#include <Xm/Form.h> 
 
  
main (int argc, char **argv)  
	 
{ XtAppContext app;
  Widget   top_wid, form,
	          button1, button2, 
           button3, button4;
  int n=0;
 
	
  top_wid = XtVaAppInitialize(&app, "Form2",
        NULL, 0, &argc, argv, NULL, NULL);
        
  /* create form and child buttons */
  
  form = XtVaCreateManagedWidget("form", xmFormWidgetClass, 
      top_wid, NULL);
  
  button1 = XtVaCreateManagedWidget("Button 1",
      xmPushButtonWidgetClass, form,
      /* attach to top, left of form */
      XmNtopAttachment, XmATTACH_FORM, 
      XmNleftAttachment, XmATTACH_FORM,
      XmNrightAttachment, XmATTACH_POSITION,
      XmNrightPosition, 50,
      XmNbottomAttachment, XmATTACH_POSITION,
      XmNbottomPosition, 50,
      NULL); 
  
 	
  button2 = XtVaCreateManagedWidget("Button 2",
      xmPushButtonWidgetClass, form,
      XmNbottomAttachment, XmATTACH_FORM,
      XmNleftAttachment, XmATTACH_FORM,
      XmNrightAttachment, XmATTACH_POSITION,
      XmNrightPosition, 50,
      XmNtopAttachment, XmATTACH_POSITION,
      XmNtopPosition, 50,
      NULL);
  
  button3 = XtVaCreateManagedWidget("Button 3",
      xmPushButtonWidgetClass, form,
      XmNtopAttachment, XmATTACH_FORM,
      XmNrightAttachment, XmATTACH_FORM,
      XmNleftAttachment, XmATTACH_POSITION,
      XmNleftPosition, 50,
      XmNbottomAttachment, XmATTACH_POSITION,
      XmNbottomPosition, 50,
      NULL);

  
  button4 = XtVaCreateManagedWidget("Button 4",
      xmPushButtonWidgetClass, form,
      XmNbottomAttachment, XmATTACH_FORM,
      XmNrightAttachment, XmATTACH_FORM,
      XmNleftAttachment, XmATTACH_POSITION,
      XmNleftPosition, 50,
      XmNtopAttachment, XmATTACH_POSITION,
      XmNtopPosition, 50,
      NULL);

 
  XtRealizeWidget (top_wid); 
  XtAppMainLoop (app); 
}
