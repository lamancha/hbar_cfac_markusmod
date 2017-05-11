    <SCRIPT>
       <!--
       function isNumberKey(evt)
       {
          var charCode = (evt.which) ? evt.which : event.keyCode;
          if (charCode != 46 && charCode > 31 && ( charCode != 45 )
            && (charCode < 48 || charCode > 57)) 
             return false;

          return true;
       }
       //-->
    </SCRIPT>


  <?php require("variable_init.php"); $fieldValues = getFields(true);?>


<table class="redborder-table">
<tr><td>
<form action="index.php" method="get">
<table class="border-table">
<tr>
<td>Query type:</td>
<td><label><input type="radio" name="qtype" value="0" <?=$fieldValues['qType']==0?"checked":"";?> style="vertical-align: middle; margin: 0px;" onclick="MainStateSwitch()"> Single decay</label></td>
<td><label><input type="radio" name="qtype" value="1" <?=$fieldValues['qType']==1?"checked":"";?> style="vertical-align: middle; margin: 0px;" onclick="MainStateSwitch()"> Main FROM</label></td>
<td><label><input type="radio" name="qtype" value="2" <?=$fieldValues['qType']==2?"checked":"";?> style="vertical-align: middle; margin: 0px;" onclick="MainStateSwitch()"> Main TO</label></td>
</tr>
</table>
</form>
  <?php ///Used to simplify form below.
  $ShortStr1="validateConsistency(0 + document.getElementsByName('qtype')[1].checked?1:0 + document.getElementsByName('qtype')[2].checked?2:0, 
  						 document.getElementsByName('upperN')[0].value,
						 document.getElementsByName('upperL')[0].value,
						 document.getElementsByName('upperJ')[0].value,
						 document.getElementsByName('upperMJ')[0].value,
						 document.getElementsByName('upperP')[0].value,
						 document.getElementsByName('lowerN')[0].value,
						 document.getElementsByName('lowerL')[0].value,
						 document.getElementsByName('lowerJ')[0].value,
						 document.getElementsByName('lowerMJ')[0].value,
						 document.getElementsByName('lowerP')[0].value,
						 document.getElementsByName('fieldB')[0].value,
						 document.getElementsByName('nEntries')[0].value,
						 document.getElementsByName('showTotal')[0].checked?1:0
						 )";
  $ShortStr2="loadResult(0 + document.getElementsByName('qtype')[1].checked?1:0 + document.getElementsByName('qtype')[2].checked?2:0, 
  						 document.getElementsByName('upperN')[0].value,
						 document.getElementsByName('upperL')[0].value,
						 document.getElementsByName('upperJ')[0].value,
						 document.getElementsByName('upperMJ')[0].value,
						 document.getElementsByName('upperP')[0].value,
						 document.getElementsByName('lowerN')[0].value,
						 document.getElementsByName('lowerL')[0].value,
						 document.getElementsByName('lowerJ')[0].value,
						 document.getElementsByName('lowerMJ')[0].value,
						 document.getElementsByName('lowerP')[0].value,
						 document.getElementsByName('fieldB')[0].value,
						 document.getElementsByName('nEntries')[0].value,
						 document.getElementsByName('showTotal')[0].checked?1:0
						 )";
  ?>
<form action="index.php" method="get">
    <table class="border-table">
        <tr class="border-bottom">
        <th class="border-side"></th>
        <th class="border-side" id="upperCol0" >Upper state</th>
        <th class="border-side" id="lowerCol0">Lower state</th>
        </tr>
    <tr>
	  <td>n </td><td id="upperCol1" class="border-side"><input class="tb5" type="text" size="3" name="upperN" value="<?=$fieldValues['upperN']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)"  ></td>
  	  <td class="border-side" id="lowerCol1"><input class="tb5" type="text" size="3" name="lowerN" value="<?=$fieldValues['lowerN']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
	</tr>
  	<tr>
	  <td>l</td><td id="upperCol2" class="border-side"><input class="tb5" type="text" size="3" name="upperL" value="<?=$fieldValues['upperL']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
  	  <td class="border-side" id="lowerCol2"><input class="tb5" type="text" size="3" name="lowerL" value="<?=$fieldValues['lowerL']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
	  </tr>
  	<tr>
  	<td>2&middot;j </td><td id="upperCol3" class="border-side"><input class="tb5" type="text" size="3" name="upperJ" value="<?=$fieldValues['upperJ']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
  	<td class="border-side" id="lowerCol3"><input class="tb5" type="text" size="3" name="lowerJ" value="<?=$fieldValues['lowerJ']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
	  </tr>
  	<tr>
  	<td>2&middot;m<sub>j</sub> </td><td id="upperCol4" class="border-side"><input class="tb5" type="text" size="3" name="upperMJ" value="<?=$fieldValues['upperMJ']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
  	<td class="border-side" id="lowerCol4"><input class="tb5" type="text" size="3" name="lowerMJ" value="<?=$fieldValues['lowerMJ']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
  	  </tr>
  	<tr class="border-bottom">
	  <td>p</td><td class="border-side" id="upperCol5" ><input class="tb5" type="text" size="3" name="upperP" value="<?=$fieldValues['upperP']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
  	<td class="border-side" id="lowerCol5"><input class="tb5" type="text" size="3" name="lowerP" value="<?=$fieldValues['lowerP']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" ></td>
	  </tr>
    <tr class="border-top border-bottom">
      <td colspan="2">Magnetic field </td><td class="border-side"><input class="tb6" type="text" size="5" name="fieldB" value="<?=$fieldValues['fieldB']?>" onkeyup="<?=$ShortStr1?>" onkeypress="return isNumberKey(event)" >T</td>
    </tr>
    <tr class="border-top border-bottom" id="EntriesRow0">
      <td colspan="2"> # Entries </td><td class="border-side"><input class="tb5" type="text" size="5" name="nEntries" value="<?=$fieldValues['nEntries']?>" onkeypress="return isNumberKey(event)" ></td>
	</tr>
	<tr id="EntriesRow1">
	  <td colspan="3"> <label><input style="vertical-align: middle; margin: 0px;" type="checkbox" name="showTotal" <?=$fieldValues['showTotal']==1?"checked":"";?> >Include total rate</label></td>
    </tr>

    </table>
	<table class="noborder-table">
	<tr><td id="validationErrMsg"></td><td><input type="button" name="submitButton" value="Go" onClick="<?=$ShortStr2?>" id="submit-button"></td></tr>
	</table>
  </form>
</td></tr></table>

<script>
function MainStateSwitch()
{
	var radios = document.getElementsByName('qtype');

	var states = new Array();

	if(radios[0].checked || radios[1].checked)
	{
		states[0] = '';
	}
	else
	{
		states[0] = 'none';
	}

	if(radios[0].checked || radios[2].checked)
	{
		states[1] = '';
	}
	else
	{
		states[1] = 'none';
	}

	if(radios[0].checked)
	{
		document.getElementById('EntriesRow0').style.display = 'none';
		document.getElementById('EntriesRow1').style.display = 'none';

	}
	else
	{
		document.getElementById('EntriesRow0').style.display = '';
		document.getElementById('EntriesRow1').style.display = '';
	}


	<?php
	for($i=0;$i<=5;++$i)
	{
		echo "document.getElementById('upperCol", $i, "').style.display = states[0]\n";
		echo "document.getElementById('lowerCol", $i, "').style.display = states[1]\n";
	}
	?>

	<?=$ShortStr1?>

}
MainStateSwitch();
</script>
