<?php 
	include "baglanti.php"; 
	include "ust.php"; 
	$sayfa=@$_GET["sayfa"];
	switch($sayfa)
	{
	case "anasayfa":
		include "slider.php"; 
		include "orta.php";
		break;
	case "hakkimda":
		include "hakkimda.php";
		break;
	case "resimler":
		include "resimler.php";
		break;
	default:
		include "slider.php"; 
		include "orta.php";
		break;
	}
	 
	include "alt.php"; 
	include "kapat.php"; 	
?>	

	
	
	
	
	

	
