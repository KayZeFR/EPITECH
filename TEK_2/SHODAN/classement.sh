#!/bin/sh
## classement.sh for shodan in /home/kayzefr/EPITECH/tek2/SHODAN
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Tue Mar  7 12:41:15 2017 Raphaël Ghikh
## Last update Tue Mar  7 12:41:39 2017 Raphaël Ghikh
##

curl -u baguette:tt7hZEDyNXmQVcuh -H "Content-Type: application/json" https://shodan.epitech.eu/api/1.2/scored --cacert shodan.pem
