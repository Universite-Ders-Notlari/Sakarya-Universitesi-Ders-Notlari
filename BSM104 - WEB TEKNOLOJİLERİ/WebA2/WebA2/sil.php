<?php
if($mail)
{


$id=$_GET["id"];

$sorgusil="DELETE FROM `menuler` WHERE `menuler`.`id` = ".$id.";";
$ssonuc=mysqli_query($baglanti,$sorgusil) or die("Soru hatalı");

if($ssonuc) header("Location:?sayfa=islemler");
else echo "Kayıt Silinemedi";
?>
<a href="?sayfa=islemler">Anasayfa</a>
<?php
}
else
{
	echo "giriş yetkiniz yoktur";
}
?>