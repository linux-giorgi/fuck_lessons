import socket
import threading
import tkinter as tk
from tkinter import simpledialog

# Configure the client
host = '127.0.0.1'
port = 55555

# Create a socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))


# Request and set the user's nickname
def set_nickname():
    while True:
        nickname = simpledialog.askstring("Nickname", "Please choose a nickname:")
        if nickname:
            client.send(nickname.encode('utf-8'))
            break


# Receive and display messages from the server
def receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            messages_listbox.insert(tk.END, message)
        except:
            # Handle a case where the client is disconnected
            print("An error occurred!")
            client.close()
            break


# Send messages to the server
def send(event=None):
    message = my_message.get()
    client.send(message.encode('utf-8'))
    if message.lower() == '!exit':
        client.close()
        window.quit()


# GUI setup
window = tk.Tk()
window.title("Chat Application")

messages_listbox = tk.Listbox(window, height=15, width=50)
messages_listbox.pack(padx=20, pady=20)

my_message = tk.StringVar()
my_message.set("Type your message here.")

entry_field = tk.Entry(window, textvariable=my_message)
entry_field.bind("<Return>", send)
entry_field.pack(padx=20, pady=20)

send_button = tk.Button(window, text="Send", command=send)
send_button.pack(padx=20, pady=20)

# Start the receive thread
receive_thread = threading.Thread(target=receive)
receive_thread.start()

# Start the Tkinter main loop
set_nickname()
window.mainloop()

