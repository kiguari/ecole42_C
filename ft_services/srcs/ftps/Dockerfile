# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 12:13:13 by eshakita          #+#    #+#              #
#    Updated: 2021/05/17 11:36:35 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update 
RUN apk upgrade 

RUN apk add openssh openssl openrc libc6-compat bash wget vsftpd supervisor

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN mkdir -p home/eshakita/ && chmod -R 777 home/ && mkdir -p /etc/ssl/ && chmod -R 777 /etc/ssl/

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/ssl/ftps.crt -keyout /etc/ssl/ftps.key -subj "/C=FR/ST=Moscow/L=Balashiha/O=42 School/OU=Eshakita/CN=Super_project"

# Чтобы избежать интерактивных вопросов со стороны adduser, вы можете вызвать его со следующими параметрами:
# RUN adduser --disabled-password'' newuser
# В системах с busybox (например, Alpine) используйте
# RUN adduser -D '' newuser

RUN adduser -D eshakita && echo "eshakita:eshakita" | chpasswd

COPY ./configs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/supervisor.conf /etc/supervisor.conf
COPY ./configs/supervisor_start.sh /

EXPOSE 21 20001

CMD bash supervisor_start.sh