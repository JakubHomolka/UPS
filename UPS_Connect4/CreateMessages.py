
# Funkce pro vytvoření přihlašovací zprávy
def login_message(name):
    form_message = "LOGIN|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro hledání hry
def find_game_message(name):
    form_message = "FIND_GAME|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro spuštění hry
def start_game_message(name):
    form_message = "START_GAME|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro tah ve hře
def move_message(name, move):
    form_message = "GAME_MOVE|" + str(move) + "|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro opuštění hry
def leave_game_message(name):
    form_message = "LEAVE_GAME|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro odhlášení
def logout_message(name):
    form_message = "LOGOUT|" + name + "\n"
    return form_message


# Funkce pro vytvoření zprávy pro pong
def ping_message(name):
    message = "PONG|" + name + "\n"
    return message


# Funkce pro validaci přihlášení
def message_valid(messages, name):

    if messages[0] == "LOGIN":
        if messages[1] != "ERR":
            return False

    elif messages[0] != name:
        return False
    else:
        return True


# Funkce pro parsování zpráv
def parser(message):
    messages = message.split("|")
    return messages
