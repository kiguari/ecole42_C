# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 14:52:37 by eshakita          #+#    #+#              #
#    Updated: 2021/05/19 12:48:20 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update 
RUN apk upgrade

RUN apk add bash supervisor libc6-compat openssl openrc nginx

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/ssl/certs/nginx_host.crt -keyout /etc/ssl/private/nginx_host.key -subj "/C=FR/ST=Moscow/L=Balashiha/O=42 School/OU=Eshakita/CN=Super_project"

RUN mkdir -p /run/nginx

COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./configs/supervisor.conf /etc/
COPY ./configs/supervisor_start.sh /

EXPOSE 80 443

CMD bash supervisor_start.sh
