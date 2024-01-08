

def login_message(name):
    form_message = "LOGIN|" + name
    return form_message


def find_game_message(name):
    form_message = "FIND_GAME|" + name
    return form_message


def start_game_message(name):
    form_message = "START_GAME|" + name
    return form_message


def move_message(name, move):
    form_message = "GAME_MOVE|" + str(move) + "|" + name
    print(form_message)
    return form_message


def leave_game_message(name):
    form_message = "LEAVE_GAME|" + name
    return form_message


def logout_message(name):
    form_message = "LOGOUT|" + name
    return form_message


def message_valid(messages, name):

    if messages[0] == "LOGIN":
        if messages[1] != "ERR":
            return False

    elif messages[0] != name:
        return False
    else:
        return True
def parser(message):
    messages = message.split("|")
    return messages