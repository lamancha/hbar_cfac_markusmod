<?php


	///Some default stuff.
	$Bmin = 0;
	$Bmax = 4;
	$Bstep = 0.05;
	$marginFactor = 0.05;
	










  // Create some random text-encoded data for a line chart.
  header('content-type: image/png');
  $url = 'https://chart.googleapis.com/chart';
  $chd = 't:';


  $ymax = 0;
  $ymin = 1E50;

  for ($i = $Bmin; $i <= $Bmax; $i+=$Bstep) 
  {
    $data = myInterpolation->Eval($i);
    $chd .= $data . ',';

	if($data > $ymax)
	{
		$ymax = $data;
	}
	if($data < $ymin)
	{
		$ymin = $data;
	}

  }
  $ymax = $ymax+($ymax-$ymin)*$marginFactor;
  $ymin = $ymin-($ymax-$ymin)*$marginFactor;


  $chd = substr($chd, 0, -1);

  // Add data, chart type, chart size, and scale to params.
  $chart = array(
    'cht' => 'lc',
    'chs' => '600x200',
    'chds' => '0,100000',
    'chd' => $chd);

  // Send the request, and print out the returned bytes.
  $context = stream_context_create(
    array('http' => array(
      'method' => 'POST',
      'content' => http_build_query($chart))));
  fpassthru(fopen($url, 'r', false, $context));
?>