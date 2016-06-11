<?php

function filledOut($formVars){
    
    foreach ($formVars as $key => $value){
        if(!isset($key) || ($value == "")){
            return FALSE;
        }
    }
    return TRUE;
}

function validEmail($email){
    if(preg_match("/^[A-Za-z0-9_\.]+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/", $email)){
        return TRUE;
    }else{
        return FALSE;
    }
}