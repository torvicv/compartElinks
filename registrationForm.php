<?php

include 'includes.inc';

//función que muestra el encabezado de la página, mas rellenar el head
doHtmlHeader("Registro de usuario", "formulario para registrarse", "formulario,registro, nombre, email, contraseña");

//función que muestra el formulario de registro
displayRegistrationForm();

//función que muestra el pie de página
do_html_footer();