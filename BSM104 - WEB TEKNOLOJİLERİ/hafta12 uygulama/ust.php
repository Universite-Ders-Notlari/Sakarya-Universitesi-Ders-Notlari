<!DOCTYPE html>
<html lang="tr">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <title>Ümit KOCABIÇAK</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
		<!-- Font Awesome CSS -->
  <link rel="stylesheet" href="css/font-awesome.min.css" type="text/css" media="screen">	
	  <!-- ek stiller -->
    <link href="css/style.css" rel="stylesheet">
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="js/jquery-2.2.3.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>

  </head>
  <body>
   
	<!-- MENÜ ÇUBUĞU -->
<header class="navbar navbar-inverse navbar-fixed-top">
  <div class="container">
    <!-- Brand and toggle get grouped for better mobile display -->
    <div class="navbar-header">
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <a class="navbar-brand pad0" href="#">
	  <img src="images/ukocabicak.jpg" alt="Ümit KOCABIÇAK" title="Ümit KOCABIÇAK" width="50px" height="50px" class="img-circle">
	  </a>
    </div>
	<span class="logo-yani-yazisi text-info hidden-xs">
	<strong>Ümit KOCABIÇAK </strong>
	
	</span>

    <!-- Collect the nav links, forms, and other content for toggling -->
    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
      <ul class="nav navbar-nav">
       <?php
	   
	   $menuler=mysqli_query($bag,"SELECT * FROM `menuler` ORDER BY `menuler`.`sira`");
		while($kayit=mysqli_fetch_array($menuler)){
			echo "<li><a href='".$kayit["link"]."'>".$kayit["baslik"]."</a></li>";
		}
		if (isset($_SESSION["email"])){
			echo "<li><a href='?page=panel'>PANEL</a></li>";
		}

?>
      </ul>
     
      <ul class="nav navbar-nav navbar-right">
	  <li><a href="#">
		  <img width="25px" height="25px"  src="images/tr.png" title="TÜRKÇE" >
		
		  </a></li>
        <li><a href="#">
		 <img src="images/en.png" width="25px" height="25px" title="ENGLISH">
		</a></li>
	 </ul>
      </ul>
	  
	  <ul class="nav navbar-nav  navbar-right pad10">
        <?php
			if (isset($_SESSION["email"])){
				echo "<li>  <a href=\"?page=logout\"><button type=\"button\" class=\"btn btn-success btn-sm\">
	   <span class=\"glyphicon glyphicon-log-in\"></span>" .$_SESSION["email"]. "</button></a> 
	   </li>";
			} else {
		?>
      <li>  <button type="button" class="btn btn-primary btn-sm">
	  <span class="glyphicon glyphicon-user"></span> ÜYE OL</button> 
	  </li>
	   <li>  <a href="?page=login"><button type="button" class="btn btn-success btn-sm">
	   <span class="glyphicon glyphicon-log-in"></span> GİRİŞ </button></a> 
	   </li>
	 <?php
			}
	 ?>
    </ul>
    </div><!-- /.navbar-collapse -->
  </div><!-- /.container -->

	</header>