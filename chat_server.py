import socket
import threading

# Server configuration
host = '127.0.0.1'
port = 55555

# Create a socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()

# List to store connected clients
clients = []
nicknames = []


# Broadcast messages to all clients
def broadcast(message):
    for client in clients:
        client.send(message)


# Handle individual client connections
def handle(client):
    while True:
        try:
            # Broadcast the received message
            message = client.recv(1024)
            broadcast(message)
        except:
            # Remove and close the connection of a disconnected client
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} has left the chat.'.encode('utf-8'))
            nicknames.remove(nickname)
            break


# Accept new connections and start handling them
def receive():
    while True:
        client, address = server.accept()
        print(f"Connection established with {str(address)}")

        # Ask and store the client's nickname
        client.send('NICK'.encode('utf-8'))
        nickname = client.recv(1024).decode('utf-8')
        nicknames.append(nickname)
        clients.append(client)

        # Broadcast the new connection to all clients
        print(f'Nickname of the client is {nickname}')
        broadcast(f'{nickname} has joined the chat.'.encode('utf-8'))
        client.send('Connected to the server!'.encode('utf-8'))

        # Start handling the client in a new thread
        thread = threading.Thread(target=handle, args=(client,))
        thread.start()


# Start the server
print("Server is listening...")
receive()

