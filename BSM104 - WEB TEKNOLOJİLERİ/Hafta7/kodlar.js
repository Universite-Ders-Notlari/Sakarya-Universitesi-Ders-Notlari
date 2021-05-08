function kiloHesabi()
{
	var boy=parseInt(document.getElementById('boy').value);
	var yas=parseInt(document.getElementById('yas').value);
	var kilo=parseInt(document.getElementById('kilo').value);
	var c=document.getElementById('cinsiyet').value;
	var ikilo=0;
	if(c=="erkek")
		ikilo=(boy-100)*0.9+(yas/10);
	else if(c=="kadin") 
		ikilo=(boy-100)*0.8+(yas/10);
	else ikilo=-1;
	var fark=Math.round(ikilo)-kilo;
	var mesaj="";
	if(fark<0)
		mesaj=Math.abs(fark)+" kilo vermelisiniz";
	else if(fark>0) 
		mesaj=fark+" kilo almalısınız";
	else mesaj="Tebrikler";
	document.getElementById('ikilo').innerHTML+=mesaj;
}
var sayilar="0123456789";
var harfler="abcABC";
var karakterler="*-?,()";
function Kontrol()
{
	var isim=document.getElementById('isim').value;
	if(isim==''||isim==null) 
	{
		document.getElementById('uyari').innerHTML+="Lütfen isim alanını boş olarak geçmeyiniz";
		return false;
	}
	var bayrak1=0;
	var bayrak2=0;
	var bayrak3=0;
	var bayrak4=0;
	if(isim.length>7) bayrak4=1;
	for(i=0;i<isim.length;i++)
	{
		var karakter=isim.charAt(i);
		if(sayilar.indexOf(karakter)!=-1)
		{
			bayrak1=1;
		}
		if(harfler.indexOf(karakter)!=-1)
		{
			bayrak2=1;
		}
		if(karakterler.indexOf(karakter)!=-1)
		{
			bayrak3=1;
		}
	}
	
	if(bayrak1==0)
	{
		document.getElementById('uyari').innerHTML+="Lütfen en az bir rakam giriniz";
		return false;
	}
	if(bayrak2==0)
	{
		document.getElementById('uyari').innerHTML+="Lütfen en az bir harf giriniz";
		return false;
	}
	if(bayrak3==0)
	{
		document.getElementById('uyari').innerHTML+="Lütfen en az bir sembol giriniz";
		return false;
	}
	if(bayrak4==0)
	{
		document.getElementById('uyari').innerHTML+="Lütfen 8 karakterden fazla deger giriniz";
		return false;
	}		
}
function kontrol2()
{
	var isim=document.getElementById('isim').value;
	var bayrak1=0;
	var bayrak2=0;
	var bayrak3=0;
	var bayrak4=0;
	if(isim.length>7) bayrak4=1;
	for(i=0;i<isim.length;i++)
	{
		var karakter=isim.charAt(i);
		if(sayilar.indexOf(karakter)!=-1)
		{
			bayrak1=1;
		}
		if(harfler.indexOf(karakter)!=-1)
		{
			bayrak2=1;
		}
		if(karakterler.indexOf(karakter)!=-1)
		{
			bayrak3=1;
		}
	}
	var uzunluk=bayrak1+bayrak2+bayrak3+bayrak4;
	if(uzunluk==1)
		document.getElementById('sonuc').style.color="red";
	else if(uzunluk==2)
		document.getElementById('sonuc').style.color="orange";
	else if(uzunluk==3)
		document.getElementById('sonuc').style.color="yellow";
	else if(uzunluk==4)
		document.getElementById('sonuc').style.color="green";
	document.getElementById('sonuc').style.width=(uzunluk*100)+"px";	
	
}
function gonder()
{
	document.getElementById('form').submit();
}






function Hesapla()
{
	var metin=document.getElementById('metin').value;
	var deger=document.getElementById('sayi').value;
	var sonuc=metin.search(deger);
	document.getElementById('sonuc').innerHTML+=sonuc;
}