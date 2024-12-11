//Lauri Ylonen  3 Pistetta toivottavasti


//Lista kaikista datatyypeista joita tarvitaan
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

//Tama auttaa selventamaan koodia jotta jokaisessa ei tarvitse alussa lukea std::
using namespace std;


//Lasketaan huoneiden hinnat
static int hinta() {
	const int maxH = 100;
	const int minH = 80;
	return minH + rand() % (maxH - minH + 1);
}


int main() {
	//Aluksi muodostetaan kaikki muuttujat joita tarvitaan
	int haluttuja_huoneita;
	vector<int> halutut_huoneet;
	const int max = 70;
	const int min = 30;
	string nimi;
	char valinta = 0;
	int yot = 0;

	//Jotta voidaan aloittaa ohjelma uudelleen on oltava do koodin alussa
	do {
		//Tyhjennetaan konsoli ruutu jos aloitetaan alusta
		system("cls");

		srand(time(0));


		//Arvotan huoneiden maara valilla 30-70
		int kaikki_huoneet = min + rand() % (max - min + 1);


		//Muodostetaan varatut huoneet
		vector<int> varatut_huoneet;

		//Arvotaan kuinka monta huonetta on varattu valilla 1 - mita ikina int kaikki antaa
		const int varatut = rand() % 21 + 1;

		//Arvotaan huoneiden numerot
		for (int i = 0; i < varatut; i++) {
			int random_varatut = rand() % kaikki_huoneet + 1;

			//Tarkistetaan ettei ole tupla varauksia
			if (find(varatut_huoneet.begin(), varatut_huoneet.end(), random_varatut) == varatut_huoneet.end()) {
				varatut_huoneet.push_back(random_varatut);
			}
		}

		//Aloitetaan hotellin varauspalvelu
		cout << "Tervetuloa hotellin varauspalveluun!" << endl << "------------------------------------" << endl;



		cout << "Montako huonetta haluat varata (1-" << kaikki_huoneet << "): " << endl;

		//Kysytaan huoneiden maara joka halutaan varata
		cin >> haluttuja_huoneita;

		


		//Tarkistetaan ettei numerot ole alle 1 tai yli 20
		if (haluttuja_huoneita < 1 || haluttuja_huoneita > kaikki_huoneet) {
			cout << "Numero ei ole valilla 1-20! Yrita uudelleen!" << endl;
			return 1;
		}

		//Kysytaan kuinka monta yota halutaan viettaa
		cout << "Kuinka monta yota haluat viettaa: " << endl;
		cin >> yot;

		//Tallennetaan henkilon nimi
		cout << "Antakaa viela varaajan etunimi ja sukunimi: " << endl;

		cin.ignore();
		getline(cin, nimi);


		//Muodostetaan vektori jossa on henkilolle arvotut huoneet
		vector<int> hotelli_huone;

		//Arvotaan henkilolle varaukset huoneista
		for (int i = 0; i < haluttuja_huoneita; i++) {
			int random_vapaa = rand() % 70 + 1;

			//Tarkastetaan ettei ole varatuissa huoneissa
			if (find(varatut_huoneet.begin(), varatut_huoneet.end(), random_vapaa) == varatut_huoneet.end()) {

			}
			//Tarkastetaan ettei tule tuplavarauksia
			if (find(hotelli_huone.begin(), hotelli_huone.end(), random_vapaa) == hotelli_huone.end()) {
				hotelli_huone.push_back(random_vapaa);
			}
		}


		//Kerrotaan yhden yon hinta.
		int yhdYonH = hinta();
		cout << "Yhden yon hinta on: " << yhdYonH << " euroa!" << endl;

		//Lasketan yhteis hinta vartuille huoneille.
		int kokHinta = yhdYonH * yot;

		//Tulostetaan varaustiedot
		cout << "Seuraavat huoneet ovat nyt varattuja: ";
		for (int huone : hotelli_huone) {
			cout << huone << " ";
		}

		//Kerrotaan mille nimelle varaus on tehty
		cout << endl << "Varaukset on tehty nimelle: " << nimi << endl;

		//Kerrotaan henkilölle kuinka paljon yhteishinta tulee olemaan
		cout << "Hinta varauksille tulee olemaan: " << kokHinta << " euroa!" << endl;

		//Kysytaan halutaanko aloittaa tyo alusta vai ei
		cout << "Haluatko aloittaa alusta?" << endl;
		cout << "(K tai E)" << endl;
		cin >> valinta;

		//Tarkistetaan etta valintana on joko K tai E
		while (valinta != 'K' && valinta != 'k' && valinta != 'E' && valinta != 'e') {
			cout << "Virheellinen valinta! Valitse joko (K tai E)" << endl;
			cin >> valinta;
		}
		//Jos valinta on K niin jarjestelma alkaa alusta mutta jos E niin se sulkeutuu
	} while (valinta == 'K' || valinta == 'k');

	cout << "Kiitos ja mukavaa paivan jatkoa!" << endl;

	//Suljetaan ohjelma
	return 0;
}