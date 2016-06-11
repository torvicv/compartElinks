<?php

include 'includes.inc';

doHtmlHeader("Recuperar contraseña", "página para recuperar contraseña", "recuperar, contraseña");

$userName = filter_input(INPUT_POST, 'userName');

if($password1 = resetPassword($userName)){
    if(notifyPassword($userName, $password1)){
        echo "<p>Tu nueva contraseña ha sido enviada a tu dirección de email.</p>";
    }else{
        echo "<p>Tu contraseña no ha podido ser enviada por email."
        . "Prueba pulsando actualizar.</p>";
    }
}else{
    echo "<p>Tu contraseña no ha podido modificarse. Prueba de nuevo mas tarde.</p>";
}

doHtmlUrl("index.php", "login");

do_html_footer();