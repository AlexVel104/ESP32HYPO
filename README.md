# ESP32HYPO
EmbebidosA320723
Problemas que tenia:
La palabra reservada "auto" solo me funcionaba en el for, no podia castear variables con estas y me arrojaba que unas variables no tenian tipo de dato.
La placa no cargaba ningun sketch.

Como lo solucione:
Aplique los static_cast<tipodato> para poder pasar a otros tipos de datos algunas variables.
Arranque la instalacion y la configuracion de la placa desde 0 usando varios tutoriales y checando que no tuviera datos fallidos (los cuales habia) y consegui un cable de datos.
