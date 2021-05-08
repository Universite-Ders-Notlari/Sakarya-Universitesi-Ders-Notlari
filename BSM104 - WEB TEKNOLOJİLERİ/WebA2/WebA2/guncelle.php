
<?php

$baslik=$_POST["baslik"];
$link=$_POST["link"];
$goster=$_POST["goster"];
$id=$_POST["id"];

$sorguguncelle="UPDATE `menuler` SET `baslik` = '".$baslik."', `link` = '".$link."', `goster` = '".$goster."' WHERE `menuler`.`id` = ".$id.";";
$gsonuc=mysqli_query($baglanti,$sorguguncelle);

if($gsonuc) header("Location:?sayfa=islemler");
else echo "Kayıt Güncellenemedi";
?>
<a href="?sayfa=islemler">Anasayfa</a>