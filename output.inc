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
    <div id="img"><img src="imagenes/iconoCarpeta3.jpg" alt="logo carpeta" title="logo 1 carpeta" width="75px" height="75px" class="img"/>
        <img src="imagenes/iconoCarpeta1.jpg" alt="logo 2 carpeta" title="logo 2 carpeta" width="75px" height="75px" class="img"/>
        <img src="imagenes/iconoCarpeta2.jpg" alt="logo 3 carpeta" title="logo 3 carpeta" width="75px" height="75px" class="img"/>
    </div>
    <h1>CompartElinks</h1>
</header>
        <hr/>
        <h2><?=$title?></h2>
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

function do_html_footer(){
    ?>
        <footer>
            Curso videotutorial Jesus Conde 2016-Autor: VICTOR CABRAL VIDA
        </footer>
    </body>
</html>
<?php
}

function registerUser(){
    ?>
<p><a href="registrationForm.php">No soy miembro aún</a></p>
<?php
}

function doHtmlUrl($link, $text){
    echo "<p><a href='$link'>$text</a></p>";
}

function displayUserMenu(){
    ?><div id="menu">
        <hr/>
        <a href="member.php">Marcadores</a>&nbsp;|&nbsp;
        <a href="addBmForm.php">Add En</a>&nbsp;|&nbsp;
        <?php
        global $bm_table;
        if($bm_table == TRUE){
            echo "<a href='#' onClick='bm_table.submit();'>Borrar En|</a>&nbsp;|&nbsp;";
        }else{
            echo "<span style='color: lightgrey;'>Borrar En</span>&nbsp;|&nbsp;";
        }
        ?>
        <a href="changePasswordForm.php">Cambiar contraseña</a>&nbsp;|&nbsp;
        <a href="recommend.php">Recomendar urls</a>&nbsp;|&nbsp;
        <a href="logout.php">Logout</a>
        <hr/>
</div>
<?php
}

function displayRecommendedUrls($recUrl){
    ?>
<table id="delete">
    <tr>
        <th>Urls recomendadas</th>
    </tr>
    <?php
    if(is_array($recUrl)){        
        foreach($recUrl as $url){
            ?>
        <tr>
            <td><?=$url?></td>
        </tr>
        <?php
        }
    }else{
        ?>
        <tr>
            <td><?=$recUrl?></td>
        </tr>
        <?php
    }
    ?>
</table>
<?php
}