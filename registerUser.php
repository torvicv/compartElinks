<?php

include 'includes.inc';

session_start();

$nombre = filter_input(INPUT_POST, 'userName');
$email = filter_input(INPUT_POST, 'email');
$password1 = filter_input(INPUT_POST, 'password');
$password2 = filter_input(INPUT_POST, 'password2');

if(!filledOut($_POST)){
    doHtmlHeader("Problema");
    
    echo "<p>No has cubierto el formulario correctamente - Vuelve e inténtalo de nuevo.</p>";
    
    do_html_footer();
    
    exit();
}

if(!validEmail($email)){
    doHtmlHeader("Problema");
    
    echo"<p>El email que has introducido no es correcto.</p>";
    
    do_html_footer();
    
    exit();
}

if(strlen($password1)<6 || strlen($password1)>16){
    doHtmlHeader("Problema","validación de formulario","validación");
    
    echo "<p>La contraseña debe tener entre 6 y 16 caracteres.</p>";
    
    do_html_footer();
    
    exit();
}

if($password1 != $password2){
    doHtmlHeader("Problema","validación de formulario","validación");
    
    echo "<p>La contraseña no coincide. Por favor inténtalo de nuevo.</p>";
    
    do_html_footer();
    
    exit();
}

$registerUser = regUser($nombre, $email, $password1);
if($registerUser == TRUE){
    
    $_SESSION['userName'] = $nombre;
    
    doHtmlHeader("Registro correcto", "página que te indica si el registro es correcto", "registro");
    echo "<p>Registro correcto. Ir a la página de miembros para empezar a configurar tus marcadores.</p>";
    doHtmlUrl("member.php","Ir a la página miembros");
}else{
    doHtmlHeader("Problema", "Problema", "Problema");
    echo $registerUser;
    do_html_footer();
    exit();
}

do_html_footer();