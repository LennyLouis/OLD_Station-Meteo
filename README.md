# Station-Meteo
Projet d'une station météo a base d'arduino et d'une interface web.

Ce projet a pour but de récupérer les températures de différentes pièces d'un domicile pour ensuite les récupérer depuis une interface web.

Les capteurs de température sont des ardus inos couplés à des capteurs TMP36 de température et des modules ESP8266 pour permettre une liaison Wi-Fi.

L'interface web est elle constituée d'un front en AngularJS permettant une actualisation plus simple des températures. Le backend est lui en Php, l'API récupère sur l'API de Blynk, un service permettant de communiquer simplement avec un ESP8266, les différentes informations des Arduinos. Par la suite on écrit dans des fichiers Json les valeurs récupérées qui pourront être par la suite interprétés par le front.

L'interface web est consultable à l'adresse suivante: https://lennylouis.github.io/stationmeteo/
