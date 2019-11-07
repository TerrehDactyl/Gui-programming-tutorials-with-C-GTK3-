#include <gtk/gtk.h>
//compile with gcc -Wall -g menu.c -o menu `pkg-config --cflags --libs gtk+-3.0`
void createmenu(GtkWidget *menu, GtkWidget *root_menu, gchar *menuarray[], int arraylen, void *callback[]);
void main_callback(GtkWidget *submenu_items, void *callback);
void menuitem1();
void menuitem2();
void menuitem3();
void menuitem4();

int main(int argc, char *argv[])
{
GtkWidget *window; //widget for the window
GtkWidget *root_menu; //widget for the root menu 
GtkWidget *menu_bar; //widget to hold the widget that holds the root menu
GtkWidget *menu; //widget that holds the submenu

gtk_init(&argc, &argv); //starting gtk 

window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //creates toplevel window
gtk_window_set_title(GTK_WINDOW(window), "TCalc v.1.0"); //sets a window title 
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); //opens the window in the center of the screen
gtk_container_set_border_width(GTK_CONTAINER(window), 5); //sets the border size of the window
g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);//this line allows the close button (x) at the top of the screen to terminate the program

                                                                                  //it is used so that each item can fill the array and you can use the whole array for the label, 
                                                                                  //using root_menu_array[i] will not work as it makes a pointer out of an integer without a cast
gchar *root_menu_array[1] = {"root_menu"};                                        //array for the root menu
gchar *menuarray[4] = {"Item 1", "Item 2", "Item 3", "Item 4"};                   //array for the menu items
void *callback[] = {menuitem1, menuitem2, menuitem3, menuitem4};
                                                
menu_bar = gtk_menu_bar_new ();                                                  //initializes the menubar as a new menu bar
char buf[128];
sprintf (buf, "%s", root_menu_array[0]);                                        //copies the root menu array to the buffer 
root_menu = gtk_menu_item_new_with_label (buf);                                  // sets the label for the root menu 
gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), root_menu);                   //adds the root menu to the menu bar

int arraylen = 4;                                                             //this is to keep track of the position of each menu item and their callbacks 
menu = gtk_menu_new();                                                     //this creates a new submenu named sub_menu 
createmenu(menu, root_menu, menuarray, arraylen, callback);


gtk_container_add(GTK_CONTAINER(window), menu_bar); //adds the menubar to the window 

gtk_widget_show_all(window); //shows all widgets in the window

gtk_main();//gtk main, this is the main loop of GTK

}

void createmenu(GtkWidget *menu, GtkWidget *root_menu, gchar *menuarray[], int arraylen, void *callback[])
{
	GtkWidget *menu_items; //widget that holds the submenu items
	char buf[128];
for(int j = 0; j<arraylen; j++)                                                       
{                                                                              /*this loop is the same as the lines above but a much easier way to create a menu, there will be another tutorial that 
                                                                                touches on this  more in the future*/ 
	sprintf (buf, "%s", menuarray[j]);
	menu_items = gtk_menu_item_new_with_label(buf);
	main_callback(menu_items, callback[j]);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_items);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(root_menu), menu);
}
}

void main_callback(GtkWidget *submenu_items, void *callback)                 //this is the main callback switch, you feed it the widget and the position and it switches between them to activate their callbacks
{
 g_signal_connect(submenu_items, "activate", G_CALLBACK(callback), NULL);
}
void menuitem1()                                                 //these are the callback functions for each menu option
{
g_print("This is button 1\n");
}

void menuitem2()                                                 //these are the callback functions for each menu option
{
g_print("This is button 2\n");
}

void menuitem3()                                                 //these are the callback functions for each menu option
{
g_print("This is button 3\n");
}

void menuitem4()                                                 //these are the callback functions for each menu option
{
g_print("This is button 4\n");
}

