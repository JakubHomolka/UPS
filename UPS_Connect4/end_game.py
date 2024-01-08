import tkinter as tk
import send_messages as message_handler


class EndGame:
    def __init__(self, parent, server, lob_window, game_window, name, end_message):
        self.parent = parent
        self.server = server
        self.name = name
        self.end_message = end_message
        self.lob_window = lob_window
        self.game_window = game_window
        self.leave_message = None
        self.message_label = None
        self.end_game_button = None
        self.logout_game_button = None
        self.end_game_window = tk.Toplevel(parent)
        self.end_game_window.title("Game End")
        self.parent.protocol("WM_DELETE_WINDOW", self.end)

        self.message_label = tk.Label(self.end_game_window, text=self.end_message)
        self.message_label.pack()

        self.end_game_button = tk.Button(self.end_game_window, text="Leave", command=self.end_game)
        self.end_game_button.pack()

        self.logout_game_button = tk.Button(self.end_game_window, text="Logout", command=self.logout)
        self.logout_game_button.pack()

    def end(self):
        self.end_game()

    def end_game(self):
        self.leave_message = message_handler.leave_game_message(self.name)
        self.server.sendall(self.leave_message.encode())

    def logout(self):
        logout_game_message = message_handler.logout_message(self.name)
        self.server.sendall(logout_game_message.encode())

    def destroy_window(self):
        self.end_game_window.destroy()
