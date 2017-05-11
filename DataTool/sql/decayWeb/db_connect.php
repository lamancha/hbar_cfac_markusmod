<?php
	function db_connect()
	{
		$hostname = "localhost";
		//$username = "rikardlu_dcayusr";
        //$pass = "78VA8KWvzFkm";
	    //$database = "rikardlu_decay";
	    $username = "decay";
   		$pass = "DeCaY!_";
   		$database = "decay";

   		$con = mysqli_connect($hostname, $username, $pass);
   		if (mysqli_connect_errno($con))
      	{	
      		echo "Failed to connect to MySQL: " . mysqli_connect_error();
      	} 
   		mysqli_select_db($con,$database) or die("Unable to select database");
		return $con;
	}
?>