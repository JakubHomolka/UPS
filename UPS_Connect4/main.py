import tkinter as tk

from LoginWin import LoginWin


# Hlavní vstupní bod aplikace, spouští přihlašovací okno
if __name__ == "__main__":
    root = tk.Tk()
    start = LoginWin(root)
    root.mainloop()
