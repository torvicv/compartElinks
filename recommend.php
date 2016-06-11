<?php

include 'includes.inc';

session_start();

doHtmlHeader("Urls recomendadas", "página para recomendar urls", "recomendar, urls, url");

checkValidUser();

$urls = recommendUrls($_SESSION['userName']);
displayRecommendedUrls($urls);

displayUserMenu();
do_html_footer();