<?php
   $hostname = "localhost";
   $username = "decay";
   $pass = "DeCaY!_";
   $database = "decay";

   $infile = $argv[1];


   $con = mysqli_connect($hostname, $username, $pass);
   if (mysqli_connect_errno($con))
      {	
      	echo "Failed to connect to MySQL: " . mysqli_connect_error();
      } 
   mysqli_select_db($con,$database) or die("Unable to select database");

   $handle = @fopen($infile, "r");
   $qid = 0;
   if ($handle) 
   {
	while (($buffer = fgets($handle, 40960000)) !== false) 
   	{
	     $result = mysqli_query($con,$buffer);
	     echo "Inserting number: ", $qid,"\n";
	     $qid=$qid+1;
    	}
    	if (!feof($handle)) 
    	{
	     echo "Error: unexpected fgets() fail\n";
    	}
	fclose($handle);
   }
   mysqli_close($con);
?>