<?php
session_start();
include "baglanti.php";
	include "ust.php";
?>
<br><br><br>
<?php 
	echo @$_SESSION["email"];
?>
<br>
<?php
$page= @$_GET["page"];
if ($page=="anasayfa"){
	include "anasayfa.php";
} else if ($page=="galeri"){
	echo "galeri sayfası";
}else if ($page=="iletisim"){
	echo "iletisim sayfası";
} else if ($page=="login"){
	include "login.php";
}  else if ($page=="loginkontrol"){
	$kullanicilar=mysqli_query($bag, "SELECT * FROM `kullanicilar` WHERE `email` = '".$_POST["email"]."' AND `parola` = '".$_POST["parola"]."'");
	if(mysqli_num_rows($kullanicilar)==0){
		echo "Kullanıcı Parola Yanlış";
	} else {
		echo "Kullanıcı Girişi Başarılı";
		$_SESSION["email"]=$_POST["email"];
	}
	
	
} else if ($page=="logout"){
	//unset($_SESSION["email"]);
	session_destroy();
}

else {
	include "anasayfa.php";
}

?>	
	
<?php
include "alt.php";
?>