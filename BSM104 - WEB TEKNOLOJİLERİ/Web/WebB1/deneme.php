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
  
   <div style="font-size:16pt">
   <form action="kaydet.php" method="post">
   <div class="col-md-2">
   Başlık:
   </div>
   <div class="col-md-10">
   <input class="bg-info" type="text" name="baslik">
   </div>
   <div class="col-md-2">
   Link:
   </div>
   <div class="col-md-10">
   <input class="bg-info" type="text" name="link">
   </div>  
   <div class="col-md-2">
   </div>
   <div class="col-md-10">
   <input class="btn btn-info" type="submit" value="Kaydet">
   </div>   
   </form>
   </div>
   </body>
   </html>