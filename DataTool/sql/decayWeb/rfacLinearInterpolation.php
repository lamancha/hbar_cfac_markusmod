<?php //This should basically be a PHP porting, of the interpolating functionality of the rfacLinearInterpolation object.

class rfacLinearInterpolation
{
	public function __construct($xval,$yval)
	{
		if(!is_array($xval) || !is_array($yval))
		{
			throw new Exception("Can only call this function with 2 arrays of values");
	    }
		$this->xvals=$xval;
		$this->yvals=$yval;
		///xvals must be increasing for binary search to work...
		for($i=0; $i<count($this->xvals)-1; ++$i)
		{
			if($this->xvals[$i]>$this->xvals[$i+1])
			{
				throw new Exception("Function values must be sorted w.r.t. x values. But for i=" . $i . " we have '" . $this->xvals[$i] . "' before '" . $this->xvals[$i+1] . "' with total count " . count($this->xvals) . ".");
			}
		}
	}


	public function GetXvals()
	{
		return $this->xvals;
	}

	public function GetYvals()
	{
		return $this->yvals;
	}



	//We're dealing with something like 20 entries here, but a binary search is probably faster anyway.
	private function FindClosest($toFind)
	{
	    $lowerBound = 0; 
        $upperBound = count($this->xvals)-1;
		while($upperBound > $lowerBound + 1)
		{
			$mid = round(($upperBound + $lowerBound)/2);
			if( $this->xvals[$mid] < $toFind)
			{
				$lowerBound = $mid;
			}
			else if( $this->xvals[$mid] >= $toFind )
			{
				$upperBound = $mid;
			}

		}
		return $lowerBound;
	}


	public function EvalX($xval)
	{
		$closest = $this->FindClosest($xval);

		if($closest == count($this->xvals)-1)
		{
			$closest = $closest - 1;
		}
		$k = ( $this->yvals[$closest+1]-$this->yvals[$closest] ) / ($this->xvals[$closest + 1] - $this->xvals[$closest] ) ;

		$val = $this->yvals[$closest] + $k*($xval-$this->xvals[$closest]);
		
		if($val < 0)
			return 0;
		else
			return $val;
	}


	private $xvals; ///X values for the plot.

	private $yvals;  ///Y values for the plot
}



?>