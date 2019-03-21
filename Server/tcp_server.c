/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ispirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:54:35 by ispirido          #+#    #+#             */
/*   Updated: 2018/03/02 18:31:25 by ispirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int	main()
{
	char server_message[256] = "You have reached the server!"; //hold the data we’re going to send to all the clients.

	//create the server socket.
	int server_socket; //to hold a return value of the socket call.
	server_socket = socket(AF_INET, SOCK_STREAM, 0); //make the socket call.

	//define the server address.
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); //could be any address because it stays on the local machine.
	server_address.sin_addr.s_addr = INADDR_ANY; //actual address

	//bind the socket to our specified IP and port.
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)); //now the socket is bound to an IP port so we can listen for connections using the listen function.

	listen(server_socket, 5); //allows to listen for connections.

	int client_socket; //int to hold the client socket, once we’re able to listen for the connections -> start accepting connections.
	client_socket = accept(server_socket, NULL, NULL); //allows to get another socket let's us to perform these functions on the client side.

	//send message.
	send(client_socket, server_message, sizeof(server_message), 0);

	//close the socket.
	close(server_socket);

	return 0;
}
