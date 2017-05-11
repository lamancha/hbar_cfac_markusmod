<?php

function getFields($useDefaults)
{
	if(isset($_COOKIE['fieldValues']))
	{
		$fieldValues = unserialize(urldecode($_COOKIE['fieldValues']));  
	}
	else
	{
		$fieldValues = array(
				"qType" => 1,
				"upperN" => 10, 
				"upperL" => 9,
				"upperJ" => 17,
				"upperMJ" => 17,
				"upperP" => 1,
				"lowerN" => 9, 
				"lowerL" => 8,
				"lowerJ" => 15,
				"lowerMJ" => 15,
				"lowerP" => 1,	
				"fieldB" => 1,
				"nEntries" => 5,		
				"showTotal" => 1
				);
	}

	foreach($fieldValues as $key => &$value)
	{
		if(isset($_GET[$key]))
		{
			$value=$_GET[$key];
		}
		else
		{
			if(!isset($useDefaults) || $useDefaults === false)
				throw new Exception("The value " + $key + " was not defined.\n");
		}
	}
	return $fieldValues;
}
?>
