#include <gtk/gtk.h>

																				//compile with gcc -Wall -g window.c -o window `pkg-config --cflags --libs gtk+-3.0`
int main(int argc, char *argv[])
{
	GtkWidget *window;															//this declares windows as type GtkWidget*
	gtk_init(&argc, &argv);														//this initializes gtk

window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 									//gtk_window_new() sets the widget to type GtkWindow* it takes one parameter which is the window type. 
											  									//the 2 window types are GTK_WINDOW_TOPLEVEL and GTK_WINDOW_POPUP. 
gtk_window_set_title(GTK_WINDOW(window), "New Window"); 						//sets a window title. gtk_window_set_title takes the 2 parameters,
																				//GtkWindow *window and const gchar *title 
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 				//opens the window in the center of the screen, this function takes 2 parameters, 
																 				//the parameters are GtkWindow* and GtkWindowPosition.

gtk_container_set_border_width(GTK_CONTAINER(window), 5); 						//sets the border width of the window, this takes 2 parameters, the GtkWidget* and the width respectively.


gtk_widget_set_size_request (window, 400, 400);									/*sets the size of the window, this is optional
														   						if this is not included in the code then the window will automatically size itself
														   						this function takes 3 parameters, the GtkWidget* to be sized, the length and the width respectively.*/  

g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);  //this line add the callback for the window to be closed when you click the x in the corner
 									  											//the function g_signal_connect is defined as g_signal_connect(instance, detailed_signal, c_handler, data)
									   											//you will see more examples of this in coming tutorials 

gtk_widget_show_all(window); 													//shows all widgets within the GtkWidget *window; this function takes one parameter with the data type GtkWidget

gtk_main();																		//gtk main is a void function, this is the main loop of GTK. 
}