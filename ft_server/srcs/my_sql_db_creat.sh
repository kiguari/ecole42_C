# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_sql_db_creat.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 15:16:30 by eshakita          #+#    #+#              #
#    Updated: 2021/02/05 15:16:34 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

mysql -e "CREATE DATABASE db_Eshakita_wp;"
mysql -e "CREATE USER 'Eshakita'@'localhost' IDENTIFIED BY 'Eshakita';"
mysql -e "GRANT ALL PRIVILEGES ON db_Eshakita_wp.* TO 'Eshakita'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"