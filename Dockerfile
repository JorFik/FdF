# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:46:37 by JFikents          #+#    #+#              #
#    Updated: 2024/01/04 00:13:51 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:bookworm
WORKDIR /fdf
COPY . /fdf
