<?php

include 'includes.inc';

session_start();

/*$del_me = $_POST['del_me'];
$i=0;
foreach($del_me as $k => $v){
    $del_me[$i] =  filter_var($v, FILTER_SANITIZE_URL);
    $i++;
}*/
/*$del_me = filter_input(INPUT_POST, 'del_me', FILTER_SANITIZE_URL , FILTER_REQUIRE_ARRAY);
$id = filter_input(INPUT_POST, 'id', FILTER_SANITIZE_NUMBER_INT, FILTER_REQUIRE_ARRAY);*/
$delMe = array('del_me' => array('name' => 'del_me','filter' => FILTER_SANITIZE_URL, 'flags' => FILTER_REQUIRE_ARRAY),
               'id' => array('name' => 'id','filter' => FILTER_SANITIZE_NUMBER_INT, 'flags' => FILTER_REQUIRE_ARRAY));

$del_me = filter_input_array(INPUT_POST,$delMe);

var_dump($del_me['id']);

doHtmlHeader("Borrar marcadores", "página para borrar marcadores", "borrar, marcador, marcadores");

checkValidUser();

if(!filledOut($_POST)){
    echo "<p>No has escrito ningún marcador para borrar. Prueba de nuevo, por favor.</p>";
    displayUserMenu();
    do_html_footer();
    exit();
}else{
    if(count($del_me) > 0){
        $i = 0;
        while($i < count($del_me['id'])){
            if(deleteBm($id)){
                echo "<p>Borrado ".htmlspecialchars($url)."</p>";
            }else{
                echo "<p>No pudo borrarse ".htmlspecialchars($url)."</p>";
            }
            $i++;
        }
    }else{
        echo "<p>No hay marcador seleccionado para borrarse.</p>";
    }
}

if($urlArray = getUserUrl($_SESSION['userName']));
    displayUserUrl($urlArray);
    
    displayUserMenu();
    
    do_html_footer();