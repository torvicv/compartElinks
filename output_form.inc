<?php

function displayFormLogin(){
    ?>
<table>
    <form action="member.php" method="post">
    <tr>
        <th><label for="userName">Nombre de usuario</label></th>
        <td><input name="userName" type="text" id="userName" maxlength="30" placeholder="Nombre de usuario" required="required"/></td>
    </tr>
    <tr>
        <th><label for="password">Contraseña</label></th>
        <td><input type="password" name="password" id="password" maxlength="16" placeholder="Contraseña" required="required"/></td>
    </tr>
    <tr>
        <td colspan="2" style="text-align: center;"><input type="submit" value="Log in"/></td>
    </tr>
    </form>
    <tr>
        <td colspan="2"><a href="forgotPasswordForm.php">¿Olvidaste la contraseña?</a></td>
    </tr>
    
</table>
<?php
}

function displayRegistrationForm(){
    ?>
<table>
    <form action="registerUser.php" method="post">
        <tr>
            <th><label for="email">Dirección email</label></th>
            <td><input type="email" name="email" id="email" placeholder="Email" required="required"/></td>
        </tr>
        <tr>
            <th><label for="userName">Nombre de usuario preferido<br/>(max. 16 caract.)</label></th>
            <td><input type="text" name="userName" id="userName" maxlength="16" placeholder="Nombre de usuario" required="required"/></td>
        </tr>
        <tr>
            <th><label for="password">Contraseña<br/>(entre 6 y 16 caract.)</label></th>
            <td><input type="password" name="password" id="password" min="6" maxlength="16" placeholder="Contraseña" required="required"/></td>
        </tr>
        <tr>
            <th><label for="password2">Confirmar contraseña</label></th>
            <td><input type="password" name="password2" id="password2" min="6" maxlength="16" placeholder="Confirmar contraseña" required="required"/></td>
        </tr>
        <tr>
            <td colspan="2" style="text-align: center;"><input type="submit" value="Registrar"/></td>
        </tr>
    </form>
</table>
<?php
}

function displayPasswordForm(){
    ?>
<table>
    <caption>Formulario</caption>
    <form action="changePassword.php" method="post">
        <tr>
            <th><label for="oldPassword">Vieja contraseña</label></th>
            <td><input type="password" name="oldPassword" id="oldPassword" size="16" maxlength="16" 
                       placeholder="Vieja contraseña" required="required"/></td>
        </tr>
        <tr>
            <th><label for="newPassword">Nueva contraseña</label></th>
            <td><input type="password" name="newPassword" id="newPassword" size="16" maxlength="16" 
                       placeholder="Nueva contraseña" required="required"/></td>
        </tr>
        <tr>
            <th><label for="newPassword2">Confirmar nueva contraseña</label></th>
            <td><input type="password" name="newPassword2" id="newPassword2" size="16" maxlength="16" 
                       placeholder="Confirmar" required="required"/></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" value="Enviar"/></td>
        </tr>
</form>
</table>
<?php
}

function displayUserUrl($urlArray){
    global $bm_table;
    $bm_table = TRUE;
    ?>
<table style="width: 300px;" id="delete">
    <form name="bm_table" action="deleteBms.php" method="post">
        <tr>
            <th style="display: none;">ID</th>
            <th>Marcador</th>
            <th>Borrar?</th>
        </tr>
        <?php
        if(is_array($urlArray) && count($urlArray)>0){
            foreach ($urlArray as $url){
                ?>
            <tr>
                <input type="hidden" name="id[]" value="<?=$url['id_marcador']?>"/>
                <td><a href="<?=$url['url']?>"><?=htmlspecialchars($url['url'])?></a></td>
                <td><input type="checkbox" name="del_me[]" value="<?=$url['url']?>"/></td>
            </tr>
            <?php
            }
        }else{
            echo "<tr><td>No hay marcadores en el registro.</td></tr>";
        }
        ?>
    </form>
</table>
<?php
}

function displayForgotForm(){
    ?>
<table>
<form action="forgotPassword.php" method="post">
    <tr>
        <th><label for="userName">Introduzca nombre de usuario:</label></th>
        <td><input type="text" name="userName" id="userName" placeholder="Nombre de usuario"/></td>
    </tr>
    <tr>
        <td colspan="2" style="text-align: center;"><input type="submit" value="Cambiar contraseña"/></td>
    </tr>
</form>
</table>
<?php
}

function displayAddBmForm(){
    
    ?>
<table>
    <form name="bm_table" action="addBms.php" method="post">
        <tr>
            <th><label for="newUrl">Nuevo EN:</label></th>
            <td><input type="text" name="newUrl" id="newUrl" value="http://" size="30" maxlength="255"/></td>
        </tr>
        <tr>
            <td colspan="2" style="text-align: center;"><input type="submit" value="Añadir EN"/></td>
        </tr>
    </form>
</table>
<?php
}