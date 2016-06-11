<?php

include 'includes.inc';

session_start();

$newPassword = filter_input(INPUT_POST, "newPassword");
$newPassword2 = filter_input(INPUT_POST, "newPassword2");
$oldPassword = filter_input(INPUT_POST, "oldPassword");

doHtmlHeader("Cambiar contraseña", "validacion para cambiar la contraseña", "validación, cambiar, contraseña");

checkValidUser();

if(!filledOut($_POST)){
    echo "<p>No has rellenado todos los campos del formulario.</p>";
    displayUserMenu();
    do_html_footer();
    exit();
}else{
    
    
    if($newPassword != $newPassword2){
        echo "<p>Las contraseñas no eran iguales. No se ha cambiado.</p>";
    }elseif (strlen ($newPassword) < 6 || strlen ($newPassword) > 16) {
        echo "<p>La contraseña debe tener entre 6 y 16 carácteres. Inténtalo de nuevo.</p>";
    }else{
        if(changePassword($_SESSION['userName'], $oldPassword, $newPassword)){
            echo "<p>Contraseña cambiada.</p>";
        }else{
            echo "<p>La contraseña no ha podido ser cambiada.</p>";
        }
    }
}

displayUserMenu();

do_html_footer();