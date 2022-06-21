import socket
from server import TCPServer
import threading
from executer import ExecuterService


if __name__ == '__main__':
    executer = ExecuterService()
    thread = threading.Thread(target=executer.run)
    thread.start()


    server = TCPServer()
    server.start()
