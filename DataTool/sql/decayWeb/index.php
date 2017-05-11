<?php
   error_reporting(E_ALL);
   ini_set('display_errors', '1');
?>

<!doctype html>
<html>

  <head>
    <title>Decay rate calculator</title>
    <meta charset="utf-8" />
	<meta name="author" content="Rikard Lundmark"/>
	<link rel="Shortcut icon" href="https://smilx0.smi.oeaw.ac.at/decay/wicon.ico" />
	<link rel="stylesheet" type="text/css" href="style.css">
    <script type="text/javascript" src="https://www.google.com/jsapi"></script>

	<script>
      google.load("visualization", "1", {packages:["corechart"]});

	  <!--AJAX script to load results when the user is typing.-->
	  function loadResult(qType,uN,uL,uJ,uMJ,uP,lN,lL,lJ,lMJ,lP,BF,nENT,totR)
	  {
	      document.getElementById("queryRes").innerHTML="<b>Loading results...</b>\n<br>\n<img src=\"loading.gif\" alt=\"\" width=\"79px\" height=\"79px\"><br>\n"+
		  												  document.getElementById("queryRes").innerHTML;
	      if (window.XMLHttpRequest)
	      {// code for IE7+, Firefox, Chrome, Opera, Safari
	          xmlhttp=new XMLHttpRequest();
	      }
	      else
	      {// code for IE6, IE5
	          xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	      }
	      xmlhttp.onreadystatechange=function()
	      {
	          if (xmlhttp.readyState==4 && xmlhttp.status==200)
              {
                  document.getElementById("queryRes").innerHTML=xmlhttp.responseText;
				  eval(document.getElementById("toEvalOnTheLoad").innerHTML);
				  drawChart();
				  document.getElementsByName("submitButton")[0].disabled = false;
				  setContainerState(true);
              }
	      }
		  document.getElementsByName("submitButton")[0].disabled = true;
		  setContainerState(false);
	      xmlhttp.open("GET","queryResult.php?qType="+qType+"&upperN="+uN+"&upperL="+uL+"&upperJ="+uJ+"&upperMJ="+uMJ+"&upperP="+uP+"&lowerN="+lN+"&lowerL="+lL+"&lowerJ="+lJ+"&lowerMJ="+lMJ+"&lowerP="+lP+"&fieldB="+BF+"&nEntries="+nENT+"&showTotal="+totR,true);
	      xmlhttp.send();
	  }

	  function setContainerState(canType)
	  {
		var nodes = document.getElementById("container").getElementsByTagName('*');
		for(var i = 0; i < nodes.length; i++)
		{
			nodes[i].disabled = !canType;
			nodes[i].color = canType?'grey':'white';
		}
	  }

	  var validateTimeout = false;

	  function validateConsistency(qType,uN,uL,uJ,uMJ,uP,lN,lL,lJ,lMJ,lP,BF,nENT,totR)
	  {
		if(validateTimeout != false) 
		{
			window.clearTimeout(validateTimeout);
    	}			
	    document.getElementById("validationErrMsg").innerHTML="Checking consistency";
        document.getElementsByName("submitButton")[0].disabled = true;
		validateTimeout = window.setTimeout(function(){validateConsistencyCont(qType,uN,uL,uJ,uMJ,uP,lN,lL,lJ,lMJ,lP,BF,nENT,totR);},300);
	  }

	  function validateConsistencyCont(qType,uN,uL,uJ,uMJ,uP,lN,lL,lJ,lMJ,lP,BF,nENT,totR)
	  {
	    document.getElementById("validationErrMsg").innerHTML="Checking consistency...";
        document.getElementsByName("submitButton")[0].disabled = true;
	      if (window.XMLHttpRequest)
	      {// code for IE7+, Firefox, Chrome, Opera, Safari
	          xmlhttp=new XMLHttpRequest();
	      }
	      else
	      {// code for IE6, IE5
	          xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	      }
	      xmlhttp.onreadystatechange=function()
	      {
	          if (xmlhttp.readyState==4 && xmlhttp.status==200)
              {
			      if(xmlhttp.responseText.length > 1)
				  {
					 document.getElementById("validationErrMsg").innerHTML = xmlhttp.responseText;
                     document.getElementsByName("submitButton")[0].disabled = true;
				  }
				  else
				  {
					 document.getElementById("validationErrMsg").innerHTML = "";
                     document.getElementsByName("submitButton")[0].disabled = false;
				  }
              }
	      }
	      xmlhttp.open("GET","variable_check.php?qType="+qType+"&upperN="+uN+"&upperL="+uL+"&upperJ="+uJ+"&upperMJ="+uMJ+"&upperP="+uP+"&lowerN="+lN+"&lowerL="+lL+"&lowerJ="+lJ+"&lowerMJ="+lMJ+"&lowerP="+lP+"&fieldB="+BF+"&nEntries="+nENT+"&showTotal="+totR,true);
	      xmlhttp.send();
	  }

	  
	</script>







  </head>

  <body>
    <h1>Calculate decay rates for atomic hydrogen in external fields</h1>
  <div id="container">

	<?php require("inputForm.php"); ?>

  </div>
	<div id="queryRes">
		<!--The result of the AJAX query goes here.-->
	</div>

	<span id="dblink"><a href="hstates.root">Download the ROOT data file</a></span>		

 </body>

</html>
