<?php
//Special quicksort algorithm.

function quicksort( $array , $fieldB) 
{
    if( count( $array ) < 2 ) 
	{
        return $array;
    }
    $left = $right = array( );
    reset( $array );
    $pivot_key	= key( $array );
    $pivot	= array_shift( $array );
    foreach( $array as $k => $v ) 
	{
    	if( $v->EvalX($fieldB) > $pivot->EvalX($fieldB) )
    		$left[$k] = $v;
    	else
    		$right[$k] = $v;
    }
    return array_merge(quicksort($left, $fieldB), array($pivot_key => $pivot), quicksort($right, $fieldB));
}

?>