#include <iostream>  
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define size 20
using namespace std;
void removeChar(char[], char);  
void printArray(int a[], int b) {

	for (int i = 0; i < b; i++)
		cout << a[i] << " ";


}
void karakter(char x[size], char y) {
	
	cout << "Lütfen max 20 karakterlik veri giriniz: ";
	cin >>x;
	cout << "Silinecek Elemaný Giriniz: ";
	cin >> y;

}
void main() {
	setlocale(LC_ALL, "TURKISH"); 
	char dizi[size], silinecek;  
	cout << "Lütfen en fazla 20 karakterlik bir kelime giriniz: ";
	cin >> dizi;
	cout << "Silinecek Harfi Giriniz: ";
	cin >> silinecek;

	
	removeChar(dizi, silinecek);
	cout << endl;
	for (int i = 0; dizi[i] != '\0'; i++) {
		cout << dizi[i];
	}
	cout << endl ;
	system("pause");
	
}
void removeChar(char d[size], char s) {
	int silinenler[size], sayac1 = 0,a,sayac2=0;
	a = size;
	int i = 0;
	for (int i = 0; d[i]=='\0' ; i++)
	{
		sayac2++;
	}
	while (i<a) {
		if (d[i] == s) {
			
			d[i] = ' ';   
			silinenler[sayac1] = i; 
			sayac1++;    
		}
		i++;
	}
	
	if (sayac1 == 0) {
		cout << "Eleman Dizide Bulunamadý " << endl;
	}
	else {
		cout << "silinen eleman sayýsý : " << sayac1 << endl;
		cout << "Silinenlerin indisi: ";
		
		printArray(silinenler, sayac1);
		
	}
}