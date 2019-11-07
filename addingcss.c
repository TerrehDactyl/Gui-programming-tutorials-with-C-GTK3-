#include <gtk/gtk.h>

//compile with gcc -Wall -g addingcss.c -o addingcss `pkg-config --cflags --libs gtk+-3.0`
//for this code to work properly, you must download the styles.css file from the repository and have it in the same folder as this file.
/* the following lines are used to add a style provider and a style context(selection for what css code in the file you want to use)
GtkCssProvider* Provider = gtk_css_provider_new();
GtkStyleContext *buttoncontext;
gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(Provider), "Styles.css", NULL);
windowcontext = gtk_widget_get_style_context(button);
gtk_style_context_add_class(buttoncontext, "window_style");
gtk_style_context_add_provider (buttoncontext,GTK_STYLE_PROVIDER(Provider), GTK_STYLE_PROVIDER_PRIORITY_USER); */

void main_callback(GtkWidget *button, void *callback[]);                                      //these are just the decalarations for the user functions 
void button1_callback();                                                                  // we will user later in the program there's one for the main callback switch
void button2_callback();                                                                  // then one for each button
void button3_callback();
void button4_callback();

int main(int argc, char *argv[])
{
	GtkWidget *window;															//this declares windows as type GtkWidget*
	GtkWidget *grid;
	GtkWidget *button;
	GtkCssProvider* Provider = gtk_css_provider_new();
	GtkStyleContext *buttoncontext;
	gtk_init(&argc, &argv);														//this initializes gtk

window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 									//gtk_window_new() sets the widget to type GtkWindow* it takes one parameter which is the window type. 
											  									//the 2 window types are GTK_WINDOW_TOPLEVEL and GTK_WINDOW_POPUP. 
gtk_window_set_title(GTK_WINDOW(window), "New Window"); 						//sets a window title. gtk_window_set_title takes the 2 parameters,
																				//GtkWindow *window and const gchar *title 
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 				//opens the window in the center of the screen, this function takes 2 parameters, 
																 				//the parameters are GtkWindow* and GtkWindowPosition.

gtk_container_set_border_width(GTK_CONTAINER(window), 5); 						//sets the border width of the window, this takes 2 parameters, the GtkWidget* and the width respectively.


g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);  //this line add the callback for the window to be closed when you click the x in the corner
 									  											//the function g_signal_connect is defined as g_signal_connect(instance, detailed_signal, c_handler, data)
									   											//you will see more examples of this in coming tutorials 

																							//BUTTONS =D The following for loops are for creating simple buttons 
int position = 0;
gchar *buttonarray[4] = {"Button1", "Button2", "Button3", "Button4"};
void *callback[] = {button1_callback, button2_callback, button3_callback, button4_callback};

grid = gtk_grid_new(); 																		//sets the table widget as a 4x4 arrangement without autosizing
for (int i=0; i < 2; i++) 																	//for loop for the rows
{
	for (int j=0; j < 2; j++) 																//for loop for the columns
	{
	button = gtk_button_new_with_label(buttonarray[position]); 								//sets each button label to the respective button 
	gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1); 									//sets the defaults for creating each table button
	gtk_widget_set_size_request(button, 40, 40); 											//sets the size of the buttons
	main_callback(button, callback[position]); 		                                                //attaches the button to the respective callback
	buttoncontext = gtk_widget_get_style_context(button);                                   //sets windowcontext as a style context for the button widget
	gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(Provider), "Styles.css", NULL);        //loads the css file 
	gtk_style_context_add_provider (buttoncontext,GTK_STYLE_PROVIDER(Provider), GTK_STYLE_PROVIDER_PRIORITY_USER); //adds the provider to the button context
	gtk_style_context_add_class(buttoncontext, "window_style");                             //sets which style in the CSS file is to be used for the button context
	position++; 																			//changes the position 
	}
}

gtk_container_add(GTK_CONTAINER(window), grid); 											//adds the vbox to the window 

gtk_widget_show_all(window); 												            	//shows all widgets within the GtkWidget *window; this function takes one parameter with the data type GtkWidget

gtk_main();																		            //gtk main is a void function, this is the main loop of GTK. 
}

void main_callback(GtkWidget *button, void *callback[])                           //this function is used to attach the callbacks to their respective buttons
{
	g_signal_connect(button, "clicked", G_CALLBACK(callback), NULL);//these lines add the callback for the window to be closed when you click the x in the corner
}
void button1_callback()                                     //these functions are void functions, they just print which button is which on the console. g_print is essentially printf.
{
	g_print("This is button 1\n");
}

void button2_callback()
{
	g_print("This is button 2\n");
}

void button3_callback()
{
	g_print("This is button 3\n");
}

void button4_callback()
{
	g_print("This is button 4\n");
}
