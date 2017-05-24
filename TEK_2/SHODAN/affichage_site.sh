#!/bin/sh
## affichage_site.sh for test in /home/kayzefr/EPITECH/tek2/SHODAN
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Thu Mar  9 11:50:35 2017 Raphaël Ghikh
## Last update Fri Mar 10 09:36:11 2017 Raphaël Ghikh
##

curl -u baguette:tt7hZEDyNXmQVcuh -H "Content-Type: application/json" https://shodan.epitech.eu/6TJpDcsSDN7ncp5x/search.php --cacert shodan.pem
