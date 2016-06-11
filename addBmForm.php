<?php

include 'includes.inc';

session_start();

doHtmlHeader("Añadir enlace", "formulario para añadir nuevo enlace", "formulario, añadir, nuevo, enlace");

checkValidUser();

displayAddBmForm();

displayUserMenu();

do_html_footer();