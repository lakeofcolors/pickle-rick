import socket
import logging
from handler import BaseHandler
import threading


logger = logging.getLogger(__name__)


class TCPServer:
    def __init__(self, addr: int = "0.0.0.0", port: int = 8080):
        self._server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._server.bind((addr, port))
        self._server.listen(5)

    def start(self):
        while True:
            client, addr = self._server.accept()
            handler = BaseHandler(client, addr)
            thread = threading.Thread(target=handler.handle)
            thread.start()
