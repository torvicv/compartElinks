<?php

function description($description){
    ?>
<meta name="description" content="<?=$description?>"/>
<?php
}

function author(){
    ?>
<meta name="author" content="Victor Cabral Vida"/>
<?php
}

function charset(){
    ?>
<meta charset="UTF-8"/>
<?php
}

function palabrasClave($palabrasClave){
    ?>
<meta name="keywords" content="<?=$palabrasClave?>"/>
<?php
}

function css_page(){
    ?>
<link rel="stylesheet" type="text/css" href="diseño.css"/>
<?php
}

function title($title){
    ?>
<title><?=$title?></title>
<?php
}