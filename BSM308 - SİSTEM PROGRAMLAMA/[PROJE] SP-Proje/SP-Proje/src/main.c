#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include "jrb.h"
#include "fields.h"
#include "main.h"

JRB siparisler, tmp;

//Girdinin sayi olup olmadıgı bakılıyor.
int sayimi(char number[])
{
	int i = 0;
	for (; number[i] != 0; i++)
	{
		if (number[i] > '9' || number[i] < '0')
			return 0;
	}
	return 1;
}

void Prompt()
{
  printf("Odev > ");
}

typedef struct {
  int sipKey;
  char *sipAd;
  char *sipMalzeme;
  char *sipRenk;
} Siparis;

//Program komutları.
char *builtin_str[]={
	"add",
	"search",
	"write",
	"print",
	"quit",
	"help"
};

//Program komutlarının açıklamaları. "help"
char *builtin_aciklama[]={
	"Siparis Ekleme. \n\tKullanim:  \"add|-sipKey-|-sipAd-|-sipMalezeme-|-sipRenk-\"",
	"Siparis arama. \n\tKullanim : \"search|-sipKey-\"",
	"Siparisleri dosyaya yazdirma. \n\tKullanim : \"write|fileName\"",
	"Siparisleri ekrana yazdirma. \n\tKullanim : \"print\"",
	"Cikis. \n\tKullanim : \"quit\"",
	"Yardim. \n\tKullanim : \"help\"",
};

//Builtin komutlarının fonksiyonunlarının adres dizisi.
int (*builtin_func[])(char**) = { 
	&builtin_add,
	&builtin_search,
	&builtin_write,
	&builtin_print,
	&builtin_quit,
	&builtin_help
};

//Toplam builtin komutsayısı
int builtinadeti()
{
	return sizeof(builtin_str)/sizeof(char *);
}

int builtin_add(char **args)
{
	int arg;

	//Argüman sayısı kontrolu
	for(arg = 0; arg <= 4; arg++)
	{
		if(args[arg] == NULL)
		{
			printf("Bicim uygun degil. Yetersiz arguman\n");
			return 0;
		}
	}
	if(args[5]){
			printf("Bicim uygun degil. Fazla arguman.\n");
			return 0;
	}

	//Siparis Key'in sayi olması kontrolu
	if(!sayimi(args[1]))
	{
		printf("Bicim uygun degil. Siparis Key bir sayi olmali.\n");
		return 0;
	}

	//Her bir karakter katarına uzunluğu kadar bellek yeri vermek için nsize kullanıldı.
	int nsize, i;

	Siparis *siparis;
	siparis = malloc(sizeof(Siparis));
	siparis->sipKey = atoi(args[1]);

	nsize = strlen(args[2]);
	siparis->sipAd = (char *) malloc(sizeof(char)*(nsize+1));
	strcpy(siparis->sipAd, args[2]);

	nsize = strlen(args[3]);
	siparis->sipMalzeme = (char *) malloc(sizeof(char)*(nsize+1));
	strcpy(siparis->sipMalzeme, args[3]);

	nsize = strlen(args[4]);
	siparis->sipRenk = (char *) malloc(sizeof(char)*(nsize+1));
	strcpy(siparis->sipRenk, args[4]);

	//Sipariş keyleri unique olduğundan mevcut ağaçta aynı keyde sipariş varmı kontrolu yapılıyor.
	tmp = jrb_find_int(siparisler, siparis->sipKey);
	if (tmp == NULL) 
	{
		//Key bosta iste agaca ekleniyor.
		jrb_insert_int(siparisler, siparis->sipKey, new_jval_v((void *) siparis));
		return 1;
	} 
	printf("Zaten %d numarali key'e sahip bir siparis var.\n", siparis->sipKey);
	return 0;

}

int builtin_search(char **args)
{
	Siparis *siparis;
	if(!sayimi(args[1]))
	{
		printf("Bicim uygun degil. Siparis Key bir sayi olmali.\n");
		return 0;
	}
	int key = atoi(args[1]);

	/*jrb_fin_int fonksiyonunda verilen değer ile,
	**ağacın düğümlerinin key'i ile kıyaslanır.
	**Eğer eşit olan bulunamazsa NULL döner.*/
	tmp = jrb_find_int(siparisler, key);
	if (tmp == NULL) 
	{
		printf("%d key numarasina sahip bir siparis yok.\n", key);
		return 0;
	}

	//Eğer eşit olan bulunursa tmp->val.v istediğimiz sipariş değeridir.
	siparis = (Siparis *) tmp->val.v;
	printf("%d, %s, %s, %s\n",siparis->sipKey, siparis->sipAd, siparis->sipMalzeme, siparis->sipRenk);
	return 1;
}

