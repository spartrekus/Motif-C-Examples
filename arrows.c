 
#include <Xm/Xm.h> 
#include <Xm/PushB.h> 
#include <Xm/ArrowB.h>
#include <Xm/Form.h>

/* Prototype callback fns */
void north(Widget , XtPointer , 
	          XmPushButtonCallbackStruct *), 
     south(Widget , XtPointer , 
	          XmPushButtonCallbackStruct *), 
     east(Widget , XtPointer , 
	          XmPushButtonCallbackStruct *), 
     west(Widget , XtPointer , 
	          XmPushButtonCallbackStruct *), 
     quitb(Widget , XtPointer , 
	          XmPushButtonCallbackStruct *); 



int main(int argc, char **argv)
{
    XtAppContext app;
    Widget top_wid, form,
           arrow1, arrow2, 
           arrow3, arrow4,           
           quit;

    top_wid = XtVaAppInitialize(&app, "Multi Widgets",
                 NULL, 0, &argc, argv, NULL, NULL);

  
    form = XtVaCreateWidget("form", xmFormWidgetClass, top_wid,
                 XmNfractionBase,     3,
	                NULL);

    arrow1 = XtVaCreateManagedWidget("arrow1",
	                xmArrowButtonWidgetClass, form,
	                XmNtopAttachment,    XmATTACH_POSITION,
	                XmNtopPosition,      0,
	                XmNbottomAttachment, XmATTACH_POSITION,
	                XmNbottomPosition,   1,
	                XmNleftAttachment,   XmATTACH_POSITION,
	                XmNleftPosition,     1,
	                XmNrightAttachment,   XmATTACH_POSITION,
	                XmNrightPosition,    2,
	                XmNarrowDirection,   XmARROW_UP,
	                NULL);

    arrow2 = XtVaCreateManagedWidget("arrow2",
	                xmArrowButtonWidgetClass, form,
	                XmNtopAttachment,    XmATTACH_POSITION,
	                XmNtopPosition,      1,
	                XmNbottomAttachment, XmATTACH_POSITION,
	                XmNbottomPosition,   2,
	                XmNleftAttachment,   XmATTACH_POSITION,
	                XmNleftPosition,     0,
	                XmNrightAttachment,   XmATTACH_POSITION,
	                XmNrightPosition,    1,
	                XmNarrowDirection,   XmARROW_LEFT,
	                NULL);

    arrow3 = XtVaCreateManagedWidget("arrow3",
	                xmArrowButtonWidgetClass, form,
	                XmNtopAttachment,    XmATTACH_POSITION,
	                XmNtopPosition,      1,
	                XmNbottomAttachment, XmATTACH_POSITION,
	                XmNbottomPosition,   2,
	                XmNleftAttachment,   XmATTACH_POSITION,
	                XmNleftPosition,     2,
	                XmNrightAttachment,   XmATTACH_POSITION,
	                XmNrightPosition,    3,
	                XmNarrowDirection,   XmARROW_RIGHT,
	                NULL);

   arrow4 = XtVaCreateManagedWidget("arrow4",
	                xmArrowButtonWidgetClass, form,
	                XmNtopAttachment,    XmATTACH_POSITION,
	                XmNtopPosition,      2,
	                XmNbottomAttachment, XmATTACH_POSITION,
	                XmNbottomPosition,   3,
	                XmNleftAttachment,   XmATTACH_POSITION,
	                XmNleftPosition,     1,
	                XmNrightAttachment,   XmATTACH_POSITION,
	                XmNrightPosition,    2,
	                XmNarrowDirection,   XmARROW_DOWN,
	                NULL);
	
   quit =XtVaCreateManagedWidget("Quit",
	                xmPushButtonWidgetClass, form,
	                XmNtopAttachment,    XmATTACH_POSITION,
	                XmNtopPosition,      1,
	                XmNbottomAttachment, XmATTACH_POSITION,
	                XmNbottomPosition,   2,
	                XmNleftAttachment,   XmATTACH_POSITION,
	                XmNleftPosition,     1,
	                XmNrightAttachment,   XmATTACH_POSITION,
	                XmNrightPosition,    2,
	                NULL); 

    /* add callback functions */
    
    XtAddCallback(arrow1, XmNactivateCallback, north, NULL);
    XtAddCallback(arrow2, XmNactivateCallback, west, NULL);
    XtAddCallback(arrow3, XmNactivateCallback, east, NULL);
    XtAddCallback(arrow4, XmNactivateCallback, south, NULL);
    XtAddCallback(quit, XmNactivateCallback, quitb, NULL);

    XtManageChild(form);
    XtRealizeWidget(top_wid);
    XtAppMainLoop(app); }


    /* CALLBACKS */ 

void north(Widget w, XtPointer client_data, 
	          XmPushButtonCallbackStruct *cbs) 

    { printf("Going North\n");
    }

void west(Widget w, XtPointer client_data, 
	         XmPushButtonCallbackStruct *cbs) 

    { printf("Going West\n");
    }

void east(Widget w, XtPointer client_data, 
	         XmPushButtonCallbackStruct *cbs) 

    { printf("Going East\n");
    }


void south(Widget w, XtPointer client_data, 
	          XmPushButtonCallbackStruct *cbs)

    { printf("Going South\n");
    }

void quitb(Widget w, XtPointer client_data, 
	          XmPushButtonCallbackStruct *cbs)

    { printf("quit button pressed\n");
      exit(0); 
    }
