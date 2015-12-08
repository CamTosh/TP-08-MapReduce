<?php 

$tableau = array('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z');
	for ($i=0; $i < 10000; $i++) {
    	$toast = $tableau[rand(0,(count($tableau))-1)].$tableau[rand(0,(count($tableau))-1)].$tableau[rand(0,(count($tableau))-1)];
      echo $toast;
      echo '<br>';
}