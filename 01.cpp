#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<time.h>
#define size 100
using namespace std;
int w = 0, ww = 0, www = 0, q_yer = 0, q_kar = 0, m_kar = 0, m_yer = 0;

int interpolation_search(int array[], int num, int x)
{
	// Find indexes of two corners 
	int st = 0, end = (num - 1);

	while (st <= end && x >= array[st] && x <= array[end])
	{
		if (st == end)
		{
			if (array[st] == x) {
				w++;
				return st;
			}
			return -1;
		}

		int pos = st + (((double)(end - st) /
			(array[end] - array[st])) * (x - array[st]));

		if (array[pos] == x) {
			w++;
			return pos;
		}
		// If x is larger, x is in upper part 
		if (array[pos] < x) {
			w++;
			st = pos + 1;
		}
		// If x is smaller, x is in the lower part 
		else {
			w++;
			end = pos - 1;
		}
	}
	return -1;
}
void quickSort(int *array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot) {
			i++;
			q_kar++;
		}
		while (array[j] > pivot) {
			j--;
			q_kar++;

		}
		if (i <= j)
		{
			q_yer++;
			q_kar++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[size];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
			m_kar++;

		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
			m_kar++;

		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
		m_yer++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
		m_yer++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];


	}
}
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
int min(int x, int y) { return (x <= y) ? x : y; }
int fibMonaccianSearch(int arr[], int x, int n)
{
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
	int fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
	int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 

								   /* fibM is going to store the smallest Fibonacci
								   Number greater than or equal to n */
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front 
	int offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */
	while (fibM > 1)
	{
		// Check if fibMm2 is a valid location 
		int i = min(offset + fibMMm2, n - 1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i */
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
			ww++;
		}

		/* If x is greater than the value at index fibMm2,
		cut the subarray after i+1  */
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			ww++;
		}

		/* element found. return index */
		else return i;
	}

	/* comparing the last element with x */
	if (fibMMm1 && arr[offset + 1] == x)return offset + 1;

	/*element not found. return -1 */
	return -1;
}
int jumpSearch(int arr[], int x, int n)
{
	// Finding block size to be jumped 
	int step = sqrt(n);

	// Finding the block where element is 
	// present (if it is present) 
	int prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		www++;
		if (prev >= n)
			return -1;
	}

	// Doing a linear search for x in block 
	// beginning with prev. 
	while (arr[prev] < x)
	{
		prev++;

		// If we reached next block or end of 
		// array, element is not present. 
		if (prev == min(step, n))
			return -1;
	}
	// If element is found 
	if (arr[prev] == x)
		return prev;

	return -1;
}

