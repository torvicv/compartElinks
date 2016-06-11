<?php

include 'includes.inc';

//función que muestra la cabecera de la página
doHtmlHeader("Inicio", "página de inicio de la aplicación", "Inicio, página, aplicacion");

//funcion para ir a la página del formulario de registro
registerUser();

//función que muestra el formulario de loguearse si ya eres usuario
displayFormLogin();

//función que muestra el pie de página
do_html_footer();