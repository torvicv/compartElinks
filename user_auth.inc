<?php

$host = "localhost";
$user = "root";
$password = "";
$database = "marcadores";

function regUser($nombre, $email, $password1){
    
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $consulta = "select * from user where nombre_usuario='$nombre'";
    $resultado = mysqli_query($db, $consulta);
    
    if(!$resultado){
        die("Error en mysqli_query");
    }
    if(mysqli_num_rows($resultado)>0){
        return "<p>El nombre de usuario esta ocupado vuelve y elige otro.</p>";
    }
    
    $insertar = "insert into user(nombre_usuario, password_usuario, email_usuario) values('$nombre','$password1','$email')";
    $resultado_insertar = mysqli_query($db, $insertar);
    
    if(!$resultado_insertar){
        die("Error en mysqli_query insertar");
    }
    
    return TRUE;
}

function checkValidUser(){
    if(isset($_SESSION['userName'])){
        echo "<p>Logged in as ".$_SESSION['userName']."</p>";
    }else{
        doHtmlHeader("Problema", "Problema", "Problema");
        echo "<p>No estas identificado.</p>";
        doHtmlUrl("index.php", "Login");
        do_html_footer();
        exit();
    }
}

function login($userName, $password1){
    
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $consulta = "select * from user where nombre_usuario='$userName' and password_usuario='$password1'";
    $resultado = mysqli_query($db, $consulta);
    
    if(!$resultado){
        die("Error en mysqli_query.");
    }
    if(mysqli_num_rows($resultado)>0){
        return 1;
    }else{
        return 0;
    }
}

function getUserUrl($userName){
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $consulta = "select url,id_marcador from marcador where nombre_usuario='$userName'";
    $resultado = mysqli_query($db, $consulta);
    
    if(!$resultado){
        die("Error en mysqli_query");
    }
    $urlArray = array();
    
    while ($fila = mysqli_fetch_array($resultado)){
        $urlArray[] = $fila;
        }
    
    mysqli_close($db);
    return $urlArray;
}

function changePassword($userName, $oldPassword, $newPassword){
    if(login($userName, $oldPassword)){
        global $host, $user, $password, $database;
    
        $db = mysqli_connect($host, $user, $password, $database);
        
        if(!$db){
            die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
        }
        
        $actualizar = "update user set password_usuario='$newPassword' where nombre_usuario='$userName'";
        $resultado = mysqli_query($db, $actualizar);
        
        if(!$resultado){
            die("Error en mysqli_query");
        }else{
            return TRUE;
        }
    }else{
        return FALSE;
    }
}

function resetPassword($userName){
    
    $newPassword = getRandomLetters(13);
    
    $randNumber = rand(0, 999);
    
    $newPassword .= $randNumber;
    
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $actualizar = "update user set password_usuario='$newPassword' where nombre_usuario='$userName'";
    $resultado = mysqli_query($db, $actualizar);
    
    if(!$resultado){
        die("Error en mysqli_query");
    }else{
        return $newPassword;
    }
}

function notifyPassword($userName, $password1){
    
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $consulta = "select email_usuario from user where nombre_usuario='$userName'";
    $resultado = mysqli_query($db, $consulta);
    
    if(!$resultado){
        die("Error en mysqli_query");
    }elseif (mysqli_num_rows($resultado) == 0) {
        die("Ese usuario no está en la base de datos.");
    }else{
        $fila = mysqli_fetch_assoc($resultado);
        $email = $fila['email_usuario'];
        print_r($fila);
        $from = "victor@sevilla.org";
        $message = "Tu contraseña de compartElinks ha sido cambiada a <b>$password1</b>."
                . "Por favor utilízalo la proxima vez que hagas log in. \n\r";
        if(mail($email, "login información compartElinks", $message, $from)){
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

function getRandomLetters($numeroLetras){
    
    global $getRandomLetters;
    $letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for($i = 0; $i < $numeroLetras; $i++){
        $getRandomLetters .= $letters{rand(0,49)};
    }
    
    return $getRandomLetters;
}

function addBm($newUrl){
    
    echo "<p>Intentando añadir ".htmlspecialchars($newUrl)."</p>";
    
    // asignar a $validUser el valor de $_SESSION['userName']
    $validUser = $_SESSION['userName'] ;
    
    global $host, $user, $password, $database;
    
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $consulta = "select * from marcador where nombre_usuario='$validUser' and url='$newUrl'";
    $resultado = mysqli_query($db, $consulta);
    
    if($resultado && (mysqli_num_rows($resultado)>0)){
        return FALSE;
    }
    
    $insertar = "insert into marcador(nombre_usuario, url) values ('$validUser', '$newUrl')";
    if(!mysqli_query($db, $insertar)){
        return FALSE;
    }
    
    return TRUE;
}

function deleteBm($id){
    
    global $host, $user, $password, $database;
    
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    $borrar = "delete from marcador where id_marcador='$id'";
    if(!mysqli_query($db, $borrar)){
        return FALSE;
    }
    return TRUE;
}

function recommendUrls($validUser, $popularity = 1){
    
    global $host, $user, $password, $database;
    $db = mysqli_connect($host, $user, $password, $database);
    
    if(!$db){
        die("Connect error(".mysqli_connect_errno().")".mysqli_connect_error());
    }
    
    //encontrar otros usuarios que coincidan con alguna url igual que la suya
    $consulta = "select distinct(b2.nombre_usuario) from marcador as b1, marcador as b2 "
            . "where b1.nombre_usuario='$validUser' and b1.nombre_usuario != b2.nombre_usuario and "
            . "b1.url=b2.url";
    if(!($resultado = mysqli_query($db, $consulta))){
        die("Error en mysqli_query!!!");
    }
    
    if(mysqli_num_rows($resultado) == 0){
        return "No hay usuarios con páginas en común.";
    }
    
    //crear conjunto de usuarios con urls en común para usar en clausula IN
    $row = mysqli_fetch_object($resultado);
    $simUsers = "('".($row->nombre_usuario)."'";
    while($row = mysqli_fetch_object($resultado)){
        $simUsers .=", '".($row->nombre_usuario)."'";
    }
    $simUsers .= ")";
    
    //crear lista de urls de usuarios para evitar replicar aquellas que ya conozcan
    $consulta = "select url from marcador where nombre_usuario='$validUser'";
    if(!($resultado = mysqli_query($db, $consulta))){
        die("Error en myqli_query 2!!!");
    }
    
    //crear conjunto de urls de usuarios para usar en clausula IN
    $row = mysqli_fetch_object($resultado);
    $usersUrl = "('".($row->url)."'";
    while ($row = mysqli_fetch_object($resultado)){
        $usersUrl .= ", '".($row->url)."'";
    }
    $usersUrl .= ")";
    
    $consulta = "select url from marcador where nombre_usuario in $simUsers and url not in $usersUrl "
            . "group by url having count(url)>'$popularity'";
    if(!($resultado = mysqli_query($db, $consulta))){
        die("Error en mysqli_query 3!!!");
    }
    
    if(!($num_resultados = mysqli_num_rows($resultado))){
        die("No hay resultados.");
    }
    
    $recUrls = array();
    while ($fila = mysqli_fetch_array($resultado)){
        $recUrls = $fila['url'];
    }
    mysqli_close($db);
    return $recUrls;
}