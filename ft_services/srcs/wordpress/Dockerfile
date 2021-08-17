# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 14:52:37 by eshakita          #+#    #+#              #
#    Updated: 2021/05/17 11:40:11 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update 
RUN apk upgrade
RUN apk add libc6-compat bash supervisor wget openrc nginx 

RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN mkdir -p /www && chmod -R 777 /www && mkdir -p /run/nginx

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN wget https://wordpress.org/latest.tar.gz
RUN tar zxvf latest.tar.gz -C ./www/

COPY ./configs/wp-config.php ./www/wordpress/wp-config.php
COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./configs/supervisor.conf /etc/ 
COPY ./configs/supervisor_start.sh /

EXPOSE 5050

CMD bash supervisor_start.sh