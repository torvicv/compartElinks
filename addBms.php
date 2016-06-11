<?php

include 'includes.inc';

session_start();

$newUrl = filter_input(INPUT_POST, 'newUrl');
doHtmlHeader("Añadir marcador", "página para añadir marcador", "añadir, nuevo, marcador");
checkValidUser();

if(!filledOut($_POST)){
    echo "<p>No has rellenado el formulario correctamente. Inténtalo de nuevo.</p>";
    
    displayUserMenu();
    do_html_footer();
    exit();
}else{
    if(strpos($newUrl, "http://") === FALSE){
        $newUrl = "http://".$newUrl;
    }
    
    if(@fopen($newUrl, "r")){
        if(addBm($newUrl)){
            echo "<p>Marcador añadido.</p>";
        }else{
            echo "<p>No se ha podido añadir el marcador.</p>";
        }
    }else{
        echo "<p>La URL no es válida.</p>";
    }
}

if($urlArray = getUserUrl($_SESSION['userName']));
    displayUserUrl($urlArray);


displayUserMenu();

do_html_footer();