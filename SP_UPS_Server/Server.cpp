//
// Created by David Kuta on 26.11.2021.
//

#include "Server.h"



using namespace std;
fd_set Server::client_socks, Server::tests;
struct sockaddr_in Server::peer_addr, Server::client, Server::server;
int MAX_INVALID_MESSAGES = 3;
const int MAX_MSG_SIZE = 1024;

/**
 * Server initilization
 */
int Server::init(string ip, int port) {
    cout << "IP: " + ip + " Port: " + to_string(port) << endl;

    //Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        cout << "Could not create socket" << endl;
        return -1;
    }

    cout << "Socket created" << endl;

    //set port release
    int enable = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        cout << "setsockopt(REUSEADDR) failed" << endl;
    }



    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;

    if (ip.compare("localhost") == 0) {
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
    } else if (ip.compare("INADDR_ANY") == 0) {
        server.sin_addr.s_addr = INADDR_ANY;
    } else {
        in_addr_t inAddr = inet_addr(ip.data());
        if (inAddr == -1) {
            cout << "Invalid IP adddress" << endl;
            return -1;
        } else {
            server.sin_addr.s_addr = inAddr;
        }
    }

    server.sin_port = htons(port);

    //Bind
    if (::bind(server_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        cout << "Bind failed. Error" << endl;
        return -1;
    }

    cout << "Bind done" << endl;

    //Listen
    if (listen(server_socket, 3) < 0) {
        cout << "Listen failed. Error" << endl;
        return -1;
    }

    //Accept and incoming connection
    cout << "Server is ready!" << endl;

    return 0;
}


int Server::listenConnections() {

    cout << "Start listening" << endl;

    FD_ZERO(&client_socks);
    FD_SET(server_socket, &client_socks);

    int fd;
    int return_value;

    while (1) {

        tests = client_socks;

        return_value = select(FD_SETSIZE, &tests, (fd_set *) NULL, (fd_set *) NULL, (struct timeval *) NULL);

        if (return_value < 0) {
            cout << "Select error\n" << endl;
            return -1;
        }

        int a2read;
        char cbuf[1024];
        // vynechavame stdin, stdout, stderr
        for (fd = 3; fd < FD_SETSIZE; fd++) {

            // je dany socket v sade fd ze kterych lze cist ?
            if (FD_ISSET(fd, &tests)) {

                // je to server socket ? prijmeme nove spojeni
                if (fd == server_socket) {
                    int c = sizeof(struct sockaddr_in);
                    client_socket = accept(server_socket, (struct sockaddr *) &client, (socklen_t *) &c);
                    if (client_socket < 0) {
                        cout << "Accept error" << endl;
                        return -1;
                    }

                    FD_SET(client_socket, &client_socks);
                    cout << "Connect new client" << endl;

                    char *ip = inet_ntoa(client.sin_addr);

                    ClientManager::create_unlogged_player(ip, client_socket);

                } else // client
                {
                    // pocet bajtu co je pripraveno ke cteni
                    ioctl(fd, FIONREAD, &a2read);

                    if (a2read > MAX_MSG_SIZE) {
                        cout << "Přijatá zpráva překračuje maximální povolenou velikost. Odpojování klienta." << endl;
                        disconnect(fd);
                        continue; // Přeskočení zbytku smyčky pro tento socket
                    }

                    // mame co cist
                    if (a2read > 0) {

                        Player *pl = ClientManager::get_logged_player_by_socket(fd);


                        //clearbuffer
                        memset(cbuf, 0, 1024);

                        recv(fd, &cbuf, 1024, 0);

                        string msg(cbuf);


                        if (pl == nullptr) {
                            pl = ClientManager::get_unlogged_player(fd);
                        }
                        Request::resolve(pl, msg);

                        msg.clear();


                        if (pl->invalid_message_counter >= MAX_INVALID_MESSAGES) {
                            cout << "Maximum invalid messages reached. Player: " + pl->name + " socket: " +
                                    to_string(pl->socket) << endl;
                            Response::sendErrorToPlayer(pl,"END|MAX_INVALID_MESSAGES_REACHED");
                            auto game = GameManager::gameExists(pl->game_id);
                            if (game != nullptr) {
                                if(game->gameState == "WAITING") GameManager::playerDequeue(pl);
                                if(game->gameState == "RUNNING") GameManager::playerLeaveGame(pl);
                            }
                            disconnect(fd);
                        }


                    }
                        // if gui is closed by ctrl+c
                    else if (a2read == 0) {
                        disconnect(fd);

                        cout << "Something bad happened on client" << endl;
                    } else {
                        close(fd);
                        FD_CLR(fd, &client_socks);

                        cout << "Something bad happened on ioctl" << endl;
                    }

                }
            }
        }
    }
}

void Server::disconnect(int socket) {
    Player *pl = ClientManager::get_logged_player_by_socket(socket);

    if (pl == nullptr) {
        pl = ClientManager::get_unlogged_player(socket);
    }

    pl->socket = -1;
    pl->connected = -1;
    auto game = GameManager::gameExists(pl->game_id);
    if (game != nullptr) {
        GameManager::notifyOponent(pl, "DISCON");
    }

    closeSocket(socket);

    if (pl->state.compare("NEW") == 0) {
        ClientManager::unlogged_players.erase(socket);
    }
    if(pl->invalid_message_counter >= MAX_INVALID_MESSAGES){
        ClientManager::logged_players.erase(pl->name);
    }

}


/**
 * Method to close specific socket
 */
void Server::closeSocket(int socket) {
    cout << "Closing socket with ID: " + to_string(socket) << endl;

    close(socket);
    FD_CLR(socket, &client_socks);

    cout << "Socket with ID: " + to_string(socket) + " has been closed" << endl;
}
