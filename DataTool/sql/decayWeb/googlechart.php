<?php
	$Bmin = 0;
	$Bmax = 4;
	$Bstep = 0.05;
?>


<div id="chart_div"></div>
    <script type="text/javascript"  id="toEvalOnTheLoad">
      function drawChart() 
	  {
        var data = google.visualization.arrayToDataTable
		([
		['Magnetic field [/T]'
		<?php
			if(count($interpolators) > 1 && $fieldValues['showTotal'] == 1)
			{
				echo ", 'Total'";
			}
			  $loopcount = 0;
    		  foreach( $interpolators as $k => $v ) 
			  {
			    echo ", '";
				echo $k;
				echo "'";
				if(++$loopcount >= $fieldValues['nEntries']  && $fieldValues['qType'] > 0)
					break;
			  }
			  echo "],\n";

		  for ($i = $Bmin; $i <= $Bmax; $i+=$Bstep) 
  		  {
			  $loopcount = 0;
			  echo "[", strval($i);
			  if(count($interpolators) > 1 && $fieldValues['showTotal'] == 1)
			  {
					$totalRate = 0;	
					foreach( $interpolators as $k => $v ) 
					{
						$totalRate+=$v->EvalX($i);
					}
					echo ", ", strval($totalRate);
		  	  }

    		  foreach( $interpolators as $k => $v ) 
			  {
			    echo ", ", strval($v->EvalX($i));
				if(++$loopcount >= $fieldValues['nEntries']  && $fieldValues['qType'] > 0)
					break;
			  }
			  echo "],\n";
		  }
?>
        ]);

        var options = {
          title: 'Decay rate for B=<?=$fieldValues['fieldB']?>T',
		  legend: {position: "bottom", textStyle: {color: 'black', fontSize: 8}},
		  hAxis: {title: "Magnetic field [/T]"},
		  vAxis: {title: "Decay rate [/s^{-1}]"}
        };

        var chart = new google.visualization.LineChart(document.getElementById('chart_div'));
        chart.draw(data, options);
      }
    </script>


<?php











?>