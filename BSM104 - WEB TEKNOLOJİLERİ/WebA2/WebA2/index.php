<?php 
	include "baglanti.php";
	$sayfa=@$_REQUEST["sayfa"];
	$mail=@$_SESSION["mail"];
	$yetki=@$_SESSION["yetki"];
	include "ust.php";
	switch($sayfa)
	{
		case "guncelle":
			include "guncelle.php";
			break;
		case "islemler":
			include "listele.php";
			break;
		case "degistir":
			include "degistir.php";
			break;
		case "sil":
			include "sil.php";
			break;
		case "kaydet":
			include "kaydet.php";
			break;
		case "kayitekle":
			include "kayitekle.php";
			break;
		case "anasayfa":
			include "slider.php";
			include "orta.php";
			break;
		case "iletisim":
			include "iletisim.php";
			break;
		case "hakkimda":
			include "hakkimda.php";
			break;
		case "giris":
			include "giris.php";
			break;
		case "login":
			$maili=$_POST["mail"];
			$parola=$_POST["parola"];
			$sorgukontrol="SELECT * FROM `kullanicilar` WHERE `mail` LIKE '".$maili."' AND `parola` LIKE '".$parola."';";
			$sonuc=mysqli_query($baglanti,$sorgukontrol) or die("Sorgu Hatalı");
			$satir=mysqli_fetch_array($sonuc);
			if($satir)
			{
				$_SESSION["mail"]=$satir["mail"];
				$_SESSION["yetki"]=$satir["yetki"];
				header("Location:?sayfa=anasayfa");
			}
			else
				header("Location:?sayfa=anasayfa");			
			break;
		case "cikis":
			session_destroy();
			header("Location:?sayfa=anasayfa");			
			break;
		default:
			include "slider.php";
			include "orta.php";
			break;
	}
	
	include "alt.php";
	include "kapat.php";
?>	



	
