<div class="container padTop20"> <!-- SLİDER ÇUBUĞU -->
	<div class="row">
	<div id="carousel-example-generic" class="carousel slide" data-interval="1000" data-ride="carousel">
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
    <li data-target="#carousel-example-generic" data-slide-to="1"></li>
 
  </ol>

  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <div class="item active">
      <img class = "fill" src="images/resim1.png" alt="SAÜ 1">
      <div class="carousel-caption">
        Sakarya Üniversitesi - 1
      </div>
    </div>
    <div class="item">
      <img class="fill" src="images/resim2.jpg" alt="SAÜ 2">
      <div class="carousel-caption">
        Sakarya Üniversitesi - 2
      </div>
    </div>
  
  </div>

  <!-- Controls -->
  <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>
	
	
	
	
	</div>

	
	
	
	
	<div class="row padTop20">
	<div class="col-md-4">  <!-- ETKİNLİKLER -->
	
	     
            <!-- Fluid width widget -->        
    	    <div class="panel panel-danger">
                <div class="panel-heading">
                    <h3 class="panel-title">
                        <span class="glyphicon glyphicon-calendar"></span>
                        ETKİNLİKLER
                    </h3>
                </div>
                <div class="panel-body">
                    <ul class="media-list">
                        <?php
							$etkinlikler=mysqli_query($bag,"Select * from etkinlikler");
							while($etkinlik=mysqli_fetch_array($etkinlikler)){
						?>		
							
						
						
						
						<li class="media">
                            <div class="media-left">
                                <div class="panel panel-danger text-center date">
                                    <div class="panel-heading month">
                                        <span class="panel-title strong">
                                            <?php 
											
											echo date("M",strtotime($etkinlik["tarih"]));
									?>
                                        </span>
                                    </div>
                                    <div class="panel-body day text-danger">
                                        <?php 
									echo date("d",strtotime($etkinlik["tarih"]));
									?>
                                    </div>
                                </div>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    <?php 
									echo $etkinlik["baslik"];
									?>
                                </h4>
                                <p>
                                    <?php 
									echo substr($etkinlik["icerik"],0,60);
									?>
                                </p>
                            </div>
                        </li>
                        <?php }  ?>
                        
                    </ul>
                    <a href="#" class="btn btn-danger btn-block">Tüm Etkinlikler »</a>
                </div>
            </div>
	</div>
	
	<div class="col-md-4">  <!-- DUYURULAR -->
		    <div class="panel panel-info">
                <div class="panel-heading">
                    <h3 class="panel-title">
                        <span class="glyphicon glyphicon-bullhorn"></span>
                        DUYURULAR
                    </h3>
                </div>
                <div class="panel-body">
                    <ul class="media-list">
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim img-rounded" src="images/mezuniyet.jpg" alt="">
								</a>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Pulvinar Mauris Eu
                                </h4>
                                <p>
                                    Vivamus pulvinar mauris eu placerat blandit. In euismod tellus vel ex vestibulum congue.
                                </p>
                            </div>
                        </li>
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim img-rounded" src="images/toren.jpg" alt="">
								</a>
                               
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Aenean Consectetur Ultricies
                                </h4>
                                <p>
                                    Curabitur vel malesuada tortor, sit amet ultricies mauris. Aenean consectetur asnbasbnsdbn shjsdhsdhj
                                </p>
                            </div>
                        </li>
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim img-rounded" src="images/kutuphane.jpg" alt="">
								</a>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Praesent Tincidunt
                                </h4>
                                <p>
                                    Sed convallis dignissim magna et dignissim. Praesent tincidunt sapien eu asjjsaj dssdhjsd sdjjdsjsd fdjkfdjk
                                </p>
                            </div>
                        </li>
                    </ul>
                    <a href="#" class="btn btn-info btn-block">Tüm Duyurular »</a>
                </div>
				</div>
	
	</div>
	
	<div class="col-md-4">  <!-- GÖRÜŞLER -->
	  <div class="panel panel-success">
                <div class="panel-heading">
                    <h3 class="panel-title">
                        <span class="glyphicon glyphicon-user"></span>
                        GÖRÜŞLER
                    </h3>
                </div>
                <div class="panel-body">
                    <ul class="media-list">
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim img-circle" src="images/ukocabicak.jpg" alt="">
								</a>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Ümit Kocabıçak
                                </h4>
                                <p>
                                    Boşuna paranıza yazık etmeyin. Buraya harcadığınız zamanda gidip gezin, dolaşın.
                                </p>
                            </div>
                        </li>
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim  img-circle" src="images/per2.jpg" alt="">
								</a>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Angelia Sundval
                                </h4>
                                <p>
                                    İngilizceyi Amerka'da bile böyle güzel öğretmiyorlar. Kaçırmayın. Böyle fırsat her zaman ele geçmez.
                                </p>
                            </div>
                        </li>
                        <li class="media">
                            <div class="media-left">
                                <a href="#">
									<img class="media-object duyuru-resim img-circle" src="images/per3.jpg" alt="">
								</a>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    Mark Zubery
                                </h4>
                                <p>
                                    Kişisel gelişim kursları bir harika. Bir daha bu kurstan sonra toplum içine çıkamıyorsunuz.
                                </p>
                            </div>
                        </li>
                    </ul>
                    <a href="#" class="btn btn-success btn-block">Tüm Görüşler »</a>
                </div>
	
	</div>
	
	</div>
	
	
	
	
	
	
	</div>