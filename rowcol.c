#include <Xm/PushB.h> 
#include <Xm/RowColumn.h>

main(int argc, char **argv) 
    
{
    Widget top_widget, rowcol;
    XtAppContext app;

    top_widget = XtVaAppInitialize(&app, "rowcol", NULL, 0, 
        &argc, argv, NULL, NULL);

    rowcol = XtVaCreateManagedWidget("rowcolumn",
        xmRowColumnWidgetClass, top_widget, NULL);

    (void) XtVaCreateManagedWidget("button 1",
        xmPushButtonWidgetClass, rowcol, NULL);

    (void) XtVaCreateManagedWidget("button 2",
        xmPushButtonWidgetClass, rowcol, NULL);

    (void) XtVaCreateManagedWidget("button 3",
        xmPushButtonWidgetClass, rowcol, NULL);
        
    (void) XtVaCreateManagedWidget("button 4",
        xmPushButtonWidgetClass, rowcol, NULL);

    XtRealizeWidget(top_widget);
    XtAppMainLoop(app); 
}