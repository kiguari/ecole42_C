# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 15:12:48 by eshakita          #+#    #+#              #
#    Updated: 2021/05/17 09:49:53 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

VOLUME ["/var/lib/mysql"]

RUN apk update 
RUN apk upgrade 

RUN apk add bash supervisor mysql mysql-client openrc libc6-compat

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/supervisord.conf /etc/
COPY ./configs/my.cnf /etc/
COPY ./configs/wordpress_db_user_php_create.sql /
COPY ./configs/wordpress.sql /
COPY ./configs/start_mysql.sh /

EXPOSE 3306

CMD bash start_mysql.sh