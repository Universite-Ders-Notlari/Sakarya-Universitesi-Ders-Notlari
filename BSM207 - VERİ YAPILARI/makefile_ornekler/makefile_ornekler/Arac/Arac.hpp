#ifndef ARAC_HPP
#define ARAC_HPP
class Arac{
	private:
	float hiz; //km/saat
	int yil; // Model yýlý
	public:
	Arac(int);
	void Hizlan(float);
	void Yavasla(float);
	float Hiz();
	float Yil();
};
#endif