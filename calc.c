#include <gtk/gtk.h>

// Function to handle button clicks
void button_clicked(GtkWidget *widget, gpointer data) {
    // Get the button label (which contains the number or operator)
    const gchar *button_label = gtk_button_get_label(GTK_BUTTON(widget));

    // Append the label to the entry field
    GtkEntry *entry = GTK_ENTRY(data);
    gtk_entry_append_text(entry, button_label);
}

// Function to handle calculation
void calculate(GtkWidget *widget, gpointer data) {
    // Get the expression from the entry field
    const gchar *expression = gtk_entry_get_text(GTK_ENTRY(data));

    // Evaluate the expression
    double result = eval_expr(expression);

    // Display the result in the entry field
    char result_str[20];
    snprintf(result_str, sizeof(result_str), "%.6f", result);
    gtk_entry_set_text(GTK_ENTRY(data), result_str);
}

// Function to evaluate the expression
double eval_expr(const char *expr) {
    // You can implement a proper expression evaluation logic here
    // For simplicity, let's assume a simple calculator with basic operations
    double result = 0.0;
    sscanf(expr, "%lf", &result);
    return result;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create the entry field
    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1.0);  // Align text to the right
    gtk_container_add(GTK_CONTAINER(window), entry);

    // Create the grid for buttons
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Array of button labels
    const char *button_labels[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
    };

    // Attach buttons to the grid
    for (int i = 0; i < 16; i++) {
        GtkWidget *button = gtk_button_new_with_label(button_labels[i]);
        gtk_grid_attach(GTK_GRID(grid), button, i % 4, i / 4, 1, 1);

        // Connect signals for button clicks
        if (i != 14) {  // Exclude "=" from button clicks
            g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), entry);
        } else {
            g_signal_connect(button, "clicked", G_CALLBACK(calculate), entry);
        }
    }

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}
