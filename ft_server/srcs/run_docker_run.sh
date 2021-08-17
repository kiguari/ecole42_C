# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_docker_run.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:17:14 by eshakita          #+#    #+#              #
#    Updated: 2021/02/20 16:37:02 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# move index file
mv ./index.html /var/www/html/index/index.html
mv ./var/www/html/index.nginx-debian.html ./var/www/html/index/index.nginx-debian.html
mv ./index.php /var/www/html/index/index.php

# SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.crt -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Moscow/L=Balashiha/O=42 School/OU=Eshakita/CN=Super_project"

# move config NGINX
mv ./nginx.conf /etc/nginx/sites-available/default

# phpmyadmin, move config file
mv ./tmp/config.inc.php /var/www/html/phpmyadmin/config.inc.php

# wordpress, move config file
mv ./wp-config.php ./var/www/html/wordpress/wp-config.php

# start mysql & php service
service mysql start
service php7.3-fpm start


# run script config MYSQL
bash ./my_sql_db_creat.sh

# start nginx service
service nginx start

# to make the container run (witout -it)
sleep infinity

#bash
