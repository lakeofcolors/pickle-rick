from store import ClientStore


class ExecuterService:
    def __init__(self):
        self.store = ClientStore()

    def execute(self, command):
        for addr, client in self.store.clients.items():
            client.send(command.encode())
            recv = client.recv(1024)
            print(f"{addr}: {recv.decode()}")

    def run(self):
        print("Picle Ricle v0.0.1\n")
        while True:
            command = input(">>>")
            self.execute(command)
