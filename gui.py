import tkinter as tk

def on_click(event):
    current_text = entry.get()
    button_text = event.widget.cget("text")

    if button_text == "=":
        try:
            result = eval(current_text)
            entry.delete(0, tk.END)
            entry.insert(tk.END, str(result))
        except Exception as e:
            entry.delete(0, tk.END)
            entry.insert(tk.END, "Error")

    elif button_text == "C":
        entry.delete(0, tk.END)

    else:
        entry.insert(tk.END, button_text)

# Create a basic tkinter window
window = tk.Tk()
window.title("Calculator")

# Entry widget to display input and output
entry = tk.Entry(window, font=('Arial', 18))
entry.grid(row=0, column=0, columnspan=4)

# Button layout
buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', 'C', '=', '+'
]

# Create buttons and assign the on_click function
row_val = 1
col_val = 0

for button_text in buttons:
    button = tk.Button(window, text=button_text, font=('Arial', 18), width=5, height=2)
    button.grid(row=row_val, column=col_val)
    button.bind("<Button-1>", on_click)  # Bind the left mouse click event
    col_val += 1

    if col_val > 3:
        col_val = 0
        row_val += 1

# Run the GUI application
window.mainloop()

