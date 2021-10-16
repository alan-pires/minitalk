# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:34:43 by apires-d          #+#    #+#              #
#    Updated: 2021/10/16 17:05:42 by apires-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $@

$(SERVER):
	$(CC) $(CFLAGS) server.c -o $@

$(BONUS_CLIENT):
	$(CC) $(CFLAGS) client_bonus.c -o $@

$(BONUS_SERVER):
	$(CC) $(CFLAGS) server_bonus.c -o $@

clean:
	rm -rf $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re: clean all bonus