import tkinter as tk
import CreateMessages as message_handler

# Třída pro lobby okno, vytváří uživatelské rozhraní pro čekací místnost hry
class LobbyWin:
    def __init__(self, parent, server, name):
        self.game_label = None
        self.opponent_label = None
        self.start_game_button = None
        self.find_game_button = None
        self.logout_game_button = None
        self.parent = parent
        self.server = server
        self.name = name
        self.game_number = None
        self.lob_window = None
        self.opponent = None
        self.state_opp = None

        self.lob_window = tk.Toplevel(self.parent)
        self.lob_window.title("Connect4 - Lobby")
        self.lob_window.protocol("WM_DELETE_WINDOW", self.end)

        self.game_label = tk.Label(self.lob_window, text="Game: ")
        self.game_label.pack()

        self.opponent_label = tk.Label(self.lob_window, text="Opponent: ")
        self.opponent_label.pack()

        self.state_opp = tk.Label(self.lob_window, text="State: ")
        self.state_opp.pack()

        self.find_game_button = tk.Button(self.lob_window, text="Find Game", command=self.find_game)
        self.find_game_button.pack()

        self.start_game_button = tk.Button(self.lob_window, text="Start Game", state=tk.DISABLED, command=self.start_game)
        self.start_game_button.pack()

        self.logout_game_button = tk.Button(self.lob_window, text="Logout", command=self.logout_message)
        self.logout_game_button.pack()

        self.leave_game_button = tk.Button(self.lob_window, text="Leave", command=self.leave_message)
        self.leave_game_button.pack()

        self.update_button_state()

    # Funkce pro zničení hlavního vlákna
    def end(self):
        self.parent.destroy()

    # Funkce pro odeslání zprávy pro opuštění hry
    def leave_message(self):
        leave_game_message = message_handler.leave_game_message(self.name)
        self.server.sendall(leave_game_message.encode())

    # Funkce pro odeslání zprávy pro odhlášení hráče
    def logout_message(self):
        logout_game_message = message_handler.logout_message(self.name)
        self.server.sendall(logout_game_message.encode())

    # Funkce pro nastavování zda lze spustit hru
    def update_button_state(self):
        if self.opponent is not None:
            self.start_game_button['state'] = tk.NORMAL
        else:
            self.start_game_button['state'] = tk.DISABLED

    # Funkce pro odeslání zprávy pro nalezení hry
    def find_game(self):
        find_game_message = message_handler.find_game_message(self.name)
        self.server.sendall(find_game_message.encode())

    # Funkce pro odeslání zprávy pro start hry
    def start_game(self):
        start_game_message = message_handler.start_game_message(self.name)
        self.server.sendall(start_game_message.encode())

    # Funkce pro nastavení čísla hry
    def update_info_game(self, game_number):
        self.game_number = game_number
        self.game_label.config(text=f"Game: {self.game_number}")

    # Funkce pro nastavení jména opponenta
    def update_info_opponent(self, opponent):
        self.opponent = opponent
        self.opponent_label.config(text=f"Opponent: {self.opponent}")
        self.update_button_state()

    # Funkce pro nastavení stavu opponenta
    def info_opp(self, state):
        self.state_opp.config(text=f"State: {state}")

    # Funkce pro zakrytí okna lobby
    def close_lobby_window(self):
        self.lob_window.withdraw()

    # Funkce pro zavření okna lobby
    def destroy_lobby_window(self):
        self.lob_window.destroy()
