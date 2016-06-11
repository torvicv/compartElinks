<?php

include 'includes.inc';

session_start();

$userName = filter_input(INPUT_POST, 'userName');
$password1 = filter_input(INPUT_POST, 'password');

if($userName && $password1){
    if(login($userName, $password1)){
        global $userName;
        $_SESSION['userName'] = $userName;
    }else{
        
        doHtmlHeader("Problema", "Problema", "Problema");
        echo "<p>No has podido identificarte. Debes estar identificado para poder ver está página.</p>";
        doHtmlUrl("index.php", "Login");
        do_html_footer();
        exit();
    }
}

doHtmlHeader("Marcadores", "página donde están los marcadores de la aplicación", "marcadores, menu, borrar,"
        . "contraseña, logout, cambiar");
checkValidUser();

$urlArray = getUserUrl($_SESSION['userName']);
displayUserUrl($urlArray);


displayUserMenu();

do_html_footer();