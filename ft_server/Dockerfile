# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 14:52:37 by eshakita          #+#    #+#              #
#    Updated: 2021/03/06 15:45:56 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# setup debian
FROM debian:buster

# upgrade && util
RUN apt-get update 
RUN apt-get upgrade -y && apt-get install nano

# for web site download
RUN apt-get -y install wget

# setup nginx
RUN apt-get -y install nginx

# setup sql-server
RUN apt-get -y install mariadb-server
# RUN apt-get -y install default-mysql-server

# setup all required php package (nginx, phpmyadmin, bd, sql, wordpress etc)
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

# generate index folder
RUN mkdir /var/www/html/index
RUN mkdir /var/www/html/phpmyadmin
RUN chmod -R 777 /var/www/*

# download & tar wordpress & phpmyadmin
RUN wget https://wordpress.org/latest.tar.gz
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0-rc1/phpMyAdmin-5.1.0-rc1-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.1.0-rc1-all-languages.tar.gz --strip-components 1 -C /var/www/html/phpmyadmin
RUN tar zxvf latest.tar.gz -C ./var/www/html/

# copy config-files & script
COPY ./srcs/nginx.conf ./nginx.conf
COPY ./srcs/index.php ./index.php
COPY ./srcs/index.html ./index.html
COPY ./srcs/run_docker_run.sh ./run_docker_run.sh
COPY ./srcs/wp-config.php ./wp-config.php
COPY ./srcs/config.inc.php ./tmp/config.inc.php
COPY ./srcs/my_sql_db_creat.sh ./my_sql_db_creat.sh

# listen only 80 & 443 ports
EXPOSE 80 443

# run script run_docker_run.sh
CMD bash run_docker_run.sh && bash
