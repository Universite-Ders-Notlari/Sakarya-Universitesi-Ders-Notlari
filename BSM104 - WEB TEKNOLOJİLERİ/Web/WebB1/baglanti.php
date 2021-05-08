<?php
    $baglanti=mysqli_connect("localhost","root","") or die("Veritabanı sunucusuna bağlanaılaması");
	mysqli_query($baglanti,"SET NAMES 'utf8'");
	mysqli_query($baglanti,"SET CHARACTER SET utf8_general_ci"); 
    $vt=mysqli_select_db($baglanti,"webtek") or die("veritabanına ulaşılamadı");
?>