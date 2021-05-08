<div><br>&nbsp;</div>
<?php
$id=$_GET["id"];

$sorguekle="SELECT * FROM `menuler` WHERE `id` = ".$id." ORDER BY `id` DESC;";
$sonuc=mysqli_query($baglanti,$sorguekle) or die("Sorfgu Hatalı")
;
$satir=mysqli_fetch_array($sonuc);
?>
<form method="post">
<div class="bg-success">
<div class="col-md-2">
	Başlık:
</div>
<div class="col-md-10">
	<input type="text" name="baslik" class="bg-info" value="<?php echo $satir["baslik"];?>">
</div>
<div class="col-md-2">
	Link:
</div>
<div class="col-md-10">
	<input type="text" name="link" class="bg-info" value="<?php echo $satir["link"];?>">
</div>
<div class="col-md-2">
	Gösterilsin mi?:
</div>
<div class="col-md-10">
	<input type="text" name="goster" class="bg-info" value="<?php echo $satir["goster"];?>">
</div>
<div class="col-md-2">
	
</div>
<div class="col-md-10">
	<input type="hidden" value="<?php echo $satir["id"];?>" name="id">
	<input type="hidden" value="guncelle" name="sayfa">
	<input type="submit" value="Güncelle" class="btn btn-warning">
</div>


</div>
</form>