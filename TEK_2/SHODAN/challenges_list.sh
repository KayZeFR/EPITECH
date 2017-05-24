#!/bin/sh
## challenges_list.sh for shodan in /home/kayzefr/EPITECH/tek2/SHODAN
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Tue Mar  7 12:25:40 2017 Raphaël Ghikh
## Last update Thu Mar  9 11:21:50 2017 Raphaël Ghikh
##

curl -u baguette:tt7hZEDyNXmQVcuh -H "Content-Type: application/json" https://shodan.epitech.eu/api/1.2/challenges --cacert shodan.pem
