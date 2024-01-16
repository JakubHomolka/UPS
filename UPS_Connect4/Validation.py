import re
from tkinter import messagebox


def validate_name(name):
    pattern = re.compile(r'^[a-z]+$')

    if pattern.match(name):
        return True
    else:
        messagebox.showerror("ERR","not valid name only lower case")
        return False


def validate_ip(ip):
    pattern = re.compile(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$')

    if pattern.match(ip) or ip.lower() == 'localhost':
        return True
    else:
        messagebox.showerror("ERR", "not valid address or localhost")
        return False


def validate_port(port):
    pattern = re.compile(r'^[1-9]\d*$')
    port_string = str(port)

    if pattern.match(port_string):
        return True
    else:
        messagebox.showerror("ERR","not valid port")
        return False

