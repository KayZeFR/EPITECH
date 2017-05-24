#!/bin/sh
## chinpokomons_list.sh for test in /home/kayzefr/EPITECH/tek2/SHODAN
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Tue Mar  7 12:50:34 2017 Raphaël Ghikh
## Last update Tue Mar  7 12:53:43 2017 Raphaël Ghikh
##

curl -u baguette:tt7hZEDyNXmQVcuh -H "Content-Type: application/json" -X POST -d '{"name": "'$1'"}' https://shodan.epitech.eu/api/1.2/challenge-info --cacert shodan.pem
