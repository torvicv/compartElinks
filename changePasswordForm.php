<?php

include 'includes.inc';

session_start();

doHtmlHeader("Cambiar contraseña", "página para cambiar la contraseña", "cambiar, contraseña");

checkValidUser();

displayPasswordForm();

do_html_footer();