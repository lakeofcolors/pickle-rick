import threading
from store import ClientStore

class BaseHandler:
    def __init__(self, client, addr):
        self.addr = addr
        self.client = client
        self.store = ClientStore()

    def _init_client(self):
        recv = self.client.recv(10)
        self.store.add_client(self.client, self.addr)

    def handle(self):
        self._init_client()
