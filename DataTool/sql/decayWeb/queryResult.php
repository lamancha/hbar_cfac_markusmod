<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

	header('Content-Type: text/plain');
	require("variable_init.php");
	$fieldValues = getFields(null);
	require("variable_validation.php");	
	require("cookie_set.php");
	require("rfacLinearInterpolation.php");


   require("db_connect.php");
   $con = db_connect();




   $query = "SELECT * FROM decayrates WHERE";
   switch($fieldValues['qType'])
   {
		case 0:
			 $query = $query . 
		   	 " upperN=" . $fieldValues['upperN'] . " AND" .
   		   	 " upperL=" . $fieldValues['upperL'] . " AND" .
   		   	 " upperJ=" . $fieldValues['upperJ'] . " AND" .
   		   	 " upperMJ=" . $fieldValues['upperMJ'] . " AND" .
   		   	 " upperP=" . $fieldValues['upperP'] . " AND" .
   		   	 " lowerN=" . $fieldValues['lowerN'] . " AND" .
   		   	 " lowerL=" . $fieldValues['lowerL'] . " AND" .
   		   	 " lowerJ=" . $fieldValues['lowerJ'] . " AND" .
   		   	 " lowerMJ=" . $fieldValues['lowerMJ'] . " AND" .
   		   	 " lowerP=" . $fieldValues['lowerP'] . ";";
		break;
		case 1:
			 $query = $query . 
		   	 " upperN=" . $fieldValues['upperN'] . " AND" .
   		   	 " upperL=" . $fieldValues['upperL'] . " AND" .
   		   	 " upperJ=" . $fieldValues['upperJ'] . " AND" .
   		   	 " upperMJ=" . $fieldValues['upperMJ'] . " AND" .
   		   	 " upperP=" . $fieldValues['upperP'] . ";";
		break;
		case 2:
			 $query = $query . 
   		   	 " lowerN=" . $fieldValues['lowerN'] . " AND" .
   		   	 " lowerL=" . $fieldValues['lowerL'] . " AND" .
   		   	 " lowerJ=" . $fieldValues['lowerJ'] . " AND" .
   		   	 " lowerMJ=" . $fieldValues['lowerMJ'] . " AND" .
   		   	 " lowerP=" . $fieldValues['lowerP'] . ";";
		break;

   }
   
   
   $interpolators = array();
   
   if($result = $con->query($query))
   {
    $fields = $result->fetch_fields();
   	while ($row = $result->fetch_row())
   	{
         $x=array();
         $y=array();
	 	 $actualValues = array();
         for($i=0; $i<$result->field_count; $i=$i+1)
         {
             if(substr($fields[$i]->name,0,1)=="x")
             {
				if(!is_null($row[$i]))
				{
					array_push($x,$row[$i]);
				}
             }
             else if(substr($fields[$i]->name,0,1)=="y")
             {
				if(!is_null($row[$i]))
				{
					array_push($y,$row[$i]);
				}
             }
			 else
			 {
				$actualValues[$fields[$i]->name]=$row[$i];
			 }
         }

         if( count($x) != count($y) )
         {
             echo "Error: non-matching number of x- and y-coordinates.";
         }

         $myInterpolation = new rfacLinearInterpolation($x,$y);
		 $myKey = "n=" . strval($actualValues['upperN']) . " l=" . strval($actualValues['upperL']) . " j=" . strval($actualValues['upperJ']) . "/2 mj=" . strval($actualValues['upperMJ']) . "/2 p=" . strval($actualValues['upperP']) . " -> n=" . strval($actualValues['lowerN']) . " l=" . strval($actualValues['lowerL']) . " j=" . strval($actualValues['lowerJ']) . "/2 mj=" . strval($actualValues['lowerMJ']) . "/2 p=" . strval($actualValues['lowerP']) . " for B=" . strval($fieldValues['fieldB']);
		 $interpolators[$myKey] = $myInterpolation;
   	}

	if($result->num_rows==0)
	{
	     echo "<h3>No data was returned for the query.</h3>\n";
		 echo "<p>The most probable reason for this is that the total decay rate is zero (for the limited dataset calculated at least).</p>\n";
	}
	else
	{
		require("quicksort.php");
		$interpolators = quicksort($interpolators, $fieldValues['fieldB']);

		if(count($interpolators) > 1 && $fieldValues['showTotal'] == 1)
		{
			$totalRate = 0;	
			foreach( $interpolators as $k => $v ) 
			{
				$totalRate+=$v->EvalX($fieldValues['fieldB']);
			}
			echo "<h2>Total decay rate: <strong style=\"color:red\">", $totalRate, " s^-1</strong></h2>\n";
		}


		$loopcount = 0;
	    foreach( $interpolators as $k => $v) 
		{
		    echo "<h3>Decay rate: <strong style=\"color:red\">", $v->EvalX($fieldValues['fieldB']), " s^-1</strong> for decay ", $k , "</h3>\n";
			if(++$loopcount >= $fieldValues['nEntries']  && $fieldValues['qType'] > 0)
				break;
		}
		if( count($interpolators) - $loopcount > 0)
		{
			echo "<h4>", strval(count($interpolators) - $loopcount), " smaller branches ignored</h4>\n";
		}
	}
	include("googlechart.php");

   }
   else
   {
        echo "Failed to execute SQL query:\n";
        echo $query;
   }

   mysqli_close($con);
?>

