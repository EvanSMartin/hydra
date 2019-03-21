/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcp_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ispirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:04:59 by ispirido          #+#    #+#             */
/*   Updated: 2018/03/02 18:16:00 by ispirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h> // for defenitions about the socket functions.
#include <sys/socket.h> // for the socket functionality and the API to create sockets. 

#include	<netinet/in.h> // structures to store address information. in.h under netinet.

int main()
{
	// create a socket. (create one of the endpoints needed to create a network communication).
	int	network_socket; // int to hold the socket descriptor - contains info about socket. 
	network_socket = socket(AF_INET, SOCK_STREAM, 0); // calls the socket function and store the resulf of it in int.

	//specify an address for the socket (netinet)
	struct sockaddr_in server_address; // declare the structure for the address. 
	server_address.sin_family = AF_INET; // socket family - sets the family of the address so it knows what type of address we're working in here. 
	server_address.sin_port = htons(9002); // specifies the port we need to connect to.
	server_address.sin_addr.s_addr = INADDR_ANY; // defines the actual address. 

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); // calls the connect function
	// check for error with the connection
	if (connection_status == -1) // if the value is 0 - everything is good; -1 - error.
	{
		printf("There was an error making a conncetion to the remote socket \n\n");
	}
	//send/receive data from the server
	char server_response[256]; //holds info which we might get back from the server.
	recv(network_socket, &server_response, sizeof(server_response), 0);//receive function.

	//print out the server's response
	printf("The server sent the data: %s\n", server_response); //print out the data we get back.

	// and then close the socket
	close(network_socket);// unistd.h

	return 0;
}
