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
					$esorgu="SELECT * FROM `etkinlikler`";
					$esonuc=mysqli_query($baglanti,$esorgu) or die("Sorgu çalıştırılamadı");
					while($esatir=mysqli_fetch_array($esonuc))
					{
					?>
                        <li class="media">
                            <div class="media-left">
                                <div class="panel panel-danger text-center date">
                                    <div class="panel-heading month">
                                        <span class="panel-title strong">
                                            <?php
											echo date("M",strtotime($esatir["tarih"]));
											?>
                                        </span>
                                    </div>
                                    <div class="panel-body day text-danger">
                                        <?php
											echo date("d",strtotime($esatir["tarih"]));
											?>
                                    </div>
                                </div>
                            </div>
                            <div class="media-body">
                                <h4 class="media-heading">
                                    <?php
											echo $esatir["baslik"];
									?>
                                </h4>
                                <p>
																									<?php
											echo substr($esatir["icerik"],0,80);
									?>
                                </p>
                            </div>
                        </li>
					<?php
					}
					?>
                    </ul>
                    <a href="#" class="btn btn-danger btn-block">Tüm Etkinlikler »</a>
                </div>
            </div>
	</div>
