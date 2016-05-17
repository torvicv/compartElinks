<?php

include 'output_head.inc';

function doHtmlHeader($title, $description, $palabrasClave){
    ?>
<!DOCTYPE html>
<html>
    <head>
        <?php
        doHtmlHead($title, $description, $palabrasClave);
        ?>
    </head>
    <body>
<header>
    <div><img src="imagenes/iconoCarpeta3.jpg" alt="logo carpeta" title="logo 1 carpeta" width="75px" height="75px" id="img"/>
        <img src="imagenes/iconoCarpeta1.jpg" alt="logo 2 carpeta" title="logo 2 carpeta" width="75px" height="75px" id="img"/>
        <img src="imagenes/iconoCarpeta2.jpg" alt="logo 3 carpeta" title="logo 3 carpeta" width="75px" height="75px" id="img"/>
    </div>
    <h1 id="img"><?=$title?></h1>
</header>
    <?php
}

function doHtmlHead($title, $description, $palabrasClave){
    charset();
    description($description);
    palabrasClave($palabrasClave);
    author();
    css_page();
    title($title);
}