void main() {

	int sec, eleman, upper = 1000, lower = 0, deneme, dizi1[size], sayi, index = 0, dizi2[size], dizi3[size], dizi4[size], dizi5[size];
	int temp, b_kar = 0, b_yer = 0, i_kar = 0, i_yer = 0, min, a, loc, s_yer = 0, s_kar = 0;
	int key, j, flag = 1, inter = 0, sayac1 = 0, sayac2 = 0, sayac3 = 0, index1 = 0, index2 = 0;
	char again, liste;

	srand(time(NULL));
y:
	cout << "	   MENU		" << endl << "------------------------------" << endl;
	cout << "-[1] Siralama Algoritmalari" << endl << "-[2] Arama Algoritmalari" << endl << "-[3] Exit" << endl << "   Seciminiz (1 ,2 ,3): ";
	cin >> sec;

	if (sec == 1) {
		cout << endl << "Test dizisine koyulacak eleman sayisini giriniz : ";
		cin >> eleman;
		cout << endl << "Kac kez deneme yapilsin : ";
		cin >> deneme;
		uuu:
		cout << endl << "Siralama sonuclari listelensin mi?: ";
		cin >> liste;
		if(liste == 'e' || liste == 'E'){
			for (int k = 0; k < deneme; k++)
			{

				for (int i = 0; i <eleman; i++)
				{
					dizi1[i] = rand() % (upper - lower + 1) + lower;
					dizi2[i] = dizi1[i];
					dizi3[i] = dizi1[i];
					dizi4[i] = dizi1[i];
					dizi5[i] = dizi1[i];
				}			
				cout << k + 1 << ". ORJINAL DIZI" << endl << "---------------" << endl;

				for (int i = 0; i < eleman; i++)
				{
					cout << dizi1[i] << endl;
				}
				for (int i = 1; i < eleman; i++)
				{
					for (int j = 0; j < eleman - i; j++)
					{

						if (dizi1[j] == dizi1[j + 1])
							b_kar++;
						if (dizi1[j] < dizi1[j + 1]) {
							b_kar++;
						}

						if (dizi1[j] > dizi1[j + 1])
						{
							b_kar++;
							temp = dizi1[j];
							dizi1[j] = dizi1[j + 1];
							dizi1[j + 1] = temp;
							b_yer++;
						}
					}
				}
				cout << k + 1 << ". SIRALANMIS DIZI" << endl << "---------------" << endl;

				for (int i = 0; i < eleman; i++)
				{
					cout << dizi1[i] << endl;
				}

				for (int i = 1; i < eleman; i++)
				{
					key = dizi2[i];
					j = i - 1;

					while (j >= 0 && dizi2[j] > key)
					{
						i_kar;
						dizi2[j + 1] = dizi2[j];
						i_yer++;
						j = j - 1;
					}
					i_kar++;
					dizi2[j + 1] = key;
				}


				for (int i = 0;i<eleman - 1;i++)
				{
					min = dizi3[i];
					loc = i;
					for (j = i + 1;j<eleman;j++)
					{
						if (min > dizi3[j])
						{
							min = dizi3[j];
							loc = j;
							s_kar++;
						}
						else
							s_kar++;

					}

					temp = dizi3[i];
					dizi1[i] = dizi3[loc];
					dizi3[loc] = temp;
					s_yer++;

				}
				quickSort(dizi4, 0, eleman);
				MergeSort(dizi5, 0, eleman - 1);


			}
		}

		else if (liste == 'h' || liste == 'H') {
			goto yyy;
		}

		else {
			cout << "Yanlis secim yaptiniz lutfen tekrar giriniz.!!";
			goto uuu;
		}
		yyy:
		for (int k = 0; k < deneme; k++)
		{

			for (int i = 0; i <eleman; i++)
			{
				dizi1[i] = rand() % (upper - lower + 1) + lower;
				dizi2[i] = dizi1[i];
				dizi3[i] = dizi1[i];
				dizi4[i] = dizi1[i];
				dizi5[i] = dizi1[i];
			}
			for (int i = 1; i < eleman; i++)
			{
				for (int j = 0; j < eleman - i; j++)
				{

					if (dizi1[j] == dizi1[j + 1])
						b_kar++;
					if (dizi1[j] < dizi1[j + 1]) {
						b_kar++;
					}

					if (dizi1[j] > dizi1[j + 1])
					{
						b_kar++;
						temp = dizi1[j];
						dizi1[j] = dizi1[j + 1];
						dizi1[j + 1] = temp;
						b_yer++;
					}
				}
			}

			for (int i = 1; i < eleman; i++)
			{
				key = dizi2[i];
				j = i - 1;

				while (j >= 0 && dizi2[j] > key)
				{
					i_kar;
					dizi2[j + 1] = dizi2[j];
					i_yer++;
					j = j - 1;
				}
				i_kar++;
				dizi2[j + 1] = key;
			}


			for (int i = 0;i<eleman - 1;i++)
			{
				min = dizi3[i];
				loc = i;
				for (j = i + 1;j<eleman;j++)
				{
					if (min > dizi3[j])
					{
						min = dizi3[j];
						loc = j;
						s_kar++;
					}
					else
						s_kar++;

				}

				temp = dizi3[i];
				dizi1[i] = dizi3[loc];
				dizi3[loc] = temp;
				s_yer++;

			}
			quickSort(dizi4, 0, eleman);
			MergeSort(dizi5, 0, eleman - 1);


		}
		cout << endl << "Bubble sort ortlama karsilastirma sayisi: " << (eleman - 1)*(eleman - 1) << endl;
		cout << "Bubble sort ortlama yer degistirme sayisi: " << b_yer / deneme << endl;
		cout << endl << "Insertion sort ortlama karsilastirma sayisi: " << i_kar / deneme << endl;
		cout << "Insertion sort ortlama yer degistirme sayisi: " << i_yer / deneme << endl;
		cout << endl << "Selection sort ortlama karsilastirma sayisi: " << s_kar / deneme << endl;
		cout << "Selection sort ortlama yer degistirme sayisi: " << s_yer / deneme << endl;
		cout << endl << "Quick sort ortlama karsilastirma sayisi: " << q_kar / deneme << endl;
		cout << "Quick sort ortlama yer degistirme sayisi: " << q_yer / deneme << endl;
		cout << endl << "Merge sort ortlama karsilastirma sayisi: " << m_kar / deneme << endl;
		cout << "Merge sort ortlama yer degistirme sayisi: " << m_yer / deneme << endl;

	}
	else if (sec == 2) {
		cout << endl << "Test dizisine koyulacak eleman sayisini giriniz : ";
		cin >> eleman;
		for (int i = 0; i < eleman; i++)
		{
			dizi1[i] = rand() % (upper - lower + 1) + lower;
		}
	z:
		cout << endl << "Arama isleminin sonucu listelensin mi? (E/H): ";
		cin >> again;
		if (again == 'e' || again == 'E')
		{
			for (int i = 1; i < eleman; i++)
			{
				key = dizi1[i];
				j = i - 1;

				while (j >= 0 && dizi1[j] > key)
				{
					i_kar;
					dizi1[j + 1] = dizi1[j];
					i_yer++;
					j--;
				}
				i_kar++;
				dizi1[j + 1] = key;
			}

			cout << endl << "ORIGINAL ARRAY" << endl << "-----------------------" << endl;
			for (int i = 0; i < eleman; i++)
			{
				cout << "ARRAY[" << i << "] " << dizi1[i] << endl;
			}
			cout << endl << "Lutfen aranacak sayiyi giriniz: ";
			cin >> sayi;
			for (int i = 0; i < eleman; i++)
			{
				if (dizi1[i] == sayi) {
					flag = 0;
					cout << "Pozisyon " << i << endl;
					cout << endl << "-Lineer search ortalama karsilastirma: " << i + 1 << endl;

				}
			}
			if (flag == 1)
				cout << "-Lineer search ortalama karsilastirma:" << eleman << endl;

			int first = 0, last, middle;
			last = eleman - 1;
			middle = (first + last) / 2;
			while (first <= last)
			{
				if (dizi1[middle] < sayi)
				{
					first = middle + 1;
					sayac1++;
				}
				else if (dizi1[middle] == sayi)
				{
					sayac1++;
					break;
				}
				else {
					sayac1++;
					last = middle - 1;
				}
				middle = (first + last) / 2;
			}
			cout << "-Binary Search ortlama karsilastirma sayisi:  " << sayac1 << "\n";
			if (first > last)
			{
				cout << sayi << "Sayi bulunamadi!!" << endl;
			}





			//cout << endl << "Interpolation search : " << u << endl;


			index = interpolation_search(dizi1, eleman, sayi);
			index1 = fibMonaccianSearch(dizi1, sayi, eleman);
			cout << "Fibonacci search ortalama karsilastrima sayisi:  " << ww << endl;

			cout << "Interpolation search ortalama karsilastrima sayisi:  " << w + 1 << endl;
			index2 = jumpSearch(dizi1, sayi, eleman);
			cout << "Jump search ortalama karsilastrima sayisi:  " << www << endl;



		}

		else if (again == 'h' || again == 'H') {
			int u = 0;
			for (int i = 0; i < eleman; i++)
			{
				cout << "ARRAY[" << i << "] " << dizi1[i] << endl;
			}
			cout << endl << "Lutfen aranacak sayiyi giriniz: ";
			cin >> sayi;
			for (int i = 0; i < eleman; i++)
			{
				if (dizi1[i] == sayi) {
					flag = 0;
					cout << "Pozisyon " << i << endl;
					cout << endl << "-Lineer search ortalama karsilastirma: " << i + 1 << endl;
					break;
				}
			}
			if (flag == 1)
				cout << "-Lineer search ortalama karsilastirma: " << eleman << endl;
			int first = 0, last, middle;
			last = eleman - 1;
			middle = (first + last) / 2;
			while (first <= last)
			{
				if (dizi1[middle] < sayi)
				{
					first = middle + 1;
					sayac1++;
				}
				else if (dizi1[middle] == sayi)
				{
					sayac1++;
					break;
				}
				else {
					sayac1++;
					last = middle - 1;
				}
				middle = (first + last) / 2;
			}
			index1 = fibMonaccianSearch(dizi1, sayi, eleman);
			cout << "Fibonacci search ortalama karsilastrima sayisi:  " << ww << endl;
			index = interpolation_search(dizi1, eleman, sayi);

			cout << "Interpolation search ortalama karsilastrima sayisi:  " << w + 1 << endl;
			index2 = jumpSearch(dizi1, sayi, eleman);
			cout << "Jump search ortalama karsilastrima sayisi:  " << www << endl;




		}
		else {
			cout << "Error!(Sadece 'E','e','H','h' giriniz) " << endl;
			goto z;
		}

	}
	else if (sec == 3) {

		cout << "Cikis yapiliyor..!" << endl;

	}
	else {
		cout << "Yanlis secim Lutfen Tekrar deneyiniz!!" << endl;
		goto y;
	}


	system("pause");
}