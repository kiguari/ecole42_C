# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 14:52:37 by eshakita          #+#    #+#              #
#    Updated: 2021/05/17 11:39:46 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update 
RUN apk upgrade 

RUN apk add bash nginx supervisor libc6-compat openrc wget

RUN apk add php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session\
			php7-common php7-iconv php7-gd php7-curl php7-xml php7-imap php7-cgi \
			fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix \
			php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

RUN mkdir /www && mkdir /www/phpmyadmin && chmod -R 777 /www/* && mkdir -p /run/nginx

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0-rc1/phpMyAdmin-5.1.0-rc1-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.1.0-rc1-all-languages.tar.gz --strip-components 1 -C /www/phpmyadmin

COPY ./configs/config.inc.php ./www/phpmyadmin/config.inc.php
COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./configs/supervisor.conf /etc/
COPY ./configs/supervisor_start.sh /

EXPOSE 5000

CMD bash supervisor_start.sh