int builtin_write(char **args)
{

	DIR *dir;
	//Bulunduğumuz dizini belirttik.
	dir = opendir(".");
	FILE *fil;
	//standard girdinin 2. tokeni dosya adıdır.
	fil = fopen(args[1], "w");
	if (fil == NULL){
		printf( "HATA: Output dosyasi belirtmediniz.\n");
		printf("Write \tKullanim : \"write|fileName\"\n");
		return 0;
	}
	//jrb_traverse siparisKeyleri kendiliğinden sıralayarak verecektir.
	jrb_traverse(tmp, siparisler) {
		Siparis *siparis = (Siparis *) tmp->val.v;
		//Yazdırılıken bir sonraki okuma icin kaydedilecek.Ekrana yazdırıldıgı gibi degil.
		fprintf(fil, "add|%d|%s|%s|%s\n",siparis->sipKey, siparis->sipAd, siparis->sipMalzeme, siparis->sipRenk);
	}
	fclose(fil);
	closedir(dir);
	return 1;
}

int builtin_print(char **args)
{

	//jrb_empty() fonksiyonu eğer ağaçta veri varsa 1 döndürür.
	if(jrb_empty(siparisler)){
		printf("Herhangi bir sipariş bulunamadi.\n");
		return 0;
	}

	//jrb_traverse siparisKeyleri kendiliğinden sıralayarak verecektir.
	jrb_traverse(tmp, siparisler) {
		Siparis *siparis = (Siparis *) tmp->val.v;
		printf("%d, %s, %s, %s\n",siparis->sipKey, siparis->sipAd, siparis->sipMalzeme, siparis->sipRenk);
  }
	return 1;
}

int builtin_quit(char **args)
{
	//Çıkış yapmadan önce hafıza temizlenecek.
	clearMemory();
	int status;
	/*Calisan child process'ler varsa onları bekleyecek.
	**Burada Fork yapılmadığından hiç bir zaman child process olmayacak.*/
	while (!waitpid(-1,&status,WNOHANG)){}
	//Sonra da cikacak.
	exit(0);
}

int builtin_help(char **args)
{
	int i;
	printf("\n***Komut Yardimi***\n\n");
	for (i=0;i<builtinadeti();i++)
	{
		printf("-%s\t%s\n\n",builtin_str[i],builtin_aciklama[i]);
	}
	return 1;
}

int clearMemory()
{
	//JRB ağacını siler.
	jrb_free_tree(siparisler);
	return 1;
}

//Birinci argümanda verilen komutun ne olduğunu çözümler.
int komutIsleyicisi(char *args[]){

	/*m 0 ise builtin_str[0] add
	**m 1 ise builtin_str[1] search*/
	int m;
	for (m = 0 ; m < builtinadeti() ; m++)
	{
		if (strcmp(args[0],builtin_str[m]) == 0)
		{
			/*Yukarıda fonksiyonun adreslerini bir diziye atamamıştık.
			**Dizilerin sırası ve boyutu aynı olduğundan.
			**çözümlenen builtin fonksiyonunu çağırır.*/
			(*builtin_func[m])(args);
			return 1;
		}
	}
	printf("%s komutu bulunamadi.\n",args[0]);
}

int main(int argc, char **argv, char **envp)
{
	//siparisleri tutacak jrb ağacı.
	siparisler = make_jrb();

	//standard girdiyi tutacak maximum 1024 eleman alabilecek standard girdi dizisi.
	char line[MAXLINE];
	int countToken;
	int status = 1;

	//standard girdide '|' ile ayrılacak olan tokenleri tutacak.
	char *token[MAXTOKEN];
	
	while(status)
	{
		//standart girişe ayrılan bellek bölümünü \0 ile doldurur.
		memset(line, '\0',MAXLINE);

		//Bu fonksiyon standard girişin klavyeden yapılıp yapılmadığını kontrol ediyor.
		if(isatty(STDIN_FILENO))
		{
			Prompt();

			//klavyeden standart girdi ister.
			fgets(line, MAXLINE, stdin);
		}

		//Standard girdi klavyeden değil ise dosyadan standard girdi alınacak.
		else
		{
			//dosyanın sonuna gelindiğinde null değeri dönecektir.
			if (fgets(line, MAXLINE, stdin) == NULL)
			{
				//dosya sona ulaştığında. standard girdi klavyeye yönlendirildi.
				freopen("/dev/tty", "rw", stdin);
				Prompt();

				//Klavyeden standard girdi alacak ve birdaha else bloğuna girilmeyecek.
				fgets(line, MAXLINE, stdin);
			}
		}
		//Örnek olarak girdi add|24|ball|silicon|green

		/*herhangi bir argüman verilmediyse while döngüsü devam edecektir.
		**strtok girdiyi '|' karakteriyle parse edecektir.
		**bu şekilde tüm tokenler ayrılacak.*/
		if((token[0] = strtok(line,"|\n")) == NULL) continue;
		
		/*Yukarıda ilk tokeni kontrol ettik.
		**yani add var. token[0]=add oldu.
		**Hiç token yoksa buraya gelinmez.*/
		countToken = 1;

		//Girdiyi tekrardan parse ediyoruz varsa diğer tokenleri da ayırıyoruz.
		while((token[countToken] = strtok(NULL, "|\n")) != NULL) 
		{
			countToken++;
		}

		//token = {add, 24, ball, silicon, green} oldu. 5 elemanlı.
		//verilen girdi parse edildi. komut işleyicisine bu tokenları gönderiyoruz.
		komutIsleyicisi(token);
	}
  return 0;
}
