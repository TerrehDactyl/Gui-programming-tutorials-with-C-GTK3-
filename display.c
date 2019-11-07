#include <gtk/gtk.h>

	GtkWidget *display;	
					
void callback(void);															//compile with gcc -Wall -g display.c -o display `pkg-config --cflags --libs gtk+-3.0`
int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;	
	GtkWidget *vbox;													//this declares windows as type GtkWidget*
	gtk_init(&argc, &argv);														//this initializes gtk

window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 									//gtk_window_new() sets the widget to type GtkWindow* it takes one parameter which is the window type. 
											  									//the 2 window types are GTK_WINDOW_TOPLEVEL and GTK_WINDOW_POPUP. 
gtk_window_set_title(GTK_WINDOW(window), "New Window"); 						//sets a window title. gtk_window_set_title takes the 2 parameters,
																				//GtkWindow *window and const gchar *title 
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 				//opens the window in the center of the screen, this function takes 2 parameters, 
																 				//the parameters are GtkWindow* and GtkWindowPosition.

gtk_container_set_border_width(GTK_CONTAINER(window), 5); 						//sets the border width of the window, this takes 2 parameters, the GtkWidget* and the width respectively.

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);                                //creates a vbox without autosizing 
display = gtk_text_view_new (); //sets the display widget as a text display 
gtk_widget_set_size_request(display, 150, 40); //sets the size of the display 


button = gtk_button_new_with_label("This is a button");                         //creates a new button with a label
g_signal_connect(button, "clicked", G_CALLBACK(callback), NULL);                //attaches the callback to the button 
gtk_container_add(GTK_CONTAINER(window), vbox);
gtk_box_pack_start(GTK_BOX(vbox), display, FALSE, FALSE, 0); 
gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);  


g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);  //this line add the callback for the window to be closed when you click the x in the corner
 									  											//the function g_signal_connect is defined as g_signal_connect(instance, detailed_signal, c_handler, data)
									   									

gtk_widget_show_all(window); 													//shows all widgets within the GtkWidget *window; this function takes one parameter with the data type GtkWidget

gtk_main();																		//gtk main is a void function, this is the main loop of GTK. 
}

void callback(void)                                                             //button callback, prints to the console that you clicked the button.
{
	GtkTextBuffer *buffer; //widget for the text 
	char buf[128] = {"test"}; 
	buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (display)); //sets the buffer widget to the text buffer of display
	gtk_text_buffer_set_text (buffer, buf, -1); //displays inputnum1 
}