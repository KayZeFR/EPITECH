#!/bin/sh
## send-a-flag.sh for shodan in /home/kayzefr/EPITECH/tek2/SHODAN
## 
## Made by Raphaël Ghikh
## Login   <raphael.ghikh@epitech.eu>
## 
## Started on  Tue Mar  7 12:27:49 2017 Raphaël Ghikh
## Last update Fri Mar 10 11:52:38 2017 Raphaël Ghikh
##

curl -u baguette:tt7hZEDyNXmQVcuh \
     -H "Content-Type: application/json" \
     -X POST \
     -d '{"chinpokomon": "'$1'", "flag": "'$2'" https://shodan.epitech.eu/api/1.2/score \
     --cacert shodan.pem
