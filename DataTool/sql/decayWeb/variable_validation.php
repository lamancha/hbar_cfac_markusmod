<?php


foreach($fieldValues as $key => $value)
{
	if(!is_numeric($value))
	{
		echo "The field ", $key, " must be a number.\n";
		exit(0);
	}
}

if($fieldValues['qType'] < 0 || $fieldValues['qType'] > 2)
{
	echo "qType must be between 0 and 2.\n";
	exit(0);
}

if($fieldValues['qType'] == 0 || $fieldValues['qType'] == 1)
{
	//Now validate that the numerical values actually makes sense. Otherwise, print a warning to tell the user what he/she did wrong.
	if ($fieldValues['upperN'] <= 0)
	{
		echo "Upper N value must be > 0.\n";
		exit(0);
	}

	if ($fieldValues['upperN'] >= 30)
	{
		echo "Upper N value must be < 30.\n";
		exit(0);
	}
	
	if($fieldValues['upperL'] < 0 || $fieldValues['upperL'] >= $fieldValues['upperN'] )
	{
		echo "Upper L must be >= 0 and < upper N.\n";
		exit(0);
	}
	
	if( ($fieldValues['upperJ']-1)/2 != $fieldValues['upperL'] && ($fieldValues['upperJ'] + 1)/2 != $fieldValues['upperL'])
	{
		echo "Upper J and upper L are not compatible for spin 1/2.\n";
		exit(0);
	}
	
	if( $fieldValues['upperJ']%2==0)
	{
		echo "Upper J must be odd.\n"; 
		exit(0);
	}

	if( $fieldValues['upperMJ'] > $fieldValues['upperJ'] || $fieldValues['upperMJ'] < 0)
	{
		echo "Upper MJ must be >= 0 and <= upper J.\n";
		exit(0);
	}

	if( $fieldValues['upperMJ']%2==0 )
	{
		echo "Upper MJ must be odd.\n";
		exit(0);
	}


	if( $fieldValues['upperP'] != 1 && $fieldValues['upperP'] != -1)
	{
		echo "Upper P must be +1 or -1\n";
		exit(0);
	}

}

if($fieldValues['qType'] == 0 || $fieldValues['qType'] == 2)
{
	if ($fieldValues['lowerN'] >= 30)
	{
		echo "Lower N value must be < 30.\n";
		exit(0);
	}
	if ($fieldValues['lowerN'] <= 0)
	{
		echo "Lower N value must be > 0.\n";
		exit(0);
	}
	if($fieldValues['lowerL'] < 0 || $fieldValues['lowerL'] >= $fieldValues['lowerN'] )
	{
		echo "Lower L must be >= 0 and < lower N.\n";
		exit(0);
	}
	
	if( ($fieldValues['lowerJ']-1)/2 != $fieldValues['lowerL'] && ($fieldValues['lowerJ'] + 1)/2 != $fieldValues['lowerL'])
	{
		echo "Lower J and lower L are not compatible for spin 1/2.\n";
		exit(0);
	}



	if( $fieldValues['lowerJ']%2==0)
	{
		echo "Lower J must be odd.\n"; 
		exit(0);
	}



	if( $fieldValues['lowerMJ'] > $fieldValues['lowerJ'] || $fieldValues['lowerMJ'] < 0)
	{
		echo "Lower MJ must be >= 0 and <= lower J.\n";
		exit(0);
	}

	if( $fieldValues['lowerMJ']%2==0 )
	{
		echo "Lower MJ must be odd.\n";
		exit(0);
	}



	if( $fieldValues['lowerP'] != 1 && $fieldValues['lowerP'] != -1)
	{
		echo "Lower P must be +1 or -1\n";
		exit(0);
	}


}

if($fieldValues['qType'] == 0)
{
	if ($fieldValues['lowerN'] > $fieldValues['upperN'])
	{
		echo "Lower N can not be higher than upper N.\n";
		exit(0);
	}

	if($fieldValues['lowerL'] + 1 != $fieldValues['upperL'] && $fieldValues['lowerL'] - 1 != $fieldValues['upperL'] )
	{
		echo "Lower L and upper L must differ by exactly one.\n";
		exit(0);
	}

}


?>