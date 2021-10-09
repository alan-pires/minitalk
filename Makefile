# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:34:43 by apires-d          #+#    #+#              #
#    Updated: 2021/10/09 19:34:22 by apires-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $@

$(SERVER):
	$(CC) $(CFLAGS) server.c -o $@

clean:
	rm -rf $(CLIENT) $(SERVER)

re: clean all