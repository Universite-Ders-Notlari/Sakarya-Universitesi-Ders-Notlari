
<?php
include "baglanti.php";
include "ust.php";
?>
<div><br>&nbsp;</div>
<form method="post" action="kaydet.php">
<div class="bg-success">
<div class="col-md-2">
	Başlık:
</div>
<div class="col-md-10">
	<input type="text" name="baslik" class="bg-info">
</div>
<div class="col-md-2">
	Link:
</div>
<div class="col-md-10">
	<input type="text" name="link" class="bg-info">
</div>
<div class="col-md-2">
	
</div>
<div class="col-md-10">
	<input type="submit" value="Kaydet" class="btn btn-warning">
</div>


</div>
</form>


<?
mysqli_close($baglanti);
?>
</body>
</html>