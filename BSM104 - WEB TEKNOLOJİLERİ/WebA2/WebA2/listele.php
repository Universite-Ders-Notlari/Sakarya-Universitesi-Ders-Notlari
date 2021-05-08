
<div>
<br>&nbsp;</div>
<?php
if($mail)
{
?>
<div class="bg-warning"><a href="?sayfa=kayitekle">Kayıt Ekle</a></div>
<?php
$sorguliste="SELECT * FROM `menuler` ORDER BY `menuler`.`id` DESC;";
$sonuc=mysqli_query($baglanti,$sorguliste) or die("Sorguda hata var");
?>
<div>
<div class="col-md-3 bg-info">
<b>Başlık</b>
</div>
<div class="col-md-3 bg-info">
Link
</div>
<div class="col-md-3 bg-info">
Göster
</div>
<div class="col-md-3 bg-info">
İşlemler
</div>
</div>
<?php
while($satir=mysqli_fetch_array($sonuc))
{
?>
<div>
<div class="col-md-3">
<?php echo $satir["baslik"];?>
</div>
<div class="col-md-3">
<?php echo $satir["link"];?>
</div>
<div class="col-md-3">
<?php if($satir["goster"]) echo "gösterilecek";
	  else echo "gösterilmeyecek";
?>
</div>
<div class="col-md-3">
<a href="?sayfa=sil&id=<?php echo $satir["id"];?>
">Sil</a> .:|:.
<a href="?sayfa=degistir&id=<?php echo $satir["id"];?>
">Değiştir</a>
</div>
</div>
<?php
}
}
else
{
	echo "giriş yetkiniz yoktur";
}
?>
