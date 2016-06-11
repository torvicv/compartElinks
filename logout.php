<?php

include 'includes.inc';

session_start();

$oldUser = $_SESSION['userName'];
unset($_SESSION['userName']);
$resultDest = session_destroy();

doHtmlHeader("Logging out", "página para desloguearse", "logging, out");

if(!empty($oldUser)){
    if($resultDest){
        echo "<p>Logged out</p>";
        doHtmlUrl("index.php", "Login");
    }else{
        echo "<p>Could not log you out.</p>";
    }
}else{
    echo "<p>No estabas logged in, por tanto no puede hacer logged out.</p>";
    doHtmlUrl("index.php", "Login");
}

do_html_footer();