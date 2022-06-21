from helpers import SingletonThreadMeta
from typing import Dict
import socket

class ClientStore(metaclass=SingletonThreadMeta):

    def __init__(self):
        self.clients: Dict[str, socket.socket] = dict()

    def add_client(self, conn, addr):
        ip = addr[0]
        self.clients[ip] = conn
        print(f"[*] {ip} is added to store")
