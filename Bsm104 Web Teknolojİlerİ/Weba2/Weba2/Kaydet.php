
<?php

$baslik=$_POST["baslik"];
$link=$_POST["link"];
$goster=$_POST["goster"];

$ksorgu="INSERT INTO `menuler` (`id`, `baslik`, `link`, `goster`) VALUES (NULL, '".$baslik."', '".$link."', '".$goster."');";
$esonuc=mysqli_query($baglanti,$ksorgu);

if($esonuc) header("Location:?sayfa=islemler");
else echo "Kayıt Eklenemedi";
?>
<a href="?sayfa=islemler">Anasayfa</a>