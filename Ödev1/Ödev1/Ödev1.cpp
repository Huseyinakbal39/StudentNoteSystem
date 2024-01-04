/******************************************************************************************************************************************************
													SAKARYA ÜNİVERSİTESİ
										  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
											  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
												PROGRAMLAMAYA GİRİŞ DERSİ
												  ÖDEV NUMARASI:1.ÖDEV
												  ÖGRENCİ ADI:HÜSEYİN AKBAL
												  ÖGRENCİ NUMARASI:G211210069
												  DERS GRUBU:2.ÖĞRETİM C GRUBU
*********************************************************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

int secenek = 0;

char menuSecenek;

int menu;

int aralik1, aralik2;

int altDeger, ustDeger;
int girilecekOgrenci;

struct ogrenci
{
	string adi, soyAdi, No, harfNotu;//İşlem yapılmayacağı için numarayı da string tanımladım.
	float kisaSinav1, kisaSinav2, odev1, odev2, proje, vize, final, basariNotu;
	struct tarih {
		string gun, ay, yil;
	};
	tarih dogumGunu;	
};

ogrenci ogrenciListe[100];

string isim[30] =
{ "Huseyin","Dilara","Berkay","Zeki","Ahmet","Can","Zeynep","Melike","Ayberk","Eren","Cagdas","Uygar","Elif","Behlul",
"Ece","Sena","Eylul","Gozde","Berna","Berat","Kadir","Ceren","Akif","Samet","Melih","Yaren","Ali","Yunus","Cagla","Sema" };
string soyIsim[30] =
{ "Akbal","Cetin","Congar","Sonmez","Bilgin","Korkmaz","Koc","Sabanci","Altun","Yuksel","Tuncer","Gunduz"
,"Akcayol","Duganci","Tekin","Ugur","Ekmekci","Ozarslan","Avuz","Babacan","Demir","Donmez","Buyukbayrak","Isik","Tunc","Tutuncu","Ay","Abaci","Turcan","Varol" };

void harfNot()
{
	for (int i = 0; i < 100; i++)//100 Öğrencinin başarı notlarına göre harf notunu almak için 0 dan 99 a kadar olan öğrenciler for döngüsüyle alınacak.
	{


		if (ogrenciListe[i].basariNotu < 100 && ogrenciListe[i].basariNotu >= 90)//Girilen notun harf değerini bastıran belli aralıklarda olmasını if elseler ile çıkartılması için böyle bir fonksiyon yazdım.
			ogrenciListe[i].harfNotu = "AA";
		else if (ogrenciListe[i].basariNotu < 90 && ogrenciListe[i].basariNotu >= 85)
			ogrenciListe[i].harfNotu = "BA";
		else if (ogrenciListe[i].basariNotu < 85 && ogrenciListe[i].basariNotu >= 80)
			ogrenciListe[i].harfNotu = "BB";
		else if (ogrenciListe[i].basariNotu < 80 && ogrenciListe[i].basariNotu >= 75)
			ogrenciListe[i].harfNotu = "CB";
		else if (ogrenciListe[i].basariNotu < 75 && ogrenciListe[i].basariNotu >= 70)
			ogrenciListe[i].harfNotu = "CC";
		else if (ogrenciListe[i].basariNotu < 70 && ogrenciListe[i].basariNotu >= 65)
			ogrenciListe[i].harfNotu = "DC";
		else if (ogrenciListe[i].basariNotu < 65 && ogrenciListe[i].basariNotu >= 60)
			ogrenciListe[i].harfNotu = "DD";
		else if (ogrenciListe[i].basariNotu < 60 && ogrenciListe[i].basariNotu >= 50)
			ogrenciListe[i].harfNotu = "FD";
		else
			ogrenciListe[i].harfNotu = "FF";

	}
}
float notDogrulugu(string s, float sayi)
{
	while (!(sayi >= 0 && sayi <= 100))//Girilin değerin 0 ve 100 arasında olmasını sağlamak için while döngüsüyle birlikte bir fonksiyon oluşturdum.
	{
		cout << s << " " << "degerini tekrar giriniz : "; cin >> sayi;
	}
	return sayi;
}

void vizeRan()
{

	for (int i = 0; i < 100; i++)//Bütün girilmesi gereken not değerlerini aynı şekilde for döngüsü yaparak random atanmasını sağladım.	
	{

		if (i < 10) {//İlk 10 öğrencinin belirtilen aralıkta random olması için for dönügüs içinde if kalıbıyla beraber bunu her sınav değeri için sağladım.
			int randomSayi = rand() % 40;
			ogrenciListe[i].vize = randomSayi;
		}

		else if (i >= 10 && i < 60) {//10 dahil ve 60 arasındaki ögrencilerin notlarını döngü ile random atadım.

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].vize = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].vize = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].vize = randomSayi;

		}


	}
}
void finalRan()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].final = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].final = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].final = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].final = randomSayi;

		}


	}
}
void kisaSinav1Ran()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].kisaSinav1 = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].kisaSinav1 = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].kisaSinav1 = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].kisaSinav1 = randomSayi;

		}


	}
}
void kisaSinav2Ran()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].kisaSinav2 = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].kisaSinav2 = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].kisaSinav2 = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].kisaSinav2 = randomSayi;

		}


	}
}
void odev1Ran()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].odev1 = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].odev1 = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].odev1 = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].odev1 = randomSayi;

		}


	}
}
void odev2Ran()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].odev2 = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].odev2 = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].odev2 = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].odev2 = randomSayi;

		}


	}
}
void projeRan()
{

	for (int i = 0; i < 100; i++)
	{

		if (i < 10) {
			int randomSayi = rand() % 40;
			ogrenciListe[i].proje = randomSayi;
		}

		else if (i >= 10 && i < 60) {

			int randomSayi = rand() % 30 + 40;
			ogrenciListe[i].proje = randomSayi;

		}

		else if (i >= 60 && i < 75)
		{
			int randomSayi = rand() % 10 + 70;
			ogrenciListe[i].proje = randomSayi;
		}

		else
		{
			int randomSayi = rand() % 20 + 80;
			ogrenciListe[i].proje = randomSayi;

		}


	}
}


void isimRan()
{

	for (int i = 0; i < 100; i++)//isim ve soyisim fonksiyonlarında randomSayi değişkenini random atayıp random sayiya göre rastgele isim ve soyisim çıkmasın sağladım.
	{

		int randomSayi = rand() % 30;
		ogrenciListe[i].adi = isim[randomSayi];

	}
}


void soyIsimRan()
{

	for (int i = 0; i < 100; i++)
	{

		int randomSayi = rand() % 30;
		ogrenciListe[i].soyAdi = soyIsim[randomSayi];

	}
}

void numaraRan()
{
	for (int i = 0; i < 100; i++)//Her ogrenci icin 100.000 ve 101.000 arasında random numara çeviren fonksiyon.
	{
		int randomSayi = rand() % 1000 + 100000;
		ogrenciListe[i].No = to_string(randomSayi);//Numarayı structta string belirlediğim için stringe sayıya çevirdim to_string komutuyla.

	}
}

void basariNotHesaplama()
{
	for (int i = 0; i < 100; i++)//Her öğrencinin bütün sınav değerleriyle yıl içi notunu hesaplayıp başarı notunu hesaplayan fonksiyon.
	{
		float yilIciNot = (ogrenciListe[i].vize * 0.5) + (ogrenciListe[i].kisaSinav1 * 0.07) + (ogrenciListe[i].kisaSinav2 * 0.07) + (ogrenciListe[i].odev1 * 0.1)
			+ (ogrenciListe[i].odev2 * 0.1) + (ogrenciListe[i].proje * 0.16);
		ogrenciListe[i].basariNotu = (ogrenciListe[i].final * 0.45) + (yilIciNot * 0.55);

	}

}

void dogumGunRand()
{
	int randomYil;
	int randomAy;
	int randomGun;
	for (int i = 0; i < 100; i++)//Her öğrencinin doğum gününün belirlenmesi için yine 100 döngülük bir for döngüsü oluşturdum.
	{
		randomYil = rand() % 5 + 2000;
		if (randomYil % 4 == 0) {//Tarih belirlerken şubat ayı 4 yılda bir 29 gün olabildiği için 4 yılda bir dönen yıl varsa 29-0 arasında değerleri random atamasını sağladım if ve elseler yadımıyla.
			randomAy = rand() % 12 + 1;
			if (randomAy == 2) {//Aylar 30 ve 31 gün olabileceği için her ayın durumunu teker teker yazdım ve sonucunda 30 -0 ve 31-0 arasında random günler aya göre atanabilecek.
				randomGun = rand() % 29 + 1;
			}
			else if (randomAy == 4 || randomAy == 6 || randomAy == 9 || randomAy == 11)//Şubat ayının 4 yılda bir denk gelmeyen kısımları için else if le beraber şubat ayının durumunu belirttim diğer değerler aynı.
				randomGun = rand() % 30 + 1;
			else
				randomGun = rand() % 31 + 1;
		}
		else {
			randomAy = rand() % 12 + 1;
			if (randomAy == 2) {
				randomGun = rand() % 28 + 1;
			}
			else if (randomAy == 4 || randomAy == 6 || randomAy == 9 || randomAy == 11)
				randomGun = rand() % 30 + 1;
			else
				randomGun = rand() % 31 + 1;
		}
		ogrenciListe[i].dogumGunu.yil = to_string(randomYil);//dogum günü değerlerini tarih structında string belirlediğimiz için stringi sayıya çevirmek içi to_string kalıbını kullandım.
		ogrenciListe[i].dogumGunu.ay = to_string(randomAy);
		ogrenciListe[i].dogumGunu.gun = to_string(randomGun);
	}

}

float enYuksekNot()//Menu2
{
	float enYuksekNot = ogrenciListe[0].basariNotu;
	for (int i = 0; i < 100; i++)//Her öğrencinin başarı notunu çıkartıp if yardımıyla en büyük olanı atayıp onu return eden fonksiyonu yazdım.
	{

		if (enYuksekNot <= ogrenciListe[i + 1].basariNotu && i != 99)//i 99 olursa i + 1 den 100 gelip boş çıkacağı için 99 olmamasını sağladım ve notların büyüklük durumunu karşılaştırdım.
		{
			enYuksekNot = ogrenciListe[i + 1].basariNotu;

		}

	}
	return enYuksekNot;
}

float enDusukNot()//Menu3
{
	float enDusukNot = ogrenciListe[0].basariNotu;
	for (int i = 0; i < 100; i++)//Her öğrencinin başarı notunu çıkartıp if yardımıyla en küçük olanı atayıp onu return eden fonksiyonu yazdım.
	{
		if (enDusukNot >= ogrenciListe[i + 1].basariNotu && i != 99)
		{
			enDusukNot = ogrenciListe[i + 1].basariNotu;
		}

	}
	return enDusukNot;
}

float ortalamaHesaplama()//Menu4
{
	float aritmetikNot = 0;
	for (int i = 0; i < 100; i++)//Bütün öğrencilerin döngü yardımıyla teker teker toplanıp en son bulunan değerin öğrenci sayısına bölümü return edilen fonksiyonu yazdım.
	{

		aritmetikNot += ogrenciListe[i].basariNotu;

	}
	return aritmetikNot / 100;
}

float standartSapma()//Menu5
{
	float varyans;

	for (int i = 0; i < 100; i++)//Standart sapmayı bulmak için her öğrencinin başarı notu sayesiyle varyans hesapladım ortalama da varyans için gerektiği için fonksiyonu işleme ekledim.
	{
		varyans = sqrt(pow(ogrenciListe[i].basariNotu - ortalamaHesaplama(), 2) / 99);

	}
	return varyans;
}
void ogrenciYazdir()//Menu 1 Öğrencilerin listesini çıkartan fonksiyon
{
	for (int i = 0; i < 100; i++)//Her öğrencinin her değerinin çıkartılması için for döngüsüyle fonksiyon sağladım
	{
		if (i % 20 == 0) {//Her seferde 20 öğrenci yazılıp silinmesini medyan ve ifle sağladım.Ve daha uygun gözükmesi için setw ile boşluklarını verdim
			system("Pause");
			system("CLS");
			cout << setw(40) << "final" << setw(5) << "vize" << setw(5) << "1.KS" << setw(5) << "2.KS" << setw(5) << "1.Odev"
				<< setw(5) << "2.Odev" << setw(5) << "Proje" << " " << "BasariNot" << setw(5) << "HarfNot" <<setw(5)<<"DogumTarih" << endl;

		}
		int uzunluk = ogrenciListe[i].adi.length() + ogrenciListe[i].soyAdi.length();//Aradaki uzunluk kadar boşluk vermek istedim o yüzden uzunluk tanımlayıp setw yardımıyla eşit aralık verdim.

		cout << i + 1 << ".Ogrenci " << ogrenciListe[i].adi << " " << ogrenciListe[i].soyAdi << " " << ogrenciListe[i].No << " " << setw(20 - uzunluk) <<
			ogrenciListe[i].final << setw(5) << ogrenciListe[i].vize << setw(5) << ogrenciListe[i].kisaSinav1 << setw(5) <<
			ogrenciListe[i].kisaSinav2 << setw(5) << ogrenciListe[i].odev1 << setw(5) << ogrenciListe[i].odev2 << setw(5) <<
			ogrenciListe[i].proje << "    " << ogrenciListe[i].basariNotu << "  " << ogrenciListe[i].harfNotu <<"  " << 
			ogrenciListe[i].dogumGunu.gun << "." << ogrenciListe[i].dogumGunu.ay << "." << ogrenciListe[i].dogumGunu.yil << endl;
	}
}

void aralikListele(float max, float min)//Menu 6
{
	for (int i = 0; i < 100; i++)//Menu 6 için main fonksiyonda kullanıcıdan max ve min değerler isteyip bu aralıkta olan kişilerin yazdırılmasını sağlayan fonksiyon
	{
		if (ogrenciListe[i].basariNotu > min && ogrenciListe[i].basariNotu < max)//Girilen değerlerin arasında kalan notları bulmak için if kullandım.
		{
			cout << ogrenciListe[i].adi << " " << ogrenciListe[i].soyAdi << " " << ogrenciListe[i].basariNotu << endl;
		}
	}
}

void degerAlti()//Menu7
{
	cout << "Degeri giriniz " << endl;
	cin >> altDeger;
	cout << "Degerin altinda kalan ogrenciler :" << endl;
	for (int i = 0; i < 100; i++)//Kullanıcıdan değer isteyerek bu değerin altında kalan isimleri çıkartan fonksiyon.
	{
		if (ogrenciListe[i].basariNotu < altDeger)//Değerin altında olanları çıkartmak için if kullandım.
		{

			cout << ogrenciListe[i].adi << ogrenciListe[i].soyAdi << endl;
		}
	}
}

void degerUstu()//Menu8
{
	cout << "Degeri giriniz " << endl;
	cin >> ustDeger;
	cout << "Degerin ustunde kalan ogrenciler :" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (ogrenciListe[i].basariNotu > ustDeger)
		{

			cout << ogrenciListe[i].adi << ogrenciListe[i].soyAdi << endl;
		}
	}
}

int main()
{
	srand(time(NULL));
	cout << "1.Secenek = Degerler random atansin" << " " << "2.Secenek = Degerler disaridan atansin " << endl;
	cout << "Lutfen yapmak istediginiz secenegi giriniz : ";
	cin >> secenek;
	float minAralik, maxAralik;

	if (secenek == 1) {//Kullanıcı 1. seçeneği seçtiğinde random atanmasını sağlamak için oluşturduğum fonksiyonları burada çağırdım
		vizeRan();
		finalRan();
		odev1Ran();
		odev2Ran();
		kisaSinav1Ran();
		kisaSinav2Ran();
		projeRan();
		isimRan();
		soyIsimRan();
		numaraRan();
		basariNotHesaplama();
		harfNot();
		dogumGunRand();

	}
	

	if (secenek == 2) {//Kullanıcı 2. seçeneği seçtiğinde değerlerin kullanıcı tarafından girilmesi için her öğrenci için döngüyle beraber değerlerin alınmasını sağladım
	//Girilen sınav değerlerinin 0 ve 100 arasında olup olmadığını kontrol etmek için notDogrulugu fonksiyonunu çağırdım.	

		for (int i = 0; i < 100; i++)
		{
			
			system("CLS");
			cout << "Ogrenci " << i + 1 << " " << "degerlerini giriniz" << endl << endl;
			cout << "Ogrencinin adini giriniz : ";
			cin >> ogrenciListe[i].adi;
			cout << "Ogrencinin soyadiniz : ";
			cin >> ogrenciListe[i].soyAdi;
			cout << "Vize notunu giriniz : ";
			cin >> ogrenciListe[i].vize;
			ogrenciListe[i].vize = notDogrulugu("vize", ogrenciListe[i].vize);
			cout << "Final notunu giriniz : ";
			cin >> ogrenciListe[i].final;
			ogrenciListe[i].final = notDogrulugu("final", ogrenciListe[i].final);
			cout << "1.Kisa sinav notunu giriniz : ";
			cin >> ogrenciListe[i].kisaSinav1;
			ogrenciListe[i].kisaSinav1 = notDogrulugu("kisaSinav1", ogrenciListe[i].kisaSinav1);
			cout << "2.Kisa sinav notunu giriniz : ";
			cin >> ogrenciListe[i].kisaSinav2;
			ogrenciListe[i].kisaSinav2 = notDogrulugu("kisaSinav2", ogrenciListe[i].kisaSinav2);
			cout << "1.Odev notunu giriniz : ";
			cin >> ogrenciListe[i].odev1;
			ogrenciListe[i].odev1 = notDogrulugu("odev1", ogrenciListe[i].odev1);
			cout << "2.Odev notunu giriniz : ";
			cin >> ogrenciListe[i].odev2;
			ogrenciListe[i].odev2 = notDogrulugu("odev2", ogrenciListe[i].odev2);
			cout << "Proje notunu giriniz : ";
			cin >> ogrenciListe[i].proje;
			ogrenciListe[i].proje = notDogrulugu("proje", ogrenciListe[i].proje);
			cout << endl;
			basariNotHesaplama();
			harfNot();
		}


	}


	do {//Değerler seçeneğe göre atandıktan sonra kullanıcının istediği menüyü seçip çıkartan ve işleme devam etmesi için do while döngüsü kullanıp tekrar menüye dönülebilmesini sağladım
		system("CLS");

		cout << "Menu 1 = Ogrenci listele " << endl;
		cout << "Menu 2 = Sinifin en yuksek notu hesaplansin " << endl;
		cout << "Menu 3 = Sinifin en dusuk notu hesaplansin " << endl;
		cout << "Menu 4 = Sinifin basari notu ortalamasi hesaplansin " << endl;
		cout << "Menu 5 = Sinifin standart sapmasi hesaplansin " << endl;
		cout << "Menu 6 = Basari notu istediginiz aralikta olanlar listelensin (Ornegin 50<= not <80 gibi) " << endl;
		cout << "Menu 7 = Basari notu istediginiz araligin altinda olanlar listelensin (Ornegin not<70 gibi) " << endl;
		cout << "Menu 8 = Basari notu istediginiz araligin ustunde olanlar listelensin (Ornegin notu>70 gibi) " << endl;
		cout << "Menu seciniz ";
		cin >> menu;
		system("CLS");
		cout << endl << endl;
		if (menu == 1)//Kullanıcı menü sayısını yazdıktan sonra menüye göre gereken fonksiyonu teker teker çağıdım.
		{
			ogrenciYazdir();
		}

		if (menu == 2)
		{
			cout << "Sinifin en yuksek notu :" << enYuksekNot() << endl << endl;
		}
		if (menu == 3)
		{
			cout << "Sinifin en dusuk notu :" << enDusukNot() << endl << endl;
		}
		if (menu == 4)
		{
			cout << "Sinifin ortalama puani :" << ortalamaHesaplama() << endl << endl;
		}
		if (menu == 5)
		{
			cout << "Sinifin standart sapmasi :" << standartSapma() << endl << endl;
		}
		if (menu == 6)
		{
			cout << "Minimum araligi giriniz ";
			cin >> minAralik;
			cout << "Maximum araligi giriniz ";
			cin >> maxAralik;
			while (minAralik >= maxAralik)//max değerin min değerinden küçük olmaması adına while döngüsüyle bunu sorguladım eğer min değeri büyük gelirse tekrar kullanıcıdan değer istiyoruz.
			{
				cout << "Degerleri tekrar giriniz " << endl;
				cout << "Minimum araligi giriniz ";
				cin >> minAralik;
				cout << "Maximum araligi giriniz ";
				cin >> maxAralik;
			}
			aralikListele(maxAralik, minAralik);

		}
		if (menu == 7)
		{
			degerAlti();

		}
		if (menu == 8)
		{
			degerUstu();
		}
		cout << "Isleme devam etmek istiyor musunuz (E/H)" << endl;
		cin >> menuSecenek;


	} while (toupper(menuSecenek) == 'E');//Kullanıcı e girdiği sürece menüye tekrar dönülebilmesi için do while döngüsünün koşulu ve toupper komutunu kullanarak büyük veya küçük harf girerse ikisini de kabul edecek.








}



