<?php
 //Don't use this file, thus:
 exit(1);

   $hostname = "rikardlundmark.com";
   $username = "rikardlu_dcayusr";
   $pass = "78VA8KWvzFkm";
   $database = "rikardlu_decay";

   //$hostname = "localhost";
   //$username = "rikard";
   //$pass = "hej";
   //$database = "decayrate";

   $con = mysqli_connect($hostname, $username, $pass);
   if (mysqli_connect_errno($con))
      {	
      	echo "Failed to connect to MySQL: " . mysqli_connect_error();
      } 
   mysqli_select_db($con,$database) or die("Unable to select database");

   $query ="CREATE TABLE IF NOT EXISTS decayrates
	      (
	      id INT(8) NOT NULL AUTO_INCREMENT,
	      upperN TINYINT UNSIGNED NOT NULL,
	      upperL TINYINT UNSIGNED NOT NULL,
	      upperJ TINYINT UNSIGNED NOT NULL,
	      upperMJ TINYINT UNSIGNED NOT NULL,
	      upperP TINYINT NOT NULL,
	      lowerN TINYINT UNSIGNED NOT NULL,
	      lowerL TINYINT UNSIGNED NOT NULL,
	      lowerJ TINYINT UNSIGNED NOT NULL,
	      lowerMJ TINYINT UNSIGNED NOT NULL,
	      lowerP TINYINT NOT NULL,
	      zeroCoeff DOUBLE NOT NULL,	
	      linCoeffE DOUBLE NOT NULL,
	      linCoeffB DOUBLE NOT NULL,
	      linCoeffA DOUBLE NOT NULL,
	      PRIMARY KEY (id),
	      UNIQUE id (id),
	      KEY id_2 (id)
	       )";
   $result = mysqli_query($con,$query);
   echo $result;
   mysqli_close($con);
?